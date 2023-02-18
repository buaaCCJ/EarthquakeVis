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
enum class ArcGISLatitudeLongitudeFormat
{
    /// <summary>
    /// The geographical coordinates are represented in decimal degrees.
    /// </summary>
    /// <since>1.0.0</since>
    DecimalDegrees = 0,
    
    /// <summary>
    /// The geographical coordinates are represented in degrees and decimal minutes.
    /// </summary>
    /// <since>1.0.0</since>
    DegreesDecimalMinutes = 1,
    
    /// <summary>
    /// The geographical coordinates are represented in degrees and minutes and decimal seconds.
    /// </summary>
    /// <since>1.0.0</since>
    DegreesMinutesSeconds = 2
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri