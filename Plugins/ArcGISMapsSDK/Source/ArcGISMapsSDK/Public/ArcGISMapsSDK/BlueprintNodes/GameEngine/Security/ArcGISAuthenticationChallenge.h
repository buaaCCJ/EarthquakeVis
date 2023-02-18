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

#include "ArcGISAuthenticationChallenge.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
class ArcGISAuthenticationChallenge;
} // namespace Security
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Authentication challenge
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISAuthenticationChallenge :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISAuthenticationChallenge")
    /// <summary>
    /// Cancels the authentication challenge
    /// </summary>
    /// <since>1.0.0</since>
    void Cancel();
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Security::ArcGISAuthenticationChallenge> APIObject;
};