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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodesicEllipseParameters.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GeodesicEllipseParameters_destroy(RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_destroy_def)(RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_destroy_func = reinterpret_cast<RT_GeodesicEllipseParameters_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_destroy")));
    
    RT_GeodesicEllipseParameters_destroy_func(thisHandle, errorHandler);
}

RT_GeodesicEllipseParametersHandle RT_GeodesicEllipseParameters_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeodesicEllipseParametersHandle (*RT_GeodesicEllipseParameters_create_def)(const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_create_func = reinterpret_cast<RT_GeodesicEllipseParameters_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_create")));
    
    return RT_GeodesicEllipseParameters_create_func(errorHandler);
}

RT_GeodesicEllipseParametersHandle RT_GeodesicEllipseParameters_createWith(double axisDirection, const RT_AngularUnitHandle angularUnit, const RT_PointHandle center, const RT_LinearUnitHandle linearUnit, uint32_t maxPointCount, double maxSegmentLength, RT_GeometryType geometryType, double semiAxis1Length, double semiAxis2Length, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeodesicEllipseParametersHandle (*RT_GeodesicEllipseParameters_createWith_def)(double, const RT_AngularUnitHandle, const RT_PointHandle, const RT_LinearUnitHandle, uint32_t, double, RT_GeometryType, double, double, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_createWith_func = reinterpret_cast<RT_GeodesicEllipseParameters_createWith_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_createWith")));
    
    return RT_GeodesicEllipseParameters_createWith_func(axisDirection, angularUnit, center, linearUnit, maxPointCount, maxSegmentLength, geometryType, semiAxis1Length, semiAxis2Length, errorHandler);
}

RT_GeodesicEllipseParametersHandle RT_GeodesicEllipseParameters_createWithCenterAndAxisLengths(const RT_PointHandle center, double semiAxis1Length, double semiAxis2Length, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeodesicEllipseParametersHandle (*RT_GeodesicEllipseParameters_createWithCenterAndAxisLengths_def)(const RT_PointHandle, double, double, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_createWithCenterAndAxisLengths_func = reinterpret_cast<RT_GeodesicEllipseParameters_createWithCenterAndAxisLengths_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_createWithCenterAndAxisLengths")));
    
    return RT_GeodesicEllipseParameters_createWithCenterAndAxisLengths_func(center, semiAxis1Length, semiAxis2Length, errorHandler);
}

RT_AngularUnitHandle RT_GeodesicEllipseParameters_getAngularUnit(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AngularUnitHandle (*RT_GeodesicEllipseParameters_getAngularUnit_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getAngularUnit_func = reinterpret_cast<RT_GeodesicEllipseParameters_getAngularUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getAngularUnit")));
    
    return RT_GeodesicEllipseParameters_getAngularUnit_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setAngularUnit(RT_GeodesicEllipseParametersHandle thisHandle, RT_AngularUnitHandle angularUnit, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setAngularUnit_def)(RT_GeodesicEllipseParametersHandle, RT_AngularUnitHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setAngularUnit_func = reinterpret_cast<RT_GeodesicEllipseParameters_setAngularUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setAngularUnit")));
    
    RT_GeodesicEllipseParameters_setAngularUnit_func(thisHandle, angularUnit, errorHandler);
}

double RT_GeodesicEllipseParameters_getAxisDirection(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicEllipseParameters_getAxisDirection_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getAxisDirection_func = reinterpret_cast<RT_GeodesicEllipseParameters_getAxisDirection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getAxisDirection")));
    
    return RT_GeodesicEllipseParameters_getAxisDirection_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setAxisDirection(RT_GeodesicEllipseParametersHandle thisHandle, double axisDirection, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setAxisDirection_def)(RT_GeodesicEllipseParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setAxisDirection_func = reinterpret_cast<RT_GeodesicEllipseParameters_setAxisDirection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setAxisDirection")));
    
    RT_GeodesicEllipseParameters_setAxisDirection_func(thisHandle, axisDirection, errorHandler);
}

RT_PointHandle RT_GeodesicEllipseParameters_getCenter(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_GeodesicEllipseParameters_getCenter_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getCenter_func = reinterpret_cast<RT_GeodesicEllipseParameters_getCenter_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getCenter")));
    
    return RT_GeodesicEllipseParameters_getCenter_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setCenter(RT_GeodesicEllipseParametersHandle thisHandle, RT_PointHandle center, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setCenter_def)(RT_GeodesicEllipseParametersHandle, RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setCenter_func = reinterpret_cast<RT_GeodesicEllipseParameters_setCenter_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setCenter")));
    
    RT_GeodesicEllipseParameters_setCenter_func(thisHandle, center, errorHandler);
}

RT_GeometryType RT_GeodesicEllipseParameters_getGeometryType(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryType (*RT_GeodesicEllipseParameters_getGeometryType_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getGeometryType_func = reinterpret_cast<RT_GeodesicEllipseParameters_getGeometryType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getGeometryType")));
    
    return RT_GeodesicEllipseParameters_getGeometryType_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setGeometryType(RT_GeodesicEllipseParametersHandle thisHandle, RT_GeometryType geometryType, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setGeometryType_def)(RT_GeodesicEllipseParametersHandle, RT_GeometryType, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setGeometryType_func = reinterpret_cast<RT_GeodesicEllipseParameters_setGeometryType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setGeometryType")));
    
    RT_GeodesicEllipseParameters_setGeometryType_func(thisHandle, geometryType, errorHandler);
}

RT_LinearUnitHandle RT_GeodesicEllipseParameters_getLinearUnit(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LinearUnitHandle (*RT_GeodesicEllipseParameters_getLinearUnit_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getLinearUnit_func = reinterpret_cast<RT_GeodesicEllipseParameters_getLinearUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getLinearUnit")));
    
    return RT_GeodesicEllipseParameters_getLinearUnit_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setLinearUnit(RT_GeodesicEllipseParametersHandle thisHandle, RT_LinearUnitHandle linearUnit, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setLinearUnit_def)(RT_GeodesicEllipseParametersHandle, RT_LinearUnitHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setLinearUnit_func = reinterpret_cast<RT_GeodesicEllipseParameters_setLinearUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setLinearUnit")));
    
    RT_GeodesicEllipseParameters_setLinearUnit_func(thisHandle, linearUnit, errorHandler);
}

uint32_t RT_GeodesicEllipseParameters_getMaxPointCount(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef uint32_t (*RT_GeodesicEllipseParameters_getMaxPointCount_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getMaxPointCount_func = reinterpret_cast<RT_GeodesicEllipseParameters_getMaxPointCount_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getMaxPointCount")));
    
    return RT_GeodesicEllipseParameters_getMaxPointCount_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setMaxPointCount(RT_GeodesicEllipseParametersHandle thisHandle, uint32_t maxPointCount, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setMaxPointCount_def)(RT_GeodesicEllipseParametersHandle, uint32_t, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setMaxPointCount_func = reinterpret_cast<RT_GeodesicEllipseParameters_setMaxPointCount_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setMaxPointCount")));
    
    RT_GeodesicEllipseParameters_setMaxPointCount_func(thisHandle, maxPointCount, errorHandler);
}

double RT_GeodesicEllipseParameters_getMaxSegmentLength(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicEllipseParameters_getMaxSegmentLength_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getMaxSegmentLength_func = reinterpret_cast<RT_GeodesicEllipseParameters_getMaxSegmentLength_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getMaxSegmentLength")));
    
    return RT_GeodesicEllipseParameters_getMaxSegmentLength_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setMaxSegmentLength(RT_GeodesicEllipseParametersHandle thisHandle, double maxSegmentLength, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setMaxSegmentLength_def)(RT_GeodesicEllipseParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setMaxSegmentLength_func = reinterpret_cast<RT_GeodesicEllipseParameters_setMaxSegmentLength_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setMaxSegmentLength")));
    
    RT_GeodesicEllipseParameters_setMaxSegmentLength_func(thisHandle, maxSegmentLength, errorHandler);
}

double RT_GeodesicEllipseParameters_getSemiAxis1Length(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicEllipseParameters_getSemiAxis1Length_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getSemiAxis1Length_func = reinterpret_cast<RT_GeodesicEllipseParameters_getSemiAxis1Length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getSemiAxis1Length")));
    
    return RT_GeodesicEllipseParameters_getSemiAxis1Length_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setSemiAxis1Length(RT_GeodesicEllipseParametersHandle thisHandle, double semiAxis1Length, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setSemiAxis1Length_def)(RT_GeodesicEllipseParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setSemiAxis1Length_func = reinterpret_cast<RT_GeodesicEllipseParameters_setSemiAxis1Length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setSemiAxis1Length")));
    
    RT_GeodesicEllipseParameters_setSemiAxis1Length_func(thisHandle, semiAxis1Length, errorHandler);
}

double RT_GeodesicEllipseParameters_getSemiAxis2Length(const RT_GeodesicEllipseParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicEllipseParameters_getSemiAxis2Length_def)(const RT_GeodesicEllipseParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_getSemiAxis2Length_func = reinterpret_cast<RT_GeodesicEllipseParameters_getSemiAxis2Length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_getSemiAxis2Length")));
    
    return RT_GeodesicEllipseParameters_getSemiAxis2Length_func(thisHandle, errorHandler);
}
void RT_GeodesicEllipseParameters_setSemiAxis2Length(RT_GeodesicEllipseParametersHandle thisHandle, double semiAxis2Length, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicEllipseParameters_setSemiAxis2Length_def)(RT_GeodesicEllipseParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicEllipseParameters_setSemiAxis2Length_func = reinterpret_cast<RT_GeodesicEllipseParameters_setSemiAxis2Length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicEllipseParameters_setSemiAxis2Length")));
    
    RT_GeodesicEllipseParameters_setSemiAxis2Length_func(thisHandle, semiAxis2Length, errorHandler);
}
#endif