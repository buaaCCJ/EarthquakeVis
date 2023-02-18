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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSegment.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Segment.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPoint ArcGISSegment::GetEndPoint() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Segment_getEndPoint(reinterpret_cast<RT_SegmentHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISSegment::GetIsClosed() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Segment_getIsClosed(reinterpret_cast<RT_SegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISSegment::GetIsCurve() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Segment_getIsCurve(reinterpret_cast<RT_SegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISSegment::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Segment_getSpatialReference(reinterpret_cast<RT_SegmentHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISSegment::GetStartPoint() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Segment_getStartPoint(reinterpret_cast<RT_SegmentHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISSegment::Equals(const ArcGISSegment& right) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localRight = static_cast<const RT_SegmentHandle>(right.GetHandle());
    
    auto localResult = RT_Segment_equals(reinterpret_cast<RT_SegmentHandle>(GetHandle()), localRight, &errorHandler);
    
    return localResult;
}

ArcGISSegment::ArcGISSegment(void* handle) :
    m_handle{ handle }
{
}

ArcGISSegment::ArcGISSegment(ArcGISSegment&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISSegment::~ArcGISSegment()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Segment_destroy(reinterpret_cast<RT_SegmentHandle>(m_handle), &errorHandler);
    }
}

ArcGISSegment& ArcGISSegment::operator=(ArcGISSegment&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISSegment::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISSegment::GetHandle() const
{
    return m_handle;
}
void ArcGISSegment::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri