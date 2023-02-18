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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelopeBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometry.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipartBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipointBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPointBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygon.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolygonBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolyline.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPolylineBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Geometry.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISEnvelope ArcGISGeometryBuilder::GetExtent() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_getExtent(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISGeometryBuilder::GetHasCurves() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_getHasCurves(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISGeometryBuilder::GetHasM() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_getHasM(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISGeometryBuilder::GetHasZ() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_getHasZ(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISGeometryBuilder::GetIsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_getIsEmpty(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

bool ArcGISGeometryBuilder::GetIsSketchValid() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_getIsSketchValid(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISSpatialReference ArcGISGeometryBuilder::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_getSpatialReference(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

ArcGISGeometryBuilder ArcGISGeometryBuilder::Create(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    auto localResult = RT_GeometryBuilder_createFromGeometry(localGeometry, &errorHandler);
    
    auto localLocalResult = ArcGISGeometryBuilder{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GeometryBuilder_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryBuilderType_envelopeBuilder:
                localLocalResult = ArcGISEnvelopeBuilder{ localResult };
                break;
            case RT_GeometryBuilderType_multipointBuilder:
                localLocalResult = ArcGISMultipointBuilder{ localResult };
                break;
            case RT_GeometryBuilderType_pointBuilder:
                localLocalResult = ArcGISPointBuilder{ localResult };
                break;
            case RT_GeometryBuilderType_polygonBuilder:
                localLocalResult = ArcGISPolygonBuilder{ localResult };
                break;
            case RT_GeometryBuilderType_polylineBuilder:
                localLocalResult = ArcGISPolylineBuilder{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometryBuilder{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISGeometryBuilder ArcGISGeometryBuilder::Create(ArcGISGeometryType geometryType, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_GeometryBuilder_createFromGeometryTypeAndSpatialReference(static_cast<RT_GeometryType>(geometryType), localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISGeometryBuilder{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GeometryBuilder_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GeometryBuilderType_envelopeBuilder:
                localLocalResult = ArcGISEnvelopeBuilder{ localResult };
                break;
            case RT_GeometryBuilderType_multipointBuilder:
                localLocalResult = ArcGISMultipointBuilder{ localResult };
                break;
            case RT_GeometryBuilderType_pointBuilder:
                localLocalResult = ArcGISPointBuilder{ localResult };
                break;
            case RT_GeometryBuilderType_polygonBuilder:
                localLocalResult = ArcGISPolygonBuilder{ localResult };
                break;
            case RT_GeometryBuilderType_polylineBuilder:
                localLocalResult = ArcGISPolylineBuilder{ localResult };
                break;
            default:
                localLocalResult = ArcGISGeometryBuilder{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

void ArcGISGeometryBuilder::ReplaceGeometry(const ArcGISGeometry& geometry)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localGeometry = static_cast<const RT_GeometryHandle>(geometry.GetHandle());
    
    RT_GeometryBuilder_replaceGeometry(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), localGeometry, &errorHandler);
}

ArcGISGeometry ArcGISGeometryBuilder::ToGeometry() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_toGeometry(reinterpret_cast<RT_GeometryBuilderHandle>(GetHandle()), &errorHandler);
    
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

ArcGISGeometryBuilder::ArcGISGeometryBuilder(void* handle) :
    m_handle{ handle }
{
}

ArcGISGeometryBuilder::ArcGISGeometryBuilder(ArcGISGeometryBuilder&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISGeometryBuilder::~ArcGISGeometryBuilder()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GeometryBuilder_destroy(reinterpret_cast<RT_GeometryBuilderHandle>(m_handle), &errorHandler);
    }
}

ArcGISGeometryBuilder& ArcGISGeometryBuilder::operator=(ArcGISGeometryBuilder&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISGeometryBuilder::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISGeometryBuilder::GetHandle() const
{
    return m_handle;
}
void ArcGISGeometryBuilder::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri