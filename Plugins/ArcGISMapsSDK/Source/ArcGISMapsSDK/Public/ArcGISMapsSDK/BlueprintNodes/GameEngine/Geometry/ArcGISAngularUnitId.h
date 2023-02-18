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

#include "ArcGISAngularUnitId.generated.h"

UENUM(BlueprintType, meta=(ScriptName="ArcGISAngularUnitId"))
namespace EArcGISAngularUnitId
{
    enum Type
    {
        /// <summary>
        /// Indicates that the unit of angular measurement is a custom unit, or is a unit not listed in the enumerated type.
        /// This value may be returned from an AngularUnit created from a WKID of a less commonly used unit of measurement
        /// that does not have an equivalent value in this enumeration.
        /// </summary>
        /// <since>1.0.0</since>
        Other = 0,
        
        /// <summary>
        /// Indicates an angular measurement in degrees.
        /// This unit has a WKID of 9102.
        /// </summary>
        /// <since>1.0.0</since>
        Degrees = 9102,
        
        /// <summary>
        /// Indicates an angular measurement in grads.
        /// This unit has a WKID of 9105.
        /// </summary>
        /// <since>1.0.0</since>
        Grads = 9105,
        
        /// <summary>
        /// Indicates an angular measurement in minutes, equal to one-sixtieth of a degree.
        /// This unit has a WKID of 9103.
        /// </summary>
        /// <since>1.0.0</since>
        Minutes = 9103,
        
        /// <summary>
        /// Indicates an angular measurement in radians.
        /// This unit has an WKID of 9101.
        /// </summary>
        /// <since>1.0.0</since>
        Radians = 9101,
        
        /// <summary>
        /// Indicates an angular measurement in seconds, equal to one-sixtieth of a minute.
        /// This unit has a WKID of 9104.
        /// </summary>
        /// <since>1.0.0</since>
        Seconds = 9104
    };
}