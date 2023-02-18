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
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISLayerViewState.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISLayerViewStatus.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessage.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GELayerViewState.h"

namespace Esri
{
namespace GameEngine
{
namespace View
{
namespace State
{
ArcGISViewStateMessage ArcGISLayerViewState::GetMessage() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayerViewState_getMessage(reinterpret_cast<RT_GELayerViewStateHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISViewStateMessage{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISViewStateMessage{ localResult };
    }
    
    return localLocalResult;
}

ArcGISLayerViewStatus ArcGISLayerViewState::GetStatus() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayerViewState_getStatus(reinterpret_cast<RT_GELayerViewStateHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISLayerViewStatus>(localResult);
}

ArcGISLayerViewState::ArcGISLayerViewState(void* handle) :
    m_handle{ handle }
{
}

ArcGISLayerViewState::ArcGISLayerViewState(ArcGISLayerViewState&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISLayerViewState::~ArcGISLayerViewState()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GELayerViewState_destroy(reinterpret_cast<RT_GELayerViewStateHandle>(m_handle), &errorHandler);
    }
}

ArcGISLayerViewState& ArcGISLayerViewState::operator=(ArcGISLayerViewState&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISLayerViewState::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISLayerViewState::GetHandle() const
{
    return m_handle;
}
void ArcGISLayerViewState::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri