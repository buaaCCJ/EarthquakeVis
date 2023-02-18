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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Polyline.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Polyline_destroy(RT_PolylineHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Polyline_destroy_def)(RT_PolylineHandle, const RT_ErrorHandler*);
    static auto RT_Polyline_destroy_func = reinterpret_cast<RT_Polyline_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Polyline_destroy")));
    
    RT_Polyline_destroy_func(thisHandle, errorHandler);
}
#endif