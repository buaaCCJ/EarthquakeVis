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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AngularUnit.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_AngularUnit_destroy(RT_AngularUnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_AngularUnit_destroy_def)(RT_AngularUnitHandle, const RT_ErrorHandler*);
    static auto RT_AngularUnit_destroy_func = reinterpret_cast<RT_AngularUnit_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AngularUnit_destroy")));
    
    RT_AngularUnit_destroy_func(thisHandle, errorHandler);
}

RT_AngularUnitHandle RT_AngularUnit_create(RT_AngularUnitId unitId, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AngularUnitHandle (*RT_AngularUnit_create_def)(RT_AngularUnitId, const RT_ErrorHandler*);
    static auto RT_AngularUnit_create_func = reinterpret_cast<RT_AngularUnit_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AngularUnit_create")));
    
    return RT_AngularUnit_create_func(unitId, errorHandler);
}

RT_AngularUnitId RT_AngularUnit_getAngularUnitId(const RT_AngularUnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AngularUnitId (*RT_AngularUnit_getAngularUnitId_def)(const RT_AngularUnitHandle, const RT_ErrorHandler*);
    static auto RT_AngularUnit_getAngularUnitId_func = reinterpret_cast<RT_AngularUnit_getAngularUnitId_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AngularUnit_getAngularUnitId")));
    
    return RT_AngularUnit_getAngularUnitId_func(thisHandle, errorHandler);
}

double RT_AngularUnit_convertFrom(const RT_AngularUnitHandle thisHandle, const RT_AngularUnitHandle fromUnit, double angle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_AngularUnit_convertFrom_def)(const RT_AngularUnitHandle, const RT_AngularUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_AngularUnit_convertFrom_func = reinterpret_cast<RT_AngularUnit_convertFrom_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AngularUnit_convertFrom")));
    
    return RT_AngularUnit_convertFrom_func(thisHandle, fromUnit, angle, errorHandler);
}

double RT_AngularUnit_convertTo(const RT_AngularUnitHandle thisHandle, const RT_AngularUnitHandle toUnit, double angle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_AngularUnit_convertTo_def)(const RT_AngularUnitHandle, const RT_AngularUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_AngularUnit_convertTo_func = reinterpret_cast<RT_AngularUnit_convertTo_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AngularUnit_convertTo")));
    
    return RT_AngularUnit_convertTo_func(thisHandle, toUnit, angle, errorHandler);
}

double RT_AngularUnit_fromRadians(const RT_AngularUnitHandle thisHandle, double radians, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_AngularUnit_fromRadians_def)(const RT_AngularUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_AngularUnit_fromRadians_func = reinterpret_cast<RT_AngularUnit_fromRadians_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AngularUnit_fromRadians")));
    
    return RT_AngularUnit_fromRadians_func(thisHandle, radians, errorHandler);
}

double RT_AngularUnit_toRadians(const RT_AngularUnitHandle thisHandle, double angle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_AngularUnit_toRadians_def)(const RT_AngularUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_AngularUnit_toRadians_func = reinterpret_cast<RT_AngularUnit_toRadians_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AngularUnit_toRadians")));
    
    return RT_AngularUnit_toRadians_func(thisHandle, angle, errorHandler);
}
#endif