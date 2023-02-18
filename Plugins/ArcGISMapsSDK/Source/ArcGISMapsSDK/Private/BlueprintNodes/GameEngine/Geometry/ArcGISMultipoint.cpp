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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMultipoint.h" // IWYU pragma: associated

UArcGISImmutablePointCollection* UArcGISMultipoint::GetPoints()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISMultipoint>(APIObject);
    
    auto localResult = derivedAPIObject->GetPoints();
    
    auto localLocalResult = NewObject<UArcGISImmutablePointCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISImmutablePointCollection>(std::move(localResult));
    
    return localLocalResult;
}