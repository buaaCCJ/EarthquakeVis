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
#include "ArcGISMapsSDK/CAPI/GameEngine/GameEngineType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMapHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/MapView/CameraHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/MapView/GlobeModel.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Math/Vector3.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/RCQ/RenderCommandServerHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/GEViewHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/GEViewOptions.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/GEViewSpatialReferenceChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEElevationSourceViewStateChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEElevationSourceViewStateHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GELayerViewStateChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GELayerViewStateHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateChangedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEView_destroy(RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEViewHandle RT_GEView_create(RT_GameEngineType gameEngineType, RT_GlobeModel globeModel, const RT_ErrorHandler* errorHandler);

RT_CameraHandle RT_GEView_getCamera(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEView_setCamera(RT_GEViewHandle thisHandle, RT_CameraHandle camera, const RT_ErrorHandler* errorHandler);
RT_GEMapHandle RT_GEView_getMap(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEView_setMap(RT_GEViewHandle thisHandle, RT_GEMapHandle map, const RT_ErrorHandler* errorHandler);
RT_RenderCommandServerHandle RT_GEView_getRenderCommandServer(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_GEView_getSpatialReference(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEViewOptions RT_GEView_getViewOptions(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEView_setViewOptions(RT_GEViewHandle thisHandle, RT_GEViewOptions viewOptions, const RT_ErrorHandler* errorHandler);

RT_Vector3 RT_GEView_geographicToWorld(const RT_GEViewHandle thisHandle, const RT_PointHandle geographicCoordinate, const RT_ErrorHandler* errorHandler);
RT_GEViewStateHandle RT_GEView_getViewViewState(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEElevationSourceViewStateHandle RT_GEView_getElevationSourceViewState(const RT_GEViewHandle thisHandle, const RT_GEElevationSourceHandle elevation, const RT_ErrorHandler* errorHandler);
RT_GELayerViewStateHandle RT_GEView_getLayerViewState(const RT_GEViewHandle thisHandle, const RT_GELayerHandle layer, const RT_ErrorHandler* errorHandler);
void RT_GEView_handleLowMemoryWarning(RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEView_setMemoryQuotas(RT_GEViewHandle thisHandle, int64_t systemMemory, int64_t videoMemory, const RT_ErrorHandler* errorHandler);
void RT_GEView_setViewportProperties(RT_GEViewHandle thisHandle, uint32_t viewportWidthPixels, uint32_t viewportHeightPixels, float horizontalFieldOfViewDegrees, float verticalFieldOfViewDegrees, float verticalDistortionFactor, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_GEView_worldToGeographic(const RT_GEViewHandle thisHandle, RT_Vector3 worldCoordinate, const RT_ErrorHandler* errorHandler);

void RT_GEView_setElevationSourceViewStateChangedCallback(RT_GEViewHandle thisHandle, RT_GEElevationSourceViewStateChangedEvent_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_GEView_setLayerViewStateChangedCallback(RT_GEViewHandle thisHandle, RT_GELayerViewStateChangedEvent_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_GEView_setSpatialReferenceChangedCallback(RT_GEViewHandle thisHandle, RT_GEViewSpatialReferenceChangedEvent_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler);
void RT_GEView_setViewStateChangedCallback(RT_GEViewHandle thisHandle, RT_GEViewStateChangedEvent_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif