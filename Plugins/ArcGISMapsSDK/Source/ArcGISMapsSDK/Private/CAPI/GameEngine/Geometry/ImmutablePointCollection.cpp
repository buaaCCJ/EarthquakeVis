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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePointCollection.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_ImmutablePointCollection_destroy(RT_ImmutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ImmutablePointCollection_destroy_def)(RT_ImmutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePointCollection_destroy_func = reinterpret_cast<RT_ImmutablePointCollection_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePointCollection_destroy")));
    
    RT_ImmutablePointCollection_destroy_func(thisHandle, errorHandler);
}

bool RT_ImmutablePointCollection_getIsEmpty(const RT_ImmutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_ImmutablePointCollection_getIsEmpty_def)(const RT_ImmutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePointCollection_getIsEmpty_func = reinterpret_cast<RT_ImmutablePointCollection_getIsEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePointCollection_getIsEmpty")));
    
    return RT_ImmutablePointCollection_getIsEmpty_func(thisHandle, errorHandler);
}

size_t RT_ImmutablePointCollection_getSize(const RT_ImmutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePointCollection_getSize_def)(const RT_ImmutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePointCollection_getSize_func = reinterpret_cast<RT_ImmutablePointCollection_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePointCollection_getSize")));
    
    return RT_ImmutablePointCollection_getSize_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_ImmutablePointCollection_getSpatialReference(const RT_ImmutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_ImmutablePointCollection_getSpatialReference_def)(const RT_ImmutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePointCollection_getSpatialReference_func = reinterpret_cast<RT_ImmutablePointCollection_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePointCollection_getSpatialReference")));
    
    return RT_ImmutablePointCollection_getSpatialReference_func(thisHandle, errorHandler);
}

RT_PointHandle RT_ImmutablePointCollection_getPoint(const RT_ImmutablePointCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_ImmutablePointCollection_getPoint_def)(const RT_ImmutablePointCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_ImmutablePointCollection_getPoint_func = reinterpret_cast<RT_ImmutablePointCollection_getPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePointCollection_getPoint")));
    
    return RT_ImmutablePointCollection_getPoint_func(thisHandle, index, errorHandler);
}

size_t RT_ImmutablePointCollection_indexOf(const RT_ImmutablePointCollectionHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePointCollection_indexOf_def)(const RT_ImmutablePointCollectionHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePointCollection_indexOf_func = reinterpret_cast<RT_ImmutablePointCollection_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePointCollection_indexOf")));
    
    return RT_ImmutablePointCollection_indexOf_func(thisHandle, point, errorHandler);
}
#endif