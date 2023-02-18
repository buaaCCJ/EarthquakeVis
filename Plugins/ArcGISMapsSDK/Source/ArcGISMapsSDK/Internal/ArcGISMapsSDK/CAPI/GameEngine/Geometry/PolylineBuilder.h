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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PolylineBuilderHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PolylineHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_PolylineBuilder_destroy(RT_PolylineBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_PolylineBuilderHandle RT_PolylineBuilder_createFromPolyline(const RT_PolylineHandle polyline, const RT_ErrorHandler* errorHandler);
RT_PolylineBuilderHandle RT_PolylineBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif