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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayer.h"

#include "ArcGIS3DObjectSceneLayer.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
class ArcGIS3DObjectSceneLayer;
} // namespace Layers
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Public class that will contain a layer with a 3d objects inside.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGIS3DObjectSceneLayer :
    public UArcGISLayer
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGIS3DObjectSceneLayer")
    /// <summary>
    /// Creates a new layer.
    /// </summary>
    /// <remarks>
    /// Creates a new layer.
    /// </remarks>
    /// <param name="source">Layer source</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    static UArcGIS3DObjectSceneLayer* CreateArcGIS3DObjectSceneLayer(FString source, FString APIKey);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGIS3DObjectSceneLayer")
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
    static UArcGIS3DObjectSceneLayer* CreateArcGIS3DObjectSceneLayerWithProperties(FString source, FString name, float opacity, bool visible, FString APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGIS3DObjectSceneLayer")
    /// <summary>
    /// The user defined material reference to render the layer
    /// </summary>
    /// <remarks>
    /// This is required to be set before the layer is loaded or an error will occur.
    /// </remarks>
    /// <since>1.0.0</since>
    UMaterialInterface* GetMaterialReference();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGIS3DObjectSceneLayer")
    /// <summary>
    /// The user defined material reference to render the layer
    /// </summary>
    /// <remarks>
    /// This is required to be set before the layer is loaded or an error will occur.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetMaterialReference(UMaterialInterface* materialReference);
    #pragma endregion Properties
};