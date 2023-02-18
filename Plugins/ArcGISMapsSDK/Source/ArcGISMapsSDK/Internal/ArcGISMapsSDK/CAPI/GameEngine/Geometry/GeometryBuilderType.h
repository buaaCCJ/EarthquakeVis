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

typedef enum RT_GeometryBuilderType
{
    RT_GeometryBuilderType_pointBuilder = 1,
    RT_GeometryBuilderType_envelopeBuilder = 2,
    RT_GeometryBuilderType_polylineBuilder = 3,
    RT_GeometryBuilderType_polygonBuilder = 4,
    RT_GeometryBuilderType_multipointBuilder = 5,
    RT_GeometryBuilderType_unknown = -1
} RT_GeometryBuilderType;

#ifdef __cplusplus
} // extern "C"
#endif