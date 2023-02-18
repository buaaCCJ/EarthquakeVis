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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISHorizontalVerticalTransformationStep.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/HorizontalVerticalTransformationStep.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISHorizontalVerticalTransformationStep::ArcGISHorizontalVerticalTransformationStep(int32_t WKID)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_HorizontalVerticalTransformationStep_createWithWKID(WKID, &errorHandler));
}

ArcGISHorizontalVerticalTransformationStep::ArcGISHorizontalVerticalTransformationStep(const FString& WKText)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_HorizontalVerticalTransformationStep_createWithWKText(TCHAR_TO_ANSI(*WKText), &errorHandler));
}

bool ArcGISHorizontalVerticalTransformationStep::GetIsInverse() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_HorizontalVerticalTransformationStep_getIsInverse(reinterpret_cast<RT_HorizontalVerticalTransformationStepHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISHorizontalVerticalTransformationStep::GetIsMissingProjectionEngineFiles() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_HorizontalVerticalTransformationStep_getIsMissingProjectionEngineFiles(reinterpret_cast<RT_HorizontalVerticalTransformationStepHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

Unreal::ArcGISImmutableArray<FString> ArcGISHorizontalVerticalTransformationStep::GetProjectionEngineFilenames() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_HorizontalVerticalTransformationStep_getProjectionEngineFilenames(reinterpret_cast<RT_HorizontalVerticalTransformationStepHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<FString>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<FString>{ localResult };
    }
    
    return localLocalResult;
}

int32_t ArcGISHorizontalVerticalTransformationStep::GetWKID() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_HorizontalVerticalTransformationStep_getWKID(reinterpret_cast<RT_HorizontalVerticalTransformationStepHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

FString ArcGISHorizontalVerticalTransformationStep::GetWKText() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_HorizontalVerticalTransformationStep_getWKText(reinterpret_cast<RT_HorizontalVerticalTransformationStepHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

bool ArcGISHorizontalVerticalTransformationStep::Equals(const ArcGISHorizontalVerticalTransformationStep& rightHorizontalVerticalTransformationStep) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localRightHorizontalVerticalTransformationStep = static_cast<const RT_HorizontalVerticalTransformationStepHandle>(rightHorizontalVerticalTransformationStep.GetHandle());
    
    auto localResult = RT_HorizontalVerticalTransformationStep_equals(reinterpret_cast<RT_HorizontalVerticalTransformationStepHandle>(GetHandle()), localRightHorizontalVerticalTransformationStep, &errorHandler);
    
    return localResult;
}

ArcGISHorizontalVerticalTransformationStep ArcGISHorizontalVerticalTransformationStep::GetInverse() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_HorizontalVerticalTransformationStep_getInverse(reinterpret_cast<RT_HorizontalVerticalTransformationStepHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISHorizontalVerticalTransformationStep{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISHorizontalVerticalTransformationStep{ localResult };
    }
    
    return localLocalResult;
}

ArcGISHorizontalVerticalTransformationStep::ArcGISHorizontalVerticalTransformationStep(void* handle) :
    m_handle{ handle }
{
}

ArcGISHorizontalVerticalTransformationStep::ArcGISHorizontalVerticalTransformationStep(ArcGISHorizontalVerticalTransformationStep&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISHorizontalVerticalTransformationStep::~ArcGISHorizontalVerticalTransformationStep()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_HorizontalVerticalTransformationStep_destroy(reinterpret_cast<RT_HorizontalVerticalTransformationStepHandle>(m_handle), &errorHandler);
    }
}

ArcGISHorizontalVerticalTransformationStep& ArcGISHorizontalVerticalTransformationStep::operator=(ArcGISHorizontalVerticalTransformationStep&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISHorizontalVerticalTransformationStep::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISHorizontalVerticalTransformationStep::GetHandle() const
{
    return m_handle;
}
void ArcGISHorizontalVerticalTransformationStep::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri