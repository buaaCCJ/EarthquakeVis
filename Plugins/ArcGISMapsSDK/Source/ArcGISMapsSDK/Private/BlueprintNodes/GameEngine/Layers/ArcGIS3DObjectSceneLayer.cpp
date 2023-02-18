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
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGIS3DObjectSceneLayer.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/ArcGIS3DObjectSceneLayer.h" // IWYU pragma: associated

UArcGIS3DObjectSceneLayer* UArcGIS3DObjectSceneLayer::CreateArcGIS3DObjectSceneLayer(FString source, FString APIKey)
{
    auto result = NewObject<UArcGIS3DObjectSceneLayer>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Layers::ArcGIS3DObjectSceneLayer>(source, APIKey);
    
    return result;
}

UArcGIS3DObjectSceneLayer* UArcGIS3DObjectSceneLayer::CreateArcGIS3DObjectSceneLayerWithProperties(FString source, FString name, float opacity, bool visible, FString APIKey)
{
    auto result = NewObject<UArcGIS3DObjectSceneLayer>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Layers::ArcGIS3DObjectSceneLayer>(source, name, opacity, visible, APIKey);
    
    return result;
}

UMaterialInterface* UArcGIS3DObjectSceneLayer::GetMaterialReference()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Layers::ArcGIS3DObjectSceneLayer>(APIObject);
    
    auto localResult = derivedAPIObject->GetMaterialReference();
    
    return localResult;
}
void UArcGIS3DObjectSceneLayer::SetMaterialReference(UMaterialInterface* materialReference)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Layers::ArcGIS3DObjectSceneLayer>(APIObject);
    
    derivedAPIObject->SetMaterialReference(materialReference);
}