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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISHorizontalVerticalTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISHorizontalVerticalTransformationStep.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISHorizontalVerticalTransformation.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISHorizontalVerticalTransformationStep.h"

UArcGISHorizontalVerticalTransformation* UArcGISHorizontalVerticalTransformation::CreateArcGISHorizontalVerticalTransformationWithStep(UArcGISHorizontalVerticalTransformationStep* step)
{
    auto result = NewObject<UArcGISHorizontalVerticalTransformation>();
    
    auto nullStep = Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformation>(step ? *step->APIObject : nullStep);
    
    return result;
}