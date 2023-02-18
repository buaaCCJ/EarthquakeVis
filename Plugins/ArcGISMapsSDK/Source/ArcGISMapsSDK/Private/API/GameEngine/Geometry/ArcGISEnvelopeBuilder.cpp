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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelopeBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/EnvelopeBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISEnvelopeBuilder::ArcGISEnvelopeBuilder(const ArcGISEnvelope& envelope) :
    ArcGISGeometryBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localEnvelope = static_cast<const RT_EnvelopeHandle>(envelope.GetHandle());
    
    SetHandle(RT_EnvelopeBuilder_createFromEnvelope(localEnvelope, &errorHandler));
}

ArcGISEnvelopeBuilder::ArcGISEnvelopeBuilder(const ArcGISPoint& center, double width, double height) :
    ArcGISGeometryBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    SetHandle(RT_EnvelopeBuilder_createFromCenterPoint(localCenter, width, height, &errorHandler));
}

ArcGISEnvelopeBuilder::ArcGISEnvelopeBuilder(const ArcGISPoint& center, double width, double height, double depth) :
    ArcGISGeometryBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    SetHandle(RT_EnvelopeBuilder_createFromCenterPointAndDepth(localCenter, width, height, depth, &errorHandler));
}

ArcGISEnvelopeBuilder::ArcGISEnvelopeBuilder(const ArcGISSpatialReference& spatialReference) :
    ArcGISGeometryBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_EnvelopeBuilder_createFromSpatialReference(localSpatialReference, &errorHandler));
}

ArcGISPoint ArcGISEnvelopeBuilder::GetCenter() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getCenter(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISEnvelopeBuilder::GetDepth() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getDepth(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelopeBuilder::GetHeight() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getHeight(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelopeBuilder::GetMMax() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getMMax(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISEnvelopeBuilder::SetMMax(double mMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setMMax(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), mMax, &errorHandler);
}

double ArcGISEnvelopeBuilder::GetMMin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getMMin(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISEnvelopeBuilder::SetMMin(double mMin)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setMMin(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), mMin, &errorHandler);
}

double ArcGISEnvelopeBuilder::GetWidth() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getWidth(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelopeBuilder::GetXMax() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getXMax(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISEnvelopeBuilder::SetXMax(double xMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setXMax(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), xMax, &errorHandler);
}

double ArcGISEnvelopeBuilder::GetXMin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getXMin(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISEnvelopeBuilder::SetXMin(double xMin)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setXMin(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), xMin, &errorHandler);
}

double ArcGISEnvelopeBuilder::GetYMax() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getYMax(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISEnvelopeBuilder::SetYMax(double yMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setYMax(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), yMax, &errorHandler);
}

double ArcGISEnvelopeBuilder::GetYMin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getYMin(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISEnvelopeBuilder::SetYMin(double yMin)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setYMin(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), yMin, &errorHandler);
}

double ArcGISEnvelopeBuilder::GetZMax() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getZMax(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISEnvelopeBuilder::SetZMax(double zMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setZMax(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), zMax, &errorHandler);
}

double ArcGISEnvelopeBuilder::GetZMin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_EnvelopeBuilder_getZMin(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}
void ArcGISEnvelopeBuilder::SetZMin(double zMin)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setZMin(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), zMin, &errorHandler);
}

void ArcGISEnvelopeBuilder::CenterAt(const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    RT_EnvelopeBuilder_centerAt(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), localPoint, &errorHandler);
}

void ArcGISEnvelopeBuilder::ChangeAspectRatio(double width, double height)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_changeAspectRatio(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), width, height, &errorHandler);
}

void ArcGISEnvelopeBuilder::Expand(double factor)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_expand(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), factor, &errorHandler);
}

void ArcGISEnvelopeBuilder::Expand(const ArcGISPoint& anchor, double factor)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localAnchor = static_cast<const RT_PointHandle>(anchor.GetHandle());
    
    RT_EnvelopeBuilder_expandAtAnchor(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), localAnchor, factor, &errorHandler);
}

void ArcGISEnvelopeBuilder::OffsetBy(double offsetX, double offsetY)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_offsetBy(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), offsetX, offsetY, &errorHandler);
}

void ArcGISEnvelopeBuilder::SetM(double mMin, double mMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setM(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), mMin, mMax, &errorHandler);
}

void ArcGISEnvelopeBuilder::SetXY(double xMin, double yMin, double xMax, double yMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setXY(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), xMin, yMin, xMax, yMax, &errorHandler);
}

void ArcGISEnvelopeBuilder::SetZ(double zMin, double zMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_EnvelopeBuilder_setZ(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), zMin, zMax, &errorHandler);
}

void ArcGISEnvelopeBuilder::Union(const ArcGISEnvelope& envelope)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localEnvelope = static_cast<const RT_EnvelopeHandle>(envelope.GetHandle());
    
    RT_EnvelopeBuilder_unionWithEnvelope(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), localEnvelope, &errorHandler);
}

void ArcGISEnvelopeBuilder::Union(const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    RT_EnvelopeBuilder_unionWithPoint(reinterpret_cast<RT_EnvelopeBuilderHandle>(GetHandle()), localPoint, &errorHandler);
}

ArcGISEnvelopeBuilder::ArcGISEnvelopeBuilder(void* handle) :
    ArcGISGeometryBuilder{ handle }
{
}

ArcGISEnvelopeBuilder::ArcGISEnvelopeBuilder(ArcGISEnvelopeBuilder&& other) noexcept :
    ArcGISGeometryBuilder{ std::move(other) }
{
}

ArcGISEnvelopeBuilder::ArcGISEnvelopeBuilder() :
    ArcGISGeometryBuilder{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri