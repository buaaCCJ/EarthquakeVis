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
#include "ArcGISMapsSDK/API/GameEngine/MapView/ArcGISCamera.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/MapView/Camera.h"

namespace Esri
{
namespace GameEngine
{
namespace MapView
{
ArcGISCamera::ArcGISCamera(const Geometry::ArcGISPoint& locationPoint, double heading, double pitch, double roll)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLocationPoint = static_cast<const RT_PointHandle>(locationPoint.GetHandle());
    
    SetHandle(RT_Camera_createWithLocationHeadingPitchRoll(localLocationPoint, heading, pitch, roll, &errorHandler));
}

double ArcGISCamera::GetHeading() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Camera_getHeading(reinterpret_cast<RT_CameraHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

Geometry::ArcGISPoint ArcGISCamera::GetLocation() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Camera_getLocation(reinterpret_cast<RT_CameraHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISCamera::GetPitch() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Camera_getPitch(reinterpret_cast<RT_CameraHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISCamera::GetRoll() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Camera_getRoll(reinterpret_cast<RT_CameraHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISCamera ArcGISCamera::Elevate(double deltaAltitude) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Camera_elevate(reinterpret_cast<RT_CameraHandle>(GetHandle()), deltaAltitude, &errorHandler);
    
    auto localLocalResult = ArcGISCamera{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISCamera{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISCamera::Equals(const ArcGISCamera& otherCamera) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localOtherCamera = static_cast<const RT_CameraHandle>(otherCamera.GetHandle());
    
    auto localResult = RT_Camera_equals(reinterpret_cast<RT_CameraHandle>(GetHandle()), localOtherCamera, &errorHandler);
    
    return localResult;
}

ArcGISCamera ArcGISCamera::MoveTo(const Geometry::ArcGISPoint& location) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLocation = static_cast<const RT_PointHandle>(location.GetHandle());
    
    auto localResult = RT_Camera_moveTo(reinterpret_cast<RT_CameraHandle>(GetHandle()), localLocation, &errorHandler);
    
    auto localLocalResult = ArcGISCamera{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISCamera{ localResult };
    }
    
    return localLocalResult;
}

ArcGISCamera ArcGISCamera::RotateTo(double heading, double pitch, double roll) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Camera_rotateTo(reinterpret_cast<RT_CameraHandle>(GetHandle()), heading, pitch, roll, &errorHandler);
    
    auto localLocalResult = ArcGISCamera{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISCamera{ localResult };
    }
    
    return localLocalResult;
}

ArcGISCamera::ArcGISCamera(void* handle) :
    m_handle{ handle }
{
}

ArcGISCamera::ArcGISCamera(ArcGISCamera&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISCamera::~ArcGISCamera()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Camera_destroy(reinterpret_cast<RT_CameraHandle>(m_handle), &errorHandler);
    }
}

ArcGISCamera& ArcGISCamera::operator=(ArcGISCamera&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISCamera::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISCamera::GetHandle() const
{
    return m_handle;
}
void ArcGISCamera::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace MapView
} // namespace GameEngine
} // namespace Esri