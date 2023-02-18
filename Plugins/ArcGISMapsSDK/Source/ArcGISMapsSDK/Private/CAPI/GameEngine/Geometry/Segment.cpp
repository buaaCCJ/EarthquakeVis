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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Segment.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Segment_destroy(RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Segment_destroy_def)(RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_destroy_func = reinterpret_cast<RT_Segment_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_destroy")));
    
    RT_Segment_destroy_func(thisHandle, errorHandler);
}

RT_PointHandle RT_Segment_getEndPoint(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Segment_getEndPoint_def)(const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_getEndPoint_func = reinterpret_cast<RT_Segment_getEndPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_getEndPoint")));
    
    return RT_Segment_getEndPoint_func(thisHandle, errorHandler);
}

bool RT_Segment_getIsClosed(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Segment_getIsClosed_def)(const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_getIsClosed_func = reinterpret_cast<RT_Segment_getIsClosed_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_getIsClosed")));
    
    return RT_Segment_getIsClosed_func(thisHandle, errorHandler);
}

bool RT_Segment_getIsCurve(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Segment_getIsCurve_def)(const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_getIsCurve_func = reinterpret_cast<RT_Segment_getIsCurve_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_getIsCurve")));
    
    return RT_Segment_getIsCurve_func(thisHandle, errorHandler);
}

RT_SegmentType RT_Segment_getObjectType(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SegmentType (*RT_Segment_getObjectType_def)(const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_getObjectType_func = reinterpret_cast<RT_Segment_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_getObjectType")));
    
    return RT_Segment_getObjectType_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_Segment_getSpatialReference(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_Segment_getSpatialReference_def)(const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_getSpatialReference_func = reinterpret_cast<RT_Segment_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_getSpatialReference")));
    
    return RT_Segment_getSpatialReference_func(thisHandle, errorHandler);
}

RT_PointHandle RT_Segment_getStartPoint(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Segment_getStartPoint_def)(const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_getStartPoint_func = reinterpret_cast<RT_Segment_getStartPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_getStartPoint")));
    
    return RT_Segment_getStartPoint_func(thisHandle, errorHandler);
}

bool RT_Segment_equals(const RT_SegmentHandle thisHandle, const RT_SegmentHandle right, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Segment_equals_def)(const RT_SegmentHandle, const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_equals_func = reinterpret_cast<RT_Segment_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_equals")));
    
    return RT_Segment_equals_func(thisHandle, right, errorHandler);
}

size_t RT_Segment_getHash(const RT_SegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Segment_getHash_def)(const RT_SegmentHandle, const RT_ErrorHandler*);
    static auto RT_Segment_getHash_func = reinterpret_cast<RT_Segment_getHash_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Segment_getHash")));
    
    return RT_Segment_getHash_func(thisHandle, errorHandler);
}
#endif