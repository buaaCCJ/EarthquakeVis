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
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewState.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessage.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStatus.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewState.h"

namespace Esri
{
namespace GameEngine
{
namespace View
{
namespace State
{
ArcGISViewStateMessage ArcGISViewState::GetMessage() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEViewState_getMessage(reinterpret_cast<RT_GEViewStateHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISViewStateMessage{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISViewStateMessage{ localResult };
    }
    
    return localLocalResult;
}

ArcGISViewStatus ArcGISViewState::GetStatus() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEViewState_getStatus(reinterpret_cast<RT_GEViewStateHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISViewStatus>(localResult);
}

ArcGISViewState::ArcGISViewState(void* handle) :
    m_handle{ handle }
{
}

ArcGISViewState::ArcGISViewState(ArcGISViewState&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISViewState::~ArcGISViewState()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEViewState_destroy(reinterpret_cast<RT_GEViewStateHandle>(m_handle), &errorHandler);
    }
}

ArcGISViewState& ArcGISViewState::operator=(ArcGISViewState&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISViewState::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISViewState::GetHandle() const
{
    return m_handle;
}
void ArcGISViewState::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri