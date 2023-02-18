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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Point_destroy(RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_Point_createWithXY(double x, double y, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_Point_createWithXYZ(double x, double y, double z, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_Point_createWithXYZSpatialReference(double x, double y, double z, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_Point_createWithXYSpatialReference(double x, double y, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

double RT_Point_getM(const RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Point_getX(const RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Point_getY(const RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Point_getZ(const RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_Point_createWithM(double x, double y, double m, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_Point_createWithZM(double x, double y, double z, double m, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_Point_createWithZMSpatialReference(double x, double y, double z, double m, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_Point_createWithMSpatialReference(double x, double y, double m, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif