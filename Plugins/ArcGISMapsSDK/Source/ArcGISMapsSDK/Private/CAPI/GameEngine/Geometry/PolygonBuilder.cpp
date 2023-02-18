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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PolygonBuilder.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_PolygonBuilder_destroy(RT_PolygonBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PolygonBuilder_destroy_def)(RT_PolygonBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PolygonBuilder_destroy_func = reinterpret_cast<RT_PolygonBuilder_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PolygonBuilder_destroy")));
    
    RT_PolygonBuilder_destroy_func(thisHandle, errorHandler);
}

RT_PolygonBuilderHandle RT_PolygonBuilder_createFromPolygon(const RT_PolygonHandle polygon, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolygonBuilderHandle (*RT_PolygonBuilder_createFromPolygon_def)(const RT_PolygonHandle, const RT_ErrorHandler*);
    static auto RT_PolygonBuilder_createFromPolygon_func = reinterpret_cast<RT_PolygonBuilder_createFromPolygon_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PolygonBuilder_createFromPolygon")));
    
    return RT_PolygonBuilder_createFromPolygon_func(polygon, errorHandler);
}

RT_PolygonBuilderHandle RT_PolygonBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolygonBuilderHandle (*RT_PolygonBuilder_createFromSpatialReference_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_PolygonBuilder_createFromSpatialReference_func = reinterpret_cast<RT_PolygonBuilder_createFromSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PolygonBuilder_createFromSpatialReference")));
    
    return RT_PolygonBuilder_createFromSpatialReference_func(spatialReference, errorHandler);
}

RT_PolylineHandle RT_PolygonBuilder_toPolyline(const RT_PolygonBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolylineHandle (*RT_PolygonBuilder_toPolyline_def)(const RT_PolygonBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PolygonBuilder_toPolyline_func = reinterpret_cast<RT_PolygonBuilder_toPolyline_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PolygonBuilder_toPolyline")));
    
    return RT_PolygonBuilder_toPolyline_func(thisHandle, errorHandler);
}
#endif