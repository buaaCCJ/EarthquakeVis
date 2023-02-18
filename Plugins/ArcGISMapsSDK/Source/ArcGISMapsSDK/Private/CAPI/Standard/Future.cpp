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
#include "ArcGISMapsSDK/CAPI/Standard/Future.h"

void RT_Task_destroy(RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Task_destroy_def)(RT_TaskHandle, const RT_ErrorHandler*);
    static auto RT_Task_destroy_func = reinterpret_cast<RT_Task_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Task_destroy")));
    
    RT_Task_destroy_func(thisHandle, errorHandler);
}

bool RT_Task_cancel(RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Task_cancel_def)(RT_TaskHandle, const RT_ErrorHandler*);
    static auto RT_Task_cancel_func = reinterpret_cast<RT_Task_cancel_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Task_cancel")));
    
    return RT_Task_cancel_func(thisHandle, errorHandler);
}

RT_ElementHandle RT_Task_get(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Task_get_def)(const RT_TaskHandle, const RT_ErrorHandler*);
    static auto RT_Task_get_func = reinterpret_cast<RT_Task_get_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Task_get")));
    
    return RT_Task_get_func(thisHandle, errorHandler);
}

RT_ErrorHandle RT_Task_getError(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ErrorHandle (*RT_Task_getError_def)(const RT_TaskHandle, const RT_ErrorHandler*);
    static auto RT_Task_getError_func = reinterpret_cast<RT_Task_getError_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Task_getError")));
    
    return RT_Task_getError_func(thisHandle, errorHandler);
}

bool RT_Task_isCanceled(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Task_isCanceled_def)(const RT_TaskHandle, const RT_ErrorHandler*);
    static auto RT_Task_isCanceled_func = reinterpret_cast<RT_Task_isCanceled_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Task_isCanceled")));
    
    return RT_Task_isCanceled_func(thisHandle, errorHandler);
}

bool RT_Task_isDone(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Task_isDone_def)(const RT_TaskHandle, const RT_ErrorHandler*);
    static auto RT_Task_isDone_func = reinterpret_cast<RT_Task_isDone_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Task_isDone")));
    
    return RT_Task_isDone_func(thisHandle, errorHandler);
}

RT_TaskStatus RT_Task_wait(const RT_TaskHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_TaskStatus (*RT_Task_wait_def)(const RT_TaskHandle, const RT_ErrorHandler*);
    static auto RT_Task_wait_func = reinterpret_cast<RT_Task_wait_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Task_wait")));
    
    return RT_Task_wait_func(thisHandle, errorHandler);
}

void RT_Task_setTaskCompletedCallback(RT_TaskHandle thisHandle, RT_TaskCompletedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Task_setTaskCompletedCallback_def)(RT_TaskHandle, RT_TaskCompletedEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_Task_setTaskCompletedCallback_func = reinterpret_cast<RT_Task_setTaskCompletedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Task_setTaskCompletedCallback")));
    
    RT_Task_setTaskCompletedCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif