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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSourceInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSourceType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSource.h"

namespace Esri
{
namespace GameEngine
{
namespace Elevation
{
namespace Base
{
ArcGISElevationSourceType ArcGISElevationSourceInternal::GetObjectType(ArcGISElevationSource* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSource_getObjectType(reinterpret_cast<RT_GEElevationSourceHandle>(self->GetHandle()), &errorHandler);
    
    return static_cast<ArcGISElevationSourceType>(localResult);
}
} // namespace Base
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri