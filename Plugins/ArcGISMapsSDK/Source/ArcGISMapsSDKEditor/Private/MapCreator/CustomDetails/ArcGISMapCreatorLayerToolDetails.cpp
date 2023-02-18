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
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorLayerToolDetails.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"

#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"

using namespace MapCreatorUtilities;

TSharedRef<IDetailCustomization> FArcGISMapCreatorLayerToolDetails::MakeInstance()
{
	return MakeShared<FArcGISMapCreatorLayerToolDetails>();
}

void FArcGISMapCreatorLayerToolDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	MapComponent = Cast<UArcGISMapComponent>(MapComponentManager::GetMapComponent());

	TArray<TWeakObjectPtr<UObject>> object;
	DetailBuilder.GetObjectsBeingCustomized(object);
	Properties = Cast<UArcGISMapCreatorLayerToolProperties>(object[0]);

	StyleAddNewData(DetailBuilder);
}

// Add New Data

void FArcGISMapCreatorLayerToolDetails::StyleAddNewData(IDetailLayoutBuilder& detailBuilder)
{
	constexpr char categoryName[] = "AddNewData";
	auto& addDataCategory = detailBuilder.EditCategory(categoryName);

	TArray<TSharedRef<IPropertyHandle>> categoryProperties;
	addDataCategory.GetDefaultProperties(categoryProperties);

	for (auto& prop : categoryProperties)
	{
		addDataCategory.GetParentLayout().HideProperty(prop);

		if (prop->GetProperty()->GetFName() == "LayerSource")
		{
			MapCreatorUtilities::MapCreatorWidgetFactory::CreateFileSelectorField(addDataCategory, categoryName, prop, &Properties->LayerSource,
																				  nullptr);
		}
		else
		{
			addDataCategory.AddProperty(prop);
		}
	}

	// clang-format off
	addDataCategory.AddCustomRow(FText::FromString(categoryName))
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(0.5f)
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		[
			SNew(SSpacer)
		]
		+ SHorizontalBox::Slot()
		.FillWidth(1)
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.HAlign(EHorizontalAlignment::HAlign_Fill)
			[
				SNew(SButton)
				.Content()
				[
					SNew(SBox)
					.Content()
					[
						SNew(STextBlock)
						.Text(FText::FromString("Clear"))
						.Justification(ETextJustify::Center)
						.Margin(FMargin(0, 2, 0, 0))
					]
				]
				.OnClicked(this, &FArcGISMapCreatorLayerToolDetails::ClearFields)
			]
			+ SHorizontalBox::Slot()
			.HAlign(EHorizontalAlignment::HAlign_Fill)
			.Padding(12, 0, 0, 0)
			[
				SNew(SButton)
				.ButtonColorAndOpacity(FLinearColor(0.0f, 5.0f, 20.0f))
				.Content()
				[
					SNew(STextBlock)
					.Text(FText::FromString("Add"))
					.Justification(ETextJustify::Center)
					.Margin(FMargin(0, 2, 0, 0))
				]
				.OnClicked(this, &FArcGISMapCreatorLayerToolDetails::AddLayer)
			]
		]
	];
	// clang-format on
}

FReply FArcGISMapCreatorLayerToolDetails::ClearFields()
{
	Properties->LayerName = "";
	Properties->LayerSource = "";
	Properties->LayerType = EArcGISLayerType::ArcGISImageLayer;
	return FReply::Handled();
}

FReply FArcGISMapCreatorLayerToolDetails::AddLayer()
{
	if (Properties->LayerSource == "" || !MapComponent)
	{
		return FReply::Handled();
	}

	FMapCreatorLayer mapCreatorLayer;
	{
		mapCreatorLayer.Name = Properties->LayerName;
		mapCreatorLayer.Source = Properties->LayerSource;
		mapCreatorLayer.Type = Properties->LayerType;
		mapCreatorLayer.AuthConfigID = Properties->AuthConfigID;
	}

	Properties->Layers.Add(mapCreatorLayer);

	Properties->UpdateMapComponentLayers();

	ClearFields();

	return FReply::Handled();
}
