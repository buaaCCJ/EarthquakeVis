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

#include "ArcGISLayerType.generated.h"

UENUM(BlueprintType, meta=(ScriptName="ArcGISLayerType"))
namespace EArcGISLayerType
{
    enum Type
    {
        /// <summary>
        /// An imagery layer
        /// </summary>
        /// <since>1.0.0</since>
        ArcGISImageLayer = 0,
        
        /// <summary>
        /// A 3D object scene layer
        /// </summary>
        /// <since>1.0.0</since>
        ArcGIS3DObjectSceneLayer = 1,
        
        /// <summary>
        /// An integrated mesh layer
        /// </summary>
        /// <since>1.0.0</since>
        ArcGISIntegratedMeshLayer = 2,
        
        /// <summary>
        /// An unsupported layer
        /// </summary>
        /// <since>1.0.0</since>
        ArcGISUnsupportedLayer = 4 UMETA(Hidden),
        
        /// <summary>
        /// An unknown layer
        /// </summary>
        /// <since>1.0.0</since>
        ArcGISUnknownLayer = 5 UMETA(Hidden),
        
        /// <summary>
        /// A vector tile layer
        /// </summary>
        /// <since>1.0.0</since>
        ArcGISVectorTileLayer = 6
    };
}