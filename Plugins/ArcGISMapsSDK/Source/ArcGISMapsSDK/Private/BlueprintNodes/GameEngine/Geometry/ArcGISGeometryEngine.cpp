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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodesicEllipseParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodesicSectorParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodeticCurveType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodeticDistanceResult.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometry.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryEngine.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryExtendOptions.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryOffsetType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygon.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISProximityResult.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAngularUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAreaUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISDatumTransformation.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeodesicEllipseParameters.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeodesicSectorParameters.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeodeticCurveType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeodeticDistanceResult.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometry.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryEngine.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryExtendOptions.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryOffsetType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMultipart.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPolygon.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISProximityResult.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

double UArcGISGeometryEngine::Area(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Area(geometry ? *geometry->APIObject : nullGeometry);
    
    return localResult;
}

double UArcGISGeometryEngine::AreaGeodetic(UArcGISGeometry* geometry, UArcGISAreaUnit* unit, EArcGISGeodeticCurveType::Type curveType)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullUnit = Esri::GameEngine::Geometry::ArcGISAreaUnit{};
    auto derivedUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(unit->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::AreaGeodetic(geometry ? *geometry->APIObject : nullGeometry, unit ? *derivedUnitAPIObject : nullUnit, static_cast<Esri::GameEngine::Geometry::ArcGISGeodeticCurveType>(curveType));
    
    return localResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Boundary(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Boundary(geometry ? *geometry->APIObject : nullGeometry);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPolygon* UArcGISGeometryEngine::Buffer(UArcGISGeometry* geometry, double distance)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Buffer(geometry ? *geometry->APIObject : nullGeometry, distance);
    
    auto localLocalResult = NewObject<UArcGISPolygon>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPolygon>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPolygon* UArcGISGeometryEngine::BufferGeodetic(UArcGISGeometry* geometry, double distance, UArcGISLinearUnit* distanceUnit, double maxDeviation, EArcGISGeodeticCurveType::Type curveType)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullDistanceUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedDistanceUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(distanceUnit->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::BufferGeodetic(geometry ? *geometry->APIObject : nullGeometry, distance, distanceUnit ? *derivedDistanceUnitAPIObject : nullDistanceUnit, maxDeviation, static_cast<Esri::GameEngine::Geometry::ArcGISGeodeticCurveType>(curveType));
    
    auto localLocalResult = NewObject<UArcGISPolygon>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPolygon>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Contains(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Contains(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}

UArcGISGeometry* UArcGISGeometryEngine::ConvexHull(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::ConvexHull(geometry ? *geometry->APIObject : nullGeometry);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISGeometryEngine::CreatePointAlong(UArcGISPolyline* polyline, double distance)
{
    auto nullPolyline = Esri::GameEngine::Geometry::ArcGISPolyline{};
    auto derivedPolylineAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolyline>(polyline->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::CreatePointAlong(polyline ? *derivedPolylineAPIObject : nullPolyline, distance);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Crosses(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Crosses(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Densify(UArcGISGeometry* geometry, double maxSegmentLength)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Densify(geometry ? *geometry->APIObject : nullGeometry, maxSegmentLength);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::DensifyGeodetic(UArcGISGeometry* geometry, double maxSegmentLength, UArcGISLinearUnit* lengthUnit, EArcGISGeodeticCurveType::Type curveType)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullLengthUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedLengthUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(lengthUnit->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::DensifyGeodetic(geometry ? *geometry->APIObject : nullGeometry, maxSegmentLength, lengthUnit ? *derivedLengthUnitAPIObject : nullLengthUnit, static_cast<Esri::GameEngine::Geometry::ArcGISGeodeticCurveType>(curveType));
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Difference(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Difference(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Disjoint(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Disjoint(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}

double UArcGISGeometryEngine::Distance(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Distance(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}

UArcGISGeodeticDistanceResult* UArcGISGeometryEngine::DistanceGeodetic(UArcGISPoint* point1, UArcGISPoint* point2, UArcGISLinearUnit* distanceUnit, UArcGISAngularUnit* azimuthUnit, EArcGISGeodeticCurveType::Type curveType)
{
    auto nullPoint1 = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPoint1APIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point1->APIObject);
    auto nullPoint2 = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPoint2APIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point2->APIObject);
    auto nullDistanceUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedDistanceUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(distanceUnit->APIObject);
    auto nullAzimuthUnit = Esri::GameEngine::Geometry::ArcGISAngularUnit{};
    auto derivedAzimuthUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(azimuthUnit->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::DistanceGeodetic(point1 ? *derivedPoint1APIObject : nullPoint1, point2 ? *derivedPoint2APIObject : nullPoint2, distanceUnit ? *derivedDistanceUnitAPIObject : nullDistanceUnit, azimuthUnit ? *derivedAzimuthUnitAPIObject : nullAzimuthUnit, static_cast<Esri::GameEngine::Geometry::ArcGISGeodeticCurveType>(curveType));
    
    auto localLocalResult = NewObject<UArcGISGeodeticDistanceResult>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeodeticDistanceResult>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::EllipseGeodesic(UArcGISGeodesicEllipseParameters* parameters)
{
    auto nullParameters = Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::EllipseGeodesic(parameters ? *parameters->APIObject : nullParameters);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Equals(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Equals(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}

UArcGISPolyline* UArcGISGeometryEngine::Extend(UArcGISPolyline* polyline, UArcGISPolyline* extender, EArcGISGeometryExtendOptions::Type extendOptions)
{
    auto nullPolyline = Esri::GameEngine::Geometry::ArcGISPolyline{};
    auto derivedPolylineAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolyline>(polyline->APIObject);
    auto nullExtender = Esri::GameEngine::Geometry::ArcGISPolyline{};
    auto derivedExtenderAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolyline>(extender->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Extend(polyline ? *derivedPolylineAPIObject : nullPolyline, extender ? *derivedExtenderAPIObject : nullExtender, static_cast<Esri::GameEngine::Geometry::ArcGISGeometryExtendOptions>(extendOptions));
    
    auto localLocalResult = NewObject<UArcGISPolyline>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPolyline>(std::move(localResult));
    
    return localLocalResult;
}

double UArcGISGeometryEngine::FractionAlong(UArcGISPolyline* line, UArcGISPoint* point, double tolerance)
{
    auto nullLine = Esri::GameEngine::Geometry::ArcGISPolyline{};
    auto derivedLineAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolyline>(line->APIObject);
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::FractionAlong(line ? *derivedLineAPIObject : nullLine, point ? *derivedPointAPIObject : nullPoint, tolerance);
    
    return localResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Generalize(UArcGISGeometry* geometry, double maxDeviation, bool removeDegenerateParts)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Generalize(geometry ? *geometry->APIObject : nullGeometry, maxDeviation, removeDegenerateParts);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Intersection(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Intersection(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Intersects(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Intersects(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}

bool UArcGISGeometryEngine::IsSimple(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::IsSimple(geometry ? *geometry->APIObject : nullGeometry);
    
    return localResult;
}

UArcGISPoint* UArcGISGeometryEngine::LabelPoint(UArcGISPolygon* polygon)
{
    auto nullPolygon = Esri::GameEngine::Geometry::ArcGISPolygon{};
    auto derivedPolygonAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolygon>(polygon->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::LabelPoint(polygon ? *derivedPolygonAPIObject : nullPolygon);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

double UArcGISGeometryEngine::Length(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Length(geometry ? *geometry->APIObject : nullGeometry);
    
    return localResult;
}

double UArcGISGeometryEngine::LengthGeodetic(UArcGISGeometry* geometry, UArcGISLinearUnit* lengthUnit, EArcGISGeodeticCurveType::Type curveType)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullLengthUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedLengthUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(lengthUnit->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::LengthGeodetic(geometry ? *geometry->APIObject : nullGeometry, lengthUnit ? *derivedLengthUnitAPIObject : nullLengthUnit, static_cast<Esri::GameEngine::Geometry::ArcGISGeodeticCurveType>(curveType));
    
    return localResult;
}

UArcGISProximityResult* UArcGISGeometryEngine::NearestCoordinate(UArcGISGeometry* geometry, UArcGISPoint* point)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::NearestCoordinate(geometry ? *geometry->APIObject : nullGeometry, point ? *derivedPointAPIObject : nullPoint);
    
    auto localLocalResult = NewObject<UArcGISProximityResult>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISProximityResult>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISProximityResult* UArcGISGeometryEngine::NearestCoordinateGeodetic(UArcGISGeometry* geometry, UArcGISPoint* point, double maxDeviation, UArcGISLinearUnit* deviationUnit)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    auto nullDeviationUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedDeviationUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(deviationUnit->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::NearestCoordinateGeodetic(geometry ? *geometry->APIObject : nullGeometry, point ? *derivedPointAPIObject : nullPoint, maxDeviation, deviationUnit ? *derivedDeviationUnitAPIObject : nullDeviationUnit);
    
    auto localLocalResult = NewObject<UArcGISProximityResult>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISProximityResult>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISProximityResult* UArcGISGeometryEngine::NearestVertex(UArcGISGeometry* geometry, UArcGISPoint* point)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::NearestVertex(geometry ? *geometry->APIObject : nullGeometry, point ? *derivedPointAPIObject : nullPoint);
    
    auto localLocalResult = NewObject<UArcGISProximityResult>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISProximityResult>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::NormalizeCentralMeridian(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::NormalizeCentralMeridian(geometry ? *geometry->APIObject : nullGeometry);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Offset(UArcGISGeometry* geometry, double distance, EArcGISGeometryOffsetType::Type offsetType, double bevelRatio, double flattenError)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Offset(geometry ? *geometry->APIObject : nullGeometry, distance, static_cast<Esri::GameEngine::Geometry::ArcGISGeometryOffsetType>(offsetType), bevelRatio, flattenError);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Overlaps(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Overlaps(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Project(UArcGISGeometry* geometry, UArcGISSpatialReference* spatialReference)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Project(geometry ? *geometry->APIObject : nullGeometry, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::ProjectWithTransformation(UArcGISGeometry* geometry, UArcGISSpatialReference* outputSpatialReference, UArcGISDatumTransformation* datumTransformation)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullOutputSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    auto nullDatumTransformation = Esri::GameEngine::Geometry::ArcGISDatumTransformation{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Project(geometry ? *geometry->APIObject : nullGeometry, outputSpatialReference ? *outputSpatialReference->APIObject : nullOutputSpatialReference, datumTransformation ? *datumTransformation->APIObject : nullDatumTransformation);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Relate(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2, FString relation)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Relate(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2, relation);
    
    return localResult;
}

UArcGISGeometry* UArcGISGeometryEngine::RemoveM(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::RemoveM(geometry ? *geometry->APIObject : nullGeometry);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::RemoveZ(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::RemoveZ(geometry ? *geometry->APIObject : nullGeometry);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::RemoveZAndM(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::RemoveZAndM(geometry ? *geometry->APIObject : nullGeometry);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISMultipart* UArcGISGeometryEngine::Reshape(UArcGISMultipart* geometry, UArcGISPolyline* reshaper)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISMultipart{};
    auto derivedGeometryAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipart>(geometry->APIObject);
    auto nullReshaper = Esri::GameEngine::Geometry::ArcGISPolyline{};
    auto derivedReshaperAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolyline>(reshaper->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Reshape(geometry ? *derivedGeometryAPIObject : nullGeometry, reshaper ? *derivedReshaperAPIObject : nullReshaper);
    
    auto localLocalResult = NewObject<UArcGISMultipart>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMultipart>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::SectorGeodesic(UArcGISGeodesicSectorParameters* parameters)
{
    auto nullParameters = Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::SectorGeodesic(parameters ? *parameters->APIObject : nullParameters);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::SetM(UArcGISGeometry* geometry, double m)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::SetM(geometry ? *geometry->APIObject : nullGeometry, m);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::SetZ(UArcGISGeometry* geometry, double z)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::SetZ(geometry ? *geometry->APIObject : nullGeometry, z);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::SetZAndM(UArcGISGeometry* geometry, double z, double m)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::SetZAndM(geometry ? *geometry->APIObject : nullGeometry, z, m);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Simplify(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Simplify(geometry ? *geometry->APIObject : nullGeometry);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometry* UArcGISGeometryEngine::SymmetricDifference(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::SymmetricDifference(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Touches(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Touches(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}

UArcGISGeometry* UArcGISGeometryEngine::Union(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Union(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometryEngine::Within(UArcGISGeometry* geometry1, UArcGISGeometry* geometry2)
{
    auto nullGeometry1 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    auto nullGeometry2 = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryEngine::Within(geometry1 ? *geometry1->APIObject : nullGeometry1, geometry2 ? *geometry2->APIObject : nullGeometry2);
    
    return localResult;
}