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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePartCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMutablePart.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMutablePartCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISMutablePartCollection* UArcGISMutablePartCollection::CreateArcGISMutablePartCollectionWithSpatialReference(UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISMutablePartCollection>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMutablePartCollection>(spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

bool UArcGISMutablePartCollection::GetIsEmpty()
{
    auto localResult = APIObject->GetIsEmpty();
    
    return localResult;
}

int64 UArcGISMutablePartCollection::GetSize()
{
    auto localResult = APIObject->GetSize();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISMutablePartCollection::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISMutablePartCollection::AddPart(UArcGISMutablePart* mutablePart)
{
    auto nullMutablePart = Esri::GameEngine::Geometry::ArcGISMutablePart{};
    
    auto localResult = APIObject->AddPart(mutablePart ? *mutablePart->APIObject : nullMutablePart);
    
    return localResult;
}

UArcGISMutablePart* UArcGISMutablePartCollection::GetPart(int64 index) const
{
    auto localResult = APIObject->GetPart(index);
    
    auto localLocalResult = NewObject<UArcGISMutablePart>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMutablePart>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISMutablePartCollection::IndexOf(UArcGISMutablePart* mutablePart) const
{
    auto nullMutablePart = Esri::GameEngine::Geometry::ArcGISMutablePart{};
    
    auto localResult = APIObject->IndexOf(mutablePart ? *mutablePart->APIObject : nullMutablePart);
    
    return localResult;
}

void UArcGISMutablePartCollection::InsertPart(int64 index, UArcGISMutablePart* mutablePart)
{
    auto nullMutablePart = Esri::GameEngine::Geometry::ArcGISMutablePart{};
    
    APIObject->InsertPart(index, mutablePart ? *mutablePart->APIObject : nullMutablePart);
}

void UArcGISMutablePartCollection::RemoveAll()
{
    APIObject->RemoveAll();
}

void UArcGISMutablePartCollection::RemovePart(int64 index)
{
    APIObject->RemovePart(index);
}

void UArcGISMutablePartCollection::SetPart(int64 index, UArcGISMutablePart* mutablePart)
{
    auto nullMutablePart = Esri::GameEngine::Geometry::ArcGISMutablePart{};
    
    APIObject->SetPart(index, mutablePart ? *mutablePart->APIObject : nullMutablePart);
}