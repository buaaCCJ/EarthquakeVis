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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeographicTransformationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeographicTransformationStepHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GeographicTransformation_destroy(RT_GeographicTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GeographicTransformationHandle RT_GeographicTransformation_createWithSteps(const RT_ArrayHandle steps, const RT_ErrorHandler* errorHandler);
RT_GeographicTransformationHandle RT_GeographicTransformation_createWithStep(const RT_GeographicTransformationStepHandle step, const RT_ErrorHandler* errorHandler);

RT_ArrayHandle RT_GeographicTransformation_getSteps(const RT_GeographicTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif