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
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/TransformationCatalog.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

RT_StringHandle RT_TransformationCatalog_getProjectionEngineDirectory(const RT_ErrorHandler* errorHandler)
{
    typedef RT_StringHandle (*RT_TransformationCatalog_getProjectionEngineDirectory_def)(const RT_ErrorHandler*);
    static auto RT_TransformationCatalog_getProjectionEngineDirectory_func = reinterpret_cast<RT_TransformationCatalog_getProjectionEngineDirectory_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_TransformationCatalog_getProjectionEngineDirectory")));
    
    return RT_TransformationCatalog_getProjectionEngineDirectory_func(errorHandler);
}
void RT_TransformationCatalog_setProjectionEngineDirectory(char* projectionEngineDirectory, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_TransformationCatalog_setProjectionEngineDirectory_def)(char*, const RT_ErrorHandler*);
    static auto RT_TransformationCatalog_setProjectionEngineDirectory_func = reinterpret_cast<RT_TransformationCatalog_setProjectionEngineDirectory_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_TransformationCatalog_setProjectionEngineDirectory")));
    
    RT_TransformationCatalog_setProjectionEngineDirectory_func(projectionEngineDirectory, errorHandler);
}

RT_DatumTransformationHandle RT_TransformationCatalog_getTransformation(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DatumTransformationHandle (*RT_TransformationCatalog_getTransformation_def)(const RT_SpatialReferenceHandle, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_TransformationCatalog_getTransformation_func = reinterpret_cast<RT_TransformationCatalog_getTransformation_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_TransformationCatalog_getTransformation")));
    
    return RT_TransformationCatalog_getTransformation_func(inputSpatialReference, outputSpatialReference, errorHandler);
}

RT_DatumTransformationHandle RT_TransformationCatalog_getTransformationWithAreaOfInterest(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_EnvelopeHandle areaOfInterest, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DatumTransformationHandle (*RT_TransformationCatalog_getTransformationWithAreaOfInterest_def)(const RT_SpatialReferenceHandle, const RT_SpatialReferenceHandle, const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_TransformationCatalog_getTransformationWithAreaOfInterest_func = reinterpret_cast<RT_TransformationCatalog_getTransformationWithAreaOfInterest_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_TransformationCatalog_getTransformationWithAreaOfInterest")));
    
    return RT_TransformationCatalog_getTransformationWithAreaOfInterest_func(inputSpatialReference, outputSpatialReference, areaOfInterest, errorHandler);
}

RT_DatumTransformationHandle RT_TransformationCatalog_getTransformationWithAreaOfInterestAndIgnoreVertical(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_EnvelopeHandle areaOfInterest, bool ignoreVertical, const RT_ErrorHandler* errorHandler)
{
    typedef RT_DatumTransformationHandle (*RT_TransformationCatalog_getTransformationWithAreaOfInterestAndIgnoreVertical_def)(const RT_SpatialReferenceHandle, const RT_SpatialReferenceHandle, const RT_EnvelopeHandle, bool, const RT_ErrorHandler*);
    static auto RT_TransformationCatalog_getTransformationWithAreaOfInterestAndIgnoreVertical_func = reinterpret_cast<RT_TransformationCatalog_getTransformationWithAreaOfInterestAndIgnoreVertical_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_TransformationCatalog_getTransformationWithAreaOfInterestAndIgnoreVertical")));
    
    return RT_TransformationCatalog_getTransformationWithAreaOfInterestAndIgnoreVertical_func(inputSpatialReference, outputSpatialReference, areaOfInterest, ignoreVertical, errorHandler);
}

RT_ArrayHandle RT_TransformationCatalog_getTransformationsBySuitability(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_TransformationCatalog_getTransformationsBySuitability_def)(const RT_SpatialReferenceHandle, const RT_SpatialReferenceHandle, const RT_ErrorHandler*);
    static auto RT_TransformationCatalog_getTransformationsBySuitability_func = reinterpret_cast<RT_TransformationCatalog_getTransformationsBySuitability_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_TransformationCatalog_getTransformationsBySuitability")));
    
    return RT_TransformationCatalog_getTransformationsBySuitability_func(inputSpatialReference, outputSpatialReference, errorHandler);
}

RT_ArrayHandle RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterest(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_EnvelopeHandle areaOfInterest, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterest_def)(const RT_SpatialReferenceHandle, const RT_SpatialReferenceHandle, const RT_EnvelopeHandle, const RT_ErrorHandler*);
    static auto RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterest_func = reinterpret_cast<RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterest_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterest")));
    
    return RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterest_func(inputSpatialReference, outputSpatialReference, areaOfInterest, errorHandler);
}

RT_ArrayHandle RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterestAndIgnoreVertical(const RT_SpatialReferenceHandle inputSpatialReference, const RT_SpatialReferenceHandle outputSpatialReference, const RT_EnvelopeHandle areaOfInterest, bool ignoreVertical, const RT_ErrorHandler* errorHandler)
{
    typedef RT_ArrayHandle (*RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterestAndIgnoreVertical_def)(const RT_SpatialReferenceHandle, const RT_SpatialReferenceHandle, const RT_EnvelopeHandle, bool, const RT_ErrorHandler*);
    static auto RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterestAndIgnoreVertical_func = reinterpret_cast<RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterestAndIgnoreVertical_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterestAndIgnoreVertical")));
    
    return RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterestAndIgnoreVertical_func(inputSpatialReference, outputSpatialReference, areaOfInterest, ignoreVertical, errorHandler);
}
#endif