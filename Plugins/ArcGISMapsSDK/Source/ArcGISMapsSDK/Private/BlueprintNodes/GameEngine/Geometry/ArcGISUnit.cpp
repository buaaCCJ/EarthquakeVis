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
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISUnit.h" // IWYU pragma: associated

FString UArcGISUnit::GetAbbreviation()
{
    auto localResult = APIObject->GetAbbreviation();
    
    return localResult;
}

FString UArcGISUnit::GetDisplayName()
{
    auto localResult = APIObject->GetDisplayName();
    
    return localResult;
}

FString UArcGISUnit::GetName()
{
    auto localResult = APIObject->GetName();
    
    return localResult;
}

FString UArcGISUnit::GetPluralDisplayName()
{
    auto localResult = APIObject->GetPluralDisplayName();
    
    return localResult;
}

int32 UArcGISUnit::GetUnitId()
{
    auto localResult = APIObject->GetUnitId();
    
    return localResult;
}

int32 UArcGISUnit::GetWKID()
{
    auto localResult = APIObject->GetWKID();
    
    return localResult;
}

UArcGISUnit* UArcGISUnit::FromUnitId(int32 unitId)
{
    auto localResult = Esri::GameEngine::Geometry::ArcGISUnit::FromUnitId(unitId);
    
    auto localLocalResult = NewObject<UArcGISUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISUnit>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISUnit* UArcGISUnit::FromWKID(int32 WKID)
{
    auto localResult = Esri::GameEngine::Geometry::ArcGISUnit::FromWKID(WKID);
    
    auto localLocalResult = NewObject<UArcGISUnit>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISUnit>(std::move(localResult));
    
    return localLocalResult;
}