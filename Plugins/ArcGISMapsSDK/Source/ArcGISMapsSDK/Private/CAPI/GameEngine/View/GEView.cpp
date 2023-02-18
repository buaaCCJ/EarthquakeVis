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
#include "ArcGISMapsSDK/CAPI/GameEngine/View/GEView.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEView_destroy(RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_destroy_def)(RT_GEViewHandle, const RT_ErrorHandler*);
    static auto RT_GEView_destroy_func = reinterpret_cast<RT_GEView_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_destroy")));
    
    RT_GEView_destroy_func(thisHandle, errorHandler);
}

RT_GEViewHandle RT_GEView_create(RT_GameEngineType gameEngineType, RT_GlobeModel globeModel, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEViewHandle (*RT_GEView_create_def)(RT_GameEngineType, RT_GlobeModel, const RT_ErrorHandler*);
    static auto RT_GEView_create_func = reinterpret_cast<RT_GEView_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_create")));
    
    return RT_GEView_create_func(gameEngineType, globeModel, errorHandler);
}

RT_CameraHandle RT_GEView_getCamera(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_CameraHandle (*RT_GEView_getCamera_def)(const RT_GEViewHandle, const RT_ErrorHandler*);
    static auto RT_GEView_getCamera_func = reinterpret_cast<RT_GEView_getCamera_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_getCamera")));
    
    return RT_GEView_getCamera_func(thisHandle, errorHandler);
}
void RT_GEView_setCamera(RT_GEViewHandle thisHandle, RT_CameraHandle camera, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setCamera_def)(RT_GEViewHandle, RT_CameraHandle, const RT_ErrorHandler*);
    static auto RT_GEView_setCamera_func = reinterpret_cast<RT_GEView_setCamera_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setCamera")));
    
    RT_GEView_setCamera_func(thisHandle, camera, errorHandler);
}

RT_GEMapHandle RT_GEView_getMap(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEMapHandle (*RT_GEView_getMap_def)(const RT_GEViewHandle, const RT_ErrorHandler*);
    static auto RT_GEView_getMap_func = reinterpret_cast<RT_GEView_getMap_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_getMap")));
    
    return RT_GEView_getMap_func(thisHandle, errorHandler);
}
void RT_GEView_setMap(RT_GEViewHandle thisHandle, RT_GEMapHandle map, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setMap_def)(RT_GEViewHandle, RT_GEMapHandle, const RT_ErrorHandler*);
    static auto RT_GEView_setMap_func = reinterpret_cast<RT_GEView_setMap_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setMap")));
    
    RT_GEView_setMap_func(thisHandle, map, errorHandler);
}

RT_RenderCommandServerHandle RT_GEView_getRenderCommandServer(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_RenderCommandServerHandle (*RT_GEView_getRenderCommandServer_def)(const RT_GEViewHandle, const RT_ErrorHandler*);
    static auto RT_GEView_getRenderCommandServer_func = reinterpret_cast<RT_GEView_getRenderCommandServer_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_getRenderCommandServer")));
    
    return RT_GEView_getRenderCommandServer_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_GEView_getSpatialReference(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_GEView_getSpatialReference_def)(const RT_GEViewHandle, const RT_ErrorHandler*);
    static auto RT_GEView_getSpatialReference_func = reinterpret_cast<RT_GEView_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_getSpatialReference")));
    
    return RT_GEView_getSpatialReference_func(thisHandle, errorHandler);
}

RT_GEViewOptions RT_GEView_getViewOptions(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEViewOptions (*RT_GEView_getViewOptions_def)(const RT_GEViewHandle, const RT_ErrorHandler*);
    static auto RT_GEView_getViewOptions_func = reinterpret_cast<RT_GEView_getViewOptions_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_getViewOptions")));
    
    return RT_GEView_getViewOptions_func(thisHandle, errorHandler);
}
void RT_GEView_setViewOptions(RT_GEViewHandle thisHandle, RT_GEViewOptions viewOptions, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setViewOptions_def)(RT_GEViewHandle, RT_GEViewOptions, const RT_ErrorHandler*);
    static auto RT_GEView_setViewOptions_func = reinterpret_cast<RT_GEView_setViewOptions_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setViewOptions")));
    
    RT_GEView_setViewOptions_func(thisHandle, viewOptions, errorHandler);
}

RT_Vector3 RT_GEView_geographicToWorld(const RT_GEViewHandle thisHandle, const RT_PointHandle geographicCoordinate, const RT_ErrorHandler* errorHandler)
{
    typedef RT_Vector3 (*RT_GEView_geographicToWorld_def)(const RT_GEViewHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_GEView_geographicToWorld_func = reinterpret_cast<RT_GEView_geographicToWorld_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_geographicToWorld")));
    
    return RT_GEView_geographicToWorld_func(thisHandle, geographicCoordinate, errorHandler);
}

RT_GEViewStateHandle RT_GEView_getViewViewState(const RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEViewStateHandle (*RT_GEView_getViewViewState_def)(const RT_GEViewHandle, const RT_ErrorHandler*);
    static auto RT_GEView_getViewViewState_func = reinterpret_cast<RT_GEView_getViewViewState_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_getViewViewState")));
    
    return RT_GEView_getViewViewState_func(thisHandle, errorHandler);
}

RT_GEElevationSourceViewStateHandle RT_GEView_getElevationSourceViewState(const RT_GEViewHandle thisHandle, const RT_GEElevationSourceHandle elevation, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceViewStateHandle (*RT_GEView_getElevationSourceViewState_def)(const RT_GEViewHandle, const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEView_getElevationSourceViewState_func = reinterpret_cast<RT_GEView_getElevationSourceViewState_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_getElevationSourceViewState")));
    
    return RT_GEView_getElevationSourceViewState_func(thisHandle, elevation, errorHandler);
}

RT_GELayerViewStateHandle RT_GEView_getLayerViewState(const RT_GEViewHandle thisHandle, const RT_GELayerHandle layer, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerViewStateHandle (*RT_GEView_getLayerViewState_def)(const RT_GEViewHandle, const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GEView_getLayerViewState_func = reinterpret_cast<RT_GEView_getLayerViewState_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_getLayerViewState")));
    
    return RT_GEView_getLayerViewState_func(thisHandle, layer, errorHandler);
}

void RT_GEView_handleLowMemoryWarning(RT_GEViewHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_handleLowMemoryWarning_def)(RT_GEViewHandle, const RT_ErrorHandler*);
    static auto RT_GEView_handleLowMemoryWarning_func = reinterpret_cast<RT_GEView_handleLowMemoryWarning_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_handleLowMemoryWarning")));
    
    RT_GEView_handleLowMemoryWarning_func(thisHandle, errorHandler);
}

void RT_GEView_setMemoryQuotas(RT_GEViewHandle thisHandle, int64_t systemMemory, int64_t videoMemory, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setMemoryQuotas_def)(RT_GEViewHandle, int64_t, int64_t, const RT_ErrorHandler*);
    static auto RT_GEView_setMemoryQuotas_func = reinterpret_cast<RT_GEView_setMemoryQuotas_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setMemoryQuotas")));
    
    RT_GEView_setMemoryQuotas_func(thisHandle, systemMemory, videoMemory, errorHandler);
}

void RT_GEView_setViewportProperties(RT_GEViewHandle thisHandle, uint32_t viewportWidthPixels, uint32_t viewportHeightPixels, float horizontalFieldOfViewDegrees, float verticalFieldOfViewDegrees, float verticalDistortionFactor, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setViewportProperties_def)(RT_GEViewHandle, uint32_t, uint32_t, float, float, float, const RT_ErrorHandler*);
    static auto RT_GEView_setViewportProperties_func = reinterpret_cast<RT_GEView_setViewportProperties_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setViewportProperties")));
    
    RT_GEView_setViewportProperties_func(thisHandle, viewportWidthPixels, viewportHeightPixels, horizontalFieldOfViewDegrees, verticalFieldOfViewDegrees, verticalDistortionFactor, errorHandler);
}

RT_PointHandle RT_GEView_worldToGeographic(const RT_GEViewHandle thisHandle, RT_Vector3 worldCoordinate, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_GEView_worldToGeographic_def)(const RT_GEViewHandle, RT_Vector3, const RT_ErrorHandler*);
    static auto RT_GEView_worldToGeographic_func = reinterpret_cast<RT_GEView_worldToGeographic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_worldToGeographic")));
    
    return RT_GEView_worldToGeographic_func(thisHandle, worldCoordinate, errorHandler);
}

void RT_GEView_setElevationSourceViewStateChangedCallback(RT_GEViewHandle thisHandle, RT_GEElevationSourceViewStateChangedEvent_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setElevationSourceViewStateChangedCallback_def)(RT_GEViewHandle, RT_GEElevationSourceViewStateChangedEvent_issued_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEView_setElevationSourceViewStateChangedCallback_func = reinterpret_cast<RT_GEView_setElevationSourceViewStateChangedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setElevationSourceViewStateChangedCallback")));
    
    RT_GEView_setElevationSourceViewStateChangedCallback_func(thisHandle, callback, userData, errorHandler);
}

void RT_GEView_setLayerViewStateChangedCallback(RT_GEViewHandle thisHandle, RT_GELayerViewStateChangedEvent_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setLayerViewStateChangedCallback_def)(RT_GEViewHandle, RT_GELayerViewStateChangedEvent_issued_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEView_setLayerViewStateChangedCallback_func = reinterpret_cast<RT_GEView_setLayerViewStateChangedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setLayerViewStateChangedCallback")));
    
    RT_GEView_setLayerViewStateChangedCallback_func(thisHandle, callback, userData, errorHandler);
}

void RT_GEView_setSpatialReferenceChangedCallback(RT_GEViewHandle thisHandle, RT_GEViewSpatialReferenceChangedEvent_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setSpatialReferenceChangedCallback_def)(RT_GEViewHandle, RT_GEViewSpatialReferenceChangedEvent_issued_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEView_setSpatialReferenceChangedCallback_func = reinterpret_cast<RT_GEView_setSpatialReferenceChangedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setSpatialReferenceChangedCallback")));
    
    RT_GEView_setSpatialReferenceChangedCallback_func(thisHandle, callback, userData, errorHandler);
}

void RT_GEView_setViewStateChangedCallback(RT_GEViewHandle thisHandle, RT_GEViewStateChangedEvent_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEView_setViewStateChangedCallback_def)(RT_GEViewHandle, RT_GEViewStateChangedEvent_issued_fn, void*, const RT_ErrorHandler*);
    static auto RT_GEView_setViewStateChangedCallback_func = reinterpret_cast<RT_GEView_setViewStateChangedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEView_setViewStateChangedCallback")));
    
    RT_GEView_setViewStateChangedCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif