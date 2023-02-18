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

typedef enum RT_MeshBufferChangeType
{
    RT_MeshBufferChangeType_positions = 0,
    RT_MeshBufferChangeType_normals = 1,
    RT_MeshBufferChangeType_tangents = 2,
    RT_MeshBufferChangeType_colors = 3,
    RT_MeshBufferChangeType_uv0 = 4,
    RT_MeshBufferChangeType_uv1 = 5,
    RT_MeshBufferChangeType_uv2 = 6,
    RT_MeshBufferChangeType_uv3 = 7
} RT_MeshBufferChangeType;

#ifdef __cplusplus
} // extern "C"
#endif