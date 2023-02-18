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
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentRectangle.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayerType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISException.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayer.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace Base
{
ArcGISLayer::ArcGISLayer(const FString& source, ArcGISLayerType type, const FString& APIKey)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GELayer_create(TCHAR_TO_ANSI(*source), static_cast<RT_GELayerType>(type), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

FString ArcGISLayer::GetAPIKey() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getAPIKey(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

Extent::ArcGISExtentRectangle ArcGISLayer::GetExtent() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getExtent(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Extent::ArcGISExtentRectangle{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Extent::ArcGISExtentRectangle{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISLayer::GetIsVisible() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getIsVisible(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISLayer::SetIsVisible(bool isVisible)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayer_setIsVisible(reinterpret_cast<RT_GELayerHandle>(GetHandle()), isVisible, &errorHandler);
}

FString ArcGISLayer::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getName(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}
void ArcGISLayer::SetName(const FString& name)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayer_setName(reinterpret_cast<RT_GELayerHandle>(GetHandle()), TCHAR_TO_ANSI(*name), &errorHandler);
}

float ArcGISLayer::GetOpacity() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getOpacity(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISLayer::SetOpacity(float opacity)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayer_setOpacity(reinterpret_cast<RT_GELayerHandle>(GetHandle()), opacity, &errorHandler);
}

FString ArcGISLayer::GetSource() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getSource(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

Geometry::ArcGISSpatialReference ArcGISLayer::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getSpatialReference(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISException ArcGISLayer::GetLoadError() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getLoadError(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISException{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISException{ localResult };
    }
    
    return localLocalResult;
}

ArcGISLoadStatus ArcGISLayer::GetLoadStatus() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getLoadStatus(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISLoadStatus>(localResult);
}

void ArcGISLayer::CancelLoad()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayer_cancelLoad(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
}

void ArcGISLayer::Load()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayer_load(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
}

void ArcGISLayer::RetryLoad()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayer_retryLoad(reinterpret_cast<RT_GELayerHandle>(GetHandle()), &errorHandler);
}

ArcGISLoadableDoneLoadingEvent ArcGISLayer::GetDoneLoading() const
{
    return m_doneLoading;
}
void ArcGISLayer::SetDoneLoading(ArcGISLoadableDoneLoadingEvent doneLoading)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_doneLoading = std::move(doneLoading);
    
    static auto callbackHandler = [](void* userData, RT_ErrorHandle loadError_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISLayer*>(userData);
        
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
        RT_GELayer_setDoneLoadingCallback(reinterpret_cast<RT_GELayerHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GELayer_setDoneLoadingCallback(reinterpret_cast<RT_GELayerHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISLoadableLoadStatusChangedEvent ArcGISLayer::GetLoadStatusChanged() const
{
    return m_loadStatusChanged;
}
void ArcGISLayer::SetLoadStatusChanged(ArcGISLoadableLoadStatusChangedEvent loadStatusChanged)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_loadStatusChanged = std::move(loadStatusChanged);
    
    static auto callbackHandler = [](void* userData, RT_LoadStatus loadStatus_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISLayer*>(userData);
        
        auto callback = callbackObject->GetLoadStatusChanged();
        
        if (!callback)
        {
            return;
        }
        
        callback(static_cast<ArcGISLoadStatus>(loadStatus_));
    };
    
    if (m_loadStatusChanged)
    {
        RT_GELayer_setLoadStatusChangedCallback(reinterpret_cast<RT_GELayerHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GELayer_setLoadStatusChangedCallback(reinterpret_cast<RT_GELayerHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISLayer::ArcGISLayer(void* handle) :
    m_handle{ handle }
{
}

ArcGISLayer::ArcGISLayer(ArcGISLayer&& other) noexcept :
    m_handle{ other.m_handle },
    m_doneLoading{ std::move(other.m_doneLoading) },
    m_loadStatusChanged{ std::move(other.m_loadStatusChanged) }
{
    other.m_handle = nullptr;
}

ArcGISLayer::~ArcGISLayer()
{
    if (m_handle)
    {
        if (m_doneLoading)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GELayer_setDoneLoadingCallback(reinterpret_cast<RT_GELayerHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        if (m_loadStatusChanged)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GELayer_setLoadStatusChangedCallback(reinterpret_cast<RT_GELayerHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GELayer_destroy(reinterpret_cast<RT_GELayerHandle>(m_handle), &errorHandler);
    }
}

ArcGISLayer& ArcGISLayer::operator=(ArcGISLayer&& other) noexcept
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

ArcGISLayer::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISLayer::GetHandle() const
{
    return m_handle;
}
void ArcGISLayer::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Base
} // namespace Layers
} // namespace GameEngine
} // namespace Esri