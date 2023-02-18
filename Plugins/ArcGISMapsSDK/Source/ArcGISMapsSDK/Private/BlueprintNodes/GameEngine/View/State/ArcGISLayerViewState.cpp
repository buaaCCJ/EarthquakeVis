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
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISLayerViewState.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISLayerViewStatus.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessage.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISLayerViewState.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISLayerViewStatus.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewStateMessage.h"

UArcGISViewStateMessage* UArcGISLayerViewState::GetMessage()
{
    auto localResult = APIObject->GetMessage();
    
    auto localLocalResult = NewObject<UArcGISViewStateMessage>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::View::State::ArcGISViewStateMessage>(std::move(localResult));
    
    return localLocalResult;
}

EArcGISLayerViewStatus::Type UArcGISLayerViewState::GetStatus()
{
    auto localResult = APIObject->GetStatus();
    
    return static_cast<EArcGISLayerViewStatus::Type>(localResult);
}