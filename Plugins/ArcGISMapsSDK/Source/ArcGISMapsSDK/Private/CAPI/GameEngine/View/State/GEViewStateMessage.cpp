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
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateMessage.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEViewStateMessage_destroy(RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEViewStateMessage_destroy_def)(RT_GEViewStateMessageHandle, const RT_ErrorHandler*);
    static auto RT_GEViewStateMessage_destroy_func = reinterpret_cast<RT_GEViewStateMessage_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEViewStateMessage_destroy")));
    
    RT_GEViewStateMessage_destroy_func(thisHandle, errorHandler);
}

RT_DictionaryHandle RT_GEViewStateMessage_getAdditionalInformation(const RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DictionaryHandle (*RT_GEViewStateMessage_getAdditionalInformation_def)(const RT_GEViewStateMessageHandle, const RT_ErrorHandler*);
    static auto RT_GEViewStateMessage_getAdditionalInformation_func = reinterpret_cast<RT_GEViewStateMessage_getAdditionalInformation_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEViewStateMessage_getAdditionalInformation")));
    
    return RT_GEViewStateMessage_getAdditionalInformation_func(thisHandle, errorHandler);
}

uint32_t RT_GEViewStateMessage_getCode(const RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef uint32_t (*RT_GEViewStateMessage_getCode_def)(const RT_GEViewStateMessageHandle, const RT_ErrorHandler*);
    static auto RT_GEViewStateMessage_getCode_func = reinterpret_cast<RT_GEViewStateMessage_getCode_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEViewStateMessage_getCode")));
    
    return RT_GEViewStateMessage_getCode_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEViewStateMessage_getMessage(const RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEViewStateMessage_getMessage_def)(const RT_GEViewStateMessageHandle, const RT_ErrorHandler*);
    static auto RT_GEViewStateMessage_getMessage_func = reinterpret_cast<RT_GEViewStateMessage_getMessage_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEViewStateMessage_getMessage")));
    
    return RT_GEViewStateMessage_getMessage_func(thisHandle, errorHandler);
}

RT_GEViewStateMessageType RT_GEViewStateMessage_getMessageType(const RT_GEViewStateMessageHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEViewStateMessageType (*RT_GEViewStateMessage_getMessageType_def)(const RT_GEViewStateMessageHandle, const RT_ErrorHandler*);
    static auto RT_GEViewStateMessage_getMessageType_func = reinterpret_cast<RT_GEViewStateMessage_getMessageType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEViewStateMessage_getMessageType")));
    
    return RT_GEViewStateMessage_getMessageType_func(thisHandle, errorHandler);
}
#endif