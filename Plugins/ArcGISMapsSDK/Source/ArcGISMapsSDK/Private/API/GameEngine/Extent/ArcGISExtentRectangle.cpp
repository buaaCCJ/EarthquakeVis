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
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentRectangle.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtentRectangle.h"

namespace Esri
{
namespace GameEngine
{
namespace Extent
{
ArcGISExtentRectangle::ArcGISExtentRectangle(const Geometry::ArcGISPoint& center, double width, double height) :
    ArcGISExtent{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    SetHandle(RT_GEExtentRectangle_create(localCenter, width, height, &errorHandler));
}

double ArcGISExtentRectangle::GetHeight() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEExtentRectangle_getHeight(reinterpret_cast<RT_GEExtentRectangleHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISExtentRectangle::GetWidth() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEExtentRectangle_getWidth(reinterpret_cast<RT_GEExtentRectangleHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISExtentRectangle::ArcGISExtentRectangle(void* handle) :
    ArcGISExtent{ handle }
{
}

ArcGISExtentRectangle::ArcGISExtentRectangle(ArcGISExtentRectangle&& other) noexcept :
    ArcGISExtent{ std::move(other) }
{
}

ArcGISExtentRectangle::ArcGISExtentRectangle() :
    ArcGISExtent{}
{
}
} // namespace Extent
} // namespace GameEngine
} // namespace Esri