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

#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadStatus.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadableDoneLoadingEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadableLoadStatusChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/BasemapStyle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEBasemapHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEBasemap_destroy(RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEBasemapHandle RT_GEBasemap_create(const RT_ErrorHandler* errorHandler);
RT_GEBasemapHandle RT_GEBasemap_createWithBasemapStyle(RT_BasemapStyle basemapStyle, const char* APIKey, const RT_ErrorHandler* errorHandler);
RT_GEBasemapHandle RT_GEBasemap_createWithLayerSourceAndType(const char* source, RT_GELayerType type, const char* APIKey, const RT_ErrorHandler* errorHandler);
RT_GEBasemapHandle RT_GEBasemap_createWithBasemapSource(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler);

RT_StringHandle RT_GEBasemap_getAPIKey(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GELayerCollectionHandle RT_GEBasemap_getBaseLayers(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBasemap_setBaseLayers(RT_GEBasemapHandle thisHandle, RT_GELayerCollectionHandle baseLayers, const RT_ErrorHandler* errorHandler);
RT_ErrorHandle RT_GEBasemap_getLoadError(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_LoadStatus RT_GEBasemap_getLoadStatus(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEBasemap_getName(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBasemap_setName(RT_GEBasemapHandle thisHandle, char* name, const RT_ErrorHandler* errorHandler);
RT_GELayerCollectionHandle RT_GEBasemap_getReferenceLayers(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBasemap_setReferenceLayers(RT_GEBasemapHandle thisHandle, RT_GELayerCollectionHandle referenceLayers, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEBasemap_getSource(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEBasemap_cancelLoad(RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBasemap_load(RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEBasemap_retryLoad(RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEBasemap_setDoneLoadingCallback(RT_GEBasemapHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_GEBasemap_setLoadStatusChangedCallback(RT_GEBasemapHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif