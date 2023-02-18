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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelope.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometry.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryDimension.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygon.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Geometry.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISGeometryDimension ArcGISGeometry::GetDimension() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Geometry_getDimension(reinterpret_cast<RT_GeometryHandle>(GetHandle()), &errorHandler);
    
    return static_cast<ArcGISGeometryDimension>(localResult);
}

ArcGISEnvelope ArcGISGeometry::GetExtent() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Geometry_getExtent(reinterpret_cast<RT_GeometryHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISGeometry::GetHasCurves() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Geometry_getHasCurves(reinterpret_cast<RT_GeometryHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISGeometry::GetHasM() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Geometry_getHasM(reinterpret_cast<RT_GeometryHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISGeometry::GetHasZ() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Geometry_getHasZ(reinterpret_cast<RT_GeometryHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISGeometry::GetIsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Geometry_getIsEmpty(reinterpret_cast<RT_GeometryHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISGeometry::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Geometry_getSpatialReference(reinterpret_cast<RT_GeometryHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISGeometry::Equals(const ArcGISGeometry& right) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localRight = static_cast<const RT_GeometryHandle>(right.GetHandle());
    
    auto localResult = RT_Geometry_equals(reinterpret_cast<RT_GeometryHandle>(GetHandle()), localRight, &errorHandler);
    
    return localResult;
}

bool ArcGISGeometry::Equals(const ArcGISGeometry& right, double tolerance) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localRight = static_cast<const RT_GeometryHandle>(right.GetHandle());
    
    auto localResult = RT_Geometry_equalsWithTolerance(reinterpret_cast<RT_GeometryHandle>(GetHandle()), localRight, tolerance, &errorHandler);
    
    return localResult;
}

ArcGISGeometry ArcGISGeometry::FromJSON(const FString& inputJSON, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_Geometry_fromJSONWithSpatialReference(TCHAR_TO_ANSI(*inputJSON), localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISGeometry{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_Geometry_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryType_envelope:
                localLocalResult = ArcGISEnvelope{ localResult };
                break;
            case RT_GeometryType_multipoint:
                localLocalResult = ArcGISMultipoint{ localResult };
                break;
            case RT_GeometryType_point:
                localLocalResult = ArcGISPoint{ localResult };
                break;
            case RT_GeometryType_polygon:
                localLocalResult = ArcGISPolygon{ localResult };
                break;
            case RT_GeometryType_polyline:
                localLocalResult = ArcGISPolyline{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometry{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometry::ArcGISGeometry(void* handle) :
    m_handle{ handle }
{
}

ArcGISGeometry::ArcGISGeometry(ArcGISGeometry&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISGeometry::~ArcGISGeometry()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_Geometry_destroy(reinterpret_cast<RT_GeometryHandle>(m_handle), &errorHandler);
    }
}

ArcGISGeometry& ArcGISGeometry::operator=(ArcGISGeometry&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISGeometry::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISGeometry::GetHandle() const
{
    return m_handle;
}
void ArcGISGeometry::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri