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
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"

#include "DesktopPlatformModule.h"
#include "DetailWidgetRow.h"
#include "EditorDirectories.h"
#include "Engine/Selection.h"
#include "GameFramework/Actor.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/FileManager.h"
#include "IDesktopPlatform.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SHyperlink.h"

#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorStyles.h"

#define LOCTEXT_NAMESPACE "UtilitiesText"

MapCreatorUtilities::MapComponentFetcher MapCreatorUtilities::MapComponentManager::CurrentMapComponentFetcher = nullptr;

IArcGISMapComponentInterface* MapCreatorUtilities::MapComponentManager::GetMapComponent()
{
	if (CurrentMapComponentFetcher)
	{
		return CurrentMapComponentFetcher();
	}

	return GEditor->GetEditorWorldContext().World()->GetSubsystem<UArcGISMapsSDKSubsystem>()->GetMapComponent();
}

void MapCreatorUtilities::MapComponentManager::SetMapComponentFetcher(MapComponentFetcher InMapComponentFetcher)
{
	CurrentMapComponentFetcher = InMapComponentFetcher;
}

void MapCreatorUtilities::MapComponentManager::MarkPackageDirty()
{
	auto mapComponent = GetMapComponent();

	if (!mapComponent)
	{
		return;
	}

	mapComponent->MarkPackageDirty();
}

void MapCreatorUtilities::MapCreatorWidgetFactory::CreateFileSelectorField(IDetailCategoryBuilder& category,
																		   const FString& categoryName,
																		   TSharedRef<IPropertyHandle> inProperty,
																		   FString* propertySource,
																		   TSharedPtr<FSimpleDelegate> callback)
{
	// clang-format off
	category.AddCustomRow(FText::FromString(categoryName))
	.NameContent()
	[
		inProperty->CreatePropertyNameWidget()
	]
	.ValueContent()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(2)
		[
			inProperty->CreatePropertyValueWidget()
		]
		+ SHorizontalBox::Slot()
		.MaxWidth(25)
		[
			SNew(SButton)
			.Text(FText::FromString("..."))
			.ContentPadding(FMargin(-6, 0, -8, 0))
			.OnClicked(FOnClicked::CreateLambda([propertySource, callback]()
			{
				auto FileName = PromptForFile();

				if (FileName.IsEmpty())
				{
					if (callback)
					{
						callback->Execute();
					}

					return FReply::Handled();
				}

				*propertySource = FileName.TrimStartAndEnd();

				if (callback)
				{
					callback->Execute();
				}

				return FReply::Handled();
			}))
		]
	];
	// clang-format on
}

FString MapCreatorUtilities::MapCreatorWidgetFactory::PromptForFile()
{
	if (IDesktopPlatform* Platform = FDesktopPlatformModule::Get())
	{
		const void* ParentWindowWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);

		TArray<FString> OpenFilenames;
		FString OpenFilePath = FEditorDirectories::Get().GetLastDirectory(ELastDirectory::GENERIC_OPEN);

		// clang-format off
#if PLATFORM_WINDOWS
		auto FileTypeText = TEXT("All|*.tpk;*.tpkx;*.vtpk;*.slpk|Scene Layer Packages|*.slpk|Tile Packages|*.tpk;*.tpkx;*.vtpk");
#else
		auto FileTypeText = TEXT("All|*.tpk;*.tpkx;*.vtpk;*.slpk|Scene Layer Packages (.slpk)|*.slpk|Tile Packages (.tpk,.tpkx,.vtpk)|*.tpk;*.tpkx;*.vtpk");
#endif

		if (Platform->OpenFileDialog(ParentWindowWindowHandle, // ParentWindowHandle
									 *LOCTEXT("ImportMap_ChooseFile", "Choose map asset source file").ToString(), // DialogTitle
									 OpenFilePath, // DefaultPath
									 TEXT(""), // DefaultFile
									 FileTypeText, // FileTypes
									 EFileDialogFlags::None, // Flags
									 OpenFilenames)) // OutFilenames
		{
			return IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*(OpenFilenames[0]));
		}
		// clang-format on
	}

	return FString();
}

void MapCreatorUtilities::MapCreatorWidgetFactory::CreateURLField(const FString text,
																  const FString url,
																  IDetailCategoryBuilder& category,
																  const char* categoryName)
{
	// clang-format off
	category.AddCustomRow(FText::FromString(categoryName))
	[
		SNew(SHyperlink)
		.Text(FText::FromString(text))
		.Style(&FArcGISMapCreatorStyles::GetCommonStyleSet()->GetWidgetStyle<FHyperlinkStyle>("HyperlinkStyle"))
		.OnNavigate(FSimpleDelegate::CreateLambda([url]()
		{
			FPlatformProcess::LaunchURL(*url, nullptr, nullptr);
		}))
	];
	// clang-format on
}
#undef LOCTEXT_NAMESPACE
