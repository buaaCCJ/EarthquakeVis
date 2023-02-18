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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolylineBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PolylineBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPolylineBuilder::ArcGISPolylineBuilder(const ArcGISPolyline& polyline) :
    ArcGISMultipartBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPolyline = static_cast<const RT_PolylineHandle>(polyline.GetHandle());
    
    SetHandle(RT_PolylineBuilder_createFromPolyline(localPolyline, &errorHandler));
}

ArcGISPolylineBuilder::ArcGISPolylineBuilder(const ArcGISSpatialReference& spatialReference) :
    ArcGISMultipartBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_PolylineBuilder_createFromSpatialReference(localSpatialReference, &errorHandler));
}

ArcGISPolylineBuilder::ArcGISPolylineBuilder(void* handle) :
    ArcGISMultipartBuilder{ handle }
{
}

ArcGISPolylineBuilder::ArcGISPolylineBuilder(ArcGISPolylineBuilder&& other) noexcept :
    ArcGISMultipartBuilder{ std::move(other) }
{
}

ArcGISPolylineBuilder::ArcGISPolylineBuilder() :
    ArcGISMultipartBuilder{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri