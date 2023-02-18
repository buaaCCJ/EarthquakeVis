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

#include "ArcGISMapElevation.generated.h"

class UArcGISElevationSourceCollection;
class UArcGISElevationSource;

namespace Esri
{
namespace GameEngine
{
namespace Map
{
class ArcGISMapElevation;
} // namespace Map
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The map contains elevation sources and additional properties and can be displayed in a ArcGISRenderComponent.
/// </summary>
/// <remarks>
/// The map represent the document with all data that will be renderer by ArcGISRenderComponent.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMapElevation :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapElevation")
    /// <summary>
    /// Create a elevation for the map with no elevation sources
    /// </summary>
    /// <remarks>
    /// Create elevation with no elevation sources
    /// </remarks>
    /// <since>1.0.0</since>
    static UArcGISMapElevation* CreateArcGISMapElevation();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapElevation")
    /// <summary>
    /// Create a elevation for the map with one elevation source
    /// </summary>
    /// <remarks>
    /// Create elevation with a single elevation source
    /// </remarks>
    /// <param name="elevationSource">Elevation source</param>
    /// <since>1.0.0</since>
    static UArcGISMapElevation* CreateArcGISMapElevationWithElevationSource(UArcGISElevationSource* elevationSource);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapElevation")
    /// <summary>
    /// List of elevation sources included on the elevation.
    /// </summary>
    /// <remarks>
    /// At present, the ArcGISElevationSourceCollection may contain a maximum of one elevation source.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISElevationSourceCollection* GetElevationSources();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapElevation")
    /// <summary>
    /// List of elevation sources included on the elevation.
    /// </summary>
    /// <remarks>
    /// At present, the ArcGISElevationSourceCollection may contain a maximum of one elevation source.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetElevationSources(UArcGISElevationSourceCollection* elevationSources);
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Map::ArcGISMapElevation> APIObject;
};