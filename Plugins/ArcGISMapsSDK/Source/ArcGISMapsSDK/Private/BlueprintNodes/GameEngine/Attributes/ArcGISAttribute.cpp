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
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttribute.h"
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttributeType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Attributes/ArcGISAttribute.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Attributes/ArcGISAttributeType.h"

EArcGISAttributeType::Type UArcGISAttribute::GetAttributeType()
{
    auto localResult = APIObject->GetAttributeType();
    
    return static_cast<EArcGISAttributeType::Type>(localResult);
}

FString UArcGISAttribute::GetName()
{
    auto localResult = APIObject->GetName();
    
    return localResult;
}