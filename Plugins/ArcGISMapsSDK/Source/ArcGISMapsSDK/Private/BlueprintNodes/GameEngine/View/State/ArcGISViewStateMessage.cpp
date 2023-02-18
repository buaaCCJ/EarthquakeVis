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
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessage.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessageType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewStateMessage.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewStateMessageType.h"

int32 UArcGISViewStateMessage::GetCode() const
{
    auto localResult = APIObject->GetCode();
    
    return localResult;
}

FString UArcGISViewStateMessage::GetMessage() const
{
    auto localResult = APIObject->GetMessage();
    
    return localResult;
}

EArcGISViewStateMessageType::Type UArcGISViewStateMessage::GetMessageType() const
{
    auto localResult = APIObject->GetMessageType();
    
    return static_cast<EArcGISViewStateMessageType::Type>(localResult);
}