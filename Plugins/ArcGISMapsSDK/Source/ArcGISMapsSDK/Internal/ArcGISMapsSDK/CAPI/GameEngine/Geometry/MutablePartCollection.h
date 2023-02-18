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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePartCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePartHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_MutablePartCollection_destroy(RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_MutablePartCollectionHandle RT_MutablePartCollection_createWithSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

bool RT_MutablePartCollection_getIsEmpty(const RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePartCollection_getSize(const RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_MutablePartCollection_getSpatialReference(const RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_MutablePartCollection_addPart(RT_MutablePartCollectionHandle thisHandle, const RT_MutablePartHandle mutablePart, const RT_ErrorHandler* errorHandler);
RT_MutablePartHandle RT_MutablePartCollection_getPart(const RT_MutablePartCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePartCollection_indexOf(const RT_MutablePartCollectionHandle thisHandle, const RT_MutablePartHandle mutablePart, const RT_ErrorHandler* errorHandler);
void RT_MutablePartCollection_insertPart(RT_MutablePartCollectionHandle thisHandle, size_t index, const RT_MutablePartHandle mutablePart, const RT_ErrorHandler* errorHandler);
void RT_MutablePartCollection_removeAll(RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_MutablePartCollection_removePart(RT_MutablePartCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler);
void RT_MutablePartCollection_setPart(RT_MutablePartCollectionHandle thisHandle, size_t index, const RT_MutablePartHandle mutablePart, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif