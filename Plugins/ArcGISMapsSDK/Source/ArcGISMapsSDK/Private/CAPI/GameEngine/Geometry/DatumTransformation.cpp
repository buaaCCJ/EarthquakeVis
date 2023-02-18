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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/DatumTransformation.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_DatumTransformation_destroy(RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_DatumTransformation_destroy_def)(RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_destroy_func = reinterpret_cast<RT_DatumTransformation_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_destroy")));
    
    RT_DatumTransformation_destroy_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_DatumTransformation_getInputSpatialReference(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_DatumTransformation_getInputSpatialReference_def)(const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_getInputSpatialReference_func = reinterpret_cast<RT_DatumTransformation_getInputSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_getInputSpatialReference")));
    
    return RT_DatumTransformation_getInputSpatialReference_func(thisHandle, errorHandler);
}

bool RT_DatumTransformation_getIsMissingProjectionEngineFiles(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DatumTransformation_getIsMissingProjectionEngineFiles_def)(const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_getIsMissingProjectionEngineFiles_func = reinterpret_cast<RT_DatumTransformation_getIsMissingProjectionEngineFiles_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_getIsMissingProjectionEngineFiles")));
    
    return RT_DatumTransformation_getIsMissingProjectionEngineFiles_func(thisHandle, errorHandler);
}

RT_StringHandle RT_DatumTransformation_getName(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_DatumTransformation_getName_def)(const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_getName_func = reinterpret_cast<RT_DatumTransformation_getName_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_getName")));
    
    return RT_DatumTransformation_getName_func(thisHandle, errorHandler);
}

RT_DatumTransformationType RT_DatumTransformation_getObjectType(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DatumTransformationType (*RT_DatumTransformation_getObjectType_def)(const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_getObjectType_func = reinterpret_cast<RT_DatumTransformation_getObjectType_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_getObjectType")));
    
    return RT_DatumTransformation_getObjectType_func(thisHandle, errorHandler);
}

RT_SpatialReferenceHandle RT_DatumTransformation_getOutputSpatialReference(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_SpatialReferenceHandle (*RT_DatumTransformation_getOutputSpatialReference_def)(const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_getOutputSpatialReference_func = reinterpret_cast<RT_DatumTransformation_getOutputSpatialReference_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_getOutputSpatialReference")));
    
    return RT_DatumTransformation_getOutputSpatialReference_func(thisHandle, errorHandler);
}

bool RT_DatumTransformation_equals(const RT_DatumTransformationHandle thisHandle, const RT_DatumTransformationHandle rightDatumTransformation, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_DatumTransformation_equals_def)(const RT_DatumTransformationHandle, const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_equals_func = reinterpret_cast<RT_DatumTransformation_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_equals")));
    
    return RT_DatumTransformation_equals_func(thisHandle, rightDatumTransformation, errorHandler);
}

size_t RT_DatumTransformation_getHash(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef size_t (*RT_DatumTransformation_getHash_def)(const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_getHash_func = reinterpret_cast<RT_DatumTransformation_getHash_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_getHash")));
    
    return RT_DatumTransformation_getHash_func(thisHandle, errorHandler);
}

RT_DatumTransformationHandle RT_DatumTransformation_getInverse(const RT_DatumTransformationHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DatumTransformationHandle (*RT_DatumTransformation_getInverse_def)(const RT_DatumTransformationHandle, const RT_ErrorHandler*);
    static auto RT_DatumTransformation_getInverse_func = reinterpret_cast<RT_DatumTransformation_getInverse_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_DatumTransformation_getInverse")));
    
    return RT_DatumTransformation_getInverse_func(thisHandle, errorHandler);
}
#endif