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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodesicSectorParametersHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GeodesicSectorParameters_destroy(RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GeodesicSectorParametersHandle RT_GeodesicSectorParameters_create(const RT_ErrorHandler* errorHandler);
RT_GeodesicSectorParametersHandle RT_GeodesicSectorParameters_createWith(double axisDirection, const RT_AngularUnitHandle angularUnit, const RT_PointHandle center, const RT_LinearUnitHandle linearUnit, uint32_t maxPointCount, double maxSegmentLength, RT_GeometryType geometryType, double sectorAngle, double semiAxis1Length, double semiAxis2Length, double startDirection, const RT_ErrorHandler* errorHandler);
RT_GeodesicSectorParametersHandle RT_GeodesicSectorParameters_createWithCenterAndAxisLengthsAndSectorAngleAndStartDirection(const RT_PointHandle center, double semiAxis1Length, double semiAxis2Length, double sectorAngle, double startDirection, const RT_ErrorHandler* errorHandler);

RT_AngularUnitHandle RT_GeodesicSectorParameters_getAngularUnit(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setAngularUnit(RT_GeodesicSectorParametersHandle thisHandle, RT_AngularUnitHandle angularUnit, const RT_ErrorHandler* errorHandler);
double RT_GeodesicSectorParameters_getAxisDirection(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setAxisDirection(RT_GeodesicSectorParametersHandle thisHandle, double axisDirection, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_GeodesicSectorParameters_getCenter(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setCenter(RT_GeodesicSectorParametersHandle thisHandle, RT_PointHandle center, const RT_ErrorHandler* errorHandler);
RT_GeometryType RT_GeodesicSectorParameters_getGeometryType(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setGeometryType(RT_GeodesicSectorParametersHandle thisHandle, RT_GeometryType geometryType, const RT_ErrorHandler* errorHandler);
RT_LinearUnitHandle RT_GeodesicSectorParameters_getLinearUnit(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setLinearUnit(RT_GeodesicSectorParametersHandle thisHandle, RT_LinearUnitHandle linearUnit, const RT_ErrorHandler* errorHandler);
uint32_t RT_GeodesicSectorParameters_getMaxPointCount(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setMaxPointCount(RT_GeodesicSectorParametersHandle thisHandle, uint32_t maxPointCount, const RT_ErrorHandler* errorHandler);
double RT_GeodesicSectorParameters_getMaxSegmentLength(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setMaxSegmentLength(RT_GeodesicSectorParametersHandle thisHandle, double maxSegmentLength, const RT_ErrorHandler* errorHandler);
double RT_GeodesicSectorParameters_getSectorAngle(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setSectorAngle(RT_GeodesicSectorParametersHandle thisHandle, double sectorAngle, const RT_ErrorHandler* errorHandler);
double RT_GeodesicSectorParameters_getSemiAxis1Length(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setSemiAxis1Length(RT_GeodesicSectorParametersHandle thisHandle, double semiAxis1Length, const RT_ErrorHandler* errorHandler);
double RT_GeodesicSectorParameters_getSemiAxis2Length(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setSemiAxis2Length(RT_GeodesicSectorParametersHandle thisHandle, double semiAxis2Length, const RT_ErrorHandler* errorHandler);
double RT_GeodesicSectorParameters_getStartDirection(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_GeodesicSectorParameters_setStartDirection(RT_GeodesicSectorParametersHandle thisHandle, double startDirection, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif