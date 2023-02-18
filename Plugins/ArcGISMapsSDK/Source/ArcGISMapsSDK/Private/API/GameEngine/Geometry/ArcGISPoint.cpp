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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Point.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPoint::ArcGISPoint(double x, double y) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_Point_createWithXY(x, y, &errorHandler));
}

ArcGISPoint::ArcGISPoint(double x, double y, double z) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_Point_createWithXYZ(x, y, z, &errorHandler));
}

ArcGISPoint::ArcGISPoint(double x, double y, double z, const ArcGISSpatialReference& spatialReference) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_Point_createWithXYZSpatialReference(x, y, z, localSpatialReference, &errorHandler));
}

ArcGISPoint::ArcGISPoint(double x, double y, const ArcGISSpatialReference& spatialReference) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_Point_createWithXYSpatialReference(x, y, localSpatialReference, &errorHandler));
}

double ArcGISPoint::GetM() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Point_getM(reinterpret_cast<RT_PointHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISPoint::GetX() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Point_getX(reinterpret_cast<RT_PointHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISPoint::GetY() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Point_getY(reinterpret_cast<RT_PointHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISPoint::GetZ() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Point_getZ(reinterpret_cast<RT_PointHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISPoint ArcGISPoint::CreateWithM(double x, double y, double m)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Point_createWithM(x, y, m, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISPoint::CreateWithM(double x, double y, double z, double m)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Point_createWithZM(x, y, z, m, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISPoint::CreateWithM(double x, double y, double z, double m, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_Point_createWithZMSpatialReference(x, y, z, m, localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISPoint::CreateWithM(double x, double y, double m, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_Point_createWithMSpatialReference(x, y, m, localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint::ArcGISPoint(void* handle) :
    ArcGISGeometry{ handle }
{
}

ArcGISPoint::ArcGISPoint(ArcGISPoint&& other) noexcept :
    ArcGISGeometry{ std::move(other) }
{
}

ArcGISPoint::ArcGISPoint() :
    ArcGISGeometry{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri