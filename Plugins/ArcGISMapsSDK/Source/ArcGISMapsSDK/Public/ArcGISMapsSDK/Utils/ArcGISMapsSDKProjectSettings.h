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

#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"

#include "ArcGISMapsSDKProjectSettings.generated.h"

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "ArcGIS Maps SDK Project Settings"))
class ARCGISMAPSSDK_API UArcGISMapsSDKProjectSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Authentication", meta = (DisplayName = "API Key"))
	FString APIKey;
};
