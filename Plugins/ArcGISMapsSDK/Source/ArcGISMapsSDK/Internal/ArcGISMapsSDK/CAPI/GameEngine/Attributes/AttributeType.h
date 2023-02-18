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

typedef enum RT_AttributeType
{
    RT_AttributeType_string = 1,
    RT_AttributeType_int8 = 2,
    RT_AttributeType_uint8 = 3,
    RT_AttributeType_int16 = 4,
    RT_AttributeType_uint16 = 5,
    RT_AttributeType_int32 = 6,
    RT_AttributeType_uint32 = 7,
    RT_AttributeType_float32 = 8,
    RT_AttributeType_float64 = 9,
    RT_AttributeType_OID32 = 10
} RT_AttributeType;

#ifdef __cplusplus
} // extern "C"
#endif