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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMapType.h"

#include "ArcGISMap.generated.h"

class UArcGISLoadable;
class UArcGISBasemap;
class UArcGISExtent;
class UArcGISMapElevation;
class UArcGISLayerCollection;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Map
{
class ArcGISMap;
} // namespace Map
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The map contains layers and additional properties and can be displayed in a ArcGISRenderComponent.
/// </summary>
/// <remarks>
/// The map represent the document with all data that will be renderer by ArcGISRenderComponent.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMap :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Create a new Map document.
    /// </summary>
    /// <remarks>
    /// Creates map view for displaying a map. We only be able to have one map by scene, it will be automatically rendered on the ArcGISRenderComponent.
    /// </remarks>
    /// <param name="basemap">Specifies the basemap</param>
    /// <param name="mapType">Specifies the map type.</param>
    /// <since>1.0.0</since>
    static UArcGISMap* CreateArcGISMapWithBasemapAndMapType(UArcGISBasemap* basemap, EArcGISMapType::Type mapType);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Create a new Map document.
    /// </summary>
    /// <remarks>
    /// Creates map view for displaying a map. We only be able to have one map by scene, it will be automatically rendered on the ArcGISRenderComponent.
    /// </remarks>
    /// <param name="mapType">Specifies the map type.</param>
    /// <since>1.0.0</since>
    static UArcGISMap* CreateArcGISMapWithMapType(EArcGISMapType::Type mapType);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Creates a map with spatial reference and map type.
    /// </summary>
    /// <param name="spatialReference">A spatial reference object.</param>
    /// <param name="mapType">Specifies the map type.</param>
    /// <since>1.0.0</since>
    static UArcGISMap* CreateArcGISMapWithSpatialReferenceAndMapType(UArcGISSpatialReference* spatialReference, EArcGISMapType::Type mapType);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Definition for basemap.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISBasemap* GetBasemap();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Definition for basemap.
    /// </summary>
    /// <since>1.0.0</since>
    void SetBasemap(UArcGISBasemap* basemap);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Definition of map's clipping area. This property will be applied in Local mode only.
    /// </summary>
    /// <remarks>
    /// Setting a non-null clipping area in Global mode will result in an error.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISExtent* GetClippingArea();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Definition of map's clipping area. This property will be applied in Local mode only.
    /// </summary>
    /// <remarks>
    /// Setting a non-null clipping area in Global mode will result in an error.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetClippingArea(UArcGISExtent* clippingArea);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Definition of map elevation.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISMapElevation* GetElevation();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Definition of map elevation.
    /// </summary>
    /// <since>1.0.0</since>
    void SetElevation(UArcGISMapElevation* elevation);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// List of <see cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</see> included on the map
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISLayerCollection* GetLayers();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// List of <see cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</see> included on the map
    /// </summary>
    /// <since>1.0.0</since>
    void SetLayers(UArcGISLayerCollection* layers);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// Definition for the map, if it's local or global.
    /// </summary>
    /// <since>1.0.0</since>
    EArcGISMapType::Type GetMapType();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMap")
    /// <summary>
    /// The spatial reference for the map.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Map::ArcGISMap> APIObject;
};