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
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthenticationChallenge.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEOAuthAuthenticationChallenge_destroy(RT_GEOAuthAuthenticationChallengeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEOAuthAuthenticationChallenge_destroy_def)(RT_GEOAuthAuthenticationChallengeHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationChallenge_destroy_func = reinterpret_cast<RT_GEOAuthAuthenticationChallenge_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationChallenge_destroy")));
    
    RT_GEOAuthAuthenticationChallenge_destroy_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GEOAuthAuthenticationChallenge_getAuthorizeURI(const RT_GEOAuthAuthenticationChallengeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GEOAuthAuthenticationChallenge_getAuthorizeURI_def)(const RT_GEOAuthAuthenticationChallengeHandle, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationChallenge_getAuthorizeURI_func = reinterpret_cast<RT_GEOAuthAuthenticationChallenge_getAuthorizeURI_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationChallenge_getAuthorizeURI")));
    
    return RT_GEOAuthAuthenticationChallenge_getAuthorizeURI_func(thisHandle, errorHandler);
}

void RT_GEOAuthAuthenticationChallenge_respond(RT_GEOAuthAuthenticationChallengeHandle thisHandle, const char* token, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEOAuthAuthenticationChallenge_respond_def)(RT_GEOAuthAuthenticationChallengeHandle, const char*, const RT_ErrorHandler*);
    static auto RT_GEOAuthAuthenticationChallenge_respond_func = reinterpret_cast<RT_GEOAuthAuthenticationChallenge_respond_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEOAuthAuthenticationChallenge_respond")));
    
    RT_GEOAuthAuthenticationChallenge_respond_func(thisHandle, token, errorHandler);
}
#endif