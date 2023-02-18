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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LineSegment.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_LineSegment_destroy(RT_LineSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_LineSegment_destroy_def)(RT_LineSegmentHandle, const RT_ErrorHandler*);
    static auto RT_LineSegment_destroy_func = reinterpret_cast<RT_LineSegment_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LineSegment_destroy")));
    
    RT_LineSegment_destroy_func(thisHandle, errorHandler);
}

RT_LineSegmentHandle RT_LineSegment_createWithXY(double xStart, double yStart, double xEnd, double yEnd, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LineSegmentHandle (*RT_LineSegment_createWithXY_def)(double, double, double, double, const RT_ErrorHandler*);
    static auto RT_LineSegment_createWithXY_func = reinterpret_cast<RT_LineSegment_createWithXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LineSegment_createWithXY")));
    
    return RT_LineSegment_createWithXY_func(xStart, yStart, xEnd, yEnd, errorHandler);
}

RT_LineSegmentHandle RT_LineSegment_createWithXYZ(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LineSegmentHandle (*RT_LineSegment_createWithXYZ_def)(double, double, double, double, double, double, const RT_ErrorHandler*);
    static auto RT_LineSegment_createWithXYZ_func = reinterpret_cast<RT_LineSegment_createWithXYZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LineSegment_createWithXYZ")));
    
    return RT_LineSegment_createWithXYZ_func(xStart, yStart, zStart, xEnd, yEnd, zEnd, errorHandler);
}

RT_LineSegmentHandle RT_LineSegment_createWithXYZSpatialReference(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LineSegmentHandle (*RT_LineSegment_createWithXYZSpatialReference_def)(double, double, double, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_LineSegment_createWithXYZSpatialReference_func = reinterpret_cast<RT_LineSegment_createWithXYZSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LineSegment_createWithXYZSpatialReference")));
    
    return RT_LineSegment_createWithXYZSpatialReference_func(xStart, yStart, zStart, xEnd, yEnd, zEnd, spatialReference, errorHandler);
}

RT_LineSegmentHandle RT_LineSegment_createWithXYSpatialReference(double xStart, double yStart, double xEnd, double yEnd, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LineSegmentHandle (*RT_LineSegment_createWithXYSpatialReference_def)(double, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_LineSegment_createWithXYSpatialReference_func = reinterpret_cast<RT_LineSegment_createWithXYSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LineSegment_createWithXYSpatialReference")));
    
    return RT_LineSegment_createWithXYSpatialReference_func(xStart, yStart, xEnd, yEnd, spatialReference, errorHandler);
}

RT_LineSegmentHandle RT_LineSegment_create(const RT_PointHandle startPoint, const RT_PointHandle endPoint, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LineSegmentHandle (*RT_LineSegment_create_def)(const RT_PointHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_LineSegment_create_func = reinterpret_cast<RT_LineSegment_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LineSegment_create")));
    
    return RT_LineSegment_create_func(startPoint, endPoint, errorHandler);
}

RT_LineSegmentHandle RT_LineSegment_createWithSpatialReference(const RT_PointHandle startPoint, const RT_PointHandle endPoint, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LineSegmentHandle (*RT_LineSegment_createWithSpatialReference_def)(const RT_PointHandle, const RT_PointHandle, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_LineSegment_createWithSpatialReference_func = reinterpret_cast<RT_LineSegment_createWithSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LineSegment_createWithSpatialReference")));
    
    return RT_LineSegment_createWithSpatialReference_func(startPoint, endPoint, spatialReference, errorHandler);
}

RT_LineSegmentHandle RT_LineSegment_createLineAtAngleFromStartPoint(const RT_PointHandle startPoint, double angleRadians, double length, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LineSegmentHandle (*RT_LineSegment_createLineAtAngleFromStartPoint_def)(const RT_PointHandle, double, double, const RT_ErrorHandler*);
    static auto RT_LineSegment_createLineAtAngleFromStartPoint_func = reinterpret_cast<RT_LineSegment_createLineAtAngleFromStartPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_LineSegment_createLineAtAngleFromStartPoint")));
    
    return RT_LineSegment_createLineAtAngleFromStartPoint_func(startPoint, angleRadians, length, errorHandler);
}
#endif