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

#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDataBufferView.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
struct ArcGISSetTexturePixelDataCommandParameters
{
    /// <summary>
    /// The texture parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t TextureId;
    
    /// <summary>
    /// The pixels parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISDataBufferView Pixels;
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri