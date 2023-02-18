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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileSourceInfo.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_VectorTileSourceInfo_destroy(RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_VectorTileSourceInfo_destroy_def)(RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_destroy_func = reinterpret_cast<RT_VectorTileSourceInfo_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_destroy")));
    
    RT_VectorTileSourceInfo_destroy_func(thisHandle, errorHandler);
}

RT_EnvelopeHandle RT_VectorTileSourceInfo_getFullExtent(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_VectorTileSourceInfo_getFullExtent_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getFullExtent_func = reinterpret_cast<RT_VectorTileSourceInfo_getFullExtent_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getFullExtent")));
    
    return RT_VectorTileSourceInfo_getFullExtent_func(thisHandle, errorHandler);
}

RT_EnvelopeHandle RT_VectorTileSourceInfo_getInitialExtent(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_EnvelopeHandle (*RT_VectorTileSourceInfo_getInitialExtent_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getInitialExtent_func = reinterpret_cast<RT_VectorTileSourceInfo_getInitialExtent_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getInitialExtent")));
    
    return RT_VectorTileSourceInfo_getInitialExtent_func(thisHandle, errorHandler);
}

double RT_VectorTileSourceInfo_getMaxScale(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_VectorTileSourceInfo_getMaxScale_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getMaxScale_func = reinterpret_cast<RT_VectorTileSourceInfo_getMaxScale_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getMaxScale")));
    
    return RT_VectorTileSourceInfo_getMaxScale_func(thisHandle, errorHandler);
}

double RT_VectorTileSourceInfo_getMinScale(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_VectorTileSourceInfo_getMinScale_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getMinScale_func = reinterpret_cast<RT_VectorTileSourceInfo_getMinScale_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getMinScale")));
    
    return RT_VectorTileSourceInfo_getMinScale_func(thisHandle, errorHandler);
}

RT_StringHandle RT_VectorTileSourceInfo_getName(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_VectorTileSourceInfo_getName_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getName_func = reinterpret_cast<RT_VectorTileSourceInfo_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getName")));
    
    return RT_VectorTileSourceInfo_getName_func(thisHandle, errorHandler);
}

RT_PointHandle RT_VectorTileSourceInfo_getOrigin(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_VectorTileSourceInfo_getOrigin_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getOrigin_func = reinterpret_cast<RT_VectorTileSourceInfo_getOrigin_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getOrigin")));
    
    return RT_VectorTileSourceInfo_getOrigin_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_VectorTileSourceInfo_getSpatialReference(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_VectorTileSourceInfo_getSpatialReference_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getSpatialReference_func = reinterpret_cast<RT_VectorTileSourceInfo_getSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getSpatialReference")));
    
    return RT_VectorTileSourceInfo_getSpatialReference_func(thisHandle, errorHandler);
}

RT_StringHandle RT_VectorTileSourceInfo_getURI(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_VectorTileSourceInfo_getURI_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getURI_func = reinterpret_cast<RT_VectorTileSourceInfo_getURI_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getURI")));
    
    return RT_VectorTileSourceInfo_getURI_func(thisHandle, errorHandler);
}

RT_StringHandle RT_VectorTileSourceInfo_getVersion(const RT_VectorTileSourceInfoHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_VectorTileSourceInfo_getVersion_def)(const RT_VectorTileSourceInfoHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileSourceInfo_getVersion_func = reinterpret_cast<RT_VectorTileSourceInfo_getVersion_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileSourceInfo_getVersion")));
    
    return RT_VectorTileSourceInfo_getVersion_func(thisHandle, errorHandler);
}
#endif