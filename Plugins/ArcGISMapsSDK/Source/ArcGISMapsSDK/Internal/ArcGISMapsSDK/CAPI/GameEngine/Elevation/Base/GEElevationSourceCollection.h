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
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEElevationSourceCollection_destroy(RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEElevationSourceCollectionHandle RT_GEElevationSourceCollection_create(const RT_ErrorHandler* errorHandler);

size_t RT_GEElevationSourceCollection_getSize(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_GEElevationSourceCollection_add(RT_GEElevationSourceCollectionHandle thisHandle, const RT_GEElevationSourceHandle value, const RT_ErrorHandler* errorHandler);
size_t RT_GEElevationSourceCollection_addArray(RT_GEElevationSourceCollectionHandle thisHandle, const RT_GEElevationSourceCollectionHandle vector2, const RT_ErrorHandler* errorHandler);
RT_GEElevationSourceHandle RT_GEElevationSourceCollection_at(const RT_GEElevationSourceCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
bool RT_GEElevationSourceCollection_contains(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_GEElevationSourceHandle value, const RT_ErrorHandler* errorHandler);
bool RT_GEElevationSourceCollection_equals(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_GEElevationSourceCollectionHandle vector2, const RT_ErrorHandler* errorHandler);
RT_GEElevationSourceHandle RT_GEElevationSourceCollection_first(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_GEElevationSourceCollection_indexOf(const RT_GEElevationSourceCollectionHandle thisHandle, RT_GEElevationSourceHandle value, const RT_ErrorHandler* errorHandler);
void RT_GEElevationSourceCollection_insert(RT_GEElevationSourceCollectionHandle thisHandle, size_t position, const RT_GEElevationSourceHandle value, const RT_ErrorHandler* errorHandler);
bool RT_GEElevationSourceCollection_isEmpty(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEElevationSourceHandle RT_GEElevationSourceCollection_last(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GEElevationSourceCollection_move(RT_GEElevationSourceCollectionHandle thisHandle, size_t oldPosition, size_t newPosition, const RT_ErrorHandler* errorHandler);
size_t RT_GEElevationSourceCollection_npos(const RT_ErrorHandler* errorHandler);
void RT_GEElevationSourceCollection_remove(RT_GEElevationSourceCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler);
void RT_GEElevationSourceCollection_removeAll(RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif