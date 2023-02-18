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

#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISViewSpatialReferenceChangedEvent.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISElevationSourceViewStateChangedEvent.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISLayerViewStateChangedEvent.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateChangedEvent.h"

namespace Esri
{
namespace GameEngine
{
enum class ArcGISGameEngineType;

namespace Elevation
{
namespace Base
{
class ArcGISElevationSource;
} // namespace Base
} // namespace Elevation

namespace Geometry
{
class ArcGISPoint;
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
class ArcGISMap;
} // namespace Map

namespace MapView
{
class ArcGISCamera;
enum class ArcGISGlobeModel;
} // namespace MapView

namespace View
{
struct ArcGISViewOptions;

namespace State
{
class ArcGISElevationSourceViewState;
class ArcGISLayerViewState;
class ArcGISViewState;
} // namespace State

/// <summary>
/// A view for interaction with geographic content from an <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISView
{
    friend class ArcGISViewInternal;

public:
    #pragma region Constructors
    /// <summary>
    /// Create a new <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
    /// </summary>
    /// <param name="gameEngineType">Specifies the client game engine type</param>
    /// <param name="globeModel">Specifies the model used to represent a 3D globe</param>
    /// <since>1.0.0</since>
    ArcGISView(ArcGISGameEngineType gameEngineType, MapView::ArcGISGlobeModel globeModel);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The current camera
    /// </summary>
    /// <since>1.0.0</since>
    MapView::ArcGISCamera GetCamera() const;
    void SetCamera(const MapView::ArcGISCamera& camera);
    
    /// <summary>
    /// The current map document.
    /// </summary>
    /// <since>1.0.0</since>
    Map::ArcGISMap GetMap() const;
    void SetMap(const Map::ArcGISMap& map);
    
    /// <summary>
    /// The current View Spatial Reference.
    /// </summary>
    /// <since>1.0.0</since>
    Geometry::ArcGISSpatialReference GetSpatialReference() const;
    
    /// <summary>
    /// The current view options for the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISViewOptions GetViewOptions() const;
    void SetViewOptions(const ArcGISViewOptions& viewOptions);
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Transforms a geographic coordinate in a GCS or PCS to game engine world cartesian space.
    /// If the view has no spatial reference the returned coordinate will have NaN values.
    /// </summary>
    /// <remarks>
    /// The geographicCoordinate.spatialReference does not have to match the view spatial reference (SR),
    /// but the coordinate will be internally reprojected to the view SR. Depending on the
    /// SR of geographicCoordinate, the result may be inaccurate, or the reprojection may fail and return
    /// NaN values, so specifying geographicCoordinate in the view SR is preferred.
    /// </remarks>
    /// <param name="geographicCoordinate">The geographic position in a GCS or PCS</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Math::ArcGISVector3">ArcGISVector3</see>.
    /// </returns>
    /// <since>1.0.0</since>
    FVector3d GeographicToWorld(const Geometry::ArcGISPoint& geographicCoordinate) const;
    
    /// <summary>
    /// Retrieve the view's view state.
    /// </summary>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISViewState">ArcGISViewState</see>.
    /// </returns>
    /// <since>1.0.0</since>
    State::ArcGISViewState GetViewState() const;
    
    /// <summary>
    /// Retrieve the elevation source's view state.
    /// </summary>
    /// <param name="elevation">A elevation object to get the view state for.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewState">ArcGISElevationSourceViewState</see>.
    /// </returns>
    /// <since>1.0.0</since>
    State::ArcGISElevationSourceViewState GetViewState(const Elevation::Base::ArcGISElevationSource& elevation) const;
    
    /// <summary>
    /// Retrieve the layer's view state.
    /// </summary>
    /// <param name="layer">A layer object to get the view state for.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState">ArcGISLayerViewState</see>.
    /// </returns>
    /// <since>1.0.0</since>
    State::ArcGISLayerViewState GetViewState(const Layers::Base::ArcGISLayer& layer) const;
    
    /// <summary>
    /// Handle a platform low memory event
    /// </summary>
    /// <since>1.0.0</since>
    void HandleLowMemoryWarning();
    
    /// <summary>
    /// Sets the quotas for system and video memory that can be used by the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>
    /// </summary>
    /// <remarks>
    /// If provided video memory quota is < 0 on mobile devices, a shared memory model will be assumed.
    /// </remarks>
    /// <param name="systemMemory">The system memory quota in MiB</param>
    /// <param name="videoMemory">The video memory quota in MiB</param>
    /// <since>1.0.0</since>
    void SetMemoryQuotas(int64_t systemMemory, int64_t videoMemory);
    
    /// <summary>
    /// Sets the viewport size and field of view. 
    /// Either field of view angle can be set to 0 to indicate "unset".
    /// For example, if verticalFieldOfViewDegrees is 0.0, but horizontalFieldOfViewDegrees is greater than zero, then the viewport vertical field
    /// of view will be set to the appropriate value given the horizontal FOV and distortion factor. And vice versa.
    /// </summary>
    /// <param name="viewportWidthPixels">used in visible tile calculation, on the basis that DPI is 96.</param>
    /// <param name="viewportHeightPixels">used in visible tile calculation, on the basis that DPI is 96.</param>
    /// <param name="horizontalFieldOfViewDegrees">A value in degrees. The valid range is 0 to 120</param>
    /// <param name="verticalFieldOfViewDegrees">A value in degrees. The valid range is 0 to 120</param>
    /// <param name="verticalDistortionFactor">Determines how much the vertical field of view is distorted. A distortion factor of 1.0 is default. A distortion factor less than 1.0 will cause the visuals to be stretched taller in comparison to their width. A distortion factor greater than 1.0 will cause the visuals to be shrunk shorter in comparison to their width.</param>
    /// <since>1.0.0</since>
    void SetViewportProperties(uint32_t viewportWidthPixels, uint32_t viewportHeightPixels, float horizontalFieldOfViewDegrees, float verticalFieldOfViewDegrees, float verticalDistortionFactor);
    
    /// <summary>
    /// Transforms a world coordinate to a geographic coordinate in the spatial reference of the view.
    /// If the view has no spatial reference the returned coordinate will have NaN values.
    /// </summary>
    /// <param name="worldCoordinate">The game engine world coordinate</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>.
    /// </returns>
    /// <since>1.0.0</since>
    Geometry::ArcGISPoint WorldToGeographic(FVector3d worldCoordinate) const;
    #pragma endregion Methods
    
    #pragma region Events
    /// <summary>
    /// Sets a callback to be invoked when the elevation source view state changes for the view.
    /// </summary>
    /// <since>1.0.0</since>
    State::ArcGISElevationSourceViewStateChangedEvent GetElevationSourceViewStateChanged() const;
    void SetElevationSourceViewStateChanged(State::ArcGISElevationSourceViewStateChangedEvent elevationSourceViewStateChanged);
    
    /// <summary>
    /// Sets a callback to be invoked when the layer view state changes for the view.
    /// </summary>
    /// <since>1.0.0</since>
    State::ArcGISLayerViewStateChangedEvent GetLayerViewStateChanged() const;
    void SetLayerViewStateChanged(State::ArcGISLayerViewStateChangedEvent layerViewStateChanged);
    
    /// <summary>
    /// Sets a callback to be invoked when the View's spatial reference changes.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISViewSpatialReferenceChangedEvent GetSpatialReferenceChanged() const;
    void SetSpatialReferenceChanged(ArcGISViewSpatialReferenceChangedEvent spatialReferenceChanged);
    
    /// <summary>
    /// Sets a callback to be invoked when the view state changes for the view.
    /// </summary>
    /// <since>1.0.0</since>
    State::ArcGISViewStateChangedEvent GetViewStateChanged() const;
    void SetViewStateChanged(State::ArcGISViewStateChangedEvent viewStateChanged);
    #pragma endregion Events

public:
    #pragma region Special Members
    explicit ArcGISView(void* handle);
    ArcGISView(const ArcGISView&) = delete;
    ArcGISView(ArcGISView&& other) noexcept;
    ArcGISView() = default;
    ~ArcGISView();
    
    ArcGISView& operator=(const ArcGISView&) = delete;
    ArcGISView& operator=(ArcGISView&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
    State::ArcGISElevationSourceViewStateChangedEvent m_elevationSourceViewStateChanged;
    State::ArcGISLayerViewStateChangedEvent m_layerViewStateChanged;
    ArcGISViewSpatialReferenceChangedEvent m_spatialReferenceChanged;
    State::ArcGISViewStateChangedEvent m_viewStateChanged;
};
} // namespace View
} // namespace GameEngine
} // namespace Esri