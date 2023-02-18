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

typedef enum RT_MGRSConversionMode
{
    RT_MGRSConversionMode_automatic = 0,
    RT_MGRSConversionMode_new180InZone01 = 1,
    RT_MGRSConversionMode_new180InZone60 = 2,
    RT_MGRSConversionMode_old180InZone01 = 3,
    RT_MGRSConversionMode_old180InZone60 = 4
} RT_MGRSConversionMode;

#ifdef __cplusplus
} // extern "C"
#endif