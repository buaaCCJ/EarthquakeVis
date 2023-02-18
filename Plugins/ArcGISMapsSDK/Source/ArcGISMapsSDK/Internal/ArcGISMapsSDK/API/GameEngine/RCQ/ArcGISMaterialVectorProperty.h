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
enum class ArcGISMaterialVectorProperty
{
    /// <summary>
    /// Map area min
    /// </summary>
    /// <since>1.0.0</since>
    MapAreaMin = 0,
    
    /// <summary>
    /// Map area max
    /// </summary>
    /// <since>1.0.0</since>
    MapAreaMax = 1,
    
    /// <summary>
    /// The region of the normal map texture to be sampled
    /// </summary>
    /// <remarks>
    /// Set on terrain tiles.
    /// XY contains the minimum UV of the region to be sampled and ZW contains the size of the region to be sampled.
    /// To perform the required scaling and offset of UVs they should be multiplied by ZW and then have XY added to them.
    /// For example: for normalMapRegion == {0.5, 0.5, 0.25, 0.25}, scaled and offset UVs would range from {0.5, 0.5} to {0.75, 0.75}
    /// </remarks>
    /// <since>1.0.0</since>
    NormalMapRegion = 2,
    
    /// <summary>
    /// The region of the imagery texture to be sampled
    /// </summary>
    /// <remarks>
    /// Set on terrain tiles.
    /// Works the same way as <see cref="Esri::GameEngine::RCQ::ArcGISMaterialVectorProperty.normalMapRegion">ArcGISMaterialVectorProperty.normalMapRegion</see>.
    /// </remarks>
    /// <since>1.0.0</since>
    ImageryRegion = 3
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri