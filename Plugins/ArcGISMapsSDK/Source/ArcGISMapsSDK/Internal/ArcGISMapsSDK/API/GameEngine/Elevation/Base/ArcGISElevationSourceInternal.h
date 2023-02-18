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
namespace Elevation
{
namespace Base
{
enum class ArcGISElevationSourceType;

/// <summary>
/// Abstract base class for all ElevationSources
/// </summary>
/// <remarks>
/// A base class of implementations of elevation sources.  To use an elevation source you create an instance of a 
/// derived class and set it in to a <see cref="Esri::GameEngine::Map::ArcGISMapElevation">ArcGISMapElevation</see> in the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>. The combination of elevation sources within the 
/// <see cref="Esri::GameEngine::Map::ArcGISMapElevation">ArcGISMapElevation</see> generate a rendering surface on which data can be draped or offset from.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISElevationSourceInternal
{
    friend class ArcGISElevationSourceInternal;

public:
    #pragma region Properties
    /// <summary>
    /// Defines what type of ArcGISElevationSource is it. Is read only and it will be setup on the constructor
    /// </summary>
    /// <since>1.0.0</since>
    static ArcGISElevationSourceType GetObjectType(ArcGISElevationSource* self);
    #pragma endregion Properties

protected:
    ArcGISLoadableDoneLoadingEvent m_doneLoading;
    ArcGISLoadableLoadStatusChangedEvent m_loadStatusChanged;
};
} // namespace Base
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri