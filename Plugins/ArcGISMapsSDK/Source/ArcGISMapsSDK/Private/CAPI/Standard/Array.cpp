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
#include "ArcGISMapsSDK/CAPI/Standard/Array.h"

void RT_Array_destroy(RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Array_destroy_def)(RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_Array_destroy_func = reinterpret_cast<RT_Array_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_destroy")));
    
    RT_Array_destroy_func(thisHandle, errorHandler);
}

RT_ArrayType RT_Array_getObjectType(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayType (*RT_Array_getObjectType_def)(const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_Array_getObjectType_func = reinterpret_cast<RT_Array_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_getObjectType")));
    
    return RT_Array_getObjectType_func(thisHandle, errorHandler);
}

size_t RT_Array_getSize(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Array_getSize_def)(const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_Array_getSize_func = reinterpret_cast<RT_Array_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_getSize")));
    
    return RT_Array_getSize_func(thisHandle, errorHandler);
}

RT_ElementType RT_Array_getValueType(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementType (*RT_Array_getValueType_def)(const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_Array_getValueType_func = reinterpret_cast<RT_Array_getValueType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_getValueType")));
    
    return RT_Array_getValueType_func(thisHandle, errorHandler);
}

RT_ElementHandle RT_Array_at(const RT_ArrayHandle thisHandle, size_t position, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Array_at_def)(const RT_ArrayHandle, size_t, const RT_ErrorHandler*);
    static auto RT_Array_at_func = reinterpret_cast<RT_Array_at_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_at")));
    
    return RT_Array_at_func(thisHandle, position, errorHandler);
}

bool RT_Array_contains(const RT_ArrayHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Array_contains_def)(const RT_ArrayHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Array_contains_func = reinterpret_cast<RT_Array_contains_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_contains")));
    
    return RT_Array_contains_func(thisHandle, value, errorHandler);
}

RT_ArrayBuilderHandle RT_Array_createBuilder(RT_ElementType valueType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayBuilderHandle (*RT_Array_createBuilder_def)(RT_ElementType, const RT_ErrorHandler*);
    static auto RT_Array_createBuilder_func = reinterpret_cast<RT_Array_createBuilder_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_createBuilder")));
    
    return RT_Array_createBuilder_func(valueType, errorHandler);
}

bool RT_Array_equals(const RT_ArrayHandle thisHandle, const RT_ArrayHandle array2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Array_equals_def)(const RT_ArrayHandle, const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_Array_equals_func = reinterpret_cast<RT_Array_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_equals")));
    
    return RT_Array_equals_func(thisHandle, array2, errorHandler);
}

RT_ElementHandle RT_Array_first(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Array_first_def)(const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_Array_first_func = reinterpret_cast<RT_Array_first_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_first")));
    
    return RT_Array_first_func(thisHandle, errorHandler);
}

size_t RT_Array_indexOf(const RT_ArrayHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Array_indexOf_def)(const RT_ArrayHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Array_indexOf_func = reinterpret_cast<RT_Array_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_indexOf")));
    
    return RT_Array_indexOf_func(thisHandle, value, errorHandler);
}

bool RT_Array_isEmpty(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Array_isEmpty_def)(const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_Array_isEmpty_func = reinterpret_cast<RT_Array_isEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_isEmpty")));
    
    return RT_Array_isEmpty_func(thisHandle, errorHandler);
}

RT_ElementHandle RT_Array_last(const RT_ArrayHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Array_last_def)(const RT_ArrayHandle, const RT_ErrorHandler*);
    static auto RT_Array_last_func = reinterpret_cast<RT_Array_last_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Array_last")));
    
    return RT_Array_last_func(thisHandle, errorHandler);
}
#endif