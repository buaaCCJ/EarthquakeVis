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
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationChallengeInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationChallengeType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationChallenge.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
ArcGISAuthenticationChallengeType ArcGISAuthenticationChallengeInternal::GetObjectType(ArcGISAuthenticationChallenge* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEAuthenticationChallenge_getObjectType(reinterpret_cast<RT_GEAuthenticationChallengeHandle>(self->GetHandle()), &errorHandler);
    
    return static_cast<ArcGISAuthenticationChallengeType>(localResult);
}
} // namespace Security
} // namespace GameEngine
} // namespace Esri