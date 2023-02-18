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

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
enum class ArcGISMaterialScalarProperty
{
    /// <summary>
    /// Clipping mode
    /// </summary>
    /// <since>1.0.0</since>
    ClippingMode = 0,
    
    /// <summary>
    /// Use uv region lut
    /// </summary>
    /// <since>1.0.0</since>
    UseUvRegionLut = 1,
    
    /// <summary>
    /// Metallic factor for PBR
    /// </summary>
    /// <since>1.0.0</since>
    Metallic = 2,
    
    /// <summary>
    /// Roughness factor for PBR
    /// </summary>
    /// <since>1.0.0</since>
    Roughness = 3,
    
    /// <summary>
    /// Opacity factor
    /// </summary>
    /// <since>1.0.0</since>
    Opacity = 4,
    
    /// <summary>
    /// Flag indicating whether the Renderable has transparency
    /// </summary>
    /// <since>1.0.0</since>
    HasTransparency = 5
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri