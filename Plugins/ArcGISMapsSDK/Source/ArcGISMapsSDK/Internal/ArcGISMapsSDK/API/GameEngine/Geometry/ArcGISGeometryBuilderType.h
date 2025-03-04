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
enum class ArcGISGeometryBuilderType
{
    /// <summary>
    /// Point builder to which produces point geometry.
    /// </summary>
    /// <since>1.0.0</since>
    PointBuilder = 1,
    
    /// <summary>
    /// Envelope builder to which produces envelope geometry.
    /// </summary>
    /// <since>1.0.0</since>
    EnvelopeBuilder = 2,
    
    /// <summary>
    /// Polyline builder to which produces polyline geometry.
    /// </summary>
    /// <since>1.0.0</since>
    PolylineBuilder = 3,
    
    /// <summary>
    /// Polygon builder to which produces polygon geometry.
    /// </summary>
    /// <since>1.0.0</since>
    PolygonBuilder = 4,
    
    /// <summary>
    /// Multipoint builder to which produces multipoint geometry.
    /// </summary>
    /// <since>1.0.0</since>
    MultipointBuilder = 5,
    
    /// <summary>
    /// An unknown geometry builder.
    /// </summary>
    /// <since>1.0.0</since>
    Unknown = -1
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri