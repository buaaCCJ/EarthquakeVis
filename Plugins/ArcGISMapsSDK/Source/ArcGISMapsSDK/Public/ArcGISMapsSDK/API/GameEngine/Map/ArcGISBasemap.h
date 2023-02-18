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

#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadable.h"

namespace Esri
{
namespace Unreal
{
template<typename T> class ArcGISCollection;
class ArcGISException;
} // namespace Unreal

namespace GameEngine
{
enum class ArcGISLoadStatus;

namespace Layers
{
namespace Base
{
class ArcGISLayer;
enum class ArcGISLayerType;
} // namespace Base
} // namespace Layers

namespace Map
{
enum class ArcGISBasemapStyle;

/// <summary>
/// Public class that will contain a basemap.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISBasemap :
    public ArcGISLoadable
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates an empty ArcGISBasemap. Basemap is created in a loaded state.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISBasemap();
    
    /// <summary>
    /// Creates a basemap with a style.
    /// </summary>
    /// <param name="basemapStyle">The basemap style.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <seealso cref="Esri::GameEngine::Map::ArcGISBasemapStyle">ArcGISBasemapStyle</seealso>
    /// <since>1.0.0</since>
    ArcGISBasemap(ArcGISBasemapStyle basemapStyle, const FString& APIKey);
    
    /// <summary>
    /// Creates a ArcGISBasemap from a URI and ArcGISLayerType
    /// </summary>
    /// <param name="source">ArcGISLayer source</param>
    /// <param name="type">Layer type definition.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGISBasemap(const FString& source, Layers::Base::ArcGISLayerType type, const FString& APIKey);
    
    /// <summary>
    /// Creates a ArcGISBasemap from a basemap URI
    /// </summary>
    /// <param name="source">ArcGISBasemap source</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGISBasemap(const FString& source, const FString& APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// API Key will be sended on loading process to match the new credit system.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAPIKey() const;
    
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
    Unreal::ArcGISCollection<Layers::Base::ArcGISLayer> GetBaseLayers() const;
    void SetBaseLayers(const Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>& baseLayers);
    
    /// <summary>
    /// This property will help the user to identify the layer on his application.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName() const;
    void SetName(const FString& name);
    
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
    Unreal::ArcGISCollection<Layers::Base::ArcGISLayer> GetReferenceLayers() const;
    void SetReferenceLayers(const Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>& referenceLayers);
    
    /// <summary>
    /// Source property will be a read only, it will be setup on the constructor
    /// </summary>
    /// <since>1.0.0</since>
    FString GetSource() const;
    #pragma endregion Properties
    
    #pragma region ArcGISLoadable
    Unreal::ArcGISException GetLoadError() const override;
    
    ArcGISLoadStatus GetLoadStatus() const override;
    
    void CancelLoad() override;
    
    void Load() override;
    
    void RetryLoad() override;
    
    ArcGISLoadableDoneLoadingEvent GetDoneLoading() const override;
    void SetDoneLoading(ArcGISLoadableDoneLoadingEvent doneLoading) override;
    
    ArcGISLoadableLoadStatusChangedEvent GetLoadStatusChanged() const override;
    void SetLoadStatusChanged(ArcGISLoadableLoadStatusChangedEvent loadStatusChanged) override;
    #pragma endregion ArcGISLoadable

public:
    #pragma region Special Members
    explicit ArcGISBasemap(void* handle);
    ArcGISBasemap(const ArcGISBasemap&) = delete;
    ArcGISBasemap(ArcGISBasemap&& other) noexcept;
    virtual ~ArcGISBasemap();
    
    ArcGISBasemap& operator=(const ArcGISBasemap&) = delete;
    ArcGISBasemap& operator=(ArcGISBasemap&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
    ArcGISLoadableDoneLoadingEvent m_doneLoading;
    ArcGISLoadableLoadStatusChangedEvent m_loadStatusChanged;
};
} // namespace Map
} // namespace GameEngine
} // namespace Esri