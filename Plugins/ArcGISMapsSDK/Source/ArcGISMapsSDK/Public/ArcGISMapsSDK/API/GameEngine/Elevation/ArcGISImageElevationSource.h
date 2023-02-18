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

#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"

namespace Esri
{
namespace GameEngine
{
namespace Elevation
{
/// <summary>
/// Public class that will contain a tiled image elevation source.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISImageElevationSource :
    public Base::ArcGISElevationSource
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a new ElevationSource.
    /// </summary>
    /// <remarks>
    /// Creates a new ElevationSource.
    /// </remarks>
    /// <param name="source">ElevationSource source</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGISImageElevationSource(const FString& source, const FString& APIKey);
    
    /// <summary>
    /// Creates a new ElevationSource.
    /// </summary>
    /// <remarks>
    /// Creates a new ElevationSource.
    /// </remarks>
    /// <param name="source">ElevationSource source.</param>
    /// <param name="name">ElevationSource name</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    ArcGISImageElevationSource(const FString& source, const FString& name, const FString& APIKey);
    #pragma endregion Constructors

public:
    #pragma region Special Members
    explicit ArcGISImageElevationSource(void* handle);
    ArcGISImageElevationSource(const ArcGISImageElevationSource&) = delete;
    ArcGISImageElevationSource(ArcGISImageElevationSource&& other) noexcept;
    ArcGISImageElevationSource();
    virtual ~ArcGISImageElevationSource() = default;
    
    ArcGISImageElevationSource& operator=(const ArcGISImageElevationSource&) = delete;
    ArcGISImageElevationSource& operator=(ArcGISImageElevationSource&& other) = default;
    #pragma endregion Special Members
};
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri