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
enum class ArcGISElevationSourceViewStatus
{
    /// <summary>
    /// = 1, The elevation source in the view is active.
    /// </summary>
    /// <remarks>
    /// A status of <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.active">ArcGISElevationSourceViewStatus.active</see> indicates that the elevation source is being displayed in the view.
    /// </remarks>
    /// <since>1.0.0</since>
    Active = 1,
    
    /// <summary>
    /// = 2, The elevation source in the view is not enabled.
    /// </summary>
    /// <since>1.0.0</since>
    NotEnabled = 2,
    
    /// <summary>
    /// = 4, The elevation source in the view is out of scale.
    /// </summary>
    /// <remarks>
    /// A status of <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.outOfScale">ArcGISElevationSourceViewStatus.outOfScale</see> indicates that the view is zoomed outside of the scale range
    /// range of the elevation source. If the view is zoomed too far in (e.g. to a street level) it is beyond the max scale defined 
    /// for the elevation source. If the view has zoomed to far out (e.g. to global scale) it is beyond the min scale defined for the elevation source.
    /// </remarks>
    /// <since>1.0.0</since>
    OutOfScale = 4,
    
    /// <summary>
    /// = 8, The elevation source in the view is loading.
    /// </summary>
    /// <remarks>
    /// Once loading has completed, the elevation source will be available for display in the view.
    /// If there was a problem loading the elevation source, the status will be set to <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.error">ArcGISElevationSourceViewStatus.error</see>
    /// and the <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.error">ArcGISElevationSourceViewStatus.error</see> property will provide details on the specific problem.
    /// </remarks>
    /// <since>1.0.0</since>
    Loading = 8,
    
    /// <summary>
    /// = 16, The elevation source in the view has an unrecoverable error.
    /// </summary>
    /// <remarks>
    /// When the status is <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.error">ArcGISElevationSourceViewStatus.error</see>, the elevation source cannot be rendered in the view.
    /// For example, it may have failed to load, be an unsupported elevation source type or contain invalid data.
    /// 
    /// The <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.error">ArcGISElevationSourceViewStatus.error</see> property will provide more details about the specific problem which was encountered.
    /// Depending on the type of problem, you could:
    /// - call <see cref="">ElevationSource.retryLoad</see>
    /// - remove the elevation source from the <see cref="">Map</see> or <see cref="">Scene</see>
    /// - inspect the data
    /// </remarks>
    /// <since>1.0.0</since>
    Error = 16,
    
    /// <summary>
    /// = 32, The elevation source in the view has encountered an error which may be temporary.
    /// </summary>
    /// <remarks>
    /// When the status is <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.warning">ArcGISElevationSourceViewStatus.warning</see>, the elevation source may still be displayed in the view.
    /// It is possible for the status to be both <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.active">ArcGISElevationSourceViewStatus.active</see> and <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.warning">ArcGISElevationSourceViewStatus.warning</see>.
    /// 
    /// A warning status indicates that the elevation source has encountered a problem but may still be usable.
    /// 
    /// You should be aware that when a <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.warning">ArcGISElevationSourceViewStatus.warning</see> is received, the elevation source may not be showing
    /// all data or it may be showing data which is not up-to-date.
    /// 
    /// The <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus.error">ArcGISElevationSourceViewStatus.error</see> property will provide more details about the specific problem which was encountered.
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