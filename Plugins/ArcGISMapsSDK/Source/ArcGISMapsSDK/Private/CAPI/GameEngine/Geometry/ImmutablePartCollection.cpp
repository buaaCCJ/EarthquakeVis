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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePartCollection.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_ImmutablePartCollection_destroy(RT_ImmutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ImmutablePartCollection_destroy_def)(RT_ImmutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePartCollection_destroy_func = reinterpret_cast<RT_ImmutablePartCollection_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePartCollection_destroy")));
    
    RT_ImmutablePartCollection_destroy_func(thisHandle, errorHandler);
}

bool RT_ImmutablePartCollection_getIsEmpty(const RT_ImmutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_ImmutablePartCollection_getIsEmpty_def)(const RT_ImmutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePartCollection_getIsEmpty_func = reinterpret_cast<RT_ImmutablePartCollection_getIsEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePartCollection_getIsEmpty")));
    
    return RT_ImmutablePartCollection_getIsEmpty_func(thisHandle, errorHandler);
}

size_t RT_ImmutablePartCollection_getSize(const RT_ImmutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePartCollection_getSize_def)(const RT_ImmutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePartCollection_getSize_func = reinterpret_cast<RT_ImmutablePartCollection_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePartCollection_getSize")));
    
    return RT_ImmutablePartCollection_getSize_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_ImmutablePartCollection_getSpatialReference(const RT_ImmutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_ImmutablePartCollection_getSpatialReference_def)(const RT_ImmutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePartCollection_getSpatialReference_func = reinterpret_cast<RT_ImmutablePartCollection_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePartCollection_getSpatialReference")));
    
    return RT_ImmutablePartCollection_getSpatialReference_func(thisHandle, errorHandler);
}

RT_ImmutablePartHandle RT_ImmutablePartCollection_getPart(const RT_ImmutablePartCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ImmutablePartHandle (*RT_ImmutablePartCollection_getPart_def)(const RT_ImmutablePartCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_ImmutablePartCollection_getPart_func = reinterpret_cast<RT_ImmutablePartCollection_getPart_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePartCollection_getPart")));
    
    return RT_ImmutablePartCollection_getPart_func(thisHandle, index, errorHandler);
}

size_t RT_ImmutablePartCollection_indexOf(const RT_ImmutablePartCollectionHandle thisHandle, const RT_ImmutablePartHandle immutablePart, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePartCollection_indexOf_def)(const RT_ImmutablePartCollectionHandle, const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePartCollection_indexOf_func = reinterpret_cast<RT_ImmutablePartCollection_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePartCollection_indexOf")));
    
    return RT_ImmutablePartCollection_indexOf_func(thisHandle, immutablePart, errorHandler);
}
#endif