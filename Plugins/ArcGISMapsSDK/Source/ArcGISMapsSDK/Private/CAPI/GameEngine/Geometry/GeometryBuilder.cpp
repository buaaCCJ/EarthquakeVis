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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryBuilder.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_GeometryBuilder_destroy(RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeometryBuilder_destroy_def)(RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_destroy_func = reinterpret_cast<RT_GeometryBuilder_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_destroy")));
    
    RT_GeometryBuilder_destroy_func(thisHandle, errorHandler);
}

RT_EnvelopeHandle RT_GeometryBuilder_getExtent(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_GeometryBuilder_getExtent_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_getExtent_func = reinterpret_cast<RT_GeometryBuilder_getExtent_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_getExtent")));
    
    return RT_GeometryBuilder_getExtent_func(thisHandle, errorHandler);
}

bool RT_GeometryBuilder_getHasCurves(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryBuilder_getHasCurves_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_getHasCurves_func = reinterpret_cast<RT_GeometryBuilder_getHasCurves_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_getHasCurves")));
    
    return RT_GeometryBuilder_getHasCurves_func(thisHandle, errorHandler);
}

bool RT_GeometryBuilder_getHasM(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryBuilder_getHasM_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_getHasM_func = reinterpret_cast<RT_GeometryBuilder_getHasM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_getHasM")));
    
    return RT_GeometryBuilder_getHasM_func(thisHandle, errorHandler);
}

bool RT_GeometryBuilder_getHasZ(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryBuilder_getHasZ_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_getHasZ_func = reinterpret_cast<RT_GeometryBuilder_getHasZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_getHasZ")));
    
    return RT_GeometryBuilder_getHasZ_func(thisHandle, errorHandler);
}

bool RT_GeometryBuilder_getIsEmpty(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryBuilder_getIsEmpty_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_getIsEmpty_func = reinterpret_cast<RT_GeometryBuilder_getIsEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_getIsEmpty")));
    
    return RT_GeometryBuilder_getIsEmpty_func(thisHandle, errorHandler);
}

bool RT_GeometryBuilder_getIsSketchValid(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_GeometryBuilder_getIsSketchValid_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_getIsSketchValid_func = reinterpret_cast<RT_GeometryBuilder_getIsSketchValid_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_getIsSketchValid")));
    
    return RT_GeometryBuilder_getIsSketchValid_func(thisHandle, errorHandler);
}

RT_GeometryBuilderType RT_GeometryBuilder_getObjectType(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryBuilderType (*RT_GeometryBuilder_getObjectType_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_getObjectType_func = reinterpret_cast<RT_GeometryBuilder_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_getObjectType")));
    
    return RT_GeometryBuilder_getObjectType_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_GeometryBuilder_getSpatialReference(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_GeometryBuilder_getSpatialReference_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_getSpatialReference_func = reinterpret_cast<RT_GeometryBuilder_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_getSpatialReference")));
    
    return RT_GeometryBuilder_getSpatialReference_func(thisHandle, errorHandler);
}

RT_GeometryBuilderHandle RT_GeometryBuilder_createFromGeometry(const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryBuilderHandle (*RT_GeometryBuilder_createFromGeometry_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_createFromGeometry_func = reinterpret_cast<RT_GeometryBuilder_createFromGeometry_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_createFromGeometry")));
    
    return RT_GeometryBuilder_createFromGeometry_func(geometry, errorHandler);
}

RT_GeometryBuilderHandle RT_GeometryBuilder_createFromGeometryTypeAndSpatialReference(RT_GeometryType geometryType, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryBuilderHandle (*RT_GeometryBuilder_createFromGeometryTypeAndSpatialReference_def)(RT_GeometryType, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_createFromGeometryTypeAndSpatialReference_func = reinterpret_cast<RT_GeometryBuilder_createFromGeometryTypeAndSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_createFromGeometryTypeAndSpatialReference")));
    
    return RT_GeometryBuilder_createFromGeometryTypeAndSpatialReference_func(geometryType, spatialReference, errorHandler);
}

void RT_GeometryBuilder_replaceGeometry(RT_GeometryBuilderHandle thisHandle, const RT_GeometryHandle geometry, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_GeometryBuilder_replaceGeometry_def)(RT_GeometryBuilderHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_replaceGeometry_func = reinterpret_cast<RT_GeometryBuilder_replaceGeometry_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_replaceGeometry")));
    
    RT_GeometryBuilder_replaceGeometry_func(thisHandle, geometry, errorHandler);
}

RT_GeometryHandle RT_GeometryBuilder_toGeometry(const RT_GeometryBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_GeometryBuilder_toGeometry_def)(const RT_GeometryBuilderHandle, const RT_ErrorHandler*);
    static auto RT_GeometryBuilder_toGeometry_func = reinterpret_cast<RT_GeometryBuilder_toGeometry_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_GeometryBuilder_toGeometry")));
    
    return RT_GeometryBuilder_toGeometry_func(thisHandle, errorHandler);
}
#endif