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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISPoint* UArcGISPoint::CreateArcGISPointWithXY(double x, double y)
{
    auto result = NewObject<UArcGISPoint>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(x, y);
    
    return result;
}

UArcGISPoint* UArcGISPoint::CreateArcGISPointWithXYZ(double x, double y, double z)
{
    auto result = NewObject<UArcGISPoint>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(x, y, z);
    
    return result;
}

UArcGISPoint* UArcGISPoint::CreateArcGISPointWithXYZSpatialReference(double x, double y, double z, UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISPoint>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(x, y, z, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISPoint* UArcGISPoint::CreateArcGISPointWithXYSpatialReference(double x, double y, UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISPoint>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(x, y, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

double UArcGISPoint::GetM()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(APIObject);
    
    auto localResult = derivedAPIObject->GetM();
    
    return localResult;
}

double UArcGISPoint::GetX()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(APIObject);
    
    auto localResult = derivedAPIObject->GetX();
    
    return localResult;
}

double UArcGISPoint::GetY()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(APIObject);
    
    auto localResult = derivedAPIObject->GetY();
    
    return localResult;
}

double UArcGISPoint::GetZ()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(APIObject);
    
    auto localResult = derivedAPIObject->GetZ();
    
    return localResult;
}

UArcGISPoint* UArcGISPoint::CreateWithM(double x, double y, double m)
{
    auto localResult = Esri::GameEngine::Geometry::ArcGISPoint::CreateWithM(x, y, m);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISPoint::CreateWithZM(double x, double y, double z, double m)
{
    auto localResult = Esri::GameEngine::Geometry::ArcGISPoint::CreateWithM(x, y, z, m);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISPoint::CreateWithZMSpatialReference(double x, double y, double z, double m, UArcGISSpatialReference* spatialReference)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISPoint::CreateWithM(x, y, z, m, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISPoint::CreateWithMSpatialReference(double x, double y, double m, UArcGISSpatialReference* spatialReference)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISPoint::CreateWithM(x, y, m, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}