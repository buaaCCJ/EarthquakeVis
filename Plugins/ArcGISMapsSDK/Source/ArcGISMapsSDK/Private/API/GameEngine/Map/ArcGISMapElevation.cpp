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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMapElevation.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMapElevation.h"

namespace Esri
{
namespace GameEngine
{
namespace Map
{
ArcGISMapElevation::ArcGISMapElevation()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEMapElevation_create(&errorHandler));
}

ArcGISMapElevation::ArcGISMapElevation(Elevation::Base::ArcGISElevationSource& elevationSource)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localElevationSource = static_cast<RT_GEElevationSourceHandle>(elevationSource.GetHandle());
    
    SetHandle(RT_GEMapElevation_createWithElevationSource(localElevationSource, &errorHandler));
}

Unreal::ArcGISCollection<Elevation::Base::ArcGISElevationSource> ArcGISMapElevation::GetElevationSources() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMapElevation_getElevationSources(reinterpret_cast<RT_GEMapElevationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISCollection<Elevation::Base::ArcGISElevationSource>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISCollection<Elevation::Base::ArcGISElevationSource>{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISMapElevation::SetElevationSources(const Unreal::ArcGISCollection<Elevation::Base::ArcGISElevationSource>& elevationSources)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localElevationSources = static_cast<const RT_GEElevationSourceCollectionHandle>(elevationSources.GetHandle());
    
    RT_GEMapElevation_setElevationSources(reinterpret_cast<RT_GEMapElevationHandle>(GetHandle()), localElevationSources, &errorHandler);
}

ArcGISMapElevation::ArcGISMapElevation(void* handle) :
    m_handle{ handle }
{
}

ArcGISMapElevation::ArcGISMapElevation(ArcGISMapElevation&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISMapElevation::~ArcGISMapElevation()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEMapElevation_destroy(reinterpret_cast<RT_GEMapElevationHandle>(m_handle), &errorHandler);
    }
}

ArcGISMapElevation& ArcGISMapElevation::operator=(ArcGISMapElevation&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISMapElevation::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISMapElevation::GetHandle() const
{
    return m_handle;
}
void ArcGISMapElevation::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Map
} // namespace GameEngine
} // namespace Esri