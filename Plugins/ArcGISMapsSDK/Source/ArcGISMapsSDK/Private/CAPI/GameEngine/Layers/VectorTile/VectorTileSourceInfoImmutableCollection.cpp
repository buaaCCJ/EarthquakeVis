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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileSourceInfoImmutableCollection.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_VectorTileSourceInfoImmutableCollection_destroy(RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_VectorTileSourceInfoImmutableCollection_destroy_def)(RT_VectorTileSourceInfoImmutableCollectionHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_destroy_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_destroy")));
    
    RT_VectorTileSourceInfoImmutableCollection_destroy_func(thisHandle, errorHandler);
}

size_t RT_VectorTileSourceInfoImmutableCollection_getSize(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_VectorTileSourceInfoImmutableCollection_getSize_def)(const RT_VectorTileSourceInfoImmutableCollectionHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_getSize_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_getSize")));
    
    return RT_VectorTileSourceInfoImmutableCollection_getSize_func(thisHandle, errorHandler);
}

RT_VectorTileSourceInfoHandle RT_VectorTileSourceInfoImmutableCollection_at(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VectorTileSourceInfoHandle (*RT_VectorTileSourceInfoImmutableCollection_at_def)(const RT_VectorTileSourceInfoImmutableCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_at_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_at_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_at")));
    
    return RT_VectorTileSourceInfoImmutableCollection_at_func(thisHandle, position, errorHandler);
}

bool RT_VectorTileSourceInfoImmutableCollection_contains(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_VectorTileSourceInfoHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_VectorTileSourceInfoImmutableCollection_contains_def)(const RT_VectorTileSourceInfoImmutableCollectionHandle, const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_contains_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_contains_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_contains")));
    
    return RT_VectorTileSourceInfoImmutableCollection_contains_func(thisHandle, value, errorHandler);
}

bool RT_VectorTileSourceInfoImmutableCollection_equals(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_VectorTileSourceInfoImmutableCollectionHandle vector2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_VectorTileSourceInfoImmutableCollection_equals_def)(const RT_VectorTileSourceInfoImmutableCollectionHandle, const RT_VectorTileSourceInfoImmutableCollectionHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_equals_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_equals")));
    
    return RT_VectorTileSourceInfoImmutableCollection_equals_func(thisHandle, vector2, errorHandler);
}

RT_VectorTileSourceInfoHandle RT_VectorTileSourceInfoImmutableCollection_first(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VectorTileSourceInfoHandle (*RT_VectorTileSourceInfoImmutableCollection_first_def)(const RT_VectorTileSourceInfoImmutableCollectionHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_first_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_first_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_first")));
    
    return RT_VectorTileSourceInfoImmutableCollection_first_func(thisHandle, errorHandler);
}

size_t RT_VectorTileSourceInfoImmutableCollection_indexOf(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, RT_VectorTileSourceInfoHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_VectorTileSourceInfoImmutableCollection_indexOf_def)(const RT_VectorTileSourceInfoImmutableCollectionHandle, RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_indexOf_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_indexOf")));
    
    return RT_VectorTileSourceInfoImmutableCollection_indexOf_func(thisHandle, value, errorHandler);
}

bool RT_VectorTileSourceInfoImmutableCollection_isEmpty(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_VectorTileSourceInfoImmutableCollection_isEmpty_def)(const RT_VectorTileSourceInfoImmutableCollectionHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_isEmpty_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_isEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_isEmpty")));
    
    return RT_VectorTileSourceInfoImmutableCollection_isEmpty_func(thisHandle, errorHandler);
}

RT_VectorTileSourceInfoHandle RT_VectorTileSourceInfoImmutableCollection_last(const RT_VectorTileSourceInfoImmutableCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VectorTileSourceInfoHandle (*RT_VectorTileSourceInfoImmutableCollection_last_def)(const RT_VectorTileSourceInfoImmutableCollectionHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_last_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_last_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_last")));
    
    return RT_VectorTileSourceInfoImmutableCollection_last_func(thisHandle, errorHandler);
}

size_t RT_VectorTileSourceInfoImmutableCollection_npos(const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_VectorTileSourceInfoImmutableCollection_npos_def)(const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfoImmutableCollection_npos_func = reinterpret_cast<RT_VectorTileSourceInfoImmutableCollection_npos_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfoImmutableCollection_npos")));
    
    return RT_VectorTileSourceInfoImmutableCollection_npos_func(errorHandler);
}
#endif