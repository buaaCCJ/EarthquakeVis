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
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorAuthenticationTool.h"

#include "InteractiveToolManager.h"
#include "ToolBuilderUtil.h"

#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"

using namespace MapCreatorUtilities;

#define LOCTEXT_NAMESPACE "ArcGISMapCreatorAuthenticationTool"

FString UArcGISMapCreatorAuthenticationToolProperties::StoredAPIKey = "";

FString UArcGISMapCreatorAuthenticationToolProperties::GetStoredAPIKey()
{
	return StoredAPIKey;
}

void UArcGISMapCreatorAuthenticationToolProperties::SetStoredAPIKey(const FString& InAPIKey)
{
	 StoredAPIKey = InAPIKey;
}

bool UArcGISMapCreatorAuthenticationToolBuilder::CanBuildTool(const FToolBuilderState& SceneState) const
{
	return true;
}

UInteractiveTool* UArcGISMapCreatorAuthenticationToolBuilder::BuildTool(const FToolBuilderState& SceneState) const
{
	return NewObject<UArcGISMapCreatorAuthenticationTool>(SceneState.ToolManager);
}

void UArcGISMapCreatorAuthenticationToolBuilder::PostSetupTool(UInteractiveTool* Tool, const FToolBuilderState& SceneState) const
{
	UArcGISMapCreatorAuthenticationTool* authTool = Cast<UArcGISMapCreatorAuthenticationTool>(Tool);
	auto properties = authTool->Properties;

	auto mapComponent = MapComponentManager::GetMapComponent();

	if (!mapComponent)
	{
		properties->APIKey = UArcGISMapCreatorAuthenticationToolProperties::GetStoredAPIKey();
		return;
	}

	properties->APIKey = mapComponent->GetAPIKey();
	properties->Configs = mapComponent->GetAuthenticationConfigurations();

	if (properties->APIKey != UArcGISMapCreatorAuthenticationToolProperties::GetStoredAPIKey())
	{
		UArcGISMapCreatorAuthenticationToolProperties::SetStoredAPIKey(properties->APIKey);
	}
}

void UArcGISMapCreatorAuthenticationTool::Setup()
{
	UInteractiveTool::Setup();

	Properties = NewObject<UArcGISMapCreatorAuthenticationToolProperties>(this);
	AddToolPropertySource(Properties);
}

void UArcGISMapCreatorAuthenticationTool::OnPropertyModified(UObject* PropertySet, FProperty* Property)
{
	auto mapComponent = MapComponentManager::GetMapComponent();

	if (Property->GetFName() == GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorAuthenticationToolProperties, APIKey))
	{
		UArcGISMapCreatorAuthenticationToolProperties::SetStoredAPIKey(Properties->APIKey);
	}

	if (!mapComponent)
	{
		return;
	}

	if (Property->GetFName() == GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorAuthenticationToolProperties, APIKey))
	{
		mapComponent->SetAPIKey(Properties->APIKey);
	}
	else if (Property->GetFName() == GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorAuthenticationToolProperties, Configs) ||
			 Property->GetFName() == GET_MEMBER_NAME_CHECKED(FArcGISAuthenticationConfigurationInstanceData, Name) ||
			 Property->GetFName() == GET_MEMBER_NAME_CHECKED(FArcGISAuthenticationConfigurationInstanceData, ID) ||
			 Property->GetFName() == GET_MEMBER_NAME_CHECKED(FArcGISAuthenticationConfigurationInstanceData, ClientID) ||
			 Property->GetFName() == GET_MEMBER_NAME_CHECKED(FArcGISAuthenticationConfigurationInstanceData, RedirectURI))
	{
		mapComponent->SetAuthenticationConfigurations(Properties->Configs);
	}
}

#undef LOCTEXT_NAMESPACE
