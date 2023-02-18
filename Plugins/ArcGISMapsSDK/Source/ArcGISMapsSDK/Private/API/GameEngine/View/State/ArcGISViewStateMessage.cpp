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
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessage.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewStateMessageType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISDictionary.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/State/GEViewStateMessage.h"

namespace Esri
{
namespace GameEngine
{
namespace View
{
namespace State
{
Unreal::ArcGISDictionary<FString, FString> ArcGISViewStateMessage::GetAdditionalInformation() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEViewStateMessage_getAdditionalInformation(reinterpret_cast<RT_GEViewStateMessageHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISDictionary<FString, FString>{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISDictionary<FString, FString>{ localResult };
    }
    
    return localLocalResult;
}

uint32_t ArcGISViewStateMessage::GetCode() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEViewStateMessage_getCode(reinterpret_cast<RT_GEViewStateMessageHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

FString ArcGISViewStateMessage::GetMessage() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEViewStateMessage_getMessage(reinterpret_cast<RT_GEViewStateMessageHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISViewStateMessageType ArcGISViewStateMessage::GetMessageType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEViewStateMessage_getMessageType(reinterpret_cast<RT_GEViewStateMessageHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISViewStateMessageType>(localResult);
}

ArcGISViewStateMessage::ArcGISViewStateMessage(void* handle) :
    m_handle{ handle }
{
}

ArcGISViewStateMessage::ArcGISViewStateMessage(ArcGISViewStateMessage&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISViewStateMessage::~ArcGISViewStateMessage()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEViewStateMessage_destroy(reinterpret_cast<RT_GEViewStateMessageHandle>(m_handle), &errorHandler);
    }
}

ArcGISViewStateMessage& ArcGISViewStateMessage::operator=(ArcGISViewStateMessage&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISViewStateMessage::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISViewStateMessage::GetHandle() const
{
    return m_handle;
}
void ArcGISViewStateMessage::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri