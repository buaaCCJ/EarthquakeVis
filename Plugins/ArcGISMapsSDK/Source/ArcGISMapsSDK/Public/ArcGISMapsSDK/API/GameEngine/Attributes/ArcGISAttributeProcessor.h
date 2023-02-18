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
#pragma once

#include "ArcGISMapsSDK/API/GameEngine/Attributes/ArcGISAttributeProcessorEvent.h"

namespace Esri
{
namespace GameEngine
{
namespace Attributes
{
/// <summary>
/// Provides access to the <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessorEvent">ArcGISAttributeProcessorEvent</see>
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISAttributeProcessor
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates an attribute processor object.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISAttributeProcessor();
    #pragma endregion Constructors
    
    #pragma region Events
    /// <summary>
    /// Set an <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessorEvent">ArcGISAttributeProcessorEvent</see> which is invoked when the requested attributes are available to
    ///  be processed.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISAttributeProcessorEvent GetProcessEvent() const;
    void SetProcessEvent(ArcGISAttributeProcessorEvent processEvent);
    #pragma endregion Events

public:
    #pragma region Special Members
    explicit ArcGISAttributeProcessor(void* handle);
    ArcGISAttributeProcessor(const ArcGISAttributeProcessor&) = delete;
    ArcGISAttributeProcessor(ArcGISAttributeProcessor&& other) noexcept;
    ~ArcGISAttributeProcessor();
    
    ArcGISAttributeProcessor& operator=(const ArcGISAttributeProcessor&) = delete;
    ArcGISAttributeProcessor& operator=(ArcGISAttributeProcessor&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
    ArcGISAttributeProcessorEvent m_processEvent;
};
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri