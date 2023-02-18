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
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayerCollection.h" // IWYU pragma: associated

UArcGISLayerCollection* UArcGISLayerCollection::CreateArcGISLayerCollection()
{
    auto result = NewObject<UArcGISLayerCollection>();
    
    result->APIObject = ::MakeShared<Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>>();
    
    return result;
}

int64 UArcGISLayerCollection::GetSize()
{
    auto localResult = APIObject->GetSize();
    
    return localResult;
}

int64 UArcGISLayerCollection::Add(UArcGISLayer* value)
{
    auto nullValue = Esri::GameEngine::Layers::Base::ArcGISLayer{};
    
    auto localResult = APIObject->Add(value ? *value->APIObject : nullValue);
    
    return localResult;
}

int64 UArcGISLayerCollection::AddArray(UArcGISLayerCollection* vector2)
{
    auto nullVector2 = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>{};
    
    auto localResult = APIObject->AddArray(vector2 ? *vector2->APIObject : nullVector2);
    
    return localResult;
}

UArcGISLayer* UArcGISLayerCollection::At(int64 position) const
{
    auto localResult = APIObject->At(position);
    
    auto localLocalResult = NewObject<UArcGISLayer>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Layers::Base::ArcGISLayer>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISLayerCollection::Contains(UArcGISLayer* value) const
{
    auto nullValue = Esri::GameEngine::Layers::Base::ArcGISLayer{};
    
    auto localResult = APIObject->Contains(value ? *value->APIObject : nullValue);
    
    return localResult;
}

bool UArcGISLayerCollection::Equals(UArcGISLayerCollection* vector2) const
{
    auto nullVector2 = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>{};
    
    auto localResult = APIObject->Equals(vector2 ? *vector2->APIObject : nullVector2);
    
    return localResult;
}

UArcGISLayer* UArcGISLayerCollection::First() const
{
    auto localResult = APIObject->First();
    
    auto localLocalResult = NewObject<UArcGISLayer>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Layers::Base::ArcGISLayer>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISLayerCollection::IndexOf(UArcGISLayer* value) const
{
    auto nullValue = Esri::GameEngine::Layers::Base::ArcGISLayer{};
    
    auto localResult = APIObject->IndexOf(value ? *value->APIObject : nullValue);
    
    return localResult;
}

void UArcGISLayerCollection::Insert(int64 position, UArcGISLayer* value)
{
    auto nullValue = Esri::GameEngine::Layers::Base::ArcGISLayer{};
    
    APIObject->Insert(position, value ? *value->APIObject : nullValue);
}

bool UArcGISLayerCollection::IsEmpty() const
{
    auto localResult = APIObject->IsEmpty();
    
    return localResult;
}

UArcGISLayer* UArcGISLayerCollection::Last() const
{
    auto localResult = APIObject->Last();
    
    auto localLocalResult = NewObject<UArcGISLayer>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Layers::Base::ArcGISLayer>(std::move(localResult));
    
    return localLocalResult;
}

void UArcGISLayerCollection::Move(int64 oldPosition, int64 newPosition)
{
    APIObject->Move(oldPosition, newPosition);
}

int64 UArcGISLayerCollection::Npos()
{
    auto localResult = Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>::Npos();
    
    return localResult;
}

void UArcGISLayerCollection::Remove(int64 position)
{
    APIObject->Remove(position);
}

void UArcGISLayerCollection::RemoveAll()
{
    APIObject->RemoveAll();
}