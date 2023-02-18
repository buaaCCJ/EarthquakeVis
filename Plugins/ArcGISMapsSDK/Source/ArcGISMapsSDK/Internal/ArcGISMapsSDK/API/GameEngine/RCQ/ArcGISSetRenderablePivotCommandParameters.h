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

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
struct ArcGISSetRenderablePivotCommandParameters
{
    /// <summary>
    /// The renderable parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t RenderableId;
    
    /// <summary>
    /// The x parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    double X;
    
    /// <summary>
    /// The y parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    double Y;
    
    /// <summary>
    /// The z parameter of this render command
    /// </summary>
    /// <since>1.0.0</since>
    double Z;
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri