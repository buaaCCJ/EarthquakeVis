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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AreaUnitId.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_AreaUnit_destroy(RT_AreaUnitHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_AreaUnitHandle RT_AreaUnit_create(RT_AreaUnitId unitId, const RT_ErrorHandler* errorHandler);
RT_AreaUnitHandle RT_AreaUnit_createFromLinearUnit(const RT_LinearUnitHandle linearUnit, const RT_ErrorHandler* errorHandler);

RT_AreaUnitId RT_AreaUnit_getAreaUnitId(const RT_AreaUnitHandle thisHandle, const RT_ErrorHandler* errorHandler);

double RT_AreaUnit_convertFrom(const RT_AreaUnitHandle thisHandle, const RT_AreaUnitHandle fromUnit, double area, const RT_ErrorHandler* errorHandler);
double RT_AreaUnit_convertTo(const RT_AreaUnitHandle thisHandle, const RT_AreaUnitHandle toUnit, double area, const RT_ErrorHandler* errorHandler);
double RT_AreaUnit_fromSquareMeters(const RT_AreaUnitHandle thisHandle, double area, const RT_ErrorHandler* errorHandler);
double RT_AreaUnit_toSquareMeters(const RT_AreaUnitHandle thisHandle, double area, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif