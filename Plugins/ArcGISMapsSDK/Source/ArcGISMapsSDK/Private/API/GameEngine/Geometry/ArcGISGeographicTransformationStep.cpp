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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeographicTransformationStep.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeographicTransformationStep.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISGeographicTransformationStep::ArcGISGeographicTransformationStep(int32_t WKID)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GeographicTransformationStep_createWithWKID(WKID, &errorHandler));
}

ArcGISGeographicTransformationStep::ArcGISGeographicTransformationStep(const FString& WKText)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GeographicTransformationStep_createWithWKText(TCHAR_TO_ANSI(*WKText), &errorHandler));
}

bool ArcGISGeographicTransformationStep::GetIsInverse() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeographicTransformationStep_getIsInverse(reinterpret_cast<RT_GeographicTransformationStepHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISGeographicTransformationStep::GetIsMissingProjectionEngineFiles() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeographicTransformationStep_getIsMissingProjectionEngineFiles(reinterpret_cast<RT_GeographicTransformationStepHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

Unreal::ArcGISImmutableArray<FString> ArcGISGeographicTransformationStep::GetProjectionEngineFilenames() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeographicTransformationStep_getProjectionEngineFilenames(reinterpret_cast<RT_GeographicTransformationStepHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<FString>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<FString>{ localResult };
    }
    
    return localLocalResult;
}

int32_t ArcGISGeographicTransformationStep::GetWKID() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeographicTransformationStep_getWKID(reinterpret_cast<RT_GeographicTransformationStepHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

FString ArcGISGeographicTransformationStep::GetWKText() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeographicTransformationStep_getWKText(reinterpret_cast<RT_GeographicTransformationStepHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

bool ArcGISGeographicTransformationStep::Equals(const ArcGISGeographicTransformationStep& rightGeographicTransformationStep) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localRightGeographicTransformationStep = static_cast<const RT_GeographicTransformationStepHandle>(rightGeographicTransformationStep.GetHandle());
    
    auto localResult = RT_GeographicTransformationStep_equals(reinterpret_cast<RT_GeographicTransformationStepHandle>(GetHandle()), localRightGeographicTransformationStep, &errorHandler);
    
    return localResult;
}

ArcGISGeographicTransformationStep ArcGISGeographicTransformationStep::GetInverse() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeographicTransformationStep_getInverse(reinterpret_cast<RT_GeographicTransformationStepHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISGeographicTransformationStep{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISGeographicTransformationStep{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeographicTransformationStep::ArcGISGeographicTransformationStep(void* handle) :
    m_handle{ handle }
{
}

ArcGISGeographicTransformationStep::ArcGISGeographicTransformationStep(ArcGISGeographicTransformationStep&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISGeographicTransformationStep::~ArcGISGeographicTransformationStep()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GeographicTransformationStep_destroy(reinterpret_cast<RT_GeographicTransformationStepHandle>(m_handle), &errorHandler);
    }
}

ArcGISGeographicTransformationStep& ArcGISGeographicTransformationStep::operator=(ArcGISGeographicTransformationStep&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISGeographicTransformationStep::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISGeographicTransformationStep::GetHandle() const
{
    return m_handle;
}
void ArcGISGeographicTransformationStep::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri