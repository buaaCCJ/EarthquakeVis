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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/CubicBezierSegment.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_CubicBezierSegment_destroy(RT_CubicBezierSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_CubicBezierSegment_destroy_def)(RT_CubicBezierSegmentHandle, const RT_ErrorHandler*);
    static auto RT_CubicBezierSegment_destroy_func = reinterpret_cast<RT_CubicBezierSegment_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CubicBezierSegment_destroy")));
    
    RT_CubicBezierSegment_destroy_func(thisHandle, errorHandler);
}

RT_CubicBezierSegmentHandle RT_CubicBezierSegment_create(const RT_PointHandle startPoint, const RT_PointHandle controlPoint1, const RT_PointHandle controlPoint2, const RT_PointHandle endPoint, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_CubicBezierSegmentHandle (*RT_CubicBezierSegment_create_def)(const RT_PointHandle, const RT_PointHandle, const RT_PointHandle, const RT_PointHandle, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_CubicBezierSegment_create_func = reinterpret_cast<RT_CubicBezierSegment_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CubicBezierSegment_create")));
    
    return RT_CubicBezierSegment_create_func(startPoint, controlPoint1, controlPoint2, endPoint, spatialReference, errorHandler);
}

RT_PointHandle RT_CubicBezierSegment_getControlPoint1(const RT_CubicBezierSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_CubicBezierSegment_getControlPoint1_def)(const RT_CubicBezierSegmentHandle, const RT_ErrorHandler*);
    static auto RT_CubicBezierSegment_getControlPoint1_func = reinterpret_cast<RT_CubicBezierSegment_getControlPoint1_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CubicBezierSegment_getControlPoint1")));
    
    return RT_CubicBezierSegment_getControlPoint1_func(thisHandle, errorHandler);
}

RT_PointHandle RT_CubicBezierSegment_getControlPoint2(const RT_CubicBezierSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_CubicBezierSegment_getControlPoint2_def)(const RT_CubicBezierSegmentHandle, const RT_ErrorHandler*);
    static auto RT_CubicBezierSegment_getControlPoint2_func = reinterpret_cast<RT_CubicBezierSegment_getControlPoint2_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CubicBezierSegment_getControlPoint2")));
    
    return RT_CubicBezierSegment_getControlPoint2_func(thisHandle, errorHandler);
}
#endif