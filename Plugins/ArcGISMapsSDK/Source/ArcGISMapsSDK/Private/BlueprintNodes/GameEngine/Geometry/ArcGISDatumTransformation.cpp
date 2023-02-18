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
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISDatumTransformation.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISSpatialReference* UArcGISDatumTransformation::GetInputSpatialReference()
{
    auto localResult = APIObject->GetInputSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISDatumTransformation::GetIsMissingProjectionEngineFiles()
{
    auto localResult = APIObject->GetIsMissingProjectionEngineFiles();
    
    return localResult;
}

FString UArcGISDatumTransformation::GetName()
{
    auto localResult = APIObject->GetName();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISDatumTransformation::GetOutputSpatialReference()
{
    auto localResult = APIObject->GetOutputSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISDatumTransformation::Equals(UArcGISDatumTransformation* rightDatumTransformation) const
{
    auto nullRightDatumTransformation = Esri::GameEngine::Geometry::ArcGISDatumTransformation{};
    
    auto localResult = APIObject->Equals(rightDatumTransformation ? *rightDatumTransformation->APIObject : nullRightDatumTransformation);
    
    return localResult;
}

UArcGISDatumTransformation* UArcGISDatumTransformation::GetInverse() const
{
    auto localResult = APIObject->GetInverse();
    
    auto localLocalResult = NewObject<UArcGISDatumTransformation>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISDatumTransformation>(std::move(localResult));
    
    return localLocalResult;
}