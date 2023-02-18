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

#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef void (*RT_Attribute_processor_fn)(void* userData, const RT_ArrayHandle layerAttributes, const RT_ArrayHandle visualizationAttributes);

#ifdef __cplusplus
} // extern "C"
#endif