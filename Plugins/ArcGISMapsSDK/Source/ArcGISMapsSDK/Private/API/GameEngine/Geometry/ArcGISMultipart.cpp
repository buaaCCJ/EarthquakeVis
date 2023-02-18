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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePartCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipart.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Multipart.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISImmutablePartCollection ArcGISMultipart::GetParts() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Multipart_getParts(reinterpret_cast<RT_MultipartHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISImmutablePartCollection{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISImmutablePartCollection{ localResult };
    }
    
    return localLocalResult;
}

ArcGISMultipart::ArcGISMultipart(void* handle) :
    ArcGISGeometry{ handle }
{
}

ArcGISMultipart::ArcGISMultipart(ArcGISMultipart&& other) noexcept :
    ArcGISGeometry{ std::move(other) }
{
}

ArcGISMultipart::ArcGISMultipart() :
    ArcGISGeometry{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri