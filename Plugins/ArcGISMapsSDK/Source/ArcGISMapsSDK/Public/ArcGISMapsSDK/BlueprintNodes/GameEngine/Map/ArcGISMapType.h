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

#include "ArcGISMapType.generated.h"

UENUM(BlueprintType, meta=(ScriptName="ArcGISMapType"))
namespace EArcGISMapType
{
    enum Type
    {
        /// <summary>
        /// Global Type.
        /// </summary>
        /// <since>1.0.0</since>
        Global = 0,
        
        /// <summary>
        /// Local Type.
        /// </summary>
        /// <since>1.0.0</since>
        Local = 1
    };
}