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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISProximityResult.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/ProximityResult.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPoint ArcGISProximityResult::GetCoordinate() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ProximityResult_getCoordinate(reinterpret_cast<RT_ProximityResultHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISProximityResult::GetDistance() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ProximityResult_getDistance(reinterpret_cast<RT_ProximityResultHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISProximityResult::GetPartIndex() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ProximityResult_getPartIndex(reinterpret_cast<RT_ProximityResultHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISProximityResult::GetPointIndex() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_ProximityResult_getPointIndex(reinterpret_cast<RT_ProximityResultHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISProximityResult::ArcGISProximityResult(void* handle) :
    m_handle{ handle }
{
}

ArcGISProximityResult::ArcGISProximityResult(ArcGISProximityResult&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISProximityResult::~ArcGISProximityResult()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_ProximityResult_destroy(reinterpret_cast<RT_ProximityResultHandle>(m_handle), &errorHandler);
    }
}

ArcGISProximityResult& ArcGISProximityResult::operator=(ArcGISProximityResult&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISProximityResult::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISProximityResult::GetHandle() const
{
    return m_handle;
}
void ArcGISProximityResult::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri