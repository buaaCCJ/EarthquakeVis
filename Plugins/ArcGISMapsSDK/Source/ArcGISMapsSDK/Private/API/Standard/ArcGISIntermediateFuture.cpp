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
#include "ArcGISMapsSDK/API/Standard/ArcGISElement.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISFutureStatus.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISIntermediateFuture.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISException.h"
#include "ArcGISMapsSDK/CAPI/Standard/Future.h"

namespace Esri
{
namespace Standard
{
bool ArcGISIntermediateFuture::Cancel()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Task_cancel(reinterpret_cast<RT_TaskHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISElement ArcGISIntermediateFuture::Get() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Task_get(reinterpret_cast<RT_TaskHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISElement{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISElement{ localResult };
    }
    
    return localLocalResult;
}

Unreal::ArcGISException ArcGISIntermediateFuture::GetError() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Task_getError(reinterpret_cast<RT_TaskHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Unreal::ArcGISException{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Unreal::ArcGISException{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISIntermediateFuture::IsCanceled() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Task_isCanceled(reinterpret_cast<RT_TaskHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISIntermediateFuture::IsDone() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Task_isDone(reinterpret_cast<RT_TaskHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISFutureStatus ArcGISIntermediateFuture::Wait() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Task_wait(reinterpret_cast<RT_TaskHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISFutureStatus>(localResult);
}

ArcGISFutureCompletedEvent ArcGISIntermediateFuture::GetTaskCompleted() const
{
    return m_taskCompleted;
}
void ArcGISIntermediateFuture::SetTaskCompleted(ArcGISFutureCompletedEvent taskCompleted)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    m_taskCompleted = std::move(taskCompleted);
    
    static auto callbackHandler = [](void* userData)
    {
        if (!userData)
        {
            return;
        }
        
        auto* callbackObject = reinterpret_cast<ArcGISIntermediateFuture*>(userData);
        
        auto callback = callbackObject->GetTaskCompleted();
        
        if (!callback)
        {
            return;
        }
        
        callback();
    };
    
    if (m_taskCompleted)
    {
        RT_Task_setTaskCompletedCallback(reinterpret_cast<RT_TaskHandle>(GetHandle()), callbackHandler, reinterpret_cast<void*>(this), &errorHandler);
    }
    else
    {
        RT_Task_setTaskCompletedCallback(reinterpret_cast<RT_TaskHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
    }
}

ArcGISIntermediateFuture::ArcGISIntermediateFuture(void* handle) :
    m_handle{ handle }
{
}

ArcGISIntermediateFuture::ArcGISIntermediateFuture(ArcGISIntermediateFuture&& other) noexcept :
    m_handle{ other.m_handle },
    m_taskCompleted{ std::move(other.m_taskCompleted) }
{
    other.m_handle = nullptr;
}

ArcGISIntermediateFuture::~ArcGISIntermediateFuture()
{
    if (m_handle)
    {
        if (m_taskCompleted)
        {
            auto errorHandler = Unreal::CreateErrorHandler();
            
            RT_Task_setTaskCompletedCallback(reinterpret_cast<RT_TaskHandle>(GetHandle()), nullptr, reinterpret_cast<void*>(this), &errorHandler);
        }
        
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Task_destroy(reinterpret_cast<RT_TaskHandle>(m_handle), &errorHandler);
    }
}

ArcGISIntermediateFuture& ArcGISIntermediateFuture::operator=(ArcGISIntermediateFuture&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
        swap(m_taskCompleted, other.m_taskCompleted);
    }
    
    return *this;
}

ArcGISIntermediateFuture::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISIntermediateFuture::GetHandle() const
{
    return m_handle;
}
void ArcGISIntermediateFuture::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Standard
} // namespace Esri