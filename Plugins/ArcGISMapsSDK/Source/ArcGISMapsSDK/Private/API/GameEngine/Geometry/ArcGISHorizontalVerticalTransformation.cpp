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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISHorizontalVerticalTransformation.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISHorizontalVerticalTransformationStep.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/HorizontalVerticalTransformation.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISHorizontalVerticalTransformation::ArcGISHorizontalVerticalTransformation(const Unreal::ArcGISImmutableArray<ArcGISHorizontalVerticalTransformationStep>& steps) :
    ArcGISDatumTransformation{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSteps = static_cast<const RT_ArrayHandle>(steps.GetHandle());
    
    SetHandle(RT_HorizontalVerticalTransformation_createWithSteps(localSteps, &errorHandler));
}

ArcGISHorizontalVerticalTransformation::ArcGISHorizontalVerticalTransformation(const ArcGISHorizontalVerticalTransformationStep& step) :
    ArcGISDatumTransformation{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localStep = static_cast<const RT_HorizontalVerticalTransformationStepHandle>(step.GetHandle());
    
    SetHandle(RT_HorizontalVerticalTransformation_createWithStep(localStep, &errorHandler));
}

Unreal::ArcGISImmutableArray<ArcGISHorizontalVerticalTransformationStep> ArcGISHorizontalVerticalTransformation::GetSteps() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_HorizontalVerticalTransformation_getSteps(reinterpret_cast<RT_HorizontalVerticalTransformationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISHorizontalVerticalTransformationStep>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISHorizontalVerticalTransformationStep>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISHorizontalVerticalTransformation::ArcGISHorizontalVerticalTransformation(void* handle) :
    ArcGISDatumTransformation{ handle }
{
}

ArcGISHorizontalVerticalTransformation::ArcGISHorizontalVerticalTransformation(ArcGISHorizontalVerticalTransformation&& other) noexcept :
    ArcGISDatumTransformation{ std::move(other) }
{
}

ArcGISHorizontalVerticalTransformation::ArcGISHorizontalVerticalTransformation() :
    ArcGISDatumTransformation{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri