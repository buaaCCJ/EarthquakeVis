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
enum class ArcGISElevationSourceType
{
    /// <summary>
    /// An ArcGISElevationSource from tiled image data
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISImageElevationSource = 0,
    
    /// <summary>
    /// An unknown ArcGISElevationSource
    /// </summary>
    /// <since>1.0.0</since>
    Unknown = -1
};
} // namespace Base
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri