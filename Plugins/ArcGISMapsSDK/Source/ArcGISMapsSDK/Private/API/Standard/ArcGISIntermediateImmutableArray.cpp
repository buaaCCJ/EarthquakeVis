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
#include "ArcGISMapsSDK/API/Standard/ArcGISArrayType.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISElement.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISElementType.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISIntermediateImmutableArray.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Standard/ArcGISIntermediateImmutableArrayBuilder.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/Standard/Array.h"

namespace Esri
{
namespace Standard
{
ArcGISArrayType ArcGISIntermediateImmutableArray::GetObjectType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Array_getObjectType(reinterpret_cast<RT_ArrayHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISArrayType>(localResult);
}

size_t ArcGISIntermediateImmutableArray::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Array_getSize(reinterpret_cast<RT_ArrayHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISElementType ArcGISIntermediateImmutableArray::GetValueType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Array_getValueType(reinterpret_cast<RT_ArrayHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISElementType>(localResult);
}

ArcGISElement ArcGISIntermediateImmutableArray::At(size_t position) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Array_at(reinterpret_cast<RT_ArrayHandle>(GetHandle()), position, &errorHandler);
    
    auto localLocalResult = ArcGISElement{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISElement{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISIntermediateImmutableArray::Contains(const ArcGISElement& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_ElementHandle>(value.GetHandle());
    
    auto localResult = RT_Array_contains(reinterpret_cast<RT_ArrayHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

ArcGISIntermediateImmutableArrayBuilder ArcGISIntermediateImmutableArray::CreateBuilder(ArcGISElementType valueType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Array_createBuilder(static_cast<RT_ElementType>(valueType), &errorHandler);
    
    auto localLocalResult = ArcGISIntermediateImmutableArrayBuilder{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISIntermediateImmutableArrayBuilder{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISIntermediateImmutableArray::Equals(const Unreal::ArcGISImmutableArray<ArcGISElement>& array2) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localArray2 = static_cast<const RT_ArrayHandle>(array2.GetHandle());
    
    auto localResult = RT_Array_equals(reinterpret_cast<RT_ArrayHandle>(GetHandle()), localArray2, &errorHandler);
    
    return localResult;
}

ArcGISElement ArcGISIntermediateImmutableArray::First() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Array_first(reinterpret_cast<RT_ArrayHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISElement{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISElement{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISIntermediateImmutableArray::IndexOf(const ArcGISElement& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_ElementHandle>(value.GetHandle());
    
    auto localResult = RT_Array_indexOf(reinterpret_cast<RT_ArrayHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

bool ArcGISIntermediateImmutableArray::IsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Array_isEmpty(reinterpret_cast<RT_ArrayHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISElement ArcGISIntermediateImmutableArray::Last() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Array_last(reinterpret_cast<RT_ArrayHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISElement{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISElement{ localResult };
    }
    
    return localLocalResult;
}

ArcGISIntermediateImmutableArray::ArcGISIntermediateImmutableArray(void* handle) :
    m_handle{ handle }
{
}

ArcGISIntermediateImmutableArray::ArcGISIntermediateImmutableArray(ArcGISIntermediateImmutableArray&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISIntermediateImmutableArray::~ArcGISIntermediateImmutableArray()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Array_destroy(reinterpret_cast<RT_ArrayHandle>(m_handle), &errorHandler);
    }
}

ArcGISIntermediateImmutableArray& ArcGISIntermediateImmutableArray::operator=(ArcGISIntermediateImmutableArray&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISIntermediateImmutableArray::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISIntermediateImmutableArray::GetHandle() const
{
    return m_handle;
}
void ArcGISIntermediateImmutableArray::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Standard
} // namespace Esri