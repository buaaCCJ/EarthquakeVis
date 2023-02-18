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
namespace Geometry
{
class ArcGISEnvelope;
class ArcGISPoint;
class ArcGISSpatialReference;
} // namespace Geometry

namespace Layers
{
namespace VectorTile
{
/// <summary>
/// This object represents the source metadata for a vector tile layer.
/// </summary>
/// <seealso cref="">ArcGISVectorTiledLayer.sourceInfo</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISVectorTileSourceInfo
{
public:
    #pragma region Properties
    /// <summary>
    /// The full extent of the source data.
    /// </summary>
    /// <since>1.0.0</since>
    Geometry::ArcGISEnvelope GetFullExtent() const;
    
    /// <summary>
    /// The initial extent of the source data.
    /// </summary>
    /// <since>1.0.0</since>
    Geometry::ArcGISEnvelope GetInitialExtent() const;
    
    /// <summary>
    /// The maximum scale.
    /// </summary>
    /// <remarks>
    /// Will return an undefined float if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetMaxScale() const;
    
    /// <summary>
    /// The minimum scale.
    /// </summary>
    /// <remarks>
    /// Will return an undefined float if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetMinScale() const;
    
    /// <summary>
    /// The source name.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName() const;
    
    /// <summary>
    /// The origin of the source data.
    /// </summary>
    /// <since>1.0.0</since>
    Geometry::ArcGISPoint GetOrigin() const;
    
    /// <summary>
    /// The spatial reference of the source data.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    Geometry::ArcGISSpatialReference GetSpatialReference() const;
    
    /// <summary>
    /// The vector tile source URI.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetURI() const;
    
    /// <summary>
    /// The source version.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetVersion() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISVectorTileSourceInfo(void* handle);
    ArcGISVectorTileSourceInfo(const ArcGISVectorTileSourceInfo&) = delete;
    ArcGISVectorTileSourceInfo(ArcGISVectorTileSourceInfo&& other) noexcept;
    ArcGISVectorTileSourceInfo() = default;
    ~ArcGISVectorTileSourceInfo();
    
    ArcGISVectorTileSourceInfo& operator=(const ArcGISVectorTileSourceInfo&) = delete;
    ArcGISVectorTileSourceInfo& operator=(ArcGISVectorTileSourceInfo&& other) noexcept;
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