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
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationChallenge.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEAuthenticationChallenge_destroy(RT_GEAuthenticationChallengeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEAuthenticationChallenge_destroy_def)(RT_GEAuthenticationChallengeHandle, const RT_ErrorHandler*);
    static auto RT_GEAuthenticationChallenge_destroy_func = reinterpret_cast<RT_GEAuthenticationChallenge_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEAuthenticationChallenge_destroy")));
    
    RT_GEAuthenticationChallenge_destroy_func(thisHandle, errorHandler);
}

RT_GEAuthenticationChallengeType RT_GEAuthenticationChallenge_getObjectType(const RT_GEAuthenticationChallengeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEAuthenticationChallengeType (*RT_GEAuthenticationChallenge_getObjectType_def)(const RT_GEAuthenticationChallengeHandle, const RT_ErrorHandler*);
    static auto RT_GEAuthenticationChallenge_getObjectType_func = reinterpret_cast<RT_GEAuthenticationChallenge_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEAuthenticationChallenge_getObjectType")));
    
    return RT_GEAuthenticationChallenge_getObjectType_func(thisHandle, errorHandler);
}

void RT_GEAuthenticationChallenge_cancel(RT_GEAuthenticationChallengeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEAuthenticationChallenge_cancel_def)(RT_GEAuthenticationChallengeHandle, const RT_ErrorHandler*);
    static auto RT_GEAuthenticationChallenge_cancel_func = reinterpret_cast<RT_GEAuthenticationChallenge_cancel_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEAuthenticationChallenge_cancel")));
    
    RT_GEAuthenticationChallenge_cancel_func(thisHandle, errorHandler);
}
#endif