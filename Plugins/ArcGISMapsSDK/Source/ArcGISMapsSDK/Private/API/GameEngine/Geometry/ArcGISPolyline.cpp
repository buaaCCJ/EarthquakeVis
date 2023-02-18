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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Polyline.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPolyline::ArcGISPolyline(void* handle) :
    ArcGISMultipart{ handle }
{
}

ArcGISPolyline::ArcGISPolyline(ArcGISPolyline&& other) noexcept :
    ArcGISMultipart{ std::move(other) }
{
}

ArcGISPolyline::ArcGISPolyline() :
    ArcGISMultipart{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri