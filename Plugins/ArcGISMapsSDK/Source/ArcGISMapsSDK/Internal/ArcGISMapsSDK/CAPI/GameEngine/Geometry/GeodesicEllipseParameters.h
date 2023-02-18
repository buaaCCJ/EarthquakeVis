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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AngularUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodesicEllipseParametersHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GeodesicEllipseParameters_destroy(RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GeodesicEllipseParametersHandle RT_GeodesicEllipseParameters_create(const RT_ErrorHandler* errorHandler);
RT_GeodesicEllipseParametersHandle RT_GeodesicEllipseParameters_createWith(double axisDirection, const RT_AngularUnitHandle angularUnit, const RT_PointHandle center, const RT_LinearUnitHandle linearUnit, uint32_t maxPointCount, double maxSegmentLength, RT_GeometryType geometryType, double semiAxis1Length, double semiAxis2Length, const RT_ErrorHandler* errorHandler);
RT_GeodesicEllipseParametersHandle RT_GeodesicEllipseParameters_createWithCenterAndAxisLengths(const RT_PointHandle center, double semiAxis1Length, double semiAxis2Length, const RT_ErrorHandler* errorHandler);

RT_AngularUnitHandle RT_GeodesicEllipseParameters_getAngularUnit(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setAngularUnit(RT_GeodesicEllipseParametersHandle thisHandle, RT_AngularUnitHandle angularUnit, const RT_ErrorHandler* errorHandler);
double RT_GeodesicEllipseParameters_getAxisDirection(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setAxisDirection(RT_GeodesicEllipseParametersHandle thisHandle, double axisDirection, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_GeodesicEllipseParameters_getCenter(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setCenter(RT_GeodesicEllipseParametersHandle thisHandle, RT_PointHandle center, const RT_ErrorHandler* errorHandler);
RT_GeometryType RT_GeodesicEllipseParameters_getGeometryType(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setGeometryType(RT_GeodesicEllipseParametersHandle thisHandle, RT_GeometryType geometryType, const RT_ErrorHandler* errorHandler);
RT_LinearUnitHandle RT_GeodesicEllipseParameters_getLinearUnit(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setLinearUnit(RT_GeodesicEllipseParametersHandle thisHandle, RT_LinearUnitHandle linearUnit, const RT_ErrorHandler* errorHandler);
uint32_t RT_GeodesicEllipseParameters_getMaxPointCount(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setMaxPointCount(RT_GeodesicEllipseParametersHandle thisHandle, uint32_t maxPointCount, const RT_ErrorHandler* errorHandler);
double RT_GeodesicEllipseParameters_getMaxSegmentLength(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setMaxSegmentLength(RT_GeodesicEllipseParametersHandle thisHandle, double maxSegmentLength, const RT_ErrorHandler* errorHandler);
double RT_GeodesicEllipseParameters_getSemiAxis1Length(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setSemiAxis1Length(RT_GeodesicEllipseParametersHandle thisHandle, double semiAxis1Length, const RT_ErrorHandler* errorHandler);
double RT_GeodesicEllipseParameters_getSemiAxis2Length(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicEllipseParameters_setSemiAxis2Length(RT_GeodesicEllipseParametersHandle thisHandle, double semiAxis2Length, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif