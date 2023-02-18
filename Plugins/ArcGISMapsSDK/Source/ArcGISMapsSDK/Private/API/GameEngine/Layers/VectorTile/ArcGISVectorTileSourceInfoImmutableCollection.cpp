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
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfo.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfoImmutableCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableCollection.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileSourceInfoImmutableCollection.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
size_t ArcGISVectorTileSourceInfoImmutableCollection::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_getSize(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISVectorTileSourceInfo ArcGISVectorTileSourceInfoImmutableCollection::At(size_t position) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_at(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(GetHandle()), position, &errorHandler);
    
    auto localLocalResult = ArcGISVectorTileSourceInfo{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISVectorTileSourceInfo{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISVectorTileSourceInfoImmutableCollection::Contains(const ArcGISVectorTileSourceInfo& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_VectorTileSourceInfoHandle>(value.GetHandle());
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_contains(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

bool ArcGISVectorTileSourceInfoImmutableCollection::Equals(const Unreal::ArcGISImmutableCollection<ArcGISVectorTileSourceInfo>& vector2) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localVector2 = static_cast<const RT_VectorTileSourceInfoImmutableCollectionHandle>(vector2.GetHandle());
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_equals(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(GetHandle()), localVector2, &errorHandler);
    
    return localResult;
}

ArcGISVectorTileSourceInfo ArcGISVectorTileSourceInfoImmutableCollection::First() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_first(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISVectorTileSourceInfo{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISVectorTileSourceInfo{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISVectorTileSourceInfoImmutableCollection::IndexOf(ArcGISVectorTileSourceInfo& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localValue = static_cast<RT_VectorTileSourceInfoHandle>(value.GetHandle());
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_indexOf(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

bool ArcGISVectorTileSourceInfoImmutableCollection::IsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_isEmpty(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISVectorTileSourceInfo ArcGISVectorTileSourceInfoImmutableCollection::Last() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_last(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISVectorTileSourceInfo{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISVectorTileSourceInfo{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISVectorTileSourceInfoImmutableCollection::Npos()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfoImmutableCollection_npos(&errorHandler);
    
    return localResult;
}

ArcGISVectorTileSourceInfoImmutableCollection::ArcGISVectorTileSourceInfoImmutableCollection(void* handle) :
    m_handle{ handle }
{
}

ArcGISVectorTileSourceInfoImmutableCollection::ArcGISVectorTileSourceInfoImmutableCollection(ArcGISVectorTileSourceInfoImmutableCollection&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISVectorTileSourceInfoImmutableCollection::~ArcGISVectorTileSourceInfoImmutableCollection()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_VectorTileSourceInfoImmutableCollection_destroy(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(m_handle), &errorHandler);
    }
}

ArcGISVectorTileSourceInfoImmutableCollection& ArcGISVectorTileSourceInfoImmutableCollection::operator=(ArcGISVectorTileSourceInfoImmutableCollection&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISVectorTileSourceInfoImmutableCollection::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISVectorTileSourceInfoImmutableCollection::GetHandle() const
{
    return m_handle;
}
void ArcGISVectorTileSourceInfoImmutableCollection::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine
} // namespace Esri