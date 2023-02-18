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
/// An instance of this class represents a layer whose type could not be determined.
/// </summary>
/// <remarks>
/// The layer will not be persisted in the string returned by <see cref="">Map.toJSON</see>,
/// and will not be drawn by the  view.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISUnknownLayer :
    public Base::ArcGISLayer
{
public:

public:
    #pragma region Special Members
    explicit ArcGISUnknownLayer(void* handle);
    ArcGISUnknownLayer(const ArcGISUnknownLayer&) = delete;
    ArcGISUnknownLayer(ArcGISUnknownLayer&& other) noexcept;
    ArcGISUnknownLayer();
    virtual ~ArcGISUnknownLayer() = default;
    
    ArcGISUnknownLayer& operator=(const ArcGISUnknownLayer&) = delete;
    ArcGISUnknownLayer& operator=(ArcGISUnknownLayer&& other) = default;
    #pragma endregion Special Members
};
} // namespace Layers
} // namespace GameEngine
} // namespace Esri