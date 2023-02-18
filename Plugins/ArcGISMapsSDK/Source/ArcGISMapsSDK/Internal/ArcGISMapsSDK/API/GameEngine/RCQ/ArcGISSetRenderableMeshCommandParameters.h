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

#include "ArcGISMapsSDK/API/GameEngine/Math/ArcGISOrientedBoundingBox.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDataBufferView.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
struct ArcGISSetRenderableMeshCommandParameters
{
    /// <summary>
    /// The renderable parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t RenderableId;
    
    /// <summary>
    /// The triangles parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISDataBufferView Triangles;
    
    /// <summary>
    /// The positions parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISDataBufferView Positions;
    
    /// <summary>
    /// The normals parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISDataBufferView Normals;
    
    /// <summary>
    /// The tangents parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISDataBufferView Tangents;
    
    /// <summary>
    /// The uvs parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISDataBufferView Uvs;
    
    /// <summary>
    /// The colors parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISDataBufferView Colors;
    
    /// <summary>
    /// The ID of the uv region parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISDataBufferView UvRegionIds;
    
    /// <summary>
    /// The mesh's feature indices
    /// </summary>
    /// <remarks>
    /// A zero-based id that is unique for each feature contained in the scene node. 
    /// Used to look up feature ID in the <see cref="Esri::GameEngine::RCQ::ArcGISMaterialTextureProperty.featureIds">ArcGISMaterialTextureProperty.featureIds</see> texture.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISDataBufferView FeatureIndices;
    
    /// <summary>
    /// The oriented bounding box of the mesh
    /// </summary>
    /// <since>1.0.0</since>
    Math::ArcGISOrientedBoundingBox OrientedBoundingBox;
    
    /// <summary>
    /// The boolean indicating whether this mesh should be used to mask terrain
    /// </summary>
    /// <since>1.0.0</since>
    bool MaskTerrain;
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri