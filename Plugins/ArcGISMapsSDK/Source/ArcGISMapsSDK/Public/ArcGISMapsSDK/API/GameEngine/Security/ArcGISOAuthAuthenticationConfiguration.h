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

#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationConfiguration.h"
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISOAuthAuthorizationCredentialIssuedEvent.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
class ArcGISOAuthAuthorizationCredential;

/// <summary>
/// A class that contains authentication information for OAuth2
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISOAuthAuthenticationConfiguration :
    public ArcGISAuthenticationConfiguration
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a authentication information object for OAuth 2
    /// </summary>
    /// <param name="clientId">The client identifier.</param>
    /// <param name="clientSecret">The client secret. Mandatory for App Login.</param>
    /// <param name="redirectURI">The redirect URI. Mandatory for Named User Login.</param>
    /// <since>1.0.0</since>
    ArcGISOAuthAuthenticationConfiguration(const FString& clientId, const FString& clientSecret, const FString& redirectURI);
    
    /// <summary>
    /// Creates an authentication information object for OAuth 2 including credentials
    /// </summary>
    /// <param name="clientId">The client identifier.</param>
    /// <param name="clientSecret">The client secret. Mandatory for App Login.</param>
    /// <param name="redirectURI">The redirect URI. Mandatory for Named User Login.</param>
    /// <param name="authenticationCredential">The authentication credential.</param>
    /// <since>1.0.0</since>
    ArcGISOAuthAuthenticationConfiguration(const FString& clientId, const FString& clientSecret, const FString& redirectURI, const ArcGISOAuthAuthorizationCredential& authenticationCredential);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The current authorization credential
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISOAuthAuthorizationCredential GetAuthorizationCredential() const;
    
    /// <summary>
    /// The current client id
    /// </summary>
    /// <since>1.0.0</since>
    FString GetClientId() const;
    
    /// <summary>
    /// The current client secret
    /// </summary>
    /// <since>1.0.0</since>
    FString GetClientSecret() const;
    
    /// <summary>
    /// The current redirect uri
    /// </summary>
    /// <since>1.0.0</since>
    FString GetRedirectURI() const;
    #pragma endregion Properties
    
    #pragma region Events
    /// <summary>
    /// Sets the callback invoked when a new OAuth2 authorization credential is issued
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISOAuthAuthorizationCredentialIssuedEvent GetAuthorizationCredentialIssuedEvent() const;
    void SetAuthorizationCredentialIssuedEvent(ArcGISOAuthAuthorizationCredentialIssuedEvent authorizationCredentialIssuedEvent);
    #pragma endregion Events

public:
    #pragma region Special Members
    explicit ArcGISOAuthAuthenticationConfiguration(void* handle);
    ArcGISOAuthAuthenticationConfiguration(const ArcGISOAuthAuthenticationConfiguration&) = delete;
    ArcGISOAuthAuthenticationConfiguration(ArcGISOAuthAuthenticationConfiguration&& other) noexcept;
    ArcGISOAuthAuthenticationConfiguration();
    virtual ~ArcGISOAuthAuthenticationConfiguration();
    
    ArcGISOAuthAuthenticationConfiguration& operator=(const ArcGISOAuthAuthenticationConfiguration&) = delete;
    ArcGISOAuthAuthenticationConfiguration& operator=(ArcGISOAuthAuthenticationConfiguration&& other) noexcept;
    #pragma endregion Special Members

protected:
    ArcGISOAuthAuthorizationCredentialIssuedEvent m_authorizationCredentialIssuedEvent;
};
} // namespace Security
} // namespace GameEngine
} // namespace Esri