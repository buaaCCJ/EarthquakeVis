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

#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationChallenge.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
/// <summary>
/// Authentication challenge for OAuth
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISOAuthAuthenticationChallenge :
    public ArcGISAuthenticationChallenge
{
public:
    #pragma region Properties
    /// <summary>
    /// The current authorization endpoint uri
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAuthorizeURI() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Respond to the challenge with a token
    /// </summary>
    /// <param name="token"></param>
    /// <since>1.0.0</since>
    void Respond(const FString& token);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISOAuthAuthenticationChallenge(void* handle);
    ArcGISOAuthAuthenticationChallenge(const ArcGISOAuthAuthenticationChallenge&) = delete;
    ArcGISOAuthAuthenticationChallenge(ArcGISOAuthAuthenticationChallenge&& other) noexcept;
    ArcGISOAuthAuthenticationChallenge();
    virtual ~ArcGISOAuthAuthenticationChallenge() = default;
    
    ArcGISOAuthAuthenticationChallenge& operator=(const ArcGISOAuthAuthenticationChallenge&) = delete;
    ArcGISOAuthAuthenticationChallenge& operator=(ArcGISOAuthAuthenticationChallenge&& other) = default;
    #pragma endregion Special Members
};
} // namespace Security
} // namespace GameEngine
} // namespace Esri