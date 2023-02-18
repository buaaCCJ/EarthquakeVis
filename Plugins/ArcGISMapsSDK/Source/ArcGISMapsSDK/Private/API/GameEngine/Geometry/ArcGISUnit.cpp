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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAreaUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUnit.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Unit.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
FString ArcGISUnit::GetAbbreviation() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_getAbbreviation(reinterpret_cast<RT_UnitHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISUnit::GetDisplayName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_getDisplayName(reinterpret_cast<RT_UnitHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISUnit::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_getName(reinterpret_cast<RT_UnitHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISUnit::GetPluralDisplayName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_getPluralDisplayName(reinterpret_cast<RT_UnitHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

int32_t ArcGISUnit::GetUnitId() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_getUnitId(reinterpret_cast<RT_UnitHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

int32_t ArcGISUnit::GetWKID() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_getWKID(reinterpret_cast<RT_UnitHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISUnit ArcGISUnit::FromUnitId(int32_t unitId)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_fromUnitId(unitId, &errorHandler);
    
    auto localLocalResult = ArcGISUnit{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Unit_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_UnitType_angularUnit:
                localLocalResult = ArcGISAngularUnit{ localResult };
                break;
            case RT_UnitType_areaUnit:
                localLocalResult = ArcGISAreaUnit{ localResult };
                break;
            case RT_UnitType_linearUnit:
                localLocalResult = ArcGISLinearUnit{ localResult };
                break;
            default:
                localLocalResult = ArcGISUnit{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISUnit ArcGISUnit::FromWKID(int32_t WKID)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_fromWKID(WKID, &errorHandler);
    
    auto localLocalResult = ArcGISUnit{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Unit_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_UnitType_angularUnit:
                localLocalResult = ArcGISAngularUnit{ localResult };
                break;
            case RT_UnitType_areaUnit:
                localLocalResult = ArcGISAreaUnit{ localResult };
                break;
            case RT_UnitType_linearUnit:
                localLocalResult = ArcGISLinearUnit{ localResult };
                break;
            default:
                localLocalResult = ArcGISUnit{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISUnit::ArcGISUnit(void* handle) :
    m_handle{ handle }
{
}

ArcGISUnit::ArcGISUnit(ArcGISUnit&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISUnit::~ArcGISUnit()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Unit_destroy(reinterpret_cast<RT_UnitHandle>(m_handle), &errorHandler);
    }
}

ArcGISUnit& ArcGISUnit::operator=(ArcGISUnit&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISUnit::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISUnit::GetHandle() const
{
    return m_handle;
}
void ArcGISUnit::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri