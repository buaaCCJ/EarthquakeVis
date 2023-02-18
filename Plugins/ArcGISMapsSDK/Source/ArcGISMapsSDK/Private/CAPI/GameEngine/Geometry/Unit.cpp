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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Unit.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Unit_destroy(RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Unit_destroy_def)(RT_UnitHandle, const RT_ErrorHandler*);
    static auto RT_Unit_destroy_func = reinterpret_cast<RT_Unit_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_destroy")));
    
    RT_Unit_destroy_func(thisHandle, errorHandler);
}

RT_StringHandle RT_Unit_getAbbreviation(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_Unit_getAbbreviation_def)(const RT_UnitHandle, const RT_ErrorHandler*);
    static auto RT_Unit_getAbbreviation_func = reinterpret_cast<RT_Unit_getAbbreviation_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_getAbbreviation")));
    
    return RT_Unit_getAbbreviation_func(thisHandle, errorHandler);
}

RT_StringHandle RT_Unit_getDisplayName(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_Unit_getDisplayName_def)(const RT_UnitHandle, const RT_ErrorHandler*);
    static auto RT_Unit_getDisplayName_func = reinterpret_cast<RT_Unit_getDisplayName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_getDisplayName")));
    
    return RT_Unit_getDisplayName_func(thisHandle, errorHandler);
}

RT_StringHandle RT_Unit_getName(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_Unit_getName_def)(const RT_UnitHandle, const RT_ErrorHandler*);
    static auto RT_Unit_getName_func = reinterpret_cast<RT_Unit_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_getName")));
    
    return RT_Unit_getName_func(thisHandle, errorHandler);
}

RT_UnitType RT_Unit_getObjectType(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_UnitType (*RT_Unit_getObjectType_def)(const RT_UnitHandle, const RT_ErrorHandler*);
    static auto RT_Unit_getObjectType_func = reinterpret_cast<RT_Unit_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_getObjectType")));
    
    return RT_Unit_getObjectType_func(thisHandle, errorHandler);
}

RT_StringHandle RT_Unit_getPluralDisplayName(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_Unit_getPluralDisplayName_def)(const RT_UnitHandle, const RT_ErrorHandler*);
    static auto RT_Unit_getPluralDisplayName_func = reinterpret_cast<RT_Unit_getPluralDisplayName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_getPluralDisplayName")));
    
    return RT_Unit_getPluralDisplayName_func(thisHandle, errorHandler);
}

int32_t RT_Unit_getUnitId(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int32_t (*RT_Unit_getUnitId_def)(const RT_UnitHandle, const RT_ErrorHandler*);
    static auto RT_Unit_getUnitId_func = reinterpret_cast<RT_Unit_getUnitId_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_getUnitId")));
    
    return RT_Unit_getUnitId_func(thisHandle, errorHandler);
}

int32_t RT_Unit_getWKID(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int32_t (*RT_Unit_getWKID_def)(const RT_UnitHandle, const RT_ErrorHandler*);
    static auto RT_Unit_getWKID_func = reinterpret_cast<RT_Unit_getWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_getWKID")));
    
    return RT_Unit_getWKID_func(thisHandle, errorHandler);
}

RT_UnitHandle RT_Unit_fromUnitId(int32_t unitId, const RT_ErrorHandler* errorHandler)
{
    typedef RT_UnitHandle (*RT_Unit_fromUnitId_def)(int32_t, const RT_ErrorHandler*);
    static auto RT_Unit_fromUnitId_func = reinterpret_cast<RT_Unit_fromUnitId_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_fromUnitId")));
    
    return RT_Unit_fromUnitId_func(unitId, errorHandler);
}

RT_UnitHandle RT_Unit_fromWKID(int32_t WKID, const RT_ErrorHandler* errorHandler)
{
    typedef RT_UnitHandle (*RT_Unit_fromWKID_def)(int32_t, const RT_ErrorHandler*);
    static auto RT_Unit_fromWKID_func = reinterpret_cast<RT_Unit_fromWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Unit_fromWKID")));
    
    return RT_Unit_fromWKID_func(WKID, errorHandler);
}
#endif