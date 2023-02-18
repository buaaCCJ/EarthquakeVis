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
enum class ArcGISLoadStatus
{
    /// <summary>
    /// The object is fully loaded and ready to use.
    /// </summary>
    /// <since>1.0.0</since>
    Loaded = 0,
    
    /// <summary>
    /// The object is currently being loaded and some functionality may not work.
    /// </summary>
    /// <since>1.0.0</since>
    Loading = 1,
    
    /// <summary>
    /// The object failed to load and some functionality may not work.
    /// </summary>
    /// <since>1.0.0</since>
    FailedToLoad = 2,
    
    /// <summary>
    /// The object is not loaded and some functionality may not work.
    /// </summary>
    /// <since>1.0.0</since>
    NotLoaded = 3,
    
    /// <summary>
    /// Unknown load state. Only used if an error occurs and we have to return a value. Should not expose it.
    /// </summary>
    /// <since>1.0.0</since>
    Unknown = -1
};
} // namespace GameEngine
} // namespace Esri