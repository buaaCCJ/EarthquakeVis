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
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttribute.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttributeType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/Attribute.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Attributes
{
ArcGISAttributeType ArcGISAttribute::GetAttributeType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Attribute_getAttributeType(reinterpret_cast<RT_AttributeHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISAttributeType>(localResult);
}

TArrayView<uint8> ArcGISAttribute::GetData() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Attribute_getData(reinterpret_cast<RT_AttributeHandle>(GetHandle()), &errorHandler);
    
    return TArrayView<uint8>(localResult.data, localResult.size);
}

FString ArcGISAttribute::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Attribute_getName(reinterpret_cast<RT_AttributeHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISAttribute::ArcGISAttribute(void* handle) :
    m_handle{ handle }
{
}

ArcGISAttribute::ArcGISAttribute(ArcGISAttribute&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISAttribute::~ArcGISAttribute()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Attribute_destroy(reinterpret_cast<RT_AttributeHandle>(m_handle), &errorHandler);
    }
}

ArcGISAttribute& ArcGISAttribute::operator=(ArcGISAttribute&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISAttribute::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISAttribute::GetHandle() const
{
    return m_handle;
}
void ArcGISAttribute::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri