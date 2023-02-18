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
namespace GameEngine
{
namespace Layers
{
namespace Base
{
class ArcGISLayer;
} // namespace Base
} // namespace Layers

namespace Map
{
/// <summary>
/// The map contains layers and additional properties and can be displayed in a ArcGISRenderComponent.
/// </summary>
/// <remarks>
/// The map represent the document with all data that will be renderer by ArcGISRenderComponent.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISMapInternal
{
    friend class ArcGISMapInternal;

public:
    #pragma region Methods
    /// <summary>
    /// Searches for the layer with the given id.
    /// </summary>
    /// <param name="layerId">The id of the layer to find</param>
    /// <returns>
    /// An <see cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</see> or null if not found.
    /// </returns>
    /// <since>1.0.0</since>
    static Layers::Base::ArcGISLayer FindLayerById(ArcGISMap* self, uint32_t layerId);
    #pragma endregion Methods

protected:
    ArcGISLoadableDoneLoadingEvent m_doneLoading;
    ArcGISLoadableLoadStatusChangedEvent m_loadStatusChanged;
};
} // namespace Map
} // namespace GameEngine
} // namespace Esri