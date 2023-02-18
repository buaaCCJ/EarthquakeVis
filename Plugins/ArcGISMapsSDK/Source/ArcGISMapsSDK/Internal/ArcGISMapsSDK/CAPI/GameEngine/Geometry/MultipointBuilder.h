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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MultipointBuilderHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MultipointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePointCollectionHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RT_MultipointBuilder_destroy(RT_MultipointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);

RT_MultipointBuilderHandle RT_MultipointBuilder_createFromMultipoint(const RT_MultipointHandle multipoint, const RT_ErrorHandler* errorHandler);
RT_MultipointBuilderHandle RT_MultipointBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);

RT_MutablePointCollectionHandle RT_MultipointBuilder_getPoints(const RT_MultipointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler);
void RT_MultipointBuilder_setPoints(RT_MultipointBuilderHandle thisHandle, RT_MutablePointCollectionHandle points, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif