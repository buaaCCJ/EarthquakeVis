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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeographicTransformation.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeographicTransformationStep.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeographicTransformation.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISGeographicTransformation::ArcGISGeographicTransformation(const Unreal::ArcGISImmutableArray<ArcGISGeographicTransformationStep>& steps) :
    ArcGISDatumTransformation{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSteps = static_cast<const RT_ArrayHandle>(steps.GetHandle());
    
    SetHandle(RT_GeographicTransformation_createWithSteps(localSteps, &errorHandler));
}

ArcGISGeographicTransformation::ArcGISGeographicTransformation(const ArcGISGeographicTransformationStep& step) :
    ArcGISDatumTransformation{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localStep = static_cast<const RT_GeographicTransformationStepHandle>(step.GetHandle());
    
    SetHandle(RT_GeographicTransformation_createWithStep(localStep, &errorHandler));
}

Unreal::ArcGISImmutableArray<ArcGISGeographicTransformationStep> ArcGISGeographicTransformation::GetSteps() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeographicTransformation_getSteps(reinterpret_cast<RT_GeographicTransformationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISGeographicTransformationStep>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISGeographicTransformationStep>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeographicTransformation::ArcGISGeographicTransformation(void* handle) :
    ArcGISDatumTransformation{ handle }
{
}

ArcGISGeographicTransformation::ArcGISGeographicTransformation(ArcGISGeographicTransformation&& other) noexcept :
    ArcGISDatumTransformation{ std::move(other) }
{
}

ArcGISGeographicTransformation::ArcGISGeographicTransformation() :
    ArcGISDatumTransformation{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri