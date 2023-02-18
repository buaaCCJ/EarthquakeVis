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

#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSourceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSourceType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtentRectangleHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadStatus.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadableDoneLoadingEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/LoadableLoadStatusChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEElevationSource_destroy(RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEElevationSourceHandle RT_GEElevationSource_create(const char* source, RT_GEElevationSourceType type, const char* APIKey, const RT_ErrorHandler* errorHandler);

RT_StringHandle RT_GEElevationSource_getAPIKey(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEExtentRectangleHandle RT_GEElevationSource_getExtent(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GEElevationSource_getIsEnabled(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEElevationSource_setIsEnabled(RT_GEElevationSourceHandle thisHandle, bool isEnabled, const RT_ErrorHandler* errorHandler);
RT_ErrorHandle RT_GEElevationSource_getLoadError(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_LoadStatus RT_GEElevationSource_getLoadStatus(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEElevationSource_getName(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEElevationSource_setName(RT_GEElevationSourceHandle thisHandle, char* name, const RT_ErrorHandler* errorHandler);
RT_GEElevationSourceType RT_GEElevationSource_getObjectType(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GEElevationSource_getSource(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_GEElevationSource_getSpatialReference(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEElevationSource_cancelLoad(RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEElevationSource_load(RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEElevationSource_retryLoad(RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_GEElevationSource_setDoneLoadingCallback(RT_GEElevationSourceHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_GEElevationSource_setLoadStatusChangedCallback(RT_GEElevationSourceHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif