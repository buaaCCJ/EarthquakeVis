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
#pragma once

#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateMessageHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateMessageType.h"
#include "ArcGISMapsSDK/CAPI/Standard/DictionaryHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEViewStateMessage_destroy(RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_DictionaryHandle RT_GEViewStateMessage_getAdditionalInformation(const RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler);
uint32_t RT_GEViewStateMessage_getCode(const RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEViewStateMessage_getMessage(const RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEViewStateMessageType RT_GEViewStateMessage_getMessageType(const RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif