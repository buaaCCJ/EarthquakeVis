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
enum class ArcGISTextureSemantic
{
    /// <summary>
    /// The mesh imagery (color) texture.
    /// </summary>
    /// <remarks>
    /// May be a texture atlas.
    /// </remarks>
    /// <since>1.0.0</since>
    MeshPyramidImagery = 5,
    
    /// <summary>
    /// The feature index vertex attribute to UVRegions lookup table.
    /// </summary>
    /// <remarks>
    /// Used when the imagery texture is a texture atlas.
    /// </remarks>
    /// <since>1.0.0</since>
    MeshPyramidUvRegions = 6,
    
    /// <summary>
    /// The feature index vertex attribute to feature id lookup table.
    /// </summary>
    /// <since>1.0.0</since>
    MeshPyramidFeatureIds = 7,
    
    /// <summary>
    /// The feature index vertex attribute to feature attribute value lookup table.
    /// </summary>
    /// <since>1.0.0</since>
    MeshPyramidAttributeValues = 8
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri