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

namespace Esri
{
namespace GameEngine
{
namespace View
{
namespace State
{
enum class ArcGISViewStatus
{
    /// <summary>
    /// = 1, The view is active.
    /// </summary>
    /// <remarks>
    /// A status of <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.active">ArcGISViewStatus.active</see> indicates that the view is being displayed.
    /// </remarks>
    /// <since>1.0.0</since>
    Active = 1,
    
    /// <summary>
    /// = 2, The map is not ready to display.
    /// </summary>
    /// <remarks>
    /// This status applies if there is no map set on the view, or if the map has been set but doesn't contain enough information to be loaded.
    /// For instance, it may not have any layers or it may not have a basemap yet.
    /// </remarks>
    /// <since>1.0.0</since>
    MapNotReady = 2,
    
    /// <summary>
    /// = 4, There is not a valid camera, viewport properties, or spatial reference.
    /// </summary>
    /// <remarks>
    /// A status of <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.noViewport">ArcGISViewStatus.noViewport</see> indicates that the viewport properties, camera, or spatial reference are either invalid or not set yet.
    /// On initialization of the RendererView, if noViewport is reported after setting the camera and viewport properties, check that mapNotReady is not set. 
    /// Data from the Map is required to initialize the RendererView.
    /// </remarks>
    /// <since>1.0.0</since>
    NoViewport = 4,
    
    /// <summary>
    /// = 8, The view is loading.
    /// </summary>
    /// <remarks>
    /// Once loading has completed, the view will display.
    /// If there was a problem loading, the status will be set to <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.error">ArcGISViewStatus.error</see>
    /// and the <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.error">ArcGISViewStatus.error</see> property will provide details on the specific problem.
    /// </remarks>
    /// <since>1.0.0</since>
    Loading = 8,
    
    /// <summary>
    /// = 16, The view has an error preventing it from rendering.
    /// </summary>
    /// <remarks>
    /// When the status is <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.error">ArcGISViewStatus.error</see>, the view cannot be rendered.
    /// 
    /// The <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.error">ArcGISViewStatus.error</see> property will provide more details about the specific problem which was encountered.
    /// </remarks>
    /// <since>1.0.0</since>
    Error = 16,
    
    /// <summary>
    /// = 32, The view has encountered an error which may be temporary.
    /// </summary>
    /// <remarks>
    /// When the status is <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.warning">ArcGISViewStatus.warning</see>, the view may still be rendered although it may be rendered incompletely.
    /// It is possible for the status to be both <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.active">ArcGISViewStatus.active</see> and <see cref="Esri::GameEngine::View::State::ArcGISViewStatus.warning">ArcGISViewStatus.warning</see>.
    /// 
    /// The <see cref="Esri::GameEngine::View::State::ArcGISViewState.message">ArcGISViewState.message</see> property will provide more details about the specific problem which was encountered.
    /// Depending on the type of problem, you could:
    /// - check your network connection
    /// - check whether an online service is experiencing problems
    /// </remarks>
    /// <since>1.0.0</since>
    Warning = 32
};
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri