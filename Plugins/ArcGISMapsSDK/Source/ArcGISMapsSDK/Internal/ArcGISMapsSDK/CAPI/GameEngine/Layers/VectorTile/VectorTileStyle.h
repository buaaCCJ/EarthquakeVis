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

#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileStyleHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_VectorTileStyle_destroy(RT_VectorTileStyleHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_StringHandle RT_VectorTileStyle_getSourceURI(const RT_VectorTileStyleHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_VectorTileStyle_getVersion(const RT_VectorTileStyleHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif