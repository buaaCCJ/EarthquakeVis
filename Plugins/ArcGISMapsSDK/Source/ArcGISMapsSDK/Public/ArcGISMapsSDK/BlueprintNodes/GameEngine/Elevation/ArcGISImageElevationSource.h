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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSource.h"

#include "ArcGISImageElevationSource.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Elevation
{
class ArcGISImageElevationSource;
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Public class that will contain a tiled image elevation source.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISImageElevationSource :
    public UArcGISElevationSource
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImageElevationSource")
    /// <summary>
    /// Creates a new ElevationSource.
    /// </summary>
    /// <remarks>
    /// Creates a new ElevationSource.
    /// </remarks>
    /// <param name="source">ElevationSource source</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    static UArcGISImageElevationSource* CreateArcGISImageElevationSource(FString source, FString APIKey);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImageElevationSource")
    /// <summary>
    /// Creates a new ElevationSource.
    /// </summary>
    /// <remarks>
    /// Creates a new ElevationSource.
    /// </remarks>
    /// <param name="source">ElevationSource source.</param>
    /// <param name="name">ElevationSource name</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    static UArcGISImageElevationSource* CreateArcGISImageElevationSourceWithName(FString source, FString name, FString APIKey);
    #pragma endregion Constructors
};