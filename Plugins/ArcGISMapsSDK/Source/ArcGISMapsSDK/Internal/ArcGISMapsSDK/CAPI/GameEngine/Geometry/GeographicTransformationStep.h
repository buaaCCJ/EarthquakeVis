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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeographicTransformationStepHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GeographicTransformationStep_destroy(RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GeographicTransformationStepHandle RT_GeographicTransformationStep_createWithWKID(int32_t WKID, const RT_ErrorHandler* errorHandler);
RT_GeographicTransformationStepHandle RT_GeographicTransformationStep_createWithWKText(const char* WKText, const RT_ErrorHandler* errorHandler);

bool RT_GeographicTransformationStep_getIsInverse(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_GeographicTransformationStep_getIsMissingProjectionEngineFiles(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_GeographicTransformationStep_getProjectionEngineFilenames(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
int32_t RT_GeographicTransformationStep_getWKID(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_GeographicTransformationStep_getWKText(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_GeographicTransformationStep_equals(const RT_GeographicTransformationStepHandle thisHandle, const RT_GeographicTransformationStepHandle rightGeographicTransformationStep, const RT_ErrorHandler* errorHandler);
size_t RT_GeographicTransformationStep_getHash(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GeographicTransformationStepHandle RT_GeographicTransformationStep_getInverse(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif