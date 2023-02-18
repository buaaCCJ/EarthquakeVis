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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointBuilder.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_PointBuilder_destroy(RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_destroy_def)(RT_PointBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_destroy_func = reinterpret_cast<RT_PointBuilder_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_destroy")));
    
    RT_PointBuilder_destroy_func(thisHandle, errorHandler);
}

RT_PointBuilderHandle RT_PointBuilder_createFromPoint(const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointBuilderHandle (*RT_PointBuilder_createFromPoint_def)(const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_createFromPoint_func = reinterpret_cast<RT_PointBuilder_createFromPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_createFromPoint")));
    
    return RT_PointBuilder_createFromPoint_func(point, errorHandler);
}

RT_PointBuilderHandle RT_PointBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointBuilderHandle (*RT_PointBuilder_createFromSpatialReference_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_createFromSpatialReference_func = reinterpret_cast<RT_PointBuilder_createFromSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_createFromSpatialReference")));
    
    return RT_PointBuilder_createFromSpatialReference_func(spatialReference, errorHandler);
}

double RT_PointBuilder_getM(const RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_PointBuilder_getM_def)(const RT_PointBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_getM_func = reinterpret_cast<RT_PointBuilder_getM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_getM")));
    
    return RT_PointBuilder_getM_func(thisHandle, errorHandler);
}
void RT_PointBuilder_setM(RT_PointBuilderHandle thisHandle, double m, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_setM_def)(RT_PointBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_PointBuilder_setM_func = reinterpret_cast<RT_PointBuilder_setM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_setM")));
    
    RT_PointBuilder_setM_func(thisHandle, m, errorHandler);
}

double RT_PointBuilder_getX(const RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_PointBuilder_getX_def)(const RT_PointBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_getX_func = reinterpret_cast<RT_PointBuilder_getX_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_getX")));
    
    return RT_PointBuilder_getX_func(thisHandle, errorHandler);
}
void RT_PointBuilder_setX(RT_PointBuilderHandle thisHandle, double x, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_setX_def)(RT_PointBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_PointBuilder_setX_func = reinterpret_cast<RT_PointBuilder_setX_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_setX")));
    
    RT_PointBuilder_setX_func(thisHandle, x, errorHandler);
}

double RT_PointBuilder_getY(const RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_PointBuilder_getY_def)(const RT_PointBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_getY_func = reinterpret_cast<RT_PointBuilder_getY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_getY")));
    
    return RT_PointBuilder_getY_func(thisHandle, errorHandler);
}
void RT_PointBuilder_setY(RT_PointBuilderHandle thisHandle, double y, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_setY_def)(RT_PointBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_PointBuilder_setY_func = reinterpret_cast<RT_PointBuilder_setY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_setY")));
    
    RT_PointBuilder_setY_func(thisHandle, y, errorHandler);
}

double RT_PointBuilder_getZ(const RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_PointBuilder_getZ_def)(const RT_PointBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_getZ_func = reinterpret_cast<RT_PointBuilder_getZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_getZ")));
    
    return RT_PointBuilder_getZ_func(thisHandle, errorHandler);
}
void RT_PointBuilder_setZ(RT_PointBuilderHandle thisHandle, double z, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_setZ_def)(RT_PointBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_PointBuilder_setZ_func = reinterpret_cast<RT_PointBuilder_setZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_setZ")));
    
    RT_PointBuilder_setZ_func(thisHandle, z, errorHandler);
}

void RT_PointBuilder_normalize(RT_PointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_normalize_def)(RT_PointBuilderHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_normalize_func = reinterpret_cast<RT_PointBuilder_normalize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_normalize")));
    
    RT_PointBuilder_normalize_func(thisHandle, errorHandler);
}

void RT_PointBuilder_normalizeToEnvelope(RT_PointBuilderHandle thisHandle, const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_normalizeToEnvelope_def)(RT_PointBuilderHandle, const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_normalizeToEnvelope_func = reinterpret_cast<RT_PointBuilder_normalizeToEnvelope_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_normalizeToEnvelope")));
    
    RT_PointBuilder_normalizeToEnvelope_func(thisHandle, envelope, errorHandler);
}

void RT_PointBuilder_normalizeToPointClosestTo(RT_PointBuilderHandle thisHandle, const RT_PointHandle target, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_normalizeToPointClosestTo_def)(RT_PointBuilderHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_PointBuilder_normalizeToPointClosestTo_func = reinterpret_cast<RT_PointBuilder_normalizeToPointClosestTo_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_normalizeToPointClosestTo")));
    
    RT_PointBuilder_normalizeToPointClosestTo_func(thisHandle, target, errorHandler);
}

void RT_PointBuilder_offsetBy(RT_PointBuilderHandle thisHandle, double offsetX, double offsetY, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_offsetBy_def)(RT_PointBuilderHandle, double, double, const RT_ErrorHandler*);
    static auto RT_PointBuilder_offsetBy_func = reinterpret_cast<RT_PointBuilder_offsetBy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_offsetBy")));
    
    RT_PointBuilder_offsetBy_func(thisHandle, offsetX, offsetY, errorHandler);
}

void RT_PointBuilder_setXY(RT_PointBuilderHandle thisHandle, double x, double y, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_PointBuilder_setXY_def)(RT_PointBuilderHandle, double, double, const RT_ErrorHandler*);
    static auto RT_PointBuilder_setXY_func = reinterpret_cast<RT_PointBuilder_setXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_PointBuilder_setXY")));
    
    RT_PointBuilder_setXY_func(thisHandle, x, y, errorHandler);
}
#endif