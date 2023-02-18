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
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/Attribute.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Attribute_destroy(RT_AttributeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Attribute_destroy_def)(RT_AttributeHandle, const RT_ErrorHandler*);
    static auto RT_Attribute_destroy_func = reinterpret_cast<RT_Attribute_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Attribute_destroy")));
    
    RT_Attribute_destroy_func(thisHandle, errorHandler);
}

RT_AttributeType RT_Attribute_getAttributeType(const RT_AttributeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AttributeType (*RT_Attribute_getAttributeType_def)(const RT_AttributeHandle, const RT_ErrorHandler*);
    static auto RT_Attribute_getAttributeType_func = reinterpret_cast<RT_Attribute_getAttributeType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Attribute_getAttributeType")));
    
    return RT_Attribute_getAttributeType_func(thisHandle, errorHandler);
}

RT_ByteArray RT_Attribute_getData(const RT_AttributeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ByteArray (*RT_Attribute_getData_def)(const RT_AttributeHandle, const RT_ErrorHandler*);
    static auto RT_Attribute_getData_func = reinterpret_cast<RT_Attribute_getData_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Attribute_getData")));
    
    return RT_Attribute_getData_func(thisHandle, errorHandler);
}

RT_StringHandle RT_Attribute_getName(const RT_AttributeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_Attribute_getName_def)(const RT_AttributeHandle, const RT_ErrorHandler*);
    static auto RT_Attribute_getName_func = reinterpret_cast<RT_Attribute_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Attribute_getName")));
    
    return RT_Attribute_getName_func(thisHandle, errorHandler);
}
#endif