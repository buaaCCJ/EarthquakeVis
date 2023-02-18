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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MultipartBuilder.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_MultipartBuilder_destroy(RT_MultipartBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MultipartBuilder_destroy_def)(RT_MultipartBuilderHandle, const RT_ErrorHandler*);
    static auto RT_MultipartBuilder_destroy_func = reinterpret_cast<RT_MultipartBuilder_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipartBuilder_destroy")));
    
    RT_MultipartBuilder_destroy_func(thisHandle, errorHandler);
}

RT_MutablePartCollectionHandle RT_MultipartBuilder_getParts(const RT_MultipartBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MutablePartCollectionHandle (*RT_MultipartBuilder_getParts_def)(const RT_MultipartBuilderHandle, const RT_ErrorHandler*);
    static auto RT_MultipartBuilder_getParts_func = reinterpret_cast<RT_MultipartBuilder_getParts_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipartBuilder_getParts")));
    
    return RT_MultipartBuilder_getParts_func(thisHandle, errorHandler);
}
void RT_MultipartBuilder_setParts(RT_MultipartBuilderHandle thisHandle, RT_MutablePartCollectionHandle parts, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MultipartBuilder_setParts_def)(RT_MultipartBuilderHandle, RT_MutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MultipartBuilder_setParts_func = reinterpret_cast<RT_MultipartBuilder_setParts_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipartBuilder_setParts")));
    
    RT_MultipartBuilder_setParts_func(thisHandle, parts, errorHandler);
}

size_t RT_MultipartBuilder_addPointXY(RT_MultipartBuilderHandle thisHandle, double x, double y, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MultipartBuilder_addPointXY_def)(RT_MultipartBuilderHandle, double, double, const RT_ErrorHandler*);
    static auto RT_MultipartBuilder_addPointXY_func = reinterpret_cast<RT_MultipartBuilder_addPointXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipartBuilder_addPointXY")));
    
    return RT_MultipartBuilder_addPointXY_func(thisHandle, x, y, errorHandler);
}

size_t RT_MultipartBuilder_addPointXYZ(RT_MultipartBuilderHandle thisHandle, double x, double y, double z, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MultipartBuilder_addPointXYZ_def)(RT_MultipartBuilderHandle, double, double, double, const RT_ErrorHandler*);
    static auto RT_MultipartBuilder_addPointXYZ_func = reinterpret_cast<RT_MultipartBuilder_addPointXYZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipartBuilder_addPointXYZ")));
    
    return RT_MultipartBuilder_addPointXYZ_func(thisHandle, x, y, z, errorHandler);
}

size_t RT_MultipartBuilder_addPoint(RT_MultipartBuilderHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MultipartBuilder_addPoint_def)(RT_MultipartBuilderHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_MultipartBuilder_addPoint_func = reinterpret_cast<RT_MultipartBuilder_addPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipartBuilder_addPoint")));
    
    return RT_MultipartBuilder_addPoint_func(thisHandle, point, errorHandler);
}
#endif