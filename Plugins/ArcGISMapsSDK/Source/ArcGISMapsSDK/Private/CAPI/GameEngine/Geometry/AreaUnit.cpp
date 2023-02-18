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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AreaUnit.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_AreaUnit_destroy(RT_AreaUnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_AreaUnit_destroy_def)(RT_AreaUnitHandle, const RT_ErrorHandler*);
    static auto RT_AreaUnit_destroy_func = reinterpret_cast<RT_AreaUnit_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AreaUnit_destroy")));
    
    RT_AreaUnit_destroy_func(thisHandle, errorHandler);
}

RT_AreaUnitHandle RT_AreaUnit_create(RT_AreaUnitId unitId, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AreaUnitHandle (*RT_AreaUnit_create_def)(RT_AreaUnitId, const RT_ErrorHandler*);
    static auto RT_AreaUnit_create_func = reinterpret_cast<RT_AreaUnit_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AreaUnit_create")));
    
    return RT_AreaUnit_create_func(unitId, errorHandler);
}

RT_AreaUnitHandle RT_AreaUnit_createFromLinearUnit(const RT_LinearUnitHandle linearUnit, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AreaUnitHandle (*RT_AreaUnit_createFromLinearUnit_def)(const RT_LinearUnitHandle, const RT_ErrorHandler*);
    static auto RT_AreaUnit_createFromLinearUnit_func = reinterpret_cast<RT_AreaUnit_createFromLinearUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AreaUnit_createFromLinearUnit")));
    
    return RT_AreaUnit_createFromLinearUnit_func(linearUnit, errorHandler);
}

RT_AreaUnitId RT_AreaUnit_getAreaUnitId(const RT_AreaUnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AreaUnitId (*RT_AreaUnit_getAreaUnitId_def)(const RT_AreaUnitHandle, const RT_ErrorHandler*);
    static auto RT_AreaUnit_getAreaUnitId_func = reinterpret_cast<RT_AreaUnit_getAreaUnitId_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AreaUnit_getAreaUnitId")));
    
    return RT_AreaUnit_getAreaUnitId_func(thisHandle, errorHandler);
}

double RT_AreaUnit_convertFrom(const RT_AreaUnitHandle thisHandle, const RT_AreaUnitHandle fromUnit, double area, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_AreaUnit_convertFrom_def)(const RT_AreaUnitHandle, const RT_AreaUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_AreaUnit_convertFrom_func = reinterpret_cast<RT_AreaUnit_convertFrom_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AreaUnit_convertFrom")));
    
    return RT_AreaUnit_convertFrom_func(thisHandle, fromUnit, area, errorHandler);
}

double RT_AreaUnit_convertTo(const RT_AreaUnitHandle thisHandle, const RT_AreaUnitHandle toUnit, double area, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_AreaUnit_convertTo_def)(const RT_AreaUnitHandle, const RT_AreaUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_AreaUnit_convertTo_func = reinterpret_cast<RT_AreaUnit_convertTo_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AreaUnit_convertTo")));
    
    return RT_AreaUnit_convertTo_func(thisHandle, toUnit, area, errorHandler);
}

double RT_AreaUnit_fromSquareMeters(const RT_AreaUnitHandle thisHandle, double area, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_AreaUnit_fromSquareMeters_def)(const RT_AreaUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_AreaUnit_fromSquareMeters_func = reinterpret_cast<RT_AreaUnit_fromSquareMeters_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AreaUnit_fromSquareMeters")));
    
    return RT_AreaUnit_fromSquareMeters_func(thisHandle, area, errorHandler);
}

double RT_AreaUnit_toSquareMeters(const RT_AreaUnitHandle thisHandle, double area, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_AreaUnit_toSquareMeters_def)(const RT_AreaUnitHandle, double, const RT_ErrorHandler*);
    static auto RT_AreaUnit_toSquareMeters_func = reinterpret_cast<RT_AreaUnit_toSquareMeters_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AreaUnit_toSquareMeters")));
    
    return RT_AreaUnit_toSquareMeters_func(thisHandle, area, errorHandler);
}
#endif