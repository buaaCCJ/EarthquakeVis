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
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtent.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISBasemap.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMap.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMapElevation.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMapType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Extent/ArcGISExtent.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISBasemap.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMap.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMapElevation.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMapType.h"

UArcGISMap* UArcGISMap::CreateArcGISMapWithBasemapAndMapType(UArcGISBasemap* basemap, EArcGISMapType::Type mapType)
{
    auto result = NewObject<UArcGISMap>();
    
    auto nullBasemap = Esri::GameEngine::Map::ArcGISBasemap{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISMap>(basemap ? *basemap->APIObject : nullBasemap, static_cast<Esri::GameEngine::Map::ArcGISMapType>(mapType));
    
    return result;
}

UArcGISMap* UArcGISMap::CreateArcGISMapWithMapType(EArcGISMapType::Type mapType)
{
    auto result = NewObject<UArcGISMap>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISMap>(static_cast<Esri::GameEngine::Map::ArcGISMapType>(mapType));
    
    return result;
}

UArcGISMap* UArcGISMap::CreateArcGISMapWithSpatialReferenceAndMapType(UArcGISSpatialReference* spatialReference, EArcGISMapType::Type mapType)
{
    auto result = NewObject<UArcGISMap>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISMap>(spatialReference ? *spatialReference->APIObject : nullSpatialReference, static_cast<Esri::GameEngine::Map::ArcGISMapType>(mapType));
    
    return result;
}

UArcGISBasemap* UArcGISMap::GetBasemap()
{
    auto localResult = APIObject->GetBasemap();
    
    auto localLocalResult = NewObject<UArcGISBasemap>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISBasemap>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISMap::SetBasemap(UArcGISBasemap* basemap)
{
    auto nullBasemap = Esri::GameEngine::Map::ArcGISBasemap{};
    
    APIObject->SetBasemap(basemap ? *basemap->APIObject : nullBasemap);
}

UArcGISExtent* UArcGISMap::GetClippingArea()
{
    auto localResult = APIObject->GetClippingArea();
    
    auto localLocalResult = NewObject<UArcGISExtent>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Extent::ArcGISExtent>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISMap::SetClippingArea(UArcGISExtent* clippingArea)
{
    auto nullClippingArea = Esri::GameEngine::Extent::ArcGISExtent{};
    
    APIObject->SetClippingArea(clippingArea ? *clippingArea->APIObject : nullClippingArea);
}

UArcGISMapElevation* UArcGISMap::GetElevation()
{
    auto localResult = APIObject->GetElevation();
    
    auto localLocalResult = NewObject<UArcGISMapElevation>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISMapElevation>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISMap::SetElevation(UArcGISMapElevation* elevation)
{
    auto nullElevation = Esri::GameEngine::Map::ArcGISMapElevation{};
    
    APIObject->SetElevation(elevation ? *elevation->APIObject : nullElevation);
}

UArcGISLayerCollection* UArcGISMap::GetLayers()
{
    auto localResult = APIObject->GetLayers();
    
    auto localLocalResult = NewObject<UArcGISLayerCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISMap::SetLayers(UArcGISLayerCollection* layers)
{
    auto nullLayers = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>{};
    
    APIObject->SetLayers(layers ? *layers->APIObject : nullLayers);
}

EArcGISMapType::Type UArcGISMap::GetMapType()
{
    auto localResult = APIObject->GetMapType();
    
    return static_cast<EArcGISMapType::Type>(localResult);
}

UArcGISSpatialReference* UArcGISMap::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}