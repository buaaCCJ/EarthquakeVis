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
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISElevationSourceViewState.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISElevationSourceViewStatus.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessage.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEElevationSourceViewState.h"

namespace Esri
{
namespace GameEngine
{
namespace View
{
namespace State
{
ArcGISViewStateMessage ArcGISElevationSourceViewState::GetMessage() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSourceViewState_getMessage(reinterpret_cast<RT_GEElevationSourceViewStateHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISViewStateMessage{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISViewStateMessage{ localResult };
    }
    
    return localLocalResult;
}

ArcGISElevationSourceViewStatus ArcGISElevationSourceViewState::GetStatus() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSourceViewState_getStatus(reinterpret_cast<RT_GEElevationSourceViewStateHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISElevationSourceViewStatus>(localResult);
}

ArcGISElevationSourceViewState::ArcGISElevationSourceViewState(void* handle) :
    m_handle{ handle }
{
}

ArcGISElevationSourceViewState::ArcGISElevationSourceViewState(ArcGISElevationSourceViewState&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISElevationSourceViewState::~ArcGISElevationSourceViewState()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEElevationSourceViewState_destroy(reinterpret_cast<RT_GEElevationSourceViewStateHandle>(m_handle), &errorHandler);
    }
}

ArcGISElevationSourceViewState& ArcGISElevationSourceViewState::operator=(ArcGISElevationSourceViewState&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISElevationSourceViewState::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISElevationSourceViewState::GetHandle() const
{
    return m_handle;
}
void ArcGISElevationSourceViewState::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri