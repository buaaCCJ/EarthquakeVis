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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Envelope.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Envelope_destroy(RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Envelope_destroy_def)(RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_destroy_func = reinterpret_cast<RT_Envelope_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_destroy")));
    
    RT_Envelope_destroy_func(thisHandle, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithXY(double xMin, double yMin, double xMax, double yMax, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithXY_def)(double, double, double, double, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithXY_func = reinterpret_cast<RT_Envelope_createWithXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithXY")));
    
    return RT_Envelope_createWithXY_func(xMin, yMin, xMax, yMax, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithXYZ(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithXYZ_def)(double, double, double, double, double, double, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithXYZ_func = reinterpret_cast<RT_Envelope_createWithXYZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithXYZ")));
    
    return RT_Envelope_createWithXYZ_func(xMin, yMin, xMax, yMax, zMin, zMax, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithXYZSpatialReference(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithXYZSpatialReference_def)(double, double, double, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithXYZSpatialReference_func = reinterpret_cast<RT_Envelope_createWithXYZSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithXYZSpatialReference")));
    
    return RT_Envelope_createWithXYZSpatialReference_func(xMin, yMin, xMax, yMax, zMin, zMax, spatialReference, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithXYSpatialReference(double xMin, double yMin, double xMax, double yMax, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithXYSpatialReference_def)(double, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithXYSpatialReference_func = reinterpret_cast<RT_Envelope_createWithXYSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithXYSpatialReference")));
    
    return RT_Envelope_createWithXYSpatialReference_func(xMin, yMin, xMax, yMax, spatialReference, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithCenterPoint(const RT_PointHandle center, double width, double height, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithCenterPoint_def)(const RT_PointHandle, double, double, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithCenterPoint_func = reinterpret_cast<RT_Envelope_createWithCenterPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithCenterPoint")));
    
    return RT_Envelope_createWithCenterPoint_func(center, width, height, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithCenterPointAndDepth(const RT_PointHandle center, double width, double height, double depth, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithCenterPointAndDepth_def)(const RT_PointHandle, double, double, double, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithCenterPointAndDepth_func = reinterpret_cast<RT_Envelope_createWithCenterPointAndDepth_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithCenterPointAndDepth")));
    
    return RT_Envelope_createWithCenterPointAndDepth_func(center, width, height, depth, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithPoints(const RT_PointHandle min, const RT_PointHandle max, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithPoints_def)(const RT_PointHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithPoints_func = reinterpret_cast<RT_Envelope_createWithPoints_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithPoints")));
    
    return RT_Envelope_createWithPoints_func(min, max, errorHandler);
}

RT_PointHandle RT_Envelope_getCenter(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Envelope_getCenter_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getCenter_func = reinterpret_cast<RT_Envelope_getCenter_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getCenter")));
    
    return RT_Envelope_getCenter_func(thisHandle, errorHandler);
}

double RT_Envelope_getDepth(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getDepth_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getDepth_func = reinterpret_cast<RT_Envelope_getDepth_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getDepth")));
    
    return RT_Envelope_getDepth_func(thisHandle, errorHandler);
}

double RT_Envelope_getHeight(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getHeight_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getHeight_func = reinterpret_cast<RT_Envelope_getHeight_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getHeight")));
    
    return RT_Envelope_getHeight_func(thisHandle, errorHandler);
}

double RT_Envelope_getMMax(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getMMax_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getMMax_func = reinterpret_cast<RT_Envelope_getMMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getMMax")));
    
    return RT_Envelope_getMMax_func(thisHandle, errorHandler);
}

double RT_Envelope_getMMin(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getMMin_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getMMin_func = reinterpret_cast<RT_Envelope_getMMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getMMin")));
    
    return RT_Envelope_getMMin_func(thisHandle, errorHandler);
}

double RT_Envelope_getWidth(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getWidth_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getWidth_func = reinterpret_cast<RT_Envelope_getWidth_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getWidth")));
    
    return RT_Envelope_getWidth_func(thisHandle, errorHandler);
}

double RT_Envelope_getXMax(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getXMax_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getXMax_func = reinterpret_cast<RT_Envelope_getXMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getXMax")));
    
    return RT_Envelope_getXMax_func(thisHandle, errorHandler);
}

double RT_Envelope_getXMin(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getXMin_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getXMin_func = reinterpret_cast<RT_Envelope_getXMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getXMin")));
    
    return RT_Envelope_getXMin_func(thisHandle, errorHandler);
}

double RT_Envelope_getYMax(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getYMax_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getYMax_func = reinterpret_cast<RT_Envelope_getYMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getYMax")));
    
    return RT_Envelope_getYMax_func(thisHandle, errorHandler);
}

double RT_Envelope_getYMin(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getYMin_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getYMin_func = reinterpret_cast<RT_Envelope_getYMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getYMin")));
    
    return RT_Envelope_getYMin_func(thisHandle, errorHandler);
}

double RT_Envelope_getZMax(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getZMax_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getZMax_func = reinterpret_cast<RT_Envelope_getZMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getZMax")));
    
    return RT_Envelope_getZMax_func(thisHandle, errorHandler);
}

double RT_Envelope_getZMin(const RT_EnvelopeHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Envelope_getZMin_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_getZMin_func = reinterpret_cast<RT_Envelope_getZMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_getZMin")));
    
    return RT_Envelope_getZMin_func(thisHandle, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithM(double xMin, double yMin, double xMax, double yMax, double mMin, double mMax, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithM_def)(double, double, double, double, double, double, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithM_func = reinterpret_cast<RT_Envelope_createWithM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithM")));
    
    return RT_Envelope_createWithM_func(xMin, yMin, xMax, yMax, mMin, mMax, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithZM(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, double mMin, double mMax, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithZM_def)(double, double, double, double, double, double, double, double, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithZM_func = reinterpret_cast<RT_Envelope_createWithZM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithZM")));
    
    return RT_Envelope_createWithZM_func(xMin, yMin, xMax, yMax, zMin, zMax, mMin, mMax, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithZMSpatialReference(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, double mMin, double mMax, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithZMSpatialReference_def)(double, double, double, double, double, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithZMSpatialReference_func = reinterpret_cast<RT_Envelope_createWithZMSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithZMSpatialReference")));
    
    return RT_Envelope_createWithZMSpatialReference_func(xMin, yMin, xMax, yMax, zMin, zMax, mMin, mMax, spatialReference, errorHandler);
}

RT_EnvelopeHandle RT_Envelope_createWithMSpatialReference(double xMin, double yMin, double xMax, double yMax, double mMin, double mMax, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Envelope_createWithMSpatialReference_def)(double, double, double, double, double, double, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Envelope_createWithMSpatialReference_func = reinterpret_cast<RT_Envelope_createWithMSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Envelope_createWithMSpatialReference")));
    
    return RT_Envelope_createWithMSpatialReference_func(xMin, yMin, xMax, yMax, mMin, mMax, spatialReference, errorHandler);
}
#endif