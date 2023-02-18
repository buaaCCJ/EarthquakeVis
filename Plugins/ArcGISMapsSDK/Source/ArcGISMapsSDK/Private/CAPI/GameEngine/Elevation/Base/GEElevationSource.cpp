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
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSource.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEElevationSource_destroy(RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSource_destroy_def)(RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_destroy_func = reinterpret_cast<RT_GEElevationSource_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_destroy")));
    
    RT_GEElevationSource_destroy_func(thisHandle, errorHandler);
}

RT_GEElevationSourceHandle RT_GEElevationSource_create(const char* source, RT_GEElevationSourceType type, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceHandle (*RT_GEElevationSource_create_def)(const char*, RT_GEElevationSourceType, const char*, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_create_func = reinterpret_cast<RT_GEElevationSource_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_create")));
    
    return RT_GEElevationSource_create_func(source, type, APIKey, errorHandler);
}

RT_StringHandle RT_GEElevationSource_getAPIKey(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEElevationSource_getAPIKey_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getAPIKey_func = reinterpret_cast<RT_GEElevationSource_getAPIKey_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getAPIKey")));
    
    return RT_GEElevationSource_getAPIKey_func(thisHandle, errorHandler);
}

RT_GEExtentRectangleHandle RT_GEElevationSource_getExtent(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEExtentRectangleHandle (*RT_GEElevationSource_getExtent_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getExtent_func = reinterpret_cast<RT_GEElevationSource_getExtent_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getExtent")));
    
    return RT_GEElevationSource_getExtent_func(thisHandle, errorHandler);
}

bool RT_GEElevationSource_getIsEnabled(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GEElevationSource_getIsEnabled_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getIsEnabled_func = reinterpret_cast<RT_GEElevationSource_getIsEnabled_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getIsEnabled")));
    
    return RT_GEElevationSource_getIsEnabled_func(thisHandle, errorHandler);
}
void RT_GEElevationSource_setIsEnabled(RT_GEElevationSourceHandle thisHandle, bool isEnabled, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSource_setIsEnabled_def)(RT_GEElevationSourceHandle, bool, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_setIsEnabled_func = reinterpret_cast<RT_GEElevationSource_setIsEnabled_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_setIsEnabled")));
    
    RT_GEElevationSource_setIsEnabled_func(thisHandle, isEnabled, errorHandler);
}

RT_ErrorHandle RT_GEElevationSource_getLoadError(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ErrorHandle (*RT_GEElevationSource_getLoadError_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getLoadError_func = reinterpret_cast<RT_GEElevationSource_getLoadError_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getLoadError")));
    
    return RT_GEElevationSource_getLoadError_func(thisHandle, errorHandler);
}

RT_LoadStatus RT_GEElevationSource_getLoadStatus(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LoadStatus (*RT_GEElevationSource_getLoadStatus_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getLoadStatus_func = reinterpret_cast<RT_GEElevationSource_getLoadStatus_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getLoadStatus")));
    
    return RT_GEElevationSource_getLoadStatus_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEElevationSource_getName(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEElevationSource_getName_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getName_func = reinterpret_cast<RT_GEElevationSource_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getName")));
    
    return RT_GEElevationSource_getName_func(thisHandle, errorHandler);
}
void RT_GEElevationSource_setName(RT_GEElevationSourceHandle thisHandle, char* name, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSource_setName_def)(RT_GEElevationSourceHandle, char*, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_setName_func = reinterpret_cast<RT_GEElevationSource_setName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_setName")));
    
    RT_GEElevationSource_setName_func(thisHandle, name, errorHandler);
}

RT_GEElevationSourceType RT_GEElevationSource_getObjectType(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceType (*RT_GEElevationSource_getObjectType_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getObjectType_func = reinterpret_cast<RT_GEElevationSource_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getObjectType")));
    
    return RT_GEElevationSource_getObjectType_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEElevationSource_getSource(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEElevationSource_getSource_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getSource_func = reinterpret_cast<RT_GEElevationSource_getSource_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getSource")));
    
    return RT_GEElevationSource_getSource_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_GEElevationSource_getSpatialReference(const RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_GEElevationSource_getSpatialReference_def)(const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_getSpatialReference_func = reinterpret_cast<RT_GEElevationSource_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_getSpatialReference")));
    
    return RT_GEElevationSource_getSpatialReference_func(thisHandle, errorHandler);
}

void RT_GEElevationSource_cancelLoad(RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSource_cancelLoad_def)(RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_cancelLoad_func = reinterpret_cast<RT_GEElevationSource_cancelLoad_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_cancelLoad")));
    
    RT_GEElevationSource_cancelLoad_func(thisHandle, errorHandler);
}

void RT_GEElevationSource_load(RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSource_load_def)(RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_load_func = reinterpret_cast<RT_GEElevationSource_load_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_load")));
    
    RT_GEElevationSource_load_func(thisHandle, errorHandler);
}

void RT_GEElevationSource_retryLoad(RT_GEElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSource_retryLoad_def)(RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_retryLoad_func = reinterpret_cast<RT_GEElevationSource_retryLoad_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_retryLoad")));
    
    RT_GEElevationSource_retryLoad_func(thisHandle, errorHandler);
}

void RT_GEElevationSource_setDoneLoadingCallback(RT_GEElevationSourceHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSource_setDoneLoadingCallback_def)(RT_GEElevationSourceHandle, RT_LoadableDoneLoadingEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_setDoneLoadingCallback_func = reinterpret_cast<RT_GEElevationSource_setDoneLoadingCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_setDoneLoadingCallback")));
    
    RT_GEElevationSource_setDoneLoadingCallback_func(thisHandle, callback, userData, errorHandler);
}

void RT_GEElevationSource_setLoadStatusChangedCallback(RT_GEElevationSourceHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSource_setLoadStatusChangedCallback_def)(RT_GEElevationSourceHandle, RT_LoadableLoadStatusChangedEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEElevationSource_setLoadStatusChangedCallback_func = reinterpret_cast<RT_GEElevationSource_setLoadStatusChangedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSource_setLoadStatusChangedCallback")));
    
    RT_GEElevationSource_setLoadStatusChangedCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif