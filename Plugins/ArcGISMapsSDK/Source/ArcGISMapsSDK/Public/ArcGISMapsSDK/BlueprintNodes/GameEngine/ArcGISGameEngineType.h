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

#include "ArcGISGameEngineType.generated.h"

UENUM(BlueprintType, meta=(ScriptName="ArcGISGameEngineType"))
namespace EArcGISGameEngineType
{
    enum Type
    {
        Null = 0 UMETA(Hidden),
        
        /// <summary>
        /// Unity game engine
        /// </summary>
        /// <since>1.0.0</since>
        Unity = 1,
        
        /// <summary>
        /// Unreal Engine game engine
        /// </summary>
        /// <since>1.0.0</since>
        UnrealEngine = 2
    };
}