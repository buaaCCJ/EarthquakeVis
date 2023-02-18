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
#pragma once

#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"

namespace Esri
{
namespace Unreal
{
template<typename T> class ArcGISImmutableArray;
} // namespace Unreal

namespace GameEngine
{
namespace Attributes
{
class ArcGISAttributeProcessor;
class ArcGISVisualizationAttributeDescription;
} // namespace Attributes

namespace Layers
{
/// <summary>
/// Public class that will contain a layer with a 3d objects inside.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGIS3DObjectSceneLayer :
    public Base::ArcGISLayer
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a new layer.
    /// </summary>
    /// <remarks>
    /// Creates a new layer.
    /// </remarks>
    /// <param name="source">Layer source</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGIS3DObjectSceneLayer(const FString& source, const FString& APIKey);
    
    /// <summary>
    /// Creates a new layer.
    /// </summary>
    /// <remarks>
    /// Creates a new layer.
    /// </remarks>
    /// <param name="source">Layer source.</param>
    /// <param name="name">Layer name</param>
    /// <param name="opacity">Layer opacity.</param>
    /// <param name="visible">Layer visible or not.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGIS3DObjectSceneLayer(const FString& source, const FString& name, float opacity, bool visible, const FString& APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The user defined material reference to render the layer
    /// </summary>
    /// <remarks>
    /// This is required to be set before the layer is loaded or an error will occur.
    /// </remarks>
    /// <since>1.0.0</since>
    UMaterialInterface* GetMaterialReference() const;
    void SetMaterialReference(UMaterialInterface* materialReference);
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// A <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> of the strings that are used for retrieving the specified attributes for visualization
    /// </summary>
    /// <remarks>
    /// Before loading the layer ensure that <see cref="Esri::GameEngine::Layers::ArcGIS3DObjectSceneLayer.setAttributesToVisualize">ArcGIS3DObjectSceneLayer.setAttributesToVisualize</see> is set. 
    /// 
    /// To select all attributes use `*`. 
    /// 
    /// Attribute names should be passed in as string values, not as attribute keys. Empty strings will be ignored,
    /// and attribute strings that don't match exactly or don't exist will be considered invalid. Invalid attribute
    /// strings will result in <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState">ArcGISLayerViewState</see> warnings. Duplicate and extraneous strings will be removed,
    /// although the order in which removal occurs is undefined. Feature IDs will always be requested.
    /// 
    /// At present, the only supported attribute types are int and float. 
    /// 
    /// Calling this function after the layer has loaded will result in an error.
    /// </remarks>
    /// <param name="layerAttributes">The attribute names to pass through for visualization.</param>
    /// <since>1.0.0</since>
    void SetAttributesToVisualize(const Unreal::ArcGISImmutableArray<FString>& layerAttributes);
    
    /// <summary>
    /// A <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> of the strings that are used for retrieving the specified attributes from the layer,
    /// the corresponding <see cref="Esri::GameEngine::Attributes::ArcGISVisualizationAttributeDescription">ArcGISVisualizationAttributeDescription</see> to describe the attributes to be visualized and the
    /// <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessor">ArcGISAttributeProcessor</see> definition.
    /// </summary>
    /// <remarks>
    /// Before loading the layer ensure that <see cref="Esri::GameEngine::Layers::ArcGIS3DObjectSceneLayer.setAttributesToVisualize">ArcGIS3DObjectSceneLayer.setAttributesToVisualize</see> is set. 
    /// 
    /// To select all attributes use `*`. 
    /// 
    /// Attribute names should be passed in as string values, not as attribute keys. Empty strings will be ignored,
    /// and attribute strings that don't match exactly or don't exist will be considered invalid. Invalid attribute
    /// strings will result in <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState">ArcGISLayerViewState</see> warnings. Duplicate and extraneous strings will be removed,
    /// although the order in which removal occurs is undefined. Feature IDs will always be requested.
    /// 
    /// The order of the input attributes provided to the <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessor">ArcGISAttributeProcessor</see> will match the order of
    /// valid, non-empty <see cref="Esri::GameEngine::Attributes::ArcGISVisualizationAttributeDescription">ArcGISVisualizationAttributeDescription</see> provided as the first argument to this function. 
    /// 
    /// At present, the only supported attribute types are int and float. 
    /// 
    /// Calling this function after the layer has loaded will result in an error.
    /// </remarks>
    /// <param name="layerAttributes">The attribute names requested and provided to the <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessorEvent">ArcGISAttributeProcessorEvent</see> as input.</param>
    /// <param name="visualizationAttributeDescriptions">The visualization attribute descriptions to use for visualization.</param>
    /// <param name="attributeProcessor">The <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessor">ArcGISAttributeProcessor</see> defines an event which is invoked when the requested layer attributes are available to be processed.</param>
    /// <since>1.0.0</since>
    void SetAttributesToVisualize(const Unreal::ArcGISImmutableArray<FString>& layerAttributes, const Unreal::ArcGISImmutableArray<Attributes::ArcGISVisualizationAttributeDescription>& visualizationAttributeDescriptions, const Attributes::ArcGISAttributeProcessor& attributeProcessor);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGIS3DObjectSceneLayer(void* handle);
    ArcGIS3DObjectSceneLayer(const ArcGIS3DObjectSceneLayer&) = delete;
    ArcGIS3DObjectSceneLayer(ArcGIS3DObjectSceneLayer&& other) noexcept;
    ArcGIS3DObjectSceneLayer();
    virtual ~ArcGIS3DObjectSceneLayer() = default;
    
    ArcGIS3DObjectSceneLayer& operator=(const ArcGIS3DObjectSceneLayer&) = delete;
    ArcGIS3DObjectSceneLayer& operator=(ArcGIS3DObjectSceneLayer&& other) = default;
    #pragma endregion Special Members
};
} // namespace Layers
} // namespace GameEngine
} // namespace Esri