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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAreaUnitId.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISUnit.h"

#include "ArcGISAreaUnit.generated.h"

class UArcGISLinearUnit;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISAreaUnit;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Defines an area unit of measurement.
/// </summary>
/// <remarks>
/// The area unit class is derived from the unit class.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISUnit">ArcGISUnit</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISAreaUnit :
    public UArcGISUnit
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAreaUnit")
    /// <summary>
    /// Creates a unit given its known id.
    /// </summary>
    /// <param name="unitId">The known id of the unit.</param>
    /// <since>1.0.0</since>
    static UArcGISAreaUnit* CreateArcGISAreaUnit(EArcGISAreaUnitId::Type unitId);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAreaUnit")
    /// <summary>
    /// Creates an area unit given a linear unit.
    /// </summary>
    /// <remarks>
    /// Creates a unit given a linear unit.
    /// </remarks>
    /// <param name="linearUnit">The linear unit.</param>
    /// <since>1.0.0</since>
    static UArcGISAreaUnit* CreateArcGISAreaUnitFromLinearUnit(UArcGISLinearUnit* linearUnit);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAreaUnit")
    /// <summary>
    /// The <see cref="Esri::GameEngine::Geometry::ArcGISAreaUnitId">ArcGISAreaUnitId</see> of the given Area unit.
    /// </summary>
    /// <remarks>
    /// If an error occurs then <see cref="Esri::GameEngine::Geometry::ArcGISAreaUnitId.other">ArcGISAreaUnitId.other</see> is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    EArcGISAreaUnitId::Type GetAreaUnitId();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAreaUnit")
    /// <summary>
    /// Converts a value in another UOM into this UOM.
    /// </summary>
    /// <param name="fromUnit">The UOM to convert from.</param>
    /// <param name="area">The value to convert.</param>
    /// <returns>
    /// The value in the this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertFrom(UArcGISAreaUnit* fromUnit, double area) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAreaUnit")
    /// <summary>
    /// Converts a value in this UOM into another UOM.
    /// </summary>
    /// <param name="toUnit">The UOM to convert to.</param>
    /// <param name="area">The value to convert.</param>
    /// <returns>
    /// The value in the target UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertTo(UArcGISAreaUnit* toUnit, double area) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAreaUnit")
    /// <summary>
    /// Converts a square meter value to this UOM.
    /// </summary>
    /// <param name="area">The value to convert.</param>
    /// <returns>
    /// The value in this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double FromSquareMeters(double area) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAreaUnit")
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
};