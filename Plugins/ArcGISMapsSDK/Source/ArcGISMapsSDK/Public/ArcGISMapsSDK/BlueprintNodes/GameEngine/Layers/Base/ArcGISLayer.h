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

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerType.h"

#include "ArcGISLayer.generated.h"

class UArcGISLoadable;
class UArcGISExtentRectangle;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace Base
{
class ArcGISLayer;
} // namespace Base
} // namespace Layers
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Abstract class layer, base for layers
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISLayer :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// Creates a new layer.
    /// </summary>
    /// <remarks>
    /// Creates a new layer.
    /// </remarks>
    /// <param name="source">Layer source</param>
    /// <param name="type">Layer type definition.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    static UArcGISLayer* CreateArcGISLayer(FString source, EArcGISLayerType::Type type, FString APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// API Key will be sended on loading process to match the new credit system.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAPIKey();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// The full extent of this layer, which is the extent where all layer data is contained.
    /// </summary>
    /// <remarks>
    /// You can use this to zoom
    /// to all of the data contained in this layer.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISExtentRectangle* GetExtent();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// Layer visible true or false
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsVisible();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// Layer visible true or false
    /// </summary>
    /// <since>1.0.0</since>
    void SetIsVisible(bool isVisible);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// This property will help the user to identify the layer on his application.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// This property will help the user to identify the layer on his application.
    /// </summary>
    /// <since>1.0.0</since>
    void SetName(FString name);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// Layer Opacity
    /// </summary>
    /// <since>1.0.0</since>
    float GetOpacity();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// Layer Opacity
    /// </summary>
    /// <since>1.0.0</since>
    void SetOpacity(float opacity);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// Source property will be a read only, it will be setup on the constructor
    /// </summary>
    /// <since>1.0.0</since>
    FString GetSource();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayer")
    /// <summary>
    /// The spatial reference of the layer.
    /// </summary>
    /// <remarks>
    /// <see cref="Esri::GameEngine::Layers::ArcGISImageLayer">ArcGISImageLayer</see> <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> must match the <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> of the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>.
    /// <see cref="Esri::GameEngine::Layers::ArcGISImageLayer">ArcGISImageLayer</see> tiling scheme must be compatible with the tiling scheme of the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>.
    /// If any of the above constraints are violated, a <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState">ArcGISLayerViewState</see> error is generated.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Layers::Base::ArcGISLayer> APIObject;
};