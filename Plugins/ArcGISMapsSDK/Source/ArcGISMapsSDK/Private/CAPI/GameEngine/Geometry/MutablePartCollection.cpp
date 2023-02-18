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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePartCollection.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_MutablePartCollection_destroy(RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePartCollection_destroy_def)(RT_MutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_destroy_func = reinterpret_cast<RT_MutablePartCollection_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_destroy")));
    
    RT_MutablePartCollection_destroy_func(thisHandle, errorHandler);
}

RT_MutablePartCollectionHandle RT_MutablePartCollection_createWithSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MutablePartCollectionHandle (*RT_MutablePartCollection_createWithSpatialReference_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_createWithSpatialReference_func = reinterpret_cast<RT_MutablePartCollection_createWithSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_createWithSpatialReference")));
    
    return RT_MutablePartCollection_createWithSpatialReference_func(spatialReference, errorHandler);
}

bool RT_MutablePartCollection_getIsEmpty(const RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_MutablePartCollection_getIsEmpty_def)(const RT_MutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_getIsEmpty_func = reinterpret_cast<RT_MutablePartCollection_getIsEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_getIsEmpty")));
    
    return RT_MutablePartCollection_getIsEmpty_func(thisHandle, errorHandler);
}

size_t RT_MutablePartCollection_getSize(const RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePartCollection_getSize_def)(const RT_MutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_getSize_func = reinterpret_cast<RT_MutablePartCollection_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_getSize")));
    
    return RT_MutablePartCollection_getSize_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_MutablePartCollection_getSpatialReference(const RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_MutablePartCollection_getSpatialReference_def)(const RT_MutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_getSpatialReference_func = reinterpret_cast<RT_MutablePartCollection_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_getSpatialReference")));
    
    return RT_MutablePartCollection_getSpatialReference_func(thisHandle, errorHandler);
}

size_t RT_MutablePartCollection_addPart(RT_MutablePartCollectionHandle thisHandle, const RT_MutablePartHandle mutablePart, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePartCollection_addPart_def)(RT_MutablePartCollectionHandle, const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_addPart_func = reinterpret_cast<RT_MutablePartCollection_addPart_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_addPart")));
    
    return RT_MutablePartCollection_addPart_func(thisHandle, mutablePart, errorHandler);
}

RT_MutablePartHandle RT_MutablePartCollection_getPart(const RT_MutablePartCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MutablePartHandle (*RT_MutablePartCollection_getPart_def)(const RT_MutablePartCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_getPart_func = reinterpret_cast<RT_MutablePartCollection_getPart_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_getPart")));
    
    return RT_MutablePartCollection_getPart_func(thisHandle, index, errorHandler);
}

size_t RT_MutablePartCollection_indexOf(const RT_MutablePartCollectionHandle thisHandle, const RT_MutablePartHandle mutablePart, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePartCollection_indexOf_def)(const RT_MutablePartCollectionHandle, const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_indexOf_func = reinterpret_cast<RT_MutablePartCollection_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_indexOf")));
    
    return RT_MutablePartCollection_indexOf_func(thisHandle, mutablePart, errorHandler);
}

void RT_MutablePartCollection_insertPart(RT_MutablePartCollectionHandle thisHandle, size_t index, const RT_MutablePartHandle mutablePart, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePartCollection_insertPart_def)(RT_MutablePartCollectionHandle, size_t, const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_insertPart_func = reinterpret_cast<RT_MutablePartCollection_insertPart_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_insertPart")));
    
    RT_MutablePartCollection_insertPart_func(thisHandle, index, mutablePart, errorHandler);
}

void RT_MutablePartCollection_removeAll(RT_MutablePartCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePartCollection_removeAll_def)(RT_MutablePartCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_removeAll_func = reinterpret_cast<RT_MutablePartCollection_removeAll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_removeAll")));
    
    RT_MutablePartCollection_removeAll_func(thisHandle, errorHandler);
}

void RT_MutablePartCollection_removePart(RT_MutablePartCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePartCollection_removePart_def)(RT_MutablePartCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_removePart_func = reinterpret_cast<RT_MutablePartCollection_removePart_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_removePart")));
    
    RT_MutablePartCollection_removePart_func(thisHandle, index, errorHandler);
}

void RT_MutablePartCollection_setPart(RT_MutablePartCollectionHandle thisHandle, size_t index, const RT_MutablePartHandle mutablePart, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePartCollection_setPart_def)(RT_MutablePartCollectionHandle, size_t, const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePartCollection_setPart_func = reinterpret_cast<RT_MutablePartCollection_setPart_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePartCollection_setPart")));
    
    RT_MutablePartCollection_setPart_func(thisHandle, index, mutablePart, errorHandler);
}
#endif