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
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationConfiguration.h"
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationConfigurationInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationConfigurationType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationConfiguration.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
ArcGISAuthenticationConfigurationType ArcGISAuthenticationConfigurationInternal::GetObjectType(ArcGISAuthenticationConfiguration* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEAuthenticationConfiguration_getObjectType(reinterpret_cast<RT_GEAuthenticationConfigurationHandle>(self->GetHandle()), &errorHandler);
    
    return static_cast<ArcGISAuthenticationConfigurationType>(localResult);
}
} // namespace Security
} // namespace GameEngine
} // namespace Esri