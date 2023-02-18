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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LineSegmentHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_LineSegment_destroy(RT_LineSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_LineSegmentHandle RT_LineSegment_createWithXY(double xStart, double yStart, double xEnd, double yEnd, const RT_ErrorHandler* errorHandler);
RT_LineSegmentHandle RT_LineSegment_createWithXYZ(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd, const RT_ErrorHandler* errorHandler);
RT_LineSegmentHandle RT_LineSegment_createWithXYZSpatialReference(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_LineSegmentHandle RT_LineSegment_createWithXYSpatialReference(double xStart, double yStart, double xEnd, double yEnd, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_LineSegmentHandle RT_LineSegment_create(const RT_PointHandle startPoint, const RT_PointHandle endPoint, const RT_ErrorHandler* errorHandler);
RT_LineSegmentHandle RT_LineSegment_createWithSpatialReference(const RT_PointHandle startPoint, const RT_PointHandle endPoint, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

RT_LineSegmentHandle RT_LineSegment_createLineAtAngleFromStartPoint(const RT_PointHandle startPoint, double angleRadians, double length, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif