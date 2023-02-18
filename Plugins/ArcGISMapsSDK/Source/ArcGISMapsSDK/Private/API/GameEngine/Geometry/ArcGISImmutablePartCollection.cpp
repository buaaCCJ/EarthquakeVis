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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePartCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePartCollection.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
bool ArcGISImmutablePartCollection::GetIsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePartCollection_getIsEmpty(reinterpret_cast<RT_ImmutablePartCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISImmutablePartCollection::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePartCollection_getSize(reinterpret_cast<RT_ImmutablePartCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISImmutablePartCollection::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePartCollection_getSpatialReference(reinterpret_cast<RT_ImmutablePartCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISImmutablePart ArcGISImmutablePartCollection::GetPart(size_t index) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePartCollection_getPart(reinterpret_cast<RT_ImmutablePartCollectionHandle>(GetHandle()), index, &errorHandler);
    
    auto localLocalResult = ArcGISImmutablePart{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISImmutablePart{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISImmutablePartCollection::IndexOf(const ArcGISImmutablePart& immutablePart) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localImmutablePart = static_cast<const RT_ImmutablePartHandle>(immutablePart.GetHandle());
    
    auto localResult = RT_ImmutablePartCollection_indexOf(reinterpret_cast<RT_ImmutablePartCollectionHandle>(GetHandle()), localImmutablePart, &errorHandler);
    
    return localResult;
}

ArcGISImmutablePartCollection::ArcGISImmutablePartCollection(void* handle) :
    m_handle{ handle }
{
}

ArcGISImmutablePartCollection::ArcGISImmutablePartCollection(ArcGISImmutablePartCollection&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISImmutablePartCollection::~ArcGISImmutablePartCollection()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_ImmutablePartCollection_destroy(reinterpret_cast<RT_ImmutablePartCollectionHandle>(m_handle), &errorHandler);
    }
}

ArcGISImmutablePartCollection& ArcGISImmutablePartCollection::operator=(ArcGISImmutablePartCollection&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISImmutablePartCollection::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISImmutablePartCollection::GetHandle() const
{
    return m_handle;
}
void ArcGISImmutablePartCollection::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri