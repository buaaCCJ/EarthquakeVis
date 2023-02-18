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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/DatumTransformationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/TransformationCatalogHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

RT_StringHandle RT_TransformationCatalog_getProjectionEngineDirectory(const RT_ErrorHandler* errorHandler);
void RT_TransformationCatalog_setProjectionEngineDirectory(char* projectionEngineDirectory, const RT_ErrorHandler* errorHandler);

RT_DatumTransformationHandle RT_TransformationCatalog_getTransformation(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_ErrorHandler* errorHandler);
RT_DatumTransformationHandle RT_TransformationCatalog_getTransformationWithAreaOfInterest(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_EnvelopeHandle areaOfInterest, const RT_ErrorHandler* errorHandler);
RT_DatumTransformationHandle RT_TransformationCatalog_getTransformationWithAreaOfInterestAndIgnoreVertical(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_EnvelopeHandle areaOfInterest, bool ignoreVertical, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_TransformationCatalog_getTransformationsBySuitability(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterest(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_EnvelopeHandle areaOfInterest, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterestAndIgnoreVertical(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_EnvelopeHandle areaOfInterest, bool ignoreVertical, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif