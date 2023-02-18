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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometry.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Geometry.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISGeometryType ArcGISGeometryInternal::GetObjectType(ArcGISGeometry* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Geometry_getObjectType(reinterpret_cast<RT_GeometryHandle>(self->GetHandle()), &errorHandler);
    
    return static_cast<ArcGISGeometryType>(localResult);
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri