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
#include "ArcGISMapsSDK/CAPI/Standard/ArrayBuilder.h"

void RT_ArrayBuilder_destroy(RT_ArrayBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArrayBuilder_destroy_def)(RT_ArrayBuilderHandle, const RT_ErrorHandler*);
    static auto RT_ArrayBuilder_destroy_func = reinterpret_cast<RT_ArrayBuilder_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArrayBuilder_destroy")));
    
    RT_ArrayBuilder_destroy_func(thisHandle, errorHandler);
}

RT_ElementType RT_ArrayBuilder_getValueType(const RT_ArrayBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementType (*RT_ArrayBuilder_getValueType_def)(const RT_ArrayBuilderHandle, const RT_ErrorHandler*);
    static auto RT_ArrayBuilder_getValueType_func = reinterpret_cast<RT_ArrayBuilder_getValueType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArrayBuilder_getValueType")));
    
    return RT_ArrayBuilder_getValueType_func(thisHandle, errorHandler);
}

void RT_ArrayBuilder_add(RT_ArrayBuilderHandle thisHandle, const RT_ElementHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ArrayBuilder_add_def)(RT_ArrayBuilderHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_ArrayBuilder_add_func = reinterpret_cast<RT_ArrayBuilder_add_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArrayBuilder_add")));
    
    RT_ArrayBuilder_add_func(thisHandle, value, errorHandler);
}

RT_ArrayHandle RT_ArrayBuilder_moveToArray(RT_ArrayBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_ArrayBuilder_moveToArray_def)(RT_ArrayBuilderHandle, const RT_ErrorHandler*);
    static auto RT_ArrayBuilder_moveToArray_func = reinterpret_cast<RT_ArrayBuilder_moveToArray_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ArrayBuilder_moveToArray")));
    
    return RT_ArrayBuilder_moveToArray_func(thisHandle, errorHandler);
}
#endif