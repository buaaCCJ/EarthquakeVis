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
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISVisualizationAttribute.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISVisualizationAttributeType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/VisualizationAttribute.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Attributes
{
TArrayView<uint8> ArcGISVisualizationAttribute::GetData() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VisualizationAttribute_getData(reinterpret_cast<RT_VisualizationAttributeHandle>(GetHandle()), &errorHandler);
    
    return TArrayView<uint8>(localResult.data, localResult.size);
}

FString ArcGISVisualizationAttribute::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VisualizationAttribute_getName(reinterpret_cast<RT_VisualizationAttributeHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISVisualizationAttributeType ArcGISVisualizationAttribute::GetVisualizationAttributeType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VisualizationAttribute_getVisualizationAttributeType(reinterpret_cast<RT_VisualizationAttributeHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISVisualizationAttributeType>(localResult);
}

ArcGISVisualizationAttribute::ArcGISVisualizationAttribute(void* handle) :
    m_handle{ handle }
{
}

ArcGISVisualizationAttribute::ArcGISVisualizationAttribute(ArcGISVisualizationAttribute&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISVisualizationAttribute::~ArcGISVisualizationAttribute()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_VisualizationAttribute_destroy(reinterpret_cast<RT_VisualizationAttributeHandle>(m_handle), &errorHandler);
    }
}

ArcGISVisualizationAttribute& ArcGISVisualizationAttribute::operator=(ArcGISVisualizationAttribute&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISVisualizationAttribute::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISVisualizationAttribute::GetHandle() const
{
    return m_handle;
}
void ArcGISVisualizationAttribute::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri