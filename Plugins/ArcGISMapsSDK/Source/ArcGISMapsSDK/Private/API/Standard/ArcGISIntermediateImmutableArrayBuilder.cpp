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
#include "ArcGISMapsSDK/API/Standard/ArcGISElement.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISElementType.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISIntermediateImmutableArrayBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/Standard/ArrayBuilder.h"

namespace Esri
{
namespace Standard
{
ArcGISElementType ArcGISIntermediateImmutableArrayBuilder::GetValueType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ArrayBuilder_getValueType(reinterpret_cast<RT_ArrayBuilderHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISElementType>(localResult);
}

void ArcGISIntermediateImmutableArrayBuilder::Add(const ArcGISElement& value)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_ElementHandle>(value.GetHandle());
    
    RT_ArrayBuilder_add(reinterpret_cast<RT_ArrayBuilderHandle>(GetHandle()), localValue, &errorHandler);
}

Unreal::ArcGISImmutableArray<ArcGISElement> ArcGISIntermediateImmutableArrayBuilder::MoveToArray()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ArrayBuilder_moveToArray(reinterpret_cast<RT_ArrayBuilderHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableArray<ArcGISElement>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableArray<ArcGISElement>{ localResult };
    }
    
    return localLocalResult;
}

ArcGISIntermediateImmutableArrayBuilder::ArcGISIntermediateImmutableArrayBuilder(void* handle) :
    m_handle{ handle }
{
}

ArcGISIntermediateImmutableArrayBuilder::ArcGISIntermediateImmutableArrayBuilder(ArcGISIntermediateImmutableArrayBuilder&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISIntermediateImmutableArrayBuilder::~ArcGISIntermediateImmutableArrayBuilder()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_ArrayBuilder_destroy(reinterpret_cast<RT_ArrayBuilderHandle>(m_handle), &errorHandler);
    }
}

ArcGISIntermediateImmutableArrayBuilder& ArcGISIntermediateImmutableArrayBuilder::operator=(ArcGISIntermediateImmutableArrayBuilder&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISIntermediateImmutableArrayBuilder::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISIntermediateImmutableArrayBuilder::GetHandle() const
{
    return m_handle;
}
void ArcGISIntermediateImmutableArrayBuilder::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Standard
} // namespace Esri