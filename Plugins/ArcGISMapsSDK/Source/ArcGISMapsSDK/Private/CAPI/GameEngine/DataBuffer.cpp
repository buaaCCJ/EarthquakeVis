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
#include "ArcGISMapsSDK/CAPI/GameEngine/DataBuffer.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_DataBuffer_destroy(RT_DataBufferHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_DataBuffer_destroy_def)(RT_DataBufferHandle, const RT_ErrorHandler*);
    static auto RT_DataBuffer_destroy_func = reinterpret_cast<RT_DataBuffer_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DataBuffer_destroy")));
    
    RT_DataBuffer_destroy_func(thisHandle, errorHandler);
}

void* RT_DataBuffer_getData(const RT_DataBufferHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void* (*RT_DataBuffer_getData_def)(const RT_DataBufferHandle, const RT_ErrorHandler*);
    static auto RT_DataBuffer_getData_func = reinterpret_cast<RT_DataBuffer_getData_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DataBuffer_getData")));
    
    return RT_DataBuffer_getData_func(thisHandle, errorHandler);
}

size_t RT_DataBuffer_getItemSize(const RT_DataBufferHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_DataBuffer_getItemSize_def)(const RT_DataBufferHandle, const RT_ErrorHandler*);
    static auto RT_DataBuffer_getItemSize_func = reinterpret_cast<RT_DataBuffer_getItemSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DataBuffer_getItemSize")));
    
    return RT_DataBuffer_getItemSize_func(thisHandle, errorHandler);
}

size_t RT_DataBuffer_getSizeBytes(const RT_DataBufferHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_DataBuffer_getSizeBytes_def)(const RT_DataBufferHandle, const RT_ErrorHandler*);
    static auto RT_DataBuffer_getSizeBytes_func = reinterpret_cast<RT_DataBuffer_getSizeBytes_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DataBuffer_getSizeBytes")));
    
    return RT_DataBuffer_getSizeBytes_func(thisHandle, errorHandler);
}
#endif