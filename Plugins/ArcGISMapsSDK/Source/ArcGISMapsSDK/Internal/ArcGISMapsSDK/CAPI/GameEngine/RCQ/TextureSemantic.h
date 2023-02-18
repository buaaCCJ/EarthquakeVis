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

typedef enum RT_TextureSemantic
{
    RT_TextureSemantic_meshPyramidImagery = 5,
    RT_TextureSemantic_meshPyramidUvRegions = 6,
    RT_TextureSemantic_meshPyramidFeatureIds = 7,
    RT_TextureSemantic_meshPyramidAttributeValues = 8
} RT_TextureSemantic;

#ifdef __cplusplus
} // extern "C"
#endif