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

#include "ArcGISMapsSDK/CAPI/Platform.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum RT_LoadStatus
{
    RT_LoadStatus_loaded = 0,
    RT_LoadStatus_loading = 1,
    RT_LoadStatus_failedToLoad = 2,
    RT_LoadStatus_notLoaded = 3,
    RT_LoadStatus_unknown = -1
} RT_LoadStatus;

#ifdef __cplusplus
} // extern "C"
#endif