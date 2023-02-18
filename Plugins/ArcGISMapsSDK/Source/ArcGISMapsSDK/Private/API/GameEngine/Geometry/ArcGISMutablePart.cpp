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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISCubicBezierSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEllipticArcSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLineSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePart.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MutablePart.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Segment.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISMutablePart::ArcGISMutablePart(const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_MutablePart_createWithSpatialReference(localSpatialReference, &errorHandler));
}

ArcGISPoint ArcGISMutablePart::GetEndPoint() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getEndPoint(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISMutablePart::GetHasCurves() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getHasCurves(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISMutablePart::GetIsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getIsEmpty(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePart::GetPointCount() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getPointCount(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePart::GetSegmentCount() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getSegmentCount(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISMutablePart::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getSpatialReference(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISMutablePart::GetStartPoint() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getStartPoint(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISMutablePart::AddPoint(double x, double y)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_addPointXY(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), x, y, &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePart::AddPoint(double x, double y, double z)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_addPointXYZ(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), x, y, z, &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePart::AddPoint(const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_MutablePart_addPoint(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), localPoint, &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePart::AddSegment(const ArcGISSegment& segment)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSegment = static_cast<const RT_SegmentHandle>(segment.GetHandle());
    
    auto localResult = RT_MutablePart_addSegment(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), localSegment, &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePart::GetEndPointIndexFromSegmentIndex(size_t segmentIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getEndPointIndexFromSegmentIndex(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), segmentIndex, &errorHandler);
    
    return localResult;
}

ArcGISPoint ArcGISMutablePart::GetPoint(size_t pointIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getPoint(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISImmutablePointCollection ArcGISMutablePart::GetPoints() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getPoints(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISImmutablePointCollection{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISImmutablePointCollection{ localResult };
    }
    
    return localLocalResult;
}

ArcGISSegment ArcGISMutablePart::GetSegment(size_t segmentIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getSegment(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), segmentIndex, &errorHandler);
    
    auto localLocalResult = ArcGISSegment{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Segment_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_SegmentType_cubicBezierSegment:
                localLocalResult = ArcGISCubicBezierSegment{ localResult };
                break;
            case RT_SegmentType_ellipticArcSegment:
                localLocalResult = ArcGISEllipticArcSegment{ localResult };
                break;
            case RT_SegmentType_lineSegment:
                localLocalResult = ArcGISLineSegment{ localResult };
                break;
            default:
                localLocalResult = ArcGISSegment{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

size_t ArcGISMutablePart::GetSegmentIndexFromEndPointIndex(size_t pointIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getSegmentIndexFromEndPointIndex(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, &errorHandler);
    
    return localResult;
}

void ArcGISMutablePart::GetSegmentIndexFromPointIndex(size_t pointIndex, size_t* outStartPointSegmentIndex, size_t* outEndPointSegmentIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePart_getSegmentIndexFromPointIndex(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, outStartPointSegmentIndex, outEndPointSegmentIndex, &errorHandler);
}

size_t ArcGISMutablePart::GetSegmentIndexFromStartPointIndex(size_t pointIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getSegmentIndexFromStartPointIndex(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, &errorHandler);
    
    return localResult;
}

size_t ArcGISMutablePart::GetStartPointIndexFromSegmentIndex(size_t segmentIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MutablePart_getStartPointIndexFromSegmentIndex(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), segmentIndex, &errorHandler);
    
    return localResult;
}

void ArcGISMutablePart::InsertPoint(size_t pointIndex, double x, double y)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePart_insertPointXY(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, x, y, &errorHandler);
}

void ArcGISMutablePart::InsertPoint(size_t pointIndex, double x, double y, double z)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePart_insertPointXYZ(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, x, y, z, &errorHandler);
}

void ArcGISMutablePart::InsertPoint(size_t pointIndex, const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    RT_MutablePart_insertPoint(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, localPoint, &errorHandler);
}

void ArcGISMutablePart::InsertSegment(size_t segmentIndex, const ArcGISSegment& segment)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSegment = static_cast<const RT_SegmentHandle>(segment.GetHandle());
    
    RT_MutablePart_insertSegment(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), segmentIndex, localSegment, &errorHandler);
}

void ArcGISMutablePart::RemoveAll()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePart_removeAll(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), &errorHandler);
}

void ArcGISMutablePart::RemovePoint(size_t pointIndex)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePart_removePoint(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, &errorHandler);
}

void ArcGISMutablePart::RemoveSegment(size_t segmentIndex)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_MutablePart_removeSegment(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), segmentIndex, &errorHandler);
}

void ArcGISMutablePart::SetPoint(size_t pointIndex, const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    RT_MutablePart_setPoint(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), pointIndex, localPoint, &errorHandler);
}

void ArcGISMutablePart::SetSegment(size_t segmentIndex, const ArcGISSegment& segment)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSegment = static_cast<const RT_SegmentHandle>(segment.GetHandle());
    
    RT_MutablePart_setSegment(reinterpret_cast<RT_MutablePartHandle>(GetHandle()), segmentIndex, localSegment, &errorHandler);
}

ArcGISMutablePart::ArcGISMutablePart(void* handle) :
    m_handle{ handle }
{
}

ArcGISMutablePart::ArcGISMutablePart(ArcGISMutablePart&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISMutablePart::~ArcGISMutablePart()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_MutablePart_destroy(reinterpret_cast<RT_MutablePartHandle>(m_handle), &errorHandler);
    }
}

ArcGISMutablePart& ArcGISMutablePart::operator=(ArcGISMutablePart&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISMutablePart::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISMutablePart::GetHandle() const
{
    return m_handle;
}
void ArcGISMutablePart::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri