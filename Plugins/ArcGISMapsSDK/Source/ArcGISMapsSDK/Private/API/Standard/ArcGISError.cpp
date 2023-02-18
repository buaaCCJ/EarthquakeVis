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
#include "ArcGISMapsSDK/API/Standard/ArcGISError.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/Standard/Error.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace Standard
{
FString ArcGISError::GetAdditionalMessage() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Error_getAdditionalMessage(reinterpret_cast<RT_ErrorHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

int32_t ArcGISError::GetCode() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Error_getCode(reinterpret_cast<RT_ErrorHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

FString ArcGISError::GetMessage() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Error_getMessage(reinterpret_cast<RT_ErrorHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

void* ArcGISError::GetUserDefinedFailure() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Error_getUserDefinedFailure(reinterpret_cast<RT_ErrorHandle>(GetHandle()), &errorHandler);
    
    return (void*)localResult;
}

ArcGISError::ArcGISError(void* handle) :
    m_handle{ handle }
{
}

ArcGISError::ArcGISError(ArcGISError&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISError::~ArcGISError()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Error_destroy(reinterpret_cast<RT_ErrorHandle>(m_handle), &errorHandler);
    }
}

ArcGISError& ArcGISError::operator=(ArcGISError&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISError::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISError::GetHandle() const
{
    return m_handle;
}
void ArcGISError::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Standard
} // namespace Esri