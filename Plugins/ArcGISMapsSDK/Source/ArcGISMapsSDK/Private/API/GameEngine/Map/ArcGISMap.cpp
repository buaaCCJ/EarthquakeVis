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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadStatus.h"
#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadableDoneLoadingEvent.h"
#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadableLoadStatusChangedEvent.h"
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtent.h"
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentCircle.h"
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentRectangle.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISBasemap.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMap.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMapElevation.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMapType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISException.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtent.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMap.h"

namespace Esri
{
namespace GameEngine
{
namespace Map
{
ArcGISMap::ArcGISMap(ArcGISBasemap& basemap, ArcGISMapType mapType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localBasemap = static_cast<RT_GEBasemapHandle>(basemap.GetHandle());
    
    SetHandle(RT_GEMap_createWithBasemapAndMapType(localBasemap, static_cast<RT_GEMapType>(mapType), &errorHandler));
}

ArcGISMap::ArcGISMap(ArcGISMapType mapType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEMap_createWithMapType(static_cast<RT_GEMapType>(mapType), &errorHandler));
}

ArcGISMap::ArcGISMap(const Geometry::ArcGISSpatialReference& spatialReference, ArcGISMapType mapType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_GEMap_createWithSpatialReferenceAndMapType(localSpatialReference, static_cast<RT_GEMapType>(mapType), &errorHandler));
}

ArcGISBasemap ArcGISMap::GetBasemap() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_getBasemap(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISBasemap{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISBasemap{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISMap::SetBasemap(const ArcGISBasemap& basemap)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localBasemap = static_cast<const RT_GEBasemapHandle>(basemap.GetHandle());
    
    RT_GEMap_setBasemap(reinterpret_cast<RT_GEMapHandle>(GetHandle()), localBasemap, &errorHandler);
}

Extent::ArcGISExtent ArcGISMap::GetClippingArea() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_getClippingArea(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Extent::ArcGISExtent{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GEExtent_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GEExtentType_GEExtentCircle:
                localLocalResult = Extent::ArcGISExtentCircle{ localResult };
                break;
            case RT_GEExtentType_GEExtentRectangle:
                localLocalResult = Extent::ArcGISExtentRectangle{ localResult };
                break;
            default:
                localLocalResult = Extent::ArcGISExtent{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}
void ArcGISMap::SetClippingArea(const Extent::ArcGISExtent& clippingArea)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localClippingArea = static_cast<const RT_GEExtentHandle>(clippingArea.GetHandle());
    
    RT_GEMap_setClippingArea(reinterpret_cast<RT_GEMapHandle>(GetHandle()), localClippingArea, &errorHandler);
}

ArcGISMapElevation ArcGISMap::GetElevation() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_getElevation(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISMapElevation{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISMapElevation{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISMap::SetElevation(const ArcGISMapElevation& elevation)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localElevation = static_cast<const RT_GEMapElevationHandle>(elevation.GetHandle());
    
    RT_GEMap_setElevation(reinterpret_cast<RT_GEMapHandle>(GetHandle()), localElevation, &errorHandler);
}

Unreal::ArcGISCollection<Layers::Base::ArcGISLayer> ArcGISMap::GetLayers() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_getLayers(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISMap::SetLayers(const Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>& layers)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLayers = static_cast<const RT_GELayerCollectionHandle>(layers.GetHandle());
    
    RT_GEMap_setLayers(reinterpret_cast<RT_GEMapHandle>(GetHandle()), localLayers, &errorHandler);
}

ArcGISMapType ArcGISMap::GetMapType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_getMapType(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISMapType>(localResult);
}

Geometry::ArcGISSpatialReference ArcGISMap::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_getSpatialReference(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISException ArcGISMap::GetLoadError() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_getLoadError(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISException{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISException{ localResult };
    }
    
    return localLocalResult;
}

ArcGISLoadStatus ArcGISMap::GetLoadStatus() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_getLoadStatus(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISLoadStatus>(localResult);
}

void ArcGISMap::CancelLoad()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEMap_cancelLoad(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
}

void ArcGISMap::Load()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEMap_load(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
}

void ArcGISMap::RetryLoad()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEMap_retryLoad(reinterpret_cast<RT_GEMapHandle>(GetHandle()), &errorHandler);
}

ArcGISLoadableDoneLoadingEvent ArcGISMap::GetDoneLoading() const
{
    return m_doneLoading;
}
void ArcGISMap::SetDoneLoading(ArcGISLoadableDoneLoadingEvent doneLoading)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_doneLoading = std::move(doneLoading);
    
    static auto callbackHandler = [](void* userData, RT_ErrorHandle loadError_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISMap*>(userData);
        
        auto callback = callbackObject->GetDoneLoading();
        
        if (!callback)
        {
            return;
        }
        
        auto localLoadError = Unreal::ArcGISException{};
        
        if (loadError_ != nullptr)
        {
            localLoadError = Unreal::ArcGISException{ loadError_ };
        }
        
        callback(localLoadError);
    };
    
    if (m_doneLoading)
    {
        RT_GEMap_setDoneLoadingCallback(reinterpret_cast<RT_GEMapHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEMap_setDoneLoadingCallback(reinterpret_cast<RT_GEMapHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISLoadableLoadStatusChangedEvent ArcGISMap::GetLoadStatusChanged() const
{
    return m_loadStatusChanged;
}
void ArcGISMap::SetLoadStatusChanged(ArcGISLoadableLoadStatusChangedEvent loadStatusChanged)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_loadStatusChanged = std::move(loadStatusChanged);
    
    static auto callbackHandler = [](void* userData, RT_LoadStatus loadStatus_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISMap*>(userData);
        
        auto callback = callbackObject->GetLoadStatusChanged();
        
        if (!callback)
        {
            return;
        }
        
        callback(static_cast<ArcGISLoadStatus>(loadStatus_));
    };
    
    if (m_loadStatusChanged)
    {
        RT_GEMap_setLoadStatusChangedCallback(reinterpret_cast<RT_GEMapHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEMap_setLoadStatusChangedCallback(reinterpret_cast<RT_GEMapHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISMap::ArcGISMap(void* handle) :
    m_handle{ handle }
{
}

ArcGISMap::ArcGISMap(ArcGISMap&& other) noexcept :
    m_handle{ other.m_handle },
    m_doneLoading{ std::move(other.m_doneLoading) },
    m_loadStatusChanged{ std::move(other.m_loadStatusChanged) }
{
    other.m_handle = nullptr;
}

ArcGISMap::~ArcGISMap()
{
    if (m_handle)
    {
        if (m_doneLoading)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEMap_setDoneLoadingCallback(reinterpret_cast<RT_GEMapHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        if (m_loadStatusChanged)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEMap_setLoadStatusChangedCallback(reinterpret_cast<RT_GEMapHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEMap_destroy(reinterpret_cast<RT_GEMapHandle>(m_handle), &errorHandler);
    }
}

ArcGISMap& ArcGISMap::operator=(ArcGISMap&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
        swap(m_doneLoading, other.m_doneLoading);
        swap(m_loadStatusChanged, other.m_loadStatusChanged);
    }
    
    return *this;
}

ArcGISMap::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISMap::GetHandle() const
{
    return m_handle;
}
void ArcGISMap::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Map
} // namespace GameEngine
} // namespace Esri