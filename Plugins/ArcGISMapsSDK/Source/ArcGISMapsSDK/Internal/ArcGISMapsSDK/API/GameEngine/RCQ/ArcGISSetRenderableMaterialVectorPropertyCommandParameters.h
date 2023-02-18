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

#include "ArcGISMapsSDK/API/GameEngine/Math/ArcGISDoubleVector4.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISMaterialVectorProperty.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
struct ArcGISSetRenderableMaterialVectorPropertyCommandParameters
{
    /// <summary>
    /// The material parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t RenderableId;
    
    /// <summary>
    /// The material vector property parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISMaterialVectorProperty MaterialVectorProperty;
    
    /// <summary>
    /// The value parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    Math::ArcGISDoubleVector4 Value;
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri