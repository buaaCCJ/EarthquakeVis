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

#include "ArcGISViewportProperties.generated.h"

USTRUCT(Blueprintable)
struct FArcGISViewportProperties
{
	GENERATED_BODY()

	int32 ViewportWidthPixels;
	int32 ViewportHeightPixels;
	float HorizontalFieldOfViewDegrees;
	float VerticalFieldOfViewDegrees;
	float VerticalDistortionFactor;
};
