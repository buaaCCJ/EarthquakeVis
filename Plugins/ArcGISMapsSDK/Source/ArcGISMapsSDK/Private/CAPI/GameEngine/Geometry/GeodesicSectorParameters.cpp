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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodesicSectorParameters.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GeodesicSectorParameters_destroy(RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_destroy_def)(RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_destroy_func = reinterpret_cast<RT_GeodesicSectorParameters_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_destroy")));
    
    RT_GeodesicSectorParameters_destroy_func(thisHandle, errorHandler);
}

RT_GeodesicSectorParametersHandle RT_GeodesicSectorParameters_create(const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeodesicSectorParametersHandle (*RT_GeodesicSectorParameters_create_def)(const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_create_func = reinterpret_cast<RT_GeodesicSectorParameters_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_create")));
    
    return RT_GeodesicSectorParameters_create_func(errorHandler);
}

RT_GeodesicSectorParametersHandle RT_GeodesicSectorParameters_createWith(double axisDirection, const RT_AngularUnitHandle angularUnit, const RT_PointHandle center, const RT_LinearUnitHandle linearUnit, uint32_t maxPointCount, double maxSegmentLength, RT_GeometryType geometryType, double sectorAngle, double semiAxis1Length, double semiAxis2Length, double startDirection, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeodesicSectorParametersHandle (*RT_GeodesicSectorParameters_createWith_def)(double, const RT_AngularUnitHandle, const RT_PointHandle, const RT_LinearUnitHandle, uint32_t, double, RT_GeometryType, double, double, double, double, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_createWith_func = reinterpret_cast<RT_GeodesicSectorParameters_createWith_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_createWith")));
    
    return RT_GeodesicSectorParameters_createWith_func(axisDirection, angularUnit, center, linearUnit, maxPointCount, maxSegmentLength, geometryType, sectorAngle, semiAxis1Length, semiAxis2Length, startDirection, errorHandler);
}

RT_GeodesicSectorParametersHandle RT_GeodesicSectorParameters_createWithCenterAndAxisLengthsAndSectorAngleAndStartDirection(const RT_PointHandle center, double semiAxis1Length, double semiAxis2Length, double sectorAngle, double startDirection, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeodesicSectorParametersHandle (*RT_GeodesicSectorParameters_createWithCenterAndAxisLengthsAndSectorAngleAndStartDirection_def)(const RT_PointHandle, double, double, double, double, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_createWithCenterAndAxisLengthsAndSectorAngleAndStartDirection_func = reinterpret_cast<RT_GeodesicSectorParameters_createWithCenterAndAxisLengthsAndSectorAngleAndStartDirection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_createWithCenterAndAxisLengthsAndSectorAngleAndStartDirection")));
    
    return RT_GeodesicSectorParameters_createWithCenterAndAxisLengthsAndSectorAngleAndStartDirection_func(center, semiAxis1Length, semiAxis2Length, sectorAngle, startDirection, errorHandler);
}

RT_AngularUnitHandle RT_GeodesicSectorParameters_getAngularUnit(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_AngularUnitHandle (*RT_GeodesicSectorParameters_getAngularUnit_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getAngularUnit_func = reinterpret_cast<RT_GeodesicSectorParameters_getAngularUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getAngularUnit")));
    
    return RT_GeodesicSectorParameters_getAngularUnit_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setAngularUnit(RT_GeodesicSectorParametersHandle thisHandle, RT_AngularUnitHandle angularUnit, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setAngularUnit_def)(RT_GeodesicSectorParametersHandle, RT_AngularUnitHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setAngularUnit_func = reinterpret_cast<RT_GeodesicSectorParameters_setAngularUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setAngularUnit")));
    
    RT_GeodesicSectorParameters_setAngularUnit_func(thisHandle, angularUnit, errorHandler);
}

double RT_GeodesicSectorParameters_getAxisDirection(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicSectorParameters_getAxisDirection_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getAxisDirection_func = reinterpret_cast<RT_GeodesicSectorParameters_getAxisDirection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getAxisDirection")));
    
    return RT_GeodesicSectorParameters_getAxisDirection_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setAxisDirection(RT_GeodesicSectorParametersHandle thisHandle, double axisDirection, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setAxisDirection_def)(RT_GeodesicSectorParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setAxisDirection_func = reinterpret_cast<RT_GeodesicSectorParameters_setAxisDirection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setAxisDirection")));
    
    RT_GeodesicSectorParameters_setAxisDirection_func(thisHandle, axisDirection, errorHandler);
}

RT_PointHandle RT_GeodesicSectorParameters_getCenter(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_GeodesicSectorParameters_getCenter_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getCenter_func = reinterpret_cast<RT_GeodesicSectorParameters_getCenter_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getCenter")));
    
    return RT_GeodesicSectorParameters_getCenter_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setCenter(RT_GeodesicSectorParametersHandle thisHandle, RT_PointHandle center, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setCenter_def)(RT_GeodesicSectorParametersHandle, RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setCenter_func = reinterpret_cast<RT_GeodesicSectorParameters_setCenter_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setCenter")));
    
    RT_GeodesicSectorParameters_setCenter_func(thisHandle, center, errorHandler);
}

RT_GeometryType RT_GeodesicSectorParameters_getGeometryType(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryType (*RT_GeodesicSectorParameters_getGeometryType_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getGeometryType_func = reinterpret_cast<RT_GeodesicSectorParameters_getGeometryType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getGeometryType")));
    
    return RT_GeodesicSectorParameters_getGeometryType_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setGeometryType(RT_GeodesicSectorParametersHandle thisHandle, RT_GeometryType geometryType, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setGeometryType_def)(RT_GeodesicSectorParametersHandle, RT_GeometryType, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setGeometryType_func = reinterpret_cast<RT_GeodesicSectorParameters_setGeometryType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setGeometryType")));
    
    RT_GeodesicSectorParameters_setGeometryType_func(thisHandle, geometryType, errorHandler);
}

RT_LinearUnitHandle RT_GeodesicSectorParameters_getLinearUnit(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LinearUnitHandle (*RT_GeodesicSectorParameters_getLinearUnit_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getLinearUnit_func = reinterpret_cast<RT_GeodesicSectorParameters_getLinearUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getLinearUnit")));
    
    return RT_GeodesicSectorParameters_getLinearUnit_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setLinearUnit(RT_GeodesicSectorParametersHandle thisHandle, RT_LinearUnitHandle linearUnit, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setLinearUnit_def)(RT_GeodesicSectorParametersHandle, RT_LinearUnitHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setLinearUnit_func = reinterpret_cast<RT_GeodesicSectorParameters_setLinearUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setLinearUnit")));
    
    RT_GeodesicSectorParameters_setLinearUnit_func(thisHandle, linearUnit, errorHandler);
}

uint32_t RT_GeodesicSectorParameters_getMaxPointCount(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef uint32_t (*RT_GeodesicSectorParameters_getMaxPointCount_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getMaxPointCount_func = reinterpret_cast<RT_GeodesicSectorParameters_getMaxPointCount_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getMaxPointCount")));
    
    return RT_GeodesicSectorParameters_getMaxPointCount_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setMaxPointCount(RT_GeodesicSectorParametersHandle thisHandle, uint32_t maxPointCount, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setMaxPointCount_def)(RT_GeodesicSectorParametersHandle, uint32_t, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setMaxPointCount_func = reinterpret_cast<RT_GeodesicSectorParameters_setMaxPointCount_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setMaxPointCount")));
    
    RT_GeodesicSectorParameters_setMaxPointCount_func(thisHandle, maxPointCount, errorHandler);
}

double RT_GeodesicSectorParameters_getMaxSegmentLength(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicSectorParameters_getMaxSegmentLength_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getMaxSegmentLength_func = reinterpret_cast<RT_GeodesicSectorParameters_getMaxSegmentLength_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getMaxSegmentLength")));
    
    return RT_GeodesicSectorParameters_getMaxSegmentLength_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setMaxSegmentLength(RT_GeodesicSectorParametersHandle thisHandle, double maxSegmentLength, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setMaxSegmentLength_def)(RT_GeodesicSectorParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setMaxSegmentLength_func = reinterpret_cast<RT_GeodesicSectorParameters_setMaxSegmentLength_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setMaxSegmentLength")));
    
    RT_GeodesicSectorParameters_setMaxSegmentLength_func(thisHandle, maxSegmentLength, errorHandler);
}

double RT_GeodesicSectorParameters_getSectorAngle(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicSectorParameters_getSectorAngle_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getSectorAngle_func = reinterpret_cast<RT_GeodesicSectorParameters_getSectorAngle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getSectorAngle")));
    
    return RT_GeodesicSectorParameters_getSectorAngle_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setSectorAngle(RT_GeodesicSectorParametersHandle thisHandle, double sectorAngle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setSectorAngle_def)(RT_GeodesicSectorParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setSectorAngle_func = reinterpret_cast<RT_GeodesicSectorParameters_setSectorAngle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setSectorAngle")));
    
    RT_GeodesicSectorParameters_setSectorAngle_func(thisHandle, sectorAngle, errorHandler);
}

double RT_GeodesicSectorParameters_getSemiAxis1Length(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicSectorParameters_getSemiAxis1Length_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getSemiAxis1Length_func = reinterpret_cast<RT_GeodesicSectorParameters_getSemiAxis1Length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getSemiAxis1Length")));
    
    return RT_GeodesicSectorParameters_getSemiAxis1Length_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setSemiAxis1Length(RT_GeodesicSectorParametersHandle thisHandle, double semiAxis1Length, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setSemiAxis1Length_def)(RT_GeodesicSectorParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setSemiAxis1Length_func = reinterpret_cast<RT_GeodesicSectorParameters_setSemiAxis1Length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setSemiAxis1Length")));
    
    RT_GeodesicSectorParameters_setSemiAxis1Length_func(thisHandle, semiAxis1Length, errorHandler);
}

double RT_GeodesicSectorParameters_getSemiAxis2Length(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicSectorParameters_getSemiAxis2Length_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getSemiAxis2Length_func = reinterpret_cast<RT_GeodesicSectorParameters_getSemiAxis2Length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getSemiAxis2Length")));
    
    return RT_GeodesicSectorParameters_getSemiAxis2Length_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setSemiAxis2Length(RT_GeodesicSectorParametersHandle thisHandle, double semiAxis2Length, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setSemiAxis2Length_def)(RT_GeodesicSectorParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setSemiAxis2Length_func = reinterpret_cast<RT_GeodesicSectorParameters_setSemiAxis2Length_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setSemiAxis2Length")));
    
    RT_GeodesicSectorParameters_setSemiAxis2Length_func(thisHandle, semiAxis2Length, errorHandler);
}

double RT_GeodesicSectorParameters_getStartDirection(const RT_GeodesicSectorParametersHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_GeodesicSectorParameters_getStartDirection_def)(const RT_GeodesicSectorParametersHandle, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_getStartDirection_func = reinterpret_cast<RT_GeodesicSectorParameters_getStartDirection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_getStartDirection")));
    
    return RT_GeodesicSectorParameters_getStartDirection_func(thisHandle, errorHandler);
}
void RT_GeodesicSectorParameters_setStartDirection(RT_GeodesicSectorParametersHandle thisHandle, double startDirection, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeodesicSectorParameters_setStartDirection_def)(RT_GeodesicSectorParametersHandle, double, const RT_ErrorHandler*);
    static auto RT_GeodesicSectorParameters_setStartDirection_func = reinterpret_cast<RT_GeodesicSectorParameters_setStartDirection_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeodesicSectorParameters_setStartDirection")));
    
    RT_GeodesicSectorParameters_setStartDirection_func(thisHandle, startDirection, errorHandler);
}
#endif