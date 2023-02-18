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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISRuntimeEnvironment.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/ArcGISRuntimeEnvironment.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
FString ArcGISRuntimeEnvironment::GetAPIKey()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ArcGISRuntimeEnvironment_getAPIKey(&errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}
void ArcGISRuntimeEnvironment::SetAPIKey(const FString& APIKey)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setAPIKey(TCHAR_TO_ANSI(*APIKey), &errorHandler);
}
} // namespace GameEngine
} // namespace Esri