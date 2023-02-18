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

namespace Extent
{
class ArcGISExtent;
} // namespace Extent

namespace Geometry
{
class ArcGISSpatialReference;
} // namespace Geometry

namespace Layers
{
namespace Base
{
class ArcGISLayer;
} // namespace Base
} // namespace Layers

namespace Map
{
class ArcGISBasemap;
class ArcGISMapElevation;
enum class ArcGISMapType;

/// <summary>
/// The map contains layers and additional properties and can be displayed in a ArcGISRenderComponent.
/// </summary>
/// <remarks>
/// The map represent the document with all data that will be renderer by ArcGISRenderComponent.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISMap :
    public ArcGISLoadable
{
    friend class ArcGISMapInternal;

public:
    #pragma region Constructors
    /// <summary>
    /// Create a new Map document.
    /// </summary>
    /// <remarks>
    /// Creates map view for displaying a map. We only be able to have one map by scene, it will be automatically rendered on the ArcGISRenderComponent.
    /// </remarks>
    /// <param name="basemap">Specifies the basemap</param>
    /// <param name="mapType">Specifies the map type.</param>
    /// <since>1.0.0</since>
    ArcGISMap(ArcGISBasemap& basemap, ArcGISMapType mapType);
    
    /// <summary>
    /// Create a new Map document.
    /// </summary>
    /// <remarks>
    /// Creates map view for displaying a map. We only be able to have one map by scene, it will be automatically rendered on the ArcGISRenderComponent.
    /// </remarks>
    /// <param name="mapType">Specifies the map type.</param>
    /// <since>1.0.0</since>
    ArcGISMap(ArcGISMapType mapType);
    
    /// <summary>
    /// Creates a map with spatial reference and map type.
    /// </summary>
    /// <param name="spatialReference">A spatial reference object.</param>
    /// <param name="mapType">Specifies the map type.</param>
    /// <since>1.0.0</since>
    ArcGISMap(const Geometry::ArcGISSpatialReference& spatialReference, ArcGISMapType mapType);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// Definition for basemap.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISBasemap GetBasemap() const;
    void SetBasemap(const ArcGISBasemap& basemap);
    
    /// <summary>
    /// Definition of map's clipping area. This property will be applied in Local mode only.
    /// </summary>
    /// <remarks>
    /// Setting a non-null clipping area in Global mode will result in an error.
    /// </remarks>
    /// <since>1.0.0</since>
    Extent::ArcGISExtent GetClippingArea() const;
    void SetClippingArea(const Extent::ArcGISExtent& clippingArea);
    
    /// <summary>
    /// Definition of map elevation.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISMapElevation GetElevation() const;
    void SetElevation(const ArcGISMapElevation& elevation);
    
    /// <summary>
    /// List of <see cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</see> included on the map
    /// </summary>
    /// <since>1.0.0</since>
    Unreal::ArcGISCollection<Layers::Base::ArcGISLayer> GetLayers() const;
    void SetLayers(const Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>& layers);
    
    /// <summary>
    /// Definition for the map, if it's local or global.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISMapType GetMapType() const;
    
    /// <summary>
    /// The spatial reference for the map.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
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
    explicit ArcGISMap(void* handle);
    ArcGISMap(const ArcGISMap&) = delete;
    ArcGISMap(ArcGISMap&& other) noexcept;
    ArcGISMap() = default;
    virtual ~ArcGISMap();
    
    ArcGISMap& operator=(const ArcGISMap&) = delete;
    ArcGISMap& operator=(ArcGISMap&& other) noexcept;
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