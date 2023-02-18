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
#include "ArcGISMapsSDK/API/GameEngine/Security/ArcGISAuthenticationChallenge.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Security/GEAuthenticationChallenge.h"

namespace Esri
{
namespace GameEngine
{
namespace Security
{
void ArcGISAuthenticationChallenge::Cancel()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEAuthenticationChallenge_cancel(reinterpret_cast<RT_GEAuthenticationChallengeHandle>(GetHandle()), &errorHandler);
}

ArcGISAuthenticationChallenge::ArcGISAuthenticationChallenge(void* handle) :
    m_handle{ handle }
{
}

ArcGISAuthenticationChallenge::ArcGISAuthenticationChallenge(ArcGISAuthenticationChallenge&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISAuthenticationChallenge::~ArcGISAuthenticationChallenge()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEAuthenticationChallenge_destroy(reinterpret_cast<RT_GEAuthenticationChallengeHandle>(m_handle), &errorHandler);
    }
}

ArcGISAuthenticationChallenge& ArcGISAuthenticationChallenge::operator=(ArcGISAuthenticationChallenge&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISAuthenticationChallenge::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISAuthenticationChallenge::GetHandle() const
{
    return m_handle;
}
void ArcGISAuthenticationChallenge::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Security
} // namespace GameEngine
} // namespace Esri