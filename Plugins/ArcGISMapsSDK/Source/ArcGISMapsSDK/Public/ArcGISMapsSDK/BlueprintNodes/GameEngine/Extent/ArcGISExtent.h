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

#include "ArcGISExtent.generated.h"

class UArcGISPoint;

namespace Esri
{
namespace GameEngine
{
namespace Extent
{
class ArcGISExtent;
} // namespace Extent
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Abstract class of any kind of extent
/// </summary>
/// <remarks>
/// Abstract class of any kind of extent.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISExtent :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISExtent")
    /// <summary>
    /// The center of the extent.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetCenter();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Extent::ArcGISExtent> APIObject;
};