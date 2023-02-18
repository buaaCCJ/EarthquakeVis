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
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

#include "EditorStyleSet.h"
#include "Framework/Application/SlateApplication.h"
#include "Interfaces/IPluginManager.h"
#include "Slate/SlateGameResources.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/ToolBarStyle.h"

#include "ArcGISMapsSDKEditor/ArcGISMapsSDKEditorModule.h"

#define BoxBrush(RelativePath, ...) FSlateBoxBrush(StyleSet->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define PNGImageBrush(RelativePath, ...) FSlateImageBrush(StyleSet->RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)
#define SVGImageBrush(RelativePath, ...) FSlateVectorImageBrush(StyleSet->RootToContentDir(RelativePath, TEXT(".svg")), __VA_ARGS__)

const FVector2D BasemapImageSize(200, 133);
const FVector2D ElevationImageSize(854, 140);
const FVector2D LogoMargin(370, 114);
const FVector2D SmallIconMargin(20, 20);
const FVector2D ToolbarIconSize(22, 22);

TSharedPtr<FSlateStyleSet> FArcGISMapCreatorStyles::CommonStyleSet = nullptr;

void CreateHyperlinkButtonStyle(TSharedPtr<FSlateStyleSet> StyleSet)
{
	// clang-format off
	const FButtonStyle hyperlinkButtonStyle = FButtonStyle()
		.SetNormal(FSlateNoResource())
		.SetHovered(FSlateNoResource())
		.SetPressed(FSlateNoResource());
	// clang-format on

	auto defaultText = FCoreStyle::Get().GetWidgetStyle<FHyperlinkStyle>("Hyperlink").TextStyle;

	// clang-format off
	FTextBlockStyle hyperlinkTextStyle = FTextBlockStyle(defaultText)
		.SetColorAndOpacity(FSlateColor(FColor(0, 43, 170)));
	// clang-format on

	// clang-format off
	const FHyperlinkStyle hyperlinkStyle = FHyperlinkStyle()
		.SetPadding(FMargin(0, 4, 0, 4))
		.SetTextStyle(hyperlinkTextStyle)
		.SetUnderlineStyle(hyperlinkButtonStyle);
	// clang-format on

	StyleSet->Set("HyperlinkStyle", hyperlinkStyle);
}

TSharedRef<FSlateStyleSet> FArcGISMapCreatorStyles::CreateCommonStyleSet()
{
	TSharedRef<FSlateStyleSet> StyleSet = MakeShareable(new FSlateStyleSet("FArcGISMapCreatorStyles"));

	auto pluginDir = IPluginManager::Get().FindPlugin("ArcGISMapsSDK")->GetBaseDir();

	StyleSet->SetContentRoot(pluginDir / TEXT("Resources"));

	// clang-format off
	StyleSet->Set("EsriLogo",	new PNGImageBrush(TEXT("ESRI_LOGO"),	LogoMargin));
	StyleSet->Set("CrossIcon",	new SVGImageBrush(TEXT("Cross"),		SmallIconMargin));
	// clang-format on

	// clang-format off
	StyleSet->Set("BasemapTool.Custom",		new PNGImageBrush(TEXT("BasemapTool/Custom"),		BasemapImageSize));
	StyleSet->Set("BasemapTool.NoBasemap",	new PNGImageBrush(TEXT("BasemapTool/NoBasemap"),	BasemapImageSize));

	StyleSet->Set("BasemapTool.Color.ChartedTerritoryMap",				new PNGImageBrush(TEXT("BasemapTool/Color/ChartedTerritoryMap"),			BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.ColoredPencilMap",					new PNGImageBrush(TEXT("BasemapTool/Color/ColoredPencilMap"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.CommunityMap",						new PNGImageBrush(TEXT("BasemapTool/Color/CommunityMap"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.DarkGrayCanvas",					new PNGImageBrush(TEXT("BasemapTool/Color/DarkGrayCanvas"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.Imagery",							new PNGImageBrush(TEXT("BasemapTool/Color/Imagery"),						BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.ImageryHybrid",					new PNGImageBrush(TEXT("BasemapTool/Color/ImageryHybrid"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.LightGrayCanvas",					new PNGImageBrush(TEXT("BasemapTool/Color/LightGrayCanvas"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.MidCenturyMap",					new PNGImageBrush(TEXT("BasemapTool/Color/MidCenturyMap"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.ModernAntiqueMap",					new PNGImageBrush(TEXT("BasemapTool/Color/ModernAntiqueMap"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.Navigation",						new PNGImageBrush(TEXT("BasemapTool/Color/Navigation"),						BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.NavigationNight",					new PNGImageBrush(TEXT("BasemapTool/Color/NavigationNight"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.NewspaperMap",						new PNGImageBrush(TEXT("BasemapTool/Color/NewspaperMap"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.NovaMap",							new PNGImageBrush(TEXT("BasemapTool/Color/NovaMap"),						BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.Oceans",							new PNGImageBrush(TEXT("BasemapTool/Color/Oceans"),							BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.OpenStreetMap",					new PNGImageBrush(TEXT("BasemapTool/Color/OpenStreetMap"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.OpenStreetMapDarkGrayCanvas",		new PNGImageBrush(TEXT("BasemapTool/Color/OpenStreetMapDarkGrayCanvas"),	BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.OpenStreetMapLightGrayCanvas",		new PNGImageBrush(TEXT("BasemapTool/Color/OpenStreetMapLightGrayCanvas"),	BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.OpenStreetMapStreets",				new PNGImageBrush(TEXT("BasemapTool/Color/OpenStreetMapStreets"),			BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.OpenStreetMapStreetsWithRelief",	new PNGImageBrush(TEXT("BasemapTool/Color/OpenStreetMapStreetsWithRelief"),	BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.OpenStreetMapWithRelief",			new PNGImageBrush(TEXT("BasemapTool/Color/OpenStreetMapWithRelief"),		BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.Streets",							new PNGImageBrush(TEXT("BasemapTool/Color/Streets"),						BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.StreetsNight",						new PNGImageBrush(TEXT("BasemapTool/Color/StreetsNight"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.StreetsWithRelief",				new PNGImageBrush(TEXT("BasemapTool/Color/StreetsWithRelief"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.TerrainWithLabels",				new PNGImageBrush(TEXT("BasemapTool/Color/TerrainWithLabels"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Color.Topographic",						new PNGImageBrush(TEXT("BasemapTool/Color/Topographic"),					BasemapImageSize));

	StyleSet->Set("BasemapTool.Grayscale.ChartedTerritoryMap",				new PNGImageBrush(TEXT("BasemapTool/Grayscale/ChartedTerritoryMap"),			BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.ColoredPencilMap",					new PNGImageBrush(TEXT("BasemapTool/Grayscale/ColoredPencilMap"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.CommunityMap",						new PNGImageBrush(TEXT("BasemapTool/Grayscale/CommunityMap"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.DarkGrayCanvas",					new PNGImageBrush(TEXT("BasemapTool/Grayscale/DarkGrayCanvas"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.Imagery",							new PNGImageBrush(TEXT("BasemapTool/Grayscale/Imagery"),						BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.ImageryHybrid",					new PNGImageBrush(TEXT("BasemapTool/Grayscale/ImageryHybrid"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.LightGrayCanvas",					new PNGImageBrush(TEXT("BasemapTool/Grayscale/LightGrayCanvas"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.MidCenturyMap",					new PNGImageBrush(TEXT("BasemapTool/Grayscale/MidCenturyMap"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.ModernAntiqueMap",					new PNGImageBrush(TEXT("BasemapTool/Grayscale/ModernAntiqueMap"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.Navigation",						new PNGImageBrush(TEXT("BasemapTool/Grayscale/Navigation"),						BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.NavigationNight",					new PNGImageBrush(TEXT("BasemapTool/Grayscale/NavigationNight"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.NewspaperMap",						new PNGImageBrush(TEXT("BasemapTool/Grayscale/NewspaperMap"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.NovaMap",							new PNGImageBrush(TEXT("BasemapTool/Grayscale/NovaMap"),						BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.Oceans",							new PNGImageBrush(TEXT("BasemapTool/Grayscale/Oceans"),							BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.OpenStreetMap",					new PNGImageBrush(TEXT("BasemapTool/Grayscale/OpenStreetMap"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.OpenStreetMapDarkGrayCanvas",		new PNGImageBrush(TEXT("BasemapTool/Grayscale/OpenStreetMapDarkGrayCanvas"),	BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.OpenStreetMapLightGrayCanvas",		new PNGImageBrush(TEXT("BasemapTool/Grayscale/OpenStreetMapLightGrayCanvas"),	BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.OpenStreetMapStreets",				new PNGImageBrush(TEXT("BasemapTool/Grayscale/OpenStreetMapStreets"),			BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.OpenStreetMapStreetsWithRelief",	new PNGImageBrush(TEXT("BasemapTool/Grayscale/OpenStreetMapStreetsWithRelief"),	BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.OpenStreetMapWithRelief",			new PNGImageBrush(TEXT("BasemapTool/Grayscale/OpenStreetMapWithRelief"),		BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.Streets",							new PNGImageBrush(TEXT("BasemapTool/Grayscale/Streets"),						BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.StreetsNight",						new PNGImageBrush(TEXT("BasemapTool/Grayscale/StreetsNight"),					BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.StreetsWithRelief",				new PNGImageBrush(TEXT("BasemapTool/Grayscale/StreetsWithRelief"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.TerrainWithLabels",				new PNGImageBrush(TEXT("BasemapTool/Grayscale/TerrainWithLabels"),				BasemapImageSize));
	StyleSet->Set("BasemapTool.Grayscale.Topographic",						new PNGImageBrush(TEXT("BasemapTool/Grayscale/Topographic"),					BasemapImageSize));
	// clang-format on

	// clang-format off
	StyleSet->Set("ElevationTool.Default",	new PNGImageBrush(TEXT("ElevationTool/Default"),	ElevationImageSize));
	StyleSet->Set("ElevationTool.Custom",	new PNGImageBrush(TEXT("ElevationTool/Custom"),		ElevationImageSize));
	// clang-format on

	// clang-format off
	StyleSet->Set("ArcGISMiniIcon",	new PNGImageBrush(TEXT("EditorModeIcons/arcgis-maps-sdks-24"), 	SmallIconMargin));
	StyleSet->Set("AuthIcon", 		new SVGImageBrush(TEXT("EditorModeIcons/AuthToolIcon"), 		ToolbarIconSize));
	StyleSet->Set("BasemapIcon", 	new SVGImageBrush(TEXT("EditorModeIcons/BasemapToolIcon"), 		ToolbarIconSize));
	StyleSet->Set("CameraIcon", 	new SVGImageBrush(TEXT("EditorModeIcons/CameraToolIcon"), 		ToolbarIconSize));
	StyleSet->Set("ElevationIcon", 	new SVGImageBrush(TEXT("EditorModeIcons/ElevationToolIcon"), 	ToolbarIconSize));
	StyleSet->Set("HelpIcon", 		new SVGImageBrush(TEXT("EditorModeIcons/HelpToolIcon"), 		ToolbarIconSize));
	StyleSet->Set("LayersIcon", 	new SVGImageBrush(TEXT("EditorModeIcons/LayerToolIcon"), 		ToolbarIconSize));
	StyleSet->Set("MapIcon", 		new SVGImageBrush(TEXT("EditorModeIcons/MapToolIcon"), 			ToolbarIconSize));
	StyleSet->Set("SettingsIcon", 	new SVGImageBrush(TEXT("EditorModeIcons/SettingsToolIcon"), 	ToolbarIconSize));
	// clang-format on

	CreateHyperlinkButtonStyle(StyleSet);

	auto FlatButtonStyle = FAppStyle::Get().GetWidgetStyle<FButtonStyle>("SimpleButtonLabelAndIcon");

	FlatButtonStyle
		.SetNormalPadding(FMargin(0.0f, 1.f, 0.0f, 1.0f))
		.SetPressedPadding(FMargin(0.0f, 2.0f, 0.0f, 0.0f))
		.SetHovered(FSlateNoResource())
		.SetPressed(FSlateNoResource());

	StyleSet->Set("ArcGISMapsSDKEditor.FlatButton", FlatButtonStyle);

	auto RemoveButtonStyle = FAppStyle::Get().GetWidgetStyle<FButtonStyle>("SimpleButtonLabelAndIcon");

	RemoveButtonStyle
		.SetNormalPadding(0)
		.SetPressedPadding(0)
		.SetNormal(BoxBrush("White", 16.0f / 32.0f, FLinearColor(0.0f, 0.0f, 0.0f, 0.5f)))
		.SetHovered(BoxBrush("White", 16.0f / 32.0f, FLinearColor(0.0f, 0.0f, 0.0f, 0.5f)))
		.SetPressed(BoxBrush("White", 16.0f / 32.0f, FLinearColor(0.0f, 0.0f, 0.0f, 0.5f)));

	StyleSet->Set("ArcGISMapsSDKEditor.ArcGISMapCreatorBasemapWidget.RemoveButton", RemoveButtonStyle);

	auto TableViewRowStyle = FCoreStyle::Get().GetWidgetStyle<FTableRowStyle>("TableView.Row");

	TableViewRowStyle
		.SetEvenRowBackgroundBrush(FSlateNoResource())
		.SetEvenRowBackgroundHoveredBrush(FSlateNoResource())
		.SetOddRowBackgroundBrush(FSlateNoResource())
		.SetOddRowBackgroundHoveredBrush(FSlateNoResource())
		.SetSelectorFocusedBrush(FSlateNoResource())
		.SetActiveBrush(FSlateNoResource())
		.SetActiveHoveredBrush(FSlateNoResource())
		.SetInactiveBrush(FSlateNoResource())
		.SetInactiveHoveredBrush(FSlateNoResource());

	StyleSet->Set("ArcGISMapsSDKEditor.ArcGISMapCreatorBasemapWidget.TileTableRow", TableViewRowStyle);

	const auto NormalText = FEditorStyle::GetWidgetStyle<FTextBlockStyle>("NormalText");

	FTextBlockStyle TextBlockStyle = FTextBlockStyle(NormalText)
		.SetFontSize(8);

	StyleSet->Set("ArcGISMapsSDKEditor.ArcGISMapCreatorBasemapWidget.TileTableRow.Label", TextBlockStyle);

	auto ToolBarStyle = FEditorStyle::GetWidgetStyle<FToolBarStyle>("PaletteToolBar");

	ToolBarStyle.SetLabelPadding(FMargin(0, 2, 0, 0));

	ToolBarStyle.LabelStyle.Font.Size = 7;

	StyleSet->Set("ArcGISMapsSDKEditor.ArcGISEditorModeToolkit.ToolBar", ToolBarStyle);

	return StyleSet;
}

const FSlateStyleSet* FArcGISMapCreatorStyles::GetCommonStyleSet()
{
	return CommonStyleSet.Get();
}

void FArcGISMapCreatorStyles::Initialize()
{
	if (!CommonStyleSet.IsValid())
	{
		CommonStyleSet = CreateCommonStyleSet();
		FSlateStyleRegistry::RegisterSlateStyle(*CommonStyleSet);
	}

	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

void FArcGISMapCreatorStyles::Shutdown()
{
	UnregisterStyle(CommonStyleSet);
}

void FArcGISMapCreatorStyles::UnregisterStyle(TSharedPtr<FSlateStyleSet> Style)
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*Style);
	Style.Reset();
}

#undef PNGImageBrush
