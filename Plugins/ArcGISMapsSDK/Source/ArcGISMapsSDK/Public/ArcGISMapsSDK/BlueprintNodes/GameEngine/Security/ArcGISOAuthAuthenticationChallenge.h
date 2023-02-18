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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Security/ArcGISAuthenticationChallenge.h"

#include "ArcGISOAuthAuthenticationChallenge.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
class ArcGISOAuthAuthenticationChallenge;
} // namespace Security
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Authentication challenge for OAuth
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISOAuthAuthenticationChallenge :
    public UArcGISAuthenticationChallenge
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISOAuthAuthenticationChallenge")
    /// <summary>
    /// The current authorization endpoint uri
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAuthorizeURI();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISOAuthAuthenticationChallenge")
    /// <summary>
    /// Respond to the challenge with a token
    /// </summary>
    /// <param name="token"></param>
    /// <since>1.0.0</since>
    void Respond(FString token);
    #pragma endregion Methods
};