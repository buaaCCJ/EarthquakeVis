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

typedef enum RT_AngularUnitId
{
    RT_AngularUnitId_other = 0,
    RT_AngularUnitId_degrees = 9102,
    RT_AngularUnitId_grads = 9105,
    RT_AngularUnitId_minutes = 9103,
    RT_AngularUnitId_radians = 9101,
    RT_AngularUnitId_seconds = 9104
} RT_AngularUnitId;

#ifdef __cplusplus
} // extern "C"
#endif