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
namespace Elevation
{
namespace Base
{
class ArcGISElevationSource;
} // namespace Base
} // namespace Elevation

namespace View
{
namespace State
{
class ArcGISElevationSourceViewState;

using ArcGISElevationSourceViewStateChangedEvent = std::function<void(Elevation::Base::ArcGISElevationSource& layer, ArcGISElevationSourceViewState& arcGISElevationSourceViewState)>;
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri