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
enum class ArcGISGeometryType
{
    /// <summary>
    /// Point geometry.
    /// </summary>
    /// <since>1.0.0</since>
    Point = 1,
    
    /// <summary>
    /// Envelope geometry.
    /// </summary>
    /// <since>1.0.0</since>
    Envelope = 2,
    
    /// <summary>
    /// Polyline geometry.
    /// </summary>
    /// <since>1.0.0</since>
    Polyline = 3,
    
    /// <summary>
    /// Polygon geometry.
    /// </summary>
    /// <since>1.0.0</since>
    Polygon = 4,
    
    /// <summary>
    /// Multipoint geometry.
    /// </summary>
    /// <since>1.0.0</since>
    Multipoint = 5,
    
    /// <summary>
    /// An unknown geometry type.
    /// </summary>
    /// <since>1.0.0</since>
    Unknown = -1
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri