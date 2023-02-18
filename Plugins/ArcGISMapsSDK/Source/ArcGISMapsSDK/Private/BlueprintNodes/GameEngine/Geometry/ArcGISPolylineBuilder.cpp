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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolylineBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPolylineBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISPolylineBuilder* UArcGISPolylineBuilder::CreateArcGISPolylineBuilderFromPolyline(UArcGISPolyline* polyline)
{
    auto result = NewObject<UArcGISPolylineBuilder>();
    
    auto nullPolyline = Esri::GameEngine::Geometry::ArcGISPolyline{};
    auto derivedPolylineAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPolyline>(polyline->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPolylineBuilder>(polyline ? *derivedPolylineAPIObject : nullPolyline);
    
    return result;
}

UArcGISPolylineBuilder* UArcGISPolylineBuilder::CreateArcGISPolylineBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISPolylineBuilder>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPolylineBuilder>(spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}