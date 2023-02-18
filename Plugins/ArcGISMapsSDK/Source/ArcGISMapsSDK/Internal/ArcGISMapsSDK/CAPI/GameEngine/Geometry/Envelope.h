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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Envelope_destroy(RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_EnvelopeHandle RT_Envelope_createWithXY(double xMin, double yMin, double xMax, double yMax, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithXYZ(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithXYZSpatialReference(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithXYSpatialReference(double xMin, double yMin, double xMax, double yMax, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithCenterPoint(const RT_PointHandle center, double width, double height, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithCenterPointAndDepth(const RT_PointHandle center, double width, double height, double depth, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithPoints(const RT_PointHandle min, const RT_PointHandle max, const RT_ErrorHandler* errorHandler);

RT_PointHandle RT_Envelope_getCenter(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getDepth(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getHeight(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getMMax(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getMMin(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getWidth(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getXMax(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getXMin(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getYMax(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getYMin(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getZMax(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Envelope_getZMin(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_EnvelopeHandle RT_Envelope_createWithM(double xMin, double yMin, double xMax, double yMax, double mMin, double mMax, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithZM(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, double mMin, double mMax, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithZMSpatialReference(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, double mMin, double mMax, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Envelope_createWithMSpatialReference(double xMin, double yMin, double xMax, double yMax, double mMin, double mMax, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif