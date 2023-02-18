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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAreaUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnitId.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAreaUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnit.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnitId.h"

UArcGISLinearUnit* UArcGISLinearUnit::CreateArcGISLinearUnitFromAreaUnit(UArcGISAreaUnit* areaUnit)
{
    auto result = NewObject<UArcGISLinearUnit>();
    
    auto nullAreaUnit = Esri::GameEngine::Geometry::ArcGISAreaUnit{};
    auto derivedAreaUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(areaUnit->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLinearUnit>(areaUnit ? *derivedAreaUnitAPIObject : nullAreaUnit);
    
    return result;
}

UArcGISLinearUnit* UArcGISLinearUnit::CreateArcGISLinearUnit(EArcGISLinearUnitId::Type unitId)
{
    auto result = NewObject<UArcGISLinearUnit>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISLinearUnit>(static_cast<Esri::GameEngine::Geometry::ArcGISLinearUnitId>(unitId));
    
    return result;
}

EArcGISLinearUnitId::Type UArcGISLinearUnit::GetLinearUnitId()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(APIObject);
    
    auto localResult = derivedAPIObject->GetLinearUnitId();
    
    return static_cast<EArcGISLinearUnitId::Type>(localResult);
}

double UArcGISLinearUnit::ConvertFrom(UArcGISLinearUnit* fromUnit, double value) const
{
    auto nullFromUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedFromUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(fromUnit->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ConvertFrom(fromUnit ? *derivedFromUnitAPIObject : nullFromUnit, value);
    
    return localResult;
}

double UArcGISLinearUnit::ConvertTo(UArcGISLinearUnit* toUnit, double value) const
{
    auto nullToUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedToUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(toUnit->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ConvertTo(toUnit ? *derivedToUnitAPIObject : nullToUnit, value);
    
    return localResult;
}

double UArcGISLinearUnit::FromMeters(double value) const
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(APIObject);
    
    auto localResult = derivedAPIObject->FromMeters(value);
    
    return localResult;
}

double UArcGISLinearUnit::ToMeters(double value) const
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ToMeters(value);
    
    return localResult;
}