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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryDimension.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Geometry_destroy(RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GeometryDimension RT_Geometry_getDimension(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_Geometry_getExtent(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Geometry_getHasCurves(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Geometry_getHasM(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Geometry_getHasZ(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Geometry_getIsEmpty(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GeometryType RT_Geometry_getObjectType(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_Geometry_getSpatialReference(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_Geometry_equals(const RT_GeometryHandle thisHandle, const RT_GeometryHandle right, const RT_ErrorHandler* errorHandler);
bool RT_Geometry_equalsWithTolerance(const RT_GeometryHandle thisHandle, const RT_GeometryHandle right, double tolerance, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_Geometry_fromJSONWithSpatialReference(const char* inputJSON, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
size_t RT_Geometry_getHash(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif