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
namespace RCQ
{
class ArcGISRenderCommandServer;
} // namespace RCQ

namespace View
{
/// <summary>
/// A view for interaction with geographic content from an <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISViewInternal
{
    friend class ArcGISViewInternal;

public:
    #pragma region Properties
    /// <summary>
    /// Serves render commands
    /// </summary>
    /// <since>1.0.0</since>
    static RCQ::ArcGISRenderCommandServer GetRenderCommandServer(ArcGISView* self);
    #pragma endregion Properties

protected:
    State::ArcGISElevationSourceViewStateChangedEvent m_elevationSourceViewStateChanged;
    State::ArcGISLayerViewStateChangedEvent m_layerViewStateChanged;
    ArcGISViewSpatialReferenceChangedEvent m_spatialReferenceChanged;
    State::ArcGISViewStateChangedEvent m_viewStateChanged;
};
} // namespace View
} // namespace GameEngine
} // namespace Esri