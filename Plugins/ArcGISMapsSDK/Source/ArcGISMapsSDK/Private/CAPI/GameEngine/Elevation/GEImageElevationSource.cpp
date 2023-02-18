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
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/GEImageElevationSource.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEImageElevationSource_destroy(RT_GEImageElevationSourceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEImageElevationSource_destroy_def)(RT_GEImageElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEImageElevationSource_destroy_func = reinterpret_cast<RT_GEImageElevationSource_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEImageElevationSource_destroy")));
    
    RT_GEImageElevationSource_destroy_func(thisHandle, errorHandler);
}

RT_GEImageElevationSourceHandle RT_GEImageElevationSource_create(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEImageElevationSourceHandle (*RT_GEImageElevationSource_create_def)(const char*, const char*, const RT_ErrorHandler*);
    static auto RT_GEImageElevationSource_create_func = reinterpret_cast<RT_GEImageElevationSource_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEImageElevationSource_create")));
    
    return RT_GEImageElevationSource_create_func(source, APIKey, errorHandler);
}

RT_GEImageElevationSourceHandle RT_GEImageElevationSource_createWithName(const char* source, const char* name, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEImageElevationSourceHandle (*RT_GEImageElevationSource_createWithName_def)(const char*, const char*, const char*, const RT_ErrorHandler*);
    static auto RT_GEImageElevationSource_createWithName_func = reinterpret_cast<RT_GEImageElevationSource_createWithName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEImageElevationSource_createWithName")));
    
    return RT_GEImageElevationSource_createWithName_func(source, name, APIKey, errorHandler);
}
#endif