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

#include "ArcGISMapsSDK/Utils/ArcGISMapExtentShapes.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"

#include "ArcGISExtentInstanceData.generated.h"

USTRUCT(Blueprintable)
struct FArcGISExtentInstanceData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "MapExtent", meta = (DisplayName = "Geographic Center", HideZ = true))
	FGeoPosition ExtentCenter;

	UPROPERTY(EditAnywhere, Category = "MapExtent", meta = (DisplayName = "Extent Shape"))
	EMapExtentShapes ExtentShape = EMapExtentShapes::Square;

	UPROPERTY(EditAnywhere, Category = "MapExtent", meta = (DisplayName = "Shape Dimensions"))
	FVector2D ShapeDimensions = FVector2D(0, 0);

	bool operator==(const FArcGISExtentInstanceData& other) const
	{
		return ExtentCenter == other.ExtentCenter && ExtentShape == other.ExtentShape && ShapeDimensions == other.ShapeDimensions;
	}

	bool operator!=(const FArcGISExtentInstanceData& other) const
	{
		return ExtentCenter != other.ExtentCenter || ExtentShape != other.ExtentShape || ShapeDimensions != other.ShapeDimensions;
	}
};
