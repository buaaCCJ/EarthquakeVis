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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEllipticArcSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISEllipticArcSegment.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISEllipticArcSegment* UArcGISEllipticArcSegment::CreateArcGISEllipticArcSegmentWithCenter(UArcGISPoint* centerPoint, double rotationAngle, double semiMajorAxis, double minorMajorRatio, double startAngle, double centralAngle, UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISEllipticArcSegment>();
    
    auto nullCenterPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(centerPoint->APIObject);
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(centerPoint ? *derivedCenterPointAPIObject : nullCenterPoint, rotationAngle, semiMajorAxis, minorMajorRatio, startAngle, centralAngle, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISEllipticArcSegment* UArcGISEllipticArcSegment::CreateArcGISEllipticArcSegmentWithStartAndEndpoints(UArcGISPoint* startPoint, UArcGISPoint* endPoint, double rotationAngle, bool isMinor, bool isCounterClockwise, double semiMajorAxis, double minorMajorRatio, UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISEllipticArcSegment>();
    
    auto nullStartPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedStartPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(startPoint->APIObject);
    auto nullEndPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedEndPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(endPoint->APIObject);
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(startPoint ? *derivedStartPointAPIObject : nullStartPoint, endPoint ? *derivedEndPointAPIObject : nullEndPoint, rotationAngle, isMinor, isCounterClockwise, semiMajorAxis, minorMajorRatio, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISPoint* UArcGISEllipticArcSegment::GetCenterPoint()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetCenterPoint();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

double UArcGISEllipticArcSegment::GetCentralAngle()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetCentralAngle();
    
    return localResult;
}

double UArcGISEllipticArcSegment::GetEndAngle()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetEndAngle();
    
    return localResult;
}

bool UArcGISEllipticArcSegment::GetIsCircular()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetIsCircular();
    
    return localResult;
}

bool UArcGISEllipticArcSegment::GetIsCounterClockwise()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetIsCounterClockwise();
    
    return localResult;
}

double UArcGISEllipticArcSegment::GetMinorMajorRatio()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetMinorMajorRatio();
    
    return localResult;
}

double UArcGISEllipticArcSegment::GetRotationAngle()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetRotationAngle();
    
    return localResult;
}

double UArcGISEllipticArcSegment::GetSemiMajorAxis()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetSemiMajorAxis();
    
    return localResult;
}

double UArcGISEllipticArcSegment::GetSemiMinorAxis()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetSemiMinorAxis();
    
    return localResult;
}

double UArcGISEllipticArcSegment::GetStartAngle()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetStartAngle();
    
    return localResult;
}

UArcGISEllipticArcSegment* UArcGISEllipticArcSegment::CreateCircularEllipticArcWithCenterRadiusAndAngles(UArcGISPoint* centerPoint, double radius, double startAngle, double centralAngle, UArcGISSpatialReference* spatialReference)
{
    auto nullCenterPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(centerPoint->APIObject);
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISEllipticArcSegment::CreateCircularEllipticArc(centerPoint ? *derivedCenterPointAPIObject : nullCenterPoint, radius, startAngle, centralAngle, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISEllipticArcSegment>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISEllipticArcSegment* UArcGISEllipticArcSegment::CreateCircularEllipticArcWithStartEndAndInterior(UArcGISPoint* startPoint, UArcGISPoint* endPoint, UArcGISPoint* interiorPoint, UArcGISSpatialReference* spatialReference)
{
    auto nullStartPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedStartPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(startPoint->APIObject);
    auto nullEndPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedEndPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(endPoint->APIObject);
    auto nullInteriorPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedInteriorPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(interiorPoint->APIObject);
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISEllipticArcSegment::CreateCircularEllipticArc(startPoint ? *derivedStartPointAPIObject : nullStartPoint, endPoint ? *derivedEndPointAPIObject : nullEndPoint, interiorPoint ? *derivedInteriorPointAPIObject : nullInteriorPoint, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISEllipticArcSegment>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISEllipticArcSegment>(std::move(localResult));
    
    return localLocalResult;
}