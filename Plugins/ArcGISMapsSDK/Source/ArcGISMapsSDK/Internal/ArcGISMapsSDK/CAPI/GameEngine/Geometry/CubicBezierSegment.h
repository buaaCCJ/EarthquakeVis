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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/CubicBezierSegmentHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_CubicBezierSegment_destroy(RT_CubicBezierSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_CubicBezierSegmentHandle RT_CubicBezierSegment_create(const RT_PointHandle startPoint, const RT_PointHandle controlPoint1, const RT_PointHandle controlPoint2, const RT_PointHandle endPoint, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_CubicBezierSegment_getControlPoint1(const RT_CubicBezierSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_CubicBezierSegment_getControlPoint2(const RT_CubicBezierSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif