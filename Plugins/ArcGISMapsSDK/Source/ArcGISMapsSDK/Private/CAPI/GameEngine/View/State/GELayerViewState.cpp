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
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GELayerViewState.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GELayerViewState_destroy(RT_GELayerViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayerViewState_destroy_def)(RT_GELayerViewStateHandle, const RT_ErrorHandler*);
    static auto RT_GELayerViewState_destroy_func = reinterpret_cast<RT_GELayerViewState_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerViewState_destroy")));
    
    RT_GELayerViewState_destroy_func(thisHandle, errorHandler);
}

RT_GEViewStateMessageHandle RT_GELayerViewState_getMessage(const RT_GELayerViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEViewStateMessageHandle (*RT_GELayerViewState_getMessage_def)(const RT_GELayerViewStateHandle, const RT_ErrorHandler*);
    static auto RT_GELayerViewState_getMessage_func = reinterpret_cast<RT_GELayerViewState_getMessage_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerViewState_getMessage")));
    
    return RT_GELayerViewState_getMessage_func(thisHandle, errorHandler);
}

RT_GELayerViewStatus RT_GELayerViewState_getStatus(const RT_GELayerViewStateHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerViewStatus (*RT_GELayerViewState_getStatus_def)(const RT_GELayerViewStateHandle, const RT_ErrorHandler*);
    static auto RT_GELayerViewState_getStatus_func = reinterpret_cast<RT_GELayerViewState_getStatus_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerViewState_getStatus")));
    
    return RT_GELayerViewState_getStatus_func(thisHandle, errorHandler);
}
#endif