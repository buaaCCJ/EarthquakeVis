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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometry.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

bool UArcGISGeometryBuilder::GetHasCurves()
{
    auto localResult = APIObject->GetHasCurves();
    
    return localResult;
}

bool UArcGISGeometryBuilder::GetHasM()
{
    auto localResult = APIObject->GetHasM();
    
    return localResult;
}

bool UArcGISGeometryBuilder::GetHasZ()
{
    auto localResult = APIObject->GetHasZ();
    
    return localResult;
}

bool UArcGISGeometryBuilder::GetIsEmpty()
{
    auto localResult = APIObject->GetIsEmpty();
    
    return localResult;
}

bool UArcGISGeometryBuilder::GetIsSketchValid()
{
    auto localResult = APIObject->GetIsSketchValid();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISGeometryBuilder::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometryBuilder* UArcGISGeometryBuilder::CreateFromGeometry(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryBuilder::Create(geometry ? *geometry->APIObject : nullGeometry);
    
    auto localLocalResult = NewObject<UArcGISGeometryBuilder>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometryBuilder>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISGeometryBuilder* UArcGISGeometryBuilder::CreateFromGeometryTypeAndSpatialReference(EArcGISGeometryType::Type geometryType, UArcGISSpatialReference* spatialReference)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISGeometryBuilder::Create(static_cast<Esri::GameEngine::Geometry::ArcGISGeometryType>(geometryType), spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISGeometryBuilder>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometryBuilder>(std::move(localResult));
    
    return localLocalResult;
}

void UArcGISGeometryBuilder::ReplaceGeometry(UArcGISGeometry* geometry)
{
    auto nullGeometry = Esri::GameEngine::Geometry::ArcGISGeometry{};
    
    APIObject->ReplaceGeometry(geometry ? *geometry->APIObject : nullGeometry);
}

UArcGISGeometry* UArcGISGeometryBuilder::ToGeometry() const
{
    auto localResult = APIObject->ToGeometry();
    
    auto localLocalResult = NewObject<UArcGISGeometry>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeometry>(std::move(localResult));
    
    return localLocalResult;
}