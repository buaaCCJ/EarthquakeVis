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
#include "ArcGISMapsSDK/API/Standard/ArcGISIntermediateMutableArray.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISList.h"
#include "ArcGISMapsSDK/CAPI/Standard/MutableArray.h"

namespace Esri
{
namespace Standard
{
ArcGISIntermediateMutableArray::ArcGISIntermediateMutableArray(ArcGISElementType valueType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_Vector_create(static_cast<RT_ElementType>(valueType), &errorHandler));
}

size_t ArcGISIntermediateMutableArray::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Vector_getSize(reinterpret_cast<RT_VectorHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISElementType ArcGISIntermediateMutableArray::GetValueType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Vector_getValueType(reinterpret_cast<RT_VectorHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISElementType>(localResult);
}

size_t ArcGISIntermediateMutableArray::Add(const Unreal::ArcGISList<ArcGISElement>& vector2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localVector2 = static_cast<const RT_VectorHandle>(vector2.GetHandle());
    
    auto localResult = RT_Vector_addArray(reinterpret_cast<RT_VectorHandle>(GetHandle()), localVector2, &errorHandler);
    
    return localResult;
}

size_t ArcGISIntermediateMutableArray::Add(const ArcGISElement& value)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_ElementHandle>(value.GetHandle());
    
    auto localResult = RT_Vector_add(reinterpret_cast<RT_VectorHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

ArcGISElement ArcGISIntermediateMutableArray::At(size_t position) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Vector_at(reinterpret_cast<RT_VectorHandle>(GetHandle()), position, &errorHandler);
    
    auto localLocalResult = ArcGISElement{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISElement{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISIntermediateMutableArray::Contains(const ArcGISElement& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_ElementHandle>(value.GetHandle());
    
    auto localResult = RT_Vector_contains(reinterpret_cast<RT_VectorHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

bool ArcGISIntermediateMutableArray::Equals(const Unreal::ArcGISList<ArcGISElement>& vector2) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localVector2 = static_cast<const RT_VectorHandle>(vector2.GetHandle());
    
    auto localResult = RT_Vector_equals(reinterpret_cast<RT_VectorHandle>(GetHandle()), localVector2, &errorHandler);
    
    return localResult;
}

ArcGISElement ArcGISIntermediateMutableArray::First() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Vector_first(reinterpret_cast<RT_VectorHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISElement{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISElement{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISIntermediateMutableArray::IndexOf(const ArcGISElement& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_ElementHandle>(value.GetHandle());
    
    auto localResult = RT_Vector_indexOf(reinterpret_cast<RT_VectorHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

void ArcGISIntermediateMutableArray::Insert(size_t position, const ArcGISElement& value)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_ElementHandle>(value.GetHandle());
    
    RT_Vector_insert(reinterpret_cast<RT_VectorHandle>(GetHandle()), position, localValue, &errorHandler);
}

bool ArcGISIntermediateMutableArray::IsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Vector_isEmpty(reinterpret_cast<RT_VectorHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISElement ArcGISIntermediateMutableArray::Last() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Vector_last(reinterpret_cast<RT_VectorHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISElement{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISElement{ localResult };
    }
    
    return localLocalResult;
}

void ArcGISIntermediateMutableArray::Move(size_t oldPosition, size_t newPosition)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_Vector_move(reinterpret_cast<RT_VectorHandle>(GetHandle()), oldPosition, newPosition, &errorHandler);
}

size_t ArcGISIntermediateMutableArray::Npos()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Vector_npos(&errorHandler);
    
    return localResult;
}

void ArcGISIntermediateMutableArray::Remove(size_t position)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_Vector_remove(reinterpret_cast<RT_VectorHandle>(GetHandle()), position, &errorHandler);
}

void ArcGISIntermediateMutableArray::RemoveAll()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_Vector_removeAll(reinterpret_cast<RT_VectorHandle>(GetHandle()), &errorHandler);
}

ArcGISMutableArrayElementAddedEvent<ArcGISElement> ArcGISIntermediateMutableArray::GetElementAdded() const
{
    return m_elementAdded;
}
void ArcGISIntermediateMutableArray::SetElementAdded(ArcGISMutableArrayElementAddedEvent<ArcGISElement> elementAdded)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_elementAdded = std::move(elementAdded);
    
    static auto callbackHandler = [](void* userData, size_t position_, RT_ElementHandle element_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISIntermediateMutableArray*>(userData);
        
        auto callback = callbackObject->GetElementAdded();
        
        if (!callback)
        {
            return;
        }
        
        auto localElement = ArcGISElement{};
        
        if (element_ != nullptr)
        {
            localElement = ArcGISElement{ element_ };
        }
        
        callback(position_, localElement);
    };
    
    if (m_elementAdded)
    {
        RT_Vector_setElementAddedCallback(reinterpret_cast<RT_VectorHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_Vector_setElementAddedCallback(reinterpret_cast<RT_VectorHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISMutableArrayElementRemovedEvent<ArcGISElement> ArcGISIntermediateMutableArray::GetElementRemoved() const
{
    return m_elementRemoved;
}
void ArcGISIntermediateMutableArray::SetElementRemoved(ArcGISMutableArrayElementRemovedEvent<ArcGISElement> elementRemoved)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_elementRemoved = std::move(elementRemoved);
    
    static auto callbackHandler = [](void* userData, size_t position_, RT_ElementHandle element_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISIntermediateMutableArray*>(userData);
        
        auto callback = callbackObject->GetElementRemoved();
        
        if (!callback)
        {
            return;
        }
        
        auto localElement = ArcGISElement{};
        
        if (element_ != nullptr)
        {
            localElement = ArcGISElement{ element_ };
        }
        
        callback(position_, localElement);
    };
    
    if (m_elementRemoved)
    {
        RT_Vector_setElementRemovedCallback(reinterpret_cast<RT_VectorHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_Vector_setElementRemovedCallback(reinterpret_cast<RT_VectorHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISIntermediateMutableArray::ArcGISIntermediateMutableArray(void* handle) :
    m_handle{ handle }
{
}

ArcGISIntermediateMutableArray::ArcGISIntermediateMutableArray(ArcGISIntermediateMutableArray&& other) noexcept :
    m_handle{ other.m_handle },
    m_elementAdded{ std::move(other.m_elementAdded) },
    m_elementRemoved{ std::move(other.m_elementRemoved) }
{
    other.m_handle = nullptr;
}

ArcGISIntermediateMutableArray::~ArcGISIntermediateMutableArray()
{
    if (m_handle)
    {
        if (m_elementAdded)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_Vector_setElementAddedCallback(reinterpret_cast<RT_VectorHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        if (m_elementRemoved)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_Vector_setElementRemovedCallback(reinterpret_cast<RT_VectorHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Vector_destroy(reinterpret_cast<RT_VectorHandle>(m_handle), &errorHandler);
    }
}

ArcGISIntermediateMutableArray& ArcGISIntermediateMutableArray::operator=(ArcGISIntermediateMutableArray&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
        swap(m_elementAdded, other.m_elementAdded);
        swap(m_elementRemoved, other.m_elementRemoved);
    }
    
    return *this;
}

ArcGISIntermediateMutableArray::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISIntermediateMutableArray::GetHandle() const
{
    return m_handle;
}
void ArcGISIntermediateMutableArray::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Standard
} // namespace Esri