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
#include "ArcGISMapsSDK/CAPI/Platform.h"
#include "ArcGISMapsSDK/CAPI/Standard/DateTime.h"

void RT_DateTime_destroy(RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_DateTime_destroy_def)(RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_destroy_func = reinterpret_cast<RT_DateTime_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_destroy")));
    
    RT_DateTime_destroy_func(thisHandle, errorHandler);
}

RT_DateTimeHandle RT_DateTime_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_DateTime_create_def)(const RT_ErrorHandler*);
    static auto RT_DateTime_create_func = reinterpret_cast<RT_DateTime_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_create")));
    
    return RT_DateTime_create_func(errorHandler);
}

bool RT_DateTime_add(RT_DateTimeHandle thisHandle, int64_t milliseconds, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DateTime_add_def)(RT_DateTimeHandle, int64_t, const RT_ErrorHandler*);
    static auto RT_DateTime_add_func = reinterpret_cast<RT_DateTime_add_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_add")));
    
    return RT_DateTime_add_func(thisHandle, milliseconds, errorHandler);
}

bool RT_DateTime_equals(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DateTime_equals_def)(const RT_DateTimeHandle, const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_equals_func = reinterpret_cast<RT_DateTime_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_equals")));
    
    return RT_DateTime_equals_func(thisHandle, right, errorHandler);
}

RT_DateTimeHandle RT_DateTime_fromFileTime(int64_t time, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_DateTime_fromFileTime_def)(int64_t, const RT_ErrorHandler*);
    static auto RT_DateTime_fromFileTime_func = reinterpret_cast<RT_DateTime_fromFileTime_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_fromFileTime")));
    
    return RT_DateTime_fromFileTime_func(time, errorHandler);
}

RT_DateTimeHandle RT_DateTime_fromOLE(double time, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_DateTime_fromOLE_def)(double, const RT_ErrorHandler*);
    static auto RT_DateTime_fromOLE_func = reinterpret_cast<RT_DateTime_fromOLE_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_fromOLE")));
    
    return RT_DateTime_fromOLE_func(time, errorHandler);
}

RT_DateTimeHandle RT_DateTime_fromString(const char* time, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_DateTime_fromString_def)(const char*, const RT_ErrorHandler*);
    static auto RT_DateTime_fromString_func = reinterpret_cast<RT_DateTime_fromString_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_fromString")));
    
    return RT_DateTime_fromString_func(time, errorHandler);
}

RT_DateTimeHandle RT_DateTime_fromUnixMilliseconds(int64_t time, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_DateTime_fromUnixMilliseconds_def)(int64_t, const RT_ErrorHandler*);
    static auto RT_DateTime_fromUnixMilliseconds_func = reinterpret_cast<RT_DateTime_fromUnixMilliseconds_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_fromUnixMilliseconds")));
    
    return RT_DateTime_fromUnixMilliseconds_func(time, errorHandler);
}

bool RT_DateTime_greaterThan(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DateTime_greaterThan_def)(const RT_DateTimeHandle, const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_greaterThan_func = reinterpret_cast<RT_DateTime_greaterThan_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_greaterThan")));
    
    return RT_DateTime_greaterThan_func(thisHandle, right, errorHandler);
}

bool RT_DateTime_greaterThanOrEqual(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DateTime_greaterThanOrEqual_def)(const RT_DateTimeHandle, const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_greaterThanOrEqual_func = reinterpret_cast<RT_DateTime_greaterThanOrEqual_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_greaterThanOrEqual")));
    
    return RT_DateTime_greaterThanOrEqual_func(thisHandle, right, errorHandler);
}

bool RT_DateTime_lessThan(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DateTime_lessThan_def)(const RT_DateTimeHandle, const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_lessThan_func = reinterpret_cast<RT_DateTime_lessThan_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_lessThan")));
    
    return RT_DateTime_lessThan_func(thisHandle, right, errorHandler);
}

bool RT_DateTime_lessThanOrEqual(const RT_DateTimeHandle thisHandle, const RT_DateTimeHandle right, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DateTime_lessThanOrEqual_def)(const RT_DateTimeHandle, const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_lessThanOrEqual_func = reinterpret_cast<RT_DateTime_lessThanOrEqual_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_lessThanOrEqual")));
    
    return RT_DateTime_lessThanOrEqual_func(thisHandle, right, errorHandler);
}

RT_DateTimeHandle RT_DateTime_max(const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_DateTime_max_def)(const RT_ErrorHandler*);
    static auto RT_DateTime_max_func = reinterpret_cast<RT_DateTime_max_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_max")));
    
    return RT_DateTime_max_func(errorHandler);
}

RT_DateTimeHandle RT_DateTime_min(const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_DateTime_min_def)(const RT_ErrorHandler*);
    static auto RT_DateTime_min_func = reinterpret_cast<RT_DateTime_min_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_min")));
    
    return RT_DateTime_min_func(errorHandler);
}

RT_DateTimeHandle RT_DateTime_now(const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_DateTime_now_def)(const RT_ErrorHandler*);
    static auto RT_DateTime_now_func = reinterpret_cast<RT_DateTime_now_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_now")));
    
    return RT_DateTime_now_func(errorHandler);
}

bool RT_DateTime_subtract(RT_DateTimeHandle thisHandle, int64_t milliseconds, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DateTime_subtract_def)(RT_DateTimeHandle, int64_t, const RT_ErrorHandler*);
    static auto RT_DateTime_subtract_func = reinterpret_cast<RT_DateTime_subtract_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_subtract")));
    
    return RT_DateTime_subtract_func(thisHandle, milliseconds, errorHandler);
}

int64_t RT_DateTime_toFileTime(const RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int64_t (*RT_DateTime_toFileTime_def)(const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_toFileTime_func = reinterpret_cast<RT_DateTime_toFileTime_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_toFileTime")));
    
    return RT_DateTime_toFileTime_func(thisHandle, errorHandler);
}

double RT_DateTime_toOLE(const RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_DateTime_toOLE_def)(const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_toOLE_func = reinterpret_cast<RT_DateTime_toOLE_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_toOLE")));
    
    return RT_DateTime_toOLE_func(thisHandle, errorHandler);
}

RT_StringHandle RT_DateTime_toString(const RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_DateTime_toString_def)(const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_toString_func = reinterpret_cast<RT_DateTime_toString_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_toString")));
    
    return RT_DateTime_toString_func(thisHandle, errorHandler);
}

int64_t RT_DateTime_toUnixMilliseconds(const RT_DateTimeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int64_t (*RT_DateTime_toUnixMilliseconds_def)(const RT_DateTimeHandle, const RT_ErrorHandler*);
    static auto RT_DateTime_toUnixMilliseconds_func = reinterpret_cast<RT_DateTime_toUnixMilliseconds_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DateTime_toUnixMilliseconds")));
    
    return RT_DateTime_toUnixMilliseconds_func(thisHandle, errorHandler);
}
#endif