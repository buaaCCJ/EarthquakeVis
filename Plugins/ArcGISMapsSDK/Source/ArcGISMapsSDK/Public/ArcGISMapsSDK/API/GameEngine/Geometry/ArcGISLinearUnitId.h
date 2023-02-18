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
enum class ArcGISLinearUnitId
{
    /// <summary>
    /// Indicates that the unit of linear measurement is a custom unit, or a unit that is not listed in the enumerated type.
    /// This value may be returned from an LinearUnit created from a WKID of a less commonly used unit of measurement
    /// that does not have an equivalent value in this enumeration.
    /// </summary>
    /// <since>1.0.0</since>
    Other = 0,
    
    /// <summary>
    /// Indicates a linear measurement in centimeters.
    /// This unit has a WKID of 1033.
    /// </summary>
    /// <since>1.0.0</since>
    Centimeters = 1033,
    
    /// <summary>
    /// Indicates a linear measurement in feet.
    /// This unit has a WKID of 9002.
    /// </summary>
    /// <since>1.0.0</since>
    Feet = 9002,
    
    /// <summary>
    /// Indicates a linear measurement in inches.
    /// This unit has a WKID of 109008.
    /// </summary>
    /// <since>1.0.0</since>
    Inches = 109008,
    
    /// <summary>
    /// Indicates a linear measurement in kilometers.
    /// This unit has a WKID of 9036.
    /// </summary>
    /// <since>1.0.0</since>
    Kilometers = 9036,
    
    /// <summary>
    /// Indicates a linear measurement in meters.
    /// This unit has a WKID of 9001.
    /// </summary>
    /// <since>1.0.0</since>
    Meters = 9001,
    
    /// <summary>
    /// Indicates a linear measurement in statute miles.
    /// This unit has a WKID of 9093.
    /// </summary>
    /// <since>1.0.0</since>
    Miles = 9093,
    
    /// <summary>
    /// Indicates a linear measurement in millimeters.
    /// This unit has a WKID of 1025.
    /// </summary>
    /// <since>1.0.0</since>
    Millimeters = 1025,
    
    /// <summary>
    /// Indicates a linear measurement in nautical miles.
    /// This unit has a WKID of 9030.
    /// </summary>
    /// <since>1.0.0</since>
    NauticalMiles = 9030,
    
    /// <summary>
    /// Indicates a linear measurement in yards.
    /// This unit has a WKID of 9096.
    /// </summary>
    /// <since>1.0.0</since>
    Yards = 9096
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri