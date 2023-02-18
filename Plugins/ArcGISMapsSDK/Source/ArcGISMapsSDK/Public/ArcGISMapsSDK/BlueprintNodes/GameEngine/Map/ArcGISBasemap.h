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
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISBasemapStyle.h"

#include "ArcGISBasemap.generated.h"

class UArcGISLoadable;
class UArcGISLayerCollection;

namespace Esri
{
namespace GameEngine
{
namespace Map
{
class ArcGISBasemap;
} // namespace Map
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Public class that will contain a basemap.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISBasemap :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// Creates an empty ArcGISBasemap. Basemap is created in a loaded state.
    /// </summary>
    /// <since>1.0.0</since>
    static UArcGISBasemap* CreateArcGISBasemap();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// Creates a basemap with a style.
    /// </summary>
    /// <param name="basemapStyle">The basemap style.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <seealso cref="Esri::GameEngine::Map::ArcGISBasemapStyle">ArcGISBasemapStyle</seealso>
    /// <since>1.0.0</since>
    static UArcGISBasemap* CreateArcGISBasemapWithBasemapStyle(EArcGISBasemapStyle::Type basemapStyle, FString APIKey);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// Creates a ArcGISBasemap from a URI and ArcGISLayerType
    /// </summary>
    /// <param name="source">ArcGISLayer source</param>
    /// <param name="type">Layer type definition.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    static UArcGISBasemap* CreateArcGISBasemapWithLayerSourceAndType(FString source, EArcGISLayerType::Type type, FString APIKey);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// Creates a ArcGISBasemap from a basemap URI
    /// </summary>
    /// <param name="source">ArcGISBasemap source</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    static UArcGISBasemap* CreateArcGISBasemapWithBasemapSource(FString source, FString APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// API Key will be sended on loading process to match the new credit system.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAPIKey();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// The base layers.
    /// </summary>
    /// <remarks>
    /// The collection is specific to a basemap so you can't reuse an GELayerCollection coming from another <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see> or <see cref="Esri::GameEngine::Map::ArcGISBasemap">ArcGISBasemap</see>.
    /// You have to create a new layer collection by using <see cref="Esri::GameEngine::Layers::Base::ArcGISLayerCollection">ArcGISLayerCollection</see>.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</seealso>
    /// <seealso cref="Esri::GameEngine::Layers::Base::ArcGISLayerCollection">ArcGISLayerCollection</seealso>
    /// <warning>
    /// <see cref="Esri::Standard::ArcGISErrorType.mappingUnsupportedLayerType">ArcGISErrorType.mappingUnsupportedLayerType</see> thrown if <see cref="">GroupLayer</see> added to the base layer collection after retrieval.
    /// </warning>
    /// <since>1.0.0</since>
    UArcGISLayerCollection* GetBaseLayers();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// The base layers.
    /// </summary>
    /// <remarks>
    /// The collection is specific to a basemap so you can't reuse an GELayerCollection coming from another <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see> or <see cref="Esri::GameEngine::Map::ArcGISBasemap">ArcGISBasemap</see>.
    /// You have to create a new layer collection by using <see cref="Esri::GameEngine::Layers::Base::ArcGISLayerCollection">ArcGISLayerCollection</see>.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</seealso>
    /// <seealso cref="Esri::GameEngine::Layers::Base::ArcGISLayerCollection">ArcGISLayerCollection</seealso>
    /// <warning>
    /// <see cref="Esri::Standard::ArcGISErrorType.mappingUnsupportedLayerType">ArcGISErrorType.mappingUnsupportedLayerType</see> thrown if <see cref="">GroupLayer</see> added to the base layer collection after retrieval.
    /// </warning>
    /// <since>1.0.0</since>
    void SetBaseLayers(UArcGISLayerCollection* baseLayers);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// This property will help the user to identify the layer on his application.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// This property will help the user to identify the layer on his application.
    /// </summary>
    /// <since>1.0.0</since>
    void SetName(FString name);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// The reference layers.
    /// </summary>
    /// <remarks>
    /// The collection is specific to a basemap so you can't reuse an GELayerCollection coming from another <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see> or <see cref="Esri::GameEngine::Map::ArcGISBasemap">ArcGISBasemap</see>.
    /// You have to create a new layer collection by using <see cref="Esri::GameEngine::Layers::Base::ArcGISLayerCollection">ArcGISLayerCollection</see>.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</seealso>
    /// <seealso cref="Esri::GameEngine::Layers::Base::ArcGISLayerCollection">ArcGISLayerCollection</seealso>
    /// <warning>
    /// <see cref="Esri::Standard::ArcGISErrorType.mappingUnsupportedLayerType">ArcGISErrorType.mappingUnsupportedLayerType</see> thrown if <see cref="">GroupLayer</see> added to the reference layer collection after retrieval.
    /// </warning>
    /// <since>1.0.0</since>
    UArcGISLayerCollection* GetReferenceLayers();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// The reference layers.
    /// </summary>
    /// <remarks>
    /// The collection is specific to a basemap so you can't reuse an GELayerCollection coming from another <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see> or <see cref="Esri::GameEngine::Map::ArcGISBasemap">ArcGISBasemap</see>.
    /// You have to create a new layer collection by using <see cref="Esri::GameEngine::Layers::Base::ArcGISLayerCollection">ArcGISLayerCollection</see>.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</seealso>
    /// <seealso cref="Esri::GameEngine::Layers::Base::ArcGISLayerCollection">ArcGISLayerCollection</seealso>
    /// <warning>
    /// <see cref="Esri::Standard::ArcGISErrorType.mappingUnsupportedLayerType">ArcGISErrorType.mappingUnsupportedLayerType</see> thrown if <see cref="">GroupLayer</see> added to the reference layer collection after retrieval.
    /// </warning>
    /// <since>1.0.0</since>
    void SetReferenceLayers(UArcGISLayerCollection* referenceLayers);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISBasemap")
    /// <summary>
    /// Source property will be a read only, it will be setup on the constructor
    /// </summary>
    /// <since>1.0.0</since>
    FString GetSource();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Map::ArcGISBasemap> APIObject;
};