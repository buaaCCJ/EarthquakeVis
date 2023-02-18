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
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtentCircle.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEExtentCircle_destroy(RT_GEExtentCircleHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEExtentCircle_destroy_def)(RT_GEExtentCircleHandle, const RT_ErrorHandler*);
    static auto RT_GEExtentCircle_destroy_func = reinterpret_cast<RT_GEExtentCircle_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtentCircle_destroy")));
    
    RT_GEExtentCircle_destroy_func(thisHandle, errorHandler);
}

RT_GEExtentCircleHandle RT_GEExtentCircle_create(const RT_PointHandle center, double radius, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEExtentCircleHandle (*RT_GEExtentCircle_create_def)(const RT_PointHandle, double, const RT_ErrorHandler*);
    static auto RT_GEExtentCircle_create_func = reinterpret_cast<RT_GEExtentCircle_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtentCircle_create")));
    
    return RT_GEExtentCircle_create_func(center, radius, errorHandler);
}

double RT_GEExtentCircle_getRadius(const RT_GEExtentCircleHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GEExtentCircle_getRadius_def)(const RT_GEExtentCircleHandle, const RT_ErrorHandler*);
    static auto RT_GEExtentCircle_getRadius_func = reinterpret_cast<RT_GEExtentCircle_getRadius_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtentCircle_getRadius")));
    
    return RT_GEExtentCircle_getRadius_func(thisHandle, errorHandler);
}
#endif