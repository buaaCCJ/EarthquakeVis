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
#include "ArcGISMapsSDK/CAPI/Platform.h"
#include "ArcGISMapsSDK/CAPI/Standard/MutableArray.h"

void RT_Vector_destroy(RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Vector_destroy_def)(RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_destroy_func = reinterpret_cast<RT_Vector_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_destroy")));
    
    RT_Vector_destroy_func(thisHandle, errorHandler);
}

RT_VectorHandle RT_Vector_create(RT_ElementType valueType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VectorHandle (*RT_Vector_create_def)(RT_ElementType, const RT_ErrorHandler*);
    static auto RT_Vector_create_func = reinterpret_cast<RT_Vector_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_create")));
    
    return RT_Vector_create_func(valueType, errorHandler);
}

size_t RT_Vector_getSize(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Vector_getSize_def)(const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_getSize_func = reinterpret_cast<RT_Vector_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_getSize")));
    
    return RT_Vector_getSize_func(thisHandle, errorHandler);
}

RT_ElementType RT_Vector_getValueType(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementType (*RT_Vector_getValueType_def)(const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_getValueType_func = reinterpret_cast<RT_Vector_getValueType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_getValueType")));
    
    return RT_Vector_getValueType_func(thisHandle, errorHandler);
}

size_t RT_Vector_addArray(RT_VectorHandle thisHandle, const RT_VectorHandle vector2, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Vector_addArray_def)(RT_VectorHandle, const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_addArray_func = reinterpret_cast<RT_Vector_addArray_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_addArray")));
    
    return RT_Vector_addArray_func(thisHandle, vector2, errorHandler);
}

size_t RT_Vector_add(RT_VectorHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Vector_add_def)(RT_VectorHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Vector_add_func = reinterpret_cast<RT_Vector_add_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_add")));
    
    return RT_Vector_add_func(thisHandle, value, errorHandler);
}

RT_ElementHandle RT_Vector_at(const RT_VectorHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Vector_at_def)(const RT_VectorHandle, size_t, const RT_ErrorHandler*);
    static auto RT_Vector_at_func = reinterpret_cast<RT_Vector_at_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_at")));
    
    return RT_Vector_at_func(thisHandle, position, errorHandler);
}

bool RT_Vector_contains(const RT_VectorHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Vector_contains_def)(const RT_VectorHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Vector_contains_func = reinterpret_cast<RT_Vector_contains_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_contains")));
    
    return RT_Vector_contains_func(thisHandle, value, errorHandler);
}

bool RT_Vector_equals(const RT_VectorHandle thisHandle, const RT_VectorHandle vector2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Vector_equals_def)(const RT_VectorHandle, const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_equals_func = reinterpret_cast<RT_Vector_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_equals")));
    
    return RT_Vector_equals_func(thisHandle, vector2, errorHandler);
}

RT_ElementHandle RT_Vector_first(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Vector_first_def)(const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_first_func = reinterpret_cast<RT_Vector_first_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_first")));
    
    return RT_Vector_first_func(thisHandle, errorHandler);
}

size_t RT_Vector_indexOf(const RT_VectorHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Vector_indexOf_def)(const RT_VectorHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Vector_indexOf_func = reinterpret_cast<RT_Vector_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_indexOf")));
    
    return RT_Vector_indexOf_func(thisHandle, value, errorHandler);
}

void RT_Vector_insert(RT_VectorHandle thisHandle, size_t position, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Vector_insert_def)(RT_VectorHandle, size_t, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Vector_insert_func = reinterpret_cast<RT_Vector_insert_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_insert")));
    
    RT_Vector_insert_func(thisHandle, position, value, errorHandler);
}

bool RT_Vector_isEmpty(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Vector_isEmpty_def)(const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_isEmpty_func = reinterpret_cast<RT_Vector_isEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_isEmpty")));
    
    return RT_Vector_isEmpty_func(thisHandle, errorHandler);
}

RT_ElementHandle RT_Vector_last(const RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Vector_last_def)(const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_last_func = reinterpret_cast<RT_Vector_last_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_last")));
    
    return RT_Vector_last_func(thisHandle, errorHandler);
}

void RT_Vector_move(RT_VectorHandle thisHandle, size_t oldPosition, size_t newPosition, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Vector_move_def)(RT_VectorHandle, size_t, size_t, const RT_ErrorHandler*);
    static auto RT_Vector_move_func = reinterpret_cast<RT_Vector_move_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_move")));
    
    RT_Vector_move_func(thisHandle, oldPosition, newPosition, errorHandler);
}

size_t RT_Vector_npos(const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Vector_npos_def)(const RT_ErrorHandler*);
    static auto RT_Vector_npos_func = reinterpret_cast<RT_Vector_npos_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_npos")));
    
    return RT_Vector_npos_func(errorHandler);
}

void RT_Vector_remove(RT_VectorHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Vector_remove_def)(RT_VectorHandle, size_t, const RT_ErrorHandler*);
    static auto RT_Vector_remove_func = reinterpret_cast<RT_Vector_remove_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_remove")));
    
    RT_Vector_remove_func(thisHandle, position, errorHandler);
}

void RT_Vector_removeAll(RT_VectorHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Vector_removeAll_def)(RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_Vector_removeAll_func = reinterpret_cast<RT_Vector_removeAll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_removeAll")));
    
    RT_Vector_removeAll_func(thisHandle, errorHandler);
}

void RT_Vector_setElementAddedCallback(RT_VectorHandle thisHandle, RT_VectorElementAddedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Vector_setElementAddedCallback_def)(RT_VectorHandle, RT_VectorElementAddedEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_Vector_setElementAddedCallback_func = reinterpret_cast<RT_Vector_setElementAddedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_setElementAddedCallback")));
    
    RT_Vector_setElementAddedCallback_func(thisHandle, callback, userData, errorHandler);
}

void RT_Vector_setElementRemovedCallback(RT_VectorHandle thisHandle, RT_VectorElementRemovedEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Vector_setElementRemovedCallback_def)(RT_VectorHandle, RT_VectorElementRemovedEvent_fn, void*, const RT_ErrorHandler*);
    static auto RT_Vector_setElementRemovedCallback_func = reinterpret_cast<RT_Vector_setElementRemovedCallback_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Vector_setElementRemovedCallback")));
    
    RT_Vector_setElementRemovedCallback_func(thisHandle, callback, userData, errorHandler);
}
#endif