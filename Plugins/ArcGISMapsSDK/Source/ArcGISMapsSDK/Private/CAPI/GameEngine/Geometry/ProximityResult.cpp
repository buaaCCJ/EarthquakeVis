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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ProximityResult.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_ProximityResult_destroy(RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ProximityResult_destroy_def)(RT_ProximityResultHandle, const RT_ErrorHandler*);
    static auto RT_ProximityResult_destroy_func = reinterpret_cast<RT_ProximityResult_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ProximityResult_destroy")));
    
    RT_ProximityResult_destroy_func(thisHandle, errorHandler);
}

RT_PointHandle RT_ProximityResult_getCoordinate(const RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_ProximityResult_getCoordinate_def)(const RT_ProximityResultHandle, const RT_ErrorHandler*);
    static auto RT_ProximityResult_getCoordinate_func = reinterpret_cast<RT_ProximityResult_getCoordinate_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ProximityResult_getCoordinate")));
    
    return RT_ProximityResult_getCoordinate_func(thisHandle, errorHandler);
}

double RT_ProximityResult_getDistance(const RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_ProximityResult_getDistance_def)(const RT_ProximityResultHandle, const RT_ErrorHandler*);
    static auto RT_ProximityResult_getDistance_func = reinterpret_cast<RT_ProximityResult_getDistance_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ProximityResult_getDistance")));
    
    return RT_ProximityResult_getDistance_func(thisHandle, errorHandler);
}

size_t RT_ProximityResult_getPartIndex(const RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ProximityResult_getPartIndex_def)(const RT_ProximityResultHandle, const RT_ErrorHandler*);
    static auto RT_ProximityResult_getPartIndex_func = reinterpret_cast<RT_ProximityResult_getPartIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ProximityResult_getPartIndex")));
    
    return RT_ProximityResult_getPartIndex_func(thisHandle, errorHandler);
}

size_t RT_ProximityResult_getPointIndex(const RT_ProximityResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ProximityResult_getPointIndex_def)(const RT_ProximityResultHandle, const RT_ErrorHandler*);
    static auto RT_ProximityResult_getPointIndex_func = reinterpret_cast<RT_ProximityResult_getPointIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ProximityResult_getPointIndex")));
    
    return RT_ProximityResult_getPointIndex_func(thisHandle, errorHandler);
}
#endif