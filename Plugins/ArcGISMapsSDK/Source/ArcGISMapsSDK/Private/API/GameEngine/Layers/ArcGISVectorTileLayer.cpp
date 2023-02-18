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
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISVectorTileLayer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfo.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileStyle.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableCollection.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GEVectorTileLayer.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
ArcGISVectorTileLayer::ArcGISVectorTileLayer(const FString& source, const FString& APIKey) :
    Base::ArcGISLayer{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEVectorTileLayer_create(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

ArcGISVectorTileLayer::ArcGISVectorTileLayer(const FString& source, const FString& name, float opacity, bool visible, const FString& APIKey) :
    Base::ArcGISLayer{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEVectorTileLayer_createWithProperties(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*name), opacity, visible, TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

Unreal::ArcGISImmutableCollection<VectorTile::ArcGISVectorTileSourceInfo> ArcGISVectorTileLayer::GetSourceInfos() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEVectorTileLayer_getSourceInfos(reinterpret_cast<RT_GEVectorTileLayerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISImmutableCollection<VectorTile::ArcGISVectorTileSourceInfo>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISImmutableCollection<VectorTile::ArcGISVectorTileSourceInfo>{ localResult };
    }
    
    return localLocalResult;
}

VectorTile::ArcGISVectorTileStyle ArcGISVectorTileLayer::GetStyle() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEVectorTileLayer_getStyle(reinterpret_cast<RT_GEVectorTileLayerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = VectorTile::ArcGISVectorTileStyle{};
    
    if (localResult != nullptr)
    {
        localLocalResult = VectorTile::ArcGISVectorTileStyle{ localResult };
    }
    
    return localLocalResult;
}

ArcGISVectorTileLayer::ArcGISVectorTileLayer(void* handle) :
    Base::ArcGISLayer{ handle }
{
}

ArcGISVectorTileLayer::ArcGISVectorTileLayer(ArcGISVectorTileLayer&& other) noexcept :
    Base::ArcGISLayer{ std::move(other) }
{
}

ArcGISVectorTileLayer::ArcGISVectorTileLayer() :
    Base::ArcGISLayer{}
{
}
} // namespace Layers
} // namespace GameEngine
} // namespace Esri