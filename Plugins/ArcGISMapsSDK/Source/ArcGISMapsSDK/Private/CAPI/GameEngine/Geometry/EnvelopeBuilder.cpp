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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeBuilder.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_EnvelopeBuilder_destroy(RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_destroy_def)(RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_destroy_func = reinterpret_cast<RT_EnvelopeBuilder_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_destroy")));
    
    RT_EnvelopeBuilder_destroy_func(thisHandle, errorHandler);
}

RT_EnvelopeBuilderHandle RT_EnvelopeBuilder_createFromEnvelope(const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeBuilderHandle (*RT_EnvelopeBuilder_createFromEnvelope_def)(const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_createFromEnvelope_func = reinterpret_cast<RT_EnvelopeBuilder_createFromEnvelope_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_createFromEnvelope")));
    
    return RT_EnvelopeBuilder_createFromEnvelope_func(envelope, errorHandler);
}

RT_EnvelopeBuilderHandle RT_EnvelopeBuilder_createFromCenterPoint(const RT_PointHandle center, double width, double height, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeBuilderHandle (*RT_EnvelopeBuilder_createFromCenterPoint_def)(const RT_PointHandle, double, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_createFromCenterPoint_func = reinterpret_cast<RT_EnvelopeBuilder_createFromCenterPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_createFromCenterPoint")));
    
    return RT_EnvelopeBuilder_createFromCenterPoint_func(center, width, height, errorHandler);
}

RT_EnvelopeBuilderHandle RT_EnvelopeBuilder_createFromCenterPointAndDepth(const RT_PointHandle center, double width, double height, double depth, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeBuilderHandle (*RT_EnvelopeBuilder_createFromCenterPointAndDepth_def)(const RT_PointHandle, double, double, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_createFromCenterPointAndDepth_func = reinterpret_cast<RT_EnvelopeBuilder_createFromCenterPointAndDepth_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_createFromCenterPointAndDepth")));
    
    return RT_EnvelopeBuilder_createFromCenterPointAndDepth_func(center, width, height, depth, errorHandler);
}

RT_EnvelopeBuilderHandle RT_EnvelopeBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeBuilderHandle (*RT_EnvelopeBuilder_createFromSpatialReference_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_createFromSpatialReference_func = reinterpret_cast<RT_EnvelopeBuilder_createFromSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_createFromSpatialReference")));
    
    return RT_EnvelopeBuilder_createFromSpatialReference_func(spatialReference, errorHandler);
}

RT_PointHandle RT_EnvelopeBuilder_getCenter(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_EnvelopeBuilder_getCenter_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getCenter_func = reinterpret_cast<RT_EnvelopeBuilder_getCenter_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getCenter")));
    
    return RT_EnvelopeBuilder_getCenter_func(thisHandle, errorHandler);
}

double RT_EnvelopeBuilder_getDepth(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getDepth_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getDepth_func = reinterpret_cast<RT_EnvelopeBuilder_getDepth_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getDepth")));
    
    return RT_EnvelopeBuilder_getDepth_func(thisHandle, errorHandler);
}

double RT_EnvelopeBuilder_getHeight(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getHeight_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getHeight_func = reinterpret_cast<RT_EnvelopeBuilder_getHeight_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getHeight")));
    
    return RT_EnvelopeBuilder_getHeight_func(thisHandle, errorHandler);
}

double RT_EnvelopeBuilder_getMMax(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getMMax_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getMMax_func = reinterpret_cast<RT_EnvelopeBuilder_getMMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getMMax")));
    
    return RT_EnvelopeBuilder_getMMax_func(thisHandle, errorHandler);
}
void RT_EnvelopeBuilder_setMMax(RT_EnvelopeBuilderHandle thisHandle, double mMax, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setMMax_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setMMax_func = reinterpret_cast<RT_EnvelopeBuilder_setMMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setMMax")));
    
    RT_EnvelopeBuilder_setMMax_func(thisHandle, mMax, errorHandler);
}

double RT_EnvelopeBuilder_getMMin(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getMMin_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getMMin_func = reinterpret_cast<RT_EnvelopeBuilder_getMMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getMMin")));
    
    return RT_EnvelopeBuilder_getMMin_func(thisHandle, errorHandler);
}
void RT_EnvelopeBuilder_setMMin(RT_EnvelopeBuilderHandle thisHandle, double mMin, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setMMin_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setMMin_func = reinterpret_cast<RT_EnvelopeBuilder_setMMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setMMin")));
    
    RT_EnvelopeBuilder_setMMin_func(thisHandle, mMin, errorHandler);
}

double RT_EnvelopeBuilder_getWidth(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getWidth_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getWidth_func = reinterpret_cast<RT_EnvelopeBuilder_getWidth_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getWidth")));
    
    return RT_EnvelopeBuilder_getWidth_func(thisHandle, errorHandler);
}

double RT_EnvelopeBuilder_getXMax(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getXMax_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getXMax_func = reinterpret_cast<RT_EnvelopeBuilder_getXMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getXMax")));
    
    return RT_EnvelopeBuilder_getXMax_func(thisHandle, errorHandler);
}
void RT_EnvelopeBuilder_setXMax(RT_EnvelopeBuilderHandle thisHandle, double xMax, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setXMax_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setXMax_func = reinterpret_cast<RT_EnvelopeBuilder_setXMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setXMax")));
    
    RT_EnvelopeBuilder_setXMax_func(thisHandle, xMax, errorHandler);
}

double RT_EnvelopeBuilder_getXMin(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getXMin_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getXMin_func = reinterpret_cast<RT_EnvelopeBuilder_getXMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getXMin")));
    
    return RT_EnvelopeBuilder_getXMin_func(thisHandle, errorHandler);
}
void RT_EnvelopeBuilder_setXMin(RT_EnvelopeBuilderHandle thisHandle, double xMin, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setXMin_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setXMin_func = reinterpret_cast<RT_EnvelopeBuilder_setXMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setXMin")));
    
    RT_EnvelopeBuilder_setXMin_func(thisHandle, xMin, errorHandler);
}

double RT_EnvelopeBuilder_getYMax(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getYMax_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getYMax_func = reinterpret_cast<RT_EnvelopeBuilder_getYMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getYMax")));
    
    return RT_EnvelopeBuilder_getYMax_func(thisHandle, errorHandler);
}
void RT_EnvelopeBuilder_setYMax(RT_EnvelopeBuilderHandle thisHandle, double yMax, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setYMax_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setYMax_func = reinterpret_cast<RT_EnvelopeBuilder_setYMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setYMax")));
    
    RT_EnvelopeBuilder_setYMax_func(thisHandle, yMax, errorHandler);
}

double RT_EnvelopeBuilder_getYMin(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getYMin_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getYMin_func = reinterpret_cast<RT_EnvelopeBuilder_getYMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getYMin")));
    
    return RT_EnvelopeBuilder_getYMin_func(thisHandle, errorHandler);
}
void RT_EnvelopeBuilder_setYMin(RT_EnvelopeBuilderHandle thisHandle, double yMin, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setYMin_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setYMin_func = reinterpret_cast<RT_EnvelopeBuilder_setYMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setYMin")));
    
    RT_EnvelopeBuilder_setYMin_func(thisHandle, yMin, errorHandler);
}

double RT_EnvelopeBuilder_getZMax(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getZMax_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getZMax_func = reinterpret_cast<RT_EnvelopeBuilder_getZMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getZMax")));
    
    return RT_EnvelopeBuilder_getZMax_func(thisHandle, errorHandler);
}
void RT_EnvelopeBuilder_setZMax(RT_EnvelopeBuilderHandle thisHandle, double zMax, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setZMax_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setZMax_func = reinterpret_cast<RT_EnvelopeBuilder_setZMax_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setZMax")));
    
    RT_EnvelopeBuilder_setZMax_func(thisHandle, zMax, errorHandler);
}

double RT_EnvelopeBuilder_getZMin(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_EnvelopeBuilder_getZMin_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_getZMin_func = reinterpret_cast<RT_EnvelopeBuilder_getZMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_getZMin")));
    
    return RT_EnvelopeBuilder_getZMin_func(thisHandle, errorHandler);
}
void RT_EnvelopeBuilder_setZMin(RT_EnvelopeBuilderHandle thisHandle, double zMin, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setZMin_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setZMin_func = reinterpret_cast<RT_EnvelopeBuilder_setZMin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setZMin")));
    
    RT_EnvelopeBuilder_setZMin_func(thisHandle, zMin, errorHandler);
}

RT_EnvelopeHandle RT_EnvelopeBuilder_adjustForWrapAround(const RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_EnvelopeBuilder_adjustForWrapAround_def)(const RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_adjustForWrapAround_func = reinterpret_cast<RT_EnvelopeBuilder_adjustForWrapAround_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_adjustForWrapAround")));
    
    return RT_EnvelopeBuilder_adjustForWrapAround_func(thisHandle, errorHandler);
}

void RT_EnvelopeBuilder_centerAt(RT_EnvelopeBuilderHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_centerAt_def)(RT_EnvelopeBuilderHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_centerAt_func = reinterpret_cast<RT_EnvelopeBuilder_centerAt_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_centerAt")));
    
    RT_EnvelopeBuilder_centerAt_func(thisHandle, point, errorHandler);
}

void RT_EnvelopeBuilder_changeAspectRatio(RT_EnvelopeBuilderHandle thisHandle, double width, double height, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_changeAspectRatio_def)(RT_EnvelopeBuilderHandle, double, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_changeAspectRatio_func = reinterpret_cast<RT_EnvelopeBuilder_changeAspectRatio_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_changeAspectRatio")));
    
    RT_EnvelopeBuilder_changeAspectRatio_func(thisHandle, width, height, errorHandler);
}

void RT_EnvelopeBuilder_expand(RT_EnvelopeBuilderHandle thisHandle, double factor, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_expand_def)(RT_EnvelopeBuilderHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_expand_func = reinterpret_cast<RT_EnvelopeBuilder_expand_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_expand")));
    
    RT_EnvelopeBuilder_expand_func(thisHandle, factor, errorHandler);
}

void RT_EnvelopeBuilder_expandAtAnchor(RT_EnvelopeBuilderHandle thisHandle, const RT_PointHandle anchor, double factor, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_expandAtAnchor_def)(RT_EnvelopeBuilderHandle, const RT_PointHandle, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_expandAtAnchor_func = reinterpret_cast<RT_EnvelopeBuilder_expandAtAnchor_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_expandAtAnchor")));
    
    RT_EnvelopeBuilder_expandAtAnchor_func(thisHandle, anchor, factor, errorHandler);
}

void RT_EnvelopeBuilder_normalize(RT_EnvelopeBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_normalize_def)(RT_EnvelopeBuilderHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_normalize_func = reinterpret_cast<RT_EnvelopeBuilder_normalize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_normalize")));
    
    RT_EnvelopeBuilder_normalize_func(thisHandle, errorHandler);
}

void RT_EnvelopeBuilder_normalizeToEnvelope(RT_EnvelopeBuilderHandle thisHandle, const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_normalizeToEnvelope_def)(RT_EnvelopeBuilderHandle, const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_normalizeToEnvelope_func = reinterpret_cast<RT_EnvelopeBuilder_normalizeToEnvelope_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_normalizeToEnvelope")));
    
    RT_EnvelopeBuilder_normalizeToEnvelope_func(thisHandle, envelope, errorHandler);
}

void RT_EnvelopeBuilder_offsetBy(RT_EnvelopeBuilderHandle thisHandle, double offsetX, double offsetY, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_offsetBy_def)(RT_EnvelopeBuilderHandle, double, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_offsetBy_func = reinterpret_cast<RT_EnvelopeBuilder_offsetBy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_offsetBy")));
    
    RT_EnvelopeBuilder_offsetBy_func(thisHandle, offsetX, offsetY, errorHandler);
}

void RT_EnvelopeBuilder_setM(RT_EnvelopeBuilderHandle thisHandle, double mMin, double mMax, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setM_def)(RT_EnvelopeBuilderHandle, double, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setM_func = reinterpret_cast<RT_EnvelopeBuilder_setM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setM")));
    
    RT_EnvelopeBuilder_setM_func(thisHandle, mMin, mMax, errorHandler);
}

void RT_EnvelopeBuilder_setXY(RT_EnvelopeBuilderHandle thisHandle, double xMin, double yMin, double xMax, double yMax, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setXY_def)(RT_EnvelopeBuilderHandle, double, double, double, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setXY_func = reinterpret_cast<RT_EnvelopeBuilder_setXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setXY")));
    
    RT_EnvelopeBuilder_setXY_func(thisHandle, xMin, yMin, xMax, yMax, errorHandler);
}

void RT_EnvelopeBuilder_setZ(RT_EnvelopeBuilderHandle thisHandle, double zMin, double zMax, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_setZ_def)(RT_EnvelopeBuilderHandle, double, double, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_setZ_func = reinterpret_cast<RT_EnvelopeBuilder_setZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_setZ")));
    
    RT_EnvelopeBuilder_setZ_func(thisHandle, zMin, zMax, errorHandler);
}

void RT_EnvelopeBuilder_unionWithEnvelope(RT_EnvelopeBuilderHandle thisHandle, const RT_EnvelopeHandle envelope, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_unionWithEnvelope_def)(RT_EnvelopeBuilderHandle, const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_unionWithEnvelope_func = reinterpret_cast<RT_EnvelopeBuilder_unionWithEnvelope_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_unionWithEnvelope")));
    
    RT_EnvelopeBuilder_unionWithEnvelope_func(thisHandle, envelope, errorHandler);
}

void RT_EnvelopeBuilder_unionWithPoint(RT_EnvelopeBuilderHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_EnvelopeBuilder_unionWithPoint_def)(RT_EnvelopeBuilderHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_EnvelopeBuilder_unionWithPoint_func = reinterpret_cast<RT_EnvelopeBuilder_unionWithPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_EnvelopeBuilder_unionWithPoint")));
    
    RT_EnvelopeBuilder_unionWithPoint_func(thisHandle, point, errorHandler);
}
#endif