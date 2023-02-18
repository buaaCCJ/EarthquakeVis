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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeBuilderHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_EnvelopeBuilder_destroy(RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_EnvelopeBuilderHandle RT_EnvelopeBuilder_createFromEnvelope(const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler);
RT_EnvelopeBuilderHandle RT_EnvelopeBuilder_createFromCenterPoint(const RT_PointHandle center, double width, double height, const RT_ErrorHandler* errorHandler);
RT_EnvelopeBuilderHandle RT_EnvelopeBuilder_createFromCenterPointAndDepth(const RT_PointHandle center, double width, double height, double depth, const RT_ErrorHandler* errorHandler);
RT_EnvelopeBuilderHandle RT_EnvelopeBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_EnvelopeBuilder_getCenter(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getDepth(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getHeight(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getMMax(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setMMax(RT_EnvelopeBuilderHandle thisHandle, double mMax, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getMMin(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setMMin(RT_EnvelopeBuilderHandle thisHandle, double mMin, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getWidth(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getXMax(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setXMax(RT_EnvelopeBuilderHandle thisHandle, double xMax, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getXMin(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setXMin(RT_EnvelopeBuilderHandle thisHandle, double xMin, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getYMax(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setYMax(RT_EnvelopeBuilderHandle thisHandle, double yMax, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getYMin(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setYMin(RT_EnvelopeBuilderHandle thisHandle, double yMin, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getZMax(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setZMax(RT_EnvelopeBuilderHandle thisHandle, double zMax, const RT_ErrorHandler* errorHandler);
double RT_EnvelopeBuilder_getZMin(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setZMin(RT_EnvelopeBuilderHandle thisHandle, double zMin, const RT_ErrorHandler* errorHandler);

RT_EnvelopeHandle RT_EnvelopeBuilder_adjustForWrapAround(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_centerAt(RT_EnvelopeBuilderHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_changeAspectRatio(RT_EnvelopeBuilderHandle thisHandle, double width, double height, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_expand(RT_EnvelopeBuilderHandle thisHandle, double factor, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_expandAtAnchor(RT_EnvelopeBuilderHandle thisHandle, const RT_PointHandle anchor, double factor, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_normalize(RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_normalizeToEnvelope(RT_EnvelopeBuilderHandle thisHandle, const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_offsetBy(RT_EnvelopeBuilderHandle thisHandle, double offsetX, double offsetY, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setM(RT_EnvelopeBuilderHandle thisHandle, double mMin, double mMax, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setXY(RT_EnvelopeBuilderHandle thisHandle, double xMin, double yMin, double xMax, double yMax, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_setZ(RT_EnvelopeBuilderHandle thisHandle, double zMin, double zMax, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_unionWithEnvelope(RT_EnvelopeBuilderHandle thisHandle, const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler);
void RT_EnvelopeBuilder_unionWithPoint(RT_EnvelopeBuilderHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif