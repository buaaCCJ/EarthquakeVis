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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISIntermediateDataBuffer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/DataBuffer.h"

namespace Esri
{
namespace GameEngine
{
void* ArcGISIntermediateDataBuffer::GetData() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DataBuffer_getData(reinterpret_cast<RT_DataBufferHandle>(GetHandle()), &errorHandler);
    
    return (void*)localResult;
}

size_t ArcGISIntermediateDataBuffer::GetItemSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DataBuffer_getItemSize(reinterpret_cast<RT_DataBufferHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISIntermediateDataBuffer::GetSizeBytes() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DataBuffer_getSizeBytes(reinterpret_cast<RT_DataBufferHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISIntermediateDataBuffer::ArcGISIntermediateDataBuffer(void* handle) :
    m_handle{ handle }
{
}

ArcGISIntermediateDataBuffer::ArcGISIntermediateDataBuffer(ArcGISIntermediateDataBuffer&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISIntermediateDataBuffer::~ArcGISIntermediateDataBuffer()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_DataBuffer_destroy(reinterpret_cast<RT_DataBufferHandle>(m_handle), &errorHandler);
    }
}

ArcGISIntermediateDataBuffer& ArcGISIntermediateDataBuffer::operator=(ArcGISIntermediateDataBuffer&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISIntermediateDataBuffer::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISIntermediateDataBuffer::GetHandle() const
{
    return m_handle;
}
void ArcGISIntermediateDataBuffer::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace GameEngine
} // namespace Esri