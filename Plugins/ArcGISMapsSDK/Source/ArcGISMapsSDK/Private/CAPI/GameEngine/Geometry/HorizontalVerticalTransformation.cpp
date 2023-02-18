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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/HorizontalVerticalTransformation.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_HorizontalVerticalTransformation_destroy(RT_HorizontalVerticalTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_HorizontalVerticalTransformation_destroy_def)(RT_HorizontalVerticalTransformationHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformation_destroy_func = reinterpret_cast<RT_HorizontalVerticalTransformation_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformation_destroy")));
    
    RT_HorizontalVerticalTransformation_destroy_func(thisHandle, errorHandler);
}

RT_HorizontalVerticalTransformationHandle RT_HorizontalVerticalTransformation_createWithSteps(const RT_ArrayHandle steps, const RT_ErrorHandler* errorHandler)
{
    typedef RT_HorizontalVerticalTransformationHandle (*RT_HorizontalVerticalTransformation_createWithSteps_def)(const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformation_createWithSteps_func = reinterpret_cast<RT_HorizontalVerticalTransformation_createWithSteps_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformation_createWithSteps")));
    
    return RT_HorizontalVerticalTransformation_createWithSteps_func(steps, errorHandler);
}

RT_HorizontalVerticalTransformationHandle RT_HorizontalVerticalTransformation_createWithStep(const RT_HorizontalVerticalTransformationStepHandle step, const RT_ErrorHandler* errorHandler)
{
    typedef RT_HorizontalVerticalTransformationHandle (*RT_HorizontalVerticalTransformation_createWithStep_def)(const RT_HorizontalVerticalTransformationStepHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformation_createWithStep_func = reinterpret_cast<RT_HorizontalVerticalTransformation_createWithStep_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformation_createWithStep")));
    
    return RT_HorizontalVerticalTransformation_createWithStep_func(step, errorHandler);
}

RT_ArrayHandle RT_HorizontalVerticalTransformation_getSteps(const RT_HorizontalVerticalTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_HorizontalVerticalTransformation_getSteps_def)(const RT_HorizontalVerticalTransformationHandle, const RT_ErrorHandler*);
    static auto RT_HorizontalVerticalTransformation_getSteps_func = reinterpret_cast<RT_HorizontalVerticalTransformation_getSteps_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_HorizontalVerticalTransformation_getSteps")));
    
    return RT_HorizontalVerticalTransformation_getSteps_func(thisHandle, errorHandler);
}
#endif