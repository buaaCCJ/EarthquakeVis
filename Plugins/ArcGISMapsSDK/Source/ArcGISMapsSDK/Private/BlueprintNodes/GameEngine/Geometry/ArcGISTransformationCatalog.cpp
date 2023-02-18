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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDatumTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISTransformationCatalog.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISDatumTransformation.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISTransformationCatalog.h" // IWYU pragma: associated

FString UArcGISTransformationCatalog::GetProjectionEngineDirectory()
{
    auto localResult = Esri::GameEngine::Geometry::ArcGISTransformationCatalog::GetProjectionEngineDirectory();
    
    return localResult;
}
void UArcGISTransformationCatalog::SetProjectionEngineDirectory(FString projectionEngineDirectory)
{
    Esri::GameEngine::Geometry::ArcGISTransformationCatalog::SetProjectionEngineDirectory(projectionEngineDirectory);
}

UArcGISDatumTransformation* UArcGISTransformationCatalog::GetTransformation(UArcGISSpatialReference* inputSpatialReference, UArcGISSpatialReference* outputSpatialReference)
{
    auto nullInputSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    auto nullOutputSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISTransformationCatalog::GetTransformation(inputSpatialReference ? *inputSpatialReference->APIObject : nullInputSpatialReference, outputSpatialReference ? *outputSpatialReference->APIObject : nullOutputSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISDatumTransformation>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISDatumTransformation>(std::move(localResult));
    
    return localLocalResult;
}