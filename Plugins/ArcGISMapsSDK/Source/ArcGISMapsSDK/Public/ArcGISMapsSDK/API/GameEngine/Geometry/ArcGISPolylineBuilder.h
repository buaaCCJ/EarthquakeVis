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
class ArcGISPolyline;
class ArcGISSpatialReference;

/// <summary>
/// The polyline builder object is used to create a polyline.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISPolylineBuilder :
    public ArcGISMultipartBuilder
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a polyline builder from a polyline.
    /// </summary>
    /// <remarks>
    /// Prior to v100.12, only polylines without curves could be used; passing in a polygon where
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true would throw an exception.
    /// 
    /// From v100.12, polylines with curves are supported.
    /// </remarks>
    /// <param name="polyline">A polyline object.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <since>1.0.0</since>
    ArcGISPolylineBuilder(const ArcGISPolyline& polyline);
    
    /// <summary>
    /// Creates a polyline builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    ArcGISPolylineBuilder(const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors

public:
    #pragma region Special Members
    explicit ArcGISPolylineBuilder(void* handle);
    ArcGISPolylineBuilder(const ArcGISPolylineBuilder&) = delete;
    ArcGISPolylineBuilder(ArcGISPolylineBuilder&& other) noexcept;
    ArcGISPolylineBuilder();
    virtual ~ArcGISPolylineBuilder() = default;
    
    ArcGISPolylineBuilder& operator=(const ArcGISPolylineBuilder&) = delete;
    ArcGISPolylineBuilder& operator=(ArcGISPolylineBuilder&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri