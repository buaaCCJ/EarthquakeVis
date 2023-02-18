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

#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtentHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadStatus.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadableDoneLoadingEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadableLoadStatusChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEBasemapHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMapElevationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMapHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMapType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEMap_destroy(RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEMapHandle RT_GEMap_createWithBasemapAndMapType(RT_GEBasemapHandle basemap, RT_GEMapType mapType, const RT_ErrorHandler* errorHandler);
RT_GEMapHandle RT_GEMap_createWithMapType(RT_GEMapType mapType, const RT_ErrorHandler* errorHandler);
RT_GEMapHandle RT_GEMap_createWithSpatialReferenceAndMapType(const RT_SpatialReferenceHandle spatialReference, RT_GEMapType mapType, const RT_ErrorHandler* errorHandler);

RT_GEBasemapHandle RT_GEMap_getBasemap(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEMap_setBasemap(RT_GEMapHandle thisHandle, RT_GEBasemapHandle basemap, const RT_ErrorHandler* errorHandler);
RT_GEExtentHandle RT_GEMap_getClippingArea(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEMap_setClippingArea(RT_GEMapHandle thisHandle, RT_GEExtentHandle clippingArea, const RT_ErrorHandler* errorHandler);
RT_GEMapElevationHandle RT_GEMap_getElevation(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEMap_setElevation(RT_GEMapHandle thisHandle, RT_GEMapElevationHandle elevation, const RT_ErrorHandler* errorHandler);
RT_GELayerCollectionHandle RT_GEMap_getLayers(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEMap_setLayers(RT_GEMapHandle thisHandle, RT_GELayerCollectionHandle layers, const RT_ErrorHandler* errorHandler);
RT_ErrorHandle RT_GEMap_getLoadError(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_LoadStatus RT_GEMap_getLoadStatus(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEMapType RT_GEMap_getMapType(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_GEMap_getSpatialReference(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEMap_cancelLoad(RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GELayerHandle RT_GEMap_findLayerById(const RT_GEMapHandle thisHandle, uint32_t layerId, const RT_ErrorHandler* errorHandler);
void RT_GEMap_load(RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEMap_retryLoad(RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEMap_setDoneLoadingCallback(RT_GEMapHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_GEMap_setLoadStatusChangedCallback(RT_GEMapHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif