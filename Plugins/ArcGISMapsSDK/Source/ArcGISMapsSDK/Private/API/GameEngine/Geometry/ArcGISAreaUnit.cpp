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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAreaUnit.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAreaUnitId.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/AreaUnit.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISAreaUnit::ArcGISAreaUnit(ArcGISAreaUnitId unitId) :
    ArcGISUnit{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_AreaUnit_create(static_cast<RT_AreaUnitId>(unitId), &errorHandler));
}

ArcGISAreaUnit::ArcGISAreaUnit(const ArcGISLinearUnit& linearUnit) :
    ArcGISUnit{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localLinearUnit = static_cast<const RT_LinearUnitHandle>(linearUnit.GetHandle());
    
    SetHandle(RT_AreaUnit_createFromLinearUnit(localLinearUnit, &errorHandler));
}

ArcGISAreaUnitId ArcGISAreaUnit::GetAreaUnitId() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_AreaUnit_getAreaUnitId(reinterpret_cast<RT_AreaUnitHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISAreaUnitId>(localResult);
}

double ArcGISAreaUnit::ConvertFrom(const ArcGISAreaUnit& fromUnit, double area) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localFromUnit = static_cast<const RT_AreaUnitHandle>(fromUnit.GetHandle());
    
    auto localResult = RT_AreaUnit_convertFrom(reinterpret_cast<RT_AreaUnitHandle>(GetHandle()), localFromUnit, area, &errorHandler);
    
    return localResult;
}

double ArcGISAreaUnit::ConvertTo(const ArcGISAreaUnit& toUnit, double area) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localToUnit = static_cast<const RT_AreaUnitHandle>(toUnit.GetHandle());
    
    auto localResult = RT_AreaUnit_convertTo(reinterpret_cast<RT_AreaUnitHandle>(GetHandle()), localToUnit, area, &errorHandler);
    
    return localResult;
}

double ArcGISAreaUnit::FromSquareMeters(double area) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_AreaUnit_fromSquareMeters(reinterpret_cast<RT_AreaUnitHandle>(GetHandle()), area, &errorHandler);
    
    return localResult;
}

double ArcGISAreaUnit::ToSquareMeters(double area) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_AreaUnit_toSquareMeters(reinterpret_cast<RT_AreaUnitHandle>(GetHandle()), area, &errorHandler);
    
    return localResult;
}

ArcGISAreaUnit::ArcGISAreaUnit(void* handle) :
    ArcGISUnit{ handle }
{
}

ArcGISAreaUnit::ArcGISAreaUnit(ArcGISAreaUnit&& other) noexcept :
    ArcGISUnit{ std::move(other) }
{
}

ArcGISAreaUnit::ArcGISAreaUnit() :
    ArcGISUnit{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri