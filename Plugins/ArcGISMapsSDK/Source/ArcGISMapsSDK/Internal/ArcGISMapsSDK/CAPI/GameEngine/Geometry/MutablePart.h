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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePartHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SegmentHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_MutablePart_destroy(RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_MutablePartHandle RT_MutablePart_createWithSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_MutablePart_getEndPoint(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_MutablePart_getHasCurves(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_MutablePart_getIsEmpty(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_getPointCount(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_getSegmentCount(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_MutablePart_getSpatialReference(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_MutablePart_getStartPoint(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_MutablePart_addPointXY(RT_MutablePartHandle thisHandle, double x, double y, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_addPointXYZ(RT_MutablePartHandle thisHandle, double x, double y, double z, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_addPoint(RT_MutablePartHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_addSegment(RT_MutablePartHandle thisHandle, const RT_SegmentHandle segment, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_getEndPointIndexFromSegmentIndex(const RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_MutablePart_getPoint(const RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler);
RT_ImmutablePointCollectionHandle RT_MutablePart_getPoints(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SegmentHandle RT_MutablePart_getSegment(const RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_getSegmentIndexFromEndPointIndex(const RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_getSegmentIndexFromPointIndex(const RT_MutablePartHandle thisHandle, size_t pointIndex, size_t* outStartPointSegmentIndex, size_t* outEndPointSegmentIndex, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_getSegmentIndexFromStartPointIndex(const RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler);
size_t RT_MutablePart_getStartPointIndexFromSegmentIndex(const RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_insertPointXY(RT_MutablePartHandle thisHandle, size_t pointIndex, double x, double y, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_insertPointXYZ(RT_MutablePartHandle thisHandle, size_t pointIndex, double x, double y, double z, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_insertPoint(RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_insertSegment(RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_SegmentHandle segment, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_removeAll(RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_removePoint(RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_removeSegment(RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_setPoint(RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
void RT_MutablePart_setSegment(RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_SegmentHandle segment, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif