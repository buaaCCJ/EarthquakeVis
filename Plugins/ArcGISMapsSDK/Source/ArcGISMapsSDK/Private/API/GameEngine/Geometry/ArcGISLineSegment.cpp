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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLineSegment.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LineSegment.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISLineSegment::ArcGISLineSegment(double xStart, double yStart, double xEnd, double yEnd) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_LineSegment_createWithXY(xStart, yStart, xEnd, yEnd, &errorHandler));
}

ArcGISLineSegment::ArcGISLineSegment(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_LineSegment_createWithXYZ(xStart, yStart, zStart, xEnd, yEnd, zEnd, &errorHandler));
}

ArcGISLineSegment::ArcGISLineSegment(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd, const ArcGISSpatialReference& spatialReference) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_LineSegment_createWithXYZSpatialReference(xStart, yStart, zStart, xEnd, yEnd, zEnd, localSpatialReference, &errorHandler));
}

ArcGISLineSegment::ArcGISLineSegment(double xStart, double yStart, double xEnd, double yEnd, const ArcGISSpatialReference& spatialReference) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_LineSegment_createWithXYSpatialReference(xStart, yStart, xEnd, yEnd, localSpatialReference, &errorHandler));
}

ArcGISLineSegment::ArcGISLineSegment(const ArcGISPoint& startPoint, const ArcGISPoint& endPoint) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localStartPoint = static_cast<const RT_PointHandle>(startPoint.GetHandle());
    const auto localEndPoint = static_cast<const RT_PointHandle>(endPoint.GetHandle());
    
    SetHandle(RT_LineSegment_create(localStartPoint, localEndPoint, &errorHandler));
}

ArcGISLineSegment::ArcGISLineSegment(const ArcGISPoint& startPoint, const ArcGISPoint& endPoint, const ArcGISSpatialReference& spatialReference) :
    ArcGISSegment{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localStartPoint = static_cast<const RT_PointHandle>(startPoint.GetHandle());
    const auto localEndPoint = static_cast<const RT_PointHandle>(endPoint.GetHandle());
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_LineSegment_createWithSpatialReference(localStartPoint, localEndPoint, localSpatialReference, &errorHandler));
}

ArcGISLineSegment ArcGISLineSegment::CreateLineAtAngleFromStartPoint(const ArcGISPoint& startPoint, double angleRadians, double length)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localStartPoint = static_cast<const RT_PointHandle>(startPoint.GetHandle());
    
    auto localResult = RT_LineSegment_createLineAtAngleFromStartPoint(localStartPoint, angleRadians, length, &errorHandler);
    
    auto localLocalResult = ArcGISLineSegment{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISLineSegment{ localResult };
    }
    
    return localLocalResult;
}

ArcGISLineSegment::ArcGISLineSegment(void* handle) :
    ArcGISSegment{ handle }
{
}

ArcGISLineSegment::ArcGISLineSegment(ArcGISLineSegment&& other) noexcept :
    ArcGISSegment{ std::move(other) }
{
}

ArcGISLineSegment::ArcGISLineSegment() :
    ArcGISSegment{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri