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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygon.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygonBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PolygonBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPolygonBuilder::ArcGISPolygonBuilder(const ArcGISPolygon& polygon) :
    ArcGISMultipartBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPolygon = static_cast<const RT_PolygonHandle>(polygon.GetHandle());
    
    SetHandle(RT_PolygonBuilder_createFromPolygon(localPolygon, &errorHandler));
}

ArcGISPolygonBuilder::ArcGISPolygonBuilder(const ArcGISSpatialReference& spatialReference) :
    ArcGISMultipartBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_PolygonBuilder_createFromSpatialReference(localSpatialReference, &errorHandler));
}

ArcGISPolyline ArcGISPolygonBuilder::ToPolyline() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_PolygonBuilder_toPolyline(reinterpret_cast<RT_PolygonBuilderHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPolyline{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPolyline{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPolygonBuilder::ArcGISPolygonBuilder(void* handle) :
    ArcGISMultipartBuilder{ handle }
{
}

ArcGISPolygonBuilder::ArcGISPolygonBuilder(ArcGISPolygonBuilder&& other) noexcept :
    ArcGISMultipartBuilder{ std::move(other) }
{
}

ArcGISPolygonBuilder::ArcGISPolygonBuilder() :
    ArcGISMultipartBuilder{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri