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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodeticDistanceResult.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GeodeticDistanceResult_destroy(RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodeticDistanceResult_destroy_def)(RT_GeodeticDistanceResultHandle, const RT_ErrorHandler*);
    static auto RT_GeodeticDistanceResult_destroy_func = reinterpret_cast<RT_GeodeticDistanceResult_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodeticDistanceResult_destroy")));
    
    RT_GeodeticDistanceResult_destroy_func(thisHandle, errorHandler);
}

double RT_GeodeticDistanceResult_getAzimuth1(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodeticDistanceResult_getAzimuth1_def)(const RT_GeodeticDistanceResultHandle, const RT_ErrorHandler*);
    static auto RT_GeodeticDistanceResult_getAzimuth1_func = reinterpret_cast<RT_GeodeticDistanceResult_getAzimuth1_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodeticDistanceResult_getAzimuth1")));
    
    return RT_GeodeticDistanceResult_getAzimuth1_func(thisHandle, errorHandler);
}

double RT_GeodeticDistanceResult_getAzimuth2(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodeticDistanceResult_getAzimuth2_def)(const RT_GeodeticDistanceResultHandle, const RT_ErrorHandler*);
    static auto RT_GeodeticDistanceResult_getAzimuth2_func = reinterpret_cast<RT_GeodeticDistanceResult_getAzimuth2_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodeticDistanceResult_getAzimuth2")));
    
    return RT_GeodeticDistanceResult_getAzimuth2_func(thisHandle, errorHandler);
}

RT_AngularUnitHandle RT_GeodeticDistanceResult_getAzimuthUnit(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AngularUnitHandle (*RT_GeodeticDistanceResult_getAzimuthUnit_def)(const RT_GeodeticDistanceResultHandle, const RT_ErrorHandler*);
    static auto RT_GeodeticDistanceResult_getAzimuthUnit_func = reinterpret_cast<RT_GeodeticDistanceResult_getAzimuthUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodeticDistanceResult_getAzimuthUnit")));
    
    return RT_GeodeticDistanceResult_getAzimuthUnit_func(thisHandle, errorHandler);
}

double RT_GeodeticDistanceResult_getDistance(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodeticDistanceResult_getDistance_def)(const RT_GeodeticDistanceResultHandle, const RT_ErrorHandler*);
    static auto RT_GeodeticDistanceResult_getDistance_func = reinterpret_cast<RT_GeodeticDistanceResult_getDistance_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodeticDistanceResult_getDistance")));
    
    return RT_GeodeticDistanceResult_getDistance_func(thisHandle, errorHandler);
}

RT_LinearUnitHandle RT_GeodeticDistanceResult_getDistanceUnit(const RT_GeodeticDistanceResultHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LinearUnitHandle (*RT_GeodeticDistanceResult_getDistanceUnit_def)(const RT_GeodeticDistanceResultHandle, const RT_ErrorHandler*);
    static auto RT_GeodeticDistanceResult_getDistanceUnit_func = reinterpret_cast<RT_GeodeticDistanceResult_getDistanceUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodeticDistanceResult_getDistanceUnit")));
    
    return RT_GeodeticDistanceResult_getDistanceUnit_func(thisHandle, errorHandler);
}
#endif