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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Multipoint.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Multipoint_destroy(RT_MultipointHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Multipoint_destroy_def)(RT_MultipointHandle, const RT_ErrorHandler*);
    static auto RT_Multipoint_destroy_func = reinterpret_cast<RT_Multipoint_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Multipoint_destroy")));
    
    RT_Multipoint_destroy_func(thisHandle, errorHandler);
}

RT_ImmutablePointCollectionHandle RT_Multipoint_getPoints(const RT_MultipointHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ImmutablePointCollectionHandle (*RT_Multipoint_getPoints_def)(const RT_MultipointHandle, const RT_ErrorHandler*);
    static auto RT_Multipoint_getPoints_func = reinterpret_cast<RT_Multipoint_getPoints_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Multipoint_getPoints")));
    
    return RT_Multipoint_getPoints_func(thisHandle, errorHandler);
}
#endif