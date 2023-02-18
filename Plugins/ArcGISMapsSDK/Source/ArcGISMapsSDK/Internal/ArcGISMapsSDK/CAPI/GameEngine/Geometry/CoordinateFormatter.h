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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/CoordinateFormatterHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GARSConversionMode.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LatitudeLongitudeFormat.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MGRSConversionMode.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/UTMConversionMode.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

RT_PointHandle RT_CoordinateFormatter_fromGARS(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, RT_GARSConversionMode GARSConversionMode, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_CoordinateFormatter_fromGeoRef(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_CoordinateFormatter_fromLatitudeLongitude(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_CoordinateFormatter_fromMGRS(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, RT_MGRSConversionMode MGRSConversionMode, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_CoordinateFormatter_fromUSNG(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_CoordinateFormatter_fromUTM(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, RT_UTMConversionMode UTMConversionMode, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_CoordinateFormatter_toGARS(const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_CoordinateFormatter_toGeoRef(const RT_PointHandle point, int32_t precision, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_CoordinateFormatter_toLatitudeLongitude(const RT_PointHandle point, RT_LatitudeLongitudeFormat format, int32_t decimalPlaces, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_CoordinateFormatter_toMGRS(const RT_PointHandle point, RT_MGRSConversionMode MGRSConversionMode, int32_t precision, bool addSpaces, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_CoordinateFormatter_toUSNG(const RT_PointHandle point, int32_t precision, bool addSpaces, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_CoordinateFormatter_toUTM(const RT_PointHandle point, RT_UTMConversionMode UTMConversionMode, bool addSpaces, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif