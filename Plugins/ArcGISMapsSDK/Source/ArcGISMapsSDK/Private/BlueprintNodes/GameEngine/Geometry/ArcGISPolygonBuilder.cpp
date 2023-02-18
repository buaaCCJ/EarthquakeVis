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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygon.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygonBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPolygon.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPolygonBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISPolygonBuilder* UArcGISPolygonBuilder::CreateArcGISPolygonBuilderFromPolygon(UArcGISPolygon* polygon)
{
    auto result = NewObject<UArcGISPolygonBuilder>();
    
    auto nullPolygon = Esri::GameEngine::Geometry::ArcGISPolygon{};
    auto derivedPolygonAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolygon>(polygon->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPolygonBuilder>(polygon ? *derivedPolygonAPIObject : nullPolygon);
    
    return result;
}

UArcGISPolygonBuilder* UArcGISPolygonBuilder::CreateArcGISPolygonBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISPolygonBuilder>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPolygonBuilder>(spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISPolyline* UArcGISPolygonBuilder::ToPolyline() const
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolygonBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->ToPolyline();
    
    auto localLocalResult = NewObject<UArcGISPolyline>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPolyline>(std::move(localResult));
    
    return localLocalResult;
}