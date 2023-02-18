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
/// Public class that will contain a image layer.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISImageLayer :
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
    ArcGISImageLayer(const FString& source, const FString& APIKey);
    
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
    ArcGISImageLayer(const FString& source, const FString& name, float opacity, bool visible, const FString& APIKey);
    #pragma endregion Constructors

public:
    #pragma region Special Members
    explicit ArcGISImageLayer(void* handle);
    ArcGISImageLayer(const ArcGISImageLayer&) = delete;
    ArcGISImageLayer(ArcGISImageLayer&& other) noexcept;
    ArcGISImageLayer();
    virtual ~ArcGISImageLayer() = default;
    
    ArcGISImageLayer& operator=(const ArcGISImageLayer&) = delete;
    ArcGISImageLayer& operator=(ArcGISImageLayer&& other) = default;
    #pragma endregion Special Members
};
} // namespace Layers
} // namespace GameEngine
} // namespace Esri