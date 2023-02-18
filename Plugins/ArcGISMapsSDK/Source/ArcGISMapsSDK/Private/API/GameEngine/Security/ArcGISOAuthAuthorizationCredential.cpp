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
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISOAuthAuthorizationCredential.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthorizationCredential.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
ArcGISOAuthAuthorizationCredential::ArcGISOAuthAuthorizationCredential(const FString& accessToken, const FDateTime& expirationDate, const FString& refreshToken)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localExpirationDate = RT_DateTime_fromUnixMilliseconds(expirationDate.ToUnixTimestamp(), &errorHandler);
    
    SetHandle(RT_GEOAuthAuthorizationCredential_create(TCHAR_TO_ANSI(*accessToken), localExpirationDate, TCHAR_TO_ANSI(*refreshToken), &errorHandler));
    
    RT_DateTime_destroy(localExpirationDate, &errorHandler);
}

FString ArcGISOAuthAuthorizationCredential::GetAccessToken() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEOAuthAuthorizationCredential_getAccessToken(reinterpret_cast<RT_GEOAuthAuthorizationCredentialHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FDateTime ArcGISOAuthAuthorizationCredential::GetExpirationDate() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEOAuthAuthorizationCredential_getExpirationDate(reinterpret_cast<RT_GEOAuthAuthorizationCredentialHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FDateTime{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FDateTime::FromUnixTimestamp(RT_DateTime_toUnixMilliseconds(localResult, &errorHandler) / 1000);
        RT_DateTime_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISOAuthAuthorizationCredential::GetRefreshToken() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEOAuthAuthorizationCredential_getRefreshToken(reinterpret_cast<RT_GEOAuthAuthorizationCredentialHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISOAuthAuthorizationCredential::ArcGISOAuthAuthorizationCredential(void* handle) :
    m_handle{ handle }
{
}

ArcGISOAuthAuthorizationCredential::ArcGISOAuthAuthorizationCredential(ArcGISOAuthAuthorizationCredential&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISOAuthAuthorizationCredential::~ArcGISOAuthAuthorizationCredential()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEOAuthAuthorizationCredential_destroy(reinterpret_cast<RT_GEOAuthAuthorizationCredentialHandle>(m_handle), &errorHandler);
    }
}

ArcGISOAuthAuthorizationCredential& ArcGISOAuthAuthorizationCredential::operator=(ArcGISOAuthAuthorizationCredential&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISOAuthAuthorizationCredential::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISOAuthAuthorizationCredential::GetHandle() const
{
    return m_handle;
}
void ArcGISOAuthAuthorizationCredential::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Security
} // namespace GameEngine
} // namespace Esri