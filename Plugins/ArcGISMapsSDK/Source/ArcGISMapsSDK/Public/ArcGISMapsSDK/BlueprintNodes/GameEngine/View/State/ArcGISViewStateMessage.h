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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewStateMessageType.h"

#include "ArcGISViewStateMessage.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace View
{
namespace State
{
class ArcGISViewStateMessage;
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A view message.
/// </summary>
/// <remarks>
/// This object contains the error or warning message that comes from the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISViewStateMessage :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISViewStateMessage")
    /// <summary>
    /// Retrieve warning or error code.
    /// </summary>
    /// <returns>
    /// The unique code identifies a error or warning.
    /// </returns>
    /// <since>1.0.0</since>
    int32 GetCode() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISViewStateMessage")
    /// <summary>
    /// Retrieve error or warning message if it exists.
    /// </summary>
    /// <returns>
    /// This message contains the error or warning description.
    /// </returns>
    /// <since>1.0.0</since>
    FString GetMessage() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISViewStateMessage")
    /// <summary>
    /// Retrieve the message type
    /// </summary>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISViewStateMessageType">ArcGISViewStateMessageType</see>
    /// </returns>
    /// <since>1.0.0</since>
    EArcGISViewStateMessageType::Type GetMessageType() const;
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::View::State::ArcGISViewStateMessage> APIObject;
};