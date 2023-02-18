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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Extent/ArcGISExtent.h"

#include "ArcGISExtentCircle.generated.h"

class UArcGISPoint;

namespace Esri
{
namespace GameEngine
{
namespace Extent
{
class ArcGISExtentCircle;
} // namespace Extent
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Circle extent
/// </summary>
/// <remarks>
/// Circle extent
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISExtentCircle :
    public UArcGISExtent
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISExtentCircle")
    /// <summary>
    /// Creates an circle extent centered on provided coordinates.
    /// </summary>
    /// <param name="center">Circle center</param>
    /// <param name="radius">Size of radius in meters</param>
    /// <since>1.0.0</since>
    static UArcGISExtentCircle* CreateArcGISExtentCircle(UArcGISPoint* center, double radius);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISExtentCircle")
    /// <summary>
    /// Size of radius in meters
    /// </summary>
    /// <since>1.0.0</since>
    double GetRadius();
    #pragma endregion Properties
};