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
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMap.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEMap_destroy(RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_destroy_def)(RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_destroy_func = reinterpret_cast<RT_GEMap_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_destroy")));
    
    RT_GEMap_destroy_func(thisHandle, errorHandler);
}

RT_GEMapHandle RT_GEMap_createWithBasemapAndMapType(RT_GEBasemapHandle basemap, RT_GEMapType mapType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEMapHandle (*RT_GEMap_createWithBasemapAndMapType_def)(RT_GEBasemapHandle, RT_GEMapType, const RT_ErrorHandler*);
    static auto RT_GEMap_createWithBasemapAndMapType_func = reinterpret_cast<RT_GEMap_createWithBasemapAndMapType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_createWithBasemapAndMapType")));
    
    return RT_GEMap_createWithBasemapAndMapType_func(basemap, mapType, errorHandler);
}

RT_GEMapHandle RT_GEMap_createWithMapType(RT_GEMapType mapType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEMapHandle (*RT_GEMap_createWithMapType_def)(RT_GEMapType, const RT_ErrorHandler*);
    static auto RT_GEMap_createWithMapType_func = reinterpret_cast<RT_GEMap_createWithMapType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_createWithMapType")));
    
    return RT_GEMap_createWithMapType_func(mapType, errorHandler);
}

RT_GEMapHandle RT_GEMap_createWithSpatialReferenceAndMapType(const RT_SpatialReferenceHandle spatialReference, RT_GEMapType mapType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEMapHandle (*RT_GEMap_createWithSpatialReferenceAndMapType_def)(const RT_SpatialReferenceHandle, RT_GEMapType, const RT_ErrorHandler*);
    static auto RT_GEMap_createWithSpatialReferenceAndMapType_func = reinterpret_cast<RT_GEMap_createWithSpatialReferenceAndMapType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_createWithSpatialReferenceAndMapType")));
    
    return RT_GEMap_createWithSpatialReferenceAndMapType_func(spatialReference, mapType, errorHandler);
}

RT_GEBasemapHandle RT_GEMap_getBasemap(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEBasemapHandle (*RT_GEMap_getBasemap_def)(const RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_getBasemap_func = reinterpret_cast<RT_GEMap_getBasemap_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_getBasemap")));
    
    return RT_GEMap_getBasemap_func(thisHandle, errorHandler);
}
void RT_GEMap_setBasemap(RT_GEMapHandle thisHandle, RT_GEBasemapHandle basemap, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_setBasemap_def)(RT_GEMapHandle, RT_GEBasemapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_setBasemap_func = reinterpret_cast<RT_GEMap_setBasemap_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_setBasemap")));
    
    RT_GEMap_setBasemap_func(thisHandle, basemap, errorHandler);
}

RT_GEExtentHandle RT_GEMap_getClippingArea(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEExtentHandle (*RT_GEMap_getClippingArea_def)(const RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_getClippingArea_func = reinterpret_cast<RT_GEMap_getClippingArea_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_getClippingArea")));
    
    return RT_GEMap_getClippingArea_func(thisHandle, errorHandler);
}
void RT_GEMap_setClippingArea(RT_GEMapHandle thisHandle, RT_GEExtentHandle clippingArea, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_setClippingArea_def)(RT_GEMapHandle, RT_GEExtentHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_setClippingArea_func = reinterpret_cast<RT_GEMap_setClippingArea_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_setClippingArea")));
    
    RT_GEMap_setClippingArea_func(thisHandle, clippingArea, errorHandler);
}

RT_GEMapElevationHandle RT_GEMap_getElevation(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEMapElevationHandle (*RT_GEMap_getElevation_def)(const RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_getElevation_func = reinterpret_cast<RT_GEMap_getElevation_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_getElevation")));
    
    return RT_GEMap_getElevation_func(thisHandle, errorHandler);
}
void RT_GEMap_setElevation(RT_GEMapHandle thisHandle, RT_GEMapElevationHandle elevation, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_setElevation_def)(RT_GEMapHandle, RT_GEMapElevationHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_setElevation_func = reinterpret_cast<RT_GEMap_setElevation_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_setElevation")));
    
    RT_GEMap_setElevation_func(thisHandle, elevation, errorHandler);
}

RT_GELayerCollectionHandle RT_GEMap_getLayers(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerCollectionHandle (*RT_GEMap_getLayers_def)(const RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_getLayers_func = reinterpret_cast<RT_GEMap_getLayers_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_getLayers")));
    
    return RT_GEMap_getLayers_func(thisHandle, errorHandler);
}
void RT_GEMap_setLayers(RT_GEMapHandle thisHandle, RT_GELayerCollectionHandle layers, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_setLayers_def)(RT_GEMapHandle, RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_setLayers_func = reinterpret_cast<RT_GEMap_setLayers_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_setLayers")));
    
    RT_GEMap_setLayers_func(thisHandle, layers, errorHandler);
}

RT_ErrorHandle RT_GEMap_getLoadError(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ErrorHandle (*RT_GEMap_getLoadError_def)(const RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_getLoadError_func = reinterpret_cast<RT_GEMap_getLoadError_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_getLoadError")));
    
    return RT_GEMap_getLoadError_func(thisHandle, errorHandler);
}

RT_LoadStatus RT_GEMap_getLoadStatus(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LoadStatus (*RT_GEMap_getLoadStatus_def)(const RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_getLoadStatus_func = reinterpret_cast<RT_GEMap_getLoadStatus_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_getLoadStatus")));
    
    return RT_GEMap_getLoadStatus_func(thisHandle, errorHandler);
}

RT_GEMapType RT_GEMap_getMapType(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEMapType (*RT_GEMap_getMapType_def)(const RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_getMapType_func = reinterpret_cast<RT_GEMap_getMapType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_getMapType")));
    
    return RT_GEMap_getMapType_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_GEMap_getSpatialReference(const RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_GEMap_getSpatialReference_def)(const RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_getSpatialReference_func = reinterpret_cast<RT_GEMap_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_getSpatialReference")));
    
    return RT_GEMap_getSpatialReference_func(thisHandle, errorHandler);
}

void RT_GEMap_cancelLoad(RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_cancelLoad_def)(RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_cancelLoad_func = reinterpret_cast<RT_GEMap_cancelLoad_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_cancelLoad")));
    
    RT_GEMap_cancelLoad_func(thisHandle, errorHandler);
}

RT_GELayerHandle RT_GEMap_findLayerById(const RT_GEMapHandle thisHandle, uint32_t layerId, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerHandle (*RT_GEMap_findLayerById_def)(const RT_GEMapHandle, uint32_t, const RT_ErrorHandler*);
    static auto RT_GEMap_findLayerById_func = reinterpret_cast<RT_GEMap_findLayerById_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_findLayerById")));
    
    return RT_GEMap_findLayerById_func(thisHandle, layerId, errorHandler);
}

void RT_GEMap_load(RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_load_def)(RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_load_func = reinterpret_cast<RT_GEMap_load_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_load")));
    
    RT_GEMap_load_func(thisHandle, errorHandler);
}

void RT_GEMap_retryLoad(RT_GEMapHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_retryLoad_def)(RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEMap_retryLoad_func = reinterpret_cast<RT_GEMap_retryLoad_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_retryLoad")));
    
    RT_GEMap_retryLoad_func(thisHandle, errorHandler);
}

void RT_GEMap_setDoneLoadingCallback(RT_GEMapHandle thisHandle, RT_LoadableDoneLoadingEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_setDoneLoadingCallback_def)(RT_GEMapHandle, RT_LoadableDoneLoadingEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEMap_setDoneLoadingCallback_func = reinterpret_cast<RT_GEMap_setDoneLoadingCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_setDoneLoadingCallback")));
    
    RT_GEMap_setDoneLoadingCallback_func(thisHandle, callback, userData, errorHandler);
}

void RT_GEMap_setLoadStatusChangedCallback(RT_GEMapHandle thisHandle, RT_LoadableLoadStatusChangedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMap_setLoadStatusChangedCallback_def)(RT_GEMapHandle, RT_LoadableLoadStatusChangedEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEMap_setLoadStatusChangedCallback_func = reinterpret_cast<RT_GEMap_setLoadStatusChangedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMap_setLoadStatusChangedCallback")));
    
    RT_GEMap_setLoadStatusChangedCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif