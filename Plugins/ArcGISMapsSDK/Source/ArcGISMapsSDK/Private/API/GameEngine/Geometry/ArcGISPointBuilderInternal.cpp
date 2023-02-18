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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPointBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPointBuilderInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
void ArcGISPointBuilderInternal::Normalize(ArcGISPointBuilder* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_PointBuilder_normalize(reinterpret_cast<RT_PointBuilderHandle>(self->GetHandle()), &errorHandler);
}

void ArcGISPointBuilderInternal::Normalize(ArcGISPointBuilder* self, const ArcGISEnvelope& envelope)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localEnvelope = static_cast<const RT_EnvelopeHandle>(envelope.GetHandle());
    
    RT_PointBuilder_normalizeToEnvelope(reinterpret_cast<RT_PointBuilderHandle>(self->GetHandle()), localEnvelope, &errorHandler);
}

void ArcGISPointBuilderInternal::Normalize(ArcGISPointBuilder* self, const ArcGISPoint& target)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localTarget = static_cast<const RT_PointHandle>(target.GetHandle());
    
    RT_PointBuilder_normalizeToPointClosestTo(reinterpret_cast<RT_PointBuilderHandle>(self->GetHandle()), localTarget, &errorHandler);
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri