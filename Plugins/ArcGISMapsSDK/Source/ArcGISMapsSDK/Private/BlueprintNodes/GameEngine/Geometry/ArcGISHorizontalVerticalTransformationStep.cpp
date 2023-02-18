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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISHorizontalVerticalTransformationStep.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISHorizontalVerticalTransformationStep.h" // IWYU pragma: associated

UArcGISHorizontalVerticalTransformationStep* UArcGISHorizontalVerticalTransformationStep::CreateArcGISHorizontalVerticalTransformationStepWithWKID(int32 WKID)
{
    auto result = NewObject<UArcGISHorizontalVerticalTransformationStep>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep>(WKID);
    
    return result;
}

UArcGISHorizontalVerticalTransformationStep* UArcGISHorizontalVerticalTransformationStep::CreateArcGISHorizontalVerticalTransformationStepWithWKText(FString WKText)
{
    auto result = NewObject<UArcGISHorizontalVerticalTransformationStep>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep>(WKText);
    
    return result;
}

bool UArcGISHorizontalVerticalTransformationStep::GetIsInverse()
{
    auto localResult = APIObject->GetIsInverse();
    
    return localResult;
}

bool UArcGISHorizontalVerticalTransformationStep::GetIsMissingProjectionEngineFiles()
{
    auto localResult = APIObject->GetIsMissingProjectionEngineFiles();
    
    return localResult;
}

int32 UArcGISHorizontalVerticalTransformationStep::GetWKID()
{
    auto localResult = APIObject->GetWKID();
    
    return localResult;
}

FString UArcGISHorizontalVerticalTransformationStep::GetWKText()
{
    auto localResult = APIObject->GetWKText();
    
    return localResult;
}

bool UArcGISHorizontalVerticalTransformationStep::Equals(UArcGISHorizontalVerticalTransformationStep* rightHorizontalVerticalTransformationStep) const
{
    auto nullRightHorizontalVerticalTransformationStep = Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep{};
    
    auto localResult = APIObject->Equals(rightHorizontalVerticalTransformationStep ? *rightHorizontalVerticalTransformationStep->APIObject : nullRightHorizontalVerticalTransformationStep);
    
    return localResult;
}

UArcGISHorizontalVerticalTransformationStep* UArcGISHorizontalVerticalTransformationStep::GetInverse() const
{
    auto localResult = APIObject->GetInverse();
    
    auto localLocalResult = NewObject<UArcGISHorizontalVerticalTransformationStep>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep>(std::move(localResult));
    
    return localLocalResult;
}