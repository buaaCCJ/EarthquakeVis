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
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationChallenge.h"
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationConfiguration.h"
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationManager.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISOAuthAuthenticationChallenge.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISDictionary.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISFuture.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationChallenge.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationManager.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
Unreal::ArcGISDictionary<FString, ArcGISAuthenticationConfiguration> ArcGISAuthenticationManager::GetAuthenticationConfigurations()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEAuthenticationManager_getAuthenticationConfigurations(&errorHandler);
    
    auto localLocalResult = Unreal::ArcGISDictionary<FString, ArcGISAuthenticationConfiguration>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISDictionary<FString, ArcGISAuthenticationConfiguration>{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISFuture<void> ArcGISAuthenticationManager::AuthorizeAuthenticationConfigurationAsync(const FString& restEndpointURL, const ArcGISAuthenticationConfiguration& authenticationConfiguration)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localAuthenticationConfiguration = static_cast<const RT_GEAuthenticationConfigurationHandle>(authenticationConfiguration.GetHandle());
    
    auto localResult = RT_GEAuthenticationManager_authorizeAuthenticationConfigurationAsync(TCHAR_TO_ANSI(*restEndpointURL), localAuthenticationConfiguration, &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISFuture<void>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISFuture<void>{ localResult };
    }
    
    return localLocalResult;
}

static ArcGISAuthenticationChallengeIssuedEvent m_authenticationChallengeIssued;

ArcGISAuthenticationChallengeIssuedEvent ArcGISAuthenticationManager::GetAuthenticationChallengeIssued()
{
    return m_authenticationChallengeIssued;
}
void ArcGISAuthenticationManager::SetAuthenticationChallengeIssued(ArcGISAuthenticationChallengeIssuedEvent authenticationChallengeIssued)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_authenticationChallengeIssued = std::move(authenticationChallengeIssued);
    
    static auto callbackHandler = [](void* userData, RT_GEAuthenticationChallengeHandle authenticationChallenge_)
    {
        auto callback = ArcGISAuthenticationManager::GetAuthenticationChallengeIssued();
        
        if (!callback)
        {
            return;
        }
        
        auto localAuthenticationChallenge = ArcGISAuthenticationChallenge{};
        
        if (authenticationChallenge_ != nullptr)
        {
            auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
            
            auto objectType = RT_GEAuthenticationChallenge_getObjectType(authenticationChallenge_, &objectTypeErrorHandler);
            
            switch (objectType)
            {
                case RT_GEAuthenticationChallengeType_GEOAuthAuthenticationChallenge:
                    localAuthenticationChallenge = ArcGISOAuthAuthenticationChallenge{ authenticationChallenge_ };
                    break;
                default:
                    localAuthenticationChallenge = ArcGISAuthenticationChallenge{ authenticationChallenge_ };
                    break;
            }
        }
        
        callback(localAuthenticationChallenge);
    };
    
    if (m_authenticationChallengeIssued)
    {
        RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback(callbackHandler, nullptr, &errorHandler);
    }
    else
    {
        RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback(nullptr, nullptr, &errorHandler);
    }
}
} // namespace Security
} // namespace GameEngine
} // namespace Esri