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
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileStyle.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_VectorTileStyle_destroy(RT_VectorTileStyleHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_VectorTileStyle_destroy_def)(RT_VectorTileStyleHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileStyle_destroy_func = reinterpret_cast<RT_VectorTileStyle_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileStyle_destroy")));
    
    RT_VectorTileStyle_destroy_func(thisHandle, errorHandler);
}

RT_StringHandle RT_VectorTileStyle_getSourceURI(const RT_VectorTileStyleHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_VectorTileStyle_getSourceURI_def)(const RT_VectorTileStyleHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileStyle_getSourceURI_func = reinterpret_cast<RT_VectorTileStyle_getSourceURI_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileStyle_getSourceURI")));
    
    return RT_VectorTileStyle_getSourceURI_func(thisHandle, errorHandler);
}

RT_StringHandle RT_VectorTileStyle_getVersion(const RT_VectorTileStyleHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_VectorTileStyle_getVersion_def)(const RT_VectorTileStyleHandle, const RT_ErrorHandler*);
    static auto RT_VectorTileStyle_getVersion_func = reinterpret_cast<RT_VectorTileStyle_getVersion_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_VectorTileStyle_getVersion")));
    
    return RT_VectorTileStyle_getVersion_func(thisHandle, errorHandler);
}
#endif