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
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/VisualizationAttribute.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_VisualizationAttribute_destroy(RT_VisualizationAttributeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_VisualizationAttribute_destroy_def)(RT_VisualizationAttributeHandle, const RT_ErrorHandler*);
    static auto RT_VisualizationAttribute_destroy_func = reinterpret_cast<RT_VisualizationAttribute_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VisualizationAttribute_destroy")));
    
    RT_VisualizationAttribute_destroy_func(thisHandle, errorHandler);
}

RT_ByteArray RT_VisualizationAttribute_getData(const RT_VisualizationAttributeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ByteArray (*RT_VisualizationAttribute_getData_def)(const RT_VisualizationAttributeHandle, const RT_ErrorHandler*);
    static auto RT_VisualizationAttribute_getData_func = reinterpret_cast<RT_VisualizationAttribute_getData_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VisualizationAttribute_getData")));
    
    return RT_VisualizationAttribute_getData_func(thisHandle, errorHandler);
}

RT_StringHandle RT_VisualizationAttribute_getName(const RT_VisualizationAttributeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_VisualizationAttribute_getName_def)(const RT_VisualizationAttributeHandle, const RT_ErrorHandler*);
    static auto RT_VisualizationAttribute_getName_func = reinterpret_cast<RT_VisualizationAttribute_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VisualizationAttribute_getName")));
    
    return RT_VisualizationAttribute_getName_func(thisHandle, errorHandler);
}

RT_VisualizationAttributeType RT_VisualizationAttribute_getVisualizationAttributeType(const RT_VisualizationAttributeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VisualizationAttributeType (*RT_VisualizationAttribute_getVisualizationAttributeType_def)(const RT_VisualizationAttributeHandle, const RT_ErrorHandler*);
    static auto RT_VisualizationAttribute_getVisualizationAttributeType_func = reinterpret_cast<RT_VisualizationAttribute_getVisualizationAttributeType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VisualizationAttribute_getVisualizationAttributeType")));
    
    return RT_VisualizationAttribute_getVisualizationAttributeType_func(thisHandle, errorHandler);
}
#endif