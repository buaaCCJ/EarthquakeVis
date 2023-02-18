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
#include "ArcGISMapsSDK/CAPI/Standard/Dictionary.h"

void RT_Dictionary_destroy(RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Dictionary_destroy_def)(RT_DictionaryHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_destroy_func = reinterpret_cast<RT_Dictionary_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_destroy")));
    
    RT_Dictionary_destroy_func(thisHandle, errorHandler);
}

RT_DictionaryHandle RT_Dictionary_create(RT_ElementType keyType, RT_ElementType valueType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DictionaryHandle (*RT_Dictionary_create_def)(RT_ElementType, RT_ElementType, const RT_ErrorHandler*);
    static auto RT_Dictionary_create_func = reinterpret_cast<RT_Dictionary_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_create")));
    
    return RT_Dictionary_create_func(keyType, valueType, errorHandler);
}

RT_ElementType RT_Dictionary_getKeyType(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementType (*RT_Dictionary_getKeyType_def)(const RT_DictionaryHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_getKeyType_func = reinterpret_cast<RT_Dictionary_getKeyType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_getKeyType")));
    
    return RT_Dictionary_getKeyType_func(thisHandle, errorHandler);
}

size_t RT_Dictionary_getSize(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Dictionary_getSize_def)(const RT_DictionaryHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_getSize_func = reinterpret_cast<RT_Dictionary_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_getSize")));
    
    return RT_Dictionary_getSize_func(thisHandle, errorHandler);
}

RT_ElementType RT_Dictionary_getValueType(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementType (*RT_Dictionary_getValueType_def)(const RT_DictionaryHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_getValueType_func = reinterpret_cast<RT_Dictionary_getValueType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_getValueType")));
    
    return RT_Dictionary_getValueType_func(thisHandle, errorHandler);
}

RT_ElementHandle RT_Dictionary_at(const RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Dictionary_at_def)(const RT_DictionaryHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_at_func = reinterpret_cast<RT_Dictionary_at_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_at")));
    
    return RT_Dictionary_at_func(thisHandle, key, errorHandler);
}

bool RT_Dictionary_contains(const RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Dictionary_contains_def)(const RT_DictionaryHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_contains_func = reinterpret_cast<RT_Dictionary_contains_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_contains")));
    
    return RT_Dictionary_contains_func(thisHandle, key, errorHandler);
}

bool RT_Dictionary_equals(const RT_DictionaryHandle thisHandle, const RT_DictionaryHandle dictionary2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Dictionary_equals_def)(const RT_DictionaryHandle, const RT_DictionaryHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_equals_func = reinterpret_cast<RT_Dictionary_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_equals")));
    
    return RT_Dictionary_equals_func(thisHandle, dictionary2, errorHandler);
}

RT_ElementType RT_Dictionary_getTypeForKey(const RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementType (*RT_Dictionary_getTypeForKey_def)(const RT_DictionaryHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_getTypeForKey_func = reinterpret_cast<RT_Dictionary_getTypeForKey_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_getTypeForKey")));
    
    return RT_Dictionary_getTypeForKey_func(thisHandle, key, errorHandler);
}

void RT_Dictionary_insert(RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Dictionary_insert_def)(RT_DictionaryHandle, const RT_ElementHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_insert_func = reinterpret_cast<RT_Dictionary_insert_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_insert")));
    
    RT_Dictionary_insert_func(thisHandle, key, value, errorHandler);
}

bool RT_Dictionary_isEmpty(const RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Dictionary_isEmpty_def)(const RT_DictionaryHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_isEmpty_func = reinterpret_cast<RT_Dictionary_isEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_isEmpty")));
    
    return RT_Dictionary_isEmpty_func(thisHandle, errorHandler);
}

void RT_Dictionary_remove(RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Dictionary_remove_def)(RT_DictionaryHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_remove_func = reinterpret_cast<RT_Dictionary_remove_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_remove")));
    
    RT_Dictionary_remove_func(thisHandle, key, errorHandler);
}

void RT_Dictionary_removeAll(RT_DictionaryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Dictionary_removeAll_def)(RT_DictionaryHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_removeAll_func = reinterpret_cast<RT_Dictionary_removeAll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_removeAll")));
    
    RT_Dictionary_removeAll_func(thisHandle, errorHandler);
}

void RT_Dictionary_replace(RT_DictionaryHandle thisHandle, const RT_ElementHandle key, const RT_ElementHandle newValue, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Dictionary_replace_def)(RT_DictionaryHandle, const RT_ElementHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Dictionary_replace_func = reinterpret_cast<RT_Dictionary_replace_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Dictionary_replace")));
    
    RT_Dictionary_replace_func(thisHandle, key, newValue, errorHandler);
}
#endif