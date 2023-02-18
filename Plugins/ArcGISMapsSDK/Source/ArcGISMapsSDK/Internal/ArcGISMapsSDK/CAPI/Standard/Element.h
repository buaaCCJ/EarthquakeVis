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
#pragma once

#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/AttributeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/VisualizationAttributeDescriptionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/VisualizationAttributeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationConfigurationHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ElementType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Element_destroy(RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_ElementHandle RT_Element_create(const RT_ErrorHandler* errorHandler);

RT_ElementType RT_Element_getObjectType(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);

void RT_Element_clear(RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Element_equals(const RT_ElementHandle thisHandle, const RT_ElementHandle element2, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromAttribute(const RT_AttributeHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromBool(bool value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromFloat32(float value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromFloat64(double value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromGEAuthenticationConfiguration(const RT_GEAuthenticationConfigurationHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromInt16(int16_t value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromInt32(int32_t value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromInt64(int64_t value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromInt8(int8_t value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromString(const char* value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromUInt16(uint16_t value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromUInt32(uint32_t value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromUInt64(uint64_t value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromUInt8(uint8_t value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromVisualizationAttribute(const RT_VisualizationAttributeHandle value, const RT_ErrorHandler* errorHandler);
RT_ElementHandle RT_Element_fromVisualizationAttributeDescription(const RT_VisualizationAttributeDescriptionHandle value, const RT_ErrorHandler* errorHandler);
RT_AttributeHandle RT_Element_getValueAsAttribute(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Element_getValueAsBool(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_ErrorHandle RT_Element_getValueAsError(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
float RT_Element_getValueAsFloat32(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_Element_getValueAsFloat64(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_GEAuthenticationConfigurationHandle RT_Element_getValueAsGEAuthenticationConfiguration(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
int16_t RT_Element_getValueAsInt16(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
int32_t RT_Element_getValueAsInt32(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
int64_t RT_Element_getValueAsInt64(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
int8_t RT_Element_getValueAsInt8(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_Element_getValueAsString(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
uint16_t RT_Element_getValueAsUInt16(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
uint32_t RT_Element_getValueAsUInt32(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
uint64_t RT_Element_getValueAsUInt64(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
uint8_t RT_Element_getValueAsUInt8(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_VisualizationAttributeHandle RT_Element_getValueAsVisualizationAttribute(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_VisualizationAttributeDescriptionHandle RT_Element_getValueAsVisualizationAttributeDescription(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_Element_isEmpty(const RT_ElementHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromAttribute(RT_ElementHandle thisHandle, const RT_AttributeHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromBool(RT_ElementHandle thisHandle, bool value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromFloat32(RT_ElementHandle thisHandle, float value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromFloat64(RT_ElementHandle thisHandle, double value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromGEAuthenticationConfiguration(RT_ElementHandle thisHandle, const RT_GEAuthenticationConfigurationHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromInt16(RT_ElementHandle thisHandle, int16_t value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromInt32(RT_ElementHandle thisHandle, int32_t value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromInt64(RT_ElementHandle thisHandle, int64_t value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromInt8(RT_ElementHandle thisHandle, int8_t value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromString(RT_ElementHandle thisHandle, const char* value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromUInt16(RT_ElementHandle thisHandle, uint16_t value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromUInt32(RT_ElementHandle thisHandle, uint32_t value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromUInt64(RT_ElementHandle thisHandle, uint64_t value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromUInt8(RT_ElementHandle thisHandle, uint8_t value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromVisualizationAttribute(RT_ElementHandle thisHandle, const RT_VisualizationAttributeHandle value, const RT_ErrorHandler* errorHandler);
void RT_Element_setValueFromVisualizationAttributeDescription(RT_ElementHandle thisHandle, const RT_VisualizationAttributeDescriptionHandle value, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif