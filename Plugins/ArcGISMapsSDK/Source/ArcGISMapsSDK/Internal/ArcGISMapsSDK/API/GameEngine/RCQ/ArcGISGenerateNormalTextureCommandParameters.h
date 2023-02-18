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

#include "ArcGISMapsSDK/API/GameEngine/Math/ArcGISVector4.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
struct ArcGISGenerateNormalTextureCommandParameters
{
    /// <summary>
    /// The elevation parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t ElevationId;
    
    /// <summary>
    /// The tile extent parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    Math::ArcGISVector4 TileExtent;
    
    /// <summary>
    /// The texture extent parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    Math::ArcGISVector4 TextureExtent;
    
    /// <summary>
    /// The target parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t TargetId;
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri