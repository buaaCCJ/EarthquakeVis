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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryEngine.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

double RT_GeometryEngine_area(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeometryEngine_area_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_area_func = reinterpret_cast<RT_GeometryEngine_area_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_area")));
    
    return RT_GeometryEngine_area_func(geometry, errorHandler);
}

double RT_GeometryEngine_areaGeodetic(const RT_GeometryHandle geometry, const RT_AreaUnitHandle unit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeometryEngine_areaGeodetic_def)(const RT_GeometryHandle, const RT_AreaUnitHandle, RT_GeodeticCurveType, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_areaGeodetic_func = reinterpret_cast<RT_GeometryEngine_areaGeodetic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_areaGeodetic")));
    
    return RT_GeometryEngine_areaGeodetic_func(geometry, unit, curveType, errorHandler);
}

RT_ArrayHandle RT_GeometryEngine_autoComplete(const RT_VectorHandle existingBoundaries, const RT_VectorHandle newBoundaries, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeometryEngine_autoComplete_def)(const RT_VectorHandle, const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_autoComplete_func = reinterpret_cast<RT_GeometryEngine_autoComplete_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_autoComplete")));
    
    return RT_GeometryEngine_autoComplete_func(existingBoundaries, newBoundaries, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_boundary(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_boundary_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_boundary_func = reinterpret_cast<RT_GeometryEngine_boundary_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_boundary")));
    
    return RT_GeometryEngine_boundary_func(geometry, errorHandler);
}

RT_PolygonHandle RT_GeometryEngine_buffer(const RT_GeometryHandle geometry, double distance, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolygonHandle (*RT_GeometryEngine_buffer_def)(const RT_GeometryHandle, double, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_buffer_func = reinterpret_cast<RT_GeometryEngine_buffer_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_buffer")));
    
    return RT_GeometryEngine_buffer_func(geometry, distance, errorHandler);
}

RT_ArrayHandle RT_GeometryEngine_bufferCollection(const RT_VectorHandle geometries, const RT_VectorHandle distances, bool unionResult, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeometryEngine_bufferCollection_def)(const RT_VectorHandle, const RT_VectorHandle, bool, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_bufferCollection_func = reinterpret_cast<RT_GeometryEngine_bufferCollection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_bufferCollection")));
    
    return RT_GeometryEngine_bufferCollection_func(geometries, distances, unionResult, errorHandler);
}

RT_PolygonHandle RT_GeometryEngine_bufferGeodetic(const RT_GeometryHandle geometry, double distance, const RT_LinearUnitHandle distanceUnit, double maxDeviation, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolygonHandle (*RT_GeometryEngine_bufferGeodetic_def)(const RT_GeometryHandle, double, const RT_LinearUnitHandle, double, RT_GeodeticCurveType, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_bufferGeodetic_func = reinterpret_cast<RT_GeometryEngine_bufferGeodetic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_bufferGeodetic")));
    
    return RT_GeometryEngine_bufferGeodetic_func(geometry, distance, distanceUnit, maxDeviation, curveType, errorHandler);
}

RT_ArrayHandle RT_GeometryEngine_bufferGeodeticCollection(const RT_VectorHandle geometries, const RT_VectorHandle distances, const RT_LinearUnitHandle distanceUnit, double maxDeviation, RT_GeodeticCurveType curveType, bool unionResult, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeometryEngine_bufferGeodeticCollection_def)(const RT_VectorHandle, const RT_VectorHandle, const RT_LinearUnitHandle, double, RT_GeodeticCurveType, bool, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_bufferGeodeticCollection_func = reinterpret_cast<RT_GeometryEngine_bufferGeodeticCollection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_bufferGeodeticCollection")));
    
    return RT_GeometryEngine_bufferGeodeticCollection_func(geometries, distances, distanceUnit, maxDeviation, curveType, unionResult, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_clip(const RT_GeometryHandle geometry, const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_clip_def)(const RT_GeometryHandle, const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_clip_func = reinterpret_cast<RT_GeometryEngine_clip_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_clip")));
    
    return RT_GeometryEngine_clip_func(geometry, envelope, errorHandler);
}

RT_EnvelopeHandle RT_GeometryEngine_combineExtents(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_GeometryEngine_combineExtents_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_combineExtents_func = reinterpret_cast<RT_GeometryEngine_combineExtents_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_combineExtents")));
    
    return RT_GeometryEngine_combineExtents_func(geometry1, geometry2, errorHandler);
}

RT_EnvelopeHandle RT_GeometryEngine_combineExtentsCollection(const RT_VectorHandle geometries, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_GeometryEngine_combineExtentsCollection_def)(const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_combineExtentsCollection_func = reinterpret_cast<RT_GeometryEngine_combineExtentsCollection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_combineExtentsCollection")));
    
    return RT_GeometryEngine_combineExtentsCollection_func(geometries, errorHandler);
}

bool RT_GeometryEngine_contains(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_contains_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_contains_func = reinterpret_cast<RT_GeometryEngine_contains_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_contains")));
    
    return RT_GeometryEngine_contains_func(geometry1, geometry2, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_convexHull(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_convexHull_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_convexHull_func = reinterpret_cast<RT_GeometryEngine_convexHull_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_convexHull")));
    
    return RT_GeometryEngine_convexHull_func(geometry, errorHandler);
}

RT_ArrayHandle RT_GeometryEngine_convexHullCollection(const RT_VectorHandle geometries, bool merge, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeometryEngine_convexHullCollection_def)(const RT_VectorHandle, bool, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_convexHullCollection_func = reinterpret_cast<RT_GeometryEngine_convexHullCollection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_convexHullCollection")));
    
    return RT_GeometryEngine_convexHullCollection_func(geometries, merge, errorHandler);
}

RT_PointHandle RT_GeometryEngine_createPointAlong(const RT_PolylineHandle polyline, double distance, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_GeometryEngine_createPointAlong_def)(const RT_PolylineHandle, double, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_createPointAlong_func = reinterpret_cast<RT_GeometryEngine_createPointAlong_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_createPointAlong")));
    
    return RT_GeometryEngine_createPointAlong_func(polyline, distance, errorHandler);
}

bool RT_GeometryEngine_crosses(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_crosses_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_crosses_func = reinterpret_cast<RT_GeometryEngine_crosses_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_crosses")));
    
    return RT_GeometryEngine_crosses_func(geometry1, geometry2, errorHandler);
}

RT_ArrayHandle RT_GeometryEngine_cut(const RT_GeometryHandle geometry, const RT_PolylineHandle cutter, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeometryEngine_cut_def)(const RT_GeometryHandle, const RT_PolylineHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_cut_func = reinterpret_cast<RT_GeometryEngine_cut_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_cut")));
    
    return RT_GeometryEngine_cut_func(geometry, cutter, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_densify(const RT_GeometryHandle geometry, double maxSegmentLength, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_densify_def)(const RT_GeometryHandle, double, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_densify_func = reinterpret_cast<RT_GeometryEngine_densify_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_densify")));
    
    return RT_GeometryEngine_densify_func(geometry, maxSegmentLength, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_densifyGeodetic(const RT_GeometryHandle geometry, double maxSegmentLength, const RT_LinearUnitHandle lengthUnit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_densifyGeodetic_def)(const RT_GeometryHandle, double, const RT_LinearUnitHandle, RT_GeodeticCurveType, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_densifyGeodetic_func = reinterpret_cast<RT_GeometryEngine_densifyGeodetic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_densifyGeodetic")));
    
    return RT_GeometryEngine_densifyGeodetic_func(geometry, maxSegmentLength, lengthUnit, curveType, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_difference(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_difference_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_difference_func = reinterpret_cast<RT_GeometryEngine_difference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_difference")));
    
    return RT_GeometryEngine_difference_func(geometry1, geometry2, errorHandler);
}

bool RT_GeometryEngine_disjoint(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_disjoint_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_disjoint_func = reinterpret_cast<RT_GeometryEngine_disjoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_disjoint")));
    
    return RT_GeometryEngine_disjoint_func(geometry1, geometry2, errorHandler);
}

double RT_GeometryEngine_distance(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeometryEngine_distance_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_distance_func = reinterpret_cast<RT_GeometryEngine_distance_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_distance")));
    
    return RT_GeometryEngine_distance_func(geometry1, geometry2, errorHandler);
}

RT_GeodeticDistanceResultHandle RT_GeometryEngine_distanceGeodetic(const RT_PointHandle point1, const RT_PointHandle point2, const RT_LinearUnitHandle distanceUnit, const RT_AngularUnitHandle azimuthUnit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeodeticDistanceResultHandle (*RT_GeometryEngine_distanceGeodetic_def)(const RT_PointHandle, const RT_PointHandle, const RT_LinearUnitHandle, const RT_AngularUnitHandle, RT_GeodeticCurveType, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_distanceGeodetic_func = reinterpret_cast<RT_GeometryEngine_distanceGeodetic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_distanceGeodetic")));
    
    return RT_GeometryEngine_distanceGeodetic_func(point1, point2, distanceUnit, azimuthUnit, curveType, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_ellipseGeodesic(const RT_GeodesicEllipseParametersHandle parameters, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_ellipseGeodesic_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_ellipseGeodesic_func = reinterpret_cast<RT_GeometryEngine_ellipseGeodesic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_ellipseGeodesic")));
    
    return RT_GeometryEngine_ellipseGeodesic_func(parameters, errorHandler);
}

bool RT_GeometryEngine_equals(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_equals_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_equals_func = reinterpret_cast<RT_GeometryEngine_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_equals")));
    
    return RT_GeometryEngine_equals_func(geometry1, geometry2, errorHandler);
}

RT_PolylineHandle RT_GeometryEngine_extend(const RT_PolylineHandle polyline, const RT_PolylineHandle extender, RT_GeometryExtendOptions extendOptions, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PolylineHandle (*RT_GeometryEngine_extend_def)(const RT_PolylineHandle, const RT_PolylineHandle, RT_GeometryExtendOptions, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_extend_func = reinterpret_cast<RT_GeometryEngine_extend_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_extend")));
    
    return RT_GeometryEngine_extend_func(polyline, extender, extendOptions, errorHandler);
}

double RT_GeometryEngine_fractionAlong(const RT_PolylineHandle line, const RT_PointHandle point, double tolerance, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeometryEngine_fractionAlong_def)(const RT_PolylineHandle, const RT_PointHandle, double, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_fractionAlong_func = reinterpret_cast<RT_GeometryEngine_fractionAlong_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_fractionAlong")));
    
    return RT_GeometryEngine_fractionAlong_func(line, point, tolerance, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_generalize(const RT_GeometryHandle geometry, double maxDeviation, bool removeDegenerateParts, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_generalize_def)(const RT_GeometryHandle, double, bool, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_generalize_func = reinterpret_cast<RT_GeometryEngine_generalize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_generalize")));
    
    return RT_GeometryEngine_generalize_func(geometry, maxDeviation, removeDegenerateParts, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_intersection(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_intersection_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_intersection_func = reinterpret_cast<RT_GeometryEngine_intersection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_intersection")));
    
    return RT_GeometryEngine_intersection_func(geometry1, geometry2, errorHandler);
}

RT_ArrayHandle RT_GeometryEngine_intersections(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeometryEngine_intersections_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_intersections_func = reinterpret_cast<RT_GeometryEngine_intersections_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_intersections")));
    
    return RT_GeometryEngine_intersections_func(geometry1, geometry2, errorHandler);
}

bool RT_GeometryEngine_intersects(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_intersects_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_intersects_func = reinterpret_cast<RT_GeometryEngine_intersects_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_intersects")));
    
    return RT_GeometryEngine_intersects_func(geometry1, geometry2, errorHandler);
}

bool RT_GeometryEngine_isSimple(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_isSimple_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_isSimple_func = reinterpret_cast<RT_GeometryEngine_isSimple_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_isSimple")));
    
    return RT_GeometryEngine_isSimple_func(geometry, errorHandler);
}

RT_PointHandle RT_GeometryEngine_labelPoint(const RT_PolygonHandle polygon, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_GeometryEngine_labelPoint_def)(const RT_PolygonHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_labelPoint_func = reinterpret_cast<RT_GeometryEngine_labelPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_labelPoint")));
    
    return RT_GeometryEngine_labelPoint_func(polygon, errorHandler);
}

double RT_GeometryEngine_length(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeometryEngine_length_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_length_func = reinterpret_cast<RT_GeometryEngine_length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_length")));
    
    return RT_GeometryEngine_length_func(geometry, errorHandler);
}

double RT_GeometryEngine_lengthGeodetic(const RT_GeometryHandle geometry, const RT_LinearUnitHandle lengthUnit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeometryEngine_lengthGeodetic_def)(const RT_GeometryHandle, const RT_LinearUnitHandle, RT_GeodeticCurveType, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_lengthGeodetic_func = reinterpret_cast<RT_GeometryEngine_lengthGeodetic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_lengthGeodetic")));
    
    return RT_GeometryEngine_lengthGeodetic_func(geometry, lengthUnit, curveType, errorHandler);
}

RT_ArrayHandle RT_GeometryEngine_moveGeodetic(const RT_VectorHandle pointCollection, double distance, const RT_LinearUnitHandle distanceUnit, double azimuth, const RT_AngularUnitHandle azimuthUnit, RT_GeodeticCurveType curveType, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_GeometryEngine_moveGeodetic_def)(const RT_VectorHandle, double, const RT_LinearUnitHandle, double, const RT_AngularUnitHandle, RT_GeodeticCurveType, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_moveGeodetic_func = reinterpret_cast<RT_GeometryEngine_moveGeodetic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_moveGeodetic")));
    
    return RT_GeometryEngine_moveGeodetic_func(pointCollection, distance, distanceUnit, azimuth, azimuthUnit, curveType, errorHandler);
}

RT_ProximityResultHandle RT_GeometryEngine_nearestCoordinate(const RT_GeometryHandle geometry, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ProximityResultHandle (*RT_GeometryEngine_nearestCoordinate_def)(const RT_GeometryHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_nearestCoordinate_func = reinterpret_cast<RT_GeometryEngine_nearestCoordinate_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_nearestCoordinate")));
    
    return RT_GeometryEngine_nearestCoordinate_func(geometry, point, errorHandler);
}

RT_ProximityResultHandle RT_GeometryEngine_nearestCoordinateGeodetic(const RT_GeometryHandle geometry, const RT_PointHandle point, double maxDeviation, const RT_LinearUnitHandle deviationUnit, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ProximityResultHandle (*RT_GeometryEngine_nearestCoordinateGeodetic_def)(const RT_GeometryHandle, const RT_PointHandle, double, const RT_LinearUnitHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_nearestCoordinateGeodetic_func = reinterpret_cast<RT_GeometryEngine_nearestCoordinateGeodetic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_nearestCoordinateGeodetic")));
    
    return RT_GeometryEngine_nearestCoordinateGeodetic_func(geometry, point, maxDeviation, deviationUnit, errorHandler);
}

RT_ProximityResultHandle RT_GeometryEngine_nearestVertex(const RT_GeometryHandle geometry, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ProximityResultHandle (*RT_GeometryEngine_nearestVertex_def)(const RT_GeometryHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_nearestVertex_func = reinterpret_cast<RT_GeometryEngine_nearestVertex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_nearestVertex")));
    
    return RT_GeometryEngine_nearestVertex_func(geometry, point, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_normalizeCentralMeridian(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_normalizeCentralMeridian_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_normalizeCentralMeridian_func = reinterpret_cast<RT_GeometryEngine_normalizeCentralMeridian_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_normalizeCentralMeridian")));
    
    return RT_GeometryEngine_normalizeCentralMeridian_func(geometry, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_offset(const RT_GeometryHandle geometry, double distance, RT_GeometryOffsetType offsetType, double bevelRatio, double flattenError, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_offset_def)(const RT_GeometryHandle, double, RT_GeometryOffsetType, double, double, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_offset_func = reinterpret_cast<RT_GeometryEngine_offset_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_offset")));
    
    return RT_GeometryEngine_offset_func(geometry, distance, offsetType, bevelRatio, flattenError, errorHandler);
}

bool RT_GeometryEngine_overlaps(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_overlaps_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_overlaps_func = reinterpret_cast<RT_GeometryEngine_overlaps_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_overlaps")));
    
    return RT_GeometryEngine_overlaps_func(geometry1, geometry2, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_project(const RT_GeometryHandle geometry, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_project_def)(const RT_GeometryHandle, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_project_func = reinterpret_cast<RT_GeometryEngine_project_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_project")));
    
    return RT_GeometryEngine_project_func(geometry, spatialReference, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_projectWithTransformation(const RT_GeometryHandle geometry, const RT_SpatialReferenceHandle outputSpatialReference, const RT_DatumTransformationHandle datumTransformation, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_projectWithTransformation_def)(const RT_GeometryHandle, const RT_SpatialReferenceHandle, const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_projectWithTransformation_func = reinterpret_cast<RT_GeometryEngine_projectWithTransformation_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_projectWithTransformation")));
    
    return RT_GeometryEngine_projectWithTransformation_func(geometry, outputSpatialReference, datumTransformation, errorHandler);
}

bool RT_GeometryEngine_relate(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const char* relation, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_relate_def)(const RT_GeometryHandle, const RT_GeometryHandle, const char*, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_relate_func = reinterpret_cast<RT_GeometryEngine_relate_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_relate")));
    
    return RT_GeometryEngine_relate_func(geometry1, geometry2, relation, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_removeM(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_removeM_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_removeM_func = reinterpret_cast<RT_GeometryEngine_removeM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_removeM")));
    
    return RT_GeometryEngine_removeM_func(geometry, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_removeZ(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_removeZ_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_removeZ_func = reinterpret_cast<RT_GeometryEngine_removeZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_removeZ")));
    
    return RT_GeometryEngine_removeZ_func(geometry, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_removeZAndM(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_removeZAndM_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_removeZAndM_func = reinterpret_cast<RT_GeometryEngine_removeZAndM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_removeZAndM")));
    
    return RT_GeometryEngine_removeZAndM_func(geometry, errorHandler);
}

RT_MultipartHandle RT_GeometryEngine_reshape(const RT_MultipartHandle geometry, const RT_PolylineHandle reshaper, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MultipartHandle (*RT_GeometryEngine_reshape_def)(const RT_MultipartHandle, const RT_PolylineHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_reshape_func = reinterpret_cast<RT_GeometryEngine_reshape_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_reshape")));
    
    return RT_GeometryEngine_reshape_func(geometry, reshaper, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_sectorGeodesic(const RT_GeodesicSectorParametersHandle parameters, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_sectorGeodesic_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_sectorGeodesic_func = reinterpret_cast<RT_GeometryEngine_sectorGeodesic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_sectorGeodesic")));
    
    return RT_GeometryEngine_sectorGeodesic_func(parameters, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_setM(const RT_GeometryHandle geometry, double m, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_setM_def)(const RT_GeometryHandle, double, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_setM_func = reinterpret_cast<RT_GeometryEngine_setM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_setM")));
    
    return RT_GeometryEngine_setM_func(geometry, m, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_setZ(const RT_GeometryHandle geometry, double z, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_setZ_def)(const RT_GeometryHandle, double, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_setZ_func = reinterpret_cast<RT_GeometryEngine_setZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_setZ")));
    
    return RT_GeometryEngine_setZ_func(geometry, z, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_setZAndM(const RT_GeometryHandle geometry, double z, double m, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_setZAndM_def)(const RT_GeometryHandle, double, double, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_setZAndM_func = reinterpret_cast<RT_GeometryEngine_setZAndM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_setZAndM")));
    
    return RT_GeometryEngine_setZAndM_func(geometry, z, m, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_simplify(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_simplify_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_simplify_func = reinterpret_cast<RT_GeometryEngine_simplify_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_simplify")));
    
    return RT_GeometryEngine_simplify_func(geometry, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_symmetricDifference(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_symmetricDifference_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_symmetricDifference_func = reinterpret_cast<RT_GeometryEngine_symmetricDifference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_symmetricDifference")));
    
    return RT_GeometryEngine_symmetricDifference_func(geometry1, geometry2, errorHandler);
}

bool RT_GeometryEngine_touches(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_touches_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_touches_func = reinterpret_cast<RT_GeometryEngine_touches_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_touches")));
    
    return RT_GeometryEngine_touches_func(geometry1, geometry2, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_union(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_union_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_union_func = reinterpret_cast<RT_GeometryEngine_union_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_union")));
    
    return RT_GeometryEngine_union_func(geometry1, geometry2, errorHandler);
}

RT_GeometryHandle RT_GeometryEngine_unionCollection(const RT_VectorHandle geometries, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryEngine_unionCollection_def)(const RT_VectorHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_unionCollection_func = reinterpret_cast<RT_GeometryEngine_unionCollection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_unionCollection")));
    
    return RT_GeometryEngine_unionCollection_func(geometries, errorHandler);
}

bool RT_GeometryEngine_within(const RT_GeometryHandle geometry1, const RT_GeometryHandle geometry2, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryEngine_within_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryEngine_within_func = reinterpret_cast<RT_GeometryEngine_within_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryEngine_within")));
    
    return RT_GeometryEngine_within_func(geometry1, geometry2, errorHandler);
}
#endif