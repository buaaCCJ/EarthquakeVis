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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Location/ArcGISRotation.h"

#include "GeoRotation.generated.h"

USTRUCT(BlueprintType)
struct FGeoRotation
{
	GENERATED_BODY()

public:
	FGeoRotation();
	FGeoRotation(UArcGISRotation* InRotation);

	bool operator==(const FGeoRotation& other) const;
	bool operator!=(const FGeoRotation& other) const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ArcGISMapsSDK|Coordinates")
	float Heading = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ArcGISMapsSDK|Coordinates")
	float Pitch = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ArcGISMapsSDK|Coordinates")
	float Roll = 0;
};
