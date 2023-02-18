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
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttribute.h"
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttributeProcessor.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISVisualizationAttribute.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableArray.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Attributes/AttributeProcessor.h"

namespace Esri
{
namespace GameEngine
{
namespace Attributes
{
ArcGISAttributeProcessor::ArcGISAttributeProcessor()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_AttributeProcessor_create(&errorHandler));
}

ArcGISAttributeProcessorEvent ArcGISAttributeProcessor::GetProcessEvent() const
{
    return m_processEvent;
}
void ArcGISAttributeProcessor::SetProcessEvent(ArcGISAttributeProcessorEvent processEvent)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_processEvent = std::move(processEvent);
    
    static auto callbackHandler = [](void* userData, const RT_ArrayHandle layerAttributes_, const RT_ArrayHandle visualizationAttributes_)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISAttributeProcessor*>(userData);
        
        auto callback = callbackObject->GetProcessEvent();
        
        if (!callback)
        {
            return;
        }
        
        auto localLayerAttributes = Unreal::ArcGISImmutableArray<ArcGISAttribute>{};
        
        if (layerAttributes_ != nullptr)
        {
            localLayerAttributes = Unreal::ArcGISImmutableArray<ArcGISAttribute>{ layerAttributes_ };
        }
        
        auto localVisualizationAttributes = Unreal::ArcGISImmutableArray<ArcGISVisualizationAttribute>{};
        
        if (visualizationAttributes_ != nullptr)
        {
            localVisualizationAttributes = Unreal::ArcGISImmutableArray<ArcGISVisualizationAttribute>{ visualizationAttributes_ };
        }
        
        callback(localLayerAttributes, localVisualizationAttributes);
    };
    
    if (m_processEvent)
    {
        RT_AttributeProcessor_setProcessEventCallback(reinterpret_cast<RT_AttributeProcessorHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_AttributeProcessor_setProcessEventCallback(reinterpret_cast<RT_AttributeProcessorHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISAttributeProcessor::ArcGISAttributeProcessor(void* handle) :
    m_handle{ handle }
{
}

ArcGISAttributeProcessor::ArcGISAttributeProcessor(ArcGISAttributeProcessor&& other) noexcept :
    m_handle{ other.m_handle },
    m_processEvent{ std::move(other.m_processEvent) }
{
    other.m_handle = nullptr;
}

ArcGISAttributeProcessor::~ArcGISAttributeProcessor()
{
    if (m_handle)
    {
        if (m_processEvent)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_AttributeProcessor_setProcessEventCallback(reinterpret_cast<RT_AttributeProcessorHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_AttributeProcessor_destroy(reinterpret_cast<RT_AttributeProcessorHandle>(m_handle), &errorHandler);
    }
}

ArcGISAttributeProcessor& ArcGISAttributeProcessor::operator=(ArcGISAttributeProcessor&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
        swap(m_processEvent, other.m_processEvent);
    }
    
    return *this;
}

ArcGISAttributeProcessor::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISAttributeProcessor::GetHandle() const
{
    return m_handle;
}
void ArcGISAttributeProcessor::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri