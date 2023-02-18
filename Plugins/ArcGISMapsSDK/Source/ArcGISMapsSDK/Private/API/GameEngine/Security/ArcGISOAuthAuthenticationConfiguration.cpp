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
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISOAuthAuthenticationConfiguration.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISOAuthAuthorizationCredential.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthenticationConfiguration.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
ArcGISOAuthAuthenticationConfiguration::ArcGISOAuthAuthenticationConfiguration(const FString& clientId, const FString& clientSecret, const FString& redirectURI) :
    ArcGISAuthenticationConfiguration{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEOAuthAuthenticationConfiguration_create(TCHAR_TO_ANSI(*clientId), TCHAR_TO_ANSI(*clientSecret), TCHAR_TO_ANSI(*redirectURI), &errorHandler));
}

ArcGISOAuthAuthenticationConfiguration::ArcGISOAuthAuthenticationConfiguration(const FString& clientId, const FString& clientSecret, const FString& redirectURI, const ArcGISOAuthAuthorizationCredential& authenticationCredential) :
    ArcGISAuthenticationConfiguration{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localAuthenticationCredential = static_cast<const RT_GEOAuthAuthorizationCredentialHandle>(authenticationCredential.GetHandle());
    
    SetHandle(RT_GEOAuthAuthenticationConfiguration_createWithCredential(TCHAR_TO_ANSI(*clientId), TCHAR_TO_ANSI(*clientSecret), TCHAR_TO_ANSI(*redirectURI), localAuthenticationCredential, &errorHandler));
}

ArcGISOAuthAuthorizationCredential ArcGISOAuthAuthenticationConfiguration::GetAuthorizationCredential() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEOAuthAuthenticationConfiguration_getAuthorizationCredential(reinterpret_cast<RT_GEOAuthAuthenticationConfigurationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISOAuthAuthorizationCredential{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISOAuthAuthorizationCredential{ localResult };
    }
    
    return localLocalResult;
}

FString ArcGISOAuthAuthenticationConfiguration::GetClientId() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEOAuthAuthenticationConfiguration_getClientId(reinterpret_cast<RT_GEOAuthAuthenticationConfigurationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISOAuthAuthenticationConfiguration::GetClientSecret() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEOAuthAuthenticationConfiguration_getClientSecret(reinterpret_cast<RT_GEOAuthAuthenticationConfigurationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISOAuthAuthenticationConfiguration::GetRedirectURI() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEOAuthAuthenticationConfiguration_getRedirectURI(reinterpret_cast<RT_GEOAuthAuthenticationConfigurationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISOAuthAuthorizationCredentialIssuedEvent ArcGISOAuthAuthenticationConfiguration::GetAuthorizationCredentialIssuedEvent() const
{
    return m_authorizationCredentialIssuedEvent;
}
void ArcGISOAuthAuthenticationConfiguration::SetAuthorizationCredentialIssuedEvent(ArcGISOAuthAuthorizationCredentialIssuedEvent authorizationCredentialIssuedEvent)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_authorizationCredentialIssuedEvent = std::move(authorizationCredentialIssuedEvent);
    
    static auto callbackHandler = [](void* userData, RT_GEOAuthAuthorizationCredentialHandle authorizationCredential_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISOAuthAuthenticationConfiguration*>(userData);
        
        auto callback = callbackObject->GetAuthorizationCredentialIssuedEvent();
        
        if (!callback)
        {
            return;
        }
        
        auto localAuthorizationCredential = ArcGISOAuthAuthorizationCredential{};
        
        if (authorizationCredential_ != nullptr)
        {
            localAuthorizationCredential = ArcGISOAuthAuthorizationCredential{ authorizationCredential_ };
        }
        
        callback(localAuthorizationCredential);
    };
    
    if (m_authorizationCredentialIssuedEvent)
    {
        RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback(reinterpret_cast<RT_GEOAuthAuthenticationConfigurationHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback(reinterpret_cast<RT_GEOAuthAuthenticationConfigurationHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISOAuthAuthenticationConfiguration::ArcGISOAuthAuthenticationConfiguration(void* handle) :
    ArcGISAuthenticationConfiguration{ handle }
{
}

ArcGISOAuthAuthenticationConfiguration::ArcGISOAuthAuthenticationConfiguration(ArcGISOAuthAuthenticationConfiguration&& other) noexcept :
    ArcGISAuthenticationConfiguration{ std::move(other) },
    m_authorizationCredentialIssuedEvent{ std::move(other.m_authorizationCredentialIssuedEvent) }
{
}

ArcGISOAuthAuthenticationConfiguration::ArcGISOAuthAuthenticationConfiguration() :
    ArcGISAuthenticationConfiguration{}
{
}

ArcGISOAuthAuthenticationConfiguration::~ArcGISOAuthAuthenticationConfiguration()
{
    if (m_handle)
    {
        if (m_authorizationCredentialIssuedEvent)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEOAuthAuthenticationConfiguration_setAuthorizationCredentialIssuedEventCallback(reinterpret_cast<RT_GEOAuthAuthenticationConfigurationHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
    }
}

ArcGISOAuthAuthenticationConfiguration& ArcGISOAuthAuthenticationConfiguration::operator=(ArcGISOAuthAuthenticationConfiguration&& other) noexcept
{
    if (this != &other)
    {
        ArcGISAuthenticationConfiguration::operator=(std::move(other));
        
        using std::swap;
        
        swap(m_authorizationCredentialIssuedEvent, other.m_authorizationCredentialIssuedEvent);
    }
    
    return *this;
}
} // namespace Security
} // namespace GameEngine
} // namespace Esri