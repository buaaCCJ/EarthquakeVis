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
namespace GameEngine
{
namespace Layers
{
/// <summary>
/// Public class that will contain a layer with a integrated mesh inside.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISIntegratedMeshLayer :
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
    ArcGISIntegratedMeshLayer(const FString& source, const FString& APIKey);
    
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
    ArcGISIntegratedMeshLayer(const FString& source, const FString& name, float opacity, bool visible, const FString& APIKey);
    #pragma endregion Constructors

public:
    #pragma region Special Members
    explicit ArcGISIntegratedMeshLayer(void* handle);
    ArcGISIntegratedMeshLayer(const ArcGISIntegratedMeshLayer&) = delete;
    ArcGISIntegratedMeshLayer(ArcGISIntegratedMeshLayer&& other) noexcept;
    ArcGISIntegratedMeshLayer();
    virtual ~ArcGISIntegratedMeshLayer() = default;
    
    ArcGISIntegratedMeshLayer& operator=(const ArcGISIntegratedMeshLayer&) = delete;
    ArcGISIntegratedMeshLayer& operator=(ArcGISIntegratedMeshLayer&& other) = default;
    #pragma endregion Special Members
};
} // namespace Layers
} // namespace GameEngine
} // namespace Esri