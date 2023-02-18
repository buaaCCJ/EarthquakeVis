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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GE3DObjectSceneLayer.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GE3DObjectSceneLayer_destroy(RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GE3DObjectSceneLayer_destroy_def)(RT_GE3DObjectSceneLayerHandle, const RT_ErrorHandler*);
    static auto RT_GE3DObjectSceneLayer_destroy_func = reinterpret_cast<RT_GE3DObjectSceneLayer_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GE3DObjectSceneLayer_destroy")));
    
    RT_GE3DObjectSceneLayer_destroy_func(thisHandle, errorHandler);
}

RT_GE3DObjectSceneLayerHandle RT_GE3DObjectSceneLayer_create(const char* source, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GE3DObjectSceneLayerHandle (*RT_GE3DObjectSceneLayer_create_def)(const char*, const char*, const RT_ErrorHandler*);
    static auto RT_GE3DObjectSceneLayer_create_func = reinterpret_cast<RT_GE3DObjectSceneLayer_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GE3DObjectSceneLayer_create")));
    
    return RT_GE3DObjectSceneLayer_create_func(source, APIKey, errorHandler);
}

RT_GE3DObjectSceneLayerHandle RT_GE3DObjectSceneLayer_createWithProperties(const char* source, const char* name, float opacity, bool visible, const char* APIKey, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GE3DObjectSceneLayerHandle (*RT_GE3DObjectSceneLayer_createWithProperties_def)(const char*, const char*, float, bool, const char*, const RT_ErrorHandler*);
    static auto RT_GE3DObjectSceneLayer_createWithProperties_func = reinterpret_cast<RT_GE3DObjectSceneLayer_createWithProperties_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GE3DObjectSceneLayer_createWithProperties")));
    
    return RT_GE3DObjectSceneLayer_createWithProperties_func(source, name, opacity, visible, APIKey, errorHandler);
}

void* RT_GE3DObjectSceneLayer_getMaterialReference(const RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void* (*RT_GE3DObjectSceneLayer_getMaterialReference_def)(const RT_GE3DObjectSceneLayerHandle, const RT_ErrorHandler*);
    static auto RT_GE3DObjectSceneLayer_getMaterialReference_func = reinterpret_cast<RT_GE3DObjectSceneLayer_getMaterialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GE3DObjectSceneLayer_getMaterialReference")));
    
    return RT_GE3DObjectSceneLayer_getMaterialReference_func(thisHandle, errorHandler);
}
void RT_GE3DObjectSceneLayer_setMaterialReference(RT_GE3DObjectSceneLayerHandle thisHandle, void* materialReference, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GE3DObjectSceneLayer_setMaterialReference_def)(RT_GE3DObjectSceneLayerHandle, void*, const RT_ErrorHandler*);
    static auto RT_GE3DObjectSceneLayer_setMaterialReference_func = reinterpret_cast<RT_GE3DObjectSceneLayer_setMaterialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GE3DObjectSceneLayer_setMaterialReference")));
    
    RT_GE3DObjectSceneLayer_setMaterialReference_func(thisHandle, materialReference, errorHandler);
}

void RT_GE3DObjectSceneLayer_setAttributesToVisualize(RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ArrayHandle layerAttributes, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GE3DObjectSceneLayer_setAttributesToVisualize_def)(RT_GE3DObjectSceneLayerHandle, const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_GE3DObjectSceneLayer_setAttributesToVisualize_func = reinterpret_cast<RT_GE3DObjectSceneLayer_setAttributesToVisualize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GE3DObjectSceneLayer_setAttributesToVisualize")));
    
    RT_GE3DObjectSceneLayer_setAttributesToVisualize_func(thisHandle, layerAttributes, errorHandler);
}

void RT_GE3DObjectSceneLayer_setAttributesToVisualizeAndTransform(RT_GE3DObjectSceneLayerHandle thisHandle, const RT_ArrayHandle layerAttributes, const RT_ArrayHandle visualizationAttributeDescriptions, const RT_AttributeProcessorHandle attributeProcessor, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GE3DObjectSceneLayer_setAttributesToVisualizeAndTransform_def)(RT_GE3DObjectSceneLayerHandle, const RT_ArrayHandle, const RT_ArrayHandle, const RT_AttributeProcessorHandle, const RT_ErrorHandler*);
    static auto RT_GE3DObjectSceneLayer_setAttributesToVisualizeAndTransform_func = reinterpret_cast<RT_GE3DObjectSceneLayer_setAttributesToVisualizeAndTransform_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GE3DObjectSceneLayer_setAttributesToVisualizeAndTransform")));
    
    RT_GE3DObjectSceneLayer_setAttributesToVisualizeAndTransform_func(thisHandle, layerAttributes, visualizationAttributeDescriptions, attributeProcessor, errorHandler);
}
#endif