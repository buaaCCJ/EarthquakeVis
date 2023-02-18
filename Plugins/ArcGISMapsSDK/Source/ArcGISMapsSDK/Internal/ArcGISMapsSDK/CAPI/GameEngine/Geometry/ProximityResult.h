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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ProximityResultHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_ProximityResult_destroy(RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_ProximityResult_getCoordinate(const RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_ProximityResult_getDistance(const RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_ProximityResult_getPartIndex(const RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_ProximityResult_getPointIndex(const RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif