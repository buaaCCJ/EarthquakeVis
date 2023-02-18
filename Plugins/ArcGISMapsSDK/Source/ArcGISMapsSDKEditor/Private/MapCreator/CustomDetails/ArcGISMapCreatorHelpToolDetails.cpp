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
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorHelpToolDetails.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Widgets/Colors/SColorBlock.h"

#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

using namespace MapCreatorUtilities;

const FString URL_DocumentationHomepage = "https://developers.arcgis.com/unreal-engine/";
const FString URL_API = "https://developers.arcgis.com/unreal-engine/api-reference/";
const FString URL_Samples = "https://github.com/esri/arcgis-maps-sdk-unreal-engine-samples/";
const FString URL_Forums = "https://community.esri.com/t5/arcgis-maps-sdk-for-unreal-engine-questions/bd-p/arcgis-maps-sdk-unreal-engine-questions";
const FString URL_Support = "https://support.esri.com/en/Products/Developers/arcgis-maps-sdks/arcgis-maps-sdk-for-unreal-engine";
const FString URL_ReleaseNotes = "https://developers.arcgis.com/unreal-engine/reference/release-notes/";

TSharedRef<IDetailCustomization> FArcGISMapCreatorHelpToolDetails::MakeInstance()
{
	return MakeShared<FArcGISMapCreatorHelpToolDetails>();
}

void FArcGISMapCreatorHelpToolDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	const char* docCategoryName = "Documentation";
	IDetailCategoryBuilder& docCategory = DetailBuilder.EditCategory(docCategoryName);

	MapCreatorWidgetFactory::CreateURLField("Homepage", URL_DocumentationHomepage, docCategory, docCategoryName);
	MapCreatorWidgetFactory::CreateURLField("API Reference", URL_API, docCategory, docCategoryName);
	MapCreatorWidgetFactory::CreateURLField("Samples", URL_Samples, docCategory, docCategoryName);

	const char* supportCategoryName = "Support";
	IDetailCategoryBuilder& supportCategory = DetailBuilder.EditCategory(supportCategoryName);

	MapCreatorWidgetFactory::CreateURLField("Community", URL_Forums, supportCategory, supportCategoryName);
	MapCreatorWidgetFactory::CreateURLField("SDK Support Resources", URL_Support, supportCategory, supportCategoryName);
	MapCreatorWidgetFactory::CreateURLField("Get API Keys", URL_GetAPIKey, supportCategory, supportCategoryName);
	MapCreatorWidgetFactory::CreateURLField("Release Notes", URL_ReleaseNotes, supportCategory, supportCategoryName);

	const char* aboutCategoryName = "About";
	IDetailCategoryBuilder& aboutCategory = DetailBuilder.EditCategory(aboutCategoryName);

	// clang-format off
	aboutCategory.AddCustomRow(FText::FromString(aboutCategoryName))
	.WholeRowContent()
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.Padding(FMargin(0, 20, 0, 0))
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("ArcGIS Maps SDK for Unreal Engine 1.1.0")))
		]
		+ SVerticalBox::Slot()
		.Padding(FMargin(0, 2, 0, 18))
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Copyright ©2022 Esri Inc. All Rights Reserved")))
		]
		+ SVerticalBox::Slot()
		.MaxHeight(1)
		[
			SNew(SColorBlock)
			.Color(FLinearColor(1, 1, 1, 1))
		]
		+ SVerticalBox::Slot()
		.Padding(FMargin(0, 4, 0, 20))
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Special thanks to our beta users")))
		]
	];
	// clang-format on
}
