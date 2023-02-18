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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerCollection.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GELayerCollection_destroy(RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayerCollection_destroy_def)(RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_destroy_func = reinterpret_cast<RT_GELayerCollection_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_destroy")));
    
    RT_GELayerCollection_destroy_func(thisHandle, errorHandler);
}

RT_GELayerCollectionHandle RT_GELayerCollection_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerCollectionHandle (*RT_GELayerCollection_create_def)(const RT_ErrorHandler*);
    static auto RT_GELayerCollection_create_func = reinterpret_cast<RT_GELayerCollection_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_create")));
    
    return RT_GELayerCollection_create_func(errorHandler);
}

size_t RT_GELayerCollection_getSize(const RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GELayerCollection_getSize_def)(const RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_getSize_func = reinterpret_cast<RT_GELayerCollection_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_getSize")));
    
    return RT_GELayerCollection_getSize_func(thisHandle, errorHandler);
}

size_t RT_GELayerCollection_add(RT_GELayerCollectionHandle thisHandle, const RT_GELayerHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GELayerCollection_add_def)(RT_GELayerCollectionHandle, const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_add_func = reinterpret_cast<RT_GELayerCollection_add_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_add")));
    
    return RT_GELayerCollection_add_func(thisHandle, value, errorHandler);
}

size_t RT_GELayerCollection_addArray(RT_GELayerCollectionHandle thisHandle, const RT_GELayerCollectionHandle vector2, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GELayerCollection_addArray_def)(RT_GELayerCollectionHandle, const RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_addArray_func = reinterpret_cast<RT_GELayerCollection_addArray_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_addArray")));
    
    return RT_GELayerCollection_addArray_func(thisHandle, vector2, errorHandler);
}

RT_GELayerHandle RT_GELayerCollection_at(const RT_GELayerCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerHandle (*RT_GELayerCollection_at_def)(const RT_GELayerCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_at_func = reinterpret_cast<RT_GELayerCollection_at_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_at")));
    
    return RT_GELayerCollection_at_func(thisHandle, position, errorHandler);
}

bool RT_GELayerCollection_contains(const RT_GELayerCollectionHandle thisHandle, const RT_GELayerHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GELayerCollection_contains_def)(const RT_GELayerCollectionHandle, const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_contains_func = reinterpret_cast<RT_GELayerCollection_contains_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_contains")));
    
    return RT_GELayerCollection_contains_func(thisHandle, value, errorHandler);
}

bool RT_GELayerCollection_equals(const RT_GELayerCollectionHandle thisHandle, const RT_GELayerCollectionHandle vector2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GELayerCollection_equals_def)(const RT_GELayerCollectionHandle, const RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_equals_func = reinterpret_cast<RT_GELayerCollection_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_equals")));
    
    return RT_GELayerCollection_equals_func(thisHandle, vector2, errorHandler);
}

RT_GELayerHandle RT_GELayerCollection_first(const RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerHandle (*RT_GELayerCollection_first_def)(const RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_first_func = reinterpret_cast<RT_GELayerCollection_first_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_first")));
    
    return RT_GELayerCollection_first_func(thisHandle, errorHandler);
}

size_t RT_GELayerCollection_indexOf(const RT_GELayerCollectionHandle thisHandle, RT_GELayerHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GELayerCollection_indexOf_def)(const RT_GELayerCollectionHandle, RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_indexOf_func = reinterpret_cast<RT_GELayerCollection_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_indexOf")));
    
    return RT_GELayerCollection_indexOf_func(thisHandle, value, errorHandler);
}

void RT_GELayerCollection_insert(RT_GELayerCollectionHandle thisHandle, size_t position, const RT_GELayerHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayerCollection_insert_def)(RT_GELayerCollectionHandle, size_t, const RT_GELayerHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_insert_func = reinterpret_cast<RT_GELayerCollection_insert_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_insert")));
    
    RT_GELayerCollection_insert_func(thisHandle, position, value, errorHandler);
}

bool RT_GELayerCollection_isEmpty(const RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GELayerCollection_isEmpty_def)(const RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_isEmpty_func = reinterpret_cast<RT_GELayerCollection_isEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_isEmpty")));
    
    return RT_GELayerCollection_isEmpty_func(thisHandle, errorHandler);
}

RT_GELayerHandle RT_GELayerCollection_last(const RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GELayerHandle (*RT_GELayerCollection_last_def)(const RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_last_func = reinterpret_cast<RT_GELayerCollection_last_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_last")));
    
    return RT_GELayerCollection_last_func(thisHandle, errorHandler);
}

void RT_GELayerCollection_move(RT_GELayerCollectionHandle thisHandle, size_t oldPosition, size_t newPosition, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayerCollection_move_def)(RT_GELayerCollectionHandle, size_t, size_t, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_move_func = reinterpret_cast<RT_GELayerCollection_move_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_move")));
    
    RT_GELayerCollection_move_func(thisHandle, oldPosition, newPosition, errorHandler);
}

size_t RT_GELayerCollection_npos(const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GELayerCollection_npos_def)(const RT_ErrorHandler*);
    static auto RT_GELayerCollection_npos_func = reinterpret_cast<RT_GELayerCollection_npos_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_npos")));
    
    return RT_GELayerCollection_npos_func(errorHandler);
}

void RT_GELayerCollection_remove(RT_GELayerCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayerCollection_remove_def)(RT_GELayerCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_remove_func = reinterpret_cast<RT_GELayerCollection_remove_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_remove")));
    
    RT_GELayerCollection_remove_func(thisHandle, position, errorHandler);
}

void RT_GELayerCollection_removeAll(RT_GELayerCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GELayerCollection_removeAll_def)(RT_GELayerCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GELayerCollection_removeAll_func = reinterpret_cast<RT_GELayerCollection_removeAll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GELayerCollection_removeAll")));
    
    RT_GELayerCollection_removeAll_func(thisHandle, errorHandler);
}
#endif