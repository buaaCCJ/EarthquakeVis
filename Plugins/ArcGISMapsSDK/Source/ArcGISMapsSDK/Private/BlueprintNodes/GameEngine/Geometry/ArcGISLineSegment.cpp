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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLineSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLineSegment.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISLineSegment* UArcGISLineSegment::CreateArcGISLineSegmentWithXY(double xStart, double yStart, double xEnd, double yEnd)
{
    auto result = NewObject<UArcGISLineSegment>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLineSegment>(xStart, yStart, xEnd, yEnd);
    
    return result;
}

UArcGISLineSegment* UArcGISLineSegment::CreateArcGISLineSegmentWithXYZ(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd)
{
    auto result = NewObject<UArcGISLineSegment>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLineSegment>(xStart, yStart, zStart, xEnd, yEnd, zEnd);
    
    return result;
}

UArcGISLineSegment* UArcGISLineSegment::CreateArcGISLineSegmentWithXYZSpatialReference(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd, UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISLineSegment>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLineSegment>(xStart, yStart, zStart, xEnd, yEnd, zEnd, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISLineSegment* UArcGISLineSegment::CreateArcGISLineSegmentWithXYSpatialReference(double xStart, double yStart, double xEnd, double yEnd, UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISLineSegment>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLineSegment>(xStart, yStart, xEnd, yEnd, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISLineSegment* UArcGISLineSegment::CreateArcGISLineSegment(UArcGISPoint* startPoint, UArcGISPoint* endPoint)
{
    auto result = NewObject<UArcGISLineSegment>();
    
    auto nullStartPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedStartPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(startPoint->APIObject);
    auto nullEndPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedEndPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(endPoint->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLineSegment>(startPoint ? *derivedStartPointAPIObject : nullStartPoint, endPoint ? *derivedEndPointAPIObject : nullEndPoint);
    
    return result;
}

UArcGISLineSegment* UArcGISLineSegment::CreateArcGISLineSegmentWithSpatialReference(UArcGISPoint* startPoint, UArcGISPoint* endPoint, UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISLineSegment>();
    
    auto nullStartPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedStartPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(startPoint->APIObject);
    auto nullEndPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedEndPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(endPoint->APIObject);
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLineSegment>(startPoint ? *derivedStartPointAPIObject : nullStartPoint, endPoint ? *derivedEndPointAPIObject : nullEndPoint, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISLineSegment* UArcGISLineSegment::CreateLineAtAngleFromStartPoint(UArcGISPoint* startPoint, double angleRadians, double length)
{
    auto nullStartPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedStartPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(startPoint->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISLineSegment::CreateLineAtAngleFromStartPoint(startPoint ? *derivedStartPointAPIObject : nullStartPoint, angleRadians, length);
    
    auto localLocalResult = NewObject<UArcGISLineSegment>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLineSegment>(std::move(localResult));
    
    return localLocalResult;
}