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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Point.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Point_destroy(RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Point_destroy_def)(RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_Point_destroy_func = reinterpret_cast<RT_Point_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_destroy")));
    
    RT_Point_destroy_func(thisHandle, errorHandler);
}

RT_PointHandle RT_Point_createWithXY(double x, double y, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Point_createWithXY_def)(double, double, const RT_ErrorHandler*);
    static auto RT_Point_createWithXY_func = reinterpret_cast<RT_Point_createWithXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_createWithXY")));
    
    return RT_Point_createWithXY_func(x, y, errorHandler);
}

RT_PointHandle RT_Point_createWithXYZ(double x, double y, double z, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Point_createWithXYZ_def)(double, double, double, const RT_ErrorHandler*);
    static auto RT_Point_createWithXYZ_func = reinterpret_cast<RT_Point_createWithXYZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_createWithXYZ")));
    
    return RT_Point_createWithXYZ_func(x, y, z, errorHandler);
}

RT_PointHandle RT_Point_createWithXYZSpatialReference(double x, double y, double z, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Point_createWithXYZSpatialReference_def)(double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Point_createWithXYZSpatialReference_func = reinterpret_cast<RT_Point_createWithXYZSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_createWithXYZSpatialReference")));
    
    return RT_Point_createWithXYZSpatialReference_func(x, y, z, spatialReference, errorHandler);
}

RT_PointHandle RT_Point_createWithXYSpatialReference(double x, double y, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Point_createWithXYSpatialReference_def)(double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Point_createWithXYSpatialReference_func = reinterpret_cast<RT_Point_createWithXYSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_createWithXYSpatialReference")));
    
    return RT_Point_createWithXYSpatialReference_func(x, y, spatialReference, errorHandler);
}

double RT_Point_getM(const RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Point_getM_def)(const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_Point_getM_func = reinterpret_cast<RT_Point_getM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_getM")));
    
    return RT_Point_getM_func(thisHandle, errorHandler);
}

double RT_Point_getX(const RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Point_getX_def)(const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_Point_getX_func = reinterpret_cast<RT_Point_getX_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_getX")));
    
    return RT_Point_getX_func(thisHandle, errorHandler);
}

double RT_Point_getY(const RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Point_getY_def)(const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_Point_getY_func = reinterpret_cast<RT_Point_getY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_getY")));
    
    return RT_Point_getY_func(thisHandle, errorHandler);
}

double RT_Point_getZ(const RT_PointHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Point_getZ_def)(const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_Point_getZ_func = reinterpret_cast<RT_Point_getZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_getZ")));
    
    return RT_Point_getZ_func(thisHandle, errorHandler);
}

RT_PointHandle RT_Point_createWithM(double x, double y, double m, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Point_createWithM_def)(double, double, double, const RT_ErrorHandler*);
    static auto RT_Point_createWithM_func = reinterpret_cast<RT_Point_createWithM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_createWithM")));
    
    return RT_Point_createWithM_func(x, y, m, errorHandler);
}

RT_PointHandle RT_Point_createWithZM(double x, double y, double z, double m, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Point_createWithZM_def)(double, double, double, double, const RT_ErrorHandler*);
    static auto RT_Point_createWithZM_func = reinterpret_cast<RT_Point_createWithZM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_createWithZM")));
    
    return RT_Point_createWithZM_func(x, y, z, m, errorHandler);
}

RT_PointHandle RT_Point_createWithZMSpatialReference(double x, double y, double z, double m, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Point_createWithZMSpatialReference_def)(double, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Point_createWithZMSpatialReference_func = reinterpret_cast<RT_Point_createWithZMSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_createWithZMSpatialReference")));
    
    return RT_Point_createWithZMSpatialReference_func(x, y, z, m, spatialReference, errorHandler);
}

RT_PointHandle RT_Point_createWithMSpatialReference(double x, double y, double m, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Point_createWithMSpatialReference_def)(double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Point_createWithMSpatialReference_func = reinterpret_cast<RT_Point_createWithMSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Point_createWithMSpatialReference")));
    
    return RT_Point_createWithMSpatialReference_func(x, y, m, spatialReference, errorHandler);
}
#endif