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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Geometry.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Geometry_destroy(RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Geometry_destroy_def)(RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_destroy_func = reinterpret_cast<RT_Geometry_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_destroy")));
    
    RT_Geometry_destroy_func(thisHandle, errorHandler);
}

RT_GeometryDimension RT_Geometry_getDimension(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryDimension (*RT_Geometry_getDimension_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getDimension_func = reinterpret_cast<RT_Geometry_getDimension_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getDimension")));
    
    return RT_Geometry_getDimension_func(thisHandle, errorHandler);
}

RT_EnvelopeHandle RT_Geometry_getExtent(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_Geometry_getExtent_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getExtent_func = reinterpret_cast<RT_Geometry_getExtent_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getExtent")));
    
    return RT_Geometry_getExtent_func(thisHandle, errorHandler);
}

bool RT_Geometry_getHasCurves(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Geometry_getHasCurves_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getHasCurves_func = reinterpret_cast<RT_Geometry_getHasCurves_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getHasCurves")));
    
    return RT_Geometry_getHasCurves_func(thisHandle, errorHandler);
}

bool RT_Geometry_getHasM(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Geometry_getHasM_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getHasM_func = reinterpret_cast<RT_Geometry_getHasM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getHasM")));
    
    return RT_Geometry_getHasM_func(thisHandle, errorHandler);
}

bool RT_Geometry_getHasZ(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Geometry_getHasZ_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getHasZ_func = reinterpret_cast<RT_Geometry_getHasZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getHasZ")));
    
    return RT_Geometry_getHasZ_func(thisHandle, errorHandler);
}

bool RT_Geometry_getIsEmpty(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Geometry_getIsEmpty_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getIsEmpty_func = reinterpret_cast<RT_Geometry_getIsEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getIsEmpty")));
    
    return RT_Geometry_getIsEmpty_func(thisHandle, errorHandler);
}

RT_GeometryType RT_Geometry_getObjectType(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryType (*RT_Geometry_getObjectType_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getObjectType_func = reinterpret_cast<RT_Geometry_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getObjectType")));
    
    return RT_Geometry_getObjectType_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_Geometry_getSpatialReference(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_Geometry_getSpatialReference_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getSpatialReference_func = reinterpret_cast<RT_Geometry_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getSpatialReference")));
    
    return RT_Geometry_getSpatialReference_func(thisHandle, errorHandler);
}

bool RT_Geometry_equals(const RT_GeometryHandle thisHandle, const RT_GeometryHandle right, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Geometry_equals_def)(const RT_GeometryHandle, const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_equals_func = reinterpret_cast<RT_Geometry_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_equals")));
    
    return RT_Geometry_equals_func(thisHandle, right, errorHandler);
}

bool RT_Geometry_equalsWithTolerance(const RT_GeometryHandle thisHandle, const RT_GeometryHandle right, double tolerance, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Geometry_equalsWithTolerance_def)(const RT_GeometryHandle, const RT_GeometryHandle, double, const RT_ErrorHandler*);
    static auto RT_Geometry_equalsWithTolerance_func = reinterpret_cast<RT_Geometry_equalsWithTolerance_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_equalsWithTolerance")));
    
    return RT_Geometry_equalsWithTolerance_func(thisHandle, right, tolerance, errorHandler);
}

RT_GeometryHandle RT_Geometry_fromJSONWithSpatialReference(const char* inputJSON, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_GeometryHandle (*RT_Geometry_fromJSONWithSpatialReference_def)(const char*, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_fromJSONWithSpatialReference_func = reinterpret_cast<RT_Geometry_fromJSONWithSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_fromJSONWithSpatialReference")));
    
    return RT_Geometry_fromJSONWithSpatialReference_func(inputJSON, spatialReference, errorHandler);
}

size_t RT_Geometry_getHash(const RT_GeometryHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_Geometry_getHash_def)(const RT_GeometryHandle, const RT_ErrorHandler*);
    static auto RT_Geometry_getHash_func = reinterpret_cast<RT_Geometry_getHash_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Geometry_getHash")));
    
    return RT_Geometry_getHash_func(thisHandle, errorHandler);
}
#endif