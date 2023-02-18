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

#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationChallengeIssuedEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationConfigurationHandle.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationManagerHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/DictionaryHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/FutureHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

RT_DictionaryHandle RT_GEAuthenticationManager_getAuthenticationConfigurations(const RT_ErrorHandler* errorHandler);

RT_TaskHandle RT_GEAuthenticationManager_authorizeAuthenticationConfigurationAsync(const char* restEndpointURL, const RT_GEAuthenticationConfigurationHandle authenticationConfiguration, const RT_ErrorHandler* errorHandler);

void RT_GEAuthenticationManager_setAuthenticationChallengeIssuedCallback(RT_GEAuthenticationChallenge_issued_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif