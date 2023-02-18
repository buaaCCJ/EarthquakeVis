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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePointCollection.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_MutablePointCollection_destroy(RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_destroy_def)(RT_MutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_destroy_func = reinterpret_cast<RT_MutablePointCollection_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_destroy")));
    
    RT_MutablePointCollection_destroy_func(thisHandle, errorHandler);
}

RT_MutablePointCollectionHandle RT_MutablePointCollection_createWithSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MutablePointCollectionHandle (*RT_MutablePointCollection_createWithSpatialReference_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_createWithSpatialReference_func = reinterpret_cast<RT_MutablePointCollection_createWithSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_createWithSpatialReference")));
    
    return RT_MutablePointCollection_createWithSpatialReference_func(spatialReference, errorHandler);
}

bool RT_MutablePointCollection_getIsEmpty(const RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_MutablePointCollection_getIsEmpty_def)(const RT_MutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_getIsEmpty_func = reinterpret_cast<RT_MutablePointCollection_getIsEmpty_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_getIsEmpty")));
    
    return RT_MutablePointCollection_getIsEmpty_func(thisHandle, errorHandler);
}

size_t RT_MutablePointCollection_getSize(const RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePointCollection_getSize_def)(const RT_MutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_getSize_func = reinterpret_cast<RT_MutablePointCollection_getSize_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_getSize")));
    
    return RT_MutablePointCollection_getSize_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_MutablePointCollection_getSpatialReference(const RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_MutablePointCollection_getSpatialReference_def)(const RT_MutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_getSpatialReference_func = reinterpret_cast<RT_MutablePointCollection_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_getSpatialReference")));
    
    return RT_MutablePointCollection_getSpatialReference_func(thisHandle, errorHandler);
}

size_t RT_MutablePointCollection_addPointXY(RT_MutablePointCollectionHandle thisHandle, double x, double y, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePointCollection_addPointXY_def)(RT_MutablePointCollectionHandle, double, double, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_addPointXY_func = reinterpret_cast<RT_MutablePointCollection_addPointXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_addPointXY")));
    
    return RT_MutablePointCollection_addPointXY_func(thisHandle, x, y, errorHandler);
}

size_t RT_MutablePointCollection_addPointXYZ(RT_MutablePointCollectionHandle thisHandle, double x, double y, double z, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePointCollection_addPointXYZ_def)(RT_MutablePointCollectionHandle, double, double, double, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_addPointXYZ_func = reinterpret_cast<RT_MutablePointCollection_addPointXYZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_addPointXYZ")));
    
    return RT_MutablePointCollection_addPointXYZ_func(thisHandle, x, y, z, errorHandler);
}

size_t RT_MutablePointCollection_addPoint(RT_MutablePointCollectionHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePointCollection_addPoint_def)(RT_MutablePointCollectionHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_addPoint_func = reinterpret_cast<RT_MutablePointCollection_addPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_addPoint")));
    
    return RT_MutablePointCollection_addPoint_func(thisHandle, point, errorHandler);
}

void RT_MutablePointCollection_addPointsFromImmutable(RT_MutablePointCollectionHandle thisHandle, const RT_ImmutablePointCollectionHandle points, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_addPointsFromImmutable_def)(RT_MutablePointCollectionHandle, const RT_ImmutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_addPointsFromImmutable_func = reinterpret_cast<RT_MutablePointCollection_addPointsFromImmutable_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_addPointsFromImmutable")));
    
    RT_MutablePointCollection_addPointsFromImmutable_func(thisHandle, points, errorHandler);
}

void RT_MutablePointCollection_addPoints(RT_MutablePointCollectionHandle thisHandle, const RT_MutablePointCollectionHandle points, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_addPoints_def)(RT_MutablePointCollectionHandle, const RT_MutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_addPoints_func = reinterpret_cast<RT_MutablePointCollection_addPoints_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_addPoints")));
    
    RT_MutablePointCollection_addPoints_func(thisHandle, points, errorHandler);
}

RT_PointHandle RT_MutablePointCollection_getPoint(const RT_MutablePointCollectionHandle thisHandle, size_t index, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_MutablePointCollection_getPoint_def)(const RT_MutablePointCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_getPoint_func = reinterpret_cast<RT_MutablePointCollection_getPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_getPoint")));
    
    return RT_MutablePointCollection_getPoint_func(thisHandle, index, errorHandler);
}

size_t RT_MutablePointCollection_indexOf(const RT_MutablePointCollectionHandle thisHandle, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_MutablePointCollection_indexOf_def)(const RT_MutablePointCollectionHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_indexOf_func = reinterpret_cast<RT_MutablePointCollection_indexOf_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_indexOf")));
    
    return RT_MutablePointCollection_indexOf_func(thisHandle, point, errorHandler);
}

void RT_MutablePointCollection_insertPointXY(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, double x, double y, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_insertPointXY_def)(RT_MutablePointCollectionHandle, size_t, double, double, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_insertPointXY_func = reinterpret_cast<RT_MutablePointCollection_insertPointXY_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_insertPointXY")));
    
    RT_MutablePointCollection_insertPointXY_func(thisHandle, pointIndex, x, y, errorHandler);
}

void RT_MutablePointCollection_insertPointXYZ(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, double x, double y, double z, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_insertPointXYZ_def)(RT_MutablePointCollectionHandle, size_t, double, double, double, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_insertPointXYZ_func = reinterpret_cast<RT_MutablePointCollection_insertPointXYZ_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_insertPointXYZ")));
    
    RT_MutablePointCollection_insertPointXYZ_func(thisHandle, pointIndex, x, y, z, errorHandler);
}

void RT_MutablePointCollection_insertPoint(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_insertPoint_def)(RT_MutablePointCollectionHandle, size_t, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_insertPoint_func = reinterpret_cast<RT_MutablePointCollection_insertPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_insertPoint")));
    
    RT_MutablePointCollection_insertPoint_func(thisHandle, pointIndex, point, errorHandler);
}

void RT_MutablePointCollection_removeAll(RT_MutablePointCollectionHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_removeAll_def)(RT_MutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_removeAll_func = reinterpret_cast<RT_MutablePointCollection_removeAll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_removeAll")));
    
    RT_MutablePointCollection_removeAll_func(thisHandle, errorHandler);
}

void RT_MutablePointCollection_removePoint(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_removePoint_def)(RT_MutablePointCollectionHandle, size_t, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_removePoint_func = reinterpret_cast<RT_MutablePointCollection_removePoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_removePoint")));
    
    RT_MutablePointCollection_removePoint_func(thisHandle, pointIndex, errorHandler);
}

void RT_MutablePointCollection_setPoint(RT_MutablePointCollectionHandle thisHandle, size_t pointIndex, const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MutablePointCollection_setPoint_def)(RT_MutablePointCollectionHandle, size_t, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_MutablePointCollection_setPoint_func = reinterpret_cast<RT_MutablePointCollection_setPoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MutablePointCollection_setPoint")));
    
    RT_MutablePointCollection_setPoint_func(thisHandle, pointIndex, point, errorHandler);
}
#endif