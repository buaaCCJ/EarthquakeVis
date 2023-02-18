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
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtentRectangle.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEExtentRectangle_destroy(RT_GEExtentRectangleHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEExtentRectangle_destroy_def)(RT_GEExtentRectangleHandle, const RT_ErrorHandler*);
    static auto RT_GEExtentRectangle_destroy_func = reinterpret_cast<RT_GEExtentRectangle_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtentRectangle_destroy")));
    
    RT_GEExtentRectangle_destroy_func(thisHandle, errorHandler);
}

RT_GEExtentRectangleHandle RT_GEExtentRectangle_create(const RT_PointHandle center, double width, double height, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEExtentRectangleHandle (*RT_GEExtentRectangle_create_def)(const RT_PointHandle, double, double, const RT_ErrorHandler*);
    static auto RT_GEExtentRectangle_create_func = reinterpret_cast<RT_GEExtentRectangle_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtentRectangle_create")));
    
    return RT_GEExtentRectangle_create_func(center, width, height, errorHandler);
}

double RT_GEExtentRectangle_getHeight(const RT_GEExtentRectangleHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GEExtentRectangle_getHeight_def)(const RT_GEExtentRectangleHandle, const RT_ErrorHandler*);
    static auto RT_GEExtentRectangle_getHeight_func = reinterpret_cast<RT_GEExtentRectangle_getHeight_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtentRectangle_getHeight")));
    
    return RT_GEExtentRectangle_getHeight_func(thisHandle, errorHandler);
}

double RT_GEExtentRectangle_getWidth(const RT_GEExtentRectangleHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GEExtentRectangle_getWidth_def)(const RT_GEExtentRectangleHandle, const RT_ErrorHandler*);
    static auto RT_GEExtentRectangle_getWidth_func = reinterpret_cast<RT_GEExtentRectangle_getWidth_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEExtentRectangle_getWidth")));
    
    return RT_GEExtentRectangle_getWidth_func(thisHandle, errorHandler);
}
#endif