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
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISVisualizationAttributeDescription.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISVisualizationAttributeType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/VisualizationAttributeDescription.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Attributes
{
ArcGISVisualizationAttributeDescription::ArcGISVisualizationAttributeDescription(const FString& name, ArcGISVisualizationAttributeType visualizationAttributeType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_VisualizationAttributeDescription_create(TCHAR_TO_ANSI(*name), static_cast<RT_VisualizationAttributeType>(visualizationAttributeType), &errorHandler));
}

FString ArcGISVisualizationAttributeDescription::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VisualizationAttributeDescription_getName(reinterpret_cast<RT_VisualizationAttributeDescriptionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISVisualizationAttributeType ArcGISVisualizationAttributeDescription::GetVisualizationAttributeType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VisualizationAttributeDescription_getVisualizationAttributeType(reinterpret_cast<RT_VisualizationAttributeDescriptionHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISVisualizationAttributeType>(localResult);
}

ArcGISVisualizationAttributeDescription::ArcGISVisualizationAttributeDescription(void* handle) :
    m_handle{ handle }
{
}

ArcGISVisualizationAttributeDescription::ArcGISVisualizationAttributeDescription(ArcGISVisualizationAttributeDescription&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISVisualizationAttributeDescription::~ArcGISVisualizationAttributeDescription()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_VisualizationAttributeDescription_destroy(reinterpret_cast<RT_VisualizationAttributeDescriptionHandle>(m_handle), &errorHandler);
    }
}

ArcGISVisualizationAttributeDescription& ArcGISVisualizationAttributeDescription::operator=(ArcGISVisualizationAttributeDescription&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISVisualizationAttributeDescription::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISVisualizationAttributeDescription::GetHandle() const
{
    return m_handle;
}
void ArcGISVisualizationAttributeDescription::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri