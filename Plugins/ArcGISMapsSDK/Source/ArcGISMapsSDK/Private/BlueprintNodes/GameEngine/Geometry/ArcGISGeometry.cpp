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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometry.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometry.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

bool UArcGISGeometry::GetHasCurves()
{
    auto localResult = APIObject->GetHasCurves();
    
    return localResult;
}

bool UArcGISGeometry::GetHasM()
{
    auto localResult = APIObject->GetHasM();
    
    return localResult;
}

bool UArcGISGeometry::GetHasZ()
{
    auto localResult = APIObject->GetHasZ();
    
    return localResult;
}

bool UArcGISGeometry::GetIsEmpty()
{
    auto localResult = APIObject->GetIsEmpty();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISGeometry::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISGeometry::Equals(UArcGISGeometry* right) const
{
    auto nullRight = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = APIObject->Equals(right ? *right->APIObject : nullRight);
    
    return localResult;
}

bool UArcGISGeometry::EqualsWithTolerance(UArcGISGeometry* right, double tolerance) const
{
    auto nullRight = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = APIObject->Equals(right ? *right->APIObject : nullRight, tolerance);
    
    return localResult;
}

UArcGISGeometry* UArcGISGeometry::FromJSONWithSpatialReference(FString inputJSON, UArcGISSpatialReference* spatialReference)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometry::FromJSON(inputJSON, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}