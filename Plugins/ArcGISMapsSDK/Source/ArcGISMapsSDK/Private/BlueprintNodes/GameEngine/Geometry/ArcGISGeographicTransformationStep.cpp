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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeographicTransformationStep.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeographicTransformationStep.h" // IWYU pragma: associated

UArcGISGeographicTransformationStep* UArcGISGeographicTransformationStep::CreateArcGISGeographicTransformationStepWithWKID(int32 WKID)
{
    auto result = NewObject<UArcGISGeographicTransformationStep>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep>(WKID);
    
    return result;
}

UArcGISGeographicTransformationStep* UArcGISGeographicTransformationStep::CreateArcGISGeographicTransformationStepWithWKText(FString WKText)
{
    auto result = NewObject<UArcGISGeographicTransformationStep>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep>(WKText);
    
    return result;
}

bool UArcGISGeographicTransformationStep::GetIsInverse()
{
    auto localResult = APIObject->GetIsInverse();
    
    return localResult;
}

bool UArcGISGeographicTransformationStep::GetIsMissingProjectionEngineFiles()
{
    auto localResult = APIObject->GetIsMissingProjectionEngineFiles();
    
    return localResult;
}

int32 UArcGISGeographicTransformationStep::GetWKID()
{
    auto localResult = APIObject->GetWKID();
    
    return localResult;
}

FString UArcGISGeographicTransformationStep::GetWKText()
{
    auto localResult = APIObject->GetWKText();
    
    return localResult;
}

bool UArcGISGeographicTransformationStep::Equals(UArcGISGeographicTransformationStep* rightGeographicTransformationStep) const
{
    auto nullRightGeographicTransformationStep = Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep{};
    
    auto localResult = APIObject->Equals(rightGeographicTransformationStep ? *rightGeographicTransformationStep->APIObject : nullRightGeographicTransformationStep);
    
    return localResult;
}

UArcGISGeographicTransformationStep* UArcGISGeographicTransformationStep::GetInverse() const
{
    auto localResult = APIObject->GetInverse();
    
    auto localLocalResult = NewObject<UArcGISGeographicTransformationStep>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep>(std::move(localResult));
    
    return localLocalResult;
}