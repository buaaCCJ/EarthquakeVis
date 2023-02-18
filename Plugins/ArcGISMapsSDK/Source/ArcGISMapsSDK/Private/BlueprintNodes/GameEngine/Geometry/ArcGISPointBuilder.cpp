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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPointBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPointBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISPointBuilder* UArcGISPointBuilder::CreateArcGISPointBuilderFromPoint(UArcGISPoint* point)
{
    auto result = NewObject<UArcGISPointBuilder>();
    
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPointBuilder>(point ? *derivedPointAPIObject : nullPoint);
    
    return result;
}

UArcGISPointBuilder* UArcGISPointBuilder::CreateArcGISPointBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISPointBuilder>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPointBuilder>(spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

double UArcGISPointBuilder::GetM()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetM();
    
    return localResult;
}
void UArcGISPointBuilder::SetM(double m)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    derivedAPIObject->SetM(m);
}

double UArcGISPointBuilder::GetX()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetX();
    
    return localResult;
}
void UArcGISPointBuilder::SetX(double x)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    derivedAPIObject->SetX(x);
}

double UArcGISPointBuilder::GetY()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetY();
    
    return localResult;
}
void UArcGISPointBuilder::SetY(double y)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    derivedAPIObject->SetY(y);
}

double UArcGISPointBuilder::GetZ()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetZ();
    
    return localResult;
}
void UArcGISPointBuilder::SetZ(double z)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    derivedAPIObject->SetZ(z);
}

void UArcGISPointBuilder::OffsetBy(double offsetX, double offsetY)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    derivedAPIObject->OffsetBy(offsetX, offsetY);
}

void UArcGISPointBuilder::SetXY(double x, double y)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPointBuilder>(APIObject);
    
    derivedAPIObject->SetXY(x, y);
}