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
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnsupportedLayer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GEUnsupportedLayer.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
ArcGISUnsupportedLayer::ArcGISUnsupportedLayer(void* handle) :
    Base::ArcGISLayer{ handle }
{
}

ArcGISUnsupportedLayer::ArcGISUnsupportedLayer(ArcGISUnsupportedLayer&& other) noexcept :
    Base::ArcGISLayer{ std::move(other) }
{
}

ArcGISUnsupportedLayer::ArcGISUnsupportedLayer() :
    Base::ArcGISLayer{}
{
}
} // namespace Layers
} // namespace GameEngine
} // namespace Esri