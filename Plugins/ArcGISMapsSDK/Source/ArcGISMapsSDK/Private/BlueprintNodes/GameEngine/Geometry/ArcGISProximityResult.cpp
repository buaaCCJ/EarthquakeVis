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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISProximityResult.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISProximityResult.h" // IWYU pragma: associated

UArcGISPoint* UArcGISProximityResult::GetCoordinate()
{
    auto localResult = APIObject->GetCoordinate();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

double UArcGISProximityResult::GetDistance()
{
    auto localResult = APIObject->GetDistance();
    
    return localResult;
}

int64 UArcGISProximityResult::GetPartIndex()
{
    auto localResult = APIObject->GetPartIndex();
    
    return localResult;
}

int64 UArcGISProximityResult::GetPointIndex()
{
    auto localResult = APIObject->GetPointIndex();
    
    return localResult;
}