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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GEImageLayer.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEImageLayer_destroy(RT_GEImageLayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEImageLayer_destroy_def)(RT_GEImageLayerHandle, const RT_ErrorHandler*);
    static auto RT_GEImageLayer_destroy_func = reinterpret_cast<RT_GEImageLayer_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEImageLayer_destroy")));
    
    RT_GEImageLayer_destroy_func(thisHandle, errorHandler);
}

RT_GEImageLayerHandle RT_GEImageLayer_create(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEImageLayerHandle (*RT_GEImageLayer_create_def)(const char*, const char*, const RT_ErrorHandler*);
    static auto RT_GEImageLayer_create_func = reinterpret_cast<RT_GEImageLayer_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEImageLayer_create")));
    
    return RT_GEImageLayer_create_func(source, APIKey, errorHandler);
}

RT_GEImageLayerHandle RT_GEImageLayer_createWithProperties(const char* source, const char* name, float opacity, bool visible, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEImageLayerHandle (*RT_GEImageLayer_createWithProperties_def)(const char*, const char*, float, bool, const char*, const RT_ErrorHandler*);
    static auto RT_GEImageLayer_createWithProperties_func = reinterpret_cast<RT_GEImageLayer_createWithProperties_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEImageLayer_createWithProperties")));
    
    return RT_GEImageLayer_createWithProperties_func(source, name, opacity, visible, APIKey, errorHandler);
}
#endif