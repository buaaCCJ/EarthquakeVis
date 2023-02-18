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

#include "ArcGISMapsSDK/Components/ArcGISMapComponentInterface.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"

#include "ArcGISMapCreatorMapTool.generated.h"

UENUM()
enum EMapExtentType
{
	Square = 0,
	Rectangle = 1,
	Circle = 2,
};

UCLASS()
class ARCGISMAPSSDKEDITOR_API UArcGISMapCreatorMapToolBuilder : public UInteractiveToolBuilder
{
	GENERATED_BODY()

public:
	// UInteractiveToolBuilder
	bool CanBuildTool(const FToolBuilderState& SceneState) const override;
	UInteractiveTool* BuildTool(const FToolBuilderState& SceneState) const override;
	void PostSetupTool(UInteractiveTool* Tool, const FToolBuilderState& SceneState) const override;
};

UCLASS(Transient)
class ARCGISMAPSSDKEDITOR_API UArcGISMapCreatorMapToolProperties : public UInteractiveToolPropertySet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = MapType)
	TEnumAsByte<EArcGISMapType::Type> MapType;

	UPROPERTY(EditAnywhere, Category = OriginPosition, meta = (DisplayName = "Origin At Planet Center", EditConditionHides, EditCondition = "MapType==EArcGISMapType::Global"))
	bool bIsOriginAtPlanetCenter = false;

	UPROPERTY(EditAnywhere, Category = OriginPosition, meta = (EditConditionHides, EditCondition = "bIsOriginAtPlanetCenter==false||MapType==EArcGISMapType::Local"))
	FGeoPosition OriginPosition;

	UPROPERTY(EditAnywhere, Category = MapExtent, meta = (EditConditionHides, EditCondition = "MapType==EArcGISMapType::Local"))
	bool EnableExtent = false;

	UPROPERTY(EditAnywhere, Category = MapExtent, meta = (EditConditionHides, EditCondition = "EnableExtent==true&&MapType==EArcGISMapType::Local"))
	FArcGISExtentInstanceData MapExtent;

	IArcGISMapComponentInterface* MapComponent{nullptr};
};

UCLASS()
class ARCGISMAPSSDKEDITOR_API UArcGISMapCreatorMapTool : public UInteractiveTool
{
	GENERATED_BODY()

public:
	// UInteractiveTool
	void Setup() override;
	void OnPropertyModified(UObject* PropertySet, FProperty* Property) override;

	UPROPERTY()
	TObjectPtr<UArcGISMapCreatorMapToolProperties> Properties;

private:
	double MinExtentDimension = 0;
};
