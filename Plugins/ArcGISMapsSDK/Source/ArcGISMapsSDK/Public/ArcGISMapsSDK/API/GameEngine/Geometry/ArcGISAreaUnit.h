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
enum class ArcGISAreaUnitId;
class ArcGISLinearUnit;

/// <summary>
/// Defines an area unit of measurement.
/// </summary>
/// <remarks>
/// The area unit class is derived from the unit class.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISUnit">ArcGISUnit</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISAreaUnit :
    public ArcGISUnit
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a unit given its known id.
    /// </summary>
    /// <param name="unitId">The known id of the unit.</param>
    /// <since>1.0.0</since>
    ArcGISAreaUnit(ArcGISAreaUnitId unitId);
    
    /// <summary>
    /// Creates an area unit given a linear unit.
    /// </summary>
    /// <remarks>
    /// Creates a unit given a linear unit.
    /// </remarks>
    /// <param name="linearUnit">The linear unit.</param>
    /// <since>1.0.0</since>
    ArcGISAreaUnit(const ArcGISLinearUnit& linearUnit);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The <see cref="Esri::GameEngine::Geometry::ArcGISAreaUnitId">ArcGISAreaUnitId</see> of the given Area unit.
    /// </summary>
    /// <remarks>
    /// If an error occurs then <see cref="Esri::GameEngine::Geometry::ArcGISAreaUnitId.other">ArcGISAreaUnitId.other</see> is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISAreaUnitId GetAreaUnitId() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Converts a value in another UOM into this UOM.
    /// </summary>
    /// <param name="fromUnit">The UOM to convert from.</param>
    /// <param name="area">The value to convert.</param>
    /// <returns>
    /// The value in the this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertFrom(const ArcGISAreaUnit& fromUnit, double area) const;
    
    /// <summary>
    /// Converts a value in this UOM into another UOM.
    /// </summary>
    /// <param name="toUnit">The UOM to convert to.</param>
    /// <param name="area">The value to convert.</param>
    /// <returns>
    /// The value in the target UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertTo(const ArcGISAreaUnit& toUnit, double area) const;
    
    /// <summary>
    /// Converts a square meter value to this UOM.
    /// </summary>
    /// <param name="area">The value to convert.</param>
    /// <returns>
    /// The value in this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double FromSquareMeters(double area) const;
    
    /// <summary>
    /// Converts a value in this UOM to square meters.
    /// </summary>
    /// <param name="area">The value to convert.</param>
    /// <returns>
    /// The value in square meters or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ToSquareMeters(double area) const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISAreaUnit(void* handle);
    ArcGISAreaUnit(const ArcGISAreaUnit&) = delete;
    ArcGISAreaUnit(ArcGISAreaUnit&& other) noexcept;
    ArcGISAreaUnit();
    virtual ~ArcGISAreaUnit() = default;
    
    ArcGISAreaUnit& operator=(const ArcGISAreaUnit&) = delete;
    ArcGISAreaUnit& operator=(ArcGISAreaUnit&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri