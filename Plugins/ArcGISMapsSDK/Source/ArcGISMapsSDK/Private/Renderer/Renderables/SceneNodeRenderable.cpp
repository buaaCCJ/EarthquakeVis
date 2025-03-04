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
#include "ArcGISMapsSDK/Renderer/Renderables/SceneNodeRenderable.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace Renderables
{
FSceneNodeRenderable::FSceneNodeRenderable(UObject* InOuter, uint32 InLayerId, uint64 InCallbackToken)
: FRenderable(InOuter, InLayerId, InCallbackToken)
{
}

GameEngine::RCQ::ArcGISRenderableType FSceneNodeRenderable::GetRenderableType() const
{
	return GameEngine::RCQ::ArcGISRenderableType::SceneNode;
}

bool FSceneNodeRenderable::HasGPUResources() const
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

	auto BaseMapTexture = Material->GetTexture("BaseMap");

	if (BaseMapTexture && !BaseMapTexture->GetIsUpdated())
	{
		return false;
	}

	return true;
}
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
