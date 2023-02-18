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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryBuilderInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryBuilderType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/GeometryBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISGeometryBuilderType ArcGISGeometryBuilderInternal::GetObjectType(ArcGISGeometryBuilder* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GeometryBuilder_getObjectType(reinterpret_cast<RT_GeometryBuilderHandle>(self->GetHandle()), &errorHandler);
    
    return static_cast<ArcGISGeometryBuilderType>(localResult);
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri