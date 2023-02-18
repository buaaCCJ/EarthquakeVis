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
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayerType.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISBasemap.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISBasemapStyle.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISException.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEBasemap.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Map
{
ArcGISBasemap::ArcGISBasemap()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEBasemap_create(&errorHandler));
}

ArcGISBasemap::ArcGISBasemap(ArcGISBasemapStyle basemapStyle, const FString& APIKey)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEBasemap_createWithBasemapStyle(static_cast<RT_BasemapStyle>(basemapStyle), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

ArcGISBasemap::ArcGISBasemap(const FString& source, Layers::Base::ArcGISLayerType type, const FString& APIKey)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEBasemap_createWithLayerSourceAndType(TCHAR_TO_ANSI(*source), static_cast<RT_GELayerType>(type), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

ArcGISBasemap::ArcGISBasemap(const FString& source, const FString& APIKey)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEBasemap_createWithBasemapSource(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

FString ArcGISBasemap::GetAPIKey() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEBasemap_getAPIKey(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

Unreal::ArcGISCollection<Layers::Base::ArcGISLayer> ArcGISBasemap::GetBaseLayers() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEBasemap_getBaseLayers(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISBasemap::SetBaseLayers(const Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>& baseLayers)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localBaseLayers = static_cast<const RT_GELayerCollectionHandle>(baseLayers.GetHandle());
    
    RT_GEBasemap_setBaseLayers(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), localBaseLayers, &errorHandler);
}

FString ArcGISBasemap::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEBasemap_getName(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}
void ArcGISBasemap::SetName(const FString& name)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEBasemap_setName(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), TCHAR_TO_ANSI(*name), &errorHandler);
}

Unreal::ArcGISCollection<Layers::Base::ArcGISLayer> ArcGISBasemap::GetReferenceLayers() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEBasemap_getReferenceLayers(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISBasemap::SetReferenceLayers(const Unreal::ArcGISCollection<Layers::Base::ArcGISLayer>& referenceLayers)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localReferenceLayers = static_cast<const RT_GELayerCollectionHandle>(referenceLayers.GetHandle());
    
    RT_GEBasemap_setReferenceLayers(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), localReferenceLayers, &errorHandler);
}

FString ArcGISBasemap::GetSource() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEBasemap_getSource(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

Unreal::ArcGISException ArcGISBasemap::GetLoadError() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEBasemap_getLoadError(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISException{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISException{ localResult };
    }
    
    return localLocalResult;
}

ArcGISLoadStatus ArcGISBasemap::GetLoadStatus() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEBasemap_getLoadStatus(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISLoadStatus>(localResult);
}

void ArcGISBasemap::CancelLoad()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEBasemap_cancelLoad(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
}

void ArcGISBasemap::Load()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEBasemap_load(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
}

void ArcGISBasemap::RetryLoad()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEBasemap_retryLoad(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), &errorHandler);
}

ArcGISLoadableDoneLoadingEvent ArcGISBasemap::GetDoneLoading() const
{
    return m_doneLoading;
}
void ArcGISBasemap::SetDoneLoading(ArcGISLoadableDoneLoadingEvent doneLoading)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_doneLoading = std::move(doneLoading);
    
    static auto callbackHandler = [](void* userData, RT_ErrorHandle loadError_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISBasemap*>(userData);
        
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
        RT_GEBasemap_setDoneLoadingCallback(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEBasemap_setDoneLoadingCallback(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISLoadableLoadStatusChangedEvent ArcGISBasemap::GetLoadStatusChanged() const
{
    return m_loadStatusChanged;
}
void ArcGISBasemap::SetLoadStatusChanged(ArcGISLoadableLoadStatusChangedEvent loadStatusChanged)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_loadStatusChanged = std::move(loadStatusChanged);
    
    static auto callbackHandler = [](void* userData, RT_LoadStatus loadStatus_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISBasemap*>(userData);
        
        auto callback = callbackObject->GetLoadStatusChanged();
        
        if (!callback)
        {
            return;
        }
        
        callback(static_cast<ArcGISLoadStatus>(loadStatus_));
    };
    
    if (m_loadStatusChanged)
    {
        RT_GEBasemap_setLoadStatusChangedCallback(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEBasemap_setLoadStatusChangedCallback(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISBasemap::ArcGISBasemap(void* handle) :
    m_handle{ handle }
{
}

ArcGISBasemap::ArcGISBasemap(ArcGISBasemap&& other) noexcept :
    m_handle{ other.m_handle },
    m_doneLoading{ std::move(other.m_doneLoading) },
    m_loadStatusChanged{ std::move(other.m_loadStatusChanged) }
{
    other.m_handle = nullptr;
}

ArcGISBasemap::~ArcGISBasemap()
{
    if (m_handle)
    {
        if (m_doneLoading)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEBasemap_setDoneLoadingCallback(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        if (m_loadStatusChanged)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEBasemap_setLoadStatusChangedCallback(reinterpret_cast<RT_GEBasemapHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEBasemap_destroy(reinterpret_cast<RT_GEBasemapHandle>(m_handle), &errorHandler);
    }
}

ArcGISBasemap& ArcGISBasemap::operator=(ArcGISBasemap&& other) noexcept
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

ArcGISBasemap::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISBasemap::GetHandle() const
{
    return m_handle;
}
void ArcGISBasemap::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Map
} // namespace GameEngine
} // namespace Esri