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
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayerInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayerType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayer.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace Base
{
ArcGISLayerType ArcGISLayerInternal::GetObjectType(ArcGISLayer* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayer_getObjectType(reinterpret_cast<RT_GELayerHandle>(self->GetHandle()), &errorHandler);
    
    return static_cast<ArcGISLayerType>(localResult);
}
} // namespace Base
} // namespace Layers
} // namespace GameEngine
} // namespace Esri