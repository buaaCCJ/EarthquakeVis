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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISCubicBezierSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISCubicBezierSegment.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISCubicBezierSegment* UArcGISCubicBezierSegment::CreateArcGISCubicBezierSegment(UArcGISPoint* startPoint, UArcGISPoint* controlPoint1, UArcGISPoint* controlPoint2, UArcGISPoint* endPoint, UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISCubicBezierSegment>();
    
    auto nullStartPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedStartPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(startPoint->APIObject);
    auto nullControlPoint1 = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedControlPoint1APIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(controlPoint1->APIObject);
    auto nullControlPoint2 = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedControlPoint2APIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(controlPoint2->APIObject);
    auto nullEndPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedEndPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(endPoint->APIObject);
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISCubicBezierSegment>(startPoint ? *derivedStartPointAPIObject : nullStartPoint, controlPoint1 ? *derivedControlPoint1APIObject : nullControlPoint1, controlPoint2 ? *derivedControlPoint2APIObject : nullControlPoint2, endPoint ? *derivedEndPointAPIObject : nullEndPoint, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISPoint* UArcGISCubicBezierSegment::GetControlPoint1()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISCubicBezierSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetControlPoint1();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISCubicBezierSegment::GetControlPoint2()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISCubicBezierSegment>(APIObject);
    
    auto localResult = derivedAPIObject->GetControlPoint2();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}