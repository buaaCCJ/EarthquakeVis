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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePartCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISImmutablePart.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISImmutablePartCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

bool UArcGISImmutablePartCollection::GetIsEmpty()
{
    auto localResult = APIObject->GetIsEmpty();
    
    return localResult;
}

int64 UArcGISImmutablePartCollection::GetSize()
{
    auto localResult = APIObject->GetSize();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISImmutablePartCollection::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISImmutablePart* UArcGISImmutablePartCollection::GetPart(int64 index) const
{
    auto localResult = APIObject->GetPart(index);
    
    auto localLocalResult = NewObject<UArcGISImmutablePart>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISImmutablePart>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISImmutablePartCollection::IndexOf(UArcGISImmutablePart* immutablePart) const
{
    auto nullImmutablePart = Esri::GameEngine::Geometry::ArcGISImmutablePart{};
    
    auto localResult = APIObject->IndexOf(immutablePart ? *immutablePart->APIObject : nullImmutablePart);
    
    return localResult;
}