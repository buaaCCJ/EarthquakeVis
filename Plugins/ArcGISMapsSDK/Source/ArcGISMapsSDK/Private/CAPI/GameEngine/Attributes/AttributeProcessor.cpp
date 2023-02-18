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
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/AttributeProcessor.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_AttributeProcessor_destroy(RT_AttributeProcessorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_AttributeProcessor_destroy_def)(RT_AttributeProcessorHandle, const RT_ErrorHandler*);
    static auto RT_AttributeProcessor_destroy_func = reinterpret_cast<RT_AttributeProcessor_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AttributeProcessor_destroy")));
    
    RT_AttributeProcessor_destroy_func(thisHandle, errorHandler);
}

RT_AttributeProcessorHandle RT_AttributeProcessor_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_AttributeProcessorHandle (*RT_AttributeProcessor_create_def)(const RT_ErrorHandler*);
    static auto RT_AttributeProcessor_create_func = reinterpret_cast<RT_AttributeProcessor_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AttributeProcessor_create")));
    
    return RT_AttributeProcessor_create_func(errorHandler);
}

void RT_AttributeProcessor_setProcessEventCallback(RT_AttributeProcessorHandle thisHandle, RT_Attribute_processor_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_AttributeProcessor_setProcessEventCallback_def)(RT_AttributeProcessorHandle, RT_Attribute_processor_fn, void*, const RT_ErrorHandler*);
    static auto RT_AttributeProcessor_setProcessEventCallback_func = reinterpret_cast<RT_AttributeProcessor_setProcessEventCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_AttributeProcessor_setProcessEventCallback")));
    
    RT_AttributeProcessor_setProcessEventCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif