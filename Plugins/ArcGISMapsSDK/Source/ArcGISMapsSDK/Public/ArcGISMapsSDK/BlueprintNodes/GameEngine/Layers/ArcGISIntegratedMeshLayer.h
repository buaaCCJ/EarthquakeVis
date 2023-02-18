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

#include "ArcGISIntegratedMeshLayer.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
class ArcGISIntegratedMeshLayer;
} // namespace Layers
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Public class that will contain a layer with a integrated mesh inside.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISIntegratedMeshLayer :
    public UArcGISLayer
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISIntegratedMeshLayer")
    /// <summary>
    /// Creates a new layer.
    /// </summary>
    /// <remarks>
    /// Creates a new layer.
    /// </remarks>
    /// <param name="source">Layer source</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    static UArcGISIntegratedMeshLayer* CreateArcGISIntegratedMeshLayer(FString source, FString APIKey);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISIntegratedMeshLayer")
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
    static UArcGISIntegratedMeshLayer* CreateArcGISIntegratedMeshLayerWithProperties(FString source, FString name, float opacity, bool visible, FString APIKey);
    #pragma endregion Constructors
};