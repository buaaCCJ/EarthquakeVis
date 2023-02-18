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
#include "ArcGISMapsSDKEditor/MapCreator/SArcGISMapCreatorBasemapWidget.h"

#include "IStructureDetailsView.h"
#include "Internationalization/BreakIterator.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Views/STileView.h"

#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

namespace BasemapWidgetDefs
{
constexpr float NameHeight = 20;
constexpr float TileHeight = 80.0f;
static FMargin TileMargin = FMargin(6.0f, 0.0f, 6.0f, 4.0f);
constexpr float TilePadding = 2;
constexpr float TileWidth = 120;
} // namespace BasemapWidgetDefs

class SBasemapTileView : public STileView<TSharedPtr<SArcGISMapCreatorBasemapWidget::Item>>
{
public:
	void Construct(const FArguments& InArgs)
	{
		STileView<TSharedPtr<SArcGISMapCreatorBasemapWidget::Item>>::Construct(InArgs);

		auto horizontalBox = StaticCastSharedRef<SHorizontalBox>(this->ChildSlot.GetChildAt(0));

		// The scrollbar's width is 16 so give only 8 to the right padding
		horizontalBox->GetSlot(0).SetPadding(FMargin(24.0f, 0.0f, 8.0f, 0.0f));
	}
};

void SArcGISMapCreatorBasemapWidget::Construct(const FArguments& InArgs)
{
	Items = InArgs._Items;
	OnItemRemoved = InArgs._OnItemRemoved;
	OnSelectionChanged = InArgs._OnSelectionChanged;

	TableRowStyle = FCoreStyle::Get().GetWidgetStyle<FTableRowStyle>("TableView.Row");

	// clang-format off
	ChildSlot
	[
		SAssignNew(TileView, SBasemapTileView)
		.ListItemsSource(&*Items)
		.SelectionMode(ESelectionMode::Single)
		.ClearSelectionOnClick(false)
		.OnGenerateTile(this, &SArcGISMapCreatorBasemapWidget::HandleTileViewGenerateTile)
		.OnSelectionChanged(this, &SArcGISMapCreatorBasemapWidget::HandleTileViewSelectionChanged)
		.ItemAlignment(EListItemAlignment::LeftAligned)
		.ItemHeight(BasemapWidgetDefs::TileHeight + 2 * BasemapWidgetDefs::TilePadding + BasemapWidgetDefs::NameHeight + BasemapWidgetDefs::TileMargin.Top + BasemapWidgetDefs::TileMargin.Bottom)
		.ItemWidth(BasemapWidgetDefs::TileWidth + 2 * BasemapWidgetDefs::TilePadding + BasemapWidgetDefs::TileMargin.Left + BasemapWidgetDefs::TileMargin.Right)
	];
	// clang-format on
}

const FSlateBrush* SArcGISMapCreatorBasemapWidget::GetBorderImage(TSharedPtr<STableRow<TSharedPtr<Item>>> InTableRowWidget) const
{
	if (!InTableRowWidget->IsSelected())
	{
		return FStyleDefaults::GetNoBrush();
	}

	if (InTableRowWidget->IsHovered())
	{
		return &TableRowStyle.ActiveHoveredBrush;
	}
	else
	{
		return &TableRowStyle.ActiveBrush;
	}
}

const FSlateBrush* SArcGISMapCreatorBasemapWidget::GetItemImage(TSharedPtr<Item> InItem) const
{
	auto mapComponent = Cast<UArcGISMapComponent>(MapCreatorUtilities::MapComponentManager::GetMapComponent());

	if (!mapComponent)
	{
		return InItem->ColorImageBrush;
	}

	if (InItem->RequiresAPIKey && mapComponent->GetEffectiveAPIKey().IsEmpty())
	{
		return InItem->GrayscaleImageBrush;
	}

	return InItem->ColorImageBrush;
}

FReply SArcGISMapCreatorBasemapWidget::HandleRemoveBasemapClicked(TSharedPtr<Item> InItem)
{
	if (InItem->CanBeRemoved)
	{
		Items->Remove(InItem);
		OnItemRemoved.ExecuteIfBound(InItem);
		Rebuild();
	}

	return FReply::Handled();
}

TSharedRef<ITableRow> SArcGISMapCreatorBasemapWidget::HandleTileViewGenerateTile(TSharedPtr<Item> InItem,
																				 const TSharedRef<STableViewBase>& InOwnerTable)
{
	TSharedPtr<STableRow<TSharedPtr<Item>>> TableRowWidget;

	// clang-format off
	SAssignNew(TableRowWidget, STableRow<TSharedPtr<Item>>, InOwnerTable)
	.Padding(BasemapWidgetDefs::TileMargin)
	.Style(FArcGISMapCreatorStyles::GetCommonStyleSet(), "ArcGISMapsSDKEditor.ArcGISMapCreatorBasemapWidget.TileTableRow");

	TSharedPtr<SOverlay> ImageOverlay;
	TSharedRef<SBorder> Content =
		SNew(SBorder)
		.Padding(BasemapWidgetDefs::TilePadding)
		.BorderImage(this, &SArcGISMapCreatorBasemapWidget::GetBorderImage, TableRowWidget)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SBox)
				.HeightOverride(BasemapWidgetDefs::TileHeight)
				.WidthOverride(BasemapWidgetDefs::TileWidth)
				[
					SAssignNew(ImageOverlay, SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SScaleBox)
						.Stretch(EStretch::ScaleToFill)
						[
							SNew(SImage)
							.Image(this, &SArcGISMapCreatorBasemapWidget::GetItemImage, InItem)
						]
					]
				]
			]
			+ SVerticalBox::Slot()
			.MaxHeight(BasemapWidgetDefs::NameHeight)
			.HAlign(HAlign_Center)
			.Padding(FMargin(0, 4, 0, 0))
			[
				SNew(STextBlock)
				.Text(FText::FromString(InItem->Name))
				.TextStyle(FArcGISMapCreatorStyles::GetCommonStyleSet(), "ArcGISMapsSDKEditor.ArcGISMapCreatorBasemapWidget.TileTableRow.Label")
				.OverflowPolicy(ETextOverflowPolicy::Ellipsis)
				.TextShapingMethod(ETextShapingMethod::FullShaping)
			]
		];
	// clang-format on

	if (InItem->CanBeRemoved)
	{
		// clang-format off
		ImageOverlay->AddSlot()
		.HAlign(EHorizontalAlignment::HAlign_Right)
		.VAlign(EVerticalAlignment::VAlign_Bottom)
		[
			SNew(SButton)
			.ButtonStyle(FArcGISMapCreatorStyles::GetCommonStyleSet(), "ArcGISMapsSDKEditor.ArcGISMapCreatorBasemapWidget.RemoveButton")
			.ContentPadding(7.0f)
			.OnClicked(this, &SArcGISMapCreatorBasemapWidget::HandleRemoveBasemapClicked, InItem)
			[
				SNew(SImage)
				.Image(FArcGISMapCreatorStyles::GetCommonStyleSet()->GetBrush("CrossIcon"))
				.ColorAndOpacity(FSlateColor::UseForeground())
				.DesiredSizeOverride(FVector2D(10, 10))
			]
		];
		// clang-format on
	}

	TableRowWidget->SetContent(Content);

	return TableRowWidget.ToSharedRef();
}

void SArcGISMapCreatorBasemapWidget::HandleTileViewSelectionChanged(TSharedPtr<Item> InItem, ESelectInfo::Type InSelectInfo)
{
	OnSelectionChanged.ExecuteIfBound(InItem);
}

void SArcGISMapCreatorBasemapWidget::Rebuild()
{
	TileView->RebuildList();
}

void SArcGISMapCreatorBasemapWidget::SetItems(TSharedPtr<TArray<TSharedPtr<Item>>> InItems)
{
	Items = std::move(InItems);

	TileView->SetListItemsSource(*Items);

	Rebuild();
}

void SArcGISMapCreatorBasemapWidget::SetSelectedItem(TSharedPtr<Item> InItem)
{
	if (!InItem)
	{
		TileView->ClearSelection();
	}
	else
	{
		TileView->SetSelection(InItem);
		TileView->RequestNavigateToItem(std::move(InItem));
	}
}

void SArcGISMapCreatorBasemapWidget::ScrollToItem(TSharedPtr<Item> InItem)
{
	if (InItem)
	{
		TileView->RequestNavigateToItem(std::move(InItem));
	}
}
