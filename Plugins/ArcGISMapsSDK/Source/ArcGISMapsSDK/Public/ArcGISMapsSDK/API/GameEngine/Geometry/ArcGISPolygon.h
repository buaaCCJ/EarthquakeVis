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

#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipart.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPolyline;

/// <summary>
/// A multipart shape used to represent an area.
/// </summary>
/// <remarks>
/// Polygon geometries represent the shape and location of areas, for example, a country, island,
/// or a lake. A polygon can be used as the geometry of features and graphics, or as input or
/// output of tasks or geoprocessing operations, such as the output of a drive-time analysis or a
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.buffer">ArcGISGeometryEngine.buffer</see> operation.
/// 
/// Each part of a multipart polygon is a series of connected <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> objects forming a
/// closed ring. Each part must not cross any other part, but may lie completely inside or
/// outside another part. For example, a polygon representing the state of Hawaii would comprise
/// eight disjoint parts, one representing each island. A polygon representing the country of
/// South Africa, which completely surrounds the enclave of Lesotho, would comprise two parts,
/// one contained inside the other.
/// 
/// Like polyline, the polygon class is a <see cref="Esri::GameEngine::Geometry::ArcGISMultipart">ArcGISMultipart</see>, which provides members for iterating the
/// segments and points of each part in a polygon. Unlike parts in a polyline, however, each
/// part of a polygon defines a closed area, so the end point of the last segment in the part is
/// always in the same location as the start point of the first segment, forming a closed
/// boundary. 
/// 
/// When defining a polygon part, there is no need to explicitly close it by repeating the start
/// point as the last point. Polygons parts are always interpreted as enclosed areas by the ArcGIS
/// Maps API. 
///         
/// Interior rings to make donut polygons should be counter-clockwise in direction to have the
/// correct topology.
/// 
/// If there is ever a doubt about the topological correctness of a polygon, call the 
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.simplify">ArcGISGeometryEngine.simplify</see> method to correct any issues. This is especially true
/// if you pass a polygon to ArcGIS Server for a geoprocessing task to avoid any ArcGIS Server
/// errors being thrown or to rectify polygons that may be self-intersecting, have rings which
/// are partially contained in each other, or contain incorrect ring orientations.
/// 
/// Polygons are based upon the parent <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> class. The geometry object is
/// immutable which means that you can not change its shape once it is created. If you need to
/// create a new polygon or modify it once it has been created, use the <see cref="Esri::GameEngine::Geometry::ArcGISPolygonBuilder">ArcGISPolygonBuilder</see> class.
/// 
/// A polygon can be used as the geometry of a <see cref="">Feature</see> or <see cref="">Graphic</see>. To obtain the
/// geometry on these objects, use <see cref="">GeoElement.geometry</see>.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISPolygon :
    public ArcGISMultipart
{
public:
    #pragma region Methods
    /// <summary>
    /// Creates a polyline containing paths for all the rings in this polygon.
    /// </summary>
    /// <remarks>
    /// Creates a polyline object that matches the geometry of this polygon.
    /// </remarks>
    /// <returns>
    /// A polyline.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISPolyline ToPolyline() const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISPolygon(void* handle);
    ArcGISPolygon(const ArcGISPolygon&) = delete;
    ArcGISPolygon(ArcGISPolygon&& other) noexcept;
    ArcGISPolygon();
    virtual ~ArcGISPolygon() = default;
    
    ArcGISPolygon& operator=(const ArcGISPolygon&) = delete;
    ArcGISPolygon& operator=(ArcGISPolygon&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri