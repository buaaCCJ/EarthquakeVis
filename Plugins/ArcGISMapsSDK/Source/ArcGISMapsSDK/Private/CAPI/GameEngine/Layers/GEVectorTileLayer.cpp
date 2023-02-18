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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GEVectorTileLayer.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEVectorTileLayer_destroy(RT_GEVectorTileLayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEVectorTileLayer_destroy_def)(RT_GEVectorTileLayerHandle, const RT_ErrorHandler*);
    static auto RT_GEVectorTileLayer_destroy_func = reinterpret_cast<RT_GEVectorTileLayer_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEVectorTileLayer_destroy")));
    
    RT_GEVectorTileLayer_destroy_func(thisHandle, errorHandler);
}

RT_GEVectorTileLayerHandle RT_GEVectorTileLayer_create(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEVectorTileLayerHandle (*RT_GEVectorTileLayer_create_def)(const char*, const char*, const RT_ErrorHandler*);
    static auto RT_GEVectorTileLayer_create_func = reinterpret_cast<RT_GEVectorTileLayer_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEVectorTileLayer_create")));
    
    return RT_GEVectorTileLayer_create_func(source, APIKey, errorHandler);
}

RT_GEVectorTileLayerHandle RT_GEVectorTileLayer_createWithProperties(const char* source, const char* name, float opacity, bool visible, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEVectorTileLayerHandle (*RT_GEVectorTileLayer_createWithProperties_def)(const char*, const char*, float, bool, const char*, const RT_ErrorHandler*);
    static auto RT_GEVectorTileLayer_createWithProperties_func = reinterpret_cast<RT_GEVectorTileLayer_createWithProperties_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEVectorTileLayer_createWithProperties")));
    
    return RT_GEVectorTileLayer_createWithProperties_func(source, name, opacity, visible, APIKey, errorHandler);
}

RT_VectorTileSourceInfoImmutableCollectionHandle RT_GEVectorTileLayer_getSourceInfos(const RT_GEVectorTileLayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VectorTileSourceInfoImmutableCollectionHandle (*RT_GEVectorTileLayer_getSourceInfos_def)(const RT_GEVectorTileLayerHandle, const RT_ErrorHandler*);
    static auto RT_GEVectorTileLayer_getSourceInfos_func = reinterpret_cast<RT_GEVectorTileLayer_getSourceInfos_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEVectorTileLayer_getSourceInfos")));
    
    return RT_GEVectorTileLayer_getSourceInfos_func(thisHandle, errorHandler);
}

RT_VectorTileStyleHandle RT_GEVectorTileLayer_getStyle(const RT_GEVectorTileLayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VectorTileStyleHandle (*RT_GEVectorTileLayer_getStyle_def)(const RT_GEVectorTileLayerHandle, const RT_ErrorHandler*);
    static auto RT_GEVectorTileLayer_getStyle_func = reinterpret_cast<RT_GEVectorTileLayer_getStyle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEVectorTileLayer_getStyle")));
    
    return RT_GEVectorTileLayer_getStyle_func(thisHandle, errorHandler);
}
#endif