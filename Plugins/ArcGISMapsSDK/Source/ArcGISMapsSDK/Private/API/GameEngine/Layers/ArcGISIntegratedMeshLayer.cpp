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
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISIntegratedMeshLayer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GEIntegratedMeshLayer.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
ArcGISIntegratedMeshLayer::ArcGISIntegratedMeshLayer(const FString& source, const FString& APIKey) :
    Base::ArcGISLayer{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEIntegratedMeshLayer_create(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

ArcGISIntegratedMeshLayer::ArcGISIntegratedMeshLayer(const FString& source, const FString& name, float opacity, bool visible, const FString& APIKey) :
    Base::ArcGISLayer{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEIntegratedMeshLayer_createWithProperties(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*name), opacity, visible, TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

ArcGISIntegratedMeshLayer::ArcGISIntegratedMeshLayer(void* handle) :
    Base::ArcGISLayer{ handle }
{
}

ArcGISIntegratedMeshLayer::ArcGISIntegratedMeshLayer(ArcGISIntegratedMeshLayer&& other) noexcept :
    Base::ArcGISLayer{ std::move(other) }
{
}

ArcGISIntegratedMeshLayer::ArcGISIntegratedMeshLayer() :
    Base::ArcGISLayer{}
{
}
} // namespace Layers
} // namespace GameEngine
} // namespace Esri