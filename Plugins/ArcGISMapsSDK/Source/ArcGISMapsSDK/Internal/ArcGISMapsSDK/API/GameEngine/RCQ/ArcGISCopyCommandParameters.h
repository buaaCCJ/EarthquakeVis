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

#include "ArcGISMapsSDK/API/GameEngine/Math/ArcGISVector4.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
struct ArcGISCopyCommandParameters
{
    /// <summary>
    /// The source parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t SourceId;
    
    /// <summary>
    /// Id of the render target to be used as the output of the copy.
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t TargetId;
    
    /// <summary>
    /// The region parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    Math::ArcGISVector4 Region;
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri