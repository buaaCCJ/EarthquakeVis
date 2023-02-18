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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSourceType.h"
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentRectangle.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISException.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSource.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Elevation
{
namespace Base
{
ArcGISElevationSource::ArcGISElevationSource(const FString& source, ArcGISElevationSourceType type, const FString& APIKey)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEElevationSource_create(TCHAR_TO_ANSI(*source), static_cast<RT_GEElevationSourceType>(type), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

FString ArcGISElevationSource::GetAPIKey() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getAPIKey(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

Extent::ArcGISExtentRectangle ArcGISElevationSource::GetExtent() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getExtent(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Extent::ArcGISExtentRectangle{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Extent::ArcGISExtentRectangle{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISElevationSource::GetIsEnabled() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getIsEnabled(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISElevationSource::SetIsEnabled(bool isEnabled)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEElevationSource_setIsEnabled(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), isEnabled, &errorHandler);
}

FString ArcGISElevationSource::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getName(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}
void ArcGISElevationSource::SetName(const FString& name)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEElevationSource_setName(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), TCHAR_TO_ANSI(*name), &errorHandler);
}

FString ArcGISElevationSource::GetSource() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getSource(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

Geometry::ArcGISSpatialReference ArcGISElevationSource::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getSpatialReference(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISException ArcGISElevationSource::GetLoadError() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getLoadError(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISException{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISException{ localResult };
    }
    
    return localLocalResult;
}

ArcGISLoadStatus ArcGISElevationSource::GetLoadStatus() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getLoadStatus(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISLoadStatus>(localResult);
}

void ArcGISElevationSource::CancelLoad()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEElevationSource_cancelLoad(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
}

void ArcGISElevationSource::Load()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEElevationSource_load(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
}

void ArcGISElevationSource::RetryLoad()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEElevationSource_retryLoad(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), &errorHandler);
}

ArcGISLoadableDoneLoadingEvent ArcGISElevationSource::GetDoneLoading() const
{
    return m_doneLoading;
}
void ArcGISElevationSource::SetDoneLoading(ArcGISLoadableDoneLoadingEvent doneLoading)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_doneLoading = std::move(doneLoading);
    
    static auto callbackHandler = [](void* userData, RT_ErrorHandle loadError_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISElevationSource*>(userData);
        
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
        RT_GEElevationSource_setDoneLoadingCallback(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEElevationSource_setDoneLoadingCallback(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISLoadableLoadStatusChangedEvent ArcGISElevationSource::GetLoadStatusChanged() const
{
    return m_loadStatusChanged;
}
void ArcGISElevationSource::SetLoadStatusChanged(ArcGISLoadableLoadStatusChangedEvent loadStatusChanged)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_loadStatusChanged = std::move(loadStatusChanged);
    
    static auto callbackHandler = [](void* userData, RT_LoadStatus loadStatus_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISElevationSource*>(userData);
        
        auto callback = callbackObject->GetLoadStatusChanged();
        
        if (!callback)
        {
            return;
        }
        
        callback(static_cast<ArcGISLoadStatus>(loadStatus_));
    };
    
    if (m_loadStatusChanged)
    {
        RT_GEElevationSource_setLoadStatusChangedCallback(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_GEElevationSource_setLoadStatusChangedCallback(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISElevationSource::ArcGISElevationSource(void* handle) :
    m_handle{ handle }
{
}

ArcGISElevationSource::ArcGISElevationSource(ArcGISElevationSource&& other) noexcept :
    m_handle{ other.m_handle },
    m_doneLoading{ std::move(other.m_doneLoading) },
    m_loadStatusChanged{ std::move(other.m_loadStatusChanged) }
{
    other.m_handle = nullptr;
}

ArcGISElevationSource::~ArcGISElevationSource()
{
    if (m_handle)
    {
        if (m_doneLoading)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEElevationSource_setDoneLoadingCallback(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        if (m_loadStatusChanged)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_GEElevationSource_setLoadStatusChangedCallback(reinterpret_cast<RT_GEElevationSourceHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEElevationSource_destroy(reinterpret_cast<RT_GEElevationSourceHandle>(m_handle), &errorHandler);
    }
}

ArcGISElevationSource& ArcGISElevationSource::operator=(ArcGISElevationSource&& other) noexcept
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

ArcGISElevationSource::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISElevationSource::GetHandle() const
{
    return m_handle;
}
void ArcGISElevationSource::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Base
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri