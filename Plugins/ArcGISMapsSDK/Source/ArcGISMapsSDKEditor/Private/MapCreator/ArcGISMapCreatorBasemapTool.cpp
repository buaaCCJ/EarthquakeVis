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
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorBasemapTool.h"

#include "IStructureDetailsView.h"
#include "InteractiveToolManager.h"
#include "Modules/ModuleManager.h"
#include "SPrimaryButton.h"
#include "ToolBuilderUtil.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STableViewBase.h"

#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISBasemap.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISBasemap.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMap.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

using namespace MapCreatorUtilities;

#define LOCTEXT_NAMESPACE "ArcGISMapCreatorBasemapTool"

namespace
{
TSharedPtr<SArcGISMapCreatorBasemapWidget::Item> BuildWidgetItem(FString InLabel,
																 FString InColorImageName,
																 FString InGrayscaleImageName,
																 bool InCanBeRemoved,
																 bool InRequiresAPIKey,
																 TSharedPtr<TStructOnScope<FBasemapItem>> InUserData)
{
	return MakeShareable(new SArcGISMapCreatorBasemapWidget::Item{
		InCanBeRemoved, FArcGISMapCreatorStyles::GetCommonStyleSet()->GetBrush(*InColorImageName),
		FArcGISMapCreatorStyles::GetCommonStyleSet()->GetBrush(*InGrayscaleImageName), std::move(InLabel), InRequiresAPIKey, std::move(InUserData)});
}

TSharedPtr<SArcGISMapCreatorBasemapWidget::Item> BuildDefaultWidgetItem(FString InLabel, FString InImageName, EBaseMapTypes InType, FString InUrl)
{
	auto userData = MakeShared<TStructOnScope<FBasemapItem>>();
	userData->InitializeAs<FBasemapItem>();

	userData->Get()->Name = InLabel;
	userData->Get()->Source = InUrl;
	userData->Get()->Type = InType;

	auto colorImageName = "BasemapTool.Color." + InImageName;
	auto grayscaleImageName = "BasemapTool.Grayscale." + InImageName;

	return BuildWidgetItem(std::move(InLabel), std::move(colorImageName), std::move(grayscaleImageName), false, true, std::move(userData));
}

TSharedPtr<SArcGISMapCreatorBasemapWidget::Item> GetBasemapWidgetItemFromUrl(
	const TSharedPtr<TArray<TSharedPtr<SArcGISMapCreatorBasemapWidget::Item>>>& InBasemapWidgetItems,
	const FString& InUrl)
{
	if (InUrl.IsEmpty())
	{
		return nullptr;
	}

	for (const auto& basemapWidgetItem : *InBasemapWidgetItems)
	{
		auto basemapItem = StaticCastSharedPtr<TStructOnScope<FBasemapItem>>(basemapWidgetItem->UserData);

		if (basemapItem->Get()->Source == InUrl)
		{
			return basemapWidgetItem;
		}
	}

	return nullptr;
}
} // namespace

class SAddBasemapWidget : public SCompoundWidget
{
public:
	// clang-format off
	SLATE_BEGIN_ARGS(SAddBasemapWidget) {}
		SLATE_ARGUMENT(TSharedPtr<SWindow>, WidgetWindow)
	SLATE_END_ARGS()
	// clang-format on

	void Construct(const FArguments& InArgs)
	{
		bDialogConfirmed = false;

		WidgetWindow = InArgs._WidgetWindow;

		BasemapItem = MakeShared<TStructOnScope<FBasemapItem>>();
		BasemapItem->InitializeAs<FBasemapItem>();

		auto& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

		FStructureDetailsViewArgs StructureViewArgs;
		{
			StructureViewArgs.bShowObjects = true;
			StructureViewArgs.bShowAssets = true;
			StructureViewArgs.bShowClasses = true;
			StructureViewArgs.bShowInterfaces = true;
		}

		FDetailsViewArgs ViewArgs;
		{
			ViewArgs.bAllowSearch = false;
			ViewArgs.bHideSelectionTip = false;
			ViewArgs.bShowObjectLabel = false;
		}

		auto BasemapItemDetailsView = PropertyEditorModule.CreateStructureDetailView(ViewArgs, StructureViewArgs, TSharedPtr<FStructOnScope>());

		BasemapItemDetailsView->SetStructureData(BasemapItem);

		// clang-format off
		ChildSlot
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
				[
					BasemapItemDetailsView->GetWidget().ToSharedRef()
				]
			+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Right)
				.Padding(8.0f, 8.0f, 8.0f, 8.0f)
				[
					SNew(SUniformGridPanel)
					.SlotPadding(2)
					+ SUniformGridPanel::Slot(0, 0)
					[
						SNew(SPrimaryButton)
						.Text(FText::FromString(TEXT("Add")))
						.OnClicked(this, &SAddBasemapWidget::HandleOkButtonClicked)
					]
					+ SUniformGridPanel::Slot(1, 0)
					[
						SNew(SButton)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.TextStyle(FAppStyle::Get(), "DialogButtonText")
						.Text(FText::FromString(TEXT("Cancel")))
						.OnClicked(this, &SAddBasemapWidget::HandleCancelButtonClicked)
					]
				]
		];
		// clang-format on
	}

	TSharedPtr<TStructOnScope<FBasemapItem>> GetAddedBasemap() const
	{
		return BasemapItem;
	}

	bool IsDialogConfirmed() const
	{
		return bDialogConfirmed;
	}

	FReply HandleCancelButtonClicked()
	{
		bDialogConfirmed = false;

		if (WidgetWindow.IsValid())
		{
			WidgetWindow.Pin()->RequestDestroyWindow();
		}

		return FReply::Handled();
	}

	FReply HandleOkButtonClicked()
	{
		bDialogConfirmed = true;

		if (WidgetWindow.IsValid())
		{
			WidgetWindow.Pin()->RequestDestroyWindow();
		}

		return FReply::Handled();
	}

private:
	bool bDialogConfirmed{false};

	TSharedPtr<TStructOnScope<FBasemapItem>> BasemapItem;
	TWeakPtr<SWindow> WidgetWindow;
};

bool UArcGISMapCreatorBasemapToolBuilder::CanBuildTool(const FToolBuilderState& SceneState) const
{
	return true;
}

UInteractiveTool* UArcGISMapCreatorBasemapToolBuilder::BuildTool(const FToolBuilderState& SceneState) const
{
	return NewObject<UArcGISMapCreatorBasemapTool>(SceneState.ToolManager);
}

void UArcGISMapCreatorBasemapTool::LoadBasemapSettings()
{
	auto mapComponent = MapComponentManager::GetMapComponent();

	if (!mapComponent)
	{
		return;
	}

	auto basemapAuthentication = mapComponent->GetBasemapAuthID();
	auto basemapType = mapComponent->GetBasemapType();
	auto basemapUrl = mapComponent->GetBasemapSource();

	auto basemapWidgetItem = GetBasemapWidgetItemFromUrl(BasemapWidgetItems, basemapUrl);

	if (!basemapWidgetItem)
	{
		auto userData = MakeShared<TStructOnScope<FBasemapItem>>();
		userData->InitializeAs<FBasemapItem>();

		userData->Get()->Name = "User Basemap";
		userData->Get()->Source = basemapUrl;
		userData->Get()->Type = basemapType;
		userData->Get()->Authentication = basemapAuthentication;

		basemapWidgetItem = BuildWidgetItem(userData->Get()->Name, "BasemapTool.Custom", "BasemapTool.Custom", true, false, userData);

		BasemapWidgetItems->Add(basemapWidgetItem);

		BasemapWidget->Rebuild();

		BasemapWidget->ScrollToItem(basemapWidgetItem);
	}

	BasemapWidget->SetSelectedItem(basemapWidgetItem);
}

void UArcGISMapCreatorBasemapTool::Setup()
{
	UInteractiveTool::Setup();

	BasemapWidgetItems = MakeShared<TArray<TSharedPtr<SArcGISMapCreatorBasemapWidget::Item>>>();

	// clang-format off
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("OpenStreetMap (Light Gray Canvas)",		"OpenStreetMapLightGrayCanvas",		EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=983b312ebd9b4d15a02e00f50acdb1c1"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Streets (with Relief)",					"StreetsWithRelief",				EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=03daad361e1849bc80cb7b70ed391379"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Imagery Hybrid",						"ImageryHybrid",					EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=ea3befe305494bb5b2acd77e1b3135dc"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Dark Gray Canvas",						"DarkGrayCanvas",					EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=7742cd5abef8497288dc81426266df9b"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Streets (Night)",						"StreetsNight",						EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=b22e146f927e413c92f75b5e4614354a"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Terrain with Labels",					"TerrainWithLabels",				EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=2ef1306b93c9459ca7c7b4f872c070b9"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Oceans",								"Oceans",							EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=b1dca7ef7b61466785901c41aed89ba5"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Navigation (Night)",					"NavigationNight",					EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=77073a29526046b89bb5622b6276e933"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("OpenStreetMap (with Relief)",			"OpenStreetMapWithRelief",			EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=5b93370c7fc24ca3b8740abd2a55456a"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("OpenStreetMap (Dark Gray Canvas)",		"OpenStreetMapDarkGrayCanvas",		EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=7371ca07df4047eaa5f02d09ef12b1a0"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Light Gray Canvas",						"LightGrayCanvas",					EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=0f74af7609054be8a29e0ba5f154f0a8"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Navigation",							"Navigation",						EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=78c096abedb9498380f5db1922f96aa0"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("OpenStreetMap (Streets with Relief)",	"OpenStreetMapStreetsWithRelief",	EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=c6ec0420be5a4e36b57d1ef0f243b175"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("OpenStreetMap (Streets)",				"OpenStreetMapStreets",				EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=bcefe41ce33943ac81d2fd801edd452c"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Topographic",							"Topographic",						EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=dd247558455c4ffab54566901a14f42c"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Mid-Century Map",						"MidCenturyMap",					EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=52d6a28f09704f04b33761ba7c4bf93f"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Colored Pencil Map",					"ColoredPencilMap",					EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=c0ddf27614bc407f92c35020a9b48afa"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Imagery",								"Imagery",							EBaseMapTypes::Basemap,	"https://www.arcgis.com/home/item.html?id=c7d2b5c334364e8fb5b73b0f4d6a779b"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Community Map",							"CommunityMap",						EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=184f5b81589844699ca1e132d007920e"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Streets",								"Streets",							EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=e3e6df1d2f6a485d8a70f28fdd3ce19e"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Charted Territory Map",					"ChartedTerritoryMap",				EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=303e75b27af043fd835c981ab9accf84"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Modern Antique Map",					"ModernAntiqueMap",					EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=b69f2876ce4c4e9db185cdc857fcebc7"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("OpenStreetMap",							"OpenStreetMap",					EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=695aef1564e84c06833542eb4d8c02d3"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Newspaper Map",							"NewspaperMap",						EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=e3c062eedf8b487b8bb5b9b08db1b7a9"));
	BasemapWidgetItems->Add(BuildDefaultWidgetItem("Nova Map",								"NovaMap",							EBaseMapTypes::Basemap, "https://www.arcgis.com/home/item.html?id=90f86b329f37499096d3715ac6e5ed1f"));
	// clang-format on

	for (FBasemapItem customBasemap : CustomBasemaps)
	{
		auto item = MakeShared<TStructOnScope<FBasemapItem>>();
		item->InitializeAs<FBasemapItem>(customBasemap);
		BasemapWidgetItems->Add(BuildWidgetItem(customBasemap.Name,  "BasemapTool.Custom", "BasemapTool.Custom", true, false, item));
	}

	// clang-format off
	InlineContent = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SAssignNew(BasemapWidget, SArcGISMapCreatorBasemapWidget)
			.Items(BasemapWidgetItems)
			.OnSelectionChanged_UObject(this, &UArcGISMapCreatorBasemapTool::HandleBasemapWidgetSelectionChanged)
			.OnItemRemoved_UObject(this, &UArcGISMapCreatorBasemapTool::HandleCustomBasemapWidgetRemoved)
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SBox)
			.Padding(FMargin(0.0f, 0.0f, 32.0f, 0.0f))
			.HeightOverride(56.0f)
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			[
				SNew(SButton)
				.ButtonStyle(FArcGISMapCreatorStyles::GetCommonStyleSet(), "ArcGISMapsSDKEditor.FlatButton")
				.ContentPadding(0.0f)
				.OnClicked_UObject(this, &UArcGISMapCreatorBasemapTool::HandleAddNewClicked)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.Padding(FMargin(0.0f, 0.0f, 8.0, 0.0f))
					[
						SNew(SImage)
						.Image(FAppStyle::Get().GetBrush("Icons.Plus"))
						.ColorAndOpacity(FSlateColor::UseForeground())
					]
					+ SHorizontalBox::Slot()
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("Add New")))
						.TextStyle(FAppStyle::Get(), "NormalText")
					]
				]
			]
		];
	// clang-format on

	LoadBasemapSettings();
}

TSharedPtr<SWidget> UArcGISMapCreatorBasemapTool::GetInlineContent() const
{
	return InlineContent;
}

FReply UArcGISMapCreatorBasemapTool::HandleAddNewClicked()
{
	// clang-format off
	auto Window = SNew(SWindow)
		.AutoCenter(EAutoCenter::PreferredWorkArea)
		.SupportsMaximize(false)
		.SupportsMinimize(false)
		.SizingRule(ESizingRule::Autosized)
		.Title(LOCTEXT("WindowHeader", "Add New Basemap"));
	// clang-format on

	// clang-format off
	TSharedRef<SAddBasemapWidget> AddBasemapWidget =
		SNew(SAddBasemapWidget)
		.WidgetWindow(Window);
	// clang-format on

	Window->SetContent(AddBasemapWidget);

	FSlateApplication::Get().AddModalWindow(Window, InlineContent);

	if (AddBasemapWidget.Get().IsDialogConfirmed())
	{
		auto basemapItem = AddBasemapWidget.Get().GetAddedBasemap();

		auto basemapWidgetItem = BuildWidgetItem(basemapItem->Get()->Name, "BasemapTool.Custom", "BasemapTool.Custom", true, false, basemapItem);

		BasemapWidgetItems->Add(basemapWidgetItem);
        
		CustomBasemaps.Add(*basemapItem->Get());
		SaveConfig();

		BasemapWidget->Rebuild();

		BasemapWidget->ScrollToItem(basemapWidgetItem);
	}

	return FReply::Handled();
}

void UArcGISMapCreatorBasemapTool::HandleCustomBasemapWidgetRemoved(TSharedPtr<SArcGISMapCreatorBasemapWidget::Item> InItem)
{
	if (!InItem.IsValid())
	{
		return;
	}

	auto basemapItem = StaticCastSharedPtr<TStructOnScope<FBasemapItem>>(InItem->UserData);

	if (!basemapItem.IsValid())
	{
		return;
	}

	CustomBasemaps.Remove(*basemapItem->Get());
	SaveConfig();
}

void UArcGISMapCreatorBasemapTool::HandleBasemapWidgetSelectionChanged(TSharedPtr<SArcGISMapCreatorBasemapWidget::Item> InItem)
{
	SelectedItem = std::move(InItem);

	auto mapComponent = MapComponentManager::GetMapComponent();

	if (!mapComponent)
	{
		return;
	}

	if (SelectedItem)
	{
		auto basemapItem = StaticCastSharedPtr<TStructOnScope<FBasemapItem>>(SelectedItem->UserData)->Get();

		mapComponent->SetBasemapSourceAndType(basemapItem->Source, basemapItem->Type);
		mapComponent->SetBasemapAuthID(basemapItem->Authentication);
	}
	else
	{
		mapComponent->SetBasemapSourceAndType({}, {});
		mapComponent->SetBasemapAuthID({});
	}
}

#undef LOCTEXT_NAMESPACE
