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

#include "ArcGISMapsSDK/CAPI/GameEngine/Math/OrientedBoundingBox.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/RCQ/DataBufferView.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct RT_SetRenderableMeshCommandParameters
{
    uint32_t renderableId;
    RT_DataBufferView triangles;
    RT_DataBufferView positions;
    RT_DataBufferView normals;
    RT_DataBufferView tangents;
    RT_DataBufferView uvs;
    RT_DataBufferView colors;
    RT_DataBufferView uvRegionIds;
    RT_DataBufferView featureIndices;
    RT_OrientedBoundingBox orientedBoundingBox;
    bool maskTerrain;
} RT_SetRenderableMeshCommandParameters;

#ifdef __cplusplus
} // extern "C"
#endif