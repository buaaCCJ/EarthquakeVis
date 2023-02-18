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
#include "ArcGISMapsSDK/API/Standard/ArcGISIntermediateDictionary.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISDictionary.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/Dictionary.h"

namespace Esri
{
namespace Standard
{
ArcGISIntermediateDictionary::ArcGISIntermediateDictionary(ArcGISElementType keyType, ArcGISElementType valueType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_Dictionary_create(static_cast<RT_ElementType>(keyType), static_cast<RT_ElementType>(valueType), &errorHandler));
}

ArcGISElementType ArcGISIntermediateDictionary::GetKeyType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Dictionary_getKeyType(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISElementType>(localResult);
}

size_t ArcGISIntermediateDictionary::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Dictionary_getSize(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISElementType ArcGISIntermediateDictionary::GetValueType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Dictionary_getValueType(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISElementType>(localResult);
}

ArcGISElement ArcGISIntermediateDictionary::At(const ArcGISElement& key) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localKey = static_cast<const RT_ElementHandle>(key.GetHandle());
    
    auto localResult = RT_Dictionary_at(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), localKey, &errorHandler);
    
    auto localLocalResult = ArcGISElement{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISElement{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISIntermediateDictionary::Contains(const ArcGISElement& key) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localKey = static_cast<const RT_ElementHandle>(key.GetHandle());
    
    auto localResult = RT_Dictionary_contains(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), localKey, &errorHandler);
    
    return localResult;
}

bool ArcGISIntermediateDictionary::Equals(const Unreal::ArcGISDictionary<ArcGISElement, ArcGISElement>& dictionary2) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localDictionary2 = static_cast<const RT_DictionaryHandle>(dictionary2.GetHandle());
    
    auto localResult = RT_Dictionary_equals(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), localDictionary2, &errorHandler);
    
    return localResult;
}

ArcGISElementType ArcGISIntermediateDictionary::GetTypeForKey(const ArcGISElement& key) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localKey = static_cast<const RT_ElementHandle>(key.GetHandle());
    
    auto localResult = RT_Dictionary_getTypeForKey(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), localKey, &errorHandler);
    
    return static_cast<ArcGISElementType>(localResult);
}

void ArcGISIntermediateDictionary::Insert(const ArcGISElement& key, const ArcGISElement& value)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localKey = static_cast<const RT_ElementHandle>(key.GetHandle());
    const auto localValue = static_cast<const RT_ElementHandle>(value.GetHandle());
    
    RT_Dictionary_insert(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), localKey, localValue, &errorHandler);
}

bool ArcGISIntermediateDictionary::IsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Dictionary_isEmpty(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

void ArcGISIntermediateDictionary::Remove(const ArcGISElement& key)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localKey = static_cast<const RT_ElementHandle>(key.GetHandle());
    
    RT_Dictionary_remove(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), localKey, &errorHandler);
}

void ArcGISIntermediateDictionary::RemoveAll()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_Dictionary_removeAll(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), &errorHandler);
}

void ArcGISIntermediateDictionary::Replace(const ArcGISElement& key, const ArcGISElement& newValue)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localKey = static_cast<const RT_ElementHandle>(key.GetHandle());
    const auto localNewValue = static_cast<const RT_ElementHandle>(newValue.GetHandle());
    
    RT_Dictionary_replace(reinterpret_cast<RT_DictionaryHandle>(GetHandle()), localKey, localNewValue, &errorHandler);
}

ArcGISIntermediateDictionary::ArcGISIntermediateDictionary(void* handle) :
    m_handle{ handle }
{
}

ArcGISIntermediateDictionary::ArcGISIntermediateDictionary(ArcGISIntermediateDictionary&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISIntermediateDictionary::~ArcGISIntermediateDictionary()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Dictionary_destroy(reinterpret_cast<RT_DictionaryHandle>(m_handle), &errorHandler);
    }
}

ArcGISIntermediateDictionary& ArcGISIntermediateDictionary::operator=(ArcGISIntermediateDictionary&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISIntermediateDictionary::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISIntermediateDictionary::GetHandle() const
{
    return m_handle;
}
void ArcGISIntermediateDictionary::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Standard
} // namespace Esri