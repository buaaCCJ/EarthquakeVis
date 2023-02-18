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
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorLayerTool.h"

#include "InteractiveToolManager.h"
#include "ToolBuilderUtil.h"

#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"

using namespace MapCreatorUtilities;

#define LOCTEXT_NAMESPACE "ArcGISMapCreatorLayerTool"

bool UArcGISMapCreatorLayerToolBuilder::CanBuildTool(const FToolBuilderState& SceneState) const
{
	return true;
}

UInteractiveTool* UArcGISMapCreatorLayerToolBuilder::BuildTool(const FToolBuilderState& SceneState) const
{
	return NewObject<UArcGISMapCreatorLayerTool>(SceneState.ToolManager);
}

void UArcGISMapCreatorLayerToolBuilder::PostSetupTool(UInteractiveTool* Tool, const FToolBuilderState& SceneState) const
{
	TObjectPtr<UArcGISMapCreatorLayerTool> layerTool = Cast<UArcGISMapCreatorLayerTool>(Tool);

	auto mapComponent = MapComponentManager::GetMapComponent();

	if (!mapComponent)
	{
		return;
	}

	for (const auto& mapLayer : mapComponent->GetLayers())
	{
		FMapCreatorLayer layer{};
		{
			layer.Name = mapLayer.Name;
			layer.Source = mapLayer.Source;
			layer.Opacity = mapLayer.Opacity;
			layer.bIsVisible = mapLayer.bIsVisible;
			layer.Type = mapLayer.Type;
			layer.AuthConfigID = mapLayer.AuthConfigID;
		}

		layerTool->Properties->Layers.Add(layer);
	}
}

void UArcGISMapCreatorLayerToolProperties::UpdateMapComponentLayers()
{
	auto mapComponent = MapComponentManager::GetMapComponent();

	if (!mapComponent)
	{
		return;
	}

	TArray<FArcGISLayerInstanceData> newLayers;

	for (const auto& layer : Layers)
	{
		FArcGISLayerInstanceData newLayer{};
		{
			newLayer.Name = layer.Name;
			newLayer.Source = layer.Source;
			newLayer.Opacity = layer.Opacity;
			newLayer.bIsVisible = layer.bIsVisible;
			newLayer.Type = layer.Type;
			newLayer.AuthConfigID = layer.AuthConfigID;
			newLayer.ID = FGuid::NewGuid();
		}

		newLayers.Add(newLayer);
	}

	mapComponent->SetLayers(newLayers);
}

void UArcGISMapCreatorLayerTool::Setup()
{
	UInteractiveTool::Setup();

	Properties = NewObject<UArcGISMapCreatorLayerToolProperties>(this);
	AddToolPropertySource(Properties);
}

void UArcGISMapCreatorLayerTool::OnPropertyModified(UObject* PropertySet, FProperty* Property)
{
	auto mapComponent = MapComponentManager::GetMapComponent();

	if (!mapComponent)
	{
		return;
	}

	if (Property->GetFName() == GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorLayerToolProperties, LayerType) ||
		Property->GetFName() == GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorLayerToolProperties, LayerName) ||
		Property->GetFName() == GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorLayerToolProperties, LayerSource) ||
		Property->GetFName() == GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorLayerToolProperties, AuthConfigID))
	{
		return;
	}

	Properties->UpdateMapComponentLayers();
}

#undef LOCTEXT_NAMESPACE
