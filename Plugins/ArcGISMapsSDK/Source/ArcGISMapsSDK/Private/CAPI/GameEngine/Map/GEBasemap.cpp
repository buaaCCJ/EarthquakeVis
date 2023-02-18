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
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEBasemap.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEBasemap_destroy(RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_destroy_def)(RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_destroy_func = reinterpret_cast<RT_GEBasemap_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_destroy")));
    
    RT_GEBasemap_destroy_func(thisHandle, errorHandler);
}

RT_GEBasemapHandle RT_GEBasemap_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEBasemapHandle (*RT_GEBasemap_create_def)(const RT_ErrorHandler*);
    static auto RT_GEBasemap_create_func = reinterpret_cast<RT_GEBasemap_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_create")));
    
    return RT_GEBasemap_create_func(errorHandler);
}

RT_GEBasemapHandle RT_GEBasemap_createWithBasemapStyle(RT_BasemapStyle basemapStyle, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEBasemapHandle (*RT_GEBasemap_createWithBasemapStyle_def)(RT_BasemapStyle, const char*, const RT_ErrorHandler*);
    static auto RT_GEBasemap_createWithBasemapStyle_func = reinterpret_cast<RT_GEBasemap_createWithBasemapStyle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_createWithBasemapStyle")));
    
    return RT_GEBasemap_createWithBasemapStyle_func(basemapStyle, APIKey, errorHandler);
}

RT_GEBasemapHandle RT_GEBasemap_createWithLayerSourceAndType(const char* source, RT_GELayerType type, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEBasemapHandle (*RT_GEBasemap_createWithLayerSourceAndType_def)(const char*, RT_GELayerType, const char*, const RT_ErrorHandler*);
    static auto RT_GEBasemap_createWithLayerSourceAndType_func = reinterpret_cast<RT_GEBasemap_createWithLayerSourceAndType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_createWithLayerSourceAndType")));
    
    return RT_GEBasemap_createWithLayerSourceAndType_func(source, type, APIKey, errorHandler);
}

RT_GEBasemapHandle RT_GEBasemap_createWithBasemapSource(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEBasemapHandle (*RT_GEBasemap_createWithBasemapSource_def)(const char*, const char*, const RT_ErrorHandler*);
    static auto RT_GEBasemap_createWithBasemapSource_func = reinterpret_cast<RT_GEBasemap_createWithBasemapSource_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_createWithBasemapSource")));
    
    return RT_GEBasemap_createWithBasemapSource_func(source, APIKey, errorHandler);
}

RT_StringHandle RT_GEBasemap_getAPIKey(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEBasemap_getAPIKey_def)(const RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_getAPIKey_func = reinterpret_cast<RT_GEBasemap_getAPIKey_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_getAPIKey")));
    
    return RT_GEBasemap_getAPIKey_func(thisHandle, errorHandler);
}

RT_GELayerCollectionHandle RT_GEBasemap_getBaseLayers(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerCollectionHandle (*RT_GEBasemap_getBaseLayers_def)(const RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_getBaseLayers_func = reinterpret_cast<RT_GEBasemap_getBaseLayers_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_getBaseLayers")));
    
    return RT_GEBasemap_getBaseLayers_func(thisHandle, errorHandler);
}
void RT_GEBasemap_setBaseLayers(RT_GEBasemapHandle thisHandle, RT_GELayerCollectionHandle baseLayers, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_setBaseLayers_def)(RT_GEBasemapHandle, RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_setBaseLayers_func = reinterpret_cast<RT_GEBasemap_setBaseLayers_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_setBaseLayers")));
    
    RT_GEBasemap_setBaseLayers_func(thisHandle, baseLayers, errorHandler);
}

RT_ErrorHandle RT_GEBasemap_getLoadError(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ErrorHandle (*RT_GEBasemap_getLoadError_def)(const RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_getLoadError_func = reinterpret_cast<RT_GEBasemap_getLoadError_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_getLoadError")));
    
    return RT_GEBasemap_getLoadError_func(thisHandle, errorHandler);
}

RT_LoadStatus RT_GEBasemap_getLoadStatus(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LoadStatus (*RT_GEBasemap_getLoadStatus_def)(const RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_getLoadStatus_func = reinterpret_cast<RT_GEBasemap_getLoadStatus_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_getLoadStatus")));
    
    return RT_GEBasemap_getLoadStatus_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEBasemap_getName(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEBasemap_getName_def)(const RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_getName_func = reinterpret_cast<RT_GEBasemap_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_getName")));
    
    return RT_GEBasemap_getName_func(thisHandle, errorHandler);
}
void RT_GEBasemap_setName(RT_GEBasemapHandle thisHandle, char* name, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_setName_def)(RT_GEBasemapHandle, char*, const RT_ErrorHandler*);
    static auto RT_GEBasemap_setName_func = reinterpret_cast<RT_GEBasemap_setName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_setName")));
    
    RT_GEBasemap_setName_func(thisHandle, name, errorHandler);
}

RT_GELayerCollectionHandle RT_GEBasemap_getReferenceLayers(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerCollectionHandle (*RT_GEBasemap_getReferenceLayers_def)(const RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_getReferenceLayers_func = reinterpret_cast<RT_GEBasemap_getReferenceLayers_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_getReferenceLayers")));
    
    return RT_GEBasemap_getReferenceLayers_func(thisHandle, errorHandler);
}
void RT_GEBasemap_setReferenceLayers(RT_GEBasemapHandle thisHandle, RT_GELayerCollectionHandle referenceLayers, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_setReferenceLayers_def)(RT_GEBasemapHandle, RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_setReferenceLayers_func = reinterpret_cast<RT_GEBasemap_setReferenceLayers_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_setReferenceLayers")));
    
    RT_GEBasemap_setReferenceLayers_func(thisHandle, referenceLayers, errorHandler);
}

RT_StringHandle RT_GEBasemap_getSource(const RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEBasemap_getSource_def)(const RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_getSource_func = reinterpret_cast<RT_GEBasemap_getSource_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_getSource")));
    
    return RT_GEBasemap_getSource_func(thisHandle, errorHandler);
}

void RT_GEBasemap_cancelLoad(RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_cancelLoad_def)(RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_cancelLoad_func = reinterpret_cast<RT_GEBasemap_cancelLoad_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_cancelLoad")));
    
    RT_GEBasemap_cancelLoad_func(thisHandle, errorHandler);
}

void RT_GEBasemap_load(RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_load_def)(RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_load_func = reinterpret_cast<RT_GEBasemap_load_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_load")));
    
    RT_GEBasemap_load_func(thisHandle, errorHandler);
}

void RT_GEBasemap_retryLoad(RT_GEBasemapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_retryLoad_def)(RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEBasemap_retryLoad_func = reinterpret_cast<RT_GEBasemap_retryLoad_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_retryLoad")));
    
    RT_GEBasemap_retryLoad_func(thisHandle, errorHandler);
}

void RT_GEBasemap_setDoneLoadingCallback(RT_GEBasemapHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_setDoneLoadingCallback_def)(RT_GEBasemapHandle, RT_LoadableDoneLoadingEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEBasemap_setDoneLoadingCallback_func = reinterpret_cast<RT_GEBasemap_setDoneLoadingCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_setDoneLoadingCallback")));
    
    RT_GEBasemap_setDoneLoadingCallback_func(thisHandle, callback, userData, errorHandler);
}

void RT_GEBasemap_setLoadStatusChangedCallback(RT_GEBasemapHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEBasemap_setLoadStatusChangedCallback_def)(RT_GEBasemapHandle, RT_LoadableLoadStatusChangedEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEBasemap_setLoadStatusChangedCallback_func = reinterpret_cast<RT_GEBasemap_setLoadStatusChangedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEBasemap_setLoadStatusChangedCallback")));
    
    RT_GEBasemap_setLoadStatusChangedCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif