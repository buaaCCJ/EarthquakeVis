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
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/VisualizationAttributeDescription.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_VisualizationAttributeDescription_destroy(RT_VisualizationAttributeDescriptionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_VisualizationAttributeDescription_destroy_def)(RT_VisualizationAttributeDescriptionHandle, const RT_ErrorHandler*);
    static auto RT_VisualizationAttributeDescription_destroy_func = reinterpret_cast<RT_VisualizationAttributeDescription_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VisualizationAttributeDescription_destroy")));
    
    RT_VisualizationAttributeDescription_destroy_func(thisHandle, errorHandler);
}

RT_VisualizationAttributeDescriptionHandle RT_VisualizationAttributeDescription_create(const char* name, RT_VisualizationAttributeType visualizationAttributeType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VisualizationAttributeDescriptionHandle (*RT_VisualizationAttributeDescription_create_def)(const char*, RT_VisualizationAttributeType, const RT_ErrorHandler*);
    static auto RT_VisualizationAttributeDescription_create_func = reinterpret_cast<RT_VisualizationAttributeDescription_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VisualizationAttributeDescription_create")));
    
    return RT_VisualizationAttributeDescription_create_func(name, visualizationAttributeType, errorHandler);
}

RT_StringHandle RT_VisualizationAttributeDescription_getName(const RT_VisualizationAttributeDescriptionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_VisualizationAttributeDescription_getName_def)(const RT_VisualizationAttributeDescriptionHandle, const RT_ErrorHandler*);
    static auto RT_VisualizationAttributeDescription_getName_func = reinterpret_cast<RT_VisualizationAttributeDescription_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VisualizationAttributeDescription_getName")));
    
    return RT_VisualizationAttributeDescription_getName_func(thisHandle, errorHandler);
}

RT_VisualizationAttributeType RT_VisualizationAttributeDescription_getVisualizationAttributeType(const RT_VisualizationAttributeDescriptionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VisualizationAttributeType (*RT_VisualizationAttributeDescription_getVisualizationAttributeType_def)(const RT_VisualizationAttributeDescriptionHandle, const RT_ErrorHandler*);
    static auto RT_VisualizationAttributeDescription_getVisualizationAttributeType_func = reinterpret_cast<RT_VisualizationAttributeDescription_getVisualizationAttributeType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VisualizationAttributeDescription_getVisualizationAttributeType")));
    
    return RT_VisualizationAttributeDescription_getVisualizationAttributeType_func(thisHandle, errorHandler);
}
#endif