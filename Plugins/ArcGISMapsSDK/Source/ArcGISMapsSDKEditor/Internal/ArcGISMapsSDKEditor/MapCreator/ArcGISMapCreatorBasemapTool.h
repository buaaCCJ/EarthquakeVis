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

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "InteractiveToolBuilder.h"
#include "Types/SlateEnums.h"
#include "UObject/StructOnScope.h"

#include "ArcGISMapsSDK/Components/BaseMapTypes.h"
#include "ArcGISMapsSDK/Utils/AuthGuid.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorTool.h"
#include "ArcGISMapsSDKEditor/MapCreator/SArcGISMapCreatorBasemapWidget.h"

#include "ArcGISMapCreatorBasemapTool.generated.h"

UCLASS()
class ARCGISMAPSSDKEDITOR_API UArcGISMapCreatorBasemapToolBuilder : public UInteractiveToolBuilder
{
	GENERATED_BODY()

public:
	virtual bool CanBuildTool(const FToolBuilderState& SceneState) const override;
	virtual UInteractiveTool* BuildTool(const FToolBuilderState& SceneState) const override;
};

USTRUCT(BlueprintType)
struct FBasemapItem
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, Category = NoCategory)
	FString Source;

	UPROPERTY(EditAnywhere, Category = NoCategory)
	EBaseMapTypes Type = EBaseMapTypes::Basemap;

	UPROPERTY(EditAnywhere, Category = NoCategory, meta = (BasemapAuth = true))
	FAuthGuid Authentication;

	UPROPERTY(EditAnywhere, Category = NoCategory)
	FString Name;

	bool operator==(const FBasemapItem& other)
	{
		return Source == other.Source && Type == other.Type && Authentication == other.Authentication && Name == other.Name;
	}

	bool operator!=(const FBasemapItem& other)
	{
		return !(*this == other); 
	}
};

UCLASS(Config = ArcGISBasemapEditorTool)
class ARCGISMAPSSDKEDITOR_API UArcGISMapCreatorBasemapTool : public UArcGISMapCreatorTool
{
	GENERATED_BODY()

public:
	// UInteractiveTool
	virtual void Setup() override;

	// UArcGISMapCreatorTool
	TSharedPtr<SWidget> GetInlineContent() const override;

private:
	FReply HandleAddNewClicked();
	void HandleBasemapWidgetSelectionChanged(TSharedPtr<SArcGISMapCreatorBasemapWidget::Item> InItem);
	void HandleCustomBasemapWidgetRemoved(TSharedPtr<SArcGISMapCreatorBasemapWidget::Item> InItem);
	void LoadBasemapSettings();

	TSharedPtr<TArray<TSharedPtr<SArcGISMapCreatorBasemapWidget::Item>>> BasemapWidgetItems;
	TSharedPtr<SArcGISMapCreatorBasemapWidget> BasemapWidget;
	TSharedPtr<SWidget> InlineContent;
	TSharedPtr<SArcGISMapCreatorBasemapWidget::Item> SelectedItem;

	UPROPERTY(Config)
	TArray<FBasemapItem> CustomBasemaps;
};
