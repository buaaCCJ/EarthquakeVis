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
namespace Layers
{
namespace Base
{
class ArcGISLayer;
} // namespace Base
} // namespace Layers

namespace View
{
namespace State
{
class ArcGISLayerViewState;

using ArcGISLayerViewStateChangedEvent = std::function<void(Layers::Base::ArcGISLayer& layer, ArcGISLayerViewState& arcGISLayerViewState)>;
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri