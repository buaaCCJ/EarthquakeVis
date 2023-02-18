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
struct ArcGISSpheroidData
{
    /// <summary>
    /// The major semi axis (a) of the spheroid, in meters.
    /// </summary>
    /// <since>1.0.0</since>
    double MajorSemiAxis;
    
    /// <summary>
    /// The spheroid's squared eccentricity, equal to (1 - c^2/a^2)
    /// </summary>
    /// <since>1.0.0</since>
    double SquaredEccentricity;
    
    /// <summary>
    /// The minor semi axis (c) of the spheroid, in meters.
    /// </summary>
    /// <since>1.0.0</since>
    double MinorSemiAxis;
    
    /// <summary>
    /// The spheroid's flattening, equal to ((a - c) / a)
    /// </summary>
    /// <since>1.0.0</since>
    double Flattening;
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri