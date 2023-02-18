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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePointCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_MutablePointCollection_destroy(RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_MutablePointCollectionHandle RT_MutablePointCollection_createWithSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

bool RT_MutablePointCollection_getIsEmpty(const RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePointCollection_getSize(const RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_MutablePointCollection_getSpatialReference(const RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_MutablePointCollection_addPointXY(RT_MutablePointCollectionHandle thisHandle, double x, double y, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePointCollection_addPointXYZ(RT_MutablePointCollectionHandle thisHandle, double x, double y, double z, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePointCollection_addPoint(RT_MutablePointCollectionHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
void RT_MutablePointCollection_addPointsFromImmutable(RT_MutablePointCollectionHandle thisHandle, const RT_ImmutablePointCollectionHandle points, const RT_ErrorHandler* errorHandler);
void RT_MutablePointCollection_addPoints(RT_MutablePointCollectionHandle thisHandle, const RT_MutablePointCollectionHandle points, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_MutablePointCollection_getPoint(const RT_MutablePointCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePointCollection_indexOf(const RT_MutablePointCollectionHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
void RT_MutablePointCollection_insertPointXY(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, double x, double y, const RT_ErrorHandler* errorHandler);
void RT_MutablePointCollection_insertPointXYZ(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, double x, double y, double z, const RT_ErrorHandler* errorHandler);
void RT_MutablePointCollection_insertPoint(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
void RT_MutablePointCollection_removeAll(RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_MutablePointCollection_removePoint(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler);
void RT_MutablePointCollection_setPoint(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif