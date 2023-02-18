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
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMapElevation.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEMapElevation_destroy(RT_GEMapElevationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMapElevation_destroy_def)(RT_GEMapElevationHandle, const RT_ErrorHandler*);
    static auto RT_GEMapElevation_destroy_func = reinterpret_cast<RT_GEMapElevation_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMapElevation_destroy")));
    
    RT_GEMapElevation_destroy_func(thisHandle, errorHandler);
}

RT_GEMapElevationHandle RT_GEMapElevation_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEMapElevationHandle (*RT_GEMapElevation_create_def)(const RT_ErrorHandler*);
    static auto RT_GEMapElevation_create_func = reinterpret_cast<RT_GEMapElevation_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMapElevation_create")));
    
    return RT_GEMapElevation_create_func(errorHandler);
}

RT_GEMapElevationHandle RT_GEMapElevation_createWithElevationSource(RT_GEElevationSourceHandle elevationSource, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEMapElevationHandle (*RT_GEMapElevation_createWithElevationSource_def)(RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEMapElevation_createWithElevationSource_func = reinterpret_cast<RT_GEMapElevation_createWithElevationSource_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMapElevation_createWithElevationSource")));
    
    return RT_GEMapElevation_createWithElevationSource_func(elevationSource, errorHandler);
}

RT_GEElevationSourceCollectionHandle RT_GEMapElevation_getElevationSources(const RT_GEMapElevationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceCollectionHandle (*RT_GEMapElevation_getElevationSources_def)(const RT_GEMapElevationHandle, const RT_ErrorHandler*);
    static auto RT_GEMapElevation_getElevationSources_func = reinterpret_cast<RT_GEMapElevation_getElevationSources_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMapElevation_getElevationSources")));
    
    return RT_GEMapElevation_getElevationSources_func(thisHandle, errorHandler);
}
void RT_GEMapElevation_setElevationSources(RT_GEMapElevationHandle thisHandle, RT_GEElevationSourceCollectionHandle elevationSources, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEMapElevation_setElevationSources_def)(RT_GEMapElevationHandle, RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEMapElevation_setElevationSources_func = reinterpret_cast<RT_GEMapElevation_setElevationSources_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEMapElevation_setElevationSources")));
    
    RT_GEMapElevation_setElevationSources_func(thisHandle, elevationSources, errorHandler);
}
#endif