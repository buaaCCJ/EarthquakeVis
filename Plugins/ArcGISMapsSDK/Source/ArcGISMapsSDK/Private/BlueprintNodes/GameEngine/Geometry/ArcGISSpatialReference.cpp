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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpheroidData.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpheroidData.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISUnit.h"

UArcGISSpatialReference* UArcGISSpatialReference::CreateArcGISSpatialReference(int32 WKID)
{
    auto result = NewObject<UArcGISSpatialReference>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(WKID);
    
    return result;
}

UArcGISSpatialReference* UArcGISSpatialReference::CreateArcGISSpatialReferenceVerticalWKID(int32 WKID, int32 verticalWKID)
{
    auto result = NewObject<UArcGISSpatialReference>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(WKID, verticalWKID);
    
    return result;
}

UArcGISSpatialReference* UArcGISSpatialReference::CreateArcGISSpatialReferenceFromWKText(FString wkText)
{
    auto result = NewObject<UArcGISSpatialReference>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(wkText);
    
    return result;
}

UArcGISSpatialReference* UArcGISSpatialReference::GetBaseGeographic()
{
    auto localResult = APIObject->GetBaseGeographic();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISSpatialReference::GetHasVertical()
{
    auto localResult = APIObject->GetHasVertical();
    
    return localResult;
}

bool UArcGISSpatialReference::GetIsGeographic()
{
    auto localResult = APIObject->GetIsGeographic();
    
    return localResult;
}

bool UArcGISSpatialReference::GetIsPannable()
{
    auto localResult = APIObject->GetIsPannable();
    
    return localResult;
}

bool UArcGISSpatialReference::GetIsProjected()
{
    auto localResult = APIObject->GetIsProjected();
    
    return localResult;
}

FArcGISSpheroidData UArcGISSpatialReference::GetSpheroidData()
{
    auto localResult = APIObject->GetSpheroidData();
    
    static_assert(sizeof(FArcGISSpheroidData) == sizeof(Esri::GameEngine::Geometry::ArcGISSpheroidData), "Type size mismatch");
    
    return reinterpret_cast<FArcGISSpheroidData&>(localResult);
}

UArcGISUnit* UArcGISSpatialReference::GetUnit()
{
    auto localResult = APIObject->GetUnit();
    
    auto localLocalResult = NewObject<UArcGISUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISUnit>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISLinearUnit* UArcGISSpatialReference::GetVerticalUnit()
{
    auto localResult = APIObject->GetVerticalUnit();
    
    auto localLocalResult = NewObject<UArcGISLinearUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLinearUnit>(std::move(localResult));
    
    return localLocalResult;
}

int32 UArcGISSpatialReference::GetVerticalWKID()
{
    auto localResult = APIObject->GetVerticalWKID();
    
    return localResult;
}

int32 UArcGISSpatialReference::GetWKID()
{
    auto localResult = APIObject->GetWKID();
    
    return localResult;
}

FString UArcGISSpatialReference::GetWKText()
{
    auto localResult = APIObject->GetWKText();
    
    return localResult;
}

bool UArcGISSpatialReference::Equals(UArcGISSpatialReference* right) const
{
    auto nullRight = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = APIObject->Equals(right ? *right->APIObject : nullRight);
    
    return localResult;
}

double UArcGISSpatialReference::GetConvergenceAngle(UArcGISPoint* point) const
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = APIObject->GetConvergenceAngle(point ? *derivedPointAPIObject : nullPoint);
    
    return localResult;
}

UArcGISSpatialReference* UArcGISSpatialReference::WebMercator()
{
    auto localResult = Esri::GameEngine::Geometry::ArcGISSpatialReference::WebMercator();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISSpatialReference* UArcGISSpatialReference::WGS84()
{
    auto localResult = Esri::GameEngine::Geometry::ArcGISSpatialReference::WGS84();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}