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
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGIS3DObjectSceneLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISImageLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISIntegratedMeshLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnknownLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnsupportedLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISVectorTileLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMap.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMapInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayer.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Map/GEMap.h"

namespace Esri
{
namespace GameEngine
{
namespace Map
{
Layers::Base::ArcGISLayer ArcGISMapInternal::FindLayerById(ArcGISMap* self, uint32_t layerId)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEMap_findLayerById(reinterpret_cast<RT_GEMapHandle>(self->GetHandle()), layerId, &errorHandler);
    
    auto localLocalResult = Layers::Base::ArcGISLayer{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GELayer_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GELayerType_GE3DObjectSceneLayer:
                localLocalResult = Layers::ArcGIS3DObjectSceneLayer{ localResult };
                break;
            case RT_GELayerType_GEImageLayer:
                localLocalResult = Layers::ArcGISImageLayer{ localResult };
                break;
            case RT_GELayerType_GEIntegratedMeshLayer:
                localLocalResult = Layers::ArcGISIntegratedMeshLayer{ localResult };
                break;
            case RT_GELayerType_GEUnknownLayer:
                localLocalResult = Layers::ArcGISUnknownLayer{ localResult };
                break;
            case RT_GELayerType_GEUnsupportedLayer:
                localLocalResult = Layers::ArcGISUnsupportedLayer{ localResult };
                break;
            case RT_GELayerType_GEVectorTileLayer:
                localLocalResult = Layers::ArcGISVectorTileLayer{ localResult };
                break;
            default:
                localLocalResult = Layers::Base::ArcGISLayer{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}
} // namespace Map
} // namespace GameEngine
} // namespace Esri