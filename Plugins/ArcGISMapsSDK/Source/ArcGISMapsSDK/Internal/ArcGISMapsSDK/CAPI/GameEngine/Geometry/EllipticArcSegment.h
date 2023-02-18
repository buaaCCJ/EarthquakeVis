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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EllipticArcSegmentHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_EllipticArcSegment_destroy(RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_EllipticArcSegmentHandle RT_EllipticArcSegment_createWithCenter(const RT_PointHandle centerPoint, double rotationAngle, double semiMajorAxis, double minorMajorRatio, double startAngle, double centralAngle, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_EllipticArcSegmentHandle RT_EllipticArcSegment_createWithStartAndEndpoints(const RT_PointHandle startPoint, const RT_PointHandle endPoint, double rotationAngle, bool isMinor, bool isCounterClockwise, double semiMajorAxis, double minorMajorRatio, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_EllipticArcSegment_getCenterPoint(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EllipticArcSegment_getCentralAngle(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EllipticArcSegment_getEndAngle(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_EllipticArcSegment_getIsCircular(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_EllipticArcSegment_getIsCounterClockwise(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EllipticArcSegment_getMinorMajorRatio(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EllipticArcSegment_getRotationAngle(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EllipticArcSegment_getSemiMajorAxis(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EllipticArcSegment_getSemiMinorAxis(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EllipticArcSegment_getStartAngle(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_EllipticArcSegmentHandle RT_EllipticArcSegment_createCircularEllipticArcWithCenterRadiusAndAngles(const RT_PointHandle centerPoint, double radius, double startAngle, double centralAngle, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_EllipticArcSegmentHandle RT_EllipticArcSegment_createCircularEllipticArcWithStartEndAndInterior(const RT_PointHandle startPoint, const RT_PointHandle endPoint, const RT_PointHandle interiorPoint, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif