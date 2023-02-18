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
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISImageLayer.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/ArcGISImageLayer.h" // IWYU pragma: associated

UArcGISImageLayer* UArcGISImageLayer::CreateArcGISImageLayer(FString source, FString APIKey)
{
    auto result = NewObject<UArcGISImageLayer>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Layers::ArcGISImageLayer>(source, APIKey);
    
    return result;
}

UArcGISImageLayer* UArcGISImageLayer::CreateArcGISImageLayerWithProperties(FString source, FString name, float opacity, bool visible, FString APIKey)
{
    auto result = NewObject<UArcGISImageLayer>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Layers::ArcGISImageLayer>(source, name, opacity, visible, APIKey);
    
    return result;
}