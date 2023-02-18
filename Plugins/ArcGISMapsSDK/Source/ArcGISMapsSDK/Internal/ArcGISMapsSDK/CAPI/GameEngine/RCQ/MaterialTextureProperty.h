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

typedef enum RT_MaterialTextureProperty
{
    RT_MaterialTextureProperty_imagery = 0,
    RT_MaterialTextureProperty_normalMap = 1,
    RT_MaterialTextureProperty_baseMap = 2,
    RT_MaterialTextureProperty_uvRegionLut = 3,
    RT_MaterialTextureProperty_positionsMap = 4,
    RT_MaterialTextureProperty_featureIds = 5,
    RT_MaterialTextureProperty_metallicRoughness = 6,
    RT_MaterialTextureProperty_emissive = 7,
    RT_MaterialTextureProperty_occlusionMap = 8
} RT_MaterialTextureProperty;

#ifdef __cplusplus
} // extern "C"
#endif