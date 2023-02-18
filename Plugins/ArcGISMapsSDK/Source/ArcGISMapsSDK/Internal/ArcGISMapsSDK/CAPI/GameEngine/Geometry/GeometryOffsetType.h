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

typedef enum RT_GeometryOffsetType
{
    RT_GeometryOffsetType_mitered = 0,
    RT_GeometryOffsetType_bevelled = 1,
    RT_GeometryOffsetType_rounded = 2,
    RT_GeometryOffsetType_squared = 3
} RT_GeometryOffsetType;

#ifdef __cplusplus
} // extern "C"
#endif