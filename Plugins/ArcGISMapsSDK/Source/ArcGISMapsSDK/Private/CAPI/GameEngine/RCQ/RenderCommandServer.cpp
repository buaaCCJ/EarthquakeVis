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

#if PLATFORM_MAC || PLATFORM_HOLOLENS
#include "ArcGISMapsSDK/CAPI/GameEngine/RCQ/RenderCommandServer.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_RenderCommandServer_destroy(RT_RenderCommandServerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_RenderCommandServer_destroy_def)(RT_RenderCommandServerHandle, const RT_ErrorHandler*);
    static auto RT_RenderCommandServer_destroy_func = reinterpret_cast<RT_RenderCommandServer_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_RenderCommandServer_destroy")));
    
    RT_RenderCommandServer_destroy_func(thisHandle, errorHandler);
}

RT_DataBufferHandle RT_RenderCommandServer_getRenderCommands(const RT_RenderCommandServerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DataBufferHandle (*RT_RenderCommandServer_getRenderCommands_def)(const RT_RenderCommandServerHandle, const RT_ErrorHandler*);
    static auto RT_RenderCommandServer_getRenderCommands_func = reinterpret_cast<RT_RenderCommandServer_getRenderCommands_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_RenderCommandServer_getRenderCommands")));
    
    return RT_RenderCommandServer_getRenderCommands_func(thisHandle, errorHandler);
}

void RT_RenderCommandServer_notifyRenderableHasGPUResources(RT_RenderCommandServerHandle thisHandle, RT_ByteArray callbackTokens, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_RenderCommandServer_notifyRenderableHasGPUResources_def)(RT_RenderCommandServerHandle, RT_ByteArray, const RT_ErrorHandler*);
    static auto RT_RenderCommandServer_notifyRenderableHasGPUResources_func = reinterpret_cast<RT_RenderCommandServer_notifyRenderableHasGPUResources_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_RenderCommandServer_notifyRenderableHasGPUResources")));
    
    RT_RenderCommandServer_notifyRenderableHasGPUResources_func(thisHandle, callbackTokens, errorHandler);
}
#endif