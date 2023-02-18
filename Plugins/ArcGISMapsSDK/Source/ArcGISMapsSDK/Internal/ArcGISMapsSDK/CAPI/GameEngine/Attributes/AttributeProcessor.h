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

#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/AttributeProcessorEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/AttributeProcessorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_AttributeProcessor_destroy(RT_AttributeProcessorHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_AttributeProcessorHandle RT_AttributeProcessor_create(const RT_ErrorHandler* errorHandler);

void RT_AttributeProcessor_setProcessEventCallback(RT_AttributeProcessorHandle thisHandle, RT_Attribute_processor_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif