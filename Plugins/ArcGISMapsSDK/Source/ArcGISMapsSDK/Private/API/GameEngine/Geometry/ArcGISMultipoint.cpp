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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipoint.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Multipoint.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISImmutablePointCollection ArcGISMultipoint::GetPoints() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Multipoint_getPoints(reinterpret_cast<RT_MultipointHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISImmutablePointCollection{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISImmutablePointCollection{ localResult };
    }
    
    return localLocalResult;
}

ArcGISMultipoint::ArcGISMultipoint(void* handle) :
    ArcGISGeometry{ handle }
{
}

ArcGISMultipoint::ArcGISMultipoint(ArcGISMultipoint&& other) noexcept :
    ArcGISGeometry{ std::move(other) }
{
}

ArcGISMultipoint::ArcGISMultipoint() :
    ArcGISGeometry{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri