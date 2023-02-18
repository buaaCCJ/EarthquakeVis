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
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationManager.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

RT_DictionaryHandle RT_GEAuthenticationManager_getAuthenticationConfigurations(const RT_ErrorHandler* errorHandler)
{
    typedef RT_DictionaryHandle (*RT_GEAuthenticationManager_getAuthenticationConfigurations_def)(const RT_ErrorHandler*);
    static auto RT_GEAuthenticationManager_getAuthenticationConfigurations_func = reinterpret_cast<RT_GEAuthenticationManager_getAuthenticationConfigurations_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEAuthenticationManager_getAuthenticationConfigurations")));
    
    return RT_GEAuthenticationManager_getAuthenticationConfigurations_func(errorHandler);
}

RT_TaskHandle RT_GEAuthenticationManager_authorizeAuthenticationConfigurationAsync(const char* restEndpointURL, const RT_GEAuthenticationConfigurationHandle authenticationConfiguration, const RT_ErrorHandler* errorHandler)
{
    typedef RT_TaskHandle (*RT_GEAuthenticationManager_authorizeAuthenticationConfigurationAsync_def)(const char*, const RT_GEAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_GEAuthenticationManager_authorizeAuthenticationConfigurationAsync_func = reinterpret_cast<RT_GEAuthenticationManager_authorizeAuthenticationConfigurationAsync_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEAuthenticationManager_authorizeAuthenticationConfigurationAsync")));
    
    return RT_GEAuthenticationManager_authorizeAuthenticationConfigurationAsync_func(restEndpointURL, authenticationConfiguration, errorHandler);
}

void RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback(RT_GEAuthenticationChallenge_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback_def)(RT_GEAuthenticationChallenge_issued_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback_func = reinterpret_cast<RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback")));
    
    RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback_func(callback, userData, errorHandler);
}
#endif