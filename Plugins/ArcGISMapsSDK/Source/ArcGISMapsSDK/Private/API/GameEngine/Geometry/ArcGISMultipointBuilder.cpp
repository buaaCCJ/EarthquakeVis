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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipointBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MultipointBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISMultipointBuilder::ArcGISMultipointBuilder(const ArcGISMultipoint& multipoint) :
    ArcGISGeometryBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localMultipoint = static_cast<const RT_MultipointHandle>(multipoint.GetHandle());
    
    SetHandle(RT_MultipointBuilder_createFromMultipoint(localMultipoint, &errorHandler));
}

ArcGISMultipointBuilder::ArcGISMultipointBuilder(const ArcGISSpatialReference& spatialReference) :
    ArcGISGeometryBuilder{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    SetHandle(RT_MultipointBuilder_createFromSpatialReference(localSpatialReference, &errorHandler));
}

ArcGISMutablePointCollection ArcGISMultipointBuilder::GetPoints() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MultipointBuilder_getPoints(reinterpret_cast<RT_MultipointBuilderHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISMutablePointCollection{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISMutablePointCollection{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISMultipointBuilder::SetPoints(const ArcGISMutablePointCollection& points)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoints = static_cast<const RT_MutablePointCollectionHandle>(points.GetHandle());
    
    RT_MultipointBuilder_setPoints(reinterpret_cast<RT_MultipointBuilderHandle>(GetHandle()), localPoints, &errorHandler);
}

ArcGISMultipointBuilder::ArcGISMultipointBuilder(void* handle) :
    ArcGISGeometryBuilder{ handle }
{
}

ArcGISMultipointBuilder::ArcGISMultipointBuilder(ArcGISMultipointBuilder&& other) noexcept :
    ArcGISGeometryBuilder{ std::move(other) }
{
}

ArcGISMultipointBuilder::ArcGISMultipointBuilder() :
    ArcGISGeometryBuilder{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri