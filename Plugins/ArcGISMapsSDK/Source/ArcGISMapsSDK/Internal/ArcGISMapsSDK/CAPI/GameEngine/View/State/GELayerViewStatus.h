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

typedef enum RT_GELayerViewStatus
{
    RT_GELayerViewStatus_active = 1,
    RT_GELayerViewStatus_notVisible = 2,
    RT_GELayerViewStatus_outOfScale = 4,
    RT_GELayerViewStatus_loading = 8,
    RT_GELayerViewStatus_error = 16,
    RT_GELayerViewStatus_warning = 32
} RT_GELayerViewStatus;

#ifdef __cplusplus
} // extern "C"
#endif