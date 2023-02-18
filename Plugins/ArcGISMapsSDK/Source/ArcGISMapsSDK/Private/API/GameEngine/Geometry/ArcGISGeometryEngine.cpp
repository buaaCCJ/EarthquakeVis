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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAngularUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAreaUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDatumTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelope.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodesicEllipseParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodesicSectorParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodeticCurveType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodeticDistanceResult.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometry.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryEngine.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryExtendOptions.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryOffsetType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygon.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISProximityResult.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISList.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Geometry.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryEngine.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
double ArcGISGeometryEngine::Area(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_area(localGeometry, &errorHandler);
    
    return localResult;
}

double ArcGISGeometryEngine::AreaGeodetic(const ArcGISGeometry& geometry, const ArcGISAreaUnit& unit, ArcGISGeodeticCurveType curveType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localUnit = static_cast<const RT_AreaUnitHandle>(unit.GetHandle());
    
    auto localResult = RT_GeometryEngine_areaGeodetic(localGeometry, localUnit, static_cast<RT_GeodeticCurveType>(curveType), &errorHandler);
    
    return localResult;
}

Unreal::ArcGISImmutableArray<ArcGISPolygon> ArcGISGeometryEngine::AutoComplete(const Unreal::ArcGISList<ArcGISPolygon>& existingBoundaries, const Unreal::ArcGISList<ArcGISPolyline>& newBoundaries)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localExistingBoundaries = static_cast<const RT_VectorHandle>(existingBoundaries.GetHandle());
    const auto localNewBoundaries = static_cast<const RT_VectorHandle>(newBoundaries.GetHandle());
    
    auto localResult = RT_GeometryEngine_autoComplete(localExistingBoundaries, localNewBoundaries, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISPolygon>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISPolygon>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Boundary(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_boundary(localGeometry, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISPolygon ArcGISGeometryEngine::Buffer(const ArcGISGeometry& geometry, double distance)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_buffer(localGeometry, distance, &errorHandler);
    
    auto localLocalResult = ArcGISPolygon{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPolygon{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISImmutableArray<ArcGISPolygon> ArcGISGeometryEngine::Buffer(const Unreal::ArcGISList<ArcGISGeometry>& geometries, const Unreal::ArcGISList<double>& distances, bool unionResult)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometries = static_cast<const RT_VectorHandle>(geometries.GetHandle());
    const auto localDistances = static_cast<const RT_VectorHandle>(distances.GetHandle());
    
    auto localResult = RT_GeometryEngine_bufferCollection(localGeometries, localDistances, unionResult, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISPolygon>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISPolygon>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPolygon ArcGISGeometryEngine::BufferGeodetic(const ArcGISGeometry& geometry, double distance, const ArcGISLinearUnit& distanceUnit, double maxDeviation, ArcGISGeodeticCurveType curveType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localDistanceUnit = static_cast<const RT_LinearUnitHandle>(distanceUnit.GetHandle());
    
    auto localResult = RT_GeometryEngine_bufferGeodetic(localGeometry, distance, localDistanceUnit, maxDeviation, static_cast<RT_GeodeticCurveType>(curveType), &errorHandler);
    
    auto localLocalResult = ArcGISPolygon{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPolygon{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISImmutableArray<ArcGISPolygon> ArcGISGeometryEngine::BufferGeodetic(const Unreal::ArcGISList<ArcGISGeometry>& geometries, const Unreal::ArcGISList<double>& distances, const ArcGISLinearUnit& distanceUnit, double maxDeviation, ArcGISGeodeticCurveType curveType, bool unionResult)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometries = static_cast<const RT_VectorHandle>(geometries.GetHandle());
    const auto localDistances = static_cast<const RT_VectorHandle>(distances.GetHandle());
    const auto localDistanceUnit = static_cast<const RT_LinearUnitHandle>(distanceUnit.GetHandle());
    
    auto localResult = RT_GeometryEngine_bufferGeodeticCollection(localGeometries, localDistances, localDistanceUnit, maxDeviation, static_cast<RT_GeodeticCurveType>(curveType), unionResult, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISPolygon>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISPolygon>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Clip(const ArcGISGeometry& geometry, const ArcGISEnvelope& envelope)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localEnvelope = static_cast<const RT_EnvelopeHandle>(envelope.GetHandle());
    
    auto localResult = RT_GeometryEngine_clip(localGeometry, localEnvelope, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISEnvelope ArcGISGeometryEngine::CombineExtents(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_combineExtents(localGeometry1, localGeometry2, &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

ArcGISEnvelope ArcGISGeometryEngine::CombineExtents(const Unreal::ArcGISList<ArcGISGeometry>& geometries)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometries = static_cast<const RT_VectorHandle>(geometries.GetHandle());
    
    auto localResult = RT_GeometryEngine_combineExtentsCollection(localGeometries, &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Contains(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_contains(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}

ArcGISGeometry ArcGISGeometryEngine::ConvexHull(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_convexHull(localGeometry, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

Unreal::ArcGISImmutableArray<ArcGISGeometry> ArcGISGeometryEngine::ConvexHull(const Unreal::ArcGISList<ArcGISGeometry>& geometries, bool merge)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometries = static_cast<const RT_VectorHandle>(geometries.GetHandle());
    
    auto localResult = RT_GeometryEngine_convexHullCollection(localGeometries, merge, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISGeometry>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISGeometry>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISGeometryEngine::CreatePointAlong(const ArcGISPolyline& polyline, double distance)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPolyline = static_cast<const RT_PolylineHandle>(polyline.GetHandle());
    
    auto localResult = RT_GeometryEngine_createPointAlong(localPolyline, distance, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Crosses(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_crosses(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}

Unreal::ArcGISImmutableArray<ArcGISGeometry> ArcGISGeometryEngine::Cut(const ArcGISGeometry& geometry, const ArcGISPolyline& cutter)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localCutter = static_cast<const RT_PolylineHandle>(cutter.GetHandle());
    
    auto localResult = RT_GeometryEngine_cut(localGeometry, localCutter, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISGeometry>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISGeometry>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Densify(const ArcGISGeometry& geometry, double maxSegmentLength)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_densify(localGeometry, maxSegmentLength, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::DensifyGeodetic(const ArcGISGeometry& geometry, double maxSegmentLength, const ArcGISLinearUnit& lengthUnit, ArcGISGeodeticCurveType curveType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localLengthUnit = static_cast<const RT_LinearUnitHandle>(lengthUnit.GetHandle());
    
    auto localResult = RT_GeometryEngine_densifyGeodetic(localGeometry, maxSegmentLength, localLengthUnit, static_cast<RT_GeodeticCurveType>(curveType), &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Difference(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_difference(localGeometry1, localGeometry2, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Disjoint(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_disjoint(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}

double ArcGISGeometryEngine::Distance(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_distance(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}

ArcGISGeodeticDistanceResult ArcGISGeometryEngine::DistanceGeodetic(const ArcGISPoint& point1, const ArcGISPoint& point2, const ArcGISLinearUnit& distanceUnit, const ArcGISAngularUnit& azimuthUnit, ArcGISGeodeticCurveType curveType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint1 = static_cast<const RT_PointHandle>(point1.GetHandle());
    const auto localPoint2 = static_cast<const RT_PointHandle>(point2.GetHandle());
    const auto localDistanceUnit = static_cast<const RT_LinearUnitHandle>(distanceUnit.GetHandle());
    const auto localAzimuthUnit = static_cast<const RT_AngularUnitHandle>(azimuthUnit.GetHandle());
    
    auto localResult = RT_GeometryEngine_distanceGeodetic(localPoint1, localPoint2, localDistanceUnit, localAzimuthUnit, static_cast<RT_GeodeticCurveType>(curveType), &errorHandler);
    
    auto localLocalResult = ArcGISGeodeticDistanceResult{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISGeodeticDistanceResult{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::EllipseGeodesic(const ArcGISGeodesicEllipseParameters& parameters)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localParameters = static_cast<const RT_GeodesicEllipseParametersHandle>(parameters.GetHandle());
    
    auto localResult = RT_GeometryEngine_ellipseGeodesic(localParameters, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Equals(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_equals(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}

ArcGISPolyline ArcGISGeometryEngine::Extend(const ArcGISPolyline& polyline, const ArcGISPolyline& extender, ArcGISGeometryExtendOptions extendOptions)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPolyline = static_cast<const RT_PolylineHandle>(polyline.GetHandle());
    const auto localExtender = static_cast<const RT_PolylineHandle>(extender.GetHandle());
    
    auto localResult = RT_GeometryEngine_extend(localPolyline, localExtender, static_cast<RT_GeometryExtendOptions>(extendOptions), &errorHandler);
    
    auto localLocalResult = ArcGISPolyline{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPolyline{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISGeometryEngine::FractionAlong(const ArcGISPolyline& line, const ArcGISPoint& point, double tolerance)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLine = static_cast<const RT_PolylineHandle>(line.GetHandle());
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_GeometryEngine_fractionAlong(localLine, localPoint, tolerance, &errorHandler);
    
    return localResult;
}

ArcGISGeometry ArcGISGeometryEngine::Generalize(const ArcGISGeometry& geometry, double maxDeviation, bool removeDegenerateParts)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_generalize(localGeometry, maxDeviation, removeDegenerateParts, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Intersection(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_intersection(localGeometry1, localGeometry2, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

Unreal::ArcGISImmutableArray<ArcGISGeometry> ArcGISGeometryEngine::Intersections(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_intersections(localGeometry1, localGeometry2, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISGeometry>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISGeometry>{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Intersects(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_intersects(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}

bool ArcGISGeometryEngine::IsSimple(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_isSimple(localGeometry, &errorHandler);
    
    return localResult;
}

ArcGISPoint ArcGISGeometryEngine::LabelPoint(const ArcGISPolygon& polygon)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPolygon = static_cast<const RT_PolygonHandle>(polygon.GetHandle());
    
    auto localResult = RT_GeometryEngine_labelPoint(localPolygon, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISGeometryEngine::Length(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_length(localGeometry, &errorHandler);
    
    return localResult;
}

double ArcGISGeometryEngine::LengthGeodetic(const ArcGISGeometry& geometry, const ArcGISLinearUnit& lengthUnit, ArcGISGeodeticCurveType curveType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localLengthUnit = static_cast<const RT_LinearUnitHandle>(lengthUnit.GetHandle());
    
    auto localResult = RT_GeometryEngine_lengthGeodetic(localGeometry, localLengthUnit, static_cast<RT_GeodeticCurveType>(curveType), &errorHandler);
    
    return localResult;
}

Unreal::ArcGISImmutableArray<ArcGISPoint> ArcGISGeometryEngine::MoveGeodetic(const Unreal::ArcGISList<ArcGISPoint>& pointCollection, double distance, const ArcGISLinearUnit& distanceUnit, double azimuth, const ArcGISAngularUnit& azimuthUnit, ArcGISGeodeticCurveType curveType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPointCollection = static_cast<const RT_VectorHandle>(pointCollection.GetHandle());
    const auto localDistanceUnit = static_cast<const RT_LinearUnitHandle>(distanceUnit.GetHandle());
    const auto localAzimuthUnit = static_cast<const RT_AngularUnitHandle>(azimuthUnit.GetHandle());
    
    auto localResult = RT_GeometryEngine_moveGeodetic(localPointCollection, distance, localDistanceUnit, azimuth, localAzimuthUnit, static_cast<RT_GeodeticCurveType>(curveType), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISPoint>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISPoint>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISProximityResult ArcGISGeometryEngine::NearestCoordinate(const ArcGISGeometry& geometry, const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_GeometryEngine_nearestCoordinate(localGeometry, localPoint, &errorHandler);
    
    auto localLocalResult = ArcGISProximityResult{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISProximityResult{ localResult };
    }
    
    return localLocalResult;
}

ArcGISProximityResult ArcGISGeometryEngine::NearestCoordinateGeodetic(const ArcGISGeometry& geometry, const ArcGISPoint& point, double maxDeviation, const ArcGISLinearUnit& deviationUnit)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    const auto localDeviationUnit = static_cast<const RT_LinearUnitHandle>(deviationUnit.GetHandle());
    
    auto localResult = RT_GeometryEngine_nearestCoordinateGeodetic(localGeometry, localPoint, maxDeviation, localDeviationUnit, &errorHandler);
    
    auto localLocalResult = ArcGISProximityResult{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISProximityResult{ localResult };
    }
    
    return localLocalResult;
}

ArcGISProximityResult ArcGISGeometryEngine::NearestVertex(const ArcGISGeometry& geometry, const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_GeometryEngine_nearestVertex(localGeometry, localPoint, &errorHandler);
    
    auto localLocalResult = ArcGISProximityResult{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISProximityResult{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::NormalizeCentralMeridian(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_normalizeCentralMeridian(localGeometry, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Offset(const ArcGISGeometry& geometry, double distance, ArcGISGeometryOffsetType offsetType, double bevelRatio, double flattenError)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_offset(localGeometry, distance, static_cast<RT_GeometryOffsetType>(offsetType), bevelRatio, flattenError, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Overlaps(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_overlaps(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}

ArcGISGeometry ArcGISGeometryEngine::Project(const ArcGISGeometry& geometry, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_GeometryEngine_project(localGeometry, localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Project(const ArcGISGeometry& geometry, const ArcGISSpatialReference& outputSpatialReference, const ArcGISDatumTransformation& datumTransformation)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    const auto localOutputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(outputSpatialReference.GetHandle());
    const auto localDatumTransformation = static_cast<const RT_DatumTransformationHandle>(datumTransformation.GetHandle());
    
    auto localResult = RT_GeometryEngine_projectWithTransformation(localGeometry, localOutputSpatialReference, localDatumTransformation, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Relate(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2, const FString& relation)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_relate(localGeometry1, localGeometry2, TCHAR_TO_ANSI(*relation), &errorHandler);
    
    return localResult;
}

ArcGISGeometry ArcGISGeometryEngine::RemoveM(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_removeM(localGeometry, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::RemoveZ(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_removeZ(localGeometry, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::RemoveZAndM(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_removeZAndM(localGeometry, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISMultipart ArcGISGeometryEngine::Reshape(const ArcGISMultipart& geometry, const ArcGISPolyline& reshaper)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_MultipartHandle>(geometry.GetHandle());
    const auto localReshaper = static_cast<const RT_PolylineHandle>(reshaper.GetHandle());
    
    auto localResult = RT_GeometryEngine_reshape(localGeometry, localReshaper, &errorHandler);
    
    auto localLocalResult = ArcGISMultipart{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISMultipart{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::SectorGeodesic(const ArcGISGeodesicSectorParameters& parameters)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localParameters = static_cast<const RT_GeodesicSectorParametersHandle>(parameters.GetHandle());
    
    auto localResult = RT_GeometryEngine_sectorGeodesic(localParameters, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::SetM(const ArcGISGeometry& geometry, double m)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_setM(localGeometry, m, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::SetZ(const ArcGISGeometry& geometry, double z)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_setZ(localGeometry, z, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::SetZAndM(const ArcGISGeometry& geometry, double z, double m)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_setZAndM(localGeometry, z, m, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Simplify(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryEngine_simplify(localGeometry, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::SymmetricDifference(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_symmetricDifference(localGeometry1, localGeometry2, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Touches(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_touches(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}

ArcGISGeometry ArcGISGeometryEngine::Union(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_union(localGeometry1, localGeometry2, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry ArcGISGeometryEngine::Union(const Unreal::ArcGISList<ArcGISGeometry>& geometries)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometries = static_cast<const RT_VectorHandle>(geometries.GetHandle());
    
    auto localResult = RT_GeometryEngine_unionCollection(localGeometries, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

bool ArcGISGeometryEngine::Within(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry1 = static_cast<const RT_GeometryHandle>(geometry1.GetHandle());
    const auto localGeometry2 = static_cast<const RT_GeometryHandle>(geometry2.GetHandle());
    
    auto localResult = RT_GeometryEngine_within(localGeometry1, localGeometry2, &errorHandler);
    
    return localResult;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri