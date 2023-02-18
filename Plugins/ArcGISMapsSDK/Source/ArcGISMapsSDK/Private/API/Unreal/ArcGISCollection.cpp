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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/ArcGISImageElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSourceCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGIS3DObjectSceneLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISImageLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISIntegratedMeshLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnknownLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnsupportedLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISVectorTileLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayerCollection.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSourceCollection.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerCollection.h"

namespace Esri
{
namespace Unreal
{
template <>
ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::ArcGISCollection()
{
	auto errorHandler = Unreal::CreateErrorHandler();

	auto localResult = RT_GEElevationSourceCollection_create(&errorHandler);

	m_handle = localResult;
}

template <>
ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::~ArcGISCollection()
{
	if (this->m_handle)
	{
		auto errorHandler = Unreal::CreateErrorHandler();

		RT_GEElevationSourceCollection_destroy(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(m_handle), &errorHandler);
	}
}

template <>
GameEngine::Elevation::Base::ArcGISElevationSource ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::operator[](size_t index) const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->At(index);
}

template <>
size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Add(const GameEngine::Elevation::Base::ArcGISElevationSource& value)
{
	auto collection = reinterpret_cast<GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->Add(value);
}

template <>
size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::AddArray(const ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>& vector2)
{
	auto collection = reinterpret_cast<GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->AddArray(vector2);
}

template <>
GameEngine::Elevation::Base::ArcGISElevationSource ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::At(size_t position) const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->At(position);
}

template <>
bool ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Contains(const GameEngine::Elevation::Base::ArcGISElevationSource& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->Contains(value);
}

template <>
bool ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Equals(const ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>& vector2) const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->Equals(vector2);
}

template <>
GameEngine::Elevation::Base::ArcGISElevationSource ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::First() const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->First();
}

template <>
size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::GetSize() const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->GetSize();
}

template <>
size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::IndexOf(GameEngine::Elevation::Base::ArcGISElevationSource& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->IndexOf(value);
}

template <>
void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Insert(size_t position, const GameEngine::Elevation::Base::ArcGISElevationSource& value)
{
	auto collection = reinterpret_cast<GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	collection->Insert(position, value);
}

template <>
bool ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::IsEmpty() const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->IsEmpty();
}

template <>
GameEngine::Elevation::Base::ArcGISElevationSource ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Last() const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->Last();
}

template <>
void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Move(size_t oldPosition, size_t newPosition)
{
	auto collection = reinterpret_cast<GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	collection->Move(oldPosition, newPosition);
}

template <>
size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Npos()
{
	return GameEngine::Elevation::Base::ArcGISElevationSourceCollection::Npos();
}

template <>
void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Remove(size_t position)
{
	auto collection = reinterpret_cast<GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	collection->Remove(position);
}

template <>
void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::RemoveAll()
{
	auto collection = reinterpret_cast<GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	collection->RemoveAll();
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Add(const GameEngine::Elevation::ArcGISImageElevationSource& value)
{
	auto collection = reinterpret_cast<GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->Add(value);
}

template <>
template <>
bool ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Contains(const GameEngine::Elevation::ArcGISImageElevationSource& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->Contains(value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::IndexOf(GameEngine::Elevation::ArcGISImageElevationSource& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	return collection->IndexOf(value);
}

template <>
template <>
void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Insert(size_t position, const GameEngine::Elevation::ArcGISImageElevationSource& value)
{
	auto collection = reinterpret_cast<GameEngine::Elevation::Base::ArcGISElevationSourceCollection*>(this);

	collection->Insert(position, value);
}

template <>
ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::ArcGISCollection()
{
	auto errorHandler = Unreal::CreateErrorHandler();

	auto localResult = RT_GELayerCollection_create(&errorHandler);

	m_handle = localResult;
}

template <>
ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::~ArcGISCollection()
{
	if (this->m_handle)
	{
		auto errorHandler = Unreal::CreateErrorHandler();

		RT_GELayerCollection_destroy(reinterpret_cast<RT_GELayerCollectionHandle>(m_handle), &errorHandler);
	}
}

template <>
GameEngine::Layers::Base::ArcGISLayer ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::operator[](size_t index) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->At(index);
}

template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::Base::ArcGISLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Add(value);
}

template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::AddArray(const ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>& vector2)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->AddArray(vector2);
}

template <>
GameEngine::Layers::Base::ArcGISLayer ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::At(size_t position) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->At(position);
}

template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::Base::ArcGISLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Contains(value);
}

template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Equals(const ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>& vector2) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Equals(vector2);
}

template <>
GameEngine::Layers::Base::ArcGISLayer ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::First() const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->First();
}

template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::GetSize() const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->GetSize();
}

template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::Base::ArcGISLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->IndexOf(value);
}

template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::Base::ArcGISLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Insert(position, value);
}

template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IsEmpty() const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->IsEmpty();
}

template <>
GameEngine::Layers::Base::ArcGISLayer ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Last() const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Last();
}

template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Move(size_t oldPosition, size_t newPosition)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Move(oldPosition, newPosition);
}

template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Npos()
{
	return GameEngine::Layers::Base::ArcGISLayerCollection::Npos();
}

template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Remove(size_t position)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Remove(position);
}

template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::RemoveAll()
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->RemoveAll();
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGIS3DObjectSceneLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Add(value);
}

template <>
template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGIS3DObjectSceneLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Contains(value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGIS3DObjectSceneLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->IndexOf(value);
}

template <>
template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGIS3DObjectSceneLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Insert(position, value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISImageLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Add(value);
}

template <>
template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISImageLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Contains(value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISImageLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->IndexOf(value);
}

template <>
template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISImageLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Insert(position, value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISIntegratedMeshLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Add(value);
}

template <>
template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISIntegratedMeshLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Contains(value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISIntegratedMeshLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->IndexOf(value);
}

template <>
template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISIntegratedMeshLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Insert(position, value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISUnknownLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Add(value);
}

template <>
template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISUnknownLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Contains(value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISUnknownLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->IndexOf(value);
}

template <>
template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISUnknownLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Insert(position, value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISUnsupportedLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Add(value);
}

template <>
template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISUnsupportedLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Contains(value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISUnsupportedLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->IndexOf(value);
}

template <>
template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISUnsupportedLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Insert(position, value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISVectorTileLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Add(value);
}

template <>
template <>
bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISVectorTileLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->Contains(value);
}

template <>
template <>
size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISVectorTileLayer& value) const
{
	auto collection = reinterpret_cast<const GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	return collection->IndexOf(value);
}

template <>
template <>
void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISVectorTileLayer& value)
{
	auto collection = reinterpret_cast<GameEngine::Layers::Base::ArcGISLayerCollection*>(this);

	collection->Insert(position, value);
}
} // namespace Unreal
} // namespace Esri