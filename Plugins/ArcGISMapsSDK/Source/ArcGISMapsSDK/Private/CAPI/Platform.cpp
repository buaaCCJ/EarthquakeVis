// COPYRIGHT 1995-2021 ESRI
// TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
// Unpublished material - all rights reserved under the
// Copyright Laws of the United States and applicable international
// laws, treaties, and conventions.
//
// For additional information, contact:
// Environmental Systems Research Institute, Inc.
// Attn: Contracts and Legal Services Department
// 380 New York Street
// Redlands, California, 92373
// USA
//
// email: contracts@esri.com

#if PLATFORM_MAC || PLATFORM_HOLOLENS
#include "ArcGISMapsSDK/CAPI/Platform.h" // IWYU pragma: associated

#include "Interfaces/IPluginManager.h"

void* GetRTCDLLHandle()
{
	static void* dllHandle = nullptr;

	if (!dllHandle)
	{
		// Get the base directory of this plugin
		FString PluginBaseDir = IPluginManager::Get().FindPlugin("ArcGISMapsSDK")->GetBaseDir();

		// Add on the relative location of the third party dll and load it
		FString Path = PluginBaseDir / THIRDPARTY_BINARY_SUBFOLDER;

		dllHandle = FPlatformProcess::GetDllHandle(*(Path / THIRDPARTY_BINARY_NAME));

#if PLATFORM_HOLOLENS
		if (!dllHandle)
		{
			// Workaround for HoloLens when the project name is different than the project folder name
			PluginBaseDir = FPaths::ConvertRelativePathToFull(FPlatformProcess::BaseDir(), TEXT("../../Plugins/ArcGISMapsSDK"));

			Path = PluginBaseDir / THIRDPARTY_BINARY_SUBFOLDER;

			dllHandle = FPlatformProcess::GetDllHandle(*(Path / THIRDPARTY_BINARY_NAME));
		}
#endif
	}

	return dllHandle;
}
#endif
