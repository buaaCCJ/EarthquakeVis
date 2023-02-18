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
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentCircle.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Extent/ArcGISExtentCircle.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"

UArcGISExtentCircle* UArcGISExtentCircle::CreateArcGISExtentCircle(UArcGISPoint* center, double radius)
{
    auto result = NewObject<UArcGISExtentCircle>();
    
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Extent::ArcGISExtentCircle>(center ? *derivedCenterAPIObject : nullCenter, radius);
    
    return result;
}

double UArcGISExtentCircle::GetRadius()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Extent::ArcGISExtentCircle>(APIObject);
    
    auto localResult = derivedAPIObject->GetRadius();
    
    return localResult;
}