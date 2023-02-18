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
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthorizationCredential.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEOAuthAuthorizationCredential_destroy(RT_GEOAuthAuthorizationCredentialHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEOAuthAuthorizationCredential_destroy_def)(RT_GEOAuthAuthorizationCredentialHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthorizationCredential_destroy_func = reinterpret_cast<RT_GEOAuthAuthorizationCredential_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthorizationCredential_destroy")));
    
    RT_GEOAuthAuthorizationCredential_destroy_func(thisHandle, errorHandler);
}

RT_GEOAuthAuthorizationCredentialHandle RT_GEOAuthAuthorizationCredential_create(const char* accessToken, const RT_DateTimeHandle expirationDate, const char* refreshToken, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEOAuthAuthorizationCredentialHandle (*RT_GEOAuthAuthorizationCredential_create_def)(const char*, const RT_DateTimeHandle, const char*, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthorizationCredential_create_func = reinterpret_cast<RT_GEOAuthAuthorizationCredential_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthorizationCredential_create")));
    
    return RT_GEOAuthAuthorizationCredential_create_func(accessToken, expirationDate, refreshToken, errorHandler);
}

RT_StringHandle RT_GEOAuthAuthorizationCredential_getAccessToken(const RT_GEOAuthAuthorizationCredentialHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEOAuthAuthorizationCredential_getAccessToken_def)(const RT_GEOAuthAuthorizationCredentialHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthorizationCredential_getAccessToken_func = reinterpret_cast<RT_GEOAuthAuthorizationCredential_getAccessToken_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthorizationCredential_getAccessToken")));
    
    return RT_GEOAuthAuthorizationCredential_getAccessToken_func(thisHandle, errorHandler);
}

RT_DateTimeHandle RT_GEOAuthAuthorizationCredential_getExpirationDate(const RT_GEOAuthAuthorizationCredentialHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DateTimeHandle (*RT_GEOAuthAuthorizationCredential_getExpirationDate_def)(const RT_GEOAuthAuthorizationCredentialHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthorizationCredential_getExpirationDate_func = reinterpret_cast<RT_GEOAuthAuthorizationCredential_getExpirationDate_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthorizationCredential_getExpirationDate")));
    
    return RT_GEOAuthAuthorizationCredential_getExpirationDate_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEOAuthAuthorizationCredential_getRefreshToken(const RT_GEOAuthAuthorizationCredentialHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEOAuthAuthorizationCredential_getRefreshToken_def)(const RT_GEOAuthAuthorizationCredentialHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthorizationCredential_getRefreshToken_func = reinterpret_cast<RT_GEOAuthAuthorizationCredential_getRefreshToken_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthorizationCredential_getRefreshToken")));
    
    return RT_GEOAuthAuthorizationCredential_getRefreshToken_func(thisHandle, errorHandler);
}
#endif