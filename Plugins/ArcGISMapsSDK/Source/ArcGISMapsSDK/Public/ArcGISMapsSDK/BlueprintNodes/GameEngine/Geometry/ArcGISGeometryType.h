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

#include "ArcGISGeometryType.generated.h"

UENUM(BlueprintType, meta=(ScriptName="ArcGISGeometryType"))
namespace EArcGISGeometryType
{
    enum Type
    {
        Null = 0 UMETA(Hidden),
        
        /// <summary>
        /// Point geometry.
        /// </summary>
        /// <since>1.0.0</since>
        Point = 1,
        
        /// <summary>
        /// Envelope geometry.
        /// </summary>
        /// <since>1.0.0</since>
        Envelope = 2,
        
        /// <summary>
        /// Polyline geometry.
        /// </summary>
        /// <since>1.0.0</since>
        Polyline = 3,
        
        /// <summary>
        /// Polygon geometry.
        /// </summary>
        /// <since>1.0.0</since>
        Polygon = 4,
        
        /// <summary>
        /// Multipoint geometry.
        /// </summary>
        /// <since>1.0.0</since>
        Multipoint = 5
    };
}