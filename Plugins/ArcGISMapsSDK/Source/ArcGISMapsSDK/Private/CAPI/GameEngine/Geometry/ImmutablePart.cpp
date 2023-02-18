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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePart.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_ImmutablePart_destroy(RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ImmutablePart_destroy_def)(RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_destroy_func = reinterpret_cast<RT_ImmutablePart_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_destroy")));
    
    RT_ImmutablePart_destroy_func(thisHandle, errorHandler);
}

RT_PointHandle RT_ImmutablePart_getEndPoint(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_ImmutablePart_getEndPoint_def)(const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getEndPoint_func = reinterpret_cast<RT_ImmutablePart_getEndPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getEndPoint")));
    
    return RT_ImmutablePart_getEndPoint_func(thisHandle, errorHandler);
}

bool RT_ImmutablePart_getHasCurves(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_ImmutablePart_getHasCurves_def)(const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getHasCurves_func = reinterpret_cast<RT_ImmutablePart_getHasCurves_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getHasCurves")));
    
    return RT_ImmutablePart_getHasCurves_func(thisHandle, errorHandler);
}

bool RT_ImmutablePart_getIsEmpty(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_ImmutablePart_getIsEmpty_def)(const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getIsEmpty_func = reinterpret_cast<RT_ImmutablePart_getIsEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getIsEmpty")));
    
    return RT_ImmutablePart_getIsEmpty_func(thisHandle, errorHandler);
}

size_t RT_ImmutablePart_getPointCount(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePart_getPointCount_def)(const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getPointCount_func = reinterpret_cast<RT_ImmutablePart_getPointCount_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getPointCount")));
    
    return RT_ImmutablePart_getPointCount_func(thisHandle, errorHandler);
}

size_t RT_ImmutablePart_getSegmentCount(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePart_getSegmentCount_def)(const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getSegmentCount_func = reinterpret_cast<RT_ImmutablePart_getSegmentCount_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getSegmentCount")));
    
    return RT_ImmutablePart_getSegmentCount_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_ImmutablePart_getSpatialReference(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_ImmutablePart_getSpatialReference_def)(const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getSpatialReference_func = reinterpret_cast<RT_ImmutablePart_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getSpatialReference")));
    
    return RT_ImmutablePart_getSpatialReference_func(thisHandle, errorHandler);
}

RT_PointHandle RT_ImmutablePart_getStartPoint(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_ImmutablePart_getStartPoint_def)(const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getStartPoint_func = reinterpret_cast<RT_ImmutablePart_getStartPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getStartPoint")));
    
    return RT_ImmutablePart_getStartPoint_func(thisHandle, errorHandler);
}

size_t RT_ImmutablePart_getEndPointIndexFromSegmentIndex(const RT_ImmutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePart_getEndPointIndexFromSegmentIndex_def)(const RT_ImmutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getEndPointIndexFromSegmentIndex_func = reinterpret_cast<RT_ImmutablePart_getEndPointIndexFromSegmentIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getEndPointIndexFromSegmentIndex")));
    
    return RT_ImmutablePart_getEndPointIndexFromSegmentIndex_func(thisHandle, segmentIndex, errorHandler);
}

RT_PointHandle RT_ImmutablePart_getPoint(const RT_ImmutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_ImmutablePart_getPoint_def)(const RT_ImmutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getPoint_func = reinterpret_cast<RT_ImmutablePart_getPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getPoint")));
    
    return RT_ImmutablePart_getPoint_func(thisHandle, pointIndex, errorHandler);
}

RT_ImmutablePointCollectionHandle RT_ImmutablePart_getPoints(const RT_ImmutablePartHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ImmutablePointCollectionHandle (*RT_ImmutablePart_getPoints_def)(const RT_ImmutablePartHandle, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getPoints_func = reinterpret_cast<RT_ImmutablePart_getPoints_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getPoints")));
    
    return RT_ImmutablePart_getPoints_func(thisHandle, errorHandler);
}

RT_SegmentHandle RT_ImmutablePart_getSegment(const RT_ImmutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SegmentHandle (*RT_ImmutablePart_getSegment_def)(const RT_ImmutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getSegment_func = reinterpret_cast<RT_ImmutablePart_getSegment_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getSegment")));
    
    return RT_ImmutablePart_getSegment_func(thisHandle, segmentIndex, errorHandler);
}

size_t RT_ImmutablePart_getSegmentIndexFromEndPointIndex(const RT_ImmutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePart_getSegmentIndexFromEndPointIndex_def)(const RT_ImmutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getSegmentIndexFromEndPointIndex_func = reinterpret_cast<RT_ImmutablePart_getSegmentIndexFromEndPointIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getSegmentIndexFromEndPointIndex")));
    
    return RT_ImmutablePart_getSegmentIndexFromEndPointIndex_func(thisHandle, pointIndex, errorHandler);
}

void RT_ImmutablePart_getSegmentIndexFromPointIndex(const RT_ImmutablePartHandle thisHandle, size_t pointIndex, size_t* outStartPointSegmentIndex, size_t* outEndPointSegmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_ImmutablePart_getSegmentIndexFromPointIndex_def)(const RT_ImmutablePartHandle, size_t, size_t*, size_t*, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getSegmentIndexFromPointIndex_func = reinterpret_cast<RT_ImmutablePart_getSegmentIndexFromPointIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getSegmentIndexFromPointIndex")));
    
    RT_ImmutablePart_getSegmentIndexFromPointIndex_func(thisHandle, pointIndex, outStartPointSegmentIndex, outEndPointSegmentIndex, errorHandler);
}

size_t RT_ImmutablePart_getSegmentIndexFromStartPointIndex(const RT_ImmutablePartHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePart_getSegmentIndexFromStartPointIndex_def)(const RT_ImmutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getSegmentIndexFromStartPointIndex_func = reinterpret_cast<RT_ImmutablePart_getSegmentIndexFromStartPointIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getSegmentIndexFromStartPointIndex")));
    
    return RT_ImmutablePart_getSegmentIndexFromStartPointIndex_func(thisHandle, pointIndex, errorHandler);
}

size_t RT_ImmutablePart_getStartPointIndexFromSegmentIndex(const RT_ImmutablePartHandle thisHandle, size_t segmentIndex, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_ImmutablePart_getStartPointIndexFromSegmentIndex_def)(const RT_ImmutablePartHandle, size_t, const RT_ErrorHandler*);
    static auto RT_ImmutablePart_getStartPointIndexFromSegmentIndex_func = reinterpret_cast<RT_ImmutablePart_getStartPointIndexFromSegmentIndex_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_ImmutablePart_getStartPointIndexFromSegmentIndex")));
    
    return RT_ImmutablePart_getStartPointIndexFromSegmentIndex_func(thisHandle, segmentIndex, errorHandler);
}
#endif