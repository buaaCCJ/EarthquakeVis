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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GEUnsupportedLayer.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEUnsupportedLayer_destroy(RT_GEUnsupportedLayerHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEUnsupportedLayer_destroy_def)(RT_GEUnsupportedLayerHandle, const RT_ErrorHandler*);
    static auto RT_GEUnsupportedLayer_destroy_func = reinterpret_cast<RT_GEUnsupportedLayer_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEUnsupportedLayer_destroy")));
    
    RT_GEUnsupportedLayer_destroy_func(thisHandle, errorHandler);
}
#endif