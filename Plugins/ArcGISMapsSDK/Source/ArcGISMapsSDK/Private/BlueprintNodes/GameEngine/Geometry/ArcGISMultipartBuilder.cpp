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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipartBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePartCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMultipartBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMutablePartCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"

UArcGISMutablePartCollection* UArcGISMultipartBuilder::GetParts()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipartBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetParts();
    
    auto localLocalResult = NewObject<UArcGISMutablePartCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMutablePartCollection>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISMultipartBuilder::SetParts(UArcGISMutablePartCollection* parts)
{
    auto nullParts = Esri::GameEngine::Geometry::ArcGISMutablePartCollection{};
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipartBuilder>(APIObject);
    
    derivedAPIObject->SetParts(parts ? *parts->APIObject : nullParts);
}

int64 UArcGISMultipartBuilder::AddPointXY(double x, double y)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipartBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->AddPoint(x, y);
    
    return localResult;
}

int64 UArcGISMultipartBuilder::AddPointXYZ(double x, double y, double z)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipartBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->AddPoint(x, y, z);
    
    return localResult;
}

int64 UArcGISMultipartBuilder::AddPoint(UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipartBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->AddPoint(point ? *derivedPointAPIObject : nullPoint);
    
    return localResult;
}