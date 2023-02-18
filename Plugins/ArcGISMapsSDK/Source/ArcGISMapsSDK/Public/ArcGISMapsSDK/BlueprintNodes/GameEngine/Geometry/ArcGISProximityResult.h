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

#include "ArcGISProximityResult.generated.h"

class UArcGISPoint;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISProximityResult;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The returned results of calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.nearestCoordinate">ArcGISGeometryEngine.nearestCoordinate</see> and <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.nearestVertex">ArcGISGeometryEngine.nearestVertex</see>.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISProximityResult :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISProximityResult")
    /// <summary>
    /// The point found.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetCoordinate();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISProximityResult")
    /// <summary>
    /// The result distance.
    /// </summary>
    /// <since>1.0.0</since>
    double GetDistance();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISProximityResult")
    /// <summary>
    /// The index of the part in which the point was found.
    /// </summary>
    /// <remarks>
    /// Returned index value should be checked against <see cref="">ProximityResult.npos</see> for validity.
    /// </remarks>
    /// <seealso cref="">ProximityResult.npos</seealso>
    /// <since>1.0.0</since>
    int64 GetPartIndex();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISProximityResult")
    /// <summary>
    /// The index of the point that was found within its part.
    /// </summary>
    /// <remarks>
    /// Returned index value should be checked against <see cref="">ProximityResult.npos</see> for validity.
    /// </remarks>
    /// <seealso cref="">ProximityResult.npos</seealso>
    /// <since>1.0.0</since>
    int64 GetPointIndex();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISProximityResult> APIObject;
};