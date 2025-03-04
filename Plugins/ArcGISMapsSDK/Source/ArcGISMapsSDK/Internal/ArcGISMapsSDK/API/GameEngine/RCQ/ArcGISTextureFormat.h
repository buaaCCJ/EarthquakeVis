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
enum class ArcGISTextureFormat
{
    /// <summary>
    /// Each texture cel consists of one float value (e.g. an elevation in meters)
    /// </summary>
    /// <since>1.0.0</since>
    R32Float = 2,
    
    /// <summary>
    /// Each texture cel consists of 4 unsigned bytes. R=LSB A=MSB
    /// </summary>
    /// <since>1.0.0</since>
    RGBA8UNorm = 3,
    
    /// <summary>
    /// Each texture cel consists of 3 unsigned bytes
    /// </summary>
    /// <since>1.0.0</since>
    RGB8UNorm = 4,
    
    /// <summary>
    /// Each texture cel consists of 2 unsigned bytes
    /// </summary>
    /// <since>1.0.0</since>
    RG8UNorm = 5,
    
    /// <summary>
    /// Each texture cel consists of 4 float values
    /// </summary>
    /// <since>1.0.0</since>
    RGBA32Float = 6,
    
    /// <summary>
    /// DXT compressed texture format, v1
    /// </summary>
    /// <since>1.0.0</since>
    DXT1 = 7,
    
    /// <summary>
    /// DXT compressed texture format, v3
    /// </summary>
    /// <since>1.0.0</since>
    DXT3 = 8,
    
    /// <summary>
    /// DXT compressed texture format, v5
    /// </summary>
    /// <since>1.0.0</since>
    DXT5 = 9,
    
    /// <summary>
    /// Each texture cel consists of 1 uint32 value
    /// </summary>
    /// <since>1.0.0</since>
    R32UNorm = 10,
    
    /// <summary>
    /// Each texture cel consists of 1 int32 value
    /// </summary>
    /// <since>1.0.0</since>
    R32Norm = 11,
    
    /// <summary>
    /// Each texture cel consists of 4 uint16 values
    /// </summary>
    /// <since>1.0.0</since>
    RGBA16UNorm = 12,
    
    /// <summary>
    /// ETC2 compressed texture format
    /// </summary>
    /// <since>1.0.0</since>
    ETC2RGB8 = 13,
    
    /// <summary>
    /// ETC2 compressed texture format
    /// </summary>
    /// <since>1.0.0</since>
    ETC2SRGB8 = 14,
    
    /// <summary>
    /// ETC2 compressed texture format
    /// </summary>
    /// <since>1.0.0</since>
    ETC2RGB8PunchthroughAlpha1 = 15,
    
    /// <summary>
    /// ETC2 compressed texture format
    /// </summary>
    /// <since>1.0.0</since>
    ETC2SRGB8PunchthroughAlpha1 = 16,
    
    /// <summary>
    /// ETC2 compressed texture format
    /// </summary>
    /// <since>1.0.0</since>
    ETC2EacRGBA8 = 17,
    
    /// <summary>
    /// ETC2 compressed texture format
    /// </summary>
    /// <since>1.0.0</since>
    ETC2EacSRGBA8 = 18,
    
    /// <summary>
    /// Each texture cel consists of 4 unsigned bytes. B=LSB A=MSB
    /// </summary>
    /// <since>1.0.0</since>
    BGRA8UNorm = 19
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri