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
#pragma once

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
class ArcGISVectorTileSourceInfo;
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine

namespace Unreal
{
template <typename T>
class ArcGISImmutableCollection final
{
public:
	class ConstIterator
	{
	public:
		ConstIterator(const ArcGISImmutableCollection<T>* collection, size_t offset) : m_collection(collection), m_offset(offset)
		{
		}

		ConstIterator& operator++()
		{
			++m_offset;

			return *this;
		}

		bool operator!=(const ConstIterator& rhs) const
		{
			return m_collection != rhs.m_collection || m_offset != rhs.m_offset;
		}

		const T operator*() const
		{
			return (*m_collection)[m_offset];
		}

	private:
		const ArcGISImmutableCollection<T>* m_collection;
		size_t m_offset;
	};

public:
	ArcGISImmutableCollection();
	~ArcGISImmutableCollection();

	explicit ArcGISImmutableCollection(void* handle) : m_handle(handle)
	{
	}

	ArcGISImmutableCollection(ArcGISImmutableCollection&& other)
	{
		using std::swap;
		swap(m_handle, other.m_handle);
	}

	ArcGISImmutableCollection(const ArcGISImmutableCollection&) = delete;

	ArcGISImmutableCollection& operator=(const ArcGISImmutableCollection&) = delete;

	ArcGISImmutableCollection& operator=(ArcGISImmutableCollection&& other) noexcept
	{
		if (this != &other)
		{
			using std::swap;
			swap(m_handle, other.m_handle);
		}

		return *this;
	}

	T operator[](size_t index) const;

	ConstIterator begin() const
	{
		return ConstIterator(this, 0);
	}

	ConstIterator end() const
	{
		return ConstIterator(this, GetSize());
	}

	void* GetHandle() const
	{
		return m_handle;
	}

	T At(size_t position) const;

	bool Contains(const T& value) const;

	template<typename U>
	bool Contains(const U& value) const;

	bool Equals(const ArcGISImmutableCollection<T>& vector2) const;

	T First() const;

	size_t GetSize() const;

	size_t IndexOf(T& value) const;

	template<typename U>
	size_t IndexOf(U& value) const;

	bool IsEmpty() const;

	T Last() const;

	static size_t Npos();

private:
	void* m_handle{nullptr};
};

template <>
ARCGISMAPSSDK_API ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::ArcGISImmutableCollection();

template <>
ARCGISMAPSSDK_API ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::~ArcGISImmutableCollection();

template <>
ARCGISMAPSSDK_API GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::operator[](size_t index) const;

template <>
ARCGISMAPSSDK_API GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::At(size_t position) const;

template <>
ARCGISMAPSSDK_API bool ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Contains(const GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo& value) const;

template <>
ARCGISMAPSSDK_API bool ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Equals(const ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>& vector2) const;

template <>
ARCGISMAPSSDK_API GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::First() const;

template <>
ARCGISMAPSSDK_API size_t ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::GetSize() const;

template <>
ARCGISMAPSSDK_API size_t ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::IndexOf(GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo& value) const;

template <>
ARCGISMAPSSDK_API bool ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::IsEmpty() const;

template <>
ARCGISMAPSSDK_API GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Last() const;

template <>
ARCGISMAPSSDK_API size_t ArcGISImmutableCollection<GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>::Npos();


} // namespace Unreal
} // namespace Esri