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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GEIntegratedMeshLayer.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEIntegratedMeshLayer_destroy(RT_GEIntegratedMeshLayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEIntegratedMeshLayer_destroy_def)(RT_GEIntegratedMeshLayerHandle, const RT_ErrorHandler*);
    static auto RT_GEIntegratedMeshLayer_destroy_func = reinterpret_cast<RT_GEIntegratedMeshLayer_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEIntegratedMeshLayer_destroy")));
    
    RT_GEIntegratedMeshLayer_destroy_func(thisHandle, errorHandler);
}

RT_GEIntegratedMeshLayerHandle RT_GEIntegratedMeshLayer_create(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEIntegratedMeshLayerHandle (*RT_GEIntegratedMeshLayer_create_def)(const char*, const char*, const RT_ErrorHandler*);
    static auto RT_GEIntegratedMeshLayer_create_func = reinterpret_cast<RT_GEIntegratedMeshLayer_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEIntegratedMeshLayer_create")));
    
    return RT_GEIntegratedMeshLayer_create_func(source, APIKey, errorHandler);
}

RT_GEIntegratedMeshLayerHandle RT_GEIntegratedMeshLayer_createWithProperties(const char* source, const char* name, float opacity, bool visible, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEIntegratedMeshLayerHandle (*RT_GEIntegratedMeshLayer_createWithProperties_def)(const char*, const char*, float, bool, const char*, const RT_ErrorHandler*);
    static auto RT_GEIntegratedMeshLayer_createWithProperties_func = reinterpret_cast<RT_GEIntegratedMeshLayer_createWithProperties_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEIntegratedMeshLayer_createWithProperties")));
    
    return RT_GEIntegratedMeshLayer_createWithProperties_func(source, name, opacity, visible, APIKey, errorHandler);
}
#endif