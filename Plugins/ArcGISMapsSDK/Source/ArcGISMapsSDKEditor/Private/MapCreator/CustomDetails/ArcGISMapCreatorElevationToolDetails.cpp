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
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorElevationToolDetails.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/STextComboBox.h"
#include "Widgets/Layout/SScaleBox.h"

#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

using namespace MapCreatorUtilities;

TSharedRef<IDetailCustomization> FArcGISMapCreatorElevationToolDetails::MakeInstance()
{
	return MakeShared<FArcGISMapCreatorElevationToolDetails>();
}

void FArcGISMapCreatorElevationToolDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	auto map = MapComponentManager::GetMapComponent();

	TArray<TWeakObjectPtr<UObject>> object;
	DetailBuilder.GetObjectsBeingCustomized(object);
	TObjectPtr<UArcGISMapCreatorElevationToolProperties> properties = Cast<UArcGISMapCreatorElevationToolProperties>(object[0]);

	constexpr char categoryName[] = "Elevation";
	auto& category = DetailBuilder.EditCategory(categoryName);

	DefaultElevationCheckbox =
		CreateCard(DetailBuilder, category, categoryName, "ElevationTool.Default", "Default Elevation", properties->IsDefaultElevationSource(), properties,
				   &FArcGISMapCreatorElevationToolDetails::SetDefaultCheckbox);
	CustomElevationCheckbox =
		CreateCard(DetailBuilder, category, categoryName, "ElevationTool.Custom", "Custom Elevation", properties->IsCustomElevationSource(), properties,
				   &FArcGISMapCreatorElevationToolDetails::SetCustomCheckbox);

	auto fileSelectCallback = MakeShared<FSimpleDelegate>(FSimpleDelegate::CreateLambda([map, properties]() {
		if (!map)
		{
			return;
		}

		if (map->GetIsElevationEnabled() && map->GetElevationSource() != properties->CustomElevationSource && properties->EnableCustomElevation)
		{
			map->SetElevationSource(properties->CustomElevationSource);
		}
	}));

	auto elevationSourceProperty = DetailBuilder.GetProperty("CustomElevationSource");
	DetailBuilder.HideProperty(elevationSourceProperty);
	MapCreatorUtilities::MapCreatorWidgetFactory::CreateFileSelectorField(category, categoryName, elevationSourceProperty,
																		  &properties->CustomElevationSource, fileSelectCallback);

	auto elevationAuthentication = DetailBuilder.GetProperty("ElevationAuthConfigID");
	DetailBuilder.HideProperty(elevationAuthentication);
	category.AddProperty(elevationAuthentication);
}

void FArcGISMapCreatorElevationToolDetails::SetDefaultCheckbox(ECheckBoxState state, TObjectPtr<UArcGISMapCreatorElevationToolProperties> properties)
{
	bool isChecked = state == ECheckBoxState::Checked ? true : false;
	properties->SetDefaultElevation(isChecked);
	properties->EnableCustomElevation = false;
	CustomElevationCheckbox->SetIsChecked(false);
}

void FArcGISMapCreatorElevationToolDetails::SetCustomCheckbox(ECheckBoxState state, TObjectPtr<UArcGISMapCreatorElevationToolProperties> properties)
{
	bool isChecked = state == ECheckBoxState::Checked ? true : false;
	properties->SetCustomElevation(isChecked);
	properties->EnableCustomElevation = isChecked;
	DefaultElevationCheckbox->SetIsChecked(false);
}

TSharedPtr<SCheckBox> FArcGISMapCreatorElevationToolDetails::CreateCard(
	IDetailLayoutBuilder& detailBuilder,
	IDetailCategoryBuilder& category,
	FString categoryName,
	const FName& imageName,
	const FString& cardName,
	bool isChecked,
	TObjectPtr<UArcGISMapCreatorElevationToolProperties> properties,
	void (FArcGISMapCreatorElevationToolDetails::*func)(ECheckBoxState state, TObjectPtr<UArcGISMapCreatorElevationToolProperties> properties))
{
	TSharedPtr<SCheckBox> checkbox;

	// clang-format off
	category.AddCustomRow(FText::FromString(categoryName))
	.IsValueEnabled(false)
	.WholeRowContent()
	.HAlign(EHorizontalAlignment::HAlign_Fill)
	[
		SNew(SBox)
		.Visibility(EVisibility::SelfHitTestInvisible)
		.Padding(FMargin(0, 10))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.FillHeight(1)
			.AutoHeight()
			.VAlign(EVerticalAlignment::VAlign_Fill)
			[
				SNew(SBox)
				.HeightOverride(66)
				[
					SNew(SScaleBox)
					.Stretch(EStretch::ScaleToFill)
					[
						SNew(SImage)
						.Image(FArcGISMapCreatorStyles::GetCommonStyleSet()->GetBrush(imageName))
					]
				]
			]
			+ SVerticalBox::Slot()
			.MaxHeight(26)
			.AutoHeight()
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(EHorizontalAlignment::HAlign_Fill)
				.VAlign(EVerticalAlignment::VAlign_Fill)
				[
					SNew(SImage)
					.Image(new FSlateBrush())
					.ColorAndOpacity(FSlateColor(FLinearColor(0.05f, 0.05f, 0.05f, 1.0f)))
				]
				+ SOverlay::Slot()
				.Padding(8, 0, 0, 0)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.FillWidth(0.1f)
					[
						SAssignNew(checkbox, SCheckBox)
						.IsChecked(isChecked)
						.OnCheckStateChanged(this, func, properties)
					]
					+ SHorizontalBox::Slot()
					.Padding(FMargin(0, 3))
					[
						SNew(STextBlock)
						.Text(FText::FromString(cardName))
						.Font(detailBuilder.GetDetailFont())
						.Justification(ETextJustify::Left)
						.Margin(FMargin(2, 4, 0, 0))
					]
				]
			]
		]
	];
	// clang-format on

	return checkbox;
}
