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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodesicSectorParameters.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeodesicSectorParameters.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISGeodesicSectorParameters::ArcGISGeodesicSectorParameters()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GeodesicSectorParameters_create(&errorHandler));
}

ArcGISGeodesicSectorParameters::ArcGISGeodesicSectorParameters(double axisDirection, const ArcGISAngularUnit& angularUnit, const ArcGISPoint& center, const ArcGISLinearUnit& linearUnit, uint32_t maxPointCount, double maxSegmentLength, ArcGISGeometryType geometryType, double sectorAngle, double semiAxis1Length, double semiAxis2Length, double startDirection)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localAngularUnit = static_cast<const RT_AngularUnitHandle>(angularUnit.GetHandle());
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    const auto localLinearUnit = static_cast<const RT_LinearUnitHandle>(linearUnit.GetHandle());
    
    SetHandle(RT_GeodesicSectorParameters_createWith(axisDirection, localAngularUnit, localCenter, localLinearUnit, maxPointCount, maxSegmentLength, static_cast<RT_GeometryType>(geometryType), sectorAngle, semiAxis1Length, semiAxis2Length, startDirection, &errorHandler));
}

ArcGISGeodesicSectorParameters::ArcGISGeodesicSectorParameters(const ArcGISPoint& center, double semiAxis1Length, double semiAxis2Length, double sectorAngle, double startDirection)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    SetHandle(RT_GeodesicSectorParameters_createWithCenterAndAxisLengthsAndSectorAngleAndStartDirection(localCenter, semiAxis1Length, semiAxis2Length, sectorAngle, startDirection, &errorHandler));
}

ArcGISAngularUnit ArcGISGeodesicSectorParameters::GetAngularUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getAngularUnit(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISAngularUnit{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISAngularUnit{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISGeodesicSectorParameters::SetAngularUnit(const ArcGISAngularUnit& angularUnit)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localAngularUnit = static_cast<const RT_AngularUnitHandle>(angularUnit.GetHandle());
    
    RT_GeodesicSectorParameters_setAngularUnit(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), localAngularUnit, &errorHandler);
}

double ArcGISGeodesicSectorParameters::GetAxisDirection() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getAxisDirection(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicSectorParameters::SetAxisDirection(double axisDirection)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicSectorParameters_setAxisDirection(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), axisDirection, &errorHandler);
}

ArcGISPoint ArcGISGeodesicSectorParameters::GetCenter() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getCenter(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISGeodesicSectorParameters::SetCenter(const ArcGISPoint& center)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    RT_GeodesicSectorParameters_setCenter(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), localCenter, &errorHandler);
}

ArcGISGeometryType ArcGISGeodesicSectorParameters::GetGeometryType() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getGeometryType(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISGeometryType>(localResult);
}
void ArcGISGeodesicSectorParameters::SetGeometryType(const ArcGISGeometryType& geometryType)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicSectorParameters_setGeometryType(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), static_cast<RT_GeometryType>(geometryType), &errorHandler);
}

ArcGISLinearUnit ArcGISGeodesicSectorParameters::GetLinearUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getLinearUnit(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISLinearUnit{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISLinearUnit{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISGeodesicSectorParameters::SetLinearUnit(const ArcGISLinearUnit& linearUnit)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLinearUnit = static_cast<const RT_LinearUnitHandle>(linearUnit.GetHandle());
    
    RT_GeodesicSectorParameters_setLinearUnit(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), localLinearUnit, &errorHandler);
}

uint32_t ArcGISGeodesicSectorParameters::GetMaxPointCount() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getMaxPointCount(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicSectorParameters::SetMaxPointCount(uint32_t maxPointCount)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicSectorParameters_setMaxPointCount(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), maxPointCount, &errorHandler);
}

double ArcGISGeodesicSectorParameters::GetMaxSegmentLength() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getMaxSegmentLength(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicSectorParameters::SetMaxSegmentLength(double maxSegmentLength)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicSectorParameters_setMaxSegmentLength(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), maxSegmentLength, &errorHandler);
}

double ArcGISGeodesicSectorParameters::GetSectorAngle() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getSectorAngle(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicSectorParameters::SetSectorAngle(double sectorAngle)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicSectorParameters_setSectorAngle(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), sectorAngle, &errorHandler);
}

double ArcGISGeodesicSectorParameters::GetSemiAxis1Length() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getSemiAxis1Length(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicSectorParameters::SetSemiAxis1Length(double semiAxis1Length)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicSectorParameters_setSemiAxis1Length(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), semiAxis1Length, &errorHandler);
}

double ArcGISGeodesicSectorParameters::GetSemiAxis2Length() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getSemiAxis2Length(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicSectorParameters::SetSemiAxis2Length(double semiAxis2Length)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicSectorParameters_setSemiAxis2Length(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), semiAxis2Length, &errorHandler);
}

double ArcGISGeodesicSectorParameters::GetStartDirection() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeodesicSectorParameters_getStartDirection(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISGeodesicSectorParameters::SetStartDirection(double startDirection)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GeodesicSectorParameters_setStartDirection(reinterpret_cast<RT_GeodesicSectorParametersHandle>(GetHandle()), startDirection, &errorHandler);
}

ArcGISGeodesicSectorParameters::ArcGISGeodesicSectorParameters(void* handle) :
    m_handle{ handle }
{
}

ArcGISGeodesicSectorParameters::ArcGISGeodesicSectorParameters(ArcGISGeodesicSectorParameters&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISGeodesicSectorParameters::~ArcGISGeodesicSectorParameters()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GeodesicSectorParameters_destroy(reinterpret_cast<RT_GeodesicSectorParametersHandle>(m_handle), &errorHandler);
    }
}

ArcGISGeodesicSectorParameters& ArcGISGeodesicSectorParameters::operator=(ArcGISGeodesicSectorParameters&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISGeodesicSectorParameters::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISGeodesicSectorParameters::GetHandle() const
{
    return m_handle;
}
void ArcGISGeodesicSectorParameters::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri