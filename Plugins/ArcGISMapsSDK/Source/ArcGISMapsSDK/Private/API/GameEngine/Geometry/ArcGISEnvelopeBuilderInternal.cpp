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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelope.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelopeBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelopeBuilderInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISEnvelope ArcGISEnvelopeBuilderInternal::AdjustForWrapAround(ArcGISEnvelopeBuilder* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_adjustForWrapAround(reinterpret_cast<RT_EnvelopeBuilderHandle>(self->GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

void ArcGISEnvelopeBuilderInternal::Normalize(ArcGISEnvelopeBuilder* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_normalize(reinterpret_cast<RT_EnvelopeBuilderHandle>(self->GetHandle()), &errorHandler);
}

void ArcGISEnvelopeBuilderInternal::Normalize(ArcGISEnvelopeBuilder* self, const ArcGISEnvelope& envelope)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localEnvelope = static_cast<const RT_EnvelopeHandle>(envelope.GetHandle());
    
    RT_EnvelopeBuilder_normalizeToEnvelope(reinterpret_cast<RT_EnvelopeBuilderHandle>(self->GetHandle()), localEnvelope, &errorHandler);
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri