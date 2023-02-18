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
#include "UObject/StrongObjectPtr.h"

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerType.h"
#include "ArcGISMapsSDK/Utils/AuthGuid.h"

#include "ArcGISLayerInstanceData.generated.h"

USTRUCT(Blueprintable)
struct FArcGISLayerInstanceData
{
	GENERATED_USTRUCT_BODY()

	FGuid ID;

	UPROPERTY(EditAnywhere, Category = "ArcGISMapComponent")
	FString Name;

	UPROPERTY(EditAnywhere, Category = "ArcGISMapComponent")
	FString Source;

	UPROPERTY(EditAnywhere, Category = "ArcGISMapComponent", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	double Opacity = 1;

	UPROPERTY(EditAnywhere, Category = "ArcGISMapComponent")
	bool bIsVisible = true;

	UPROPERTY(EditAnywhere, Category = "ArcGISMapComponent")
	TEnumAsByte<EArcGISLayerType::Type> Type = EArcGISLayerType::ArcGISImageLayer;

	UPROPERTY(EditAnywhere, Category = "ArcGISMapComponent", meta = (DisplayName = "Authentication"))
	FAuthGuid AuthConfigID;

	TStrongObjectPtr<UArcGISLayer> APIObject;

	friend bool operator==(const FArcGISLayerInstanceData& Left, const FArcGISLayerInstanceData& Right);
	friend bool operator!=(const FArcGISLayerInstanceData& Left, const FArcGISLayerInstanceData& Right);
};
