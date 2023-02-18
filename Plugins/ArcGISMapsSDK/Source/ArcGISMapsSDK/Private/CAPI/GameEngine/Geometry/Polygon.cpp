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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Polygon.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Polygon_destroy(RT_PolygonHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Polygon_destroy_def)(RT_PolygonHandle, const RT_ErrorHandler*);
    static auto RT_Polygon_destroy_func = reinterpret_cast<RT_Polygon_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Polygon_destroy")));
    
    RT_Polygon_destroy_func(thisHandle, errorHandler);
}

RT_PolylineHandle RT_Polygon_toPolyline(const RT_PolygonHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolylineHandle (*RT_Polygon_toPolyline_def)(const RT_PolygonHandle, const RT_ErrorHandler*);
    static auto RT_Polygon_toPolyline_func = reinterpret_cast<RT_Polygon_toPolyline_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Polygon_toPolyline")));
    
    return RT_Polygon_toPolyline_func(thisHandle, errorHandler);
}
#endif