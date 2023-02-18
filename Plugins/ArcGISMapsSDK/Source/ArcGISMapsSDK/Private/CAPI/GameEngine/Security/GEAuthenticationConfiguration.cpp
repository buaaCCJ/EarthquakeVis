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
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationConfiguration.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEAuthenticationConfiguration_destroy(RT_GEAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEAuthenticationConfiguration_destroy_def)(RT_GEAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_GEAuthenticationConfiguration_destroy_func = reinterpret_cast<RT_GEAuthenticationConfiguration_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEAuthenticationConfiguration_destroy")));
    
    RT_GEAuthenticationConfiguration_destroy_func(thisHandle, errorHandler);
}

RT_GEAuthenticationConfigurationType RT_GEAuthenticationConfiguration_getObjectType(const RT_GEAuthenticationConfigurationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEAuthenticationConfigurationType (*RT_GEAuthenticationConfiguration_getObjectType_def)(const RT_GEAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_GEAuthenticationConfiguration_getObjectType_func = reinterpret_cast<RT_GEAuthenticationConfiguration_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEAuthenticationConfiguration_getObjectType")));
    
    return RT_GEAuthenticationConfiguration_getObjectType_func(thisHandle, errorHandler);
}
#endif