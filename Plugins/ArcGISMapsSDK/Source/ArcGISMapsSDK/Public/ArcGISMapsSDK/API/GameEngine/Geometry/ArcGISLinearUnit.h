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
class ArcGISAreaUnit;
enum class ArcGISLinearUnitId;

/// <summary>
/// Defines a linear unit of measurement.
/// </summary>
/// <remarks>
/// The linear unit class is derived from the unit class.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISUnit">ArcGISUnit</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISLinearUnit :
    public ArcGISUnit
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates an linear unit given an area unit.
    /// </summary>
    /// <remarks>
    /// Creates a unit given an area unit.
    /// </remarks>
    /// <param name="areaUnit">The area unit.</param>
    /// <since>1.0.0</since>
    ArcGISLinearUnit(const ArcGISAreaUnit& areaUnit);
    
    /// <summary>
    /// Creates a unit given its known id.
    /// </summary>
    /// <param name="unitId">The known id of the unit.</param>
    /// <since>1.0.0</since>
    ArcGISLinearUnit(ArcGISLinearUnitId unitId);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnitId">ArcGISLinearUnitId</see> of the given Linear unit.
    /// </summary>
    /// <remarks>
    /// If an error occurs then <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnitId.other">ArcGISLinearUnitId.other</see> is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISLinearUnitId GetLinearUnitId() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Converts a value in another UOM into this UOM.
    /// </summary>
    /// <param name="fromUnit">The UOM to convert from.</param>
    /// <param name="value">The value to convert.</param>
    /// <returns>
    /// The value in this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertFrom(const ArcGISLinearUnit& fromUnit, double value) const;
    
    /// <summary>
    /// Converts a value in this UOM into another UOM.
    /// </summary>
    /// <param name="toUnit">The UOM to convert to.</param>
    /// <param name="value">The value to convert.</param>
    /// <returns>
    /// The value in the target UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertTo(const ArcGISLinearUnit& toUnit, double value) const;
    
    /// <summary>
    /// Converts a meter value to this UOM.
    /// </summary>
    /// <param name="value">The value to convert.</param>
    /// <returns>
    /// The value in this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double FromMeters(double value) const;
    
    /// <summary>
    /// Converts a value in this UOM to meters.
    /// </summary>
    /// <param name="value">The value to convert.</param>
    /// <returns>
    /// The value in meters or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ToMeters(double value) const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISLinearUnit(void* handle);
    ArcGISLinearUnit(const ArcGISLinearUnit&) = delete;
    ArcGISLinearUnit(ArcGISLinearUnit&& other) noexcept;
    ArcGISLinearUnit();
    virtual ~ArcGISLinearUnit() = default;
    
    ArcGISLinearUnit& operator=(const ArcGISLinearUnit&) = delete;
    ArcGISLinearUnit& operator=(ArcGISLinearUnit&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri