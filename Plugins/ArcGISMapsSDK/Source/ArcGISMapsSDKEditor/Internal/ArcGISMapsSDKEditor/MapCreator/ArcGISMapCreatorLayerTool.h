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
#include "InteractiveToolBuilder.h"
#include "UObject/NoExportTypes.h"

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerType.h"
#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"

#include "ArcGISMapCreatorLayerTool.generated.h"

USTRUCT()
struct FMapCreatorLayer
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "MapCreatorLayer")
	FString Name;

	UPROPERTY(EditAnywhere, Category = "MapCreatorLayer")
	FString Source;

	UPROPERTY(EditAnywhere, Category = "MapCreatorLayer", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	double Opacity = 1;

	UPROPERTY(EditAnywhere, Category = "MapCreatorLayer")
	bool bIsVisible = true;

	UPROPERTY(EditAnywhere, Category = "MapCreatorLayer")
	TEnumAsByte<EArcGISLayerType::Type> Type = EArcGISLayerType::ArcGISImageLayer;

	UPROPERTY(EditAnywhere, Category = "MapCreatorLayer", meta = (DisplayName = "Authentication"))
	FAuthGuid AuthConfigID;
};

UCLASS()
class ARCGISMAPSSDKEDITOR_API UArcGISMapCreatorLayerToolBuilder : public UInteractiveToolBuilder
{
	GENERATED_BODY()

public:
	// UInteractiveToolBuilder
	bool CanBuildTool(const FToolBuilderState& SceneState) const override;
	UInteractiveTool* BuildTool(const FToolBuilderState& SceneState) const override;
	void PostSetupTool(UInteractiveTool* Tool, const FToolBuilderState& SceneState) const override;
};

UCLASS(Transient)
class ARCGISMAPSSDKEDITOR_API UArcGISMapCreatorLayerToolProperties : public UInteractiveToolPropertySet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = AddNewData, meta = (DisplayName = "Type"))
	TEnumAsByte<EArcGISLayerType::Type> LayerType = EArcGISLayerType::ArcGISImageLayer;

	UPROPERTY(EditAnywhere, Category = AddNewData, meta = (DisplayName = "Source"))
	FString LayerSource;

	UPROPERTY(EditAnywhere, Category = AddNewData, meta = (DisplayName = "Name"))
	FString LayerName;

	UPROPERTY(EditAnywhere, Category = AddNewData, meta = (DisplayName = "Authentication"))
	FAuthGuid AuthConfigID;

	UPROPERTY(EditAnywhere, Category = Layers, meta = (DisplayName = "Layers"))
	TArray<FMapCreatorLayer> Layers;

	void UpdateMapComponentLayers();
};

UCLASS()
class ARCGISMAPSSDKEDITOR_API UArcGISMapCreatorLayerTool : public UInteractiveTool
{
	GENERATED_BODY()

public:
	// UInteractiveTool
	void Setup() override;
	void OnPropertyModified(UObject* PropertySet, FProperty* Property) override;

	UPROPERTY()
	TObjectPtr<UArcGISMapCreatorLayerToolProperties> Properties;
};
