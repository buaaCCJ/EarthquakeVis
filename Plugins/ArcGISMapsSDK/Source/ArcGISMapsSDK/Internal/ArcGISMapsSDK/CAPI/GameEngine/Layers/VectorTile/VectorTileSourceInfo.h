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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileSourceInfoHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_VectorTileSourceInfo_destroy(RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_EnvelopeHandle RT_VectorTileSourceInfo_getFullExtent(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_VectorTileSourceInfo_getInitialExtent(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_VectorTileSourceInfo_getMaxScale(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_VectorTileSourceInfo_getMinScale(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_VectorTileSourceInfo_getName(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_VectorTileSourceInfo_getOrigin(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_VectorTileSourceInfo_getSpatialReference(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_VectorTileSourceInfo_getURI(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_VectorTileSourceInfo_getVersion(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif