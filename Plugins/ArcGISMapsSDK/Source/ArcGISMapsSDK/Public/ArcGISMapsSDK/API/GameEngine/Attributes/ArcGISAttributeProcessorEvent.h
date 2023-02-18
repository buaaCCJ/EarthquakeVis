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
namespace Unreal
{
template<typename T> class ArcGISImmutableArray;
} // namespace Unreal

namespace GameEngine
{
namespace Attributes
{
class ArcGISAttribute;
class ArcGISVisualizationAttribute;

using ArcGISAttributeProcessorEvent = std::function<void(const Unreal::ArcGISImmutableArray<ArcGISAttribute>& layerAttributes, const Unreal::ArcGISImmutableArray<ArcGISVisualizationAttribute>& visualizationAttributes)>;
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri