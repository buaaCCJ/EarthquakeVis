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
#include "ArcGISMapsSDK/Renderer/Renderables/TileRenderable.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace Renderables
{
FTileRenderable::FTileRenderable(UObject* InOuter, uint32 InLayerId, uint64 InCallbackToken)
: FRenderable(InOuter, InLayerId, InCallbackToken)
{
}

GameEngine::RCQ::ArcGISRenderableType FTileRenderable::GetRenderableType() const
{
	return GameEngine::RCQ::ArcGISRenderableType::Tile;
}

bool FTileRenderable::HasGPUResources() const
{
	if (!MeshComponent || !MeshComponent->GetRenderData() || !MeshComponent->GetRenderData()->IsUpdated())
	{
		return false;
	}

	const auto& Material = GetMaterial();

	if (!Material)
	{
		return false;
	}

	auto ImageryTexture = Material->GetTexture("Imagery");

	if (!ImageryTexture || !ImageryTexture->GetIsUpdated())
	{
		return false;
	}

	return true;
}
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
