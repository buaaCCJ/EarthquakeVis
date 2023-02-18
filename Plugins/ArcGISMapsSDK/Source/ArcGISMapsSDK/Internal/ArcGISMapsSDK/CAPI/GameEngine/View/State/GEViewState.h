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

#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateMessageHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStatus.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEViewState_destroy(RT_GEViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEViewStateMessageHandle RT_GEViewState_getMessage(const RT_GEViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEViewStatus RT_GEViewState_getStatus(const RT_GEViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif