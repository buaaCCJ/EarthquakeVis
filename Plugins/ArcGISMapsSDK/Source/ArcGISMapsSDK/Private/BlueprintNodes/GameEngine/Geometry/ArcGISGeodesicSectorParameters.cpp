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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeodesicSectorParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAngularUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeodesicSectorParameters.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"

UArcGISGeodesicSectorParameters* UArcGISGeodesicSectorParameters::CreateArcGISGeodesicSectorParameters()
{
    auto result = NewObject<UArcGISGeodesicSectorParameters>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters>();
    
    return result;
}

UArcGISGeodesicSectorParameters* UArcGISGeodesicSectorParameters::CreateArcGISGeodesicSectorParametersWith(double axisDirection, UArcGISAngularUnit* angularUnit, UArcGISPoint* center, UArcGISLinearUnit* linearUnit, int32 maxPointCount, double maxSegmentLength, EArcGISGeometryType::Type geometryType, double sectorAngle, double semiAxis1Length, double semiAxis2Length, double startDirection)
{
    auto result = NewObject<UArcGISGeodesicSectorParameters>();
    
    auto nullAngularUnit = Esri::GameEngine::Geometry::ArcGISAngularUnit{};
    auto derivedAngularUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(angularUnit->APIObject);
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    auto nullLinearUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedLinearUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(linearUnit->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters>(axisDirection, angularUnit ? *derivedAngularUnitAPIObject : nullAngularUnit, center ? *derivedCenterAPIObject : nullCenter, linearUnit ? *derivedLinearUnitAPIObject : nullLinearUnit, maxPointCount, maxSegmentLength, static_cast<Esri::GameEngine::Geometry::ArcGISGeometryType>(geometryType), sectorAngle, semiAxis1Length, semiAxis2Length, startDirection);
    
    return result;
}

UArcGISGeodesicSectorParameters* UArcGISGeodesicSectorParameters::CreateArcGISGeodesicSectorParametersWithCenterAndAxisLengthsAndSectorAngleAndStartDirection(UArcGISPoint* center, double semiAxis1Length, double semiAxis2Length, double sectorAngle, double startDirection)
{
    auto result = NewObject<UArcGISGeodesicSectorParameters>();
    
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters>(center ? *derivedCenterAPIObject : nullCenter, semiAxis1Length, semiAxis2Length, sectorAngle, startDirection);
    
    return result;
}

UArcGISAngularUnit* UArcGISGeodesicSectorParameters::GetAngularUnit()
{
    auto localResult = APIObject->GetAngularUnit();
    
    auto localLocalResult = NewObject<UArcGISAngularUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISAngularUnit>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISGeodesicSectorParameters::SetAngularUnit(UArcGISAngularUnit* angularUnit)
{
    auto nullAngularUnit = Esri::GameEngine::Geometry::ArcGISAngularUnit{};
    auto derivedAngularUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(angularUnit->APIObject);
    
    APIObject->SetAngularUnit(angularUnit ? *derivedAngularUnitAPIObject : nullAngularUnit);
}

double UArcGISGeodesicSectorParameters::GetAxisDirection()
{
    auto localResult = APIObject->GetAxisDirection();
    
    return localResult;
}
void UArcGISGeodesicSectorParameters::SetAxisDirection(double axisDirection)
{
    APIObject->SetAxisDirection(axisDirection);
}

UArcGISPoint* UArcGISGeodesicSectorParameters::GetCenter()
{
    auto localResult = APIObject->GetCenter();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISGeodesicSectorParameters::SetCenter(UArcGISPoint* center)
{
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    
    APIObject->SetCenter(center ? *derivedCenterAPIObject : nullCenter);
}

EArcGISGeometryType::Type UArcGISGeodesicSectorParameters::GetGeometryType()
{
    auto localResult = APIObject->GetGeometryType();
    
    return static_cast<EArcGISGeometryType::Type>(localResult);
}
void UArcGISGeodesicSectorParameters::SetGeometryType(EArcGISGeometryType::Type geometryType)
{
    APIObject->SetGeometryType(static_cast<Esri::GameEngine::Geometry::ArcGISGeometryType>(geometryType));
}

UArcGISLinearUnit* UArcGISGeodesicSectorParameters::GetLinearUnit()
{
    auto localResult = APIObject->GetLinearUnit();
    
    auto localLocalResult = NewObject<UArcGISLinearUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLinearUnit>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISGeodesicSectorParameters::SetLinearUnit(UArcGISLinearUnit* linearUnit)
{
    auto nullLinearUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedLinearUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(linearUnit->APIObject);
    
    APIObject->SetLinearUnit(linearUnit ? *derivedLinearUnitAPIObject : nullLinearUnit);
}

double UArcGISGeodesicSectorParameters::GetMaxSegmentLength()
{
    auto localResult = APIObject->GetMaxSegmentLength();
    
    return localResult;
}
void UArcGISGeodesicSectorParameters::SetMaxSegmentLength(double maxSegmentLength)
{
    APIObject->SetMaxSegmentLength(maxSegmentLength);
}

double UArcGISGeodesicSectorParameters::GetSectorAngle()
{
    auto localResult = APIObject->GetSectorAngle();
    
    return localResult;
}
void UArcGISGeodesicSectorParameters::SetSectorAngle(double sectorAngle)
{
    APIObject->SetSectorAngle(sectorAngle);
}

double UArcGISGeodesicSectorParameters::GetSemiAxis1Length()
{
    auto localResult = APIObject->GetSemiAxis1Length();
    
    return localResult;
}
void UArcGISGeodesicSectorParameters::SetSemiAxis1Length(double semiAxis1Length)
{
    APIObject->SetSemiAxis1Length(semiAxis1Length);
}

double UArcGISGeodesicSectorParameters::GetSemiAxis2Length()
{
    auto localResult = APIObject->GetSemiAxis2Length();
    
    return localResult;
}
void UArcGISGeodesicSectorParameters::SetSemiAxis2Length(double semiAxis2Length)
{
    APIObject->SetSemiAxis2Length(semiAxis2Length);
}

double UArcGISGeodesicSectorParameters::GetStartDirection()
{
    auto localResult = APIObject->GetStartDirection();
    
    return localResult;
}
void UArcGISGeodesicSectorParameters::SetStartDirection(double startDirection)
{
    APIObject->SetStartDirection(startDirection);
}