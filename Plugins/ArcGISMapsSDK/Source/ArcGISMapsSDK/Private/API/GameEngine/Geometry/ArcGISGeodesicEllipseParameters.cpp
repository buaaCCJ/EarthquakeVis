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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodesicEllipseParameters.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodesicEllipseParameters.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISGeodesicEllipseParameters::ArcGISGeodesicEllipseParameters()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GeodesicEllipseParameters_create(&errorHandler));
}

ArcGISGeodesicEllipseParameters::ArcGISGeodesicEllipseParameters(double axisDirection, const ArcGISAngularUnit& angularUnit, const ArcGISPoint& center, const ArcGISLinearUnit& linearUnit, uint32_t maxPointCount, double maxSegmentLength, ArcGISGeometryType geometryType, double semiAxis1Length, double semiAxis2Length)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localAngularUnit = static_cast<const RT_AngularUnitHandle>(angularUnit.GetHandle());
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    const auto localLinearUnit = static_cast<const RT_LinearUnitHandle>(linearUnit.GetHandle());
    
    SetHandle(RT_GeodesicEllipseParameters_createWith(axisDirection, localAngularUnit, localCenter, localLinearUnit, maxPointCount, maxSegmentLength, static_cast<RT_GeometryType>(geometryType), semiAxis1Length, semiAxis2Length, &errorHandler));
}

ArcGISGeodesicEllipseParameters::ArcGISGeodesicEllipseParameters(const ArcGISPoint& center, double semiAxis1Length, double semiAxis2Length)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    SetHandle(RT_GeodesicEllipseParameters_createWithCenterAndAxisLengths(localCenter, semiAxis1Length, semiAxis2Length, &errorHandler));
}

ArcGISAngularUnit ArcGISGeodesicEllipseParameters::GetAngularUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getAngularUnit(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISAngularUnit{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISAngularUnit{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISGeodesicEllipseParameters::SetAngularUnit(const ArcGISAngularUnit& angularUnit)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localAngularUnit = static_cast<const RT_AngularUnitHandle>(angularUnit.GetHandle());
    
    RT_GeodesicEllipseParameters_setAngularUnit(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), localAngularUnit, &errorHandler);
}

double ArcGISGeodesicEllipseParameters::GetAxisDirection() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getAxisDirection(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicEllipseParameters::SetAxisDirection(double axisDirection)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicEllipseParameters_setAxisDirection(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), axisDirection, &errorHandler);
}

ArcGISPoint ArcGISGeodesicEllipseParameters::GetCenter() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getCenter(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISGeodesicEllipseParameters::SetCenter(const ArcGISPoint& center)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    RT_GeodesicEllipseParameters_setCenter(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), localCenter, &errorHandler);
}

ArcGISGeometryType ArcGISGeodesicEllipseParameters::GetGeometryType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getGeometryType(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISGeometryType>(localResult);
}
void ArcGISGeodesicEllipseParameters::SetGeometryType(const ArcGISGeometryType& geometryType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicEllipseParameters_setGeometryType(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), static_cast<RT_GeometryType>(geometryType), &errorHandler);
}

ArcGISLinearUnit ArcGISGeodesicEllipseParameters::GetLinearUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getLinearUnit(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISLinearUnit{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISLinearUnit{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISGeodesicEllipseParameters::SetLinearUnit(const ArcGISLinearUnit& linearUnit)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLinearUnit = static_cast<const RT_LinearUnitHandle>(linearUnit.GetHandle());
    
    RT_GeodesicEllipseParameters_setLinearUnit(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), localLinearUnit, &errorHandler);
}

uint32_t ArcGISGeodesicEllipseParameters::GetMaxPointCount() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getMaxPointCount(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicEllipseParameters::SetMaxPointCount(uint32_t maxPointCount)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicEllipseParameters_setMaxPointCount(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), maxPointCount, &errorHandler);
}

double ArcGISGeodesicEllipseParameters::GetMaxSegmentLength() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getMaxSegmentLength(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicEllipseParameters::SetMaxSegmentLength(double maxSegmentLength)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicEllipseParameters_setMaxSegmentLength(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), maxSegmentLength, &errorHandler);
}

double ArcGISGeodesicEllipseParameters::GetSemiAxis1Length() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getSemiAxis1Length(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicEllipseParameters::SetSemiAxis1Length(double semiAxis1Length)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicEllipseParameters_setSemiAxis1Length(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), semiAxis1Length, &errorHandler);
}

double ArcGISGeodesicEllipseParameters::GetSemiAxis2Length() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicEllipseParameters_getSemiAxis2Length(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicEllipseParameters::SetSemiAxis2Length(double semiAxis2Length)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicEllipseParameters_setSemiAxis2Length(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(GetHandle()), semiAxis2Length, &errorHandler);
}

ArcGISGeodesicEllipseParameters::ArcGISGeodesicEllipseParameters(void* handle) :
    m_handle{ handle }
{
}

ArcGISGeodesicEllipseParameters::ArcGISGeodesicEllipseParameters(ArcGISGeodesicEllipseParameters&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISGeodesicEllipseParameters::~ArcGISGeodesicEllipseParameters()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GeodesicEllipseParameters_destroy(reinterpret_cast<RT_GeodesicEllipseParametersHandle>(m_handle), &errorHandler);
    }
}

ArcGISGeodesicEllipseParameters& ArcGISGeodesicEllipseParameters::operator=(ArcGISGeodesicEllipseParameters&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISGeodesicEllipseParameters::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISGeodesicEllipseParameters::GetHandle() const
{
    return m_handle;
}
void ArcGISGeodesicEllipseParameters::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri