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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeographicTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeographicTransformationStep.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeographicTransformation.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeographicTransformationStep.h"

UArcGISGeographicTransformation* UArcGISGeographicTransformation::CreateArcGISGeographicTransformationWithStep(UArcGISGeographicTransformationStep* step)
{
    auto result = NewObject<UArcGISGeographicTransformation>();
    
    auto nullStep = Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeographicTransformation>(step ? *step->APIObject : nullStep);
    
    return result;
}