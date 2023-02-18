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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadable.h"
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentRectangle.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayerType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Extent/ArcGISExtentRectangle.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayer.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerType.h"

UArcGISLayer* UArcGISLayer::CreateArcGISLayer(FString source, EArcGISLayerType::Type type, FString APIKey)
{
    auto result = NewObject<UArcGISLayer>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Layers::Base::ArcGISLayer>(source, static_cast<Esri::GameEngine::Layers::Base::ArcGISLayerType>(type), APIKey);
    
    return result;
}

FString UArcGISLayer::GetAPIKey()
{
    auto localResult = APIObject->GetAPIKey();
    
    return localResult;
}

UArcGISExtentRectangle* UArcGISLayer::GetExtent()
{
    auto localResult = APIObject->GetExtent();
    
    auto localLocalResult = NewObject<UArcGISExtentRectangle>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Extent::ArcGISExtentRectangle>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISLayer::GetIsVisible()
{
    auto localResult = APIObject->GetIsVisible();
    
    return localResult;
}
void UArcGISLayer::SetIsVisible(bool isVisible)
{
    APIObject->SetIsVisible(isVisible);
}

FString UArcGISLayer::GetName()
{
    auto localResult = APIObject->GetName();
    
    return localResult;
}
void UArcGISLayer::SetName(FString name)
{
    APIObject->SetName(name);
}

float UArcGISLayer::GetOpacity()
{
    auto localResult = APIObject->GetOpacity();
    
    return localResult;
}
void UArcGISLayer::SetOpacity(float opacity)
{
    APIObject->SetOpacity(opacity);
}

FString UArcGISLayer::GetSource()
{
    auto localResult = APIObject->GetSource();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISLayer::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}