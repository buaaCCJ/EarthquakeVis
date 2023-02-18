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
enum class ArcGISRenderCommandType
{
    /// <summary>
    /// Create render target
    /// </summary>
    /// <since>1.0.0</since>
    CreateRenderTarget = 1,
    
    /// <summary>
    /// Create texture
    /// </summary>
    /// <since>1.0.0</since>
    CreateTexture = 2,
    
    /// <summary>
    /// Create renderable
    /// </summary>
    /// <since>1.0.0</since>
    CreateRenderable = 3,
    
    /// <summary>
    /// Destroy render target
    /// </summary>
    /// <since>1.0.0</since>
    DestroyRenderTarget = 5,
    
    /// <summary>
    /// Destroy texture
    /// </summary>
    /// <since>1.0.0</since>
    DestroyTexture = 6,
    
    /// <summary>
    /// Destroy renderable
    /// </summary>
    /// <since>1.0.0</since>
    DestroyRenderable = 7,
    
    /// <summary>
    /// Multiple compose
    /// </summary>
    /// <since>1.0.0</since>
    MultipleCompose = 8,
    
    /// <summary>
    /// Copy
    /// </summary>
    /// <since>1.0.0</since>
    Copy = 10,
    
    /// <summary>
    /// Generate normal texture
    /// </summary>
    /// <since>1.0.0</since>
    GenerateNormalTexture = 11,
    
    /// <summary>
    /// Set the pixel data of a texture
    /// </summary>
    /// <since>1.0.0</since>
    SetTexturePixelData = 12,
    
    /// <summary>
    /// Set the material scalar property of a renderable
    /// </summary>
    /// <since>1.0.0</since>
    SetRenderableMaterialScalarProperty = 13,
    
    /// <summary>
    /// Set the material vector property of a renderable
    /// </summary>
    /// <since>1.0.0</since>
    SetRenderableMaterialVectorProperty = 14,
    
    /// <summary>
    /// Set the material render target property of a renderable
    /// </summary>
    /// <since>1.0.0</since>
    SetRenderableMaterialRenderTargetProperty = 15,
    
    /// <summary>
    /// Set the material texture property of a renderable
    /// </summary>
    /// <since>1.0.0</since>
    SetRenderableMaterialTextureProperty = 16,
    
    /// <summary>
    /// Set the visibility of a renderable
    /// </summary>
    /// <since>1.0.0</since>
    SetRenderableVisible = 18,
    
    /// <summary>
    /// Set the mesh of a renderable
    /// </summary>
    /// <since>1.0.0</since>
    SetRenderableMesh = 20,
    
    /// <summary>
    /// Set the pivot position of a renderable
    /// </summary>
    /// <since>1.0.0</since>
    SetRenderablePivot = 22,
    
    /// <summary>
    /// Set the named material texture of a renderable
    /// </summary>
    /// <since>1.0.0</since>
    SetRenderableMaterialNamedTextureProperty = 23,
    
    /// <summary>
    /// Mark the start of a group of commands that should be executed atomically
    /// </summary>
    /// <since>1.0.0</since>
    CommandGroupBegin = 24,
    
    /// <summary>
    /// Mark the end of a group of commands that should be executed atomically
    /// </summary>
    /// <since>1.0.0</since>
    CommandGroupEnd = 25
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri