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

#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEElevationSourceViewStateHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEElevationSourceViewStatus.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateMessageHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEElevationSourceViewState_destroy(RT_GEElevationSourceViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEViewStateMessageHandle RT_GEElevationSourceViewState_getMessage(const RT_GEElevationSourceViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEElevationSourceViewStatus RT_GEElevationSourceViewState_getStatus(const RT_GEElevationSourceViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif