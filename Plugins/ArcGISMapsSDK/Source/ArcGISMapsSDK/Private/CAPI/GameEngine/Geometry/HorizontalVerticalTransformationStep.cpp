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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/HorizontalVerticalTransformationStep.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_HorizontalVerticalTransformationStep_destroy(RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_HorizontalVerticalTransformationStep_destroy_def)(RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_destroy_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_destroy")));
    
    RT_HorizontalVerticalTransformationStep_destroy_func(thisHandle, errorHandler);
}

RT_HorizontalVerticalTransformationStepHandle RT_HorizontalVerticalTransformationStep_createWithWKID(int32_t WKID, const RT_ErrorHandler* errorHandler)
{
    typedef RT_HorizontalVerticalTransformationStepHandle (*RT_HorizontalVerticalTransformationStep_createWithWKID_def)(int32_t, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_createWithWKID_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_createWithWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_createWithWKID")));
    
    return RT_HorizontalVerticalTransformationStep_createWithWKID_func(WKID, errorHandler);
}

RT_HorizontalVerticalTransformationStepHandle RT_HorizontalVerticalTransformationStep_createWithWKText(const char* WKText, const RT_ErrorHandler* errorHandler)
{
    typedef RT_HorizontalVerticalTransformationStepHandle (*RT_HorizontalVerticalTransformationStep_createWithWKText_def)(const char*, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_createWithWKText_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_createWithWKText_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_createWithWKText")));
    
    return RT_HorizontalVerticalTransformationStep_createWithWKText_func(WKText, errorHandler);
}

bool RT_HorizontalVerticalTransformationStep_getIsInverse(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_HorizontalVerticalTransformationStep_getIsInverse_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_getIsInverse_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_getIsInverse_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_getIsInverse")));
    
    return RT_HorizontalVerticalTransformationStep_getIsInverse_func(thisHandle, errorHandler);
}

bool RT_HorizontalVerticalTransformationStep_getIsMissingProjectionEngineFiles(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_HorizontalVerticalTransformationStep_getIsMissingProjectionEngineFiles_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_getIsMissingProjectionEngineFiles_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_getIsMissingProjectionEngineFiles_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_getIsMissingProjectionEngineFiles")));
    
    return RT_HorizontalVerticalTransformationStep_getIsMissingProjectionEngineFiles_func(thisHandle, errorHandler);
}

RT_ArrayHandle RT_HorizontalVerticalTransformationStep_getProjectionEngineFilenames(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_HorizontalVerticalTransformationStep_getProjectionEngineFilenames_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_getProjectionEngineFilenames_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_getProjectionEngineFilenames_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_getProjectionEngineFilenames")));
    
    return RT_HorizontalVerticalTransformationStep_getProjectionEngineFilenames_func(thisHandle, errorHandler);
}

int32_t RT_HorizontalVerticalTransformationStep_getWKID(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int32_t (*RT_HorizontalVerticalTransformationStep_getWKID_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_getWKID_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_getWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_getWKID")));
    
    return RT_HorizontalVerticalTransformationStep_getWKID_func(thisHandle, errorHandler);
}

RT_StringHandle RT_HorizontalVerticalTransformationStep_getWKText(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_HorizontalVerticalTransformationStep_getWKText_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_getWKText_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_getWKText_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_getWKText")));
    
    return RT_HorizontalVerticalTransformationStep_getWKText_func(thisHandle, errorHandler);
}

bool RT_HorizontalVerticalTransformationStep_equals(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_HorizontalVerticalTransformationStepHandle rightHorizontalVerticalTransformationStep, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_HorizontalVerticalTransformationStep_equals_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_equals_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_equals")));
    
    return RT_HorizontalVerticalTransformationStep_equals_func(thisHandle, rightHorizontalVerticalTransformationStep, errorHandler);
}

size_t RT_HorizontalVerticalTransformationStep_getHash(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_HorizontalVerticalTransformationStep_getHash_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_getHash_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_getHash_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_getHash")));
    
    return RT_HorizontalVerticalTransformationStep_getHash_func(thisHandle, errorHandler);
}

RT_HorizontalVerticalTransformationStepHandle RT_HorizontalVerticalTransformationStep_getInverse(const RT_HorizontalVerticalTransformationStepHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_HorizontalVerticalTransformationStepHandle (*RT_HorizontalVerticalTransformationStep_getInverse_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformationStep_getInverse_func = reinterpret_cast<RT_HorizontalVerticalTransformationStep_getInverse_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformationStep_getInverse")));
    
    return RT_HorizontalVerticalTransformationStep_getInverse_func(thisHandle, errorHandler);
}
#endif