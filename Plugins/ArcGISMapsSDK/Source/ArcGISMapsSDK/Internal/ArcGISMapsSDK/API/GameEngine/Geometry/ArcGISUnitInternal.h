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
enum class ArcGISUnitType;

/// <summary>
/// Defines a unit of measurement.
/// </summary>
/// <remarks>
/// <see cref="Esri::GameEngine::Geometry::ArcGISUnit">ArcGISUnit</see> is a base class for measurement classes such as <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnit">ArcGISLinearUnit</see>, <see cref="Esri::GameEngine::Geometry::ArcGISAngularUnit">ArcGISAngularUnit</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISAreaUnit">ArcGISAreaUnit</see>. Many
/// function parameters only accept specific types of measurement to reduce the chance of accidental use of
/// inappropriate values, but some generic functions accept all unit types, such as for translation from ID to text
/// description.
/// 
/// <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnit">ArcGISLinearUnit</see> - Projected coordinate systems define coordinates using linear measurements,
/// for example using meters or miles. They are also used to return distance measurements, for
/// example by some members of <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine">ArcGISGeometryEngine</see>.
/// 
/// <see cref="Esri::GameEngine::Geometry::ArcGISAngularUnit">ArcGISAngularUnit</see> - Geographic coordinate systems define coordinates using angular
/// measurements, for example using degrees or radians.
/// 
/// <see cref="Esri::GameEngine::Geometry::ArcGISAreaUnit">ArcGISAreaUnit</see> - Projected coordinate systems define area units for two dimensional
/// measurements such as the area enclosed by a ring, for example in acres or square kilometers.
/// 
/// Linear, angular, and area units can be defined by using enumerations of the most common units
/// of measurement. They can also be defined by well-known ID (WKID) or well-known text (WKText).
/// Create the unit instances using the Unit base class or the subtype, passing in the
/// enumeration for a specific unit of measurement.
/// 
/// Construction of related units are also supported so that if, for instance, the LinearUnit
/// (e.g. METERS) is known, then the corresponding AreaUnit (e.g. SQUARE_METERS) can be created
/// based on the LinearUnit.
/// 
/// Custom unit implementations are not supported.
/// 
/// Each instance of the various units types has properties for the unit name (singular, plural,
/// and abbreviated) and provides methods for unit conversion between different units of
/// measurement in the same category of measurement.
/// 
/// All unit names and abbreviations are returned in the English language.
/// Instances of unit are immutable.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISUnitInternal
{
    friend class ArcGISUnitInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The type of the unit.
    /// </summary>
    /// <remarks>
    /// The unit type for a specific unit. Will return <see cref="Esri::GameEngine::Geometry::ArcGISUnitType.unknown">ArcGISUnitType.unknown</see> if an error occurs.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISUnitType">ArcGISUnitType</seealso>
    /// <since>1.0.0</since>
    static ArcGISUnitType GetObjectType(ArcGISUnit* self);
    #pragma endregion Properties
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri