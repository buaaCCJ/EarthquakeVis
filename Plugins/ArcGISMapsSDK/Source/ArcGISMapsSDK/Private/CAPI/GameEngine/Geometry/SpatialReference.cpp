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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReference.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_SpatialReference_destroy(RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_SpatialReference_destroy_def)(RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_destroy_func = reinterpret_cast<RT_SpatialReference_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_destroy")));
    
    RT_SpatialReference_destroy_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_SpatialReference_create(int32_t WKID, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_SpatialReference_create_def)(int32_t, const RT_ErrorHandler*);
    static auto RT_SpatialReference_create_func = reinterpret_cast<RT_SpatialReference_create_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_create")));
    
    return RT_SpatialReference_create_func(WKID, errorHandler);
}

RT_SpatialReferenceHandle RT_SpatialReference_createVerticalWKID(int32_t WKID, int32_t verticalWKID, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_SpatialReference_createVerticalWKID_def)(int32_t, int32_t, const RT_ErrorHandler*);
    static auto RT_SpatialReference_createVerticalWKID_func = reinterpret_cast<RT_SpatialReference_createVerticalWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_createVerticalWKID")));
    
    return RT_SpatialReference_createVerticalWKID_func(WKID, verticalWKID, errorHandler);
}

RT_SpatialReferenceHandle RT_SpatialReference_createFromWKText(const char* wkText, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_SpatialReference_createFromWKText_def)(const char*, const RT_ErrorHandler*);
    static auto RT_SpatialReference_createFromWKText_func = reinterpret_cast<RT_SpatialReference_createFromWKText_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_createFromWKText")));
    
    return RT_SpatialReference_createFromWKText_func(wkText, errorHandler);
}

RT_SpatialReferenceHandle RT_SpatialReference_getBaseGeographic(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_SpatialReference_getBaseGeographic_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getBaseGeographic_func = reinterpret_cast<RT_SpatialReference_getBaseGeographic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getBaseGeographic")));
    
    return RT_SpatialReference_getBaseGeographic_func(thisHandle, errorHandler);
}

RT_EnvelopeHandle RT_SpatialReference_getFullWorldExtent(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_SpatialReference_getFullWorldExtent_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getFullWorldExtent_func = reinterpret_cast<RT_SpatialReference_getFullWorldExtent_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getFullWorldExtent")));
    
    return RT_SpatialReference_getFullWorldExtent_func(thisHandle, errorHandler);
}

bool RT_SpatialReference_getHasVertical(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_SpatialReference_getHasVertical_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getHasVertical_func = reinterpret_cast<RT_SpatialReference_getHasVertical_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getHasVertical")));
    
    return RT_SpatialReference_getHasVertical_func(thisHandle, errorHandler);
}

bool RT_SpatialReference_getIsGeographic(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_SpatialReference_getIsGeographic_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getIsGeographic_func = reinterpret_cast<RT_SpatialReference_getIsGeographic_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getIsGeographic")));
    
    return RT_SpatialReference_getIsGeographic_func(thisHandle, errorHandler);
}

bool RT_SpatialReference_getIsPannable(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_SpatialReference_getIsPannable_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getIsPannable_func = reinterpret_cast<RT_SpatialReference_getIsPannable_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getIsPannable")));
    
    return RT_SpatialReference_getIsPannable_func(thisHandle, errorHandler);
}

bool RT_SpatialReference_getIsProjected(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_SpatialReference_getIsProjected_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getIsProjected_func = reinterpret_cast<RT_SpatialReference_getIsProjected_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getIsProjected")));
    
    return RT_SpatialReference_getIsProjected_func(thisHandle, errorHandler);
}

RT_SpheroidData RT_SpatialReference_getSpheroidData(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpheroidData (*RT_SpatialReference_getSpheroidData_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getSpheroidData_func = reinterpret_cast<RT_SpatialReference_getSpheroidData_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getSpheroidData")));
    
    return RT_SpatialReference_getSpheroidData_func(thisHandle, errorHandler);
}

RT_UnitHandle RT_SpatialReference_getUnit(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_UnitHandle (*RT_SpatialReference_getUnit_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getUnit_func = reinterpret_cast<RT_SpatialReference_getUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getUnit")));
    
    return RT_SpatialReference_getUnit_func(thisHandle, errorHandler);
}

RT_LinearUnitHandle RT_SpatialReference_getVerticalUnit(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_LinearUnitHandle (*RT_SpatialReference_getVerticalUnit_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getVerticalUnit_func = reinterpret_cast<RT_SpatialReference_getVerticalUnit_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getVerticalUnit")));
    
    return RT_SpatialReference_getVerticalUnit_func(thisHandle, errorHandler);
}

int32_t RT_SpatialReference_getVerticalWKID(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int32_t (*RT_SpatialReference_getVerticalWKID_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getVerticalWKID_func = reinterpret_cast<RT_SpatialReference_getVerticalWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getVerticalWKID")));
    
    return RT_SpatialReference_getVerticalWKID_func(thisHandle, errorHandler);
}

int32_t RT_SpatialReference_getWKID(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef int32_t (*RT_SpatialReference_getWKID_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getWKID_func = reinterpret_cast<RT_SpatialReference_getWKID_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getWKID")));
    
    return RT_SpatialReference_getWKID_func(thisHandle, errorHandler);
}

RT_StringHandle RT_SpatialReference_getWKText(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_SpatialReference_getWKText_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getWKText_func = reinterpret_cast<RT_SpatialReference_getWKText_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getWKText")));
    
    return RT_SpatialReference_getWKText_func(thisHandle, errorHandler);
}

bool RT_SpatialReference_equals(const RT_SpatialReferenceHandle thisHandle, const RT_SpatialReferenceHandle right, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_SpatialReference_equals_def)(const RT_SpatialReferenceHandle, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_equals_func = reinterpret_cast<RT_SpatialReference_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_equals")));
    
    return RT_SpatialReference_equals_func(thisHandle, right, errorHandler);
}

double RT_SpatialReference_getConvergenceAngle(const RT_SpatialReferenceHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_SpatialReference_getConvergenceAngle_def)(const RT_SpatialReferenceHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getConvergenceAngle_func = reinterpret_cast<RT_SpatialReference_getConvergenceAngle_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getConvergenceAngle")));
    
    return RT_SpatialReference_getConvergenceAngle_func(thisHandle, point, errorHandler);
}

size_t RT_SpatialReference_getHash(const RT_SpatialReferenceHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_SpatialReference_getHash_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_SpatialReference_getHash_func = reinterpret_cast<RT_SpatialReference_getHash_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_getHash")));
    
    return RT_SpatialReference_getHash_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_SpatialReference_webMercator(const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_SpatialReference_webMercator_def)(const RT_ErrorHandler*);
    static auto RT_SpatialReference_webMercator_func = reinterpret_cast<RT_SpatialReference_webMercator_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_webMercator")));
    
    return RT_SpatialReference_webMercator_func(errorHandler);
}

RT_SpatialReferenceHandle RT_SpatialReference_WGS84(const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_SpatialReference_WGS84_def)(const RT_ErrorHandler*);
    static auto RT_SpatialReference_WGS84_func = reinterpret_cast<RT_SpatialReference_WGS84_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_SpatialReference_WGS84")));
    
    return RT_SpatialReference_WGS84_func(errorHandler);
}
#endif