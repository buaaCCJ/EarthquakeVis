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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeographicTransformation.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GeographicTransformation_destroy(RT_GeographicTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeographicTransformation_destroy_def)(RT_GeographicTransformationHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformation_destroy_func = reinterpret_cast<RT_GeographicTransformation_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformation_destroy")));
    
    RT_GeographicTransformation_destroy_func(thisHandle, errorHandler);
}

RT_GeographicTransformationHandle RT_GeographicTransformation_createWithSteps(const RT_ArrayHandle steps, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeographicTransformationHandle (*RT_GeographicTransformation_createWithSteps_def)(const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformation_createWithSteps_func = reinterpret_cast<RT_GeographicTransformation_createWithSteps_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformation_createWithSteps")));
    
    return RT_GeographicTransformation_createWithSteps_func(steps, errorHandler);
}

RT_GeographicTransformationHandle RT_GeographicTransformation_createWithStep(const RT_GeographicTransformationStepHandle step, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeographicTransformationHandle (*RT_GeographicTransformation_createWithStep_def)(const RT_GeographicTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformation_createWithStep_func = reinterpret_cast<RT_GeographicTransformation_createWithStep_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformation_createWithStep")));
    
    return RT_GeographicTransformation_createWithStep_func(step, errorHandler);
}

RT_ArrayHandle RT_GeographicTransformation_getSteps(const RT_GeographicTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeographicTransformation_getSteps_def)(const RT_GeographicTransformationHandle, const RT_ErrorHandler*);
    static auto RT_GeographicTransformation_getSteps_func = reinterpret_cast<RT_GeographicTransformation_getSteps_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeographicTransformation_getSteps")));
    
    return RT_GeographicTransformation_getSteps_func(thisHandle, errorHandler);
}
#endif