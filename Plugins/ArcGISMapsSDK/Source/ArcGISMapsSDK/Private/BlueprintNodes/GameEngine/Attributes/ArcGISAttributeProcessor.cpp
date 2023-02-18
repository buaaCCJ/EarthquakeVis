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
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttributeProcessor.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Attributes/ArcGISAttributeProcessor.h" // IWYU pragma: associated

UArcGISAttributeProcessor* UArcGISAttributeProcessor::CreateArcGISAttributeProcessor()
{
    auto result = NewObject<UArcGISAttributeProcessor>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Attributes::ArcGISAttributeProcessor>();
    
    return result;
}