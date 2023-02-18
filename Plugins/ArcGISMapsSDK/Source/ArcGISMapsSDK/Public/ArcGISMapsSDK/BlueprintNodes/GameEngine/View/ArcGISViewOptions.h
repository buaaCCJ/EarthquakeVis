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
#include "UObject/Object.h"

#include "ArcGISViewOptions.generated.h"

USTRUCT(BlueprintType, meta=(ScriptName="ArcGISViewOptions"))
struct FArcGISViewOptions
{
    GENERATED_BODY()

    /// <summary>
    /// Forces data to be loaded for invisible layers
    /// </summary>
    /// <remarks>
    /// Default value is false.
    /// </remarks>
    /// <since>1.0.0</since>
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ArcGISMapsSDK|ArcGISViewOptions")
    bool LoadDataFromInvisibleLayers;
};