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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISRuntimeEnvironment.h"
#include "ArcGISMapsSDK/API/GameEngine/ArcGISRuntimeEnvironmentInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Standard/ArcGISRuntimeClient.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISException.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/ArcGISRuntimeEnvironment.h"

namespace Esri
{
namespace GameEngine
{
bool ArcGISRuntimeEnvironmentInternal::GetUseCoreAuthentication()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ArcGISRuntimeEnvironment_getUseCoreAuthentication(&errorHandler);
    
    return localResult;
}
void ArcGISRuntimeEnvironmentInternal::SetUseCoreAuthentication(bool useCoreAuthentication)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setUseCoreAuthentication(useCoreAuthentication, &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::EnableBreakOnException(bool enable)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_enableBreakOnException(enable, &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::EnableLeakDetection(bool enable)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_enableLeakDetection(enable, &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::EnableRaiseAssertion(bool enable)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_enableRaiseAssertion(enable, &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::EnableShowAssertDialog(bool enable)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_enableShowAssertDialog(enable, &errorHandler);
}

FString ArcGISRuntimeEnvironmentInternal::GetFeatureToggleDirectory()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ArcGISRuntimeEnvironment_getFeatureToggleDirectory(&errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

bool ArcGISRuntimeEnvironmentInternal::IsFeatureEnabled(const FString& featureToggle)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ArcGISRuntimeEnvironment_isFeatureEnabled(TCHAR_TO_ANSI(*featureToggle), &errorHandler);
    
    return localResult;
}

void ArcGISRuntimeEnvironmentInternal::SetBetaWatermark(bool set)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setBetaWatermark(set, &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::SetFeatureToggleDirectory(const FString& featureToggleDirectory)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setFeatureToggleDirectory(TCHAR_TO_ANSI(*featureToggleDirectory), &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::SetInstallDirectory(const FString& installPath)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setInstallDirectory(TCHAR_TO_ANSI(*installPath), &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::SetProductInfo(const FString& name, const FString& version)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setProductInfo(TCHAR_TO_ANSI(*name), TCHAR_TO_ANSI(*version), &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::SetResourcesDirectory(const FString& resourcesPath)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setResourcesDirectory(TCHAR_TO_ANSI(*resourcesPath), &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::SetRuntimeClient(Standard::ArcGISRuntimeClient runtimeClient, const FString& version)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setRuntimeClient(static_cast<RT_RuntimeClient>(runtimeClient), TCHAR_TO_ANSI(*version), &errorHandler);
}

void ArcGISRuntimeEnvironmentInternal::SetTempDirectory(const FString& tempPath)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_ArcGISRuntimeEnvironment_setTempDirectory(TCHAR_TO_ANSI(*tempPath), &errorHandler);
}

static ArcGISRuntimeEnvironmentErrorEvent m_error;

ArcGISRuntimeEnvironmentErrorEvent ArcGISRuntimeEnvironmentInternal::GetError()
{
    return m_error;
}
void ArcGISRuntimeEnvironmentInternal::SetError(ArcGISRuntimeEnvironmentErrorEvent error)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_error = std::move(error);
    
    static auto callbackHandler = [](void* userData, RT_ErrorHandle error_)
    {
        auto callback = ArcGISRuntimeEnvironmentInternal::GetError();
        
        if (!callback)
        {
            return;
        }
        
        auto localError = Unreal::ArcGISException{};
        
        if (error_ != nullptr)
        {
            localError = Unreal::ArcGISException{ error_ };
        }
        
        callback(localError);
    };
    
    if (m_error)
    {
        RT_ArcGISRuntimeEnvironment_setErrorCallback(callbackHandler, nullptr, &errorHandler);
    }
    else
    {
        RT_ArcGISRuntimeEnvironment_setErrorCallback(nullptr, nullptr, &errorHandler);
    }
}
} // namespace GameEngine
} // namespace Esri