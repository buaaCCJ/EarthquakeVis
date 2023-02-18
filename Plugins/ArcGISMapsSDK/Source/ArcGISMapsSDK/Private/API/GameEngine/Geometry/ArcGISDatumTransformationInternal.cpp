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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDatumTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDatumTransformationInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDatumTransformationType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/DatumTransformation.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISDatumTransformationType ArcGISDatumTransformationInternal::GetObjectType(ArcGISDatumTransformation* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DatumTransformation_getObjectType(reinterpret_cast<RT_DatumTransformationHandle>(self->GetHandle()), &errorHandler);
    
    return static_cast<ArcGISDatumTransformationType>(localResult);
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri