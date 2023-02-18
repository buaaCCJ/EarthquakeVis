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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPointBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/PointBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPointBuilder::ArcGISPointBuilder(const ArcGISPoint& point) :
    ArcGISGeometryBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    SetHandle(RT_PointBuilder_createFromPoint(localPoint, &errorHandler));
}

ArcGISPointBuilder::ArcGISPointBuilder(const ArcGISSpatialReference& spatialReference) :
    ArcGISGeometryBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_PointBuilder_createFromSpatialReference(localSpatialReference, &errorHandler));
}

double ArcGISPointBuilder::GetM() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_PointBuilder_getM(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISPointBuilder::SetM(double m)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_PointBuilder_setM(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), m, &errorHandler);
}

double ArcGISPointBuilder::GetX() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_PointBuilder_getX(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISPointBuilder::SetX(double x)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_PointBuilder_setX(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), x, &errorHandler);
}

double ArcGISPointBuilder::GetY() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_PointBuilder_getY(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISPointBuilder::SetY(double y)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_PointBuilder_setY(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), y, &errorHandler);
}

double ArcGISPointBuilder::GetZ() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_PointBuilder_getZ(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISPointBuilder::SetZ(double z)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_PointBuilder_setZ(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), z, &errorHandler);
}

void ArcGISPointBuilder::OffsetBy(double offsetX, double offsetY)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_PointBuilder_offsetBy(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), offsetX, offsetY, &errorHandler);
}

void ArcGISPointBuilder::SetXY(double x, double y)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_PointBuilder_setXY(reinterpret_cast<RT_PointBuilderHandle>(GetHandle()), x, y, &errorHandler);
}

ArcGISPointBuilder::ArcGISPointBuilder(void* handle) :
    ArcGISGeometryBuilder{ handle }
{
}

ArcGISPointBuilder::ArcGISPointBuilder(ArcGISPointBuilder&& other) noexcept :
    ArcGISGeometryBuilder{ std::move(other) }
{
}

ArcGISPointBuilder::ArcGISPointBuilder() :
    ArcGISGeometryBuilder{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri