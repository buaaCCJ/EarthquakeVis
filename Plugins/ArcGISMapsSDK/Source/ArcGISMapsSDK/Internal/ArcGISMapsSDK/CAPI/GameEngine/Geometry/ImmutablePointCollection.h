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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePointCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_ImmutablePointCollection_destroy(RT_ImmutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_ImmutablePointCollection_getIsEmpty(const RT_ImmutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePointCollection_getSize(const RT_ImmutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_ImmutablePointCollection_getSpatialReference(const RT_ImmutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_ImmutablePointCollection_getPoint(const RT_ImmutablePointCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePointCollection_indexOf(const RT_ImmutablePointCollectionHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif