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
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentCircle.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtentCircle.h"

namespace Esri
{
namespace GameEngine
{
namespace Extent
{
ArcGISExtentCircle::ArcGISExtentCircle(const Geometry::ArcGISPoint& center, double radius) :
    ArcGISExtent{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    SetHandle(RT_GEExtentCircle_create(localCenter, radius, &errorHandler));
}

double ArcGISExtentCircle::GetRadius() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEExtentCircle_getRadius(reinterpret_cast<RT_GEExtentCircleHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISExtentCircle::ArcGISExtentCircle(void* handle) :
    ArcGISExtent{ handle }
{
}

ArcGISExtentCircle::ArcGISExtentCircle(ArcGISExtentCircle&& other) noexcept :
    ArcGISExtent{ std::move(other) }
{
}

ArcGISExtentCircle::ArcGISExtentCircle() :
    ArcGISExtent{}
{
}
} // namespace Extent
} // namespace GameEngine
} // namespace Esri