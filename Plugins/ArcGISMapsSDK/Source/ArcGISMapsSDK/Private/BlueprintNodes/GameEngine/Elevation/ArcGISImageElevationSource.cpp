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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/ArcGISImageElevationSource.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/ArcGISImageElevationSource.h" // IWYU pragma: associated

UArcGISImageElevationSource* UArcGISImageElevationSource::CreateArcGISImageElevationSource(FString source, FString APIKey)
{
    auto result = NewObject<UArcGISImageElevationSource>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Elevation::ArcGISImageElevationSource>(source, APIKey);
    
    return result;
}

UArcGISImageElevationSource* UArcGISImageElevationSource::CreateArcGISImageElevationSourceWithName(FString source, FString name, FString APIKey)
{
    auto result = NewObject<UArcGISImageElevationSource>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Elevation::ArcGISImageElevationSource>(source, name, APIKey);
    
    return result;
}