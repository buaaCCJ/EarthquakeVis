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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MultipartBuilderHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePartCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_MultipartBuilder_destroy(RT_MultipartBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_MutablePartCollectionHandle RT_MultipartBuilder_getParts(const RT_MultipartBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_MultipartBuilder_setParts(RT_MultipartBuilderHandle thisHandle, RT_MutablePartCollectionHandle parts, const RT_ErrorHandler* errorHandler);

size_t RT_MultipartBuilder_addPointXY(RT_MultipartBuilderHandle thisHandle, double x, double y, const RT_ErrorHandler* errorHandler);
size_t RT_MultipartBuilder_addPointXYZ(RT_MultipartBuilderHandle thisHandle, double x, double y, double z, const RT_ErrorHandler* errorHandler);
size_t RT_MultipartBuilder_addPoint(RT_MultipartBuilderHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif