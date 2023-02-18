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
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfo.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfo.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfoImmutableCollection.h" // IWYU pragma: associated

int64 UArcGISVectorTileSourceInfoImmutableCollection::GetSize()
{
    auto localResult = APIObject->GetSize();
    
    return localResult;
}

UArcGISVectorTileSourceInfo* UArcGISVectorTileSourceInfoImmutableCollection::At(int64 position) const
{
    auto localResult = APIObject->At(position);
    
    auto localLocalResult = NewObject<UArcGISVectorTileSourceInfo>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISVectorTileSourceInfoImmutableCollection::Contains(UArcGISVectorTileSourceInfo* value) const
{
    auto nullValue = Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo{};
    
    auto localResult = APIObject->Contains(value ? *value->APIObject : nullValue);
    
    return localResult;
}

bool UArcGISVectorTileSourceInfoImmutableCollection::Equals(UArcGISVectorTileSourceInfoImmutableCollection* vector2) const
{
    auto nullVector2 = Esri::Unreal::ArcGISImmutableCollection<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>{};
    
    auto localResult = APIObject->Equals(vector2 ? *vector2->APIObject : nullVector2);
    
    return localResult;
}

UArcGISVectorTileSourceInfo* UArcGISVectorTileSourceInfoImmutableCollection::First() const
{
    auto localResult = APIObject->First();
    
    auto localLocalResult = NewObject<UArcGISVectorTileSourceInfo>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISVectorTileSourceInfoImmutableCollection::IndexOf(UArcGISVectorTileSourceInfo* value) const
{
    auto nullValue = Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo{};
    
    auto localResult = APIObject->IndexOf(value ? *value->APIObject : nullValue);
    
    return localResult;
}

bool UArcGISVectorTileSourceInfoImmutableCollection::IsEmpty() const
{
    auto localResult = APIObject->IsEmpty();
    
    return localResult;
}

UArcGISVectorTileSourceInfo* UArcGISVectorTileSourceInfoImmutableCollection::Last() const
{
    auto localResult = APIObject->Last();
    
    auto localLocalResult = NewObject<UArcGISVectorTileSourceInfo>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISVectorTileSourceInfoImmutableCollection::Npos()
{
    auto localResult = Esri::Unreal::ArcGISImmutableCollection<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Npos();
    
    return localResult;
}