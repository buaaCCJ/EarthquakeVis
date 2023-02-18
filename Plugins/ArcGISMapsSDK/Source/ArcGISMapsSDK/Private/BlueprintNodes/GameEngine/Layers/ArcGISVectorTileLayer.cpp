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
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISVectorTileLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfo.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileStyle.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/ArcGISVectorTileLayer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfoImmutableCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/VectorTile/ArcGISVectorTileStyle.h"

UArcGISVectorTileLayer* UArcGISVectorTileLayer::CreateArcGISVectorTileLayer(FString source, FString APIKey)
{
    auto result = NewObject<UArcGISVectorTileLayer>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Layers::ArcGISVectorTileLayer>(source, APIKey);
    
    return result;
}

UArcGISVectorTileLayer* UArcGISVectorTileLayer::CreateArcGISVectorTileLayerWithProperties(FString source, FString name, float opacity, bool visible, FString APIKey)
{
    auto result = NewObject<UArcGISVectorTileLayer>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Layers::ArcGISVectorTileLayer>(source, name, opacity, visible, APIKey);
    
    return result;
}

UArcGISVectorTileSourceInfoImmutableCollection* UArcGISVectorTileLayer::GetSourceInfos()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Layers::ArcGISVectorTileLayer>(APIObject);
    
    auto localResult = derivedAPIObject->GetSourceInfos();
    
    auto localLocalResult = NewObject<UArcGISVectorTileSourceInfoImmutableCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::Unreal::ArcGISImmutableCollection<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISVectorTileStyle* UArcGISVectorTileLayer::GetStyle()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Layers::ArcGISVectorTileLayer>(APIObject);
    
    auto localResult = derivedAPIObject->GetStyle();
    
    auto localLocalResult = NewObject<UArcGISVectorTileStyle>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileStyle>(std::move(localResult));
    
    return localLocalResult;
}