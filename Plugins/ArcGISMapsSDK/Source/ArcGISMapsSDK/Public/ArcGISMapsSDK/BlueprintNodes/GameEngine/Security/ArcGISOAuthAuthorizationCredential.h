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

#include "ArcGISOAuthAuthorizationCredential.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
class ArcGISOAuthAuthorizationCredential;
} // namespace Security
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A class that contains the OAuth2 authorization credential
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISOAuthAuthorizationCredential :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISOAuthAuthorizationCredential")
    /// <summary>
    /// Creates a credential information object for OAuth 2
    /// </summary>
    /// <param name="accessToken">The access token</param>
    /// <param name="expirationDate">The date and time when the access token will expire.</param>
    /// <param name="refreshToken">The refresh token</param>
    /// <since>1.0.0</since>
    static UArcGISOAuthAuthorizationCredential* CreateArcGISOAuthAuthorizationCredential(FString accessToken, FDateTime expirationDate, FString refreshToken);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISOAuthAuthorizationCredential")
    /// <summary>
    /// The access token
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAccessToken();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISOAuthAuthorizationCredential")
    /// <summary>
    /// The date and time when the access token will expire.
    /// </summary>
    /// <since>1.0.0</since>
    FDateTime GetExpirationDate();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISOAuthAuthorizationCredential")
    /// <summary>
    /// The refresh token
    /// </summary>
    /// <since>1.0.0</since>
    FString GetRefreshToken();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Security::ArcGISOAuthAuthorizationCredential> APIObject;
};