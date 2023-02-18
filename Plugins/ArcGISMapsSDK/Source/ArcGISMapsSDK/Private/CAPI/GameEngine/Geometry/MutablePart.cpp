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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePart.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_MutablePart_destroy(RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_destroy_def)(RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_destroy_func = reinterpret_cast<RT_MutablePart_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_destroy")));
    
    RT_MutablePart_destroy_func(thisHandle, errorHandler);
}

RT_MutablePartHandle RT_MutablePart_createWithSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MutablePartHandle (*RT_MutablePart_createWithSpatialReference_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_createWithSpatialReference_func = reinterpret_cast<RT_MutablePart_createWithSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_createWithSpatialReference")));
    
    return RT_MutablePart_createWithSpatialReference_func(spatialReference, errorHandler);
}

RT_PointHandle RT_MutablePart_getEndPoint(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_MutablePart_getEndPoint_def)(const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_getEndPoint_func = reinterpret_cast<RT_MutablePart_getEndPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getEndPoint")));
    
    return RT_MutablePart_getEndPoint_func(thisHandle, errorHandler);
}

bool RT_MutablePart_getHasCurves(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_MutablePart_getHasCurves_def)(const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_getHasCurves_func = reinterpret_cast<RT_MutablePart_getHasCurves_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getHasCurves")));
    
    return RT_MutablePart_getHasCurves_func(thisHandle, errorHandler);
}

bool RT_MutablePart_getIsEmpty(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_MutablePart_getIsEmpty_def)(const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_getIsEmpty_func = reinterpret_cast<RT_MutablePart_getIsEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getIsEmpty")));
    
    return RT_MutablePart_getIsEmpty_func(thisHandle, errorHandler);
}

size_t RT_MutablePart_getPointCount(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_getPointCount_def)(const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_getPointCount_func = reinterpret_cast<RT_MutablePart_getPointCount_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getPointCount")));
    
    return RT_MutablePart_getPointCount_func(thisHandle, errorHandler);
}

size_t RT_MutablePart_getSegmentCount(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_getSegmentCount_def)(const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_getSegmentCount_func = reinterpret_cast<RT_MutablePart_getSegmentCount_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getSegmentCount")));
    
    return RT_MutablePart_getSegmentCount_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_MutablePart_getSpatialReference(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_MutablePart_getSpatialReference_def)(const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_getSpatialReference_func = reinterpret_cast<RT_MutablePart_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getSpatialReference")));
    
    return RT_MutablePart_getSpatialReference_func(thisHandle, errorHandler);
}

RT_PointHandle RT_MutablePart_getStartPoint(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_MutablePart_getStartPoint_def)(const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_getStartPoint_func = reinterpret_cast<RT_MutablePart_getStartPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getStartPoint")));
    
    return RT_MutablePart_getStartPoint_func(thisHandle, errorHandler);
}

size_t RT_MutablePart_addPointXY(RT_MutablePartHandle thisHandle, double x, double y, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_addPointXY_def)(RT_MutablePartHandle, double, double, const RT_ErrorHandler*);
    static auto RT_MutablePart_addPointXY_func = reinterpret_cast<RT_MutablePart_addPointXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_addPointXY")));
    
    return RT_MutablePart_addPointXY_func(thisHandle, x, y, errorHandler);
}

size_t RT_MutablePart_addPointXYZ(RT_MutablePartHandle thisHandle, double x, double y, double z, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_addPointXYZ_def)(RT_MutablePartHandle, double, double, double, const RT_ErrorHandler*);
    static auto RT_MutablePart_addPointXYZ_func = reinterpret_cast<RT_MutablePart_addPointXYZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_addPointXYZ")));
    
    return RT_MutablePart_addPointXYZ_func(thisHandle, x, y, z, errorHandler);
}

size_t RT_MutablePart_addPoint(RT_MutablePartHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_addPoint_def)(RT_MutablePartHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_addPoint_func = reinterpret_cast<RT_MutablePart_addPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_addPoint")));
    
    return RT_MutablePart_addPoint_func(thisHandle, point, errorHandler);
}

size_t RT_MutablePart_addSegment(RT_MutablePartHandle thisHandle, const RT_SegmentHandle segment, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_addSegment_def)(RT_MutablePartHandle, const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_addSegment_func = reinterpret_cast<RT_MutablePart_addSegment_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_addSegment")));
    
    return RT_MutablePart_addSegment_func(thisHandle, segment, errorHandler);
}

size_t RT_MutablePart_getEndPointIndexFromSegmentIndex(const RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_getEndPointIndexFromSegmentIndex_def)(const RT_MutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePart_getEndPointIndexFromSegmentIndex_func = reinterpret_cast<RT_MutablePart_getEndPointIndexFromSegmentIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getEndPointIndexFromSegmentIndex")));
    
    return RT_MutablePart_getEndPointIndexFromSegmentIndex_func(thisHandle, segmentIndex, errorHandler);
}

RT_PointHandle RT_MutablePart_getPoint(const RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_MutablePart_getPoint_def)(const RT_MutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePart_getPoint_func = reinterpret_cast<RT_MutablePart_getPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getPoint")));
    
    return RT_MutablePart_getPoint_func(thisHandle, pointIndex, errorHandler);
}

RT_ImmutablePointCollectionHandle RT_MutablePart_getPoints(const RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ImmutablePointCollectionHandle (*RT_MutablePart_getPoints_def)(const RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_getPoints_func = reinterpret_cast<RT_MutablePart_getPoints_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getPoints")));
    
    return RT_MutablePart_getPoints_func(thisHandle, errorHandler);
}

RT_SegmentHandle RT_MutablePart_getSegment(const RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SegmentHandle (*RT_MutablePart_getSegment_def)(const RT_MutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePart_getSegment_func = reinterpret_cast<RT_MutablePart_getSegment_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getSegment")));
    
    return RT_MutablePart_getSegment_func(thisHandle, segmentIndex, errorHandler);
}

size_t RT_MutablePart_getSegmentIndexFromEndPointIndex(const RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_getSegmentIndexFromEndPointIndex_def)(const RT_MutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePart_getSegmentIndexFromEndPointIndex_func = reinterpret_cast<RT_MutablePart_getSegmentIndexFromEndPointIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getSegmentIndexFromEndPointIndex")));
    
    return RT_MutablePart_getSegmentIndexFromEndPointIndex_func(thisHandle, pointIndex, errorHandler);
}

void RT_MutablePart_getSegmentIndexFromPointIndex(const RT_MutablePartHandle thisHandle, size_t pointIndex, size_t* outStartPointSegmentIndex, size_t* outEndPointSegmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_getSegmentIndexFromPointIndex_def)(const RT_MutablePartHandle, size_t, size_t*, size_t*, const RT_ErrorHandler*);
    static auto RT_MutablePart_getSegmentIndexFromPointIndex_func = reinterpret_cast<RT_MutablePart_getSegmentIndexFromPointIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getSegmentIndexFromPointIndex")));
    
    RT_MutablePart_getSegmentIndexFromPointIndex_func(thisHandle, pointIndex, outStartPointSegmentIndex, outEndPointSegmentIndex, errorHandler);
}

size_t RT_MutablePart_getSegmentIndexFromStartPointIndex(const RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_getSegmentIndexFromStartPointIndex_def)(const RT_MutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePart_getSegmentIndexFromStartPointIndex_func = reinterpret_cast<RT_MutablePart_getSegmentIndexFromStartPointIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getSegmentIndexFromStartPointIndex")));
    
    return RT_MutablePart_getSegmentIndexFromStartPointIndex_func(thisHandle, pointIndex, errorHandler);
}

size_t RT_MutablePart_getStartPointIndexFromSegmentIndex(const RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePart_getStartPointIndexFromSegmentIndex_def)(const RT_MutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePart_getStartPointIndexFromSegmentIndex_func = reinterpret_cast<RT_MutablePart_getStartPointIndexFromSegmentIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_getStartPointIndexFromSegmentIndex")));
    
    return RT_MutablePart_getStartPointIndexFromSegmentIndex_func(thisHandle, segmentIndex, errorHandler);
}

void RT_MutablePart_insertPointXY(RT_MutablePartHandle thisHandle, size_t pointIndex, double x, double y, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_insertPointXY_def)(RT_MutablePartHandle, size_t, double, double, const RT_ErrorHandler*);
    static auto RT_MutablePart_insertPointXY_func = reinterpret_cast<RT_MutablePart_insertPointXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_insertPointXY")));
    
    RT_MutablePart_insertPointXY_func(thisHandle, pointIndex, x, y, errorHandler);
}

void RT_MutablePart_insertPointXYZ(RT_MutablePartHandle thisHandle, size_t pointIndex, double x, double y, double z, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_insertPointXYZ_def)(RT_MutablePartHandle, size_t, double, double, double, const RT_ErrorHandler*);
    static auto RT_MutablePart_insertPointXYZ_func = reinterpret_cast<RT_MutablePart_insertPointXYZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_insertPointXYZ")));
    
    RT_MutablePart_insertPointXYZ_func(thisHandle, pointIndex, x, y, z, errorHandler);
}

void RT_MutablePart_insertPoint(RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_insertPoint_def)(RT_MutablePartHandle, size_t, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_insertPoint_func = reinterpret_cast<RT_MutablePart_insertPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_insertPoint")));
    
    RT_MutablePart_insertPoint_func(thisHandle, pointIndex, point, errorHandler);
}

void RT_MutablePart_insertSegment(RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_SegmentHandle segment, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_insertSegment_def)(RT_MutablePartHandle, size_t, const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_insertSegment_func = reinterpret_cast<RT_MutablePart_insertSegment_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_insertSegment")));
    
    RT_MutablePart_insertSegment_func(thisHandle, segmentIndex, segment, errorHandler);
}

void RT_MutablePart_removeAll(RT_MutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_removeAll_def)(RT_MutablePartHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_removeAll_func = reinterpret_cast<RT_MutablePart_removeAll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_removeAll")));
    
    RT_MutablePart_removeAll_func(thisHandle, errorHandler);
}

void RT_MutablePart_removePoint(RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_removePoint_def)(RT_MutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePart_removePoint_func = reinterpret_cast<RT_MutablePart_removePoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_removePoint")));
    
    RT_MutablePart_removePoint_func(thisHandle, pointIndex, errorHandler);
}

void RT_MutablePart_removeSegment(RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_removeSegment_def)(RT_MutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePart_removeSegment_func = reinterpret_cast<RT_MutablePart_removeSegment_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_removeSegment")));
    
    RT_MutablePart_removeSegment_func(thisHandle, segmentIndex, errorHandler);
}

void RT_MutablePart_setPoint(RT_MutablePartHandle thisHandle, size_t pointIndex, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_setPoint_def)(RT_MutablePartHandle, size_t, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_setPoint_func = reinterpret_cast<RT_MutablePart_setPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_setPoint")));
    
    RT_MutablePart_setPoint_func(thisHandle, pointIndex, point, errorHandler);
}

void RT_MutablePart_setSegment(RT_MutablePartHandle thisHandle, size_t segmentIndex, const RT_SegmentHandle segment, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePart_setSegment_def)(RT_MutablePartHandle, size_t, const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_MutablePart_setSegment_func = reinterpret_cast<RT_MutablePart_setSegment_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePart_setSegment")));
    
    RT_MutablePart_setSegment_func(thisHandle, segmentIndex, segment, errorHandler);
}
#endif