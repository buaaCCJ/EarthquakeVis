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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/MapView/ArcGISCamera.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/MapView/ArcGISCamera.h" // IWYU pragma: associated

UArcGISCamera* UArcGISCamera::CreateArcGISCameraWithLocationHeadingPitchRoll(UArcGISPoint* locationPoint, double heading, double pitch, double roll)
{
    auto result = NewObject<UArcGISCamera>();
    
    auto nullLocationPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedLocationPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(locationPoint->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::MapView::ArcGISCamera>(locationPoint ? *derivedLocationPointAPIObject : nullLocationPoint, heading, pitch, roll);
    
    return result;
}

double UArcGISCamera::GetHeading()
{
    auto localResult = APIObject->GetHeading();
    
    return localResult;
}

UArcGISPoint* UArcGISCamera::GetLocation()
{
    auto localResult = APIObject->GetLocation();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

double UArcGISCamera::GetPitch()
{
    auto localResult = APIObject->GetPitch();
    
    return localResult;
}

double UArcGISCamera::GetRoll()
{
    auto localResult = APIObject->GetRoll();
    
    return localResult;
}

UArcGISCamera* UArcGISCamera::Elevate(double deltaAltitude) const
{
    auto localResult = APIObject->Elevate(deltaAltitude);
    
    auto localLocalResult = NewObject<UArcGISCamera>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::MapView::ArcGISCamera>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISCamera::Equals(UArcGISCamera* otherCamera) const
{
    auto nullOtherCamera = Esri::GameEngine::MapView::ArcGISCamera{};
    
    auto localResult = APIObject->Equals(otherCamera ? *otherCamera->APIObject : nullOtherCamera);
    
    return localResult;
}

UArcGISCamera* UArcGISCamera::MoveTo(UArcGISPoint* location) const
{
    auto nullLocation = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedLocationAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(location->APIObject);
    
    auto localResult = APIObject->MoveTo(location ? *derivedLocationAPIObject : nullLocation);
    
    auto localLocalResult = NewObject<UArcGISCamera>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::MapView::ArcGISCamera>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISCamera* UArcGISCamera::RotateTo(double heading, double pitch, double roll) const
{
    auto localResult = APIObject->RotateTo(heading, pitch, roll);
    
    auto localLocalResult = NewObject<UArcGISCamera>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::MapView::ArcGISCamera>(std::move(localResult));
    
    return localLocalResult;
}