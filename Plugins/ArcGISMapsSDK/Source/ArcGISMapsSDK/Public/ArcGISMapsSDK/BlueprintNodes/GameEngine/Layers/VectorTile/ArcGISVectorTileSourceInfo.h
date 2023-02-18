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

#include "ArcGISVectorTileSourceInfo.generated.h"

class UArcGISPoint;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
class ArcGISVectorTileSourceInfo;
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// This object represents the source metadata for a vector tile layer.
/// </summary>
/// <seealso cref="">ArcGISVectorTiledLayer.sourceInfo</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISVectorTileSourceInfo :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfo")
    /// <summary>
    /// The maximum scale.
    /// </summary>
    /// <remarks>
    /// Will return an undefined float if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetMaxScale();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfo")
    /// <summary>
    /// The minimum scale.
    /// </summary>
    /// <remarks>
    /// Will return an undefined float if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetMinScale();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfo")
    /// <summary>
    /// The source name.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfo")
    /// <summary>
    /// The origin of the source data.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetOrigin();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfo")
    /// <summary>
    /// The spatial reference of the source data.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfo")
    /// <summary>
    /// The vector tile source URI.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetURI();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfo")
    /// <summary>
    /// The source version.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetVersion();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo> APIObject;
};