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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryBuilderHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryBuilderType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GeometryBuilder_destroy(RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_EnvelopeHandle RT_GeometryBuilder_getExtent(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GeometryBuilder_getHasCurves(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GeometryBuilder_getHasM(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GeometryBuilder_getHasZ(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GeometryBuilder_getIsEmpty(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GeometryBuilder_getIsSketchValid(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GeometryBuilderType RT_GeometryBuilder_getObjectType(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_GeometryBuilder_getSpatialReference(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GeometryBuilderHandle RT_GeometryBuilder_createFromGeometry(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_GeometryBuilderHandle RT_GeometryBuilder_createFromGeometryTypeAndSpatialReference(RT_GeometryType geometryType, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
void RT_GeometryBuilder_replaceGeometry(RT_GeometryBuilderHandle thisHandle, const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryBuilder_toGeometry(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif