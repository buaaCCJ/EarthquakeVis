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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDistance.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Distance.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISLinearUnit ArcGISDistance::GetUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Distance_getUnit(reinterpret_cast<RT_DistanceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISLinearUnit{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISLinearUnit{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISDistance::GetValue() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Distance_getValue(reinterpret_cast<RT_DistanceHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISDistance::ArcGISDistance(void* handle) :
    m_handle{ handle }
{
}

ArcGISDistance::ArcGISDistance(ArcGISDistance&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISDistance::~ArcGISDistance()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Distance_destroy(reinterpret_cast<RT_DistanceHandle>(m_handle), &errorHandler);
    }
}

ArcGISDistance& ArcGISDistance::operator=(ArcGISDistance&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISDistance::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISDistance::GetHandle() const
{
    return m_handle;
}
void ArcGISDistance::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri