// COPYRIGHT 1995-2022 ESRI
// TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
// Unpublished material - all rights reserved under the
// Copyright Laws of the United States and applicable international
// laws, treaties, and conventions.
//
// For additional information, contact:
// Attn: Contracts and Legal Department
// Environmental Systems Research Institute, Inc.
// 380 New York Street
// Redlands, California 92373
// USA
//
// email: legal@esri.com
#include "Materials/MaterialParameterCollection.h"

#include "ArcGISMapsSDK/Renderer/ArcGISRendererImpl.h"

#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDecodedRenderCommandQueue.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderCommandServer.h"
#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISView.h"
#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISViewInternal.h"
#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDK/Renderer/ArcGISRenderCommandThrottle.h"
#include "ArcGISMapsSDK/Renderer/GPUComputing/ComputeImageComposer.h"
#include "ArcGISMapsSDK/Renderer/GPUComputing/ComputeNormalMapGenerator.h"
#include "ArcGISMapsSDK/Renderer/GPUComputing/GraphicsImageComposer.h"
#include "ArcGISMapsSDK/Renderer/GPUComputing/GraphicsNormalMapGenerator.h"
#include "ArcGISMapsSDK/Renderer/GPUComputing/TerrainOcclusionDepthMapRenderer.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceProvider.h"
#include "ArcGISMapsSDK/Renderer/Renderables/RenderableProvider.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
FArcGISRenderer::Impl::Impl(TSharedPtr<Esri::GameEngine::View::ArcGISView> InView,
							UObject* InOuter,
							bool bInAreMeshCollidersEnabled,
							bool bInIsTerrainOcclusionEnabled)
{
	EShaderPlatform ShaderPlatform = GetFeatureLevelShaderPlatform(GMaxRHIFeatureLevel);

	if (RHISupportsComputeShaders(ShaderPlatform))
	{
		UE_LOG(LogTemp, Display, TEXT("Using FComputeImageComposer and FComputeNormalMapGenerator"));

		ImageComposer = ::MakeShared<GPUComputing::FComputeImageComposer>();
		NormalMapGenerator = ::MakeShared<GPUComputing::FComputeNormalMapGenerator>(InView);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Using FGraphicsImageComposer and FGraphicsNormalMapGenerator"));

		ImageComposer = ::MakeShared<GPUComputing::FGraphicsImageComposer>();
		NormalMapGenerator = ::MakeShared<GPUComputing::FGraphicsNormalMapGenerator>(InView);
	}

	GPUResourceProvider = ::MakeShared<GPUResources::FGPUResourceProvider>();
	RenderableProvider = ::MakeShared<Renderables::FRenderableProvider>(InOuter, bInAreMeshCollidersEnabled);

	if (bInIsTerrainOcclusionEnabled)
	{
		TerrainOcclusionDepthMapRenderer =
			::MakeShared<GPUComputing::FTerrainOcclusionDepthMapRenderer>(RenderableProvider, GPUResourceProvider, InOuter);
		TerrainOcclusionDepthMapRenderer->BeginRendering();
	}

	MapComponent = UArcGISMapComponent::GetMapComponent(InOuter);

	RenderCommandClient =
		::MakeShared<FArcGISRenderCommandClient>(MapComponent, GPUResourceProvider, RenderableProvider, ImageComposer, NormalMapGenerator);

	View = std::move(InView);

	LastENUToWorldTransformAtOrigin = MapComponent->GetENUToWorldTransformAtOrigin();

	CurrentRenderCommandQueue = Esri::GameEngine::RCQ::ArcGISDecodedRenderCommandQueue(
		Esri::GameEngine::View::ArcGISViewInternal::GetRenderCommandServer(View.Get()).GetRenderCommands());
}

FArcGISRenderer::Impl::~Impl()
{
	if (TerrainOcclusionDepthMapRenderer)
	{
		TerrainOcclusionDepthMapRenderer->EndRendering();
	}
}

void FArcGISRenderer::Impl::Update()
{
	if (TerrainOcclusionDepthMapRenderer)
	{
		TerrainOcclusionDepthMapRenderer->Update(MapComponent->GetViewportProperties());
	}

	auto renderCommandServer = Esri::GameEngine::View::ArcGISViewInternal::GetRenderCommandServer(View.Get());

	if constexpr (!FArcGISRenderCommandThrottle::bEnableThrottle)
	{
		// Process one full command queue at a time
		CurrentRenderCommandQueue = Esri::GameEngine::RCQ::ArcGISDecodedRenderCommandQueue(renderCommandServer.GetRenderCommands());

		auto RenderCommand = CurrentRenderCommandQueue.GetNextCommand();

		while (RenderCommand != nullptr)
		{
			RenderCommandClient->ExecuteRenderCommand(*RenderCommand);

			RenderCommand = CurrentRenderCommandQueue.GetNextCommand();
		}
	}
	else
	{
		FArcGISRenderCommandThrottle RenderCommandThrottle;

		// Pick up next command from previous queue, if any
		auto RenderCommand = CurrentRenderCommandQueue.GetNextCommand();

		if (RenderCommand == nullptr)
		{
			CurrentRenderCommandQueue =
				Esri::GameEngine::RCQ::ArcGISDecodedRenderCommandQueue(renderCommandServer.GetRenderCommands());
			RenderCommand = CurrentRenderCommandQueue.GetNextCommand();
		}

		while (RenderCommand != nullptr)
		{
			RenderCommandClient->ExecuteRenderCommand(*RenderCommand);

			if (RenderCommandThrottle.DoThrottle(*RenderCommand))
			{
				// Break and defer processing of the remaining commands to next Update
				break;
			}

			RenderCommand = CurrentRenderCommandQueue.GetNextCommand();
		}
	}

	auto UnavailableRenderables = RenderableProvider->GetUnavailableRenderables();

	TArray<uint64> CallbackTokens;

	for (const auto& UnavailableRenderable : UnavailableRenderables)
	{
		if (UnavailableRenderable->HasGPUResources())
		{
			CallbackTokens.Add(UnavailableRenderable->GetCallbackToken());

			RenderableProvider->SetRenderableAsAvailable(UnavailableRenderable);
		}
	}

	if (!CallbackTokens.IsEmpty())
	{
		renderCommandServer.NotifyRenderableHasGPUResources(TArrayView<uint8>(
			reinterpret_cast<uint8*>(CallbackTokens.GetData()), CallbackTokens.Num() * CallbackTokens.GetTypeSize() / sizeof(uint8)));
	}

	auto CurrentENUToWorldTransformAtOrigin = MapComponent->GetENUToWorldTransformAtOrigin();

	if (!CurrentENUToWorldTransformAtOrigin.Equals(LastENUToWorldTransformAtOrigin, 0.0f))
	{
		UpdateTransform(RenderableProvider->GetRenderables(), CurrentENUToWorldTransformAtOrigin);

		LastENUToWorldTransformAtOrigin = CurrentENUToWorldTransformAtOrigin;
	}
}

void FArcGISRenderer::Impl::UpdateTransform(const TMap<uint32, TSharedPtr<Renderables::FRenderable>>& InRenderables,
											const FTransform& CurrentTransform)
{
	for (const auto& RenderablePair : InRenderables)
	{
		auto& Renderable = RenderablePair.Value;

		if (!CurrentTransform.Equals(Renderable->ENUToWorldTransformAtOrigin, 0.0f))
		{
			auto LastTransformToCurrentTransform = Renderable->ENUToWorldTransformAtOrigin.Inverse() * CurrentTransform;

			Renderable->SetRotation(CurrentTransform.GetRotation());
			Renderable->SetLocation(LastTransformToCurrentTransform.TransformPosition(Renderable->GetLocation()));

			Renderable->ENUToWorldTransformAtOrigin = CurrentTransform;
		}
	}
}

uint32 FArcGISRenderer::Impl::GetLayerIdByMeshComponent(const UMeshComponent* InMeshComponent) const
{
	const auto& Renderable = RenderableProvider->GetRenderableFrom(InMeshComponent);

	return Renderable ? Renderable->GetLayerId() : 0;
}

void FArcGISRenderer::Impl::SetAreMeshCollidersEnabled(bool bEnabled)
{
	RenderableProvider->SetAreMeshCollidersEnabled(bEnabled);
}
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
