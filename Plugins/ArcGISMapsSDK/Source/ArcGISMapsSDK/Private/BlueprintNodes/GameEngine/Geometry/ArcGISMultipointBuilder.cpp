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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipointBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMultipoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMultipointBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMutablePointCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISMultipointBuilder* UArcGISMultipointBuilder::CreateArcGISMultipointBuilderFromMultipoint(UArcGISMultipoint* multipoint)
{
    auto result = NewObject<UArcGISMultipointBuilder>();
    
    auto nullMultipoint = Esri::GameEngine::Geometry::ArcGISMultipoint{};
    auto derivedMultipointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipoint>(multipoint->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMultipointBuilder>(multipoint ? *derivedMultipointAPIObject : nullMultipoint);
    
    return result;
}

UArcGISMultipointBuilder* UArcGISMultipointBuilder::CreateArcGISMultipointBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISMultipointBuilder>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMultipointBuilder>(spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISMutablePointCollection* UArcGISMultipointBuilder::GetPoints()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipointBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetPoints();
    
    auto localLocalResult = NewObject<UArcGISMutablePointCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMutablePointCollection>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISMultipointBuilder::SetPoints(UArcGISMutablePointCollection* points)
{
    auto nullPoints = Esri::GameEngine::Geometry::ArcGISMutablePointCollection{};
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipointBuilder>(APIObject);
    
    derivedAPIObject->SetPoints(points ? *points->APIObject : nullPoints);
}