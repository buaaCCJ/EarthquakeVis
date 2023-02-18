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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAngularUnit.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAngularUnitId.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AngularUnit.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISAngularUnit::ArcGISAngularUnit(ArcGISAngularUnitId unitId) :
    ArcGISUnit{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_AngularUnit_create(static_cast<RT_AngularUnitId>(unitId), &errorHandler));
}

ArcGISAngularUnitId ArcGISAngularUnit::GetAngularUnitId() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_AngularUnit_getAngularUnitId(reinterpret_cast<RT_AngularUnitHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISAngularUnitId>(localResult);
}

double ArcGISAngularUnit::ConvertFrom(const ArcGISAngularUnit& fromUnit, double angle) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localFromUnit = static_cast<const RT_AngularUnitHandle>(fromUnit.GetHandle());
    
    auto localResult = RT_AngularUnit_convertFrom(reinterpret_cast<RT_AngularUnitHandle>(GetHandle()), localFromUnit, angle, &errorHandler);
    
    return localResult;
}

double ArcGISAngularUnit::ConvertTo(const ArcGISAngularUnit& toUnit, double angle) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localToUnit = static_cast<const RT_AngularUnitHandle>(toUnit.GetHandle());
    
    auto localResult = RT_AngularUnit_convertTo(reinterpret_cast<RT_AngularUnitHandle>(GetHandle()), localToUnit, angle, &errorHandler);
    
    return localResult;
}

double ArcGISAngularUnit::FromRadians(double radians) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_AngularUnit_fromRadians(reinterpret_cast<RT_AngularUnitHandle>(GetHandle()), radians, &errorHandler);
    
    return localResult;
}

double ArcGISAngularUnit::ToRadians(double angle) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_AngularUnit_toRadians(reinterpret_cast<RT_AngularUnitHandle>(GetHandle()), angle, &errorHandler);
    
    return localResult;
}

ArcGISAngularUnit::ArcGISAngularUnit(void* handle) :
    ArcGISUnit{ handle }
{
}

ArcGISAngularUnit::ArcGISAngularUnit(ArcGISAngularUnit&& other) noexcept :
    ArcGISUnit{ std::move(other) }
{
}

ArcGISAngularUnit::ArcGISAngularUnit() :
    ArcGISUnit{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri