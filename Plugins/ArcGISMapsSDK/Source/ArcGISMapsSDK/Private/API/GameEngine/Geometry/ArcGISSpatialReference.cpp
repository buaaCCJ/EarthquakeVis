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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelope.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpheroidData.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUnit.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/SpatialReference.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Unit.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISSpatialReference::ArcGISSpatialReference(int32_t WKID)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_SpatialReference_create(WKID, &errorHandler));
}

ArcGISSpatialReference::ArcGISSpatialReference(int32_t WKID, int32_t verticalWKID)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_SpatialReference_createVerticalWKID(WKID, verticalWKID, &errorHandler));
}

ArcGISSpatialReference::ArcGISSpatialReference(const FString& wkText)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_SpatialReference_createFromWKText(TCHAR_TO_ANSI(*wkText), &errorHandler));
}

ArcGISSpatialReference ArcGISSpatialReference::GetBaseGeographic() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getBaseGeographic(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISEnvelope ArcGISSpatialReference::GetFullWorldExtent() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getFullWorldExtent(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISSpatialReference::GetHasVertical() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getHasVertical(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISSpatialReference::GetIsGeographic() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getIsGeographic(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISSpatialReference::GetIsPannable() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getIsPannable(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISSpatialReference::GetIsProjected() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getIsProjected(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpheroidData ArcGISSpatialReference::GetSpheroidData() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getSpheroidData(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    return std::move(reinterpret_cast<ArcGISSpheroidData&>(localResult));
}

ArcGISUnit ArcGISSpatialReference::GetUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getUnit(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
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

ArcGISLinearUnit ArcGISSpatialReference::GetVerticalUnit() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getVerticalUnit(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISLinearUnit{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISLinearUnit{ localResult };
    }
    
    return localLocalResult;
}

int32_t ArcGISSpatialReference::GetVerticalWKID() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getVerticalWKID(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

int32_t ArcGISSpatialReference::GetWKID() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getWKID(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

FString ArcGISSpatialReference::GetWKText() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_getWKText(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

bool ArcGISSpatialReference::Equals(const ArcGISSpatialReference& right) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localRight = static_cast<const RT_SpatialReferenceHandle>(right.GetHandle());
    
    auto localResult = RT_SpatialReference_equals(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), localRight, &errorHandler);
    
    return localResult;
}

double ArcGISSpatialReference::GetConvergenceAngle(const ArcGISPoint& point) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_SpatialReference_getConvergenceAngle(reinterpret_cast<RT_SpatialReferenceHandle>(GetHandle()), localPoint, &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISSpatialReference::WebMercator()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_webMercator(&errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISSpatialReference ArcGISSpatialReference::WGS84()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_SpatialReference_WGS84(&errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISSpatialReference::ArcGISSpatialReference(void* handle) :
    m_handle{ handle }
{
}

ArcGISSpatialReference::ArcGISSpatialReference(ArcGISSpatialReference&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISSpatialReference::~ArcGISSpatialReference()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_SpatialReference_destroy(reinterpret_cast<RT_SpatialReferenceHandle>(m_handle), &errorHandler);
    }
}

ArcGISSpatialReference& ArcGISSpatialReference::operator=(ArcGISSpatialReference&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISSpatialReference::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISSpatialReference::GetHandle() const
{
    return m_handle;
}
void ArcGISSpatialReference::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri