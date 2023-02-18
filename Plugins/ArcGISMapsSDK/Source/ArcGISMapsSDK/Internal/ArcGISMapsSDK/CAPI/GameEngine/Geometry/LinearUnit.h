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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AreaUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnitId.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_LinearUnit_destroy(RT_LinearUnitHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_LinearUnitHandle RT_LinearUnit_createFromAreaUnit(const RT_AreaUnitHandle areaUnit, const RT_ErrorHandler* errorHandler);
RT_LinearUnitHandle RT_LinearUnit_create(RT_LinearUnitId unitId, const RT_ErrorHandler* errorHandler);

RT_LinearUnitId RT_LinearUnit_getLinearUnitId(const RT_LinearUnitHandle thisHandle, const RT_ErrorHandler* errorHandler);

double RT_LinearUnit_convertFrom(const RT_LinearUnitHandle thisHandle, const RT_LinearUnitHandle fromUnit, double value, const RT_ErrorHandler* errorHandler);
double RT_LinearUnit_convertTo(const RT_LinearUnitHandle thisHandle, const RT_LinearUnitHandle toUnit, double value, const RT_ErrorHandler* errorHandler);
double RT_LinearUnit_fromMeters(const RT_LinearUnitHandle thisHandle, double value, const RT_ErrorHandler* errorHandler);
double RT_LinearUnit_toMeters(const RT_LinearUnitHandle thisHandle, double value, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif