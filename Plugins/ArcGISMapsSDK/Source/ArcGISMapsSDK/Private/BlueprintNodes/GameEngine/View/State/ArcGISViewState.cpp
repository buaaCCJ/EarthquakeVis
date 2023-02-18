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
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewState.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessage.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStatus.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewState.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewStateMessage.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewStatus.h"

UArcGISViewStateMessage* UArcGISViewState::GetMessage()
{
    auto localResult = APIObject->GetMessage();
    
    auto localLocalResult = NewObject<UArcGISViewStateMessage>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::View::State::ArcGISViewStateMessage>(std::move(localResult));
    
    return localLocalResult;
}

EArcGISViewStatus::Type UArcGISViewState::GetStatus()
{
    auto localResult = APIObject->GetStatus();
    
    return static_cast<EArcGISViewStatus::Type>(localResult);
}