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
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtent.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEExtent_destroy(RT_GEExtentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEExtent_destroy_def)(RT_GEExtentHandle, const RT_ErrorHandler*);
    static auto RT_GEExtent_destroy_func = reinterpret_cast<RT_GEExtent_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtent_destroy")));
    
    RT_GEExtent_destroy_func(thisHandle, errorHandler);
}

RT_PointHandle RT_GEExtent_getCenter(const RT_GEExtentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_GEExtent_getCenter_def)(const RT_GEExtentHandle, const RT_ErrorHandler*);
    static auto RT_GEExtent_getCenter_func = reinterpret_cast<RT_GEExtent_getCenter_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtent_getCenter")));
    
    return RT_GEExtent_getCenter_func(thisHandle, errorHandler);
}

RT_GEExtentType RT_GEExtent_getObjectType(const RT_GEExtentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEExtentType (*RT_GEExtent_getObjectType_def)(const RT_GEExtentHandle, const RT_ErrorHandler*);
    static auto RT_GEExtent_getObjectType_func = reinterpret_cast<RT_GEExtent_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtent_getObjectType")));
    
    return RT_GEExtent_getObjectType_func(thisHandle, errorHandler);
}
#endif