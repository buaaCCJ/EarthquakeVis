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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointBuilderHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_PointBuilder_destroy(RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_PointBuilderHandle RT_PointBuilder_createFromPoint(const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
RT_PointBuilderHandle RT_PointBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

double RT_PointBuilder_getM(const RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_PointBuilder_setM(RT_PointBuilderHandle thisHandle, double m, const RT_ErrorHandler* errorHandler);
double RT_PointBuilder_getX(const RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_PointBuilder_setX(RT_PointBuilderHandle thisHandle, double x, const RT_ErrorHandler* errorHandler);
double RT_PointBuilder_getY(const RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_PointBuilder_setY(RT_PointBuilderHandle thisHandle, double y, const RT_ErrorHandler* errorHandler);
double RT_PointBuilder_getZ(const RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_PointBuilder_setZ(RT_PointBuilderHandle thisHandle, double z, const RT_ErrorHandler* errorHandler);

void RT_PointBuilder_normalize(RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_PointBuilder_normalizeToEnvelope(RT_PointBuilderHandle thisHandle, const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler);
void RT_PointBuilder_normalizeToPointClosestTo(RT_PointBuilderHandle thisHandle, const RT_PointHandle target, const RT_ErrorHandler* errorHandler);
void RT_PointBuilder_offsetBy(RT_PointBuilderHandle thisHandle, double offsetX, double offsetY, const RT_ErrorHandler* errorHandler);
void RT_PointBuilder_setXY(RT_PointBuilderHandle thisHandle, double x, double y, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif