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
namespace Geometry
{
enum class ArcGISDatumTransformationType
{
    /// <summary>
    /// Represents a <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</see> instance.
    /// </summary>
    /// <since>1.0.0</since>
    GeographicTransformation = 1,
    
    /// <summary>
    /// Represents a <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformation">ArcGISHorizontalVerticalTransformation</see> instance.
    /// </summary>
    /// <since>1.0.0</since>
    HorizontalVerticalTransformation = 2
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri