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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSourceCollection.h" // IWYU pragma: associated

UArcGISElevationSourceCollection* UArcGISElevationSourceCollection::CreateArcGISElevationSourceCollection()
{
    auto result = NewObject<UArcGISElevationSourceCollection>();
    
    result->APIObject = ::MakeShared<Esri::Unreal::ArcGISCollection<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>>();
    
    return result;
}

int64 UArcGISElevationSourceCollection::GetSize()
{
    auto localResult = APIObject->GetSize();
    
    return localResult;
}

int64 UArcGISElevationSourceCollection::Add(UArcGISElevationSource* value)
{
    auto nullValue = Esri::GameEngine::Elevation::Base::ArcGISElevationSource{};
    
    auto localResult = APIObject->Add(value ? *value->APIObject : nullValue);
    
    return localResult;
}

int64 UArcGISElevationSourceCollection::AddArray(UArcGISElevationSourceCollection* vector2)
{
    auto nullVector2 = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>{};
    
    auto localResult = APIObject->AddArray(vector2 ? *vector2->APIObject : nullVector2);
    
    return localResult;
}

UArcGISElevationSource* UArcGISElevationSourceCollection::At(int64 position) const
{
    auto localResult = APIObject->At(position);
    
    auto localLocalResult = NewObject<UArcGISElevationSource>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISElevationSourceCollection::Contains(UArcGISElevationSource* value) const
{
    auto nullValue = Esri::GameEngine::Elevation::Base::ArcGISElevationSource{};
    
    auto localResult = APIObject->Contains(value ? *value->APIObject : nullValue);
    
    return localResult;
}

bool UArcGISElevationSourceCollection::Equals(UArcGISElevationSourceCollection* vector2) const
{
    auto nullVector2 = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>{};
    
    auto localResult = APIObject->Equals(vector2 ? *vector2->APIObject : nullVector2);
    
    return localResult;
}

UArcGISElevationSource* UArcGISElevationSourceCollection::First() const
{
    auto localResult = APIObject->First();
    
    auto localLocalResult = NewObject<UArcGISElevationSource>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISElevationSourceCollection::IndexOf(UArcGISElevationSource* value) const
{
    auto nullValue = Esri::GameEngine::Elevation::Base::ArcGISElevationSource{};
    
    auto localResult = APIObject->IndexOf(value ? *value->APIObject : nullValue);
    
    return localResult;
}

void UArcGISElevationSourceCollection::Insert(int64 position, UArcGISElevationSource* value)
{
    auto nullValue = Esri::GameEngine::Elevation::Base::ArcGISElevationSource{};
    
    APIObject->Insert(position, value ? *value->APIObject : nullValue);
}

bool UArcGISElevationSourceCollection::IsEmpty() const
{
    auto localResult = APIObject->IsEmpty();
    
    return localResult;
}

UArcGISElevationSource* UArcGISElevationSourceCollection::Last() const
{
    auto localResult = APIObject->Last();
    
    auto localLocalResult = NewObject<UArcGISElevationSource>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>(std::move(localResult));
    
    return localLocalResult;
}

void UArcGISElevationSourceCollection::Move(int64 oldPosition, int64 newPosition)
{
    APIObject->Move(oldPosition, newPosition);
}

int64 UArcGISElevationSourceCollection::Npos()
{
    auto localResult = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>::Npos();
    
    return localResult;
}

void UArcGISElevationSourceCollection::Remove(int64 position)
{
    APIObject->Remove(position);
}

void UArcGISElevationSourceCollection::RemoveAll()
{
    APIObject->RemoveAll();
}