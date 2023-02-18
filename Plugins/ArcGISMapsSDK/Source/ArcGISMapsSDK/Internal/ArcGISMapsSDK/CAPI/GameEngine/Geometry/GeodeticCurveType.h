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

typedef enum RT_GeodeticCurveType
{
    RT_GeodeticCurveType_geodesic = 0,
    RT_GeodeticCurveType_loxodrome = 1,
    RT_GeodeticCurveType_greatElliptic = 2,
    RT_GeodeticCurveType_normalSection = 3,
    RT_GeodeticCurveType_shapePreserving = 4
} RT_GeodeticCurveType;

#ifdef __cplusplus
} // extern "C"
#endif