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
#include "ArcGISMapsSDK/Renderer/Renderables/RenderableProvider.h"

#include "ArcGISMapsSDK/Renderer/Renderables/SceneNodeRenderable.h"
#include "ArcGISMapsSDK/Renderer/Renderables/TileRenderable.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace Renderables
{
FRenderableProvider::FRenderableProvider(UObject* InOuter, bool bAreMeshCollidersEnabled)
: bAreMeshCollidersEnabled(bAreMeshCollidersEnabled),
  Outer(InOuter)
{
}

TSharedPtr<FRenderable> FRenderableProvider::CreateRenderable(uint32 InId,
															  GameEngine::RCQ::ArcGISRenderableType InRenderableType,
															  uint32 InLayerId,
															  uint64 InCallbackToken)
{
	TSharedPtr<FRenderable> NewRenderable;

	if (InRenderableType == GameEngine::RCQ::ArcGISRenderableType::SceneNode)
	{
		NewRenderable = ::MakeShared<FSceneNodeRenderable>(Outer, InLayerId, InCallbackToken);
	}
	else if (InRenderableType == GameEngine::RCQ::ArcGISRenderableType::Tile)
	{
		NewRenderable = ::MakeShared<FTileRenderable>(Outer, InLayerId, InCallbackToken);
	}
	else
	{
		throw "Unknown ArcGISRenderableType";
	}

	NewRenderable->SetIsMeshColliderEnabled(bAreMeshCollidersEnabled);

	Renderables.Emplace(InId, NewRenderable);
	RenderablesByMeshComponent.Emplace(Cast<UMeshComponent>(NewRenderable->GetMeshComponent()), NewRenderable);
	UnavailableRenderables.Add(NewRenderable);

	return NewRenderable;
}

TSharedPtr<FRenderable> FRenderableProvider::GetRenderable(uint32 InId) const
{
	const auto RenderableIt = Renderables.Find(InId);
	return RenderableIt ? *RenderableIt : nullptr;
}

const TMap<uint32, TSharedPtr<FRenderable>>& FRenderableProvider::GetRenderables() const
{
	return Renderables;
}

const TSharedPtr<const FRenderable> FRenderableProvider::GetRenderableFrom(const UMeshComponent* InMeshComponent) const
{
	const auto RenderableIt = RenderablesByMeshComponent.Find(InMeshComponent);
	return RenderableIt ? *RenderableIt : nullptr;
}

const TArray<TSharedPtr<FRenderable>>& FRenderableProvider::GetUnavailableRenderables() const
{
	return UnavailableRenderables;
}

void FRenderableProvider::DestroyRenderable(uint32 InId)
{
	const auto RenderableIt = Renderables.Find(InId);

	if (RenderableIt)
	{
		RenderablesByMeshComponent.Remove(Cast<UMeshComponent>((*RenderableIt)->GetMeshComponent()));
		Renderables.Remove(InId);
		UnavailableRenderables.Remove(*RenderableIt);
	}
}

void FRenderableProvider::SetAreMeshCollidersEnabled(bool bInAreMeshCollidersEnabled)
{
	if (bAreMeshCollidersEnabled != bInAreMeshCollidersEnabled)
	{
		bAreMeshCollidersEnabled = bInAreMeshCollidersEnabled;

		for (auto& Renderable : Renderables)
		{
			Renderable.Value->SetIsMeshColliderEnabled(bInAreMeshCollidersEnabled);
		}
	}
}

void FRenderableProvider::SetRenderableAsAvailable(const TSharedPtr<FRenderable>& InRenderable)
{
	UnavailableRenderables.Remove(InRenderable);
}
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
