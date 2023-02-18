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
enum class ArcGISMaterialTextureProperty
{
    /// <summary>
    /// Imagery
    /// </summary>
    /// <since>1.0.0</since>
    Imagery = 0,
    
    /// <summary>
    /// Normal map
    /// </summary>
    /// <since>1.0.0</since>
    NormalMap = 1,
    
    /// <summary>
    /// Base map
    /// </summary>
    /// <since>1.0.0</since>
    BaseMap = 2,
    
    /// <summary>
    /// Uv region lut
    /// </summary>
    /// <since>1.0.0</since>
    UvRegionLut = 3,
    
    /// <summary>
    /// Positions map
    /// </summary>
    /// <since>1.0.0</since>
    PositionsMap = 4,
    
    /// <summary>
    /// Feature IDs.
    /// </summary>
    /// <remarks>
    /// Present on scene node meshes with feature data.
    /// The feature id for a given feature index (see <see cref="Esri::GameEngine::RCQ::ArcGISSetRenderableMeshCommandParameters.featureIndices">ArcGISSetRenderableMeshCommandParameters.featureIndices</see>) is stored at:
    /// x = feature_index % (tex_width / 2)
    /// y = floor(feature_index / (tex_width / 2))
    /// </remarks>
    /// <since>1.0.0</since>
    FeatureIds = 5,
    
    /// <summary>
    /// MetallicRoughness
    /// </summary>
    /// <since>1.0.0</since>
    MetallicRoughness = 6,
    
    /// <summary>
    /// Emissive
    /// </summary>
    /// <since>1.0.0</since>
    Emissive = 7,
    
    /// <summary>
    /// Occlusion map
    /// </summary>
    /// <since>1.0.0</since>
    OcclusionMap = 8
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri