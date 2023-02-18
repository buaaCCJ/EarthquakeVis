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

typedef enum RT_GeometryExtendOptions
{
    RT_GeometryExtendOptions_default = 0,
    RT_GeometryExtendOptions_relocateEnds = 1,
    RT_GeometryExtendOptions_keepEndAttributes = 2,
    RT_GeometryExtendOptions_noEndAttributes = 4,
    RT_GeometryExtendOptions_doNotExtendFromStartPoint = 8,
    RT_GeometryExtendOptions_doNotExtendFromEndPoint = 16
} RT_GeometryExtendOptions;

#ifdef __cplusplus
} // extern "C"
#endif