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

typedef enum RT_GeometryDimension
{
    RT_GeometryDimension_point = 0,
    RT_GeometryDimension_curve = 1,
    RT_GeometryDimension_area = 2,
    RT_GeometryDimension_volume = 3,
    RT_GeometryDimension_unknown = -1
} RT_GeometryDimension;

#ifdef __cplusplus
} // extern "C"
#endif