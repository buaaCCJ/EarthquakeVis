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

#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadStatus.h"
#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadableDoneLoadingEvent.h"
#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadableLoadStatusChangedEvent.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISException.h"

namespace Esri
{
namespace GameEngine
{
/// <summary>
/// An interface for loading metadata for an object.
/// </summary>
/// <remarks>
/// A resource that is capable of loading its metadata asynchronously is referred to as a loadable.
/// It could represent a remote service or a dataset on disk. These methods return a specific object and not
/// the interface <see cref="Esri::GameEngine::ArcGISLoadable">ArcGISLoadable</see>.
/// </remarks>
/// <since>1.0.0</since>
class ArcGISLoadable
{
public:
    #pragma region Properties
    /// <summary>
    /// The load error.
    /// </summary>
    /// <seealso cref="Esri::Standard::ArcGISError">ArcGISError</seealso>
    /// <since>1.0.0</since>
    virtual Unreal::ArcGISException GetLoadError() const = 0;
    
    /// <summary>
    /// The load status.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::ArcGISLoadStatus">ArcGISLoadStatus</seealso>
    /// <since>1.0.0</since>
    virtual ArcGISLoadStatus GetLoadStatus() const = 0;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Cancels loading metadata for the object.
    /// </summary>
    /// <remarks>
    /// Cancels loading the metadata if the object is loading and always calls <see cref="Esri::GameEngine::ArcGISLoadable.doneLoading">ArcGISLoadable.doneLoading</see>.
    /// </remarks>
    /// <since>1.0.0</since>
    virtual void CancelLoad() = 0;
    
    /// <summary>
    /// Loads the metadata for the object asynchronously.
    /// </summary>
    /// <remarks>
    /// Loads the metadata if the object is not loaded and always calls <see cref="Esri::GameEngine::ArcGISLoadable.doneLoading">ArcGISLoadable.doneLoading</see>.
    /// </remarks>
    /// <since>1.0.0</since>
    virtual void Load() = 0;
    
    /// <summary>
    /// Loads or retries loading metadata for the object asynchronously.
    /// </summary>
    /// <remarks>
    /// Will retry loading the metadata if the object is failed to load. Will load the object if it is not loaded. Will not retry to load the object if the object is loaded.
    /// Will always call the done loading if this is called.
    /// </remarks>
    /// <since>1.0.0</since>
    virtual void RetryLoad() = 0;
    #pragma endregion Methods
    
    #pragma region Events
    /// <summary>
    /// Callback, called when the object is done loading.
    /// </summary>
    /// <since>1.0.0</since>
    virtual ArcGISLoadableDoneLoadingEvent GetDoneLoading() const = 0;
    virtual void SetDoneLoading(ArcGISLoadableDoneLoadingEvent doneLoading) = 0;
    
    /// <summary>
    /// Callback, called when the loadable load status changed.
    /// </summary>
    /// <since>1.0.0</since>
    virtual ArcGISLoadableLoadStatusChangedEvent GetLoadStatusChanged() const = 0;
    virtual void SetLoadStatusChanged(ArcGISLoadableLoadStatusChangedEvent loadStatusChanged) = 0;
    #pragma endregion Events
};
} // namespace GameEngine
} // namespace Esri