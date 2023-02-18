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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Attributes/ArcGISVisualizationAttributeType.h"

#include "ArcGISVisualizationAttribute.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Attributes
{
class ArcGISVisualizationAttribute;
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Information about the visualization attribute
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISVisualizationAttribute :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVisualizationAttribute")
    /// <summary>
    /// The visualization attribute name
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVisualizationAttribute")
    /// <summary>
    /// The type of the attribute.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Attributes::ArcGISVisualizationAttributeType">ArcGISVisualizationAttributeType</seealso>
    /// <since>1.0.0</since>
    EArcGISVisualizationAttributeType::Type GetVisualizationAttributeType();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Attributes::ArcGISVisualizationAttribute> APIObject;
};