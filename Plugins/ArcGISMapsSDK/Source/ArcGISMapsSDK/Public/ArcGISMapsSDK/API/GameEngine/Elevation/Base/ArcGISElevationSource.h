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

namespace Elevation
{
namespace Base
{
enum class ArcGISElevationSourceType;

/// <summary>
/// Abstract base class for all ElevationSources
/// </summary>
/// <remarks>
/// A base class of implementations of elevation sources.  To use an elevation source you create an instance of a 
/// derived class and set it in to a <see cref="Esri::GameEngine::Map::ArcGISMapElevation">ArcGISMapElevation</see> in the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>. The combination of elevation sources within the 
/// <see cref="Esri::GameEngine::Map::ArcGISMapElevation">ArcGISMapElevation</see> generate a rendering surface on which data can be draped or offset from.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISElevationSource :
    public ArcGISLoadable
{
    friend class ArcGISElevationSourceInternal;

public:
    #pragma region Constructors
    /// <summary>
    /// Creates a new elevation source.
    /// </summary>
    /// <remarks>
    /// Creates a new elevation source.
    /// </remarks>
    /// <param name="source">Elevation source</param>
    /// <param name="type">ArcGISElevationSource type definition.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGISElevationSource(const FString& source, ArcGISElevationSourceType type, const FString& APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// API Key will be sended on loading process to match the new credit system.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAPIKey() const;
    
    /// <summary>
    /// The full extent of this ArcGISElevationSource, which is the extent where all ArcGISElevationSource data is contained.
    /// </summary>
    /// <remarks>
    /// You can use this to zoom
    /// to all of the data contained in this ArcGISElevationSource.
    /// </remarks>
    /// <since>1.0.0</since>
    Extent::ArcGISExtentRectangle GetExtent() const;
    
    /// <summary>
    /// Define if this elevation source is enabled or not.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEnabled() const;
    void SetIsEnabled(bool isEnabled);
    
    /// <summary>
    /// Identifier for elevation source
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName() const;
    void SetName(const FString& name);
    
    /// <summary>
    /// Source property will be a read only, it will be setup on the constructor
    /// </summary>
    /// <since>1.0.0</since>
    FString GetSource() const;
    
    /// <summary>
    /// The spatial reference of the elevation source.
    /// </summary>
    /// <remarks>
    /// <see cref="Esri::GameEngine::Elevation::ArcGISImageElevationSource">ArcGISImageElevationSource</see> <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> must match the <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> of the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>.
    /// <see cref="Esri::GameEngine::Elevation::ArcGISImageElevationSource">ArcGISImageElevationSource</see> tiling scheme must be compatible with the tiling scheme of the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>.
    /// If any of the above constraints are violated, an <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewState">ArcGISElevationSourceViewState</see> error is generated.
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
    explicit ArcGISElevationSource(void* handle);
    ArcGISElevationSource(const ArcGISElevationSource&) = delete;
    ArcGISElevationSource(ArcGISElevationSource&& other) noexcept;
    ArcGISElevationSource() = default;
    virtual ~ArcGISElevationSource();
    
    ArcGISElevationSource& operator=(const ArcGISElevationSource&) = delete;
    ArcGISElevationSource& operator=(ArcGISElevationSource&& other) noexcept;
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
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri