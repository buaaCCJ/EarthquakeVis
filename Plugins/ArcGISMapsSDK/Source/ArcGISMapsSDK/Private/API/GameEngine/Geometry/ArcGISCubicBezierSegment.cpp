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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISCubicBezierSegment.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/CubicBezierSegment.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISCubicBezierSegment::ArcGISCubicBezierSegment(const ArcGISPoint& startPoint, const ArcGISPoint& controlPoint1, const ArcGISPoint& controlPoint2, const ArcGISPoint& endPoint, const ArcGISSpatialReference& spatialReference) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localStartPoint = static_cast<const RT_PointHandle>(startPoint.GetHandle());
    const auto localControlPoint1 = static_cast<const RT_PointHandle>(controlPoint1.GetHandle());
    const auto localControlPoint2 = static_cast<const RT_PointHandle>(controlPoint2.GetHandle());
    const auto localEndPoint = static_cast<const RT_PointHandle>(endPoint.GetHandle());
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_CubicBezierSegment_create(localStartPoint, localControlPoint1, localControlPoint2, localEndPoint, localSpatialReference, &errorHandler));
}

ArcGISPoint ArcGISCubicBezierSegment::GetControlPoint1() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_CubicBezierSegment_getControlPoint1(reinterpret_cast<RT_CubicBezierSegmentHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISCubicBezierSegment::GetControlPoint2() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_CubicBezierSegment_getControlPoint2(reinterpret_cast<RT_CubicBezierSegmentHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISCubicBezierSegment::ArcGISCubicBezierSegment(void* handle) :
    ArcGISSegment{ handle }
{
}

ArcGISCubicBezierSegment::ArcGISCubicBezierSegment(ArcGISCubicBezierSegment&& other) noexcept :
    ArcGISSegment{ std::move(other) }
{
}

ArcGISCubicBezierSegment::ArcGISCubicBezierSegment() :
    ArcGISSegment{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri