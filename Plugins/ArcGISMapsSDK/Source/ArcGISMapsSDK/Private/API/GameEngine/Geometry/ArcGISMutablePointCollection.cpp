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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePointCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePointCollection.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISMutablePointCollection::ArcGISMutablePointCollection(const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_MutablePointCollection_createWithSpatialReference(localSpatialReference, &errorHandler));
}

bool ArcGISMutablePointCollection::GetIsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePointCollection_getIsEmpty(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePointCollection::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePointCollection_getSize(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISMutablePointCollection::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePointCollection_getSpatialReference(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISMutablePointCollection::AddPoint(double x, double y)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePointCollection_addPointXY(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), x, y, &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePointCollection::AddPoint(double x, double y, double z)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePointCollection_addPointXYZ(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), x, y, z, &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePointCollection::AddPoint(const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_MutablePointCollection_addPoint(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), localPoint, &errorHandler);
    
    return localResult;
}

void ArcGISMutablePointCollection::AddPoints(const ArcGISImmutablePointCollection& points)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoints = static_cast<const RT_ImmutablePointCollectionHandle>(points.GetHandle());
    
    RT_MutablePointCollection_addPointsFromImmutable(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), localPoints, &errorHandler);
}

void ArcGISMutablePointCollection::AddPoints(const ArcGISMutablePointCollection& points)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoints = static_cast<const RT_MutablePointCollectionHandle>(points.GetHandle());
    
    RT_MutablePointCollection_addPoints(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), localPoints, &errorHandler);
}

ArcGISPoint ArcGISMutablePointCollection::GetPoint(size_t index) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePointCollection_getPoint(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), index, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISMutablePointCollection::IndexOf(const ArcGISPoint& point) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_MutablePointCollection_indexOf(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), localPoint, &errorHandler);
    
    return localResult;
}

void ArcGISMutablePointCollection::InsertPoint(size_t pointIndex, double x, double y)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePointCollection_insertPointXY(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), pointIndex, x, y, &errorHandler);
}

void ArcGISMutablePointCollection::InsertPoint(size_t pointIndex, double x, double y, double z)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePointCollection_insertPointXYZ(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), pointIndex, x, y, z, &errorHandler);
}

void ArcGISMutablePointCollection::InsertPoint(size_t pointIndex, const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    RT_MutablePointCollection_insertPoint(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), pointIndex, localPoint, &errorHandler);
}

void ArcGISMutablePointCollection::RemoveAll()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePointCollection_removeAll(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), &errorHandler);
}

void ArcGISMutablePointCollection::RemovePoint(size_t pointIndex)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePointCollection_removePoint(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), pointIndex, &errorHandler);
}

void ArcGISMutablePointCollection::SetPoint(size_t pointIndex, const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    RT_MutablePointCollection_setPoint(reinterpret_cast<RT_MutablePointCollectionHandle>(GetHandle()), pointIndex, localPoint, &errorHandler);
}

ArcGISMutablePointCollection::ArcGISMutablePointCollection(void* handle) :
    m_handle{ handle }
{
}

ArcGISMutablePointCollection::ArcGISMutablePointCollection(ArcGISMutablePointCollection&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISMutablePointCollection::~ArcGISMutablePointCollection()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_MutablePointCollection_destroy(reinterpret_cast<RT_MutablePointCollectionHandle>(m_handle), &errorHandler);
    }
}

ArcGISMutablePointCollection& ArcGISMutablePointCollection::operator=(ArcGISMutablePointCollection&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISMutablePointCollection::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISMutablePointCollection::GetHandle() const
{
    return m_handle;
}
void ArcGISMutablePointCollection::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri