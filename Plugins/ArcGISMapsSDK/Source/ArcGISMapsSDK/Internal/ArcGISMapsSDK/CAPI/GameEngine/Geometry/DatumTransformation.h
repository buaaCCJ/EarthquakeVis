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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/DatumTransformationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/DatumTransformationType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_DatumTransformation_destroy(RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_SpatialReferenceHandle RT_DatumTransformation_getInputSpatialReference(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_DatumTransformation_getIsMissingProjectionEngineFiles(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_DatumTransformation_getName(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_DatumTransformationType RT_DatumTransformation_getObjectType(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_DatumTransformation_getOutputSpatialReference(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_DatumTransformation_equals(const RT_DatumTransformationHandle thisHandle, const RT_DatumTransformationHandle rightDatumTransformation, const RT_ErrorHandler* errorHandler);
size_t RT_DatumTransformation_getHash(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_DatumTransformationHandle RT_DatumTransformation_getInverse(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif