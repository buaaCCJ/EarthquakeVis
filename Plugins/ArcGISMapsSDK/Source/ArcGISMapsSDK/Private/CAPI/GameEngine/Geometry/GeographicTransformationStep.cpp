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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeographicTransformationStep.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GeographicTransformationStep_destroy(RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeographicTransformationStep_destroy_def)(RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_destroy_func = reinterpret_cast<RT_GeographicTransformationStep_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_destroy")));
    
    RT_GeographicTransformationStep_destroy_func(thisHandle, errorHandler);
}

RT_GeographicTransformationStepHandle RT_GeographicTransformationStep_createWithWKID(int32_t WKID, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeographicTransformationStepHandle (*RT_GeographicTransformationStep_createWithWKID_def)(int32_t, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_createWithWKID_func = reinterpret_cast<RT_GeographicTransformationStep_createWithWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_createWithWKID")));
    
    return RT_GeographicTransformationStep_createWithWKID_func(WKID, errorHandler);
}

RT_GeographicTransformationStepHandle RT_GeographicTransformationStep_createWithWKText(const char* WKText, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeographicTransformationStepHandle (*RT_GeographicTransformationStep_createWithWKText_def)(const char*, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_createWithWKText_func = reinterpret_cast<RT_GeographicTransformationStep_createWithWKText_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_createWithWKText")));
    
    return RT_GeographicTransformationStep_createWithWKText_func(WKText, errorHandler);
}

bool RT_GeographicTransformationStep_getIsInverse(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeographicTransformationStep_getIsInverse_def)(const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_getIsInverse_func = reinterpret_cast<RT_GeographicTransformationStep_getIsInverse_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_getIsInverse")));
    
    return RT_GeographicTransformationStep_getIsInverse_func(thisHandle, errorHandler);
}

bool RT_GeographicTransformationStep_getIsMissingProjectionEngineFiles(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeographicTransformationStep_getIsMissingProjectionEngineFiles_def)(const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_getIsMissingProjectionEngineFiles_func = reinterpret_cast<RT_GeographicTransformationStep_getIsMissingProjectionEngineFiles_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_getIsMissingProjectionEngineFiles")));
    
    return RT_GeographicTransformationStep_getIsMissingProjectionEngineFiles_func(thisHandle, errorHandler);
}

RT_ArrayHandle RT_GeographicTransformationStep_getProjectionEngineFilenames(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeographicTransformationStep_getProjectionEngineFilenames_def)(const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_getProjectionEngineFilenames_func = reinterpret_cast<RT_GeographicTransformationStep_getProjectionEngineFilenames_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_getProjectionEngineFilenames")));
    
    return RT_GeographicTransformationStep_getProjectionEngineFilenames_func(thisHandle, errorHandler);
}

int32_t RT_GeographicTransformationStep_getWKID(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int32_t (*RT_GeographicTransformationStep_getWKID_def)(const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_getWKID_func = reinterpret_cast<RT_GeographicTransformationStep_getWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_getWKID")));
    
    return RT_GeographicTransformationStep_getWKID_func(thisHandle, errorHandler);
}

RT_StringHandle RT_GeographicTransformationStep_getWKText(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_GeographicTransformationStep_getWKText_def)(const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_getWKText_func = reinterpret_cast<RT_GeographicTransformationStep_getWKText_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_getWKText")));
    
    return RT_GeographicTransformationStep_getWKText_func(thisHandle, errorHandler);
}

bool RT_GeographicTransformationStep_equals(const RT_GeographicTransformationStepHandle thisHandle, const RT_GeographicTransformationStepHandle rightGeographicTransformationStep, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeographicTransformationStep_equals_def)(const RT_GeographicTransformationStepHandle, const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_equals_func = reinterpret_cast<RT_GeographicTransformationStep_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_equals")));
    
    return RT_GeographicTransformationStep_equals_func(thisHandle, rightGeographicTransformationStep, errorHandler);
}

size_t RT_GeographicTransformationStep_getHash(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GeographicTransformationStep_getHash_def)(const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_getHash_func = reinterpret_cast<RT_GeographicTransformationStep_getHash_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_getHash")));
    
    return RT_GeographicTransformationStep_getHash_func(thisHandle, errorHandler);
}

RT_GeographicTransformationStepHandle RT_GeographicTransformationStep_getInverse(const RT_GeographicTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeographicTransformationStepHandle (*RT_GeographicTransformationStep_getInverse_def)(const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformationStep_getInverse_func = reinterpret_cast<RT_GeographicTransformationStep_getInverse_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformationStep_getInverse")));
    
    return RT_GeographicTransformationStep_getInverse_func(thisHandle, errorHandler);
}
#endif