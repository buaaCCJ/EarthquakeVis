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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePointCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePointCollection.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
bool ArcGISImmutablePointCollection::GetIsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePointCollection_getIsEmpty(reinterpret_cast<RT_ImmutablePointCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISImmutablePointCollection::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePointCollection_getSize(reinterpret_cast<RT_ImmutablePointCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISImmutablePointCollection::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePointCollection_getSpatialReference(reinterpret_cast<RT_ImmutablePointCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISImmutablePointCollection::GetPoint(size_t index) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePointCollection_getPoint(reinterpret_cast<RT_ImmutablePointCollectionHandle>(GetHandle()), index, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISImmutablePointCollection::IndexOf(const ArcGISPoint& point) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_ImmutablePointCollection_indexOf(reinterpret_cast<RT_ImmutablePointCollectionHandle>(GetHandle()), localPoint, &errorHandler);
    
    return localResult;
}

ArcGISImmutablePointCollection::ArcGISImmutablePointCollection(void* handle) :
    m_handle{ handle }
{
}

ArcGISImmutablePointCollection::ArcGISImmutablePointCollection(ArcGISImmutablePointCollection&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISImmutablePointCollection::~ArcGISImmutablePointCollection()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_ImmutablePointCollection_destroy(reinterpret_cast<RT_ImmutablePointCollectionHandle>(m_handle), &errorHandler);
    }
}

ArcGISImmutablePointCollection& ArcGISImmutablePointCollection::operator=(ArcGISImmutablePointCollection&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISImmutablePointCollection::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISImmutablePointCollection::GetHandle() const
{
    return m_handle;
}
void ArcGISImmutablePointCollection::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri