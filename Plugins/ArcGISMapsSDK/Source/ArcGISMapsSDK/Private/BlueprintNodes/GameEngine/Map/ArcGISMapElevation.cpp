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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMapElevation.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSourceCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMapElevation.h" // IWYU pragma: associated

UArcGISMapElevation* UArcGISMapElevation::CreateArcGISMapElevation()
{
    auto result = NewObject<UArcGISMapElevation>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISMapElevation>();
    
    return result;
}

UArcGISMapElevation* UArcGISMapElevation::CreateArcGISMapElevationWithElevationSource(UArcGISElevationSource* elevationSource)
{
    auto result = NewObject<UArcGISMapElevation>();
    
    auto nullElevationSource = Esri::GameEngine::Elevation::Base::ArcGISElevationSource{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISMapElevation>(elevationSource ? *elevationSource->APIObject : nullElevationSource);
    
    return result;
}

UArcGISElevationSourceCollection* UArcGISMapElevation::GetElevationSources()
{
    auto localResult = APIObject->GetElevationSources();
    
    auto localLocalResult = NewObject<UArcGISElevationSourceCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::Unreal::ArcGISCollection<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISMapElevation::SetElevationSources(UArcGISElevationSourceCollection* elevationSources)
{
    auto nullElevationSources = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>{};
    
    APIObject->SetElevationSources(elevationSources ? *elevationSources->APIObject : nullElevationSources);
}