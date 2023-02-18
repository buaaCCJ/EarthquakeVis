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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePartCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePartCollection.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISMutablePartCollection::ArcGISMutablePartCollection(const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_MutablePartCollection_createWithSpatialReference(localSpatialReference, &errorHandler));
}

bool ArcGISMutablePartCollection::GetIsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePartCollection_getIsEmpty(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePartCollection::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePartCollection_getSize(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISMutablePartCollection::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePartCollection_getSpatialReference(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISMutablePartCollection::AddPart(const ArcGISMutablePart& mutablePart)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localMutablePart = static_cast<const RT_MutablePartHandle>(mutablePart.GetHandle());
    
    auto localResult = RT_MutablePartCollection_addPart(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), localMutablePart, &errorHandler);
    
    return localResult;
}

ArcGISMutablePart ArcGISMutablePartCollection::GetPart(size_t index) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePartCollection_getPart(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), index, &errorHandler);
    
    auto localLocalResult = ArcGISMutablePart{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISMutablePart{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISMutablePartCollection::IndexOf(const ArcGISMutablePart& mutablePart) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localMutablePart = static_cast<const RT_MutablePartHandle>(mutablePart.GetHandle());
    
    auto localResult = RT_MutablePartCollection_indexOf(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), localMutablePart, &errorHandler);
    
    return localResult;
}

void ArcGISMutablePartCollection::InsertPart(size_t index, const ArcGISMutablePart& mutablePart)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localMutablePart = static_cast<const RT_MutablePartHandle>(mutablePart.GetHandle());
    
    RT_MutablePartCollection_insertPart(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), index, localMutablePart, &errorHandler);
}

void ArcGISMutablePartCollection::RemoveAll()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePartCollection_removeAll(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), &errorHandler);
}

void ArcGISMutablePartCollection::RemovePart(size_t index)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePartCollection_removePart(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), index, &errorHandler);
}

void ArcGISMutablePartCollection::SetPart(size_t index, const ArcGISMutablePart& mutablePart)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localMutablePart = static_cast<const RT_MutablePartHandle>(mutablePart.GetHandle());
    
    RT_MutablePartCollection_setPart(reinterpret_cast<RT_MutablePartCollectionHandle>(GetHandle()), index, localMutablePart, &errorHandler);
}

ArcGISMutablePartCollection::ArcGISMutablePartCollection(void* handle) :
    m_handle{ handle }
{
}

ArcGISMutablePartCollection::ArcGISMutablePartCollection(ArcGISMutablePartCollection&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISMutablePartCollection::~ArcGISMutablePartCollection()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_MutablePartCollection_destroy(reinterpret_cast<RT_MutablePartCollectionHandle>(m_handle), &errorHandler);
    }
}

ArcGISMutablePartCollection& ArcGISMutablePartCollection::operator=(ArcGISMutablePartCollection&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISMutablePartCollection::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISMutablePartCollection::GetHandle() const
{
    return m_handle;
}
void ArcGISMutablePartCollection::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri