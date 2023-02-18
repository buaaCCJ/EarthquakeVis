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
#include "ArcGISMapsSDKEditor/ArcGISMapsSDKEditorModule.h"

// Unreal

#include "Editor.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "UObject/Class.h"
#include "UObject/WeakObjectPtr.h"

// ArcGISMapsSDKEditor

#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDK/Utils/ArcGISMapsSDKProjectSettings.h"
#include "ArcGISMapsSDK/Utils/AuthGuid.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"
#include "ArcGISMapsSDKEditor/ArcGISEditorModeCommands.h"
#include "ArcGISMapsSDKEditor/Assets/ArcGISAssetDirectory.h"
#include "ArcGISMapsSDKEditor/DetailsPanel/ArcGISAuthGuidCustomization.h"
#include "ArcGISMapsSDKEditor/DetailsPanel/ArcGISGeoPositionProperty.h"
#include "ArcGISMapsSDKEditor/DetailsPanel/ArcGISMapComponentExtentProperty.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorLayerTool.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorMapTool.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorAuthenticationToolDetails.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorCameraToolDetails.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorElevationToolDetails.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorHelpToolDetails.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorLayerCustomization.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorLayerToolDetails.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorMapToolDetails.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

#define LOCTEXT_NAMESPACE "FArcGISMapsSDKEditorModule"

void FArcGISMapsSDKEditorModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	{
		PropertyModule.RegisterCustomPropertyTypeLayout(
			FGeoPosition::StaticStruct()->GetFName(),
			FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FArcGISGeoPositionDetailCustomization::MakeInstance));

		PropertyModule.RegisterCustomPropertyTypeLayout(
			FArcGISExtentInstanceData::StaticStruct()->GetFName(),
			FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FArcGISMapComponentExtentPropertyCustomization::MakeInstance));

		PropertyModule.RegisterCustomPropertyTypeLayout(FAuthGuid::StaticStruct()->GetFName(),
														FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FArcGISAuthGuidCustomization::MakeInstance));

		PropertyModule.RegisterCustomPropertyTypeLayout(
			FMapCreatorLayer::StaticStruct()->GetFName(),
			FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FArcGISMapCreatorLayerCustomization::MakeInstance));

		PropertyModule.RegisterCustomClassLayout(UArcGISMapCreatorMapToolProperties::StaticClass()->GetFName(),
												 FOnGetDetailCustomizationInstance::CreateStatic(&FArcGISMapCreatorMapToolDetails::MakeInstance));

		PropertyModule.RegisterCustomClassLayout(UArcGISMapCreatorCameraToolProperties::StaticClass()->GetFName(),
												 FOnGetDetailCustomizationInstance::CreateStatic(&FArcGISMapCreatorCameraToolDetails::MakeInstance));

		PropertyModule.RegisterCustomClassLayout(UArcGISMapCreatorLayerToolProperties::StaticClass()->GetFName(),
												 FOnGetDetailCustomizationInstance::CreateStatic(&FArcGISMapCreatorLayerToolDetails::MakeInstance));

		PropertyModule.RegisterCustomClassLayout(
			UArcGISMapCreatorElevationToolProperties::StaticClass()->GetFName(),
			FOnGetDetailCustomizationInstance::CreateStatic(&FArcGISMapCreatorElevationToolDetails::MakeInstance));

		PropertyModule.RegisterCustomClassLayout(
			UArcGISMapCreatorAuthenticationToolProperties::StaticClass()->GetFName(),
			FOnGetDetailCustomizationInstance::CreateStatic(&FArcGISMapCreatorAuthenticationToolDetails::MakeInstance));

		PropertyModule.RegisterCustomClassLayout(UArcGISMapCreatorHelpToolProperties::StaticClass()->GetFName(),
												 FOnGetDetailCustomizationInstance::CreateStatic(&FArcGISMapCreatorHelpToolDetails::MakeInstance));
	}

	auto SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule)
	{
		auto SettingsSection =
			SettingsModule->RegisterSettings("Project", "Plugins", "ArcGISMapsSDK", LOCTEXT("ArcGISMapsSDKSettingsName", "ArcGIS Maps SDK"),
											 LOCTEXT("ArcGISMapsSDKSettingsDescription", "Configure the ArcGIS Maps SDK plug-in."),
											 GetMutableDefault<UArcGISMapsSDKProjectSettings>());
	}

	FArcGISAssetDirectory::LoadForCook();
	FArcGISEditorModeCommands::Register();
}

void FArcGISMapsSDKEditorModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		{
			PropertyModule.UnregisterCustomClassLayout(UArcGISMapCreatorLayerToolProperties::StaticClass()->GetFName());
			PropertyModule.UnregisterCustomClassLayout(UArcGISMapCreatorHelpToolProperties::StaticClass()->GetFName());
		}
	}

	FArcGISMapCreatorStyles::Shutdown();

	auto SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ArcGISMapsSDK");
	}

	FArcGISAssetDirectory::ReleaseAll();
	FArcGISEditorModeCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FArcGISMapsSDKEditorModule, ArcGISMapsSDKEditor)
