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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDatumTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelope.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeographicTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISHorizontalVerticalTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISTransformationCatalog.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/DatumTransformation.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/TransformationCatalog.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
FString ArcGISTransformationCatalog::GetProjectionEngineDirectory()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_TransformationCatalog_getProjectionEngineDirectory(&errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}
void ArcGISTransformationCatalog::SetProjectionEngineDirectory(const FString& projectionEngineDirectory)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_TransformationCatalog_setProjectionEngineDirectory(TCHAR_TO_ANSI(*projectionEngineDirectory), &errorHandler);
}

ArcGISDatumTransformation ArcGISTransformationCatalog::GetTransformation(const ArcGISSpatialReference& inputSpatialReference, const ArcGISSpatialReference& outputSpatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localInputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(inputSpatialReference.GetHandle());
    const auto localOutputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(outputSpatialReference.GetHandle());
    
    auto localResult = RT_TransformationCatalog_getTransformation(localInputSpatialReference, localOutputSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISDatumTransformation{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_DatumTransformation_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_DatumTransformationType_geographicTransformation:
                localLocalResult = ArcGISGeographicTransformation{ localResult };
                break;
            case RT_DatumTransformationType_horizontalVerticalTransformation:
                localLocalResult = ArcGISHorizontalVerticalTransformation{ localResult };
                break;
            default:
                localLocalResult = ArcGISDatumTransformation{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISDatumTransformation ArcGISTransformationCatalog::GetTransformation(const ArcGISSpatialReference& inputSpatialReference, const ArcGISSpatialReference& outputSpatialReference, const ArcGISEnvelope& areaOfInterest)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localInputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(inputSpatialReference.GetHandle());
    const auto localOutputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(outputSpatialReference.GetHandle());
    const auto localAreaOfInterest = static_cast<const RT_EnvelopeHandle>(areaOfInterest.GetHandle());
    
    auto localResult = RT_TransformationCatalog_getTransformationWithAreaOfInterest(localInputSpatialReference, localOutputSpatialReference, localAreaOfInterest, &errorHandler);
    
    auto localLocalResult = ArcGISDatumTransformation{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_DatumTransformation_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_DatumTransformationType_geographicTransformation:
                localLocalResult = ArcGISGeographicTransformation{ localResult };
                break;
            case RT_DatumTransformationType_horizontalVerticalTransformation:
                localLocalResult = ArcGISHorizontalVerticalTransformation{ localResult };
                break;
            default:
                localLocalResult = ArcGISDatumTransformation{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISDatumTransformation ArcGISTransformationCatalog::GetTransformation(const ArcGISSpatialReference& inputSpatialReference, const ArcGISSpatialReference& outputSpatialReference, const ArcGISEnvelope& areaOfInterest, bool ignoreVertical)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localInputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(inputSpatialReference.GetHandle());
    const auto localOutputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(outputSpatialReference.GetHandle());
    const auto localAreaOfInterest = static_cast<const RT_EnvelopeHandle>(areaOfInterest.GetHandle());
    
    auto localResult = RT_TransformationCatalog_getTransformationWithAreaOfInterestAndIgnoreVertical(localInputSpatialReference, localOutputSpatialReference, localAreaOfInterest, ignoreVertical, &errorHandler);
    
    auto localLocalResult = ArcGISDatumTransformation{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_DatumTransformation_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_DatumTransformationType_geographicTransformation:
                localLocalResult = ArcGISGeographicTransformation{ localResult };
                break;
            case RT_DatumTransformationType_horizontalVerticalTransformation:
                localLocalResult = ArcGISHorizontalVerticalTransformation{ localResult };
                break;
            default:
                localLocalResult = ArcGISDatumTransformation{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

Unreal::ArcGISImmutableArray<ArcGISDatumTransformation> ArcGISTransformationCatalog::GetTransformationsBySuitability(const ArcGISSpatialReference& inputSpatialReference, const ArcGISSpatialReference& outputSpatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localInputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(inputSpatialReference.GetHandle());
    const auto localOutputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(outputSpatialReference.GetHandle());
    
    auto localResult = RT_TransformationCatalog_getTransformationsBySuitability(localInputSpatialReference, localOutputSpatialReference, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISDatumTransformation>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISDatumTransformation>{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISImmutableArray<ArcGISDatumTransformation> ArcGISTransformationCatalog::GetTransformationsBySuitability(const ArcGISSpatialReference& inputSpatialReference, const ArcGISSpatialReference& outputSpatialReference, const ArcGISEnvelope& areaOfInterest)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localInputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(inputSpatialReference.GetHandle());
    const auto localOutputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(outputSpatialReference.GetHandle());
    const auto localAreaOfInterest = static_cast<const RT_EnvelopeHandle>(areaOfInterest.GetHandle());
    
    auto localResult = RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterest(localInputSpatialReference, localOutputSpatialReference, localAreaOfInterest, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISDatumTransformation>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISDatumTransformation>{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISImmutableArray<ArcGISDatumTransformation> ArcGISTransformationCatalog::GetTransformationsBySuitability(const ArcGISSpatialReference& inputSpatialReference, const ArcGISSpatialReference& outputSpatialReference, const ArcGISEnvelope& areaOfInterest, bool ignoreVertical)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localInputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(inputSpatialReference.GetHandle());
    const auto localOutputSpatialReference = static_cast<const RT_SpatialReferenceHandle>(outputSpatialReference.GetHandle());
    const auto localAreaOfInterest = static_cast<const RT_EnvelopeHandle>(areaOfInterest.GetHandle());
    
    auto localResult = RT_TransformationCatalog_getTransformationsBySuitabilityWithAreaOfInterestAndIgnoreVertical(localInputSpatialReference, localOutputSpatialReference, localAreaOfInterest, ignoreVertical, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISDatumTransformation>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISDatumTransformation>{ localResult };
    }
    
    return localLocalResult;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri