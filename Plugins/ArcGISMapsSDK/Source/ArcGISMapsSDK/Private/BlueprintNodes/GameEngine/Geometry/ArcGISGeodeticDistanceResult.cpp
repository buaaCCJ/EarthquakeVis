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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodeticDistanceResult.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAngularUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeodeticDistanceResult.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnit.h"

double UArcGISGeodeticDistanceResult::GetAzimuth1()
{
    auto localResult = APIObject->GetAzimuth1();
    
    return localResult;
}

double UArcGISGeodeticDistanceResult::GetAzimuth2()
{
    auto localResult = APIObject->GetAzimuth2();
    
    return localResult;
}

UArcGISAngularUnit* UArcGISGeodeticDistanceResult::GetAzimuthUnit()
{
    auto localResult = APIObject->GetAzimuthUnit();
    
    auto localLocalResult = NewObject<UArcGISAngularUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISAngularUnit>(std::move(localResult));
    
    return localLocalResult;
}

double UArcGISGeodeticDistanceResult::GetDistance()
{
    auto localResult = APIObject->GetDistance();
    
    return localResult;
}

UArcGISLinearUnit* UArcGISGeodeticDistanceResult::GetDistanceUnit()
{
    auto localResult = APIObject->GetDistanceUnit();
    
    auto localLocalResult = NewObject<UArcGISLinearUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLinearUnit>(std::move(localResult));
    
    return localLocalResult;
}