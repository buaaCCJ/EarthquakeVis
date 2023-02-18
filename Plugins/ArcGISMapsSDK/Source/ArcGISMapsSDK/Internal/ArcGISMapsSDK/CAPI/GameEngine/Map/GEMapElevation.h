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

#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSourceCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSourceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMapElevationHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEMapElevation_destroy(RT_GEMapElevationHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEMapElevationHandle RT_GEMapElevation_create(const RT_ErrorHandler* errorHandler);
RT_GEMapElevationHandle RT_GEMapElevation_createWithElevationSource(RT_GEElevationSourceHandle elevationSource, const RT_ErrorHandler* errorHandler);

RT_GEElevationSourceCollectionHandle RT_GEMapElevation_getElevationSources(const RT_GEMapElevationHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEMapElevation_setElevationSources(RT_GEMapElevationHandle thisHandle, RT_GEElevationSourceCollectionHandle elevationSources, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif