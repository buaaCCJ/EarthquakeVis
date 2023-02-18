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
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderCommandServer.h"
#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISView.h"
#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISViewInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/View/GEView.h"

namespace Esri
{
namespace GameEngine
{
namespace View
{
RCQ::ArcGISRenderCommandServer ArcGISViewInternal::GetRenderCommandServer(ArcGISView* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEView_getRenderCommandServer(reinterpret_cast<RT_GEViewHandle>(self->GetHandle()), &errorHandler);
    
    auto localLocalResult = RCQ::ArcGISRenderCommandServer{};
    
    if (localResult != nullptr)
    {
        localLocalResult = RCQ::ArcGISRenderCommandServer{ localResult };
    }
    
    return localLocalResult;
}
} // namespace View
} // namespace GameEngine
} // namespace Esri