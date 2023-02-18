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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUnitInternal.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUnitType.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/Unit.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISUnitType ArcGISUnitInternal::GetObjectType(ArcGISUnit* self)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_Unit_getObjectType(reinterpret_cast<RT_UnitHandle>(self->GetHandle()), &errorHandler);
    
    return static_cast<ArcGISUnitType>(localResult);
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri