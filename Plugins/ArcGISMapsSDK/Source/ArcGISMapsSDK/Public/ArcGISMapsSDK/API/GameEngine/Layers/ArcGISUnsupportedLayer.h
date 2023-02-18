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
/// An instance of this class represents a layer type that is not currently supported.
/// </summary>
/// <remarks>
/// The layer will be persisted in the string returned by <see cref="">Map.toJSON</see>,
/// but will not be drawn by the map view.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISUnsupportedLayer :
    public Base::ArcGISLayer
{
public:

public:
    #pragma region Special Members
    explicit ArcGISUnsupportedLayer(void* handle);
    ArcGISUnsupportedLayer(const ArcGISUnsupportedLayer&) = delete;
    ArcGISUnsupportedLayer(ArcGISUnsupportedLayer&& other) noexcept;
    ArcGISUnsupportedLayer();
    virtual ~ArcGISUnsupportedLayer() = default;
    
    ArcGISUnsupportedLayer& operator=(const ArcGISUnsupportedLayer&) = delete;
    ArcGISUnsupportedLayer& operator=(ArcGISUnsupportedLayer&& other) = default;
    #pragma endregion Special Members
};
} // namespace Layers
} // namespace GameEngine
} // namespace Esri