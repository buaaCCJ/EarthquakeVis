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
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfoImmutableCollection.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISImmutableCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileSourceInfoImmutableCollection.h"

namespace Esri
{
namespace Unreal
{
template <>
ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::ArcGISImmutableCollection()
{
	m_handle = nullptr;
}

template <>
ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::~ArcGISImmutableCollection()
{
	if (this->m_handle)
	{
		auto errorHandler = Unreal::CreateErrorHandler();

		RT_VectorTileSourceInfoImmutableCollection_destroy(reinterpret_cast<RT_VectorTileSourceInfoImmutableCollectionHandle>(m_handle), &errorHandler);
	}
}

template <>
GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::operator[](size_t index) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->At(index);
}

template <>
GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::At(size_t position) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->At(position);
}

template <>
bool ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Contains(const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->Contains(value);
}

template <>
bool ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Equals(const ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>& vector2) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->Equals(vector2);
}

template <>
GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::First() const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->First();
}

template <>
size_t ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::GetSize() const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->GetSize();
}

template <>
size_t ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::IndexOf(GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->IndexOf(value);
}

template <>
bool ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::IsEmpty() const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->IsEmpty();
}

template <>
GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Last() const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection*>(this);

	return collection->Last();
}

template <>
size_t ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Npos()
{
	return GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfoImmutableCollection::Npos();
}


} // namespace Unreal
} // namespace Esri