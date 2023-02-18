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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewStatus.h"

#include "ArcGISViewState.generated.h"

class UArcGISViewStateMessage;

namespace Esri
{
namespace GameEngine
{
namespace View
{
namespace State
{
class ArcGISViewState;
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A view state object.
/// </summary>
/// <remarks>
/// This object contains the current state of the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISViewState :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISViewState")
    /// <summary>
    /// Retrieve the message if it exists.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISViewState">ArcGISViewState</seealso>
    /// <since>1.0.0</since>
    UArcGISViewStateMessage* GetMessage();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISViewState")
    /// <summary>
    /// Retrieve the renderer view status.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISViewStatus">ArcGISViewStatus</seealso>
    /// <since>1.0.0</since>
    EArcGISViewStatus::Type GetStatus();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::View::State::ArcGISViewState> APIObject;
};