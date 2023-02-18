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

namespace Esri
{
namespace GameEngine
{
namespace Security
{
/// <summary>
/// A class that contains the OAuth2 authorization credential
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISOAuthAuthorizationCredential
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a credential information object for OAuth 2
    /// </summary>
    /// <param name="accessToken">The access token</param>
    /// <param name="expirationDate">The date and time when the access token will expire.</param>
    /// <param name="refreshToken">The refresh token</param>
    /// <since>1.0.0</since>
    ArcGISOAuthAuthorizationCredential(const FString& accessToken, const FDateTime& expirationDate, const FString& refreshToken);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The access token
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAccessToken() const;
    
    /// <summary>
    /// The date and time when the access token will expire.
    /// </summary>
    /// <since>1.0.0</since>
    FDateTime GetExpirationDate() const;
    
    /// <summary>
    /// The refresh token
    /// </summary>
    /// <since>1.0.0</since>
    FString GetRefreshToken() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISOAuthAuthorizationCredential(void* handle);
    ArcGISOAuthAuthorizationCredential(const ArcGISOAuthAuthorizationCredential&) = delete;
    ArcGISOAuthAuthorizationCredential(ArcGISOAuthAuthorizationCredential&& other) noexcept;
    ArcGISOAuthAuthorizationCredential() = default;
    ~ArcGISOAuthAuthorizationCredential();
    
    ArcGISOAuthAuthorizationCredential& operator=(const ArcGISOAuthAuthorizationCredential&) = delete;
    ArcGISOAuthAuthorizationCredential& operator=(ArcGISOAuthAuthorizationCredential&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Security
} // namespace GameEngine
} // namespace Esri