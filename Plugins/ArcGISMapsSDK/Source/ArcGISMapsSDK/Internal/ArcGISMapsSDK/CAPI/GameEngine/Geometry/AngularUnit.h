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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AngularUnitId.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_AngularUnit_destroy(RT_AngularUnitHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_AngularUnitHandle RT_AngularUnit_create(RT_AngularUnitId unitId, const RT_ErrorHandler* errorHandler);

RT_AngularUnitId RT_AngularUnit_getAngularUnitId(const RT_AngularUnitHandle thisHandle, const RT_ErrorHandler* errorHandler);

double RT_AngularUnit_convertFrom(const RT_AngularUnitHandle thisHandle, const RT_AngularUnitHandle fromUnit, double angle, const RT_ErrorHandler* errorHandler);
double RT_AngularUnit_convertTo(const RT_AngularUnitHandle thisHandle, const RT_AngularUnitHandle toUnit, double angle, const RT_ErrorHandler* errorHandler);
double RT_AngularUnit_fromRadians(const RT_AngularUnitHandle thisHandle, double radians, const RT_ErrorHandler* errorHandler);
double RT_AngularUnit_toRadians(const RT_AngularUnitHandle thisHandle, double angle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif