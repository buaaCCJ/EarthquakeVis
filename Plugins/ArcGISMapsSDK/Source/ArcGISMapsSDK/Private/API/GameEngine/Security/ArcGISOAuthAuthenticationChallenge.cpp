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
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISOAuthAuthenticationChallenge.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEOAuthAuthenticationChallenge.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
FString ArcGISOAuthAuthenticationChallenge::GetAuthorizeURI() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEOAuthAuthenticationChallenge_getAuthorizeURI(reinterpret_cast<RT_GEOAuthAuthenticationChallengeHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

void ArcGISOAuthAuthenticationChallenge::Respond(const FString& token)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEOAuthAuthenticationChallenge_respond(reinterpret_cast<RT_GEOAuthAuthenticationChallengeHandle>(GetHandle()), TCHAR_TO_ANSI(*token), &errorHandler);
}

ArcGISOAuthAuthenticationChallenge::ArcGISOAuthAuthenticationChallenge(void* handle) :
    ArcGISAuthenticationChallenge{ handle }
{
}

ArcGISOAuthAuthenticationChallenge::ArcGISOAuthAuthenticationChallenge(ArcGISOAuthAuthenticationChallenge&& other) noexcept :
    ArcGISAuthenticationChallenge{ std::move(other) }
{
}

ArcGISOAuthAuthenticationChallenge::ArcGISOAuthAuthenticationChallenge() :
    ArcGISAuthenticationChallenge{}
{
}
} // namespace Security
} // namespace GameEngine
} // namespace Esri