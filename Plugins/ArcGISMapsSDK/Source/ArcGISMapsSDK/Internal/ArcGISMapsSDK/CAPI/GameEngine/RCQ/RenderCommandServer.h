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

#include "ArcGISMapsSDK/CAPI/GameEngine/DataBufferHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/RCQ/RenderCommandServerHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ByteArrayStruct.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_RenderCommandServer_destroy(RT_RenderCommandServerHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_DataBufferHandle RT_RenderCommandServer_getRenderCommands(const RT_RenderCommandServerHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_RenderCommandServer_notifyRenderableHasGPUResources(RT_RenderCommandServerHandle thisHandle, RT_ByteArray callbackTokens, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif