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

typedef enum RT_GEViewStatus
{
    RT_GEViewStatus_active = 1,
    RT_GEViewStatus_mapNotReady = 2,
    RT_GEViewStatus_noViewport = 4,
    RT_GEViewStatus_loading = 8,
    RT_GEViewStatus_error = 16,
    RT_GEViewStatus_warning = 32
} RT_GEViewStatus;

#ifdef __cplusplus
} // extern "C"
#endif