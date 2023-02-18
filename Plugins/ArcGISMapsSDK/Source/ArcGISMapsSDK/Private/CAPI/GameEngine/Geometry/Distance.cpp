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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Distance.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Distance_destroy(RT_DistanceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Distance_destroy_def)(RT_DistanceHandle, const RT_ErrorHandler*);
    static auto RT_Distance_destroy_func = reinterpret_cast<RT_Distance_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Distance_destroy")));
    
    RT_Distance_destroy_func(thisHandle, errorHandler);
}

RT_LinearUnitHandle RT_Distance_getUnit(const RT_DistanceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LinearUnitHandle (*RT_Distance_getUnit_def)(const RT_DistanceHandle, const RT_ErrorHandler*);
    static auto RT_Distance_getUnit_func = reinterpret_cast<RT_Distance_getUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Distance_getUnit")));
    
    return RT_Distance_getUnit_func(thisHandle, errorHandler);
}

double RT_Distance_getValue(const RT_DistanceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Distance_getValue_def)(const RT_DistanceHandle, const RT_ErrorHandler*);
    static auto RT_Distance_getValue_func = reinterpret_cast<RT_Distance_getValue_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Distance_getValue")));
    
    return RT_Distance_getValue_func(thisHandle, errorHandler);
}
#endif