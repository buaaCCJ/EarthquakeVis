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
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorSettingsTool.h"

#include "InteractiveToolManager.h"
#include "ToolBuilderUtil.h"

#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDK/Subsystem/ArcGISMapsSDKSubsystem.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"

using namespace MapCreatorUtilities;

#define LOCTEXT_NAMESPACE "ArcGISMapCreatorSettingsTool"

bool UArcGISMapCreatorSettingsToolBuilder::CanBuildTool(const FToolBuilderState& SceneState) const
{
	return true;
}

UInteractiveTool* UArcGISMapCreatorSettingsToolBuilder::BuildTool(const FToolBuilderState& SceneState) const
{
	return NewObject<UArcGISMapCreatorSettingsTool>(SceneState.ToolManager);
}

void UArcGISMapCreatorSettingsToolBuilder::PostSetupTool(UInteractiveTool* Tool, const FToolBuilderState& SceneState) const
{
	UArcGISMapCreatorSettingsTool* settingsTool = Cast<UArcGISMapCreatorSettingsTool>(Tool);
	auto properties = settingsTool->Properties;

	auto mapComponent = MapComponentManager::GetMapComponent();

	if (!mapComponent)
	{
		return;
	}

	properties->EnableEditorMode = mapComponent->GetIsEditorModeEnabled();
	properties->EnableMeshColliders = mapComponent->GetAreMeshCollidersEnabled();
	properties->UpdateGeoReferencingSystem = mapComponent->GetShouldUpdateGeoReferencingSystem();
}

void UArcGISMapCreatorSettingsTool::Setup()
{
	UInteractiveTool::Setup();

	Properties = NewObject<UArcGISMapCreatorSettingsToolProperties>(this);
	AddToolPropertySource(Properties);

	if (auto OwningWorld = GetWorld(); OwningWorld && OwningWorld->WorldType == EWorldType::Editor)
	{
		if (auto arcGISMapsSDKSubsystem = OwningWorld->GetSubsystem<UArcGISMapsSDKSubsystem>())
		{
			arcGISMapsSDKSubsystem->RegisterListener(this);
		}
	}
}

void UArcGISMapCreatorSettingsTool::Shutdown(EToolShutdownType ShutdownType)
{
	if (auto OwningWorld = GetWorld(); OwningWorld && OwningWorld->WorldType == EWorldType::Editor)
	{
		if (auto arcGISMapsSDKSubsystem = OwningWorld->GetSubsystem<UArcGISMapsSDKSubsystem>())
		{
			arcGISMapsSDKSubsystem->UnregisterListener(this);
		}
	}
}

void UArcGISMapCreatorSettingsTool::OnGeoReferencingSystemChanged(AGeoReferencingSystem* InGeoReferencingSystem)
{
	Properties->GeoReferencingSystem = InGeoReferencingSystem;
}

void UArcGISMapCreatorSettingsTool::OnPropertyModified(UObject* PropertySet, FProperty* Property)
{
	if (!Property)
	{
		return;
	}

	auto mapComponent = Cast<UArcGISMapComponent>(MapComponentManager::GetMapComponent());

	if (!mapComponent)
	{
		return;
	}

	if (Properties->EnableEditorMode != mapComponent->GetIsEditorModeEnabled())
	{
		mapComponent->SetIsEditorModeEnabled(Properties->EnableEditorMode);
		mapComponent->OnMapTypeChanged.Broadcast();
		mapComponent->MarkPackageDirty();
	}

	if (Properties->EnableMeshColliders != mapComponent->GetAreMeshCollidersEnabled())
	{
		mapComponent->SetAreMeshCollidersEnabled(Properties->EnableMeshColliders);
		mapComponent->MarkPackageDirty();
	}

	if (Properties->UpdateGeoReferencingSystem != mapComponent->GetShouldUpdateGeoReferencingSystem())
	{
		mapComponent->SetShouldUpdateGeoReferencingSystem(Properties->UpdateGeoReferencingSystem);
		mapComponent->MarkPackageDirty();
	}
}

#undef LOCTEXT_NAMESPACE
