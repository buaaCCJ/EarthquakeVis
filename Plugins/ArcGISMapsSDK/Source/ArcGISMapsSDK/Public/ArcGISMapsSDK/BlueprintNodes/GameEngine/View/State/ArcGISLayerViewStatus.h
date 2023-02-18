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

#include "ArcGISLayerViewStatus.generated.h"

UENUM(BlueprintType, meta=(ScriptName="ArcGISLayerViewStatus"))
namespace EArcGISLayerViewStatus
{
    enum Type
    {
        Null = 0 UMETA(Hidden),
        
        /// <summary>
        /// = 1, The layer in the view is active.
        /// </summary>
        /// <remarks>
        /// A status of <see cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus.active">ArcGISLayerViewStatus.active</see> indicates that the layer is being displayed in the view.
        /// </remarks>
        /// <since>1.0.0</since>
        Active = 1,
        
        /// <summary>
        /// = 2, The layer in the view is not visible.
        /// </summary>
        /// <since>1.0.0</since>
        NotVisible = 2,
        
        /// <summary>
        /// = 4, The layer in the view is out of scale.
        /// </summary>
        /// <remarks>
        /// A status of <see cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus.outOfScale">ArcGISLayerViewStatus.outOfScale</see> indicates that the view is zoomed outside of the scale range
        /// range of the layer. If the view is zoomed too far in (e.g. to a street level) it is beyond the max scale defined 
        /// for the layer. If the view has zoomed to far out (e.g. to global scale) it is beyond the min scale defined for the layer.
        /// </remarks>
        /// <since>1.0.0</since>
        OutOfScale = 4,
        
        /// <summary>
        /// = 8, The layer in the view is loading.
        /// </summary>
        /// <remarks>
        /// Once loading has completed, the layer will be available for display in the view.
        /// If there was a problem loading the layer, the status will be set to <see cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus.error">ArcGISLayerViewStatus.error</see>
        /// and the <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState.message">ArcGISLayerViewState.message</see> property will provide details on the specific problem.
        /// </remarks>
        /// <since>1.0.0</since>
        Loading = 8,
        
        /// <summary>
        /// = 16, The layer in the view has an unrecoverable error.
        /// </summary>
        /// <remarks>
        /// When the status is <see cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus.error">ArcGISLayerViewStatus.error</see>, the layer cannot be rendered in the view.
        /// For example, it may have failed to load, be an unsupported layer type or contain
        /// invalid data.
        /// 
        /// The <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState.message">ArcGISLayerViewState.message</see> property will provide more details about the specific
        /// problem which was encountered. Depending on the type of problem, you could:
        /// * Call <see cref="">Layer.retryLoad</see>
        /// * Remove the layer from the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>
        /// * Inspect the data
        /// </remarks>
        /// <since>1.0.0</since>
        Error = 16,
        
        /// <summary>
        /// = 32, The layer in the view has encountered an error which may be temporary.
        /// </summary>
        /// <remarks>
        /// When the status is <see cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus.warning">ArcGISLayerViewStatus.warning</see>, the layer may still be displayed in the
        /// view. It is possible for the status to be both <see cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus.active">ArcGISLayerViewStatus.active</see> and
        /// <see cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus.warning">ArcGISLayerViewStatus.warning</see>.
        /// 
        /// A warning status indicates that the layer has encountered a problem but may still be
        /// usable. For example, some tiles or features may be failing to load due to network
        /// failure or server error.
        /// 
        /// You should be aware that when a <see cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus.warning">ArcGISLayerViewStatus.warning</see> is received, the layer may
        /// not be showing all data or it may be showing data which is not up-to-date.
        /// 
        /// The <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState.message">ArcGISLayerViewState.message</see> property will provide more details about the specific
        /// problem which was encountered. Depending on the type of problem, you could:
        /// * Check your network connection
        /// * Check whether an online service is experiencing problems
        /// </remarks>
        /// <since>1.0.0</since>
        Warning = 32
    };
}