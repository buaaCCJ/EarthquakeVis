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

typedef enum RT_LinearUnitId
{
    RT_LinearUnitId_other = 0,
    RT_LinearUnitId_centimeters = 1033,
    RT_LinearUnitId_feet = 9002,
    RT_LinearUnitId_inches = 109008,
    RT_LinearUnitId_kilometers = 9036,
    RT_LinearUnitId_meters = 9001,
    RT_LinearUnitId_miles = 9093,
    RT_LinearUnitId_millimeters = 1025,
    RT_LinearUnitId_nauticalMiles = 9030,
    RT_LinearUnitId_yards = 9096
} RT_LinearUnitId;

#ifdef __cplusplus
} // extern "C"
#endif