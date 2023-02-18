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

#include "ArcGISVectorTileStyle.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
class ArcGISVectorTileStyle;
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// This object represents the style information for a vector tile layer.
/// </summary>
/// <seealso cref="">VectorTileSourceInfo.defaultStyle</seealso>
/// <seealso cref="">ArcGISVectorTiledLayer.style</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISVectorTileStyle :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileStyle")
    /// <summary>
    /// The vector tile source URI.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetSourceURI();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileStyle")
    /// <summary>
    /// The style version.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetVersion();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileStyle> APIObject;
};