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
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

void RT_String_destroy(RT_StringHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_String_destroy_def)(RT_StringHandle, const RT_ErrorHandler*);
    static auto RT_String_destroy_func = reinterpret_cast<RT_String_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_String_destroy")));
    
    RT_String_destroy_func(thisHandle, errorHandler);
}

RT_StringHandle RT_String_create(const char* string, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_String_create_def)(const char*, const RT_ErrorHandler*);
    static auto RT_String_create_func = reinterpret_cast<RT_String_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_String_create")));
    
    return RT_String_create_func(string, errorHandler);
}

size_t RT_String_getSize(const RT_StringHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_String_getSize_def)(const RT_StringHandle, const RT_ErrorHandler*);
    static auto RT_String_getSize_func = reinterpret_cast<RT_String_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_String_getSize")));
    
    return RT_String_getSize_func(thisHandle, errorHandler);
}

char* RT_String_cStr(const RT_StringHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef char* (*RT_String_cStr_def)(const RT_StringHandle, const RT_ErrorHandler*);
    static auto RT_String_cStr_func = reinterpret_cast<RT_String_cStr_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_String_cStr")));
    
    return RT_String_cStr_func(thisHandle, errorHandler);
}

RT_ByteArray RT_String_getByteArray(const RT_StringHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ByteArray (*RT_String_getByteArray_def)(const RT_StringHandle, const RT_ErrorHandler*);
    static auto RT_String_getByteArray_func = reinterpret_cast<RT_String_getByteArray_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_String_getByteArray")));
    
    return RT_String_getByteArray_func(thisHandle, errorHandler);
}
#endif