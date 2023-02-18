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

#include "ArcGISVisualizationAttributeDescription.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Attributes
{
class ArcGISVisualizationAttributeDescription;
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Describes how the visualization attributes are provided to <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessorEvent">ArcGISAttributeProcessorEvent</see>
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISVisualizationAttributeDescription :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVisualizationAttributeDescription")
    /// <summary>
    /// Creates a VisualizationAttributeDescription object.
    /// </summary>
    /// <param name="name">The attribute name</param>
    /// <param name="visualizationAttributeType">The type of the visualization attribute.</param>
    /// <since>1.0.0</since>
    static UArcGISVisualizationAttributeDescription* CreateArcGISVisualizationAttributeDescription(FString name, EArcGISVisualizationAttributeType::Type visualizationAttributeType);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVisualizationAttributeDescription")
    /// <summary>
    /// The attribute name
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVisualizationAttributeDescription")
    /// <summary>
    /// The type of the visualization attribute.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Attributes::ArcGISVisualizationAttributeType">ArcGISVisualizationAttributeType</seealso>
    /// <since>1.0.0</since>
    EArcGISVisualizationAttributeType::Type GetVisualizationAttributeType();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Attributes::ArcGISVisualizationAttributeDescription> APIObject;
};