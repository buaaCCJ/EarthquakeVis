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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISGameEngineType.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/ArcGISImageElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGIS3DObjectSceneLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISImageLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISIntegratedMeshLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnknownLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnsupportedLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISVectorTileLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMap.h"
#include "ArcGISMapsSDK/API/GameEngine/MapView/ArcGISCamera.h"
#include "ArcGISMapsSDK/API/GameEngine/MapView/ArcGISGlobeModel.h"
#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISView.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISViewOptions.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISElevationSourceViewState.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISLayerViewState.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewState.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSource.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayer.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/GEView.h"

namespace Esri
{
namespace GameEngine
{
namespace View
{
ArcGISView::ArcGISView(ArcGISGameEngineType gameEngineType, MapView::ArcGISGlobeModel globeModel)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEView_create(static_cast<RT_GameEngineType>(gameEngineType), static_cast<RT_GlobeModel>(globeModel), &errorHandler));
}

MapView::ArcGISCamera ArcGISView::GetCamera() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEView_getCamera(reinterpret_cast<RT_GEViewHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = MapView::ArcGISCamera{};
    
    if (localResult != nullptr)
    {
        localLocalResult = MapView::ArcGISCamera{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISView::SetCamera(const MapView::ArcGISCamera& camera)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCamera = static_cast<const RT_CameraHandle>(camera.GetHandle());
    
    RT_GEView_setCamera(reinterpret_cast<RT_GEViewHandle>(GetHandle()), localCamera, &errorHandler);
}

Map::ArcGISMap ArcGISView::GetMap() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEView_getMap(reinterpret_cast<RT_GEViewHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Map::ArcGISMap{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Map::ArcGISMap{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISView::SetMap(const Map::ArcGISMap& map)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localMap = static_cast<const RT_GEMapHandle>(map.GetHandle());
    
    RT_GEView_setMap(reinterpret_cast<RT_GEViewHandle>(GetHandle()), localMap, &errorHandler);
}

Geometry::ArcGISSpatialReference ArcGISView::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEView_getSpatialReference(reinterpret_cast<RT_GEViewHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISViewOptions ArcGISView::GetViewOptions() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEView_getViewOptions(reinterpret_cast<RT_GEViewHandle>(GetHandle()), &errorHandler);
    
    return std::move(reinterpret_cast<ArcGISViewOptions&>(localResult));
}
void ArcGISView::SetViewOptions(const ArcGISViewOptions& viewOptions)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localViewOptions = reinterpret_cast<const RT_GEViewOptions&>(viewOptions);
    
    RT_GEView_setViewOptions(reinterpret_cast<RT_GEViewHandle>(GetHandle()), localViewOptions, &errorHandler);
}

FVector3d ArcGISView::GeographicToWorld(const Geometry::ArcGISPoint& geographicCoordinate) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeographicCoordinate = static_cast<const RT_PointHandle>(geographicCoordinate.GetHandle());
    
    auto localResult = RT_GEView_geographicToWorld(reinterpret_cast<RT_GEViewHandle>(GetHandle()), localGeographicCoordinate, &errorHandler);
    
    return std::move(reinterpret_cast<FVector3d&>(localResult));
}

State::ArcGISViewState ArcGISView::GetViewState() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEView_getViewViewState(reinterpret_cast<RT_GEViewHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = State::ArcGISViewState{};
    
    if (localResult != nullptr)
    {
        localLocalResult = State::ArcGISViewState{ localResult };
    }
    
    return localLocalResult;
}

State::ArcGISElevationSourceViewState ArcGISView::GetViewState(const Elevation::Base::ArcGISElevationSource& elevation) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localElevation = static_cast<const RT_GEElevationSourceHandle>(elevation.GetHandle());
    
    auto localResult = RT_GEView_getElevationSourceViewState(reinterpret_cast<RT_GEViewHandle>(GetHandle()), localElevation, &errorHandler);
    
    auto localLocalResult = State::ArcGISElevationSourceViewState{};
    
    if (localResult != nullptr)
    {
        localLocalResult = State::ArcGISElevationSourceViewState{ localResult };
    }
    
    return localLocalResult;
}

State::ArcGISLayerViewState ArcGISView::GetViewState(const Layers::Base::ArcGISLayer& layer) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLayer = static_cast<const RT_GELayerHandle>(layer.GetHandle());
    
    auto localResult = RT_GEView_getLayerViewState(reinterpret_cast<RT_GEViewHandle>(GetHandle()), localLayer, &errorHandler);
    
    auto localLocalResult = State::ArcGISLayerViewState{};
    
    if (localResult != nullptr)
    {
        localLocalResult = State::ArcGISLayerViewState{ localResult };
    }
    
    return localLocalResult;
}

void ArcGISView::HandleLowMemoryWarning()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEView_handleLowMemoryWarning(reinterpret_cast<RT_GEViewHandle>(GetHandle()), &errorHandler);
}

void ArcGISView::SetMemoryQuotas(int64_t systemMemory, int64_t videoMemory)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEView_setMemoryQuotas(reinterpret_cast<RT_GEViewHandle>(GetHandle()), systemMemory, videoMemory, &errorHandler);
}

void ArcGISView::SetViewportProperties(uint32_t viewportWidthPixels, uint32_t viewportHeightPixels, float horizontalFieldOfViewDegrees, float verticalFieldOfViewDegrees, float verticalDistortionFactor)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEView_setViewportProperties(reinterpret_cast<RT_GEViewHandle>(GetHandle()), viewportWidthPixels, viewportHeightPixels, horizontalFieldOfViewDegrees, verticalFieldOfViewDegrees, verticalDistortionFactor, &errorHandler);
}

Geometry::ArcGISPoint ArcGISView::WorldToGeographic(FVector3d worldCoordinate) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localWorldCoordinate = reinterpret_cast<RT_Vector3&>(worldCoordinate);
    
    auto localResult = RT_GEView_worldToGeographic(reinterpret_cast<RT_GEViewHandle>(GetHandle()), localWorldCoordinate, &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

State::ArcGISElevationSourceViewStateChangedEvent ArcGISView::GetElevationSourceViewStateChanged() const
{
    return m_elevationSourceViewStateChanged;
}
void ArcGISView::SetElevationSourceViewStateChanged(State::ArcGISElevationSourceViewStateChangedEvent elevationSourceViewStateChanged)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_elevationSourceViewStateChanged = std::move(elevationSourceViewStateChanged);
    
    static auto callbackHandler = [](void* userData, RT_GEElevationSourceHandle layer_, RT_GEElevationSourceViewStateHandle arcGISElevationSourceViewState_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISView*>(userData);
        
        auto callback = callbackObject->GetElevationSourceViewStateChanged();
        
        if (!callback)
        {
            return;
        }
        
        auto localLayer = Elevation::Base::ArcGISElevationSource{};
        
        if (layer_ != nullptr)
        {
            auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
            
            auto objectType = RT_GEElevationSource_getObjectType(layer_, &objectTypeErrorHandler);
            
            switch (objectType)
            {
                case RT_GEElevationSourceType_GEImageElevationSource:
                    localLayer = Elevation::ArcGISImageElevationSource{ layer_ };
                    break;
                default:
                    localLayer = Elevation::Base::ArcGISElevationSource{ layer_ };
                    break;
            }
        }
        
        auto localArcGISElevationSourceViewState = State::ArcGISElevationSourceViewState{};
        
        if (arcGISElevationSourceViewState_ != nullptr)
        {
            localArcGISElevationSourceViewState = State::ArcGISElevationSourceViewState{ arcGISElevationSourceViewState_ };
        }
        
        callback(localLayer, localArcGISElevationSourceViewState);
    };
    
    if (m_elevationSourceViewStateChanged)
    {
        RT_GEView_setElevationSourceViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEView_setElevationSourceViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

State::ArcGISLayerViewStateChangedEvent ArcGISView::GetLayerViewStateChanged() const
{
    return m_layerViewStateChanged;
}
void ArcGISView::SetLayerViewStateChanged(State::ArcGISLayerViewStateChangedEvent layerViewStateChanged)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_layerViewStateChanged = std::move(layerViewStateChanged);
    
    static auto callbackHandler = [](void* userData, RT_GELayerHandle layer_, RT_GELayerViewStateHandle arcGISLayerViewState_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISView*>(userData);
        
        auto callback = callbackObject->GetLayerViewStateChanged();
        
        if (!callback)
        {
            return;
        }
        
        auto localLayer = Layers::Base::ArcGISLayer{};
        
        if (layer_ != nullptr)
        {
            auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
            
            auto objectType = RT_GELayer_getObjectType(layer_, &objectTypeErrorHandler);
            
            switch (objectType)
            {
                case RT_GELayerType_GE3DObjectSceneLayer:
                    localLayer = Layers::ArcGIS3DObjectSceneLayer{ layer_ };
                    break;
                case RT_GELayerType_GEImageLayer:
                    localLayer = Layers::ArcGISImageLayer{ layer_ };
                    break;
                case RT_GELayerType_GEIntegratedMeshLayer:
                    localLayer = Layers::ArcGISIntegratedMeshLayer{ layer_ };
                    break;
                case RT_GELayerType_GEUnknownLayer:
                    localLayer = Layers::ArcGISUnknownLayer{ layer_ };
                    break;
                case RT_GELayerType_GEUnsupportedLayer:
                    localLayer = Layers::ArcGISUnsupportedLayer{ layer_ };
                    break;
                case RT_GELayerType_GEVectorTileLayer:
                    localLayer = Layers::ArcGISVectorTileLayer{ layer_ };
                    break;
                default:
                    localLayer = Layers::Base::ArcGISLayer{ layer_ };
                    break;
            }
        }
        
        auto localArcGISLayerViewState = State::ArcGISLayerViewState{};
        
        if (arcGISLayerViewState_ != nullptr)
        {
            localArcGISLayerViewState = State::ArcGISLayerViewState{ arcGISLayerViewState_ };
        }
        
        callback(localLayer, localArcGISLayerViewState);
    };
    
    if (m_layerViewStateChanged)
    {
        RT_GEView_setLayerViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEView_setLayerViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISViewSpatialReferenceChangedEvent ArcGISView::GetSpatialReferenceChanged() const
{
    return m_spatialReferenceChanged;
}
void ArcGISView::SetSpatialReferenceChanged(ArcGISViewSpatialReferenceChangedEvent spatialReferenceChanged)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_spatialReferenceChanged = std::move(spatialReferenceChanged);
    
    static auto callbackHandler = [](void* userData)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISView*>(userData);
        
        auto callback = callbackObject->GetSpatialReferenceChanged();
        
        if (!callback)
        {
            return;
        }
        
        callback();
    };
    
    if (m_spatialReferenceChanged)
    {
        RT_GEView_setSpatialReferenceChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEView_setSpatialReferenceChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

State::ArcGISViewStateChangedEvent ArcGISView::GetViewStateChanged() const
{
    return m_viewStateChanged;
}
void ArcGISView::SetViewStateChanged(State::ArcGISViewStateChangedEvent viewStateChanged)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_viewStateChanged = std::move(viewStateChanged);
    
    static auto callbackHandler = [](void* userData, RT_GEViewStateHandle arcGISViewState_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISView*>(userData);
        
        auto callback = callbackObject->GetViewStateChanged();
        
        if (!callback)
        {
            return;
        }
        
        auto localArcGISViewState = State::ArcGISViewState{};
        
        if (arcGISViewState_ != nullptr)
        {
            localArcGISViewState = State::ArcGISViewState{ arcGISViewState_ };
        }
        
        callback(localArcGISViewState);
    };
    
    if (m_viewStateChanged)
    {
        RT_GEView_setViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEView_setViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISView::ArcGISView(void* handle) :
    m_handle{ handle }
{
}

ArcGISView::ArcGISView(ArcGISView&& other) noexcept :
    m_handle{ other.m_handle },
    m_elevationSourceViewStateChanged{ std::move(other.m_elevationSourceViewStateChanged) },
    m_layerViewStateChanged{ std::move(other.m_layerViewStateChanged) },
    m_spatialReferenceChanged{ std::move(other.m_spatialReferenceChanged) },
    m_viewStateChanged{ std::move(other.m_viewStateChanged) }
{
    other.m_handle = nullptr;
}

ArcGISView::~ArcGISView()
{
    if (m_handle)
    {
        if (m_elevationSourceViewStateChanged)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEView_setElevationSourceViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        if (m_layerViewStateChanged)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEView_setLayerViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        if (m_spatialReferenceChanged)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEView_setSpatialReferenceChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        if (m_viewStateChanged)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEView_setViewStateChangedCallback(reinterpret_cast<RT_GEViewHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEView_destroy(reinterpret_cast<RT_GEViewHandle>(m_handle), &errorHandler);
    }
}

ArcGISView& ArcGISView::operator=(ArcGISView&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
        swap(m_elevationSourceViewStateChanged, other.m_elevationSourceViewStateChanged);
        swap(m_layerViewStateChanged, other.m_layerViewStateChanged);
        swap(m_spatialReferenceChanged, other.m_spatialReferenceChanged);
        swap(m_viewStateChanged, other.m_viewStateChanged);
    }
    
    return *this;
}

ArcGISView::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISView::GetHandle() const
{
    return m_handle;
}
void ArcGISView::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace View
} // namespace GameEngine
} // namespace Esri