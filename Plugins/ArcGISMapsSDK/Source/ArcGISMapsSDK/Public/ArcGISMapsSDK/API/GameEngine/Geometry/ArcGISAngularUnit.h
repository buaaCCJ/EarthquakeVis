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

#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUnit.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
enum class ArcGISAngularUnitId;

/// <summary>
/// Defines an angular unit of measurement.
/// </summary>
/// <remarks>
/// The angular unit class is derived from the unit class.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISUnit">ArcGISUnit</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISAngularUnit :
    public ArcGISUnit
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a unit given its known id.
    /// </summary>
    /// <param name="unitId">The known id of the unit.</param>
    /// <since>1.0.0</since>
    ArcGISAngularUnit(ArcGISAngularUnitId unitId);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The <see cref="Esri::GameEngine::Geometry::ArcGISAngularUnitId">ArcGISAngularUnitId</see> of the given angular unit.
    /// </summary>
    /// <remarks>
    /// If an error occurs then <see cref="Esri::GameEngine::Geometry::ArcGISAngularUnitId.other">ArcGISAngularUnitId.other</see> is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISAngularUnitId GetAngularUnitId() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Converts a value in another UOM into this UOM.
    /// </summary>
    /// <param name="fromUnit">The UOM to convert from.</param>
    /// <param name="angle">The value to convert.</param>
    /// <returns>
    /// The value in the this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertFrom(const ArcGISAngularUnit& fromUnit, double angle) const;
    
    /// <summary>
    /// Converts a value in this UOM into another UOM.
    /// </summary>
    /// <param name="toUnit">The UOM to convert to.</param>
    /// <param name="angle">The value to convert.</param>
    /// <returns>
    /// The value in the target UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertTo(const ArcGISAngularUnit& toUnit, double angle) const;
    
    /// <summary>
    /// Converts a radian value to this UOM.
    /// </summary>
    /// <param name="radians">The value to convert.</param>
    /// <returns>
    /// The value in this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double FromRadians(double radians) const;
    
    /// <summary>
    /// Converts a value in this UOM to radians.
    /// </summary>
    /// <param name="angle">The value to convert.</param>
    /// <returns>
    /// The value in radians or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ToRadians(double angle) const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISAngularUnit(void* handle);
    ArcGISAngularUnit(const ArcGISAngularUnit&) = delete;
    ArcGISAngularUnit(ArcGISAngularUnit&& other) noexcept;
    ArcGISAngularUnit();
    virtual ~ArcGISAngularUnit() = default;
    
    ArcGISAngularUnit& operator=(const ArcGISAngularUnit&) = delete;
    ArcGISAngularUnit& operator=(ArcGISAngularUnit&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri