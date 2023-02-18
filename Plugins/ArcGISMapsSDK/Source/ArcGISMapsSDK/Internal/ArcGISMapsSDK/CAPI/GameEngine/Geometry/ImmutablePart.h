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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePartHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePointCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SegmentHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_ImmutablePart_destroy(RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_ImmutablePart_getEndPoint(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_ImmutablePart_getHasCurves(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_ImmutablePart_getIsEmpty(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePart_getPointCount(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePart_getSegmentCount(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_ImmutablePart_getSpatialReference(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_ImmutablePart_getStartPoint(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);

size_t RT_ImmutablePart_getEndPointIndexFromSegmentIndex(const RT_ImmutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_ImmutablePart_getPoint(const RT_ImmutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler);
RT_ImmutablePointCollectionHandle RT_ImmutablePart_getPoints(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SegmentHandle RT_ImmutablePart_getSegment(const RT_ImmutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePart_getSegmentIndexFromEndPointIndex(const RT_ImmutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler);
void RT_ImmutablePart_getSegmentIndexFromPointIndex(const RT_ImmutablePartHandle thisHandle, size_t pointIndex, size_t* outStartPointSegmentIndex, size_t* outEndPointSegmentIndex, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePart_getSegmentIndexFromStartPointIndex(const RT_ImmutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler);
size_t RT_ImmutablePart_getStartPointIndexFromSegmentIndex(const RT_ImmutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif