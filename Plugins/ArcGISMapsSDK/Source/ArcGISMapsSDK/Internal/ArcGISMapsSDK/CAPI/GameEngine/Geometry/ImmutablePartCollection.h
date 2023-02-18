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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePartCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePartHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_ImmutablePartCollection_destroy(RT_ImmutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_ImmutablePartCollection_getIsEmpty(const RT_ImmutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePartCollection_getSize(const RT_ImmutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_ImmutablePartCollection_getSpatialReference(const RT_ImmutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_ImmutablePartHandle RT_ImmutablePartCollection_getPart(const RT_ImmutablePartCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePartCollection_indexOf(const RT_ImmutablePartCollectionHandle thisHandle, const RT_ImmutablePartHandle immutablePart, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif