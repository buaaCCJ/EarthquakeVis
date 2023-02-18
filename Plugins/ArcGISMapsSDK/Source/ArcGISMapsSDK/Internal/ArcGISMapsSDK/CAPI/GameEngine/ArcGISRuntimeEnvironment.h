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

#include "ArcGISMapsSDK/CAPI/GameEngine/ArcGISRuntimeEnvironmentErrorEvent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/ArcGISRuntimeEnvironmentHandle.h"
#include "ArcGISMapsSDK/CAPI/Standard/ErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/RuntimeClient.h"
#include "ArcGISMapsSDK/CAPI/Standard/StringHandle.h"

#ifdef __cplusplus
extern "C"
{
#endif

RT_StringHandle RT_ArcGISRuntimeEnvironment_getAPIKey(const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setAPIKey(char* APIKey, const RT_ErrorHandler* errorHandler);
bool RT_ArcGISRuntimeEnvironment_getUseCoreAuthentication(const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setUseCoreAuthentication(bool useCoreAuthentication, const RT_ErrorHandler* errorHandler);

void RT_ArcGISRuntimeEnvironment_enableBreakOnException(bool enable, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_enableLeakDetection(bool enable, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_enableRaiseAssertion(bool enable, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_enableShowAssertDialog(bool enable, const RT_ErrorHandler* errorHandler);
RT_StringHandle RT_ArcGISRuntimeEnvironment_getFeatureToggleDirectory(const RT_ErrorHandler* errorHandler);
bool RT_ArcGISRuntimeEnvironment_isFeatureEnabled(const char* featureToggle, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setBetaWatermark(bool set, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setFeatureToggleDirectory(const char* featureToggleDirectory, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setInstallDirectory(const char* installPath, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setProductInfo(const char* name, const char* version, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setResourcesDirectory(const char* resourcesPath, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setRuntimeClient(RT_RuntimeClient runtimeClient, const char* version, const RT_ErrorHandler* errorHandler);
void RT_ArcGISRuntimeEnvironment_setTempDirectory(const char* tempPath, const RT_ErrorHandler* errorHandler);

void RT_ArcGISRuntimeEnvironment_setErrorCallback(RT_ArcGISRuntimeEnvironmentErrorEvent_fn callback, void* userData, const RT_ErrorHandler* errorHandler);

#ifdef __cplusplus
} // extern "C"
#endif