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
class ARCGISMAPSSDK_API ArcGISUnit
{
    friend class ArcGISUnitInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The abbreviation of the unit.
    /// </summary>
    /// <remarks>
    /// The abbreviation for a specific unit.
    /// </remarks>
    /// <since>1.0.0</since>
    FString GetAbbreviation() const;
    
    /// <summary>
    /// The display name of the unit.
    /// </summary>
    /// <remarks>
    /// The display name for a specific unit.
    /// </remarks>
    /// <since>1.0.0</since>
    FString GetDisplayName() const;
    
    /// <summary>
    /// The name of the unit.
    /// </summary>
    /// <remarks>
    /// The name for a specific unit.
    /// </remarks>
    /// <since>1.0.0</since>
    FString GetName() const;
    
    /// <summary>
    /// The display name of the unit.
    /// </summary>
    /// <remarks>
    /// The display name for a specific unit.
    /// </remarks>
    /// <since>1.0.0</since>
    FString GetPluralDisplayName() const;
    
    /// <summary>
    /// The well-known ID for the unit, or 0 for a custom unit.
    /// </summary>
    /// <since>1.0.0</since>
    int32_t GetUnitId() const;
    
    /// <summary>
    /// The well-known ID for the unit, or 0 for a custom unit.
    /// </summary>
    /// <since>1.0.0</since>
    int32_t GetWKID() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Creates a unit given its well-known ID.
    /// </summary>
    /// <param name="unitId">The well-known ID of the unit.</param>
    /// <returns>
    /// A unit. Depending on the well-known ID given, this may be a <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnit">ArcGISLinearUnit</see>, <see cref="Esri::GameEngine::Geometry::ArcGISAngularUnit">ArcGISAngularUnit</see>, or <see cref="Esri::GameEngine::Geometry::ArcGISAreaUnit">ArcGISAreaUnit</see>.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISUnit FromUnitId(int32_t unitId);
    
    /// <summary>
    /// Creates a unit given its well-known ID.
    /// </summary>
    /// <param name="WKID">The well-known ID of the unit.</param>
    /// <returns>
    /// A unit. Depending on the well-known ID given, this may be a <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnit">ArcGISLinearUnit</see>, <see cref="Esri::GameEngine::Geometry::ArcGISAngularUnit">ArcGISAngularUnit</see>, or <see cref="Esri::GameEngine::Geometry::ArcGISAreaUnit">ArcGISAreaUnit</see>.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISUnit FromWKID(int32_t WKID);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISUnit(void* handle);
    ArcGISUnit(const ArcGISUnit&) = delete;
    ArcGISUnit(ArcGISUnit&& other) noexcept;
    ArcGISUnit() = default;
    ~ArcGISUnit();
    
    ArcGISUnit& operator=(const ArcGISUnit&) = delete;
    ArcGISUnit& operator=(ArcGISUnit&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri