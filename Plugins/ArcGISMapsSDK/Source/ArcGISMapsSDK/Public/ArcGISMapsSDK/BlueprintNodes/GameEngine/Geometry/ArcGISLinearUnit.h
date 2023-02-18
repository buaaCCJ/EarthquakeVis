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

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnitId.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISUnit.h"

#include "ArcGISLinearUnit.generated.h"

class UArcGISAreaUnit;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISLinearUnit;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Defines a linear unit of measurement.
/// </summary>
/// <remarks>
/// The linear unit class is derived from the unit class.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISUnit">ArcGISUnit</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISLinearUnit :
    public UArcGISUnit
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLinearUnit")
    /// <summary>
    /// Creates an linear unit given an area unit.
    /// </summary>
    /// <remarks>
    /// Creates a unit given an area unit.
    /// </remarks>
    /// <param name="areaUnit">The area unit.</param>
    /// <since>1.0.0</since>
    static UArcGISLinearUnit* CreateArcGISLinearUnitFromAreaUnit(UArcGISAreaUnit* areaUnit);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLinearUnit")
    /// <summary>
    /// Creates a unit given its known id.
    /// </summary>
    /// <param name="unitId">The known id of the unit.</param>
    /// <since>1.0.0</since>
    static UArcGISLinearUnit* CreateArcGISLinearUnit(EArcGISLinearUnitId::Type unitId);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLinearUnit")
    /// <summary>
    /// The <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnitId">ArcGISLinearUnitId</see> of the given Linear unit.
    /// </summary>
    /// <remarks>
    /// If an error occurs then <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnitId.other">ArcGISLinearUnitId.other</see> is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    EArcGISLinearUnitId::Type GetLinearUnitId();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLinearUnit")
    /// <summary>
    /// Converts a value in another UOM into this UOM.
    /// </summary>
    /// <param name="fromUnit">The UOM to convert from.</param>
    /// <param name="value">The value to convert.</param>
    /// <returns>
    /// The value in this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertFrom(UArcGISLinearUnit* fromUnit, double value) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLinearUnit")
    /// <summary>
    /// Converts a value in this UOM into another UOM.
    /// </summary>
    /// <param name="toUnit">The UOM to convert to.</param>
    /// <param name="value">The value to convert.</param>
    /// <returns>
    /// The value in the target UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertTo(UArcGISLinearUnit* toUnit, double value) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLinearUnit")
    /// <summary>
    /// Converts a meter value to this UOM.
    /// </summary>
    /// <param name="value">The value to convert.</param>
    /// <returns>
    /// The value in this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double FromMeters(double value) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLinearUnit")
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
};