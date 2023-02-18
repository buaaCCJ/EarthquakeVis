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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayer.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GELayer_destroy(RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_destroy_def)(RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_destroy_func = reinterpret_cast<RT_GELayer_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_destroy")));
    
    RT_GELayer_destroy_func(thisHandle, errorHandler);
}

RT_GELayerHandle RT_GELayer_create(const char* source, RT_GELayerType type, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerHandle (*RT_GELayer_create_def)(const char*, RT_GELayerType, const char*, const RT_ErrorHandler*);
    static auto RT_GELayer_create_func = reinterpret_cast<RT_GELayer_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_create")));
    
    return RT_GELayer_create_func(source, type, APIKey, errorHandler);
}

RT_StringHandle RT_GELayer_getAPIKey(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GELayer_getAPIKey_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getAPIKey_func = reinterpret_cast<RT_GELayer_getAPIKey_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getAPIKey")));
    
    return RT_GELayer_getAPIKey_func(thisHandle, errorHandler);
}

RT_GEExtentRectangleHandle RT_GELayer_getExtent(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEExtentRectangleHandle (*RT_GELayer_getExtent_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getExtent_func = reinterpret_cast<RT_GELayer_getExtent_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getExtent")));
    
    return RT_GELayer_getExtent_func(thisHandle, errorHandler);
}

bool RT_GELayer_getIsVisible(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GELayer_getIsVisible_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getIsVisible_func = reinterpret_cast<RT_GELayer_getIsVisible_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getIsVisible")));
    
    return RT_GELayer_getIsVisible_func(thisHandle, errorHandler);
}
void RT_GELayer_setIsVisible(RT_GELayerHandle thisHandle, bool isVisible, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_setIsVisible_def)(RT_GELayerHandle, bool, const RT_ErrorHandler*);
    static auto RT_GELayer_setIsVisible_func = reinterpret_cast<RT_GELayer_setIsVisible_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_setIsVisible")));
    
    RT_GELayer_setIsVisible_func(thisHandle, isVisible, errorHandler);
}

RT_ErrorHandle RT_GELayer_getLoadError(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ErrorHandle (*RT_GELayer_getLoadError_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getLoadError_func = reinterpret_cast<RT_GELayer_getLoadError_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getLoadError")));
    
    return RT_GELayer_getLoadError_func(thisHandle, errorHandler);
}

RT_LoadStatus RT_GELayer_getLoadStatus(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LoadStatus (*RT_GELayer_getLoadStatus_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getLoadStatus_func = reinterpret_cast<RT_GELayer_getLoadStatus_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getLoadStatus")));
    
    return RT_GELayer_getLoadStatus_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GELayer_getName(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GELayer_getName_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getName_func = reinterpret_cast<RT_GELayer_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getName")));
    
    return RT_GELayer_getName_func(thisHandle, errorHandler);
}
void RT_GELayer_setName(RT_GELayerHandle thisHandle, char* name, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_setName_def)(RT_GELayerHandle, char*, const RT_ErrorHandler*);
    static auto RT_GELayer_setName_func = reinterpret_cast<RT_GELayer_setName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_setName")));
    
    RT_GELayer_setName_func(thisHandle, name, errorHandler);
}

RT_GELayerType RT_GELayer_getObjectType(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerType (*RT_GELayer_getObjectType_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getObjectType_func = reinterpret_cast<RT_GELayer_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getObjectType")));
    
    return RT_GELayer_getObjectType_func(thisHandle, errorHandler);
}

float RT_GELayer_getOpacity(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef float (*RT_GELayer_getOpacity_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getOpacity_func = reinterpret_cast<RT_GELayer_getOpacity_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getOpacity")));
    
    return RT_GELayer_getOpacity_func(thisHandle, errorHandler);
}
void RT_GELayer_setOpacity(RT_GELayerHandle thisHandle, float opacity, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_setOpacity_def)(RT_GELayerHandle, float, const RT_ErrorHandler*);
    static auto RT_GELayer_setOpacity_func = reinterpret_cast<RT_GELayer_setOpacity_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_setOpacity")));
    
    RT_GELayer_setOpacity_func(thisHandle, opacity, errorHandler);
}

RT_StringHandle RT_GELayer_getSource(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GELayer_getSource_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getSource_func = reinterpret_cast<RT_GELayer_getSource_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getSource")));
    
    return RT_GELayer_getSource_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_GELayer_getSpatialReference(const RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_GELayer_getSpatialReference_def)(const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_getSpatialReference_func = reinterpret_cast<RT_GELayer_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_getSpatialReference")));
    
    return RT_GELayer_getSpatialReference_func(thisHandle, errorHandler);
}

void RT_GELayer_cancelLoad(RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_cancelLoad_def)(RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_cancelLoad_func = reinterpret_cast<RT_GELayer_cancelLoad_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_cancelLoad")));
    
    RT_GELayer_cancelLoad_func(thisHandle, errorHandler);
}

void RT_GELayer_load(RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_load_def)(RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_load_func = reinterpret_cast<RT_GELayer_load_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_load")));
    
    RT_GELayer_load_func(thisHandle, errorHandler);
}

void RT_GELayer_retryLoad(RT_GELayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_retryLoad_def)(RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayer_retryLoad_func = reinterpret_cast<RT_GELayer_retryLoad_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_retryLoad")));
    
    RT_GELayer_retryLoad_func(thisHandle, errorHandler);
}

void RT_GELayer_setDoneLoadingCallback(RT_GELayerHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_setDoneLoadingCallback_def)(RT_GELayerHandle, RT_LoadableDoneLoadingEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_GELayer_setDoneLoadingCallback_func = reinterpret_cast<RT_GELayer_setDoneLoadingCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_setDoneLoadingCallback")));
    
    RT_GELayer_setDoneLoadingCallback_func(thisHandle, callback, userData, errorHandler);
}

void RT_GELayer_setLoadStatusChangedCallback(RT_GELayerHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayer_setLoadStatusChangedCallback_def)(RT_GELayerHandle, RT_LoadableLoadStatusChangedEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_GELayer_setLoadStatusChangedCallback_func = reinterpret_cast<RT_GELayer_setLoadStatusChangedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayer_setLoadStatusChangedCallback")));
    
    RT_GELayer_setLoadStatusChangedCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif