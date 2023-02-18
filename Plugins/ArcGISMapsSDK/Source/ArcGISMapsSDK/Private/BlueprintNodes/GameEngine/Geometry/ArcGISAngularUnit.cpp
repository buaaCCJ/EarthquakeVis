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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAngularUnitId.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAngularUnit.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAngularUnitId.h"

UArcGISAngularUnit* UArcGISAngularUnit::CreateArcGISAngularUnit(EArcGISAngularUnitId::Type unitId)
{
    auto result = NewObject<UArcGISAngularUnit>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISAngularUnit>(static_cast<Esri::GameEngine::Geometry::ArcGISAngularUnitId>(unitId));
    
    return result;
}

EArcGISAngularUnitId::Type UArcGISAngularUnit::GetAngularUnitId()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(APIObject);
    
    auto localResult = derivedAPIObject->GetAngularUnitId();
    
    return static_cast<EArcGISAngularUnitId::Type>(localResult);
}

double UArcGISAngularUnit::ConvertFrom(UArcGISAngularUnit* fromUnit, double angle) const
{
    auto nullFromUnit = Esri::GameEngine::Geometry::ArcGISAngularUnit{};
    auto derivedFromUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(fromUnit->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ConvertFrom(fromUnit ? *derivedFromUnitAPIObject : nullFromUnit, angle);
    
    return localResult;
}

double UArcGISAngularUnit::ConvertTo(UArcGISAngularUnit* toUnit, double angle) const
{
    auto nullToUnit = Esri::GameEngine::Geometry::ArcGISAngularUnit{};
    auto derivedToUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(toUnit->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ConvertTo(toUnit ? *derivedToUnitAPIObject : nullToUnit, angle);
    
    return localResult;
}

double UArcGISAngularUnit::FromRadians(double radians) const
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(APIObject);
    
    auto localResult = derivedAPIObject->FromRadians(radians);
    
    return localResult;
}

double UArcGISAngularUnit::ToRadians(double angle) const
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAngularUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ToRadians(angle);
    
    return localResult;
}