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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAreaUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnitId.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/LinearUnit.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISLinearUnit::ArcGISLinearUnit(const ArcGISAreaUnit& areaUnit) :
    ArcGISUnit{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localAreaUnit = static_cast<const RT_AreaUnitHandle>(areaUnit.GetHandle());
    
    SetHandle(RT_LinearUnit_createFromAreaUnit(localAreaUnit, &errorHandler));
}

ArcGISLinearUnit::ArcGISLinearUnit(ArcGISLinearUnitId unitId) :
    ArcGISUnit{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_LinearUnit_create(static_cast<RT_LinearUnitId>(unitId), &errorHandler));
}

ArcGISLinearUnitId ArcGISLinearUnit::GetLinearUnitId() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_LinearUnit_getLinearUnitId(reinterpret_cast<RT_LinearUnitHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISLinearUnitId>(localResult);
}

double ArcGISLinearUnit::ConvertFrom(const ArcGISLinearUnit& fromUnit, double value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localFromUnit = static_cast<const RT_LinearUnitHandle>(fromUnit.GetHandle());
    
    auto localResult = RT_LinearUnit_convertFrom(reinterpret_cast<RT_LinearUnitHandle>(GetHandle()), localFromUnit, value, &errorHandler);
    
    return localResult;
}

double ArcGISLinearUnit::ConvertTo(const ArcGISLinearUnit& toUnit, double value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localToUnit = static_cast<const RT_LinearUnitHandle>(toUnit.GetHandle());
    
    auto localResult = RT_LinearUnit_convertTo(reinterpret_cast<RT_LinearUnitHandle>(GetHandle()), localToUnit, value, &errorHandler);
    
    return localResult;
}

double ArcGISLinearUnit::FromMeters(double value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_LinearUnit_fromMeters(reinterpret_cast<RT_LinearUnitHandle>(GetHandle()), value, &errorHandler);
    
    return localResult;
}

double ArcGISLinearUnit::ToMeters(double value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_LinearUnit_toMeters(reinterpret_cast<RT_LinearUnitHandle>(GetHandle()), value, &errorHandler);
    
    return localResult;
}

ArcGISLinearUnit::ArcGISLinearUnit(void* handle) :
    ArcGISUnit{ handle }
{
}

ArcGISLinearUnit::ArcGISLinearUnit(ArcGISLinearUnit&& other) noexcept :
    ArcGISUnit{ std::move(other) }
{
}

ArcGISLinearUnit::ArcGISLinearUnit() :
    ArcGISUnit{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri