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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PolylineBuilder.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_PolylineBuilder_destroy(RT_PolylineBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PolylineBuilder_destroy_def)(RT_PolylineBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PolylineBuilder_destroy_func = reinterpret_cast<RT_PolylineBuilder_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PolylineBuilder_destroy")));
    
    RT_PolylineBuilder_destroy_func(thisHandle, errorHandler);
}

RT_PolylineBuilderHandle RT_PolylineBuilder_createFromPolyline(const RT_PolylineHandle polyline, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolylineBuilderHandle (*RT_PolylineBuilder_createFromPolyline_def)(const RT_PolylineHandle, const RT_ErrorHandler*);
    static auto RT_PolylineBuilder_createFromPolyline_func = reinterpret_cast<RT_PolylineBuilder_createFromPolyline_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PolylineBuilder_createFromPolyline")));
    
    return RT_PolylineBuilder_createFromPolyline_func(polyline, errorHandler);
}

RT_PolylineBuilderHandle RT_PolylineBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolylineBuilderHandle (*RT_PolylineBuilder_createFromSpatialReference_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_PolylineBuilder_createFromSpatialReference_func = reinterpret_cast<RT_PolylineBuilder_createFromSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PolylineBuilder_createFromSpatialReference")));
    
    return RT_PolylineBuilder_createFromSpatialReference_func(spatialReference, errorHandler);
}
#endif