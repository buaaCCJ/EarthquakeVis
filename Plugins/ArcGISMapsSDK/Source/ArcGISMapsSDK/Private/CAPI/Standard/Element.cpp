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
#include "ArcGISMapsSDK/CAPI/Standard/Element.h"

void RT_Element_destroy(RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_destroy_def)(RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_destroy_func = reinterpret_cast<RT_Element_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_destroy")));
    
    RT_Element_destroy_func(thisHandle, errorHandler);
}

RT_ElementHandle RT_Element_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_create_def)(const RT_ErrorHandler*);
    static auto RT_Element_create_func = reinterpret_cast<RT_Element_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_create")));
    
    return RT_Element_create_func(errorHandler);
}

RT_ElementType RT_Element_getObjectType(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementType (*RT_Element_getObjectType_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getObjectType_func = reinterpret_cast<RT_Element_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getObjectType")));
    
    return RT_Element_getObjectType_func(thisHandle, errorHandler);
}

void RT_Element_clear(RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_clear_def)(RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_clear_func = reinterpret_cast<RT_Element_clear_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_clear")));
    
    RT_Element_clear_func(thisHandle, errorHandler);
}

bool RT_Element_equals(const RT_ElementHandle thisHandle, const RT_ElementHandle element2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Element_equals_def)(const RT_ElementHandle, const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_equals_func = reinterpret_cast<RT_Element_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_equals")));
    
    return RT_Element_equals_func(thisHandle, element2, errorHandler);
}

RT_ElementHandle RT_Element_fromAttribute(const RT_AttributeHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromAttribute_def)(const RT_AttributeHandle, const RT_ErrorHandler*);
    static auto RT_Element_fromAttribute_func = reinterpret_cast<RT_Element_fromAttribute_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromAttribute")));
    
    return RT_Element_fromAttribute_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromBool(bool value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromBool_def)(bool, const RT_ErrorHandler*);
    static auto RT_Element_fromBool_func = reinterpret_cast<RT_Element_fromBool_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromBool")));
    
    return RT_Element_fromBool_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromFloat32(float value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromFloat32_def)(float, const RT_ErrorHandler*);
    static auto RT_Element_fromFloat32_func = reinterpret_cast<RT_Element_fromFloat32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromFloat32")));
    
    return RT_Element_fromFloat32_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromFloat64(double value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromFloat64_def)(double, const RT_ErrorHandler*);
    static auto RT_Element_fromFloat64_func = reinterpret_cast<RT_Element_fromFloat64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromFloat64")));
    
    return RT_Element_fromFloat64_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromGEAuthenticationConfiguration(const RT_GEAuthenticationConfigurationHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromGEAuthenticationConfiguration_def)(const RT_GEAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_Element_fromGEAuthenticationConfiguration_func = reinterpret_cast<RT_Element_fromGEAuthenticationConfiguration_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromGEAuthenticationConfiguration")));
    
    return RT_Element_fromGEAuthenticationConfiguration_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromInt16(int16_t value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromInt16_def)(int16_t, const RT_ErrorHandler*);
    static auto RT_Element_fromInt16_func = reinterpret_cast<RT_Element_fromInt16_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromInt16")));
    
    return RT_Element_fromInt16_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromInt32(int32_t value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromInt32_def)(int32_t, const RT_ErrorHandler*);
    static auto RT_Element_fromInt32_func = reinterpret_cast<RT_Element_fromInt32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromInt32")));
    
    return RT_Element_fromInt32_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromInt64(int64_t value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromInt64_def)(int64_t, const RT_ErrorHandler*);
    static auto RT_Element_fromInt64_func = reinterpret_cast<RT_Element_fromInt64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromInt64")));
    
    return RT_Element_fromInt64_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromInt8(int8_t value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromInt8_def)(int8_t, const RT_ErrorHandler*);
    static auto RT_Element_fromInt8_func = reinterpret_cast<RT_Element_fromInt8_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromInt8")));
    
    return RT_Element_fromInt8_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromString(const char* value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromString_def)(const char*, const RT_ErrorHandler*);
    static auto RT_Element_fromString_func = reinterpret_cast<RT_Element_fromString_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromString")));
    
    return RT_Element_fromString_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromUInt16(uint16_t value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromUInt16_def)(uint16_t, const RT_ErrorHandler*);
    static auto RT_Element_fromUInt16_func = reinterpret_cast<RT_Element_fromUInt16_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromUInt16")));
    
    return RT_Element_fromUInt16_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromUInt32(uint32_t value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromUInt32_def)(uint32_t, const RT_ErrorHandler*);
    static auto RT_Element_fromUInt32_func = reinterpret_cast<RT_Element_fromUInt32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromUInt32")));
    
    return RT_Element_fromUInt32_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromUInt64(uint64_t value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromUInt64_def)(uint64_t, const RT_ErrorHandler*);
    static auto RT_Element_fromUInt64_func = reinterpret_cast<RT_Element_fromUInt64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromUInt64")));
    
    return RT_Element_fromUInt64_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromUInt8(uint8_t value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromUInt8_def)(uint8_t, const RT_ErrorHandler*);
    static auto RT_Element_fromUInt8_func = reinterpret_cast<RT_Element_fromUInt8_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromUInt8")));
    
    return RT_Element_fromUInt8_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromVisualizationAttribute(const RT_VisualizationAttributeHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromVisualizationAttribute_def)(const RT_VisualizationAttributeHandle, const RT_ErrorHandler*);
    static auto RT_Element_fromVisualizationAttribute_func = reinterpret_cast<RT_Element_fromVisualizationAttribute_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromVisualizationAttribute")));
    
    return RT_Element_fromVisualizationAttribute_func(value, errorHandler);
}

RT_ElementHandle RT_Element_fromVisualizationAttributeDescription(const RT_VisualizationAttributeDescriptionHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ElementHandle (*RT_Element_fromVisualizationAttributeDescription_def)(const RT_VisualizationAttributeDescriptionHandle, const RT_ErrorHandler*);
    static auto RT_Element_fromVisualizationAttributeDescription_func = reinterpret_cast<RT_Element_fromVisualizationAttributeDescription_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_fromVisualizationAttributeDescription")));
    
    return RT_Element_fromVisualizationAttributeDescription_func(value, errorHandler);
}

RT_AttributeHandle RT_Element_getValueAsAttribute(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AttributeHandle (*RT_Element_getValueAsAttribute_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsAttribute_func = reinterpret_cast<RT_Element_getValueAsAttribute_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsAttribute")));
    
    return RT_Element_getValueAsAttribute_func(thisHandle, errorHandler);
}

bool RT_Element_getValueAsBool(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Element_getValueAsBool_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsBool_func = reinterpret_cast<RT_Element_getValueAsBool_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsBool")));
    
    return RT_Element_getValueAsBool_func(thisHandle, errorHandler);
}

RT_ErrorHandle RT_Element_getValueAsError(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ErrorHandle (*RT_Element_getValueAsError_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsError_func = reinterpret_cast<RT_Element_getValueAsError_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsError")));
    
    return RT_Element_getValueAsError_func(thisHandle, errorHandler);
}

float RT_Element_getValueAsFloat32(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef float (*RT_Element_getValueAsFloat32_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsFloat32_func = reinterpret_cast<RT_Element_getValueAsFloat32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsFloat32")));
    
    return RT_Element_getValueAsFloat32_func(thisHandle, errorHandler);
}

double RT_Element_getValueAsFloat64(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Element_getValueAsFloat64_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsFloat64_func = reinterpret_cast<RT_Element_getValueAsFloat64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsFloat64")));
    
    return RT_Element_getValueAsFloat64_func(thisHandle, errorHandler);
}

RT_GEAuthenticationConfigurationHandle RT_Element_getValueAsGEAuthenticationConfiguration(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GEAuthenticationConfigurationHandle (*RT_Element_getValueAsGEAuthenticationConfiguration_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsGEAuthenticationConfiguration_func = reinterpret_cast<RT_Element_getValueAsGEAuthenticationConfiguration_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsGEAuthenticationConfiguration")));
    
    return RT_Element_getValueAsGEAuthenticationConfiguration_func(thisHandle, errorHandler);
}

int16_t RT_Element_getValueAsInt16(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int16_t (*RT_Element_getValueAsInt16_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsInt16_func = reinterpret_cast<RT_Element_getValueAsInt16_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsInt16")));
    
    return RT_Element_getValueAsInt16_func(thisHandle, errorHandler);
}

int32_t RT_Element_getValueAsInt32(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int32_t (*RT_Element_getValueAsInt32_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsInt32_func = reinterpret_cast<RT_Element_getValueAsInt32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsInt32")));
    
    return RT_Element_getValueAsInt32_func(thisHandle, errorHandler);
}

int64_t RT_Element_getValueAsInt64(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int64_t (*RT_Element_getValueAsInt64_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsInt64_func = reinterpret_cast<RT_Element_getValueAsInt64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsInt64")));
    
    return RT_Element_getValueAsInt64_func(thisHandle, errorHandler);
}

int8_t RT_Element_getValueAsInt8(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int8_t (*RT_Element_getValueAsInt8_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsInt8_func = reinterpret_cast<RT_Element_getValueAsInt8_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsInt8")));
    
    return RT_Element_getValueAsInt8_func(thisHandle, errorHandler);
}

RT_StringHandle RT_Element_getValueAsString(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_Element_getValueAsString_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsString_func = reinterpret_cast<RT_Element_getValueAsString_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsString")));
    
    return RT_Element_getValueAsString_func(thisHandle, errorHandler);
}

uint16_t RT_Element_getValueAsUInt16(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef uint16_t (*RT_Element_getValueAsUInt16_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsUInt16_func = reinterpret_cast<RT_Element_getValueAsUInt16_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsUInt16")));
    
    return RT_Element_getValueAsUInt16_func(thisHandle, errorHandler);
}

uint32_t RT_Element_getValueAsUInt32(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef uint32_t (*RT_Element_getValueAsUInt32_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsUInt32_func = reinterpret_cast<RT_Element_getValueAsUInt32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsUInt32")));
    
    return RT_Element_getValueAsUInt32_func(thisHandle, errorHandler);
}

uint64_t RT_Element_getValueAsUInt64(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef uint64_t (*RT_Element_getValueAsUInt64_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsUInt64_func = reinterpret_cast<RT_Element_getValueAsUInt64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsUInt64")));
    
    return RT_Element_getValueAsUInt64_func(thisHandle, errorHandler);
}

uint8_t RT_Element_getValueAsUInt8(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef uint8_t (*RT_Element_getValueAsUInt8_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsUInt8_func = reinterpret_cast<RT_Element_getValueAsUInt8_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsUInt8")));
    
    return RT_Element_getValueAsUInt8_func(thisHandle, errorHandler);
}

RT_VisualizationAttributeHandle RT_Element_getValueAsVisualizationAttribute(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VisualizationAttributeHandle (*RT_Element_getValueAsVisualizationAttribute_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsVisualizationAttribute_func = reinterpret_cast<RT_Element_getValueAsVisualizationAttribute_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsVisualizationAttribute")));
    
    return RT_Element_getValueAsVisualizationAttribute_func(thisHandle, errorHandler);
}

RT_VisualizationAttributeDescriptionHandle RT_Element_getValueAsVisualizationAttributeDescription(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_VisualizationAttributeDescriptionHandle (*RT_Element_getValueAsVisualizationAttributeDescription_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_getValueAsVisualizationAttributeDescription_func = reinterpret_cast<RT_Element_getValueAsVisualizationAttributeDescription_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_getValueAsVisualizationAttributeDescription")));
    
    return RT_Element_getValueAsVisualizationAttributeDescription_func(thisHandle, errorHandler);
}

bool RT_Element_isEmpty(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Element_isEmpty_def)(const RT_ElementHandle, const RT_ErrorHandler*);
    static auto RT_Element_isEmpty_func = reinterpret_cast<RT_Element_isEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_isEmpty")));
    
    return RT_Element_isEmpty_func(thisHandle, errorHandler);
}

void RT_Element_setValueFromAttribute(RT_ElementHandle thisHandle, const RT_AttributeHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromAttribute_def)(RT_ElementHandle, const RT_AttributeHandle, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromAttribute_func = reinterpret_cast<RT_Element_setValueFromAttribute_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromAttribute")));
    
    RT_Element_setValueFromAttribute_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromBool(RT_ElementHandle thisHandle, bool value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromBool_def)(RT_ElementHandle, bool, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromBool_func = reinterpret_cast<RT_Element_setValueFromBool_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromBool")));
    
    RT_Element_setValueFromBool_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromFloat32(RT_ElementHandle thisHandle, float value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromFloat32_def)(RT_ElementHandle, float, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromFloat32_func = reinterpret_cast<RT_Element_setValueFromFloat32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromFloat32")));
    
    RT_Element_setValueFromFloat32_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromFloat64(RT_ElementHandle thisHandle, double value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromFloat64_def)(RT_ElementHandle, double, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromFloat64_func = reinterpret_cast<RT_Element_setValueFromFloat64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromFloat64")));
    
    RT_Element_setValueFromFloat64_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromGEAuthenticationConfiguration(RT_ElementHandle thisHandle, const RT_GEAuthenticationConfigurationHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromGEAuthenticationConfiguration_def)(RT_ElementHandle, const RT_GEAuthenticationConfigurationHandle, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromGEAuthenticationConfiguration_func = reinterpret_cast<RT_Element_setValueFromGEAuthenticationConfiguration_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromGEAuthenticationConfiguration")));
    
    RT_Element_setValueFromGEAuthenticationConfiguration_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromInt16(RT_ElementHandle thisHandle, int16_t value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromInt16_def)(RT_ElementHandle, int16_t, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromInt16_func = reinterpret_cast<RT_Element_setValueFromInt16_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromInt16")));
    
    RT_Element_setValueFromInt16_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromInt32(RT_ElementHandle thisHandle, int32_t value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromInt32_def)(RT_ElementHandle, int32_t, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromInt32_func = reinterpret_cast<RT_Element_setValueFromInt32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromInt32")));
    
    RT_Element_setValueFromInt32_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromInt64(RT_ElementHandle thisHandle, int64_t value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromInt64_def)(RT_ElementHandle, int64_t, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromInt64_func = reinterpret_cast<RT_Element_setValueFromInt64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromInt64")));
    
    RT_Element_setValueFromInt64_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromInt8(RT_ElementHandle thisHandle, int8_t value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromInt8_def)(RT_ElementHandle, int8_t, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromInt8_func = reinterpret_cast<RT_Element_setValueFromInt8_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromInt8")));
    
    RT_Element_setValueFromInt8_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromString(RT_ElementHandle thisHandle, const char* value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromString_def)(RT_ElementHandle, const char*, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromString_func = reinterpret_cast<RT_Element_setValueFromString_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromString")));
    
    RT_Element_setValueFromString_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromUInt16(RT_ElementHandle thisHandle, uint16_t value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromUInt16_def)(RT_ElementHandle, uint16_t, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromUInt16_func = reinterpret_cast<RT_Element_setValueFromUInt16_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromUInt16")));
    
    RT_Element_setValueFromUInt16_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromUInt32(RT_ElementHandle thisHandle, uint32_t value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromUInt32_def)(RT_ElementHandle, uint32_t, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromUInt32_func = reinterpret_cast<RT_Element_setValueFromUInt32_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromUInt32")));
    
    RT_Element_setValueFromUInt32_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromUInt64(RT_ElementHandle thisHandle, uint64_t value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromUInt64_def)(RT_ElementHandle, uint64_t, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromUInt64_func = reinterpret_cast<RT_Element_setValueFromUInt64_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromUInt64")));
    
    RT_Element_setValueFromUInt64_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromUInt8(RT_ElementHandle thisHandle, uint8_t value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromUInt8_def)(RT_ElementHandle, uint8_t, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromUInt8_func = reinterpret_cast<RT_Element_setValueFromUInt8_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromUInt8")));
    
    RT_Element_setValueFromUInt8_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromVisualizationAttribute(RT_ElementHandle thisHandle, const RT_VisualizationAttributeHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromVisualizationAttribute_def)(RT_ElementHandle, const RT_VisualizationAttributeHandle, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromVisualizationAttribute_func = reinterpret_cast<RT_Element_setValueFromVisualizationAttribute_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromVisualizationAttribute")));
    
    RT_Element_setValueFromVisualizationAttribute_func(thisHandle, value, errorHandler);
}

void RT_Element_setValueFromVisualizationAttributeDescription(RT_ElementHandle thisHandle, const RT_VisualizationAttributeDescriptionHandle value, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Element_setValueFromVisualizationAttributeDescription_def)(RT_ElementHandle, const RT_VisualizationAttributeDescriptionHandle, const RT_ErrorHandler*);
    static auto RT_Element_setValueFromVisualizationAttributeDescription_func = reinterpret_cast<RT_Element_setValueFromVisualizationAttributeDescription_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Element_setValueFromVisualizationAttributeDescription")));
    
    RT_Element_setValueFromVisualizationAttributeDescription_func(thisHandle, value, errorHandler);
}
#endif