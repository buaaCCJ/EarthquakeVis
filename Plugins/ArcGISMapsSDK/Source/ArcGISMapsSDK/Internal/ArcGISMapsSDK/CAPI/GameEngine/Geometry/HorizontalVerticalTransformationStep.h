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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/HorizontalVerticalTransformationStepHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_HorizontalVerticalTransformationStep_destroy(RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_HorizontalVerticalTransformationStepHandle RT_HorizontalVerticalTransformationStep_createWithWKID(int32_t WKID, const RT_ErrorHandler* errorHandler);
RT_HorizontalVerticalTransformationStepHandle RT_HorizontalVerticalTransformationStep_createWithWKText(const char* WKText, const RT_ErrorHandler* errorHandler);

bool RT_HorizontalVerticalTransformationStep_getIsInverse(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_HorizontalVerticalTransformationStep_getIsMissingProjectionEngineFiles(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_HorizontalVerticalTransformationStep_getProjectionEngineFilenames(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
int32_t RT_HorizontalVerticalTransformationStep_getWKID(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_HorizontalVerticalTransformationStep_getWKText(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_HorizontalVerticalTransformationStep_equals(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_HorizontalVerticalTransformationStepHandle rightHorizontalVerticalTransformationStep, const RT_ErrorHandler* errorHandler);
size_t RT_HorizontalVerticalTransformationStep_getHash(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_HorizontalVerticalTransformationStepHandle RT_HorizontalVerticalTransformationStep_getInverse(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif