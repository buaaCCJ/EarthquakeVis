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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SegmentHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SegmentType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Segment_destroy(RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_Segment_getEndPoint(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Segment_getIsClosed(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Segment_getIsCurve(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SegmentType RT_Segment_getObjectType(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_Segment_getSpatialReference(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_Segment_getStartPoint(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_Segment_equals(const RT_SegmentHandle thisHandle, const RT_SegmentHandle right, const RT_ErrorHandler* errorHandler);
size_t RT_Segment_getHash(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif