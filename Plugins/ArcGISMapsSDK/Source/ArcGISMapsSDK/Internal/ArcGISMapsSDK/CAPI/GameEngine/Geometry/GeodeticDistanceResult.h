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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodeticDistanceResultHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GeodeticDistanceResult_destroy(RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler);

double RT_GeodeticDistanceResult_getAzimuth1(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_GeodeticDistanceResult_getAzimuth2(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_AngularUnitHandle RT_GeodeticDistanceResult_getAzimuthUnit(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_GeodeticDistanceResult_getDistance(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_LinearUnitHandle RT_GeodeticDistanceResult_getDistanceUnit(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif