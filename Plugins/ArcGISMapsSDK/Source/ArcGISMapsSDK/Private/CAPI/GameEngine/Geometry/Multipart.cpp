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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Multipart.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Multipart_destroy(RT_MultipartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Multipart_destroy_def)(RT_MultipartHandle, const RT_ErrorHandler*);
    static auto RT_Multipart_destroy_func = reinterpret_cast<RT_Multipart_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Multipart_destroy")));
    
    RT_Multipart_destroy_func(thisHandle, errorHandler);
}

RT_ImmutablePartCollectionHandle RT_Multipart_getParts(const RT_MultipartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ImmutablePartCollectionHandle (*RT_Multipart_getParts_def)(const RT_MultipartHandle, const RT_ErrorHandler*);
    static auto RT_Multipart_getParts_func = reinterpret_cast<RT_Multipart_getParts_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Multipart_getParts")));
    
    return RT_Multipart_getParts_func(thisHandle, errorHandler);
}
#endif