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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePartCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipart.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISImmutablePartCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMultipart.h" // IWYU pragma: associated

UArcGISImmutablePartCollection* UArcGISMultipart::GetParts()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipart>(APIObject);
    
    auto localResult = derivedAPIObject->GetParts();
    
    auto localLocalResult = NewObject<UArcGISImmutablePartCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISImmutablePartCollection>(std::move(localResult));
    
    return localLocalResult;
}