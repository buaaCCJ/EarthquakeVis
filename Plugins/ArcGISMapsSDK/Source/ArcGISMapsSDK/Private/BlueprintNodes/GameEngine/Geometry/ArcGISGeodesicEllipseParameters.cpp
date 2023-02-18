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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAngularUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodesicEllipseParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAngularUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeodesicEllipseParameters.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"

UArcGISGeodesicEllipseParameters* UArcGISGeodesicEllipseParameters::CreateArcGISGeodesicEllipseParameters()
{
    auto result = NewObject<UArcGISGeodesicEllipseParameters>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters>();
    
    return result;
}

UArcGISGeodesicEllipseParameters* UArcGISGeodesicEllipseParameters::CreateArcGISGeodesicEllipseParametersWith(double axisDirection, UArcGISAngularUnit* angularUnit, UArcGISPoint* center, UArcGISLinearUnit* linearUnit, int32 maxPointCount, double maxSegmentLength, EArcGISGeometryType::Type geometryType, double semiAxis1Length, double semiAxis2Length)
{
    auto result = NewObject<UArcGISGeodesicEllipseParameters>();
    
    auto nullAngularUnit = Esri::GameEngine::Geometry::ArcGISAngularUnit{};
    auto derivedAngularUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(angularUnit->APIObject);
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    auto nullLinearUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedLinearUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(linearUnit->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters>(axisDirection, angularUnit ? *derivedAngularUnitAPIObject : nullAngularUnit, center ? *derivedCenterAPIObject : nullCenter, linearUnit ? *derivedLinearUnitAPIObject : nullLinearUnit, maxPointCount, maxSegmentLength, static_cast<Esri::GameEngine::Geometry::ArcGISGeometryType>(geometryType), semiAxis1Length, semiAxis2Length);
    
    return result;
}

UArcGISGeodesicEllipseParameters* UArcGISGeodesicEllipseParameters::CreateArcGISGeodesicEllipseParametersWithCenterAndAxisLengths(UArcGISPoint* center, double semiAxis1Length, double semiAxis2Length)
{
    auto result = NewObject<UArcGISGeodesicEllipseParameters>();
    
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters>(center ? *derivedCenterAPIObject : nullCenter, semiAxis1Length, semiAxis2Length);
    
    return result;
}

UArcGISAngularUnit* UArcGISGeodesicEllipseParameters::GetAngularUnit()
{
    auto localResult = APIObject->GetAngularUnit();
    
    auto localLocalResult = NewObject<UArcGISAngularUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISAngularUnit>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISGeodesicEllipseParameters::SetAngularUnit(UArcGISAngularUnit* angularUnit)
{
    auto nullAngularUnit = Esri::GameEngine::Geometry::ArcGISAngularUnit{};
    auto derivedAngularUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(angularUnit->APIObject);
    
    APIObject->SetAngularUnit(angularUnit ? *derivedAngularUnitAPIObject : nullAngularUnit);
}

double UArcGISGeodesicEllipseParameters::GetAxisDirection()
{
    auto localResult = APIObject->GetAxisDirection();
    
    return localResult;
}
void UArcGISGeodesicEllipseParameters::SetAxisDirection(double axisDirection)
{
    APIObject->SetAxisDirection(axisDirection);
}

UArcGISPoint* UArcGISGeodesicEllipseParameters::GetCenter()
{
    auto localResult = APIObject->GetCenter();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISGeodesicEllipseParameters::SetCenter(UArcGISPoint* center)
{
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    
    APIObject->SetCenter(center ? *derivedCenterAPIObject : nullCenter);
}

EArcGISGeometryType::Type UArcGISGeodesicEllipseParameters::GetGeometryType()
{
    auto localResult = APIObject->GetGeometryType();
    
    return static_cast<EArcGISGeometryType::Type>(localResult);
}
void UArcGISGeodesicEllipseParameters::SetGeometryType(EArcGISGeometryType::Type geometryType)
{
    APIObject->SetGeometryType(static_cast<Esri::GameEngine::Geometry::ArcGISGeometryType>(geometryType));
}

UArcGISLinearUnit* UArcGISGeodesicEllipseParameters::GetLinearUnit()
{
    auto localResult = APIObject->GetLinearUnit();
    
    auto localLocalResult = NewObject<UArcGISLinearUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLinearUnit>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISGeodesicEllipseParameters::SetLinearUnit(UArcGISLinearUnit* linearUnit)
{
    auto nullLinearUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedLinearUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(linearUnit->APIObject);
    
    APIObject->SetLinearUnit(linearUnit ? *derivedLinearUnitAPIObject : nullLinearUnit);
}

double UArcGISGeodesicEllipseParameters::GetMaxSegmentLength()
{
    auto localResult = APIObject->GetMaxSegmentLength();
    
    return localResult;
}
void UArcGISGeodesicEllipseParameters::SetMaxSegmentLength(double maxSegmentLength)
{
    APIObject->SetMaxSegmentLength(maxSegmentLength);
}

double UArcGISGeodesicEllipseParameters::GetSemiAxis1Length()
{
    auto localResult = APIObject->GetSemiAxis1Length();
    
    return localResult;
}
void UArcGISGeodesicEllipseParameters::SetSemiAxis1Length(double semiAxis1Length)
{
    APIObject->SetSemiAxis1Length(semiAxis1Length);
}

double UArcGISGeodesicEllipseParameters::GetSemiAxis2Length()
{
    auto localResult = APIObject->GetSemiAxis2Length();
    
    return localResult;
}
void UArcGISGeodesicEllipseParameters::SetSemiAxis2Length(double semiAxis2Length)
{
    APIObject->SetSemiAxis2Length(semiAxis2Length);
}