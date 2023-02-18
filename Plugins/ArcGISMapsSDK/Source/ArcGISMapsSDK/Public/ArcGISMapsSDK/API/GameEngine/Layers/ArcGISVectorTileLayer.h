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

#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"

namespace Esri
{
namespace Unreal
{
template<typename T> class ArcGISImmutableCollection;
} // namespace Unreal

namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
class ArcGISVectorTileSourceInfo;
class ArcGISVectorTileStyle;
} // namespace VectorTile

/// <summary>
/// Public class that will contain a vector tile layer.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISVectorTileLayer :
    public Base::ArcGISLayer
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a new layer.
    /// </summary>
    /// <remarks>
    /// Creates a new layer.
    /// </remarks>
    /// <param name="source">Layer source</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGISVectorTileLayer(const FString& source, const FString& APIKey);
    
    /// <summary>
    /// Creates a new layer.
    /// </summary>
    /// <remarks>
    /// Creates a new layer.
    /// </remarks>
    /// <param name="source">Layer source.</param>
    /// <param name="name">Layer name</param>
    /// <param name="opacity">Layer opacity.</param>
    /// <param name="visible">Layer visible or not.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGISVectorTileLayer(const FString& source, const FString& name, float opacity, bool visible, const FString& APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// An immutable collection of <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</seealso>
    /// <seealso cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection">ArcGISVectorTileSourceInfoImmutableCollection</seealso>
    /// <since>1.0.0</since>
    Unreal::ArcGISImmutableCollection<VectorTile::ArcGISVectorTileSourceInfo> GetSourceInfos() const;
    
    /// <summary>
    /// The vector tile style info.
    /// </summary>
    /// <since>1.0.0</since>
    VectorTile::ArcGISVectorTileStyle GetStyle() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISVectorTileLayer(void* handle);
    ArcGISVectorTileLayer(const ArcGISVectorTileLayer&) = delete;
    ArcGISVectorTileLayer(ArcGISVectorTileLayer&& other) noexcept;
    ArcGISVectorTileLayer();
    virtual ~ArcGISVectorTileLayer() = default;
    
    ArcGISVectorTileLayer& operator=(const ArcGISVectorTileLayer&) = delete;
    ArcGISVectorTileLayer& operator=(ArcGISVectorTileLayer&& other) = default;
    #pragma endregion Special Members
};
} // namespace Layers
} // namespace GameEngine
} // namespace Esri