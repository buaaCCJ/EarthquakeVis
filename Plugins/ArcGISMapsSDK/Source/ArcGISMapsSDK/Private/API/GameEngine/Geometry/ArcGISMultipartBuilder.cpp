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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMultipartBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePartCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/MultipartBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISMutablePartCollection ArcGISMultipartBuilder::GetParts() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MultipartBuilder_getParts(reinterpret_cast<RT_MultipartBuilderHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISMutablePartCollection{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISMutablePartCollection{ localResult };
    }
    
    return localLocalResult;
}
void ArcGISMultipartBuilder::SetParts(const ArcGISMutablePartCollection& parts)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localParts = static_cast<const RT_MutablePartCollectionHandle>(parts.GetHandle());
    
    RT_MultipartBuilder_setParts(reinterpret_cast<RT_MultipartBuilderHandle>(GetHandle()), localParts, &errorHandler);
}

size_t ArcGISMultipartBuilder::AddPoint(double x, double y)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MultipartBuilder_addPointXY(reinterpret_cast<RT_MultipartBuilderHandle>(GetHandle()), x, y, &errorHandler);
    
    return localResult;
}

size_t ArcGISMultipartBuilder::AddPoint(double x, double y, double z)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_MultipartBuilder_addPointXYZ(reinterpret_cast<RT_MultipartBuilderHandle>(GetHandle()), x, y, z, &errorHandler);
    
    return localResult;
}

size_t ArcGISMultipartBuilder::AddPoint(const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_MultipartBuilder_addPoint(reinterpret_cast<RT_MultipartBuilderHandle>(GetHandle()), localPoint, &errorHandler);
    
    return localResult;
}

ArcGISMultipartBuilder::ArcGISMultipartBuilder(void* handle) :
    ArcGISGeometryBuilder{ handle }
{
}

ArcGISMultipartBuilder::ArcGISMultipartBuilder(ArcGISMultipartBuilder&& other) noexcept :
    ArcGISGeometryBuilder{ std::move(other) }
{
}

ArcGISMultipartBuilder::ArcGISMultipartBuilder() :
    ArcGISGeometryBuilder{}
{
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri