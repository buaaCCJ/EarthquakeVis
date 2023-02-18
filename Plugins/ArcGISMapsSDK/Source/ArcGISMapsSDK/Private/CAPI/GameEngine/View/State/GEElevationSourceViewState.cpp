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
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEElevationSourceViewState.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEElevationSourceViewState_destroy(RT_GEElevationSourceViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSourceViewState_destroy_def)(RT_GEElevationSourceViewStateHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceViewState_destroy_func = reinterpret_cast<RT_GEElevationSourceViewState_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceViewState_destroy")));
    
    RT_GEElevationSourceViewState_destroy_func(thisHandle, errorHandler);
}

RT_GEViewStateMessageHandle RT_GEElevationSourceViewState_getMessage(const RT_GEElevationSourceViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEViewStateMessageHandle (*RT_GEElevationSourceViewState_getMessage_def)(const RT_GEElevationSourceViewStateHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceViewState_getMessage_func = reinterpret_cast<RT_GEElevationSourceViewState_getMessage_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceViewState_getMessage")));
    
    return RT_GEElevationSourceViewState_getMessage_func(thisHandle, errorHandler);
}

RT_GEElevationSourceViewStatus RT_GEElevationSourceViewState_getStatus(const RT_GEElevationSourceViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceViewStatus (*RT_GEElevationSourceViewState_getStatus_def)(const RT_GEElevationSourceViewStateHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceViewState_getStatus_func = reinterpret_cast<RT_GEElevationSourceViewState_getStatus_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceViewState_getStatus")));
    
    return RT_GEElevationSourceViewState_getStatus_func(thisHandle, errorHandler);
}
#endif