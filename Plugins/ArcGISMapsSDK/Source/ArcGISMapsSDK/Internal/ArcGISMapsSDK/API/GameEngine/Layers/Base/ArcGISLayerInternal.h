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

#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadable.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace Base
{
enum class ArcGISLayerType;

/// <summary>
/// Abstract class layer, base for layers
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISLayerInternal
{
    friend class ArcGISLayerInternal;

public:
    #pragma region Properties
    /// <summary>
    /// Defines what type of layer is it. Is read only and it will be setup on the constructor
    /// </summary>
    /// <since>1.0.0</since>
    static ArcGISLayerType GetObjectType(ArcGISLayer* self);
    #pragma endregion Properties

protected:
    ArcGISLoadableDoneLoadingEvent m_doneLoading;
    ArcGISLoadableLoadStatusChangedEvent m_loadStatusChanged;
};
} // namespace Base
} // namespace Layers
} // namespace GameEngine
} // namespace Esri