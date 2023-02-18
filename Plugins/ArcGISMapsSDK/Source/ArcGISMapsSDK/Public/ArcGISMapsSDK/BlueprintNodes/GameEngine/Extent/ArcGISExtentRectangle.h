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

#include "ArcGISExtentRectangle.generated.h"

class UArcGISPoint;

namespace Esri
{
namespace GameEngine
{
namespace Extent
{
class ArcGISExtentRectangle;
} // namespace Extent
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Rectangle extent
/// </summary>
/// <remarks>
/// Rectangle extent
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISExtentRectangle :
    public UArcGISExtent
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISExtentRectangle")
    /// <summary>
    /// Creates an rectangle extent centered on provided coordinates.
    /// </summary>
    /// <param name="center">Rectangle center</param>
    /// <param name="width">Side length along the east-to-west axis, in meters</param>
    /// <param name="height">Side length along the north-to-south axis, in meters</param>
    /// <since>1.0.0</since>
    static UArcGISExtentRectangle* CreateArcGISExtentRectangle(UArcGISPoint* center, double width, double height);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISExtentRectangle")
    /// <summary>
    /// Side length along the north-to-south axis, in meters
    /// </summary>
    /// <since>1.0.0</since>
    double GetHeight();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISExtentRectangle")
    /// <summary>
    /// Side length along the east-to-west axis, in meters
    /// </summary>
    /// <since>1.0.0</since>
    double GetWidth();
    #pragma endregion Properties
};