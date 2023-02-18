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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpheroidData.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/UnitHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_SpatialReference_destroy(RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_SpatialReferenceHandle RT_SpatialReference_create(int32_t WKID, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_SpatialReference_createVerticalWKID(int32_t WKID, int32_t verticalWKID, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_SpatialReference_createFromWKText(const char* wkText, const RT_ErrorHandler* errorHandler);

RT_SpatialReferenceHandle RT_SpatialReference_getBaseGeographic(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_SpatialReference_getFullWorldExtent(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_SpatialReference_getHasVertical(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_SpatialReference_getIsGeographic(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_SpatialReference_getIsPannable(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
bool RT_SpatialReference_getIsProjected(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpheroidData RT_SpatialReference_getSpheroidData(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_UnitHandle RT_SpatialReference_getUnit(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_LinearUnitHandle RT_SpatialReference_getVerticalUnit(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
int32_t RT_SpatialReference_getVerticalWKID(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
int32_t RT_SpatialReference_getWKID(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_SpatialReference_getWKText(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);

bool RT_SpatialReference_equals(const RT_SpatialReferenceHandle thisHandle, const RT_SpatialReferenceHandle right, const RT_ErrorHandler* errorHandler);
double RT_SpatialReference_getConvergenceAngle(const RT_SpatialReferenceHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
size_t RT_SpatialReference_getHash(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_SpatialReference_webMercator(const RT_ErrorHandler* errorHandler);
RT_SpatialReferenceHandle RT_SpatialReference_WGS84(const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif