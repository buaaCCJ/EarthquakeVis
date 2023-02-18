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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelope.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Envelope.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISEnvelope::ArcGISEnvelope(double xMin, double yMin, double xMax, double yMax) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_Envelope_createWithXY(xMin, yMin, xMax, yMax, &errorHandler));
}

ArcGISEnvelope::ArcGISEnvelope(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_Envelope_createWithXYZ(xMin, yMin, xMax, yMax, zMin, zMax, &errorHandler));
}

ArcGISEnvelope::ArcGISEnvelope(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, const ArcGISSpatialReference& spatialReference) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_Envelope_createWithXYZSpatialReference(xMin, yMin, xMax, yMax, zMin, zMax, localSpatialReference, &errorHandler));
}

ArcGISEnvelope::ArcGISEnvelope(double xMin, double yMin, double xMax, double yMax, const ArcGISSpatialReference& spatialReference) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_Envelope_createWithXYSpatialReference(xMin, yMin, xMax, yMax, localSpatialReference, &errorHandler));
}

ArcGISEnvelope::ArcGISEnvelope(const ArcGISPoint& center, double width, double height) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    SetHandle(RT_Envelope_createWithCenterPoint(localCenter, width, height, &errorHandler));
}

ArcGISEnvelope::ArcGISEnvelope(const ArcGISPoint& center, double width, double height, double depth) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localCenter = static_cast<const RT_PointHandle>(center.GetHandle());
    
    SetHandle(RT_Envelope_createWithCenterPointAndDepth(localCenter, width, height, depth, &errorHandler));
}

ArcGISEnvelope::ArcGISEnvelope(const ArcGISPoint& min, const ArcGISPoint& max) :
    ArcGISGeometry{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localMin = static_cast<const RT_PointHandle>(min.GetHandle());
    const auto localMax = static_cast<const RT_PointHandle>(max.GetHandle());
    
    SetHandle(RT_Envelope_createWithPoints(localMin, localMax, &errorHandler));
}

ArcGISPoint ArcGISEnvelope::GetCenter() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getCenter(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISEnvelope::GetDepth() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getDepth(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetHeight() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getHeight(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetMMax() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getMMax(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetMMin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getMMin(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetWidth() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getWidth(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetXMax() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getXMax(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetXMin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getXMin(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetYMax() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getYMax(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetYMin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getYMin(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetZMax() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getZMax(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISEnvelope::GetZMin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_getZMin(reinterpret_cast<RT_EnvelopeHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISEnvelope ArcGISEnvelope::CreateWithM(double xMin, double yMin, double xMax, double yMax, double mMin, double mMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_createWithM(xMin, yMin, xMax, yMax, mMin, mMax, &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

ArcGISEnvelope ArcGISEnvelope::CreateWithM(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, double mMin, double mMax)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Envelope_createWithZM(xMin, yMin, xMax, yMax, zMin, zMax, mMin, mMax, &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

ArcGISEnvelope ArcGISEnvelope::CreateWithM(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, double mMin, double mMax, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_Envelope_createWithZMSpatialReference(xMin, yMin, xMax, yMax, zMin, zMax, mMin, mMax, localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

ArcGISEnvelope ArcGISEnvelope::CreateWithM(double xMin, double yMin, double xMax, double yMax, double mMin, double mMax, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_Envelope_createWithMSpatialReference(xMin, yMin, xMax, yMax, mMin, mMax, localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

ArcGISEnvelope::ArcGISEnvelope(void* handle) :
    ArcGISGeometry{ handle }
{
}

ArcGISEnvelope::ArcGISEnvelope(ArcGISEnvelope&& other) noexcept :
    ArcGISGeometry{ std::move(other) }
{
}

ArcGISEnvelope::ArcGISEnvelope() :
    ArcGISGeometry{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri