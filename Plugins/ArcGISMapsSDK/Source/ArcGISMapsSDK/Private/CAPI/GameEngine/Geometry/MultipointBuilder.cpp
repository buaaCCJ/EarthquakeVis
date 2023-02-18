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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MultipointBuilder.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_MultipointBuilder_destroy(RT_MultipointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MultipointBuilder_destroy_def)(RT_MultipointBuilderHandle, const RT_ErrorHandler*);
    static auto RT_MultipointBuilder_destroy_func = reinterpret_cast<RT_MultipointBuilder_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipointBuilder_destroy")));
    
    RT_MultipointBuilder_destroy_func(thisHandle, errorHandler);
}

RT_MultipointBuilderHandle RT_MultipointBuilder_createFromMultipoint(const RT_MultipointHandle multipoint, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MultipointBuilderHandle (*RT_MultipointBuilder_createFromMultipoint_def)(const RT_MultipointHandle, const RT_ErrorHandler*);
    static auto RT_MultipointBuilder_createFromMultipoint_func = reinterpret_cast<RT_MultipointBuilder_createFromMultipoint_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipointBuilder_createFromMultipoint")));
    
    return RT_MultipointBuilder_createFromMultipoint_func(multipoint, errorHandler);
}

RT_MultipointBuilderHandle RT_MultipointBuilder_createFromSpatialReference(const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MultipointBuilderHandle (*RT_MultipointBuilder_createFromSpatialReference_def)(const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_MultipointBuilder_createFromSpatialReference_func = reinterpret_cast<RT_MultipointBuilder_createFromSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipointBuilder_createFromSpatialReference")));
    
    return RT_MultipointBuilder_createFromSpatialReference_func(spatialReference, errorHandler);
}

RT_MutablePointCollectionHandle RT_MultipointBuilder_getPoints(const RT_MultipointBuilderHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_MutablePointCollectionHandle (*RT_MultipointBuilder_getPoints_def)(const RT_MultipointBuilderHandle, const RT_ErrorHandler*);
    static auto RT_MultipointBuilder_getPoints_func = reinterpret_cast<RT_MultipointBuilder_getPoints_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipointBuilder_getPoints")));
    
    return RT_MultipointBuilder_getPoints_func(thisHandle, errorHandler);
}
void RT_MultipointBuilder_setPoints(RT_MultipointBuilderHandle thisHandle, RT_MutablePointCollectionHandle points, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_MultipointBuilder_setPoints_def)(RT_MultipointBuilderHandle, RT_MutablePointCollectionHandle, const RT_ErrorHandler*);
    static auto RT_MultipointBuilder_setPoints_func = reinterpret_cast<RT_MultipointBuilder_setPoints_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_MultipointBuilder_setPoints")));
    
    RT_MultipointBuilder_setPoints_func(thisHandle, points, errorHandler);
}
#endif