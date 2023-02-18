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

#include "Input/Reply.h"
#include "Styling/SlateTypes.h"
#include "Widgets/SCompoundWidget.h"

class FStructOnScope;
class ITableRow;
class STableViewBase;
template <typename ItemType>
class STableRow;
template <typename ItemType>
class STileView;

class SArcGISMapCreatorBasemapWidget : public SCompoundWidget
{
public:
	struct Item
	{
		bool CanBeRemoved;
		const FSlateBrush* ColorImageBrush;
		const FSlateBrush* GrayscaleImageBrush;
		FString Name;
		bool RequiresAPIKey;
		TSharedPtr<FStructOnScope> UserData;
	};

public:
	DECLARE_DELEGATE_OneParam(FOnSelectionChanged, TSharedPtr<Item>);
	DECLARE_DELEGATE_OneParam(FOnItemRemoved, TSharedPtr<Item>);

	// clang-format off
	SLATE_BEGIN_ARGS(SArcGISMapCreatorBasemapWidget) {}
		SLATE_ARGUMENT(TSharedPtr<TArray<TSharedPtr<Item>>>, Items)

		SLATE_EVENT(FOnSelectionChanged, OnSelectionChanged)
		SLATE_EVENT(FOnItemRemoved, OnItemRemoved)
	SLATE_END_ARGS()
	// clang-format on

	void Construct(const FArguments& InArgs);

	void Rebuild();
	void SetItems(TSharedPtr<TArray<TSharedPtr<Item>>> InItems);
	void SetSelectedItem(TSharedPtr<Item> InItem);
	void ScrollToItem(TSharedPtr<Item> InItem);

private:
	const FSlateBrush* GetBorderImage(TSharedPtr<STableRow<TSharedPtr<Item>>> InTableRowWidget) const;
	const FSlateBrush* GetItemImage(TSharedPtr<Item> InItem) const;
	FReply HandleRemoveBasemapClicked(TSharedPtr<Item> InItem);
	TSharedRef<ITableRow> HandleTileViewGenerateTile(TSharedPtr<Item> InItem, const TSharedRef<STableViewBase>& InOwnerTable);
	void HandleTileViewSelectionChanged(TSharedPtr<Item> InItem, ESelectInfo::Type InSelectInfo);

	TSharedPtr<TArray<TSharedPtr<Item>>> Items;
	FOnItemRemoved OnItemRemoved;
	FOnSelectionChanged OnSelectionChanged;
	FTableRowStyle TableRowStyle;
	TSharedPtr<STileView<TSharedPtr<Item>>> TileView;
};
