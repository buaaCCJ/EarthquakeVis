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
class ArcGISException;
} // namespace Unreal

namespace GameEngine
{
enum class ArcGISLoadStatus;

namespace Extent
{
class ArcGISExtentRectangle;
} // namespace Extent

namespace Geometry
{
class ArcGISSpatialReference;
} // namespace Geometry

namespace Layers
{
namespace Base
{
enum class ArcGISLayerType;

/// <summary>
/// Abstract class layer, base for layers
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISLayer :
    public ArcGISLoadable
{
    friend class ArcGISLayerInternal;

public:
    #pragma region Constructors
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
    ArcGISLayer(const FString& source, ArcGISLayerType type, const FString& APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// API Key will be sended on loading process to match the new credit system.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAPIKey() const;
    
    /// <summary>
    /// The full extent of this layer, which is the extent where all layer data is contained.
    /// </summary>
    /// <remarks>
    /// You can use this to zoom
    /// to all of the data contained in this layer.
    /// </remarks>
    /// <since>1.0.0</since>
    Extent::ArcGISExtentRectangle GetExtent() const;
    
    /// <summary>
    /// Layer visible true or false
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsVisible() const;
    void SetIsVisible(bool isVisible);
    
    /// <summary>
    /// This property will help the user to identify the layer on his application.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName() const;
    void SetName(const FString& name);
    
    /// <summary>
    /// Layer Opacity
    /// </summary>
    /// <since>1.0.0</since>
    float GetOpacity() const;
    void SetOpacity(float opacity);
    
    /// <summary>
    /// Source property will be a read only, it will be setup on the constructor
    /// </summary>
    /// <since>1.0.0</since>
    FString GetSource() const;
    
    /// <summary>
    /// The spatial reference of the layer.
    /// </summary>
    /// <remarks>
    /// <see cref="Esri::GameEngine::Layers::ArcGISImageLayer">ArcGISImageLayer</see> <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> must match the <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> of the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>.
    /// <see cref="Esri::GameEngine::Layers::ArcGISImageLayer">ArcGISImageLayer</see> tiling scheme must be compatible with the tiling scheme of the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>.
    /// If any of the above constraints are violated, a <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState">ArcGISLayerViewState</see> error is generated.
    /// </remarks>
    /// <since>1.0.0</since>
    Geometry::ArcGISSpatialReference GetSpatialReference() const;
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
    explicit ArcGISLayer(void* handle);
    ArcGISLayer(const ArcGISLayer&) = delete;
    ArcGISLayer(ArcGISLayer&& other) noexcept;
    ArcGISLayer() = default;
    virtual ~ArcGISLayer();
    
    ArcGISLayer& operator=(const ArcGISLayer&) = delete;
    ArcGISLayer& operator=(ArcGISLayer&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
    ArcGISLoadableDoneLoadingEvent m_doneLoading;
    ArcGISLoadableLoadStatusChangedEvent m_loadStatusChanged;
};
} // namespace Base
} // namespace Layers
} // namespace GameEngine
} // namespace Esri