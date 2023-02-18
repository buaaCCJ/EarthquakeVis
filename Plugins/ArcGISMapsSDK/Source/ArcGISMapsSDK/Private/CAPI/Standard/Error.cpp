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
#include "ArcGISMapsSDK/CAPI/Standard/Error.h"

void RT_Error_destroy(RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Error_destroy_def)(RT_ErrorHandle, const RT_ErrorHandler*);
    static auto RT_Error_destroy_func = reinterpret_cast<RT_Error_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Error_destroy")));
    
    RT_Error_destroy_func(thisHandle, errorHandler);
}

RT_StringHandle RT_Error_getAdditionalMessage(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_Error_getAdditionalMessage_def)(const RT_ErrorHandle, const RT_ErrorHandler*);
    static auto RT_Error_getAdditionalMessage_func = reinterpret_cast<RT_Error_getAdditionalMessage_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Error_getAdditionalMessage")));
    
    return RT_Error_getAdditionalMessage_func(thisHandle, errorHandler);
}

int32_t RT_Error_getCode(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int32_t (*RT_Error_getCode_def)(const RT_ErrorHandle, const RT_ErrorHandler*);
    static auto RT_Error_getCode_func = reinterpret_cast<RT_Error_getCode_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Error_getCode")));
    
    return RT_Error_getCode_func(thisHandle, errorHandler);
}

RT_StringHandle RT_Error_getMessage(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_Error_getMessage_def)(const RT_ErrorHandle, const RT_ErrorHandler*);
    static auto RT_Error_getMessage_func = reinterpret_cast<RT_Error_getMessage_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Error_getMessage")));
    
    return RT_Error_getMessage_func(thisHandle, errorHandler);
}

void* RT_Error_getUserDefinedFailure(const RT_ErrorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void* (*RT_Error_getUserDefinedFailure_def)(const RT_ErrorHandle, const RT_ErrorHandler*);
    static auto RT_Error_getUserDefinedFailure_func = reinterpret_cast<RT_Error_getUserDefinedFailure_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Error_getUserDefinedFailure")));
    
    return RT_Error_getUserDefinedFailure_func(thisHandle, errorHandler);
}
#endif