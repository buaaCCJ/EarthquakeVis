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
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSourceCollection.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GEElevationSourceCollection_destroy(RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSourceCollection_destroy_def)(RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_destroy_func = reinterpret_cast<RT_GEElevationSourceCollection_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_destroy")));
    
    RT_GEElevationSourceCollection_destroy_func(thisHandle, errorHandler);
}

RT_GEElevationSourceCollectionHandle RT_GEElevationSourceCollection_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceCollectionHandle (*RT_GEElevationSourceCollection_create_def)(const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_create_func = reinterpret_cast<RT_GEElevationSourceCollection_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_create")));
    
    return RT_GEElevationSourceCollection_create_func(errorHandler);
}

size_t RT_GEElevationSourceCollection_getSize(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GEElevationSourceCollection_getSize_def)(const RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_getSize_func = reinterpret_cast<RT_GEElevationSourceCollection_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_getSize")));
    
    return RT_GEElevationSourceCollection_getSize_func(thisHandle, errorHandler);
}

size_t RT_GEElevationSourceCollection_add(RT_GEElevationSourceCollectionHandle thisHandle, const RT_GEElevationSourceHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GEElevationSourceCollection_add_def)(RT_GEElevationSourceCollectionHandle, const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_add_func = reinterpret_cast<RT_GEElevationSourceCollection_add_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_add")));
    
    return RT_GEElevationSourceCollection_add_func(thisHandle, value, errorHandler);
}

size_t RT_GEElevationSourceCollection_addArray(RT_GEElevationSourceCollectionHandle thisHandle, const RT_GEElevationSourceCollectionHandle vector2, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GEElevationSourceCollection_addArray_def)(RT_GEElevationSourceCollectionHandle, const RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_addArray_func = reinterpret_cast<RT_GEElevationSourceCollection_addArray_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_addArray")));
    
    return RT_GEElevationSourceCollection_addArray_func(thisHandle, vector2, errorHandler);
}

RT_GEElevationSourceHandle RT_GEElevationSourceCollection_at(const RT_GEElevationSourceCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceHandle (*RT_GEElevationSourceCollection_at_def)(const RT_GEElevationSourceCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_at_func = reinterpret_cast<RT_GEElevationSourceCollection_at_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_at")));
    
    return RT_GEElevationSourceCollection_at_func(thisHandle, position, errorHandler);
}

bool RT_GEElevationSourceCollection_contains(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_GEElevationSourceHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GEElevationSourceCollection_contains_def)(const RT_GEElevationSourceCollectionHandle, const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_contains_func = reinterpret_cast<RT_GEElevationSourceCollection_contains_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_contains")));
    
    return RT_GEElevationSourceCollection_contains_func(thisHandle, value, errorHandler);
}

bool RT_GEElevationSourceCollection_equals(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_GEElevationSourceCollectionHandle vector2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GEElevationSourceCollection_equals_def)(const RT_GEElevationSourceCollectionHandle, const RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_equals_func = reinterpret_cast<RT_GEElevationSourceCollection_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_equals")));
    
    return RT_GEElevationSourceCollection_equals_func(thisHandle, vector2, errorHandler);
}

RT_GEElevationSourceHandle RT_GEElevationSourceCollection_first(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceHandle (*RT_GEElevationSourceCollection_first_def)(const RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_first_func = reinterpret_cast<RT_GEElevationSourceCollection_first_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_first")));
    
    return RT_GEElevationSourceCollection_first_func(thisHandle, errorHandler);
}

size_t RT_GEElevationSourceCollection_indexOf(const RT_GEElevationSourceCollectionHandle thisHandle, RT_GEElevationSourceHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GEElevationSourceCollection_indexOf_def)(const RT_GEElevationSourceCollectionHandle, RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_indexOf_func = reinterpret_cast<RT_GEElevationSourceCollection_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_indexOf")));
    
    return RT_GEElevationSourceCollection_indexOf_func(thisHandle, value, errorHandler);
}

void RT_GEElevationSourceCollection_insert(RT_GEElevationSourceCollectionHandle thisHandle, size_t position, const RT_GEElevationSourceHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSourceCollection_insert_def)(RT_GEElevationSourceCollectionHandle, size_t, const RT_GEElevationSourceHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_insert_func = reinterpret_cast<RT_GEElevationSourceCollection_insert_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_insert")));
    
    RT_GEElevationSourceCollection_insert_func(thisHandle, position, value, errorHandler);
}

bool RT_GEElevationSourceCollection_isEmpty(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GEElevationSourceCollection_isEmpty_def)(const RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_isEmpty_func = reinterpret_cast<RT_GEElevationSourceCollection_isEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_isEmpty")));
    
    return RT_GEElevationSourceCollection_isEmpty_func(thisHandle, errorHandler);
}

RT_GEElevationSourceHandle RT_GEElevationSourceCollection_last(const RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEElevationSourceHandle (*RT_GEElevationSourceCollection_last_def)(const RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_last_func = reinterpret_cast<RT_GEElevationSourceCollection_last_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_last")));
    
    return RT_GEElevationSourceCollection_last_func(thisHandle, errorHandler);
}

void RT_GEElevationSourceCollection_move(RT_GEElevationSourceCollectionHandle thisHandle, size_t oldPosition, size_t newPosition, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSourceCollection_move_def)(RT_GEElevationSourceCollectionHandle, size_t, size_t, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_move_func = reinterpret_cast<RT_GEElevationSourceCollection_move_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_move")));
    
    RT_GEElevationSourceCollection_move_func(thisHandle, oldPosition, newPosition, errorHandler);
}

size_t RT_GEElevationSourceCollection_npos(const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_GEElevationSourceCollection_npos_def)(const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_npos_func = reinterpret_cast<RT_GEElevationSourceCollection_npos_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_npos")));
    
    return RT_GEElevationSourceCollection_npos_func(errorHandler);
}

void RT_GEElevationSourceCollection_remove(RT_GEElevationSourceCollectionHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSourceCollection_remove_def)(RT_GEElevationSourceCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_remove_func = reinterpret_cast<RT_GEElevationSourceCollection_remove_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_remove")));
    
    RT_GEElevationSourceCollection_remove_func(thisHandle, position, errorHandler);
}

void RT_GEElevationSourceCollection_removeAll(RT_GEElevationSourceCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GEElevationSourceCollection_removeAll_def)(RT_GEElevationSourceCollectionHandle, const RT_ErrorHandler*);
    static auto RT_GEElevationSourceCollection_removeAll_func = reinterpret_cast<RT_GEElevationSourceCollection_removeAll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GEElevationSourceCollection_removeAll")));
    
    RT_GEElevationSourceCollection_removeAll_func(thisHandle, errorHandler);
}
#endif