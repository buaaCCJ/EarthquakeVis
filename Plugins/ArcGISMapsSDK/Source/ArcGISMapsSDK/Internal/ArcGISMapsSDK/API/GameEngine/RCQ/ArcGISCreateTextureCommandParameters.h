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

#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISTextureFormat.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
struct ArcGISCreateTextureCommandParameters
{
    /// <summary>
    /// The id that will be use for the created texture.
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t TextureId;
    
    /// <summary>
    /// The width parameter of the texture
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t Width;
    
    /// <summary>
    /// The height parameter of the texture
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t Height;
    
    /// <summary>
    /// The format parameter of the texture
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISTextureFormat TextureFormat;
    
    /// <summary>
    /// Indicate whether color data is stored in the sRGB color space or not
    /// </summary>
    /// <since>1.0.0</since>
    bool IsSRGB;
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri