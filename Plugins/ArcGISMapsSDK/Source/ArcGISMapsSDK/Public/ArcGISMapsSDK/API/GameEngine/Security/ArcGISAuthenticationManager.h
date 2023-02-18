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

#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationChallengeIssuedEvent.h"

namespace Esri
{
namespace Unreal
{
template<typename Key, typename Value> class ArcGISDictionary;
template<typename T> class ArcGISFuture;
} // namespace Unreal

namespace GameEngine
{
namespace Security
{
class ArcGISAuthenticationConfiguration;

/// <summary>
/// A class to manage authentication
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISAuthenticationManager
{
public:
    #pragma region Properties
    /// <summary>
    /// The authentication configurations for URLs.
    /// </summary>
    /// <since>1.0.0</since>
    static Unreal::ArcGISDictionary<FString, ArcGISAuthenticationConfiguration> GetAuthenticationConfigurations();
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Starts the authorization flow on the provided authentication configuration
    /// </summary>
    /// <remarks>
    /// The URL should include the `/sharing/rest` fragment.
    /// The provided authentication configuration won't be considered for requests authentication
    /// unless it gets manually added to <see cref="Esri::GameEngine::Security::ArcGISAuthenticationManager.authenticationConfigurations">ArcGISAuthenticationManager.authenticationConfigurations</see>.
    /// </remarks>
    /// <param name="restEndpointURL">The REST endpoint URL of the portal.</param>
    /// <param name="authenticationConfiguration">The authentication configuration to get authorized</param>
    /// <returns>
    /// A <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> that has no return value.
    /// </returns>
    /// <since>1.0.0</since>
    static Unreal::ArcGISFuture<void> AuthorizeAuthenticationConfigurationAsync(const FString& restEndpointURL, const ArcGISAuthenticationConfiguration& authenticationConfiguration);
    #pragma endregion Methods
    
    #pragma region Events
    /// <summary>
    /// Sets the global callback invoked when an authentication challenge is issued
    /// </summary>
    /// <since>1.0.0</since>
    static ArcGISAuthenticationChallengeIssuedEvent GetAuthenticationChallengeIssued();
    static void SetAuthenticationChallengeIssued(ArcGISAuthenticationChallengeIssuedEvent authenticationChallengeIssued);
    #pragma endregion Events
};
} // namespace Security
} // namespace GameEngine
} // namespace Esri