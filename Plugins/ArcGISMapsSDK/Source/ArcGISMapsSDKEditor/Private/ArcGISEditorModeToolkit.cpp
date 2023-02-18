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
#include "ArcGISMapsSDKEditor/ArcGISEditorModeToolkit.h"

// Unreal

#include "EditorModeManager.h"
#include "Engine/Selection.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "IDetailsView.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"

// ArcGISMapsSDK

#include "ArcGISMapsSDKEditor/ArcGISEditorMode.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorBasemapTool.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

#define LOCTEXT_NAMESPACE "ArcGISEditorModeToolkit"

void FArcGISEditorModeToolkit::BuildToolPalette(FName PaletteName, class FToolBarBuilder& ToolbarBuilder)
{
    ToolbarBuilder.SetStyle(FArcGISMapCreatorStyles::GetCommonStyleSet(), "ArcGISMapsSDKEditor.ArcGISEditorModeToolkit.ToolBar");

    FModeToolkit::BuildToolPalette(std::move(PaletteName), ToolbarBuilder);
}

void FArcGISEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);

	InlineContent = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			ModeDetailsView.ToSharedRef()
		]
		+ SVerticalBox::Slot()
		.Expose(DetailsViewSlot);
}

void FArcGISEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}

FName FArcGISEditorModeToolkit::GetToolkitFName() const
{
	return FName("ArcGISEditorMode");
}

FText FArcGISEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "ArcGISEditorMode Toolkit");
}

TSharedPtr<SWidget> FArcGISEditorModeToolkit::GetInlineContent() const
{
	return InlineContent;
}

void FArcGISEditorModeToolkit::OnToolStarted(UInteractiveToolManager* Manager, UInteractiveTool* Tool)
{
	auto MapCreatorTool = Cast<UArcGISMapCreatorTool>(Tool);

	if (MapCreatorTool)
	{
		DetailsViewSlot->AttachWidget(MapCreatorTool->GetInlineContent().ToSharedRef());
	}
	else
	{
		DetailsViewSlot->AttachWidget(DetailsView.ToSharedRef());

		FModeToolkit::OnToolStarted(Manager, Tool);
	}
}

#undef LOCTEXT_NAMESPACE
