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
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderCommandServer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISDataBuffer.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/RCQ/RenderCommandServer.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
Unreal::ArcGISDataBuffer<uint8_t> ArcGISRenderCommandServer::GetRenderCommands() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_RenderCommandServer_getRenderCommands(reinterpret_cast<RT_RenderCommandServerHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISDataBuffer<uint8_t>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISDataBuffer<uint8_t>{ localResult };
    }
    
    return localLocalResult;
}

void ArcGISRenderCommandServer::NotifyRenderableHasGPUResources(TArrayView<uint8> callbackTokens)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localCallbackTokens = RT_ByteArray{callbackTokens.IsEmpty() ? nullptr : &callbackTokens[0], static_cast<size_t>(callbackTokens.Num())};
    
    RT_RenderCommandServer_notifyRenderableHasGPUResources(reinterpret_cast<RT_RenderCommandServerHandle>(GetHandle()), localCallbackTokens, &errorHandler);
}

ArcGISRenderCommandServer::ArcGISRenderCommandServer(void* handle) :
    m_handle{ handle }
{
}

ArcGISRenderCommandServer::ArcGISRenderCommandServer(ArcGISRenderCommandServer&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISRenderCommandServer::~ArcGISRenderCommandServer()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_RenderCommandServer_destroy(reinterpret_cast<RT_RenderCommandServerHandle>(m_handle), &errorHandler);
    }
}

ArcGISRenderCommandServer& ArcGISRenderCommandServer::operator=(ArcGISRenderCommandServer&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISRenderCommandServer::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISRenderCommandServer::GetHandle() const
{
    return m_handle;
}
void ArcGISRenderCommandServer::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri