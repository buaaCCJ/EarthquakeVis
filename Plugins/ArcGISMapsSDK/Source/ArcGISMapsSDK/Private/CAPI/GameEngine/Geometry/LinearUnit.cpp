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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnit.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_LinearUnit_destroy(RT_LinearUnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_LinearUnit_destroy_def)(RT_LinearUnitHandle, const RT_ErrorHandler*);
    static auto RT_LinearUnit_destroy_func = reinterpret_cast<RT_LinearUnit_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LinearUnit_destroy")));
    
    RT_LinearUnit_destroy_func(thisHandle, errorHandler);
}

RT_LinearUnitHandle RT_LinearUnit_createFromAreaUnit(const RT_AreaUnitHandle areaUnit, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LinearUnitHandle (*RT_LinearUnit_createFromAreaUnit_def)(const RT_AreaUnitHandle, const RT_ErrorHandler*);
    static auto RT_LinearUnit_createFromAreaUnit_func = reinterpret_cast<RT_LinearUnit_createFromAreaUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LinearUnit_createFromAreaUnit")));
    
    return RT_LinearUnit_createFromAreaUnit_func(areaUnit, errorHandler);
}

RT_LinearUnitHandle RT_LinearUnit_create(RT_LinearUnitId unitId, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LinearUnitHandle (*RT_LinearUnit_create_def)(RT_LinearUnitId, const RT_ErrorHandler*);
    static auto RT_LinearUnit_create_func = reinterpret_cast<RT_LinearUnit_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LinearUnit_create")));
    
    return RT_LinearUnit_create_func(unitId, errorHandler);
}

RT_LinearUnitId RT_LinearUnit_getLinearUnitId(const RT_LinearUnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LinearUnitId (*RT_LinearUnit_getLinearUnitId_def)(const RT_LinearUnitHandle, const RT_ErrorHandler*);
    static auto RT_LinearUnit_getLinearUnitId_func = reinterpret_cast<RT_LinearUnit_getLinearUnitId_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LinearUnit_getLinearUnitId")));
    
    return RT_LinearUnit_getLinearUnitId_func(thisHandle, errorHandler);
}

double RT_LinearUnit_convertFrom(const RT_LinearUnitHandle thisHandle, const RT_LinearUnitHandle fromUnit, double value, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_LinearUnit_convertFrom_def)(const RT_LinearUnitHandle, const RT_LinearUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_LinearUnit_convertFrom_func = reinterpret_cast<RT_LinearUnit_convertFrom_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LinearUnit_convertFrom")));
    
    return RT_LinearUnit_convertFrom_func(thisHandle, fromUnit, value, errorHandler);
}

double RT_LinearUnit_convertTo(const RT_LinearUnitHandle thisHandle, const RT_LinearUnitHandle toUnit, double value, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_LinearUnit_convertTo_def)(const RT_LinearUnitHandle, const RT_LinearUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_LinearUnit_convertTo_func = reinterpret_cast<RT_LinearUnit_convertTo_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LinearUnit_convertTo")));
    
    return RT_LinearUnit_convertTo_func(thisHandle, toUnit, value, errorHandler);
}

double RT_LinearUnit_fromMeters(const RT_LinearUnitHandle thisHandle, double value, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_LinearUnit_fromMeters_def)(const RT_LinearUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_LinearUnit_fromMeters_func = reinterpret_cast<RT_LinearUnit_fromMeters_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LinearUnit_fromMeters")));
    
    return RT_LinearUnit_fromMeters_func(thisHandle, value, errorHandler);
}

double RT_LinearUnit_toMeters(const RT_LinearUnitHandle thisHandle, double value, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_LinearUnit_toMeters_def)(const RT_LinearUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_LinearUnit_toMeters_func = reinterpret_cast<RT_LinearUnit_toMeters_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LinearUnit_toMeters")));
    
    return RT_LinearUnit_toMeters_func(thisHandle, value, errorHandler);
}
#endif