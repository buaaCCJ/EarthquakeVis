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

#include "ArcGISViewStateMessageType.generated.h"

UENUM(BlueprintType, meta=(ScriptName="ArcGISViewStateMessageType"))
namespace EArcGISViewStateMessageType
{
    enum Type
    {
        Null = 0 UMETA(Hidden),
        
        /// <summary>
        /// Message contains error information.
        /// </summary>
        /// <since>1.0.0</since>
        Error = 1,
        
        /// <summary>
        /// Message contains warning information.
        /// </summary>
        /// <since>1.0.0</since>
        Warning = 2
    };
}