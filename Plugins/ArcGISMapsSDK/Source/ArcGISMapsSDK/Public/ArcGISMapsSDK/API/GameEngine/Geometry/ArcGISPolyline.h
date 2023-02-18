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
/// <summary>
/// A multipart linear shape.
/// </summary>
/// <remarks>
/// Polyline geometries represent the shape and location of linear features, such as a street
/// in a road network, a contour line representing an elevation value, or a hiking trail. A
/// polyline can be used to define geometry for features and graphics, or as input or output
/// for tasks or geoprocessing operations, such as the output of a network trace.
/// 
/// A polyline can be used as the geometry of a <see cref="">Feature</see> or <see cref="">Graphic</see>. To obtain the
/// geometry on these objects, use <see cref="">GeoElement.geometry</see>.
/// 
/// A polyline is composed of a series of connected segments, where each <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> defines a
/// continuous line between a start and an end point. You can define a new polyline from a
/// collection of <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see> objects to create a series of straight <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see> objects
/// connecting the points you specified. You can use <see cref="Esri::GameEngine::Geometry::ArcGISPolylineBuilder">ArcGISPolylineBuilder</see> to build a polyline
/// one point at a time, or to modify an existing polyline.
/// 
/// A polyline can have multiple parts. Each part is a series of connected segments, but the
/// parts can be disjoint, for example, a polyline representing a street that ends, and starts
/// again a block later. Parts can also intersect at one or more points (or vertices), for
/// example, a polyline representing a river and its tributaries.
/// 
/// Polylines inherit from <see cref="Esri::GameEngine::Geometry::ArcGISMultipart">ArcGISMultipart</see>, which provides members for iterating the segments and
/// points of each part in a polyline.
/// 
/// Polylines are based upon the parent <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> class which is immutable, meaning you can
/// not change its shape once it is created. If you need to modify a polyline once it has been
/// created, use the <see cref="Esri::GameEngine::Geometry::ArcGISPolylineBuilder">ArcGISPolylineBuilder</see> class.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISPolyline :
    public ArcGISMultipart
{
public:

public:
    #pragma region Special Members
    explicit ArcGISPolyline(void* handle);
    ArcGISPolyline(const ArcGISPolyline&) = delete;
    ArcGISPolyline(ArcGISPolyline&& other) noexcept;
    ArcGISPolyline();
    virtual ~ArcGISPolyline() = default;
    
    ArcGISPolyline& operator=(const ArcGISPolyline&) = delete;
    ArcGISPolyline& operator=(ArcGISPolyline&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri