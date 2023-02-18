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
#pragma once

#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderableType.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
struct ArcGISCreateRenderableCommandParameters
{
    /// <summary>
    /// The id that will be use for the created render target.
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t RenderableId;
    
    /// <summary>
    /// The type parameter of the renderable
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISRenderableType RenderableType;
    
    /// <summary>
    /// Internal 32-bit identifier of a layer. Only valid for Scene Nodes.
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t LayerId;
    
    /// <summary>
    /// The game engine material
    /// </summary>
    /// <since>1.0.0</since>
    void* Material;
    
    /// <summary>
    /// Internal 64-bit identifier passed back to the runtimecore via <see cref="Esri::GameEngine::RCQ::ArcGISRenderCommandServer.notifyRenderableHasGPUResources">ArcGISRenderCommandServer.notifyRenderableHasGPUResources</see> to notify when a Renderable is drawable.
    /// </summary>
    /// <since>1.0.0</since>
    uint64_t CallbackToken;
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri