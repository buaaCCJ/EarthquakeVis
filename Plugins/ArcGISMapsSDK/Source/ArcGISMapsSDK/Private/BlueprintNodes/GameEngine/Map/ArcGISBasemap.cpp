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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadable.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayerType.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISBasemap.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISBasemapStyle.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISBasemap.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISBasemapStyle.h"

UArcGISBasemap* UArcGISBasemap::CreateArcGISBasemap()
{
    auto result = NewObject<UArcGISBasemap>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISBasemap>();
    
    return result;
}

UArcGISBasemap* UArcGISBasemap::CreateArcGISBasemapWithBasemapStyle(EArcGISBasemapStyle::Type basemapStyle, FString APIKey)
{
    auto result = NewObject<UArcGISBasemap>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISBasemap>(static_cast<Esri::GameEngine::Map::ArcGISBasemapStyle>(basemapStyle), APIKey);
    
    return result;
}

UArcGISBasemap* UArcGISBasemap::CreateArcGISBasemapWithLayerSourceAndType(FString source, EArcGISLayerType::Type type, FString APIKey)
{
    auto result = NewObject<UArcGISBasemap>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISBasemap>(source, static_cast<Esri::GameEngine::Layers::Base::ArcGISLayerType>(type), APIKey);
    
    return result;
}

UArcGISBasemap* UArcGISBasemap::CreateArcGISBasemapWithBasemapSource(FString source, FString APIKey)
{
    auto result = NewObject<UArcGISBasemap>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISBasemap>(source, APIKey);
    
    return result;
}

FString UArcGISBasemap::GetAPIKey()
{
    auto localResult = APIObject->GetAPIKey();
    
    return localResult;
}

UArcGISLayerCollection* UArcGISBasemap::GetBaseLayers()
{
    auto localResult = APIObject->GetBaseLayers();
    
    auto localLocalResult = NewObject<UArcGISLayerCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISBasemap::SetBaseLayers(UArcGISLayerCollection* baseLayers)
{
    auto nullBaseLayers = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>{};
    
    APIObject->SetBaseLayers(baseLayers ? *baseLayers->APIObject : nullBaseLayers);
}

FString UArcGISBasemap::GetName()
{
    auto localResult = APIObject->GetName();
    
    return localResult;
}
void UArcGISBasemap::SetName(FString name)
{
    APIObject->SetName(name);
}

UArcGISLayerCollection* UArcGISBasemap::GetReferenceLayers()
{
    auto localResult = APIObject->GetReferenceLayers();
    
    auto localLocalResult = NewObject<UArcGISLayerCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISBasemap::SetReferenceLayers(UArcGISLayerCollection* referenceLayers)
{
    auto nullReferenceLayers = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>{};
    
    APIObject->SetReferenceLayers(referenceLayers ? *referenceLayers->APIObject : nullReferenceLayers);
}

FString UArcGISBasemap::GetSource()
{
    auto localResult = APIObject->GetSource();
    
    return localResult;
}