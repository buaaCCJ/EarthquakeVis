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
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISOAuthAuthorizationCredential.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Security/ArcGISOAuthAuthorizationCredential.h" // IWYU pragma: associated

UArcGISOAuthAuthorizationCredential* UArcGISOAuthAuthorizationCredential::CreateArcGISOAuthAuthorizationCredential(FString accessToken, FDateTime expirationDate, FString refreshToken)
{
    auto result = NewObject<UArcGISOAuthAuthorizationCredential>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Security::ArcGISOAuthAuthorizationCredential>(accessToken, expirationDate, refreshToken);
    
    return result;
}

FString UArcGISOAuthAuthorizationCredential::GetAccessToken()
{
    auto localResult = APIObject->GetAccessToken();
    
    return localResult;
}

FDateTime UArcGISOAuthAuthorizationCredential::GetExpirationDate()
{
    auto localResult = APIObject->GetExpirationDate();
    
    return localResult;
}

FString UArcGISOAuthAuthorizationCredential::GetRefreshToken()
{
    auto localResult = APIObject->GetRefreshToken();
    
    return localResult;
}