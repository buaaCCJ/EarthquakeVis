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
namespace Geometry
{
enum class ArcGISGeometryDimension
{
    /// <summary>
    /// The geometry is a point or multipoint.
    /// </summary>
    /// <since>1.0.0</since>
    Point = 0,
    
    /// <summary>
    /// The geometry is a curve.
    /// </summary>
    /// <since>1.0.0</since>
    Curve = 1,
    
    /// <summary>
    /// The geometry has an area.
    /// </summary>
    /// <since>1.0.0</since>
    Area = 2,
    
    /// <summary>
    /// The geometry has a volume.
    /// </summary>
    /// <since>1.0.0</since>
    Volume = 3,
    
    /// <summary>
    /// Unknown geometry dimensions.
    /// </summary>
    /// <since>1.0.0</since>
    Unknown = -1
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri