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

#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AngularUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AreaUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/DatumTransformationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodesicEllipseParametersHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodesicSectorParametersHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodeticCurveType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodeticDistanceResultHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryEngineHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryExtendOptions.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryOffsetType.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnitHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MultipartHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PolygonHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PolylineHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ProximityResultHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReferenceHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/MutableArrayHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

double RT_GeometryEngine_area(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
double RT_GeometryEngine_areaGeodetic(const RT_GeometryHandle geometry, const RT_AreaUnitHandle unit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_GeometryEngine_autoComplete(const RT_VectorHandle existingBoundaries, const RT_VectorHandle newBoundaries, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_boundary(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_PolygonHandle RT_GeometryEngine_buffer(const RT_GeometryHandle geometry, double distance, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_GeometryEngine_bufferCollection(const RT_VectorHandle geometries, const RT_VectorHandle distances, bool unionResult, const RT_ErrorHandler* errorHandler);
RT_PolygonHandle RT_GeometryEngine_bufferGeodetic(const RT_GeometryHandle geometry, double distance, const RT_LinearUnitHandle distanceUnit, double maxDeviation, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_GeometryEngine_bufferGeodeticCollection(const RT_VectorHandle geometries, const RT_VectorHandle distances, const RT_LinearUnitHandle distanceUnit, double maxDeviation, RT_GeodeticCurveType curveType, bool unionResult, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_clip(const RT_GeometryHandle geometry, const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_GeometryEngine_combineExtents(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_EnvelopeHandle RT_GeometryEngine_combineExtentsCollection(const RT_VectorHandle geometries, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_contains(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_convexHull(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_GeometryEngine_convexHullCollection(const RT_VectorHandle geometries, bool merge, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_GeometryEngine_createPointAlong(const RT_PolylineHandle polyline, double distance, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_crosses(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_GeometryEngine_cut(const RT_GeometryHandle geometry, const RT_PolylineHandle cutter, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_densify(const RT_GeometryHandle geometry, double maxSegmentLength, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_densifyGeodetic(const RT_GeometryHandle geometry, double maxSegmentLength, const RT_LinearUnitHandle lengthUnit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_difference(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_disjoint(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
double RT_GeometryEngine_distance(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_GeodeticDistanceResultHandle RT_GeometryEngine_distanceGeodetic(const RT_PointHandle point1, const RT_PointHandle point2, const RT_LinearUnitHandle distanceUnit, const RT_AngularUnitHandle azimuthUnit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_ellipseGeodesic(const RT_GeodesicEllipseParametersHandle parameters, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_equals(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_PolylineHandle RT_GeometryEngine_extend(const RT_PolylineHandle polyline, const RT_PolylineHandle extender, RT_GeometryExtendOptions extendOptions, const RT_ErrorHandler* errorHandler);
double RT_GeometryEngine_fractionAlong(const RT_PolylineHandle line, const RT_PointHandle point, double tolerance, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_generalize(const RT_GeometryHandle geometry, double maxDeviation, bool removeDegenerateParts, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_intersection(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_GeometryEngine_intersections(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_intersects(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_isSimple(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_PointHandle RT_GeometryEngine_labelPoint(const RT_PolygonHandle polygon, const RT_ErrorHandler* errorHandler);
double RT_GeometryEngine_length(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
double RT_GeometryEngine_lengthGeodetic(const RT_GeometryHandle geometry, const RT_LinearUnitHandle lengthUnit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler);
RT_ArrayHandle RT_GeometryEngine_moveGeodetic(const RT_VectorHandle pointCollection, double distance, const RT_LinearUnitHandle distanceUnit, double azimuth, const RT_AngularUnitHandle azimuthUnit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler);
RT_ProximityResultHandle RT_GeometryEngine_nearestCoordinate(const RT_GeometryHandle geometry, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
RT_ProximityResultHandle RT_GeometryEngine_nearestCoordinateGeodetic(const RT_GeometryHandle geometry, const RT_PointHandle point, double maxDeviation, const RT_LinearUnitHandle deviationUnit, const RT_ErrorHandler* errorHandler);
RT_ProximityResultHandle RT_GeometryEngine_nearestVertex(const RT_GeometryHandle geometry, const RT_PointHandle point, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_normalizeCentralMeridian(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_offset(const RT_GeometryHandle geometry, double distance, RT_GeometryOffsetType offsetType, double bevelRatio, double flattenError, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_overlaps(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_project(const RT_GeometryHandle geometry, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_projectWithTransformation(const RT_GeometryHandle geometry, const RT_SpatialReferenceHandle outputSpatialReference, const RT_DatumTransformationHandle datumTransformation, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_relate(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const char* relation, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_removeM(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_removeZ(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_removeZAndM(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_MultipartHandle RT_GeometryEngine_reshape(const RT_MultipartHandle geometry, const RT_PolylineHandle reshaper, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_sectorGeodesic(const RT_GeodesicSectorParametersHandle parameters, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_setM(const RT_GeometryHandle geometry, double m, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_setZ(const RT_GeometryHandle geometry, double z, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_setZAndM(const RT_GeometryHandle geometry, double z, double m, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_simplify(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_symmetricDifference(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_touches(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_union(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);
RT_GeometryHandle RT_GeometryEngine_unionCollection(const RT_VectorHandle geometries, const RT_ErrorHandler* errorHandler);
bool RT_GeometryEngine_within(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif