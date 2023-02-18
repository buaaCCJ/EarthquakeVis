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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EllipticArcSegment.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_EllipticArcSegment_destroy(RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EllipticArcSegment_destroy_def)(RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_destroy_func = reinterpret_cast<RT_EllipticArcSegment_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_destroy")));
    
    RT_EllipticArcSegment_destroy_func(thisHandle, errorHandler);
}

RT_EllipticArcSegmentHandle RT_EllipticArcSegment_createWithCenter(const RT_PointHandle centerPoint, double rotationAngle, double semiMajorAxis, double minorMajorRatio, double startAngle, double centralAngle, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EllipticArcSegmentHandle (*RT_EllipticArcSegment_createWithCenter_def)(const RT_PointHandle, double, double, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_createWithCenter_func = reinterpret_cast<RT_EllipticArcSegment_createWithCenter_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_createWithCenter")));
    
    return RT_EllipticArcSegment_createWithCenter_func(centerPoint, rotationAngle, semiMajorAxis, minorMajorRatio, startAngle, centralAngle, spatialReference, errorHandler);
}

RT_EllipticArcSegmentHandle RT_EllipticArcSegment_createWithStartAndEndpoints(const RT_PointHandle startPoint, const RT_PointHandle endPoint, double rotationAngle, bool isMinor, bool isCounterClockwise, double semiMajorAxis, double minorMajorRatio, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EllipticArcSegmentHandle (*RT_EllipticArcSegment_createWithStartAndEndpoints_def)(const RT_PointHandle, const RT_PointHandle, double, bool, bool, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_createWithStartAndEndpoints_func = reinterpret_cast<RT_EllipticArcSegment_createWithStartAndEndpoints_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_createWithStartAndEndpoints")));
    
    return RT_EllipticArcSegment_createWithStartAndEndpoints_func(startPoint, endPoint, rotationAngle, isMinor, isCounterClockwise, semiMajorAxis, minorMajorRatio, spatialReference, errorHandler);
}

RT_PointHandle RT_EllipticArcSegment_getCenterPoint(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_EllipticArcSegment_getCenterPoint_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getCenterPoint_func = reinterpret_cast<RT_EllipticArcSegment_getCenterPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getCenterPoint")));
    
    return RT_EllipticArcSegment_getCenterPoint_func(thisHandle, errorHandler);
}

double RT_EllipticArcSegment_getCentralAngle(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EllipticArcSegment_getCentralAngle_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getCentralAngle_func = reinterpret_cast<RT_EllipticArcSegment_getCentralAngle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getCentralAngle")));
    
    return RT_EllipticArcSegment_getCentralAngle_func(thisHandle, errorHandler);
}

double RT_EllipticArcSegment_getEndAngle(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EllipticArcSegment_getEndAngle_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getEndAngle_func = reinterpret_cast<RT_EllipticArcSegment_getEndAngle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getEndAngle")));
    
    return RT_EllipticArcSegment_getEndAngle_func(thisHandle, errorHandler);
}

bool RT_EllipticArcSegment_getIsCircular(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_EllipticArcSegment_getIsCircular_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getIsCircular_func = reinterpret_cast<RT_EllipticArcSegment_getIsCircular_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getIsCircular")));
    
    return RT_EllipticArcSegment_getIsCircular_func(thisHandle, errorHandler);
}

bool RT_EllipticArcSegment_getIsCounterClockwise(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_EllipticArcSegment_getIsCounterClockwise_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getIsCounterClockwise_func = reinterpret_cast<RT_EllipticArcSegment_getIsCounterClockwise_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getIsCounterClockwise")));
    
    return RT_EllipticArcSegment_getIsCounterClockwise_func(thisHandle, errorHandler);
}

double RT_EllipticArcSegment_getMinorMajorRatio(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EllipticArcSegment_getMinorMajorRatio_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getMinorMajorRatio_func = reinterpret_cast<RT_EllipticArcSegment_getMinorMajorRatio_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getMinorMajorRatio")));
    
    return RT_EllipticArcSegment_getMinorMajorRatio_func(thisHandle, errorHandler);
}

double RT_EllipticArcSegment_getRotationAngle(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EllipticArcSegment_getRotationAngle_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getRotationAngle_func = reinterpret_cast<RT_EllipticArcSegment_getRotationAngle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getRotationAngle")));
    
    return RT_EllipticArcSegment_getRotationAngle_func(thisHandle, errorHandler);
}

double RT_EllipticArcSegment_getSemiMajorAxis(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EllipticArcSegment_getSemiMajorAxis_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getSemiMajorAxis_func = reinterpret_cast<RT_EllipticArcSegment_getSemiMajorAxis_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getSemiMajorAxis")));
    
    return RT_EllipticArcSegment_getSemiMajorAxis_func(thisHandle, errorHandler);
}

double RT_EllipticArcSegment_getSemiMinorAxis(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EllipticArcSegment_getSemiMinorAxis_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getSemiMinorAxis_func = reinterpret_cast<RT_EllipticArcSegment_getSemiMinorAxis_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getSemiMinorAxis")));
    
    return RT_EllipticArcSegment_getSemiMinorAxis_func(thisHandle, errorHandler);
}

double RT_EllipticArcSegment_getStartAngle(const RT_EllipticArcSegmentHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EllipticArcSegment_getStartAngle_def)(const RT_EllipticArcSegmentHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_getStartAngle_func = reinterpret_cast<RT_EllipticArcSegment_getStartAngle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_getStartAngle")));
    
    return RT_EllipticArcSegment_getStartAngle_func(thisHandle, errorHandler);
}

RT_EllipticArcSegmentHandle RT_EllipticArcSegment_createCircularEllipticArcWithCenterRadiusAndAngles(const RT_PointHandle centerPoint, double radius, double startAngle, double centralAngle, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EllipticArcSegmentHandle (*RT_EllipticArcSegment_createCircularEllipticArcWithCenterRadiusAndAngles_def)(const RT_PointHandle, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_createCircularEllipticArcWithCenterRadiusAndAngles_func = reinterpret_cast<RT_EllipticArcSegment_createCircularEllipticArcWithCenterRadiusAndAngles_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_createCircularEllipticArcWithCenterRadiusAndAngles")));
    
    return RT_EllipticArcSegment_createCircularEllipticArcWithCenterRadiusAndAngles_func(centerPoint, radius, startAngle, centralAngle, spatialReference, errorHandler);
}

RT_EllipticArcSegmentHandle RT_EllipticArcSegment_createCircularEllipticArcWithStartEndAndInterior(const RT_PointHandle startPoint, const RT_PointHandle endPoint, const RT_PointHandle interiorPoint, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EllipticArcSegmentHandle (*RT_EllipticArcSegment_createCircularEllipticArcWithStartEndAndInterior_def)(const RT_PointHandle, const RT_PointHandle, const RT_PointHandle, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_EllipticArcSegment_createCircularEllipticArcWithStartEndAndInterior_func = reinterpret_cast<RT_EllipticArcSegment_createCircularEllipticArcWithStartEndAndInterior_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EllipticArcSegment_createCircularEllipticArcWithStartEndAndInterior")));
    
    return RT_EllipticArcSegment_createCircularEllipticArcWithStartEndAndInterior_func(startPoint, endPoint, interiorPoint, spatialReference, errorHandler);
}
#endif