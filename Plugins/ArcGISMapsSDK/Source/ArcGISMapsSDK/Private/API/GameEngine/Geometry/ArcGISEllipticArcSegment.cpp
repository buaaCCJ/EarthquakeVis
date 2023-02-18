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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEllipticArcSegment.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EllipticArcSegment.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISEllipticArcSegment::ArcGISEllipticArcSegment(const ArcGISPoint& centerPoint, double rotationAngle, double semiMajorAxis, double minorMajorRatio, double startAngle, double centralAngle, const ArcGISSpatialReference& spatialReference) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenterPoint = static_cast<const RT_PointHandle>(centerPoint.GetHandle());
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_EllipticArcSegment_createWithCenter(localCenterPoint, rotationAngle, semiMajorAxis, minorMajorRatio, startAngle, centralAngle, localSpatialReference, &errorHandler));
}

ArcGISEllipticArcSegment::ArcGISEllipticArcSegment(const ArcGISPoint& startPoint, const ArcGISPoint& endPoint, double rotationAngle, bool isMinor, bool isCounterClockwise, double semiMajorAxis, double minorMajorRatio, const ArcGISSpatialReference& spatialReference) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localStartPoint = static_cast<const RT_PointHandle>(startPoint.GetHandle());
    const auto localEndPoint = static_cast<const RT_PointHandle>(endPoint.GetHandle());
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_EllipticArcSegment_createWithStartAndEndpoints(localStartPoint, localEndPoint, rotationAngle, isMinor, isCounterClockwise, semiMajorAxis, minorMajorRatio, localSpatialReference, &errorHandler));
}

ArcGISPoint ArcGISEllipticArcSegment::GetCenterPoint() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getCenterPoint(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISEllipticArcSegment::GetCentralAngle() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getCentralAngle(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEllipticArcSegment::GetEndAngle() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getEndAngle(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISEllipticArcSegment::GetIsCircular() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getIsCircular(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISEllipticArcSegment::GetIsCounterClockwise() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getIsCounterClockwise(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEllipticArcSegment::GetMinorMajorRatio() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getMinorMajorRatio(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEllipticArcSegment::GetRotationAngle() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getRotationAngle(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEllipticArcSegment::GetSemiMajorAxis() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getSemiMajorAxis(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEllipticArcSegment::GetSemiMinorAxis() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getSemiMinorAxis(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEllipticArcSegment::GetStartAngle() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EllipticArcSegment_getStartAngle(reinterpret_cast<RT_EllipticArcSegmentHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISEllipticArcSegment ArcGISEllipticArcSegment::CreateCircularEllipticArc(const ArcGISPoint& centerPoint, double radius, double startAngle, double centralAngle, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenterPoint = static_cast<const RT_PointHandle>(centerPoint.GetHandle());
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_EllipticArcSegment_createCircularEllipticArcWithCenterRadiusAndAngles(localCenterPoint, radius, startAngle, centralAngle, localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISEllipticArcSegment{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEllipticArcSegment{ localResult };
    }
    
    return localLocalResult;
}

ArcGISEllipticArcSegment ArcGISEllipticArcSegment::CreateCircularEllipticArc(const ArcGISPoint& startPoint, const ArcGISPoint& endPoint, const ArcGISPoint& interiorPoint, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localStartPoint = static_cast<const RT_PointHandle>(startPoint.GetHandle());
    const auto localEndPoint = static_cast<const RT_PointHandle>(endPoint.GetHandle());
    const auto localInteriorPoint = static_cast<const RT_PointHandle>(interiorPoint.GetHandle());
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_EllipticArcSegment_createCircularEllipticArcWithStartEndAndInterior(localStartPoint, localEndPoint, localInteriorPoint, localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISEllipticArcSegment{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEllipticArcSegment{ localResult };
    }
    
    return localLocalResult;
}

ArcGISEllipticArcSegment::ArcGISEllipticArcSegment(void* handle) :
    ArcGISSegment{ handle }
{
}

ArcGISEllipticArcSegment::ArcGISEllipticArcSegment(ArcGISEllipticArcSegment&& other) noexcept :
    ArcGISSegment{ std::move(other) }
{
}

ArcGISEllipticArcSegment::ArcGISEllipticArcSegment() :
    ArcGISSegment{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri