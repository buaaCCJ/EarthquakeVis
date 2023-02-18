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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/CoordinateFormatter.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

RT_PointHandle RT_CoordinateFormatter_fromGARS(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, RT_GARSConversionMode GARSConversionMode, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_CoordinateFormatter_fromGARS_def)(const char*, const RT_SpatialReferenceHandle, RT_GARSConversionMode, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_fromGARS_func = reinterpret_cast<RT_CoordinateFormatter_fromGARS_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_fromGARS")));
    
    return RT_CoordinateFormatter_fromGARS_func(coordinates, spatialReference, GARSConversionMode, errorHandler);
}

RT_PointHandle RT_CoordinateFormatter_fromGeoRef(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_CoordinateFormatter_fromGeoRef_def)(const char*, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_fromGeoRef_func = reinterpret_cast<RT_CoordinateFormatter_fromGeoRef_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_fromGeoRef")));
    
    return RT_CoordinateFormatter_fromGeoRef_func(coordinates, spatialReference, errorHandler);
}

RT_PointHandle RT_CoordinateFormatter_fromLatitudeLongitude(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_CoordinateFormatter_fromLatitudeLongitude_def)(const char*, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_fromLatitudeLongitude_func = reinterpret_cast<RT_CoordinateFormatter_fromLatitudeLongitude_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_fromLatitudeLongitude")));
    
    return RT_CoordinateFormatter_fromLatitudeLongitude_func(coordinates, spatialReference, errorHandler);
}

RT_PointHandle RT_CoordinateFormatter_fromMGRS(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, RT_MGRSConversionMode MGRSConversionMode, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_CoordinateFormatter_fromMGRS_def)(const char*, const RT_SpatialReferenceHandle, RT_MGRSConversionMode, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_fromMGRS_func = reinterpret_cast<RT_CoordinateFormatter_fromMGRS_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_fromMGRS")));
    
    return RT_CoordinateFormatter_fromMGRS_func(coordinates, spatialReference, MGRSConversionMode, errorHandler);
}

RT_PointHandle RT_CoordinateFormatter_fromUSNG(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_CoordinateFormatter_fromUSNG_def)(const char*, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_fromUSNG_func = reinterpret_cast<RT_CoordinateFormatter_fromUSNG_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_fromUSNG")));
    
    return RT_CoordinateFormatter_fromUSNG_func(coordinates, spatialReference, errorHandler);
}

RT_PointHandle RT_CoordinateFormatter_fromUTM(const char* coordinates, const RT_SpatialReferenceHandle spatialReference, RT_UTMConversionMode UTMConversionMode, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_CoordinateFormatter_fromUTM_def)(const char*, const RT_SpatialReferenceHandle, RT_UTMConversionMode, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_fromUTM_func = reinterpret_cast<RT_CoordinateFormatter_fromUTM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_fromUTM")));
    
    return RT_CoordinateFormatter_fromUTM_func(coordinates, spatialReference, UTMConversionMode, errorHandler);
}

RT_StringHandle RT_CoordinateFormatter_toGARS(const RT_PointHandle point, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_CoordinateFormatter_toGARS_def)(const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_toGARS_func = reinterpret_cast<RT_CoordinateFormatter_toGARS_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_toGARS")));
    
    return RT_CoordinateFormatter_toGARS_func(point, errorHandler);
}

RT_StringHandle RT_CoordinateFormatter_toGeoRef(const RT_PointHandle point, int32_t precision, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_CoordinateFormatter_toGeoRef_def)(const RT_PointHandle, int32_t, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_toGeoRef_func = reinterpret_cast<RT_CoordinateFormatter_toGeoRef_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_toGeoRef")));
    
    return RT_CoordinateFormatter_toGeoRef_func(point, precision, errorHandler);
}

RT_StringHandle RT_CoordinateFormatter_toLatitudeLongitude(const RT_PointHandle point, RT_LatitudeLongitudeFormat format, int32_t decimalPlaces, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_CoordinateFormatter_toLatitudeLongitude_def)(const RT_PointHandle, RT_LatitudeLongitudeFormat, int32_t, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_toLatitudeLongitude_func = reinterpret_cast<RT_CoordinateFormatter_toLatitudeLongitude_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_toLatitudeLongitude")));
    
    return RT_CoordinateFormatter_toLatitudeLongitude_func(point, format, decimalPlaces, errorHandler);
}

RT_StringHandle RT_CoordinateFormatter_toMGRS(const RT_PointHandle point, RT_MGRSConversionMode MGRSConversionMode, int32_t precision, bool addSpaces, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_CoordinateFormatter_toMGRS_def)(const RT_PointHandle, RT_MGRSConversionMode, int32_t, bool, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_toMGRS_func = reinterpret_cast<RT_CoordinateFormatter_toMGRS_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_toMGRS")));
    
    return RT_CoordinateFormatter_toMGRS_func(point, MGRSConversionMode, precision, addSpaces, errorHandler);
}

RT_StringHandle RT_CoordinateFormatter_toUSNG(const RT_PointHandle point, int32_t precision, bool addSpaces, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_CoordinateFormatter_toUSNG_def)(const RT_PointHandle, int32_t, bool, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_toUSNG_func = reinterpret_cast<RT_CoordinateFormatter_toUSNG_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_toUSNG")));
    
    return RT_CoordinateFormatter_toUSNG_func(point, precision, addSpaces, errorHandler);
}

RT_StringHandle RT_CoordinateFormatter_toUTM(const RT_PointHandle point, RT_UTMConversionMode UTMConversionMode, bool addSpaces, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_CoordinateFormatter_toUTM_def)(const RT_PointHandle, RT_UTMConversionMode, bool, const RT_ErrorHandler*);
    static auto RT_CoordinateFormatter_toUTM_func = reinterpret_cast<RT_CoordinateFormatter_toUTM_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_CoordinateFormatter_toUTM")));
    
    return RT_CoordinateFormatter_toUTM_func(point, UTMConversionMode, addSpaces, errorHandler);
}
#endif