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
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttributeProcessor.h"
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISVisualizationAttributeDescription.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGIS3DObjectSceneLayer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/GE3DObjectSceneLayer.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
ArcGIS3DObjectSceneLayer::ArcGIS3DObjectSceneLayer(const FString& source, const FString& APIKey) :
    Base::ArcGISLayer{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GE3DObjectSceneLayer_create(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

ArcGIS3DObjectSceneLayer::ArcGIS3DObjectSceneLayer(const FString& source, const FString& name, float opacity, bool visible, const FString& APIKey) :
    Base::ArcGISLayer{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GE3DObjectSceneLayer_createWithProperties(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*name), opacity, visible, TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

UMaterialInterface* ArcGIS3DObjectSceneLayer::GetMaterialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GE3DObjectSceneLayer_getMaterialReference(reinterpret_cast<RT_GE3DObjectSceneLayerHandle>(GetHandle()), &errorHandler);
    
    UMaterialInterface* localLocalResult = nullptr;
    
    if (localResult != nullptr)
    {
        localLocalResult = static_cast<UMaterialInterface*>(reinterpret_cast<FWeakObjectPtr*>(localResult)->Get());
    }
    
    return localLocalResult;
}
void ArcGIS3DObjectSceneLayer::SetMaterialReference(UMaterialInterface* materialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localMaterialReference = new FWeakObjectPtr(materialReference);
    
    RT_GE3DObjectSceneLayer_setMaterialReference(reinterpret_cast<RT_GE3DObjectSceneLayerHandle>(GetHandle()), localMaterialReference, &errorHandler);
}

void ArcGIS3DObjectSceneLayer::SetAttributesToVisualize(const Unreal::ArcGISImmutableArray<FString>& layerAttributes)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLayerAttributes = static_cast<const RT_ArrayHandle>(layerAttributes.GetHandle());
    
    RT_GE3DObjectSceneLayer_setAttributesToVisualize(reinterpret_cast<RT_GE3DObjectSceneLayerHandle>(GetHandle()), localLayerAttributes, &errorHandler);
}

void ArcGIS3DObjectSceneLayer::SetAttributesToVisualize(const Unreal::ArcGISImmutableArray<FString>& layerAttributes, const Unreal::ArcGISImmutableArray<Attributes::ArcGISVisualizationAttributeDescription>& visualizationAttributeDescriptions, const Attributes::ArcGISAttributeProcessor& attributeProcessor)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLayerAttributes = static_cast<const RT_ArrayHandle>(layerAttributes.GetHandle());
    const auto localVisualizationAttributeDescriptions = static_cast<const RT_ArrayHandle>(visualizationAttributeDescriptions.GetHandle());
    const auto localAttributeProcessor = static_cast<const RT_AttributeProcessorHandle>(attributeProcessor.GetHandle());
    
    RT_GE3DObjectSceneLayer_setAttributesToVisualizeAndTransform(reinterpret_cast<RT_GE3DObjectSceneLayerHandle>(GetHandle()), localLayerAttributes, localVisualizationAttributeDescriptions, localAttributeProcessor, &errorHandler);
}

ArcGIS3DObjectSceneLayer::ArcGIS3DObjectSceneLayer(void* handle) :
    Base::ArcGISLayer{ handle }
{
}

ArcGIS3DObjectSceneLayer::ArcGIS3DObjectSceneLayer(ArcGIS3DObjectSceneLayer&& other) noexcept :
    Base::ArcGISLayer{ std::move(other) }
{
}

ArcGIS3DObjectSceneLayer::ArcGIS3DObjectSceneLayer() :
    Base::ArcGISLayer{}
{
}
} // namespace Layers
} // namespace GameEngine
} // namespace Esri