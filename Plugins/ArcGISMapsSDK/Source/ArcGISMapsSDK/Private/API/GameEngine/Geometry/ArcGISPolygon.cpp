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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygon.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Polygon.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPolyline ArcGISPolygon::ToPolyline() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Polygon_toPolyline(reinterpret_cast<RT_PolygonHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPolyline{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPolyline{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPolygon::ArcGISPolygon(void* handle) :
    ArcGISMultipart{ handle }
{
}

ArcGISPolygon::ArcGISPolygon(ArcGISPolygon&& other) noexcept :
    ArcGISMultipart{ std::move(other) }
{
}

ArcGISPolygon::ArcGISPolygon() :
    ArcGISMultipart{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri