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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/UnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/UnitType.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_Unit_destroy(RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_StringHandle RT_Unit_getAbbreviation(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_Unit_getDisplayName(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_Unit_getName(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_UnitType RT_Unit_getObjectType(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_Unit_getPluralDisplayName(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler);
int32_t RT_Unit_getUnitId(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler);
int32_t RT_Unit_getWKID(const RT_UnitHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_UnitHandle RT_Unit_fromUnitId(int32_t unitId, const RT_ErrorHandler* errorHandler);
RT_UnitHandle RT_Unit_fromWKID(int32_t WKID, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif