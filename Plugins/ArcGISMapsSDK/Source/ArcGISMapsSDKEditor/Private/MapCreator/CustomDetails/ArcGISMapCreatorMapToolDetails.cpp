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
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorMapToolDetails.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IPropertyUtilities.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SSegmentedControl.h"
#include "Widgets/Input/STextComboBox.h"
#include "Widgets/Layout/SScaleBox.h"

#include "ArcGISMapsSDK/Actors/ArcGISMapActor.h"
#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorAuthenticationTool.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

using namespace MapCreatorUtilities;

TSharedRef<IDetailCustomization> FArcGISMapCreatorMapToolDetails::MakeInstance()
{
	return MakeShared<FArcGISMapCreatorMapToolDetails>();
}

void FArcGISMapCreatorMapToolDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<TWeakObjectPtr<UObject>> object;
	DetailBuilder.GetObjectsBeingCustomized(object);
	TObjectPtr<UArcGISMapCreatorMapToolProperties> properties = Cast<UArcGISMapCreatorMapToolProperties>(object[0]);

	StyleMapTool(DetailBuilder, properties);
}

// Add New Data

void FArcGISMapCreatorMapToolDetails::StyleMapTool(IDetailLayoutBuilder& detailBuilder, TObjectPtr<UArcGISMapCreatorMapToolProperties> properties)
{
	auto world = GEditor->GetEditorWorldContext().World();
	AArcGISMapActor* mapActor = Cast<AArcGISMapActor>(UGameplayStatics::GetActorOfClass(world, AArcGISMapActor::StaticClass()));

	CreateLogo(detailBuilder);
	CreateMapTypeButton(detailBuilder, properties);
	CreateMapButton(detailBuilder, properties);
}

void FArcGISMapCreatorMapToolDetails::CreateLogo(IDetailLayoutBuilder& detailBuilder)
{
	constexpr const char* logoCategoryName = "ArcGIS Maps SDK for Unreal Engine";

	auto& logoCategory = detailBuilder.EditCategory(logoCategoryName);
	// clang-format off
	logoCategory.AddCustomRow(FText::FromString(logoCategoryName))
	[
		SNew(SScaleBox)
		[
			SNew(SImage)
			.Image(FArcGISMapCreatorStyles::GetCommonStyleSet()->GetBrush("EsriLogo"))
		]
	];
	// clang-format on
}

void FArcGISMapCreatorMapToolDetails::CreateMapTypeButton(IDetailLayoutBuilder& detailBuilder,
														  TObjectPtr<UArcGISMapCreatorMapToolProperties> properties)
{
	constexpr const char* mapTypeCategoryName = "MapType";

	detailBuilder.HideProperty(mapTypeCategoryName);

	auto& mapTypeCategory = detailBuilder.EditCategory(mapTypeCategoryName);

	// clang-format off
	mapTypeCategory.AddCustomRow(FText::FromString(mapTypeCategoryName))
	.WholeRowContent()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(1)
		[
			SNew(SSpacer)
		]
		+ SHorizontalBox::Slot()
		.FillWidth(4)
		[
			SNew(SSegmentedControl<EArcGISMapType::Type>)
			.Value(properties->MapType)
			.OnValueChanged(this, &FArcGISMapCreatorMapToolDetails::SetMapType, properties)
			+ SSegmentedControl<EArcGISMapType::Type>::Slot(EArcGISMapType::Type::Global)
			.Text(FText::FromString("Global"))
			+ SSegmentedControl<EArcGISMapType::Type>::Slot(EArcGISMapType::Type::Local)
			.Text(FText::FromString("Local"))
		]
		+ SHorizontalBox::Slot()
		.FillWidth(1)
		[
			SNew(SSpacer)
		]
	];
}

void FArcGISMapCreatorMapToolDetails::SetMapType(EArcGISMapType::Type InMapType, TObjectPtr<UArcGISMapCreatorMapToolProperties> properties)
{
	properties->MapType = InMapType;

	auto mapComponent = MapComponentManager::GetMapComponent();

	if (mapComponent)
	{
		mapComponent->SetMapType(InMapType);
	}
}

void FArcGISMapCreatorMapToolDetails::CreateMapButton(IDetailLayoutBuilder& detailBuilder, TObjectPtr<UArcGISMapCreatorMapToolProperties> properties)
{
	constexpr const char* mapCategoryName = "Create Map";
	auto& createMapButtonCategory = detailBuilder.EditCategory(mapCategoryName);
	auto propUtilities = detailBuilder.GetPropertyUtilities();
	auto buttonColor = FLinearColor(0.0f, 5.0f, 20.0f);
	auto mapComponent = MapComponentManager::GetMapComponent();

	if (mapComponent)
	{
		buttonColor = FLinearColor::Gray;
	}

	// clang-format off
	createMapButtonCategory.AddCustomRow(FText::FromString(mapCategoryName))
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(1)
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		[
			SNew(SSpacer)
		]
		+ SHorizontalBox::Slot()
		.FillWidth(0.5f)
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.HAlign(EHorizontalAlignment::HAlign_Fill)
			[
				SNew(SButton)
				.ButtonColorAndOpacity(buttonColor)
				.Content()
				[
					SNew(STextBlock)
					.Text(FText::FromString("Create"))
					.Justification(ETextJustify::Center)
					.Margin(FMargin(0, 2, 0, 0))
				]
				.OnClicked(this, &FArcGISMapCreatorMapToolDetails::CreateMap, properties, propUtilities)
				.IsEnabled(!mapComponent)
			]
		]
	];
	// clang-format on

	auto& originCategory = detailBuilder.EditCategory("OriginPosition");
	auto& extentCategory = detailBuilder.EditCategory("MapExtent");

	extentCategory.SetSortOrder(originCategory.GetSortOrder() + 1);
	createMapButtonCategory.SetSortOrder(originCategory.GetSortOrder() + 2);
}

FReply FArcGISMapCreatorMapToolDetails::CreateMap(TObjectPtr<UArcGISMapCreatorMapToolProperties> properties, TSharedRef<IPropertyUtilities> utilities)
{
	auto world = GEditor->GetEditorWorldContext().World();

	AArcGISMapActor* mapActor = Cast<AArcGISMapActor>(UGameplayStatics::GetActorOfClass(world, AArcGISMapActor::StaticClass()));

	if (mapActor)
	{
		return FReply::Handled();
	}

	mapActor = world->SpawnActor<AArcGISMapActor>();
	auto mapComponent = mapActor->GetMapComponent();

	mapComponent->SetOriginPosition(properties->OriginPosition);
	mapComponent->SetIsOriginAtPlanetCenter(properties->bIsOriginAtPlanetCenter);

	mapComponent->SetExtent(properties->MapExtent);
	mapComponent->SetMapType(properties->MapType);
	
	mapComponent->SetAPIKey(UArcGISMapCreatorAuthenticationToolProperties::GetStoredAPIKey());

	//Default values for other tabs
	{
		mapComponent->SetIsElevationEnabled(true);
		mapComponent->SetElevationSource(TEXT("https://elevation3d.arcgis.com/arcgis/rest/services/WorldElevation3D/Terrain3D/ImageServer"));
		mapComponent->SetBasemapSourceAndType(TEXT("https://www.arcgis.com/home/item.html?id=c7d2b5c334364e8fb5b73b0f4d6a779b"),
											  EBaseMapTypes::Basemap);
	}

	utilities->ForceRefresh();

	return FReply::Handled();
}
