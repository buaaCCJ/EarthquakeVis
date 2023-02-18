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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISAreaUnitId.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLinearUnit.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAreaUnit.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISAreaUnitId.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLinearUnit.h"

UArcGISAreaUnit* UArcGISAreaUnit::CreateArcGISAreaUnit(EArcGISAreaUnitId::Type unitId)
{
    auto result = NewObject<UArcGISAreaUnit>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISAreaUnit>(static_cast<Esri::GameEngine::Geometry::ArcGISAreaUnitId>(unitId));
    
    return result;
}

UArcGISAreaUnit* UArcGISAreaUnit::CreateArcGISAreaUnitFromLinearUnit(UArcGISLinearUnit* linearUnit)
{
    auto result = NewObject<UArcGISAreaUnit>();
    
    auto nullLinearUnit = Esri::GameEngine::Geometry::ArcGISLinearUnit{};
    auto derivedLinearUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISLinearUnit>(linearUnit->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISAreaUnit>(linearUnit ? *derivedLinearUnitAPIObject : nullLinearUnit);
    
    return result;
}

EArcGISAreaUnitId::Type UArcGISAreaUnit::GetAreaUnitId()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(APIObject);
    
    auto localResult = derivedAPIObject->GetAreaUnitId();
    
    return static_cast<EArcGISAreaUnitId::Type>(localResult);
}

double UArcGISAreaUnit::ConvertFrom(UArcGISAreaUnit* fromUnit, double area) const
{
    auto nullFromUnit = Esri::GameEngine::Geometry::ArcGISAreaUnit{};
    auto derivedFromUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(fromUnit->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ConvertFrom(fromUnit ? *derivedFromUnitAPIObject : nullFromUnit, area);
    
    return localResult;
}

double UArcGISAreaUnit::ConvertTo(UArcGISAreaUnit* toUnit, double area) const
{
    auto nullToUnit = Esri::GameEngine::Geometry::ArcGISAreaUnit{};
    auto derivedToUnitAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(toUnit->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ConvertTo(toUnit ? *derivedToUnitAPIObject : nullToUnit, area);
    
    return localResult;
}

double UArcGISAreaUnit::FromSquareMeters(double area) const
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(APIObject);
    
    auto localResult = derivedAPIObject->FromSquareMeters(area);
    
    return localResult;
}

double UArcGISAreaUnit::ToSquareMeters(double area) const
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISAreaUnit>(APIObject);
    
    auto localResult = derivedAPIObject->ToSquareMeters(area);
    
    return localResult;
}