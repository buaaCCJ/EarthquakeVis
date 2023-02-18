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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayer.h"

#include "ArcGISUnknownLayer.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
class ArcGISUnknownLayer;
} // namespace Layers
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// An instance of this class represents a layer whose type could not be determined.
/// </summary>
/// <remarks>
/// The layer will not be persisted in the string returned by <see cref="">Map.toJSON</see>,
/// and will not be drawn by the  view.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISUnknownLayer :
    public UArcGISLayer
{
    GENERATED_BODY()
};