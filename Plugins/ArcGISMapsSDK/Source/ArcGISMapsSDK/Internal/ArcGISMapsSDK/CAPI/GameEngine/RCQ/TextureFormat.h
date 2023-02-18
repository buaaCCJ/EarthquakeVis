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

typedef enum RT_TextureFormat
{
    RT_TextureFormat_R32Float = 2,
    RT_TextureFormat_RGBA8UNorm = 3,
    RT_TextureFormat_RGB8UNorm = 4,
    RT_TextureFormat_RG8UNorm = 5,
    RT_TextureFormat_RGBA32Float = 6,
    RT_TextureFormat_DXT1 = 7,
    RT_TextureFormat_DXT3 = 8,
    RT_TextureFormat_DXT5 = 9,
    RT_TextureFormat_R32UNorm = 10,
    RT_TextureFormat_R32Norm = 11,
    RT_TextureFormat_RGBA16UNorm = 12,
    RT_TextureFormat_ETC2RGB8 = 13,
    RT_TextureFormat_ETC2SRGB8 = 14,
    RT_TextureFormat_ETC2RGB8PunchthroughAlpha1 = 15,
    RT_TextureFormat_ETC2SRGB8PunchthroughAlpha1 = 16,
    RT_TextureFormat_ETC2EacRGBA8 = 17,
    RT_TextureFormat_ETC2EacSRGBA8 = 18,
    RT_TextureFormat_BGRA8UNorm = 19
} RT_TextureFormat;

#ifdef __cplusplus
} // extern "C"
#endif