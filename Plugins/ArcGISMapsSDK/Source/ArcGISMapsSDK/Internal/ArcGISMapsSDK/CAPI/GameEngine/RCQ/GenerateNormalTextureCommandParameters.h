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

#include "ArcGISMapsSDK/CAPI/GameEngine/Math/Vector4.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct RT_GenerateNormalTextureCommandParameters
{
    uint32_t elevationId;
    RT_Vector4 tileExtent;
    RT_Vector4 textureExtent;
    uint32_t targetId;
} RT_GenerateNormalTextureCommandParameters;

#ifdef __cplusplus
} // extern "C"
#endif