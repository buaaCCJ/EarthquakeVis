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
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthenticationConfiguration.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEOAuthAuthenticationConfiguration_destroy(RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEOAuthAuthenticationConfiguration_destroy_def)(RT_GEOAuthAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationConfiguration_destroy_func = reinterpret_cast<RT_GEOAuthAuthenticationConfiguration_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationConfiguration_destroy")));
    
    RT_GEOAuthAuthenticationConfiguration_destroy_func(thisHandle, errorHandler);
}

RT_GEOAuthAuthenticationConfigurationHandle RT_GEOAuthAuthenticationConfiguration_create(const char* clientId, const char* clientSecret, const char* redirectURI, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEOAuthAuthenticationConfigurationHandle (*RT_GEOAuthAuthenticationConfiguration_create_def)(const char*, const char*, const char*, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationConfiguration_create_func = reinterpret_cast<RT_GEOAuthAuthenticationConfiguration_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationConfiguration_create")));
    
    return RT_GEOAuthAuthenticationConfiguration_create_func(clientId, clientSecret, redirectURI, errorHandler);
}

RT_GEOAuthAuthenticationConfigurationHandle RT_GEOAuthAuthenticationConfiguration_createWithCredential(const char* clientId, const char* clientSecret, const char* redirectURI, const RT_GEOAuthAuthorizationCredentialHandle authenticationCredential, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEOAuthAuthenticationConfigurationHandle (*RT_GEOAuthAuthenticationConfiguration_createWithCredential_def)(const char*, const char*, const char*, const RT_GEOAuthAuthorizationCredentialHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationConfiguration_createWithCredential_func = reinterpret_cast<RT_GEOAuthAuthenticationConfiguration_createWithCredential_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationConfiguration_createWithCredential")));
    
    return RT_GEOAuthAuthenticationConfiguration_createWithCredential_func(clientId, clientSecret, redirectURI, authenticationCredential, errorHandler);
}

RT_GEOAuthAuthorizationCredentialHandle RT_GEOAuthAuthenticationConfiguration_getAuthorizationCredential(const RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEOAuthAuthorizationCredentialHandle (*RT_GEOAuthAuthenticationConfiguration_getAuthorizationCredential_def)(const RT_GEOAuthAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationConfiguration_getAuthorizationCredential_func = reinterpret_cast<RT_GEOAuthAuthenticationConfiguration_getAuthorizationCredential_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationConfiguration_getAuthorizationCredential")));
    
    return RT_GEOAuthAuthenticationConfiguration_getAuthorizationCredential_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEOAuthAuthenticationConfiguration_getClientId(const RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEOAuthAuthenticationConfiguration_getClientId_def)(const RT_GEOAuthAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationConfiguration_getClientId_func = reinterpret_cast<RT_GEOAuthAuthenticationConfiguration_getClientId_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationConfiguration_getClientId")));
    
    return RT_GEOAuthAuthenticationConfiguration_getClientId_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEOAuthAuthenticationConfiguration_getClientSecret(const RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEOAuthAuthenticationConfiguration_getClientSecret_def)(const RT_GEOAuthAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationConfiguration_getClientSecret_func = reinterpret_cast<RT_GEOAuthAuthenticationConfiguration_getClientSecret_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationConfiguration_getClientSecret")));
    
    return RT_GEOAuthAuthenticationConfiguration_getClientSecret_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEOAuthAuthenticationConfiguration_getRedirectURI(const RT_GEOAuthAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEOAuthAuthenticationConfiguration_getRedirectURI_def)(const RT_GEOAuthAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationConfiguration_getRedirectURI_func = reinterpret_cast<RT_GEOAuthAuthenticationConfiguration_getRedirectURI_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationConfiguration_getRedirectURI")));
    
    return RT_GEOAuthAuthenticationConfiguration_getRedirectURI_func(thisHandle, errorHandler);
}

void RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback(RT_GEOAuthAuthenticationConfigurationHandle thisHandle, RT_GEOAuthAuthorizationCredential_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback_def)(RT_GEOAuthAuthenticationConfigurationHandle, RT_GEOAuthAuthorizationCredential_issued_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback_func = reinterpret_cast<RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback")));
    
    RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif