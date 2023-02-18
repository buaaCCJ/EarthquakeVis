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

#include "ArcGISMapsSDK/CAPI/GameEngine/LoadStatus.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef void (*RT_LoadableLoadStatusChangedEvent_fn)(void* userData, RT_LoadStatus loadStatus);

#ifdef __cplusplus
} // extern "C"
#endif