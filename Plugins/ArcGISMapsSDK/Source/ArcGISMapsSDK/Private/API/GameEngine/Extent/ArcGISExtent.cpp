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
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtent.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Extent/GEExtent.h"

namespace Esri
{
namespace GameEngine
{
namespace Extent
{
Geometry::ArcGISPoint ArcGISExtent::GetCenter() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEExtent_getCenter(reinterpret_cast<RT_GEExtentHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISExtent::ArcGISExtent(void* handle) :
    m_handle{ handle }
{
}

ArcGISExtent::ArcGISExtent(ArcGISExtent&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISExtent::~ArcGISExtent()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEExtent_destroy(reinterpret_cast<RT_GEExtentHandle>(m_handle), &errorHandler);
    }
}

ArcGISExtent& ArcGISExtent::operator=(ArcGISExtent&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISExtent::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISExtent::GetHandle() const
{
    return m_handle;
}
void ArcGISExtent::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Extent
} // namespace GameEngine
} // namespace Esri