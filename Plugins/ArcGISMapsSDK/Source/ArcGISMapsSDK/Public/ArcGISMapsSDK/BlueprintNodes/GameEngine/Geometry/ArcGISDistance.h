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

#include "ArcGISDistance.generated.h"

class UArcGISLinearUnit;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISDistance;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// <see cref="Esri::GameEngine::Geometry::ArcGISDistance">ArcGISDistance</see> holds the distance measurement data associated with a specific distance component.
/// </summary>
/// <remarks>
/// Distance contains the value and associated <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnit">ArcGISLinearUnit</see> of a specific distance component.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISLinearUnit">ArcGISLinearUnit</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISDistance :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISDistance")
    /// <summary>
    /// The unit of the Distance component.
    /// </summary>
    /// <remarks>
    /// Unit is the linear unit by which the value of the distance is measured.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISLinearUnit* GetUnit();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISDistance")
    /// <summary>
    /// The value of the Distance component.
    /// </summary>
    /// <remarks>
    /// Value is the scalar value of the distance, measured by the associated Distance Unit. Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetValue();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISDistance> APIObject;
};