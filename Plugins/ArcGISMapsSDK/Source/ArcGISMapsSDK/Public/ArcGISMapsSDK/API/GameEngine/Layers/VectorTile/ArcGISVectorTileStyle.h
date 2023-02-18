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
namespace Layers
{
namespace VectorTile
{
/// <summary>
/// This object represents the style information for a vector tile layer.
/// </summary>
/// <seealso cref="">VectorTileSourceInfo.defaultStyle</seealso>
/// <seealso cref="">ArcGISVectorTiledLayer.style</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISVectorTileStyle
{
public:
    #pragma region Properties
    /// <summary>
    /// The vector tile source URI.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetSourceURI() const;
    
    /// <summary>
    /// The style version.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetVersion() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISVectorTileStyle(void* handle);
    ArcGISVectorTileStyle(const ArcGISVectorTileStyle&) = delete;
    ArcGISVectorTileStyle(ArcGISVectorTileStyle&& other) noexcept;
    ArcGISVectorTileStyle() = default;
    ~ArcGISVectorTileStyle();
    
    ArcGISVectorTileStyle& operator=(const ArcGISVectorTileStyle&) = delete;
    ArcGISVectorTileStyle& operator=(ArcGISVectorTileStyle&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine
} // namespace Esri