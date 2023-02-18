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
#include "ArcGISMapsSDK/CAPI/GameEngine/MapView/CameraHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Camera_destroy(RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_CameraHandle RT_Camera_createWithLocationHeadingPitchRoll(const RT_PointHandle locationPoint, double heading, double pitch, double roll, const RT_ErrorHandler* errorHandler);

double RT_Camera_getHeading(const RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_Camera_getLocation(const RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Camera_getPitch(const RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Camera_getRoll(const RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_CameraHandle RT_Camera_elevate(const RT_CameraHandle thisHandle, double deltaAltitude, const RT_ErrorHandler* errorHandler);
bool RT_Camera_equals(const RT_CameraHandle thisHandle, const RT_CameraHandle otherCamera, const RT_ErrorHandler* errorHandler);
RT_CameraHandle RT_Camera_moveTo(const RT_CameraHandle thisHandle, const RT_PointHandle location, const RT_ErrorHandler* errorHandler);
RT_CameraHandle RT_Camera_rotateTo(const RT_CameraHandle thisHandle, double heading, double pitch, double roll, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif