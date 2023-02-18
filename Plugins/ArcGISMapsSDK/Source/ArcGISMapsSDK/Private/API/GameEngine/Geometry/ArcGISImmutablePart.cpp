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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePart.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLineSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ImmutablePart.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Segment.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPoint ArcGISImmutablePart::GetEndPoint() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getEndPoint(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISImmutablePart::GetHasCurves() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getHasCurves(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISImmutablePart::GetIsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getIsEmpty(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISImmutablePart::GetPointCount() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getPointCount(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISImmutablePart::GetSegmentCount() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getSegmentCount(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISImmutablePart::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getSpatialReference(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISImmutablePart::GetStartPoint() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getStartPoint(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

size_t ArcGISImmutablePart::GetEndPointIndexFromSegmentIndex(size_t segmentIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getEndPointIndexFromSegmentIndex(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), segmentIndex, &errorHandler);
    
    return localResult;
}

ArcGISPoint ArcGISImmutablePart::GetPoint(size_t pointIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getPoint(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), pointIndex, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISImmutablePointCollection ArcGISImmutablePart::GetPoints() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getPoints(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISImmutablePointCollection{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISImmutablePointCollection{ localResult };
    }
    
    return localLocalResult;
}

ArcGISSegment ArcGISImmutablePart::GetSegment(size_t segmentIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getSegment(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), segmentIndex, &errorHandler);
    
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

size_t ArcGISImmutablePart::GetSegmentIndexFromEndPointIndex(size_t pointIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getSegmentIndexFromEndPointIndex(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), pointIndex, &errorHandler);
    
    return localResult;
}

void ArcGISImmutablePart::GetSegmentIndexFromPointIndex(size_t pointIndex, size_t* outStartPointSegmentIndex, size_t* outEndPointSegmentIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ImmutablePart_getSegmentIndexFromPointIndex(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), pointIndex, outStartPointSegmentIndex, outEndPointSegmentIndex, &errorHandler);
}

size_t ArcGISImmutablePart::GetSegmentIndexFromStartPointIndex(size_t pointIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getSegmentIndexFromStartPointIndex(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), pointIndex, &errorHandler);
    
    return localResult;
}

size_t ArcGISImmutablePart::GetStartPointIndexFromSegmentIndex(size_t segmentIndex) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ImmutablePart_getStartPointIndexFromSegmentIndex(reinterpret_cast<RT_ImmutablePartHandle>(GetHandle()), segmentIndex, &errorHandler);
    
    return localResult;
}

ArcGISImmutablePart::ArcGISImmutablePart(void* handle) :
    m_handle{ handle }
{
}

ArcGISImmutablePart::ArcGISImmutablePart(ArcGISImmutablePart&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISImmutablePart::~ArcGISImmutablePart()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_ImmutablePart_destroy(reinterpret_cast<RT_ImmutablePartHandle>(m_handle), &errorHandler);
    }
}

ArcGISImmutablePart& ArcGISImmutablePart::operator=(ArcGISImmutablePart&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISImmutablePart::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISImmutablePart::GetHandle() const
{
    return m_handle;
}
void ArcGISImmutablePart::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri