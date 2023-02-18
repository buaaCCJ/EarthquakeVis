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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAngularUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodeticDistanceResult.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodeticDistanceResult.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
double ArcGISGeodeticDistanceResult::GetAzimuth1() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodeticDistanceResult_getAzimuth1(reinterpret_cast<RT_GeodeticDistanceResultHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISGeodeticDistanceResult::GetAzimuth2() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodeticDistanceResult_getAzimuth2(reinterpret_cast<RT_GeodeticDistanceResultHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISAngularUnit ArcGISGeodeticDistanceResult::GetAzimuthUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodeticDistanceResult_getAzimuthUnit(reinterpret_cast<RT_GeodeticDistanceResultHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISAngularUnit{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISAngularUnit{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISGeodeticDistanceResult::GetDistance() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodeticDistanceResult_getDistance(reinterpret_cast<RT_GeodeticDistanceResultHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISLinearUnit ArcGISGeodeticDistanceResult::GetDistanceUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodeticDistanceResult_getDistanceUnit(reinterpret_cast<RT_GeodeticDistanceResultHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISLinearUnit{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISLinearUnit{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeodeticDistanceResult::ArcGISGeodeticDistanceResult(void* handle) :
    m_handle{ handle }
{
}

ArcGISGeodeticDistanceResult::ArcGISGeodeticDistanceResult(ArcGISGeodeticDistanceResult&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISGeodeticDistanceResult::~ArcGISGeodeticDistanceResult()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GeodeticDistanceResult_destroy(reinterpret_cast<RT_GeodeticDistanceResultHandle>(m_handle), &errorHandler);
    }
}

ArcGISGeodeticDistanceResult& ArcGISGeodeticDistanceResult::operator=(ArcGISGeodeticDistanceResult&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISGeodeticDistanceResult::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISGeodeticDistanceResult::GetHandle() const
{
    return m_handle;
}
void ArcGISGeodeticDistanceResult::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri