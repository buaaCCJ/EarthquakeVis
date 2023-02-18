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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAngularUnitId.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISUnit.h"

#include "ArcGISAngularUnit.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISAngularUnit;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Defines an angular unit of measurement.
/// </summary>
/// <remarks>
/// The angular unit class is derived from the unit class.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISUnit">ArcGISUnit</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISAngularUnit :
    public UArcGISUnit
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAngularUnit")
    /// <summary>
    /// Creates a unit given its known id.
    /// </summary>
    /// <param name="unitId">The known id of the unit.</param>
    /// <since>1.0.0</since>
    static UArcGISAngularUnit* CreateArcGISAngularUnit(EArcGISAngularUnitId::Type unitId);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAngularUnit")
    /// <summary>
    /// The <see cref="Esri::GameEngine::Geometry::ArcGISAngularUnitId">ArcGISAngularUnitId</see> of the given angular unit.
    /// </summary>
    /// <remarks>
    /// If an error occurs then <see cref="Esri::GameEngine::Geometry::ArcGISAngularUnitId.other">ArcGISAngularUnitId.other</see> is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    EArcGISAngularUnitId::Type GetAngularUnitId();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAngularUnit")
    /// <summary>
    /// Converts a value in another UOM into this UOM.
    /// </summary>
    /// <param name="fromUnit">The UOM to convert from.</param>
    /// <param name="angle">The value to convert.</param>
    /// <returns>
    /// The value in the this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertFrom(UArcGISAngularUnit* fromUnit, double angle) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAngularUnit")
    /// <summary>
    /// Converts a value in this UOM into another UOM.
    /// </summary>
    /// <param name="toUnit">The UOM to convert to.</param>
    /// <param name="angle">The value to convert.</param>
    /// <returns>
    /// The value in the target UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double ConvertTo(UArcGISAngularUnit* toUnit, double angle) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAngularUnit")
    /// <summary>
    /// Converts a radian value to this UOM.
    /// </summary>
    /// <param name="radians">The value to convert.</param>
    /// <returns>
    /// The value in this UOM or NAN if the conversion fails.
    /// </returns>
    /// <since>1.0.0</since>
    double FromRadians(double radians) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAngularUnit")
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
};