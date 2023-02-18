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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISElevationSourceViewStatus.h"

#include "ArcGISElevationSourceViewState.generated.h"

class UArcGISViewStateMessage;

namespace Esri
{
namespace GameEngine
{
namespace View
{
namespace State
{
class ArcGISElevationSourceViewState;
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A elevation source view state object.
/// </summary>
/// <remarks>
/// This object allows you to know the current state of a elevation source in a view.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISElevationSourceViewState :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSourceViewState")
    /// <summary>
    /// Retrieve the message if it exists.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewState">ArcGISElevationSourceViewState</seealso>
    /// <since>1.0.0</since>
    UArcGISViewStateMessage* GetMessage();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSourceViewState")
    /// <summary>
    /// Retrieve the elevation source status.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus">ArcGISElevationSourceViewStatus</seealso>
    /// <since>1.0.0</since>
    EArcGISElevationSourceViewStatus::Type GetStatus();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::View::State::ArcGISElevationSourceViewState> APIObject;
};