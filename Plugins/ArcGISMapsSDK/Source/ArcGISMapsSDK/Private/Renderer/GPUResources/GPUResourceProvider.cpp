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
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceProvider.h"

#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"

#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderableType.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISTextureFormat.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceMaterial.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceTexture2D.h"

namespace
{
EPixelFormat ConvertToEPixelFormat(Esri::GameEngine::RCQ::ArcGISTextureFormat Format)
{
	using namespace Esri::GameEngine::RCQ;
	switch (Format)
	{
		case ArcGISTextureFormat::RGBA16UNorm:
			return PF_A16B16G16R16;
		case ArcGISTextureFormat::R32Norm:
#ifdef PLATFORM_APPLE
			return PF_R32_FLOAT;
#else
			return PF_R32_SINT;
#endif
		case ArcGISTextureFormat::RGBA32Float:
			return PF_A32B32G32R32F;
		case ArcGISTextureFormat::RGBA8UNorm:
			return PF_R8G8B8A8;
		case ArcGISTextureFormat::BGRA8UNorm:
			return PF_B8G8R8A8;
		case ArcGISTextureFormat::R32Float:
			return PF_R32_FLOAT;
		case ArcGISTextureFormat::DXT1:
			return PF_DXT1;
		case ArcGISTextureFormat::DXT3:
			return PF_DXT3;
		case ArcGISTextureFormat::DXT5:
			return PF_DXT5;
		case ArcGISTextureFormat::ETC2RGB8:
		case ArcGISTextureFormat::ETC2SRGB8:
			return PF_ETC2_RGB;
		case ArcGISTextureFormat::ETC2RGB8PunchthroughAlpha1:
		case ArcGISTextureFormat::ETC2SRGB8PunchthroughAlpha1:
		case ArcGISTextureFormat::ETC2EacSRGBA8:
		case ArcGISTextureFormat::ETC2EacRGBA8:
			return PF_ETC2_RGBA;
		default:
			throw "Unknown PixelFormat";
	}
}
} // namespace

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
FGPUResourceProvider::FGPUResourceProvider()
{
	// Create zero-valued float texture
	const float BlackFloatTextureData{0.0f};
	BlackFloatTexture = ::MakeShared<FGPUResourceTexture2D>(
		1, 1, ConvertToEPixelFormat(GameEngine::RCQ::ArcGISTextureFormat::R32Float), false);
	BlackFloatTexture->SetPixelData(reinterpret_cast<const uint8*>(&BlackFloatTextureData));
}

const TSharedPtr<FGPUResourceTexture2D>& FGPUResourceProvider::GetBlackFloatTexture() const
{
	return BlackFloatTexture;
}

TSharedPtr<FGPUResourceMaterial> FGPUResourceProvider::CreateMaterial(uint32 Id,
																	  GameEngine::RCQ::ArcGISRenderableType RenderableType,
																	  UMaterialInterface* CustomMaterial)
{
	using namespace Esri::GameEngine::RCQ;

	UMaterialInterface* MaterialInterface = CustomMaterial;

	if (!MaterialInterface)
	{
		auto Name = RenderableType == ArcGISRenderableType::Tile ? "Material'/ArcGISMapsSDK/Materials/Tile.Tile'" : "Material'/ArcGISMapsSDK/Materials/SceneNode.SceneNode'";

		MaterialInterface = LoadObject<UMaterial>(nullptr, ANSI_TO_TCHAR(Name));
	}

	auto NewMaterial = ::MakeShared<FGPUResourceMaterial>(MaterialInterface);

	if (RenderableType == ArcGISRenderableType::Tile)
	{
		static const FString OcclusionRenderTargetName("OcclusionRenderTarget");
		NewMaterial->SetTexture(OcclusionRenderTargetName, OcclusionRenderTarget);
	}

	Materials.Emplace(Id, NewMaterial);

	return NewMaterial;
}

TSharedPtr<FGPUResourceRenderTarget> FGPUResourceProvider::CreateRenderTarget(uint32 Id,
																			  uint32 Width,
																			  uint32 Height,
																			  GameEngine::RCQ::ArcGISTextureFormat Format,
																			  bool bUseMipmaps)
{
	auto NewRenderTarget = ::MakeShared<FGPUResourceRenderTarget>(Width, Height, ConvertToEPixelFormat(Format), bUseMipmaps);

	RenderTargets.Emplace(Id, NewRenderTarget);

	return NewRenderTarget;
}

TSharedPtr<FGPUResourceTexture2D> FGPUResourceProvider::CreateTexture(uint32 Id,
																	  uint32 Width,
																	  uint32 Height,
																	  GameEngine::RCQ::ArcGISTextureFormat Format,
																	  bool bInIsSRGB)
{
	auto NewTexture = ::MakeShared<FGPUResourceTexture2D>(Width, Height, ConvertToEPixelFormat(Format), bInIsSRGB);

	Textures.Emplace(Id, NewTexture);

	return NewTexture;
}

TSharedPtr<FGPUResourceMaterial> FGPUResourceProvider::GetMaterial(uint32 Id) const
{
	const auto* value = Materials.Find(Id);

	if (value)
	{
		return *value;
	}

	return nullptr;
}

TSharedPtr<FGPUResourceRenderTarget> FGPUResourceProvider::GetRenderTarget(uint32 Id) const
{
	const auto* value = RenderTargets.Find(Id);

	if (value)
	{
		return *value;
	}

	return nullptr;
}

TSharedPtr<FGPUResourceTexture2D> FGPUResourceProvider::GetTexture(uint32 Id) const
{
	const auto* value = Textures.Find(Id);

	if (value)
	{
		return *value;
	}

	return nullptr;
}

void FGPUResourceProvider::DestroyMaterial(uint32 Id)
{
	Materials.Remove(Id);
}

void FGPUResourceProvider::DestroyRenderTarget(uint32 Id)
{
	RenderTargets.Remove(Id);
}

void FGPUResourceProvider::DestroyTexture(uint32 Id)
{
	Textures.Remove(Id);
}

void FGPUResourceProvider::SetOcclusionRenderTarget(UTextureRenderTarget2D* InOcclusionRenderTarget)
{
	OcclusionRenderTarget = ::MakeShared<FGPUResourceRenderTarget>(InOcclusionRenderTarget);
}
} // namespace GPUResources
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
