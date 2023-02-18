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
#include "ArcGISMapsSDK/CAPI/GameEngine/ArcGISRuntimeEnvironment.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

RT_StringHandle RT_ArcGISRuntimeEnvironment_getAPIKey(const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_ArcGISRuntimeEnvironment_getAPIKey_def)(const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_getAPIKey_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_getAPIKey_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_getAPIKey")));
    
    return RT_ArcGISRuntimeEnvironment_getAPIKey_func(errorHandler);
}
void RT_ArcGISRuntimeEnvironment_setAPIKey(char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setAPIKey_def)(char*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setAPIKey_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setAPIKey_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setAPIKey")));
    
    RT_ArcGISRuntimeEnvironment_setAPIKey_func(APIKey, errorHandler);
}

bool RT_ArcGISRuntimeEnvironment_getUseCoreAuthentication(const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_ArcGISRuntimeEnvironment_getUseCoreAuthentication_def)(const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_getUseCoreAuthentication_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_getUseCoreAuthentication_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_getUseCoreAuthentication")));
    
    return RT_ArcGISRuntimeEnvironment_getUseCoreAuthentication_func(errorHandler);
}
void RT_ArcGISRuntimeEnvironment_setUseCoreAuthentication(bool useCoreAuthentication, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setUseCoreAuthentication_def)(bool, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setUseCoreAuthentication_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setUseCoreAuthentication_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setUseCoreAuthentication")));
    
    RT_ArcGISRuntimeEnvironment_setUseCoreAuthentication_func(useCoreAuthentication, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_enableBreakOnException(bool enable, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_enableBreakOnException_def)(bool, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_enableBreakOnException_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_enableBreakOnException_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_enableBreakOnException")));
    
    RT_ArcGISRuntimeEnvironment_enableBreakOnException_func(enable, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_enableLeakDetection(bool enable, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_enableLeakDetection_def)(bool, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_enableLeakDetection_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_enableLeakDetection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_enableLeakDetection")));
    
    RT_ArcGISRuntimeEnvironment_enableLeakDetection_func(enable, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_enableRaiseAssertion(bool enable, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_enableRaiseAssertion_def)(bool, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_enableRaiseAssertion_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_enableRaiseAssertion_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_enableRaiseAssertion")));
    
    RT_ArcGISRuntimeEnvironment_enableRaiseAssertion_func(enable, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_enableShowAssertDialog(bool enable, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_enableShowAssertDialog_def)(bool, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_enableShowAssertDialog_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_enableShowAssertDialog_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_enableShowAssertDialog")));
    
    RT_ArcGISRuntimeEnvironment_enableShowAssertDialog_func(enable, errorHandler);
}

RT_StringHandle RT_ArcGISRuntimeEnvironment_getFeatureToggleDirectory(const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_ArcGISRuntimeEnvironment_getFeatureToggleDirectory_def)(const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_getFeatureToggleDirectory_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_getFeatureToggleDirectory_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_getFeatureToggleDirectory")));
    
    return RT_ArcGISRuntimeEnvironment_getFeatureToggleDirectory_func(errorHandler);
}

bool RT_ArcGISRuntimeEnvironment_isFeatureEnabled(const char* featureToggle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_ArcGISRuntimeEnvironment_isFeatureEnabled_def)(const char*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_isFeatureEnabled_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_isFeatureEnabled_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_isFeatureEnabled")));
    
    return RT_ArcGISRuntimeEnvironment_isFeatureEnabled_func(featureToggle, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_setBetaWatermark(bool set, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setBetaWatermark_def)(bool, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setBetaWatermark_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setBetaWatermark_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setBetaWatermark")));
    
    RT_ArcGISRuntimeEnvironment_setBetaWatermark_func(set, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_setFeatureToggleDirectory(const char* featureToggleDirectory, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setFeatureToggleDirectory_def)(const char*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setFeatureToggleDirectory_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setFeatureToggleDirectory_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setFeatureToggleDirectory")));
    
    RT_ArcGISRuntimeEnvironment_setFeatureToggleDirectory_func(featureToggleDirectory, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_setInstallDirectory(const char* installPath, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setInstallDirectory_def)(const char*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setInstallDirectory_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setInstallDirectory_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setInstallDirectory")));
    
    RT_ArcGISRuntimeEnvironment_setInstallDirectory_func(installPath, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_setProductInfo(const char* name, const char* version, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setProductInfo_def)(const char*, const char*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setProductInfo_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setProductInfo_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setProductInfo")));
    
    RT_ArcGISRuntimeEnvironment_setProductInfo_func(name, version, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_setResourcesDirectory(const char* resourcesPath, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setResourcesDirectory_def)(const char*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setResourcesDirectory_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setResourcesDirectory_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setResourcesDirectory")));
    
    RT_ArcGISRuntimeEnvironment_setResourcesDirectory_func(resourcesPath, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_setRuntimeClient(RT_RuntimeClient runtimeClient, const char* version, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setRuntimeClient_def)(RT_RuntimeClient, const char*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setRuntimeClient_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setRuntimeClient_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setRuntimeClient")));
    
    RT_ArcGISRuntimeEnvironment_setRuntimeClient_func(runtimeClient, version, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_setTempDirectory(const char* tempPath, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setTempDirectory_def)(const char*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setTempDirectory_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setTempDirectory_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setTempDirectory")));
    
    RT_ArcGISRuntimeEnvironment_setTempDirectory_func(tempPath, errorHandler);
}

void RT_ArcGISRuntimeEnvironment_setErrorCallback(RT_ArcGISRuntimeEnvironmentErrorEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArcGISRuntimeEnvironment_setErrorCallback_def)(RT_ArcGISRuntimeEnvironmentErrorEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_ArcGISRuntimeEnvironment_setErrorCallback_func = reinterpret_cast<RT_ArcGISRuntimeEnvironment_setErrorCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArcGISRuntimeEnvironment_setErrorCallback")));
    
    RT_ArcGISRuntimeEnvironment_setErrorCallback_func(callback, userData, errorHandler);
}
#endif