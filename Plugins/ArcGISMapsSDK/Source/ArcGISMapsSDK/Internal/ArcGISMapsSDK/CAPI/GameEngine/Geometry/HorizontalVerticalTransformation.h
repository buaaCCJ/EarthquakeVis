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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/HorizontalVerticalTransformationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/HorizontalVerticalTransformationStepHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_HorizontalVerticalTransformation_destroy(RT_HorizontalVerticalTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_HorizontalVerticalTransformationHandle RT_HorizontalVerticalTransformation_createWithSteps(const RT_ArrayHandle steps, const RT_ErrorHandler* errorHandler);
RT_HorizontalVerticalTransformationHandle RT_HorizontalVerticalTransformation_createWithStep(const RT_HorizontalVerticalTransformationStepHandle step, const RT_ErrorHandler* errorHandler);

RT_ArrayHandle RT_HorizontalVerticalTransformation_getSteps(const RT_HorizontalVerticalTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif