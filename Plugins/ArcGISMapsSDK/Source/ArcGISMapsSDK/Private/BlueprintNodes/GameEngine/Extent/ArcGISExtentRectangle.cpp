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
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentRectangle.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Extent/ArcGISExtentRectangle.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"

UArcGISExtentRectangle* UArcGISExtentRectangle::CreateArcGISExtentRectangle(UArcGISPoint* center, double width, double height)
{
    auto result = NewObject<UArcGISExtentRectangle>();
    
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Extent::ArcGISExtentRectangle>(center ? *derivedCenterAPIObject : nullCenter, width, height);
    
    return result;
}

double UArcGISExtentRectangle::GetHeight()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Extent::ArcGISExtentRectangle>(APIObject);
    
    auto localResult = derivedAPIObject->GetHeight();
    
    return localResult;
}

double UArcGISExtentRectangle::GetWidth()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Extent::ArcGISExtentRectangle>(APIObject);
    
    auto localResult = derivedAPIObject->GetWidth();
    
    return localResult;
}