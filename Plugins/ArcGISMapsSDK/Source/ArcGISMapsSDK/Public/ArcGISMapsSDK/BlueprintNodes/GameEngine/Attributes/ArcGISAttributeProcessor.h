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

#include "ArcGISAttributeProcessor.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Attributes
{
class ArcGISAttributeProcessor;
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Provides access to the <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessorEvent">ArcGISAttributeProcessorEvent</see>
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISAttributeProcessor :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAttributeProcessor")
    /// <summary>
    /// Creates an attribute processor object.
    /// </summary>
    /// <since>1.0.0</since>
    static UArcGISAttributeProcessor* CreateArcGISAttributeProcessor();
    #pragma endregion Constructors

public:
    TSharedPtr<Esri::GameEngine::Attributes::ArcGISAttributeProcessor> APIObject;
};