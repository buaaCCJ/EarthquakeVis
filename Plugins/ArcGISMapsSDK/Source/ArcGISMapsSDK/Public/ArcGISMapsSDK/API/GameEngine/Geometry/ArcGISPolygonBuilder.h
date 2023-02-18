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

#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipartBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPolygon;
class ArcGISPolyline;
class ArcGISSpatialReference;

/// <summary>
/// The polygon builder object is used to create a polygon.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISPolygonBuilder :
    public ArcGISMultipartBuilder
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a polygon builder from a polygon.
    /// </summary>
    /// <remarks>
    /// Prior to v100.12, only polygons without curves could be used; passing in a polygon where
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true would throw an exception.
    /// 
    /// From v100.12, polygons with curves are supported.
    /// </remarks>
    /// <param name="polygon">A polygon object.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <since>1.0.0</since>
    ArcGISPolygonBuilder(const ArcGISPolygon& polygon);
    
    /// <summary>
    /// Creates a polygon builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    ArcGISPolygonBuilder(const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors
    
    #pragma region Methods
    /// <summary>
    /// Creates a polyline with the values in the polygon builder.
    /// </summary>
    /// <remarks>
    /// Creates the polyline object described by this builder.
    /// </remarks>
    /// <returns>
    /// A polyline.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISPolyline ToPolyline() const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISPolygonBuilder(void* handle);
    ArcGISPolygonBuilder(const ArcGISPolygonBuilder&) = delete;
    ArcGISPolygonBuilder(ArcGISPolygonBuilder&& other) noexcept;
    ArcGISPolygonBuilder();
    virtual ~ArcGISPolygonBuilder() = default;
    
    ArcGISPolygonBuilder& operator=(const ArcGISPolygonBuilder&) = delete;
    ArcGISPolygonBuilder& operator=(ArcGISPolygonBuilder&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri