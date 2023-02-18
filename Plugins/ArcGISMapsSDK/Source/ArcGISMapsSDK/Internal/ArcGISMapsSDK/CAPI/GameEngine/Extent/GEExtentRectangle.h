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

#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtentRectangleHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_GEExtentRectangle_destroy(RT_GEExtentRectangleHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_GEExtentRectangleHandle RT_GEExtentRectangle_create(const RT_PointHandle center, double width, double height, const RT_ErrorHandler* errorHandler);

double RT_GEExtentRectangle_getHeight(const RT_GEExtentRectangleHandle thisHandle, const RT_ErrorHandler* errorHandler);
double RT_GEExtentRectangle_getWidth(const RT_GEExtentRectangleHandle thisHandle, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif