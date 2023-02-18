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
namespace Elevation
{
class ArcGISImageElevationSource;

namespace Base
{
class ArcGISElevationSource;
} // namespace Base
} // namespace Elevation

namespace Layers
{
class ArcGIS3DObjectSceneLayer;
class ArcGISImageLayer;
class ArcGISIntegratedMeshLayer;
class ArcGISUnknownLayer;
class ArcGISUnsupportedLayer;
class ArcGISVectorTileLayer;

namespace Base
{
class ArcGISLayer;
} // namespace Base
} // namespace Layers
} // namespace GameEngine

namespace Unreal
{
template <typename T>
class ArcGISCollection final
{
public:
	class ConstIterator
	{
	public:
		ConstIterator(const ArcGISCollection<T>* collection, size_t offset) : m_collection(collection), m_offset(offset)
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
		const ArcGISCollection<T>* m_collection;
		size_t m_offset;
	};

	class Iterator
	{
	public:
		Iterator(ArcGISCollection<T>* collection, size_t offset) : m_collection(collection), m_offset(offset)
		{
		}

		Iterator& operator++()
		{
			++m_offset;

			return *this;
		}

		bool operator!=(const Iterator& rhs) const
		{
			return m_collection != rhs.m_collection || m_offset != rhs.m_offset;
		}

		T operator*()
		{
			return (*m_collection)[m_offset];
		}

	private:
		ArcGISCollection<T>* m_collection;
		size_t m_offset;
	};

public:
	ArcGISCollection();
	~ArcGISCollection();

	explicit ArcGISCollection(void* handle) : m_handle(handle)
	{
	}

	ArcGISCollection(ArcGISCollection&& other)
	{
		using std::swap;
		swap(m_handle, other.m_handle);
	}

	ArcGISCollection(const ArcGISCollection&) = delete;

	ArcGISCollection& operator=(const ArcGISCollection&) = delete;

	ArcGISCollection& operator=(ArcGISCollection&& other) noexcept
	{
		if (this != &other)
		{
			using std::swap;
			swap(m_handle, other.m_handle);
		}

		return *this;
	}

	T operator[](size_t index) const;

	Iterator begin()
	{
		return Iterator(this, 0);
	}

	ConstIterator begin() const
	{
		return ConstIterator(this, 0);
	}

	Iterator end()
	{
		return Iterator(this, GetSize());
	}

	ConstIterator end() const
	{
		return ConstIterator(this, GetSize());
	}

	void* GetHandle() const
	{
		return m_handle;
	}

	size_t Add(const T& value);

	template<typename U>
	size_t Add(const U& value);

	size_t AddArray(const ArcGISCollection<T>& vector2);

	T At(size_t position) const;

	bool Contains(const T& value) const;

	template<typename U>
	bool Contains(const U& value) const;

	bool Equals(const ArcGISCollection<T>& vector2) const;

	T First() const;

	size_t GetSize() const;

	size_t IndexOf(T& value) const;

	template<typename U>
	size_t IndexOf(U& value) const;

	void Insert(size_t position, const T& value);

	template<typename U>
	void Insert(size_t position, const U& value);

	bool IsEmpty() const;

	T Last() const;

	void Move(size_t oldPosition, size_t newPosition);

	static size_t Npos();

	void Remove(size_t position);

	void RemoveAll();

private:
	void* m_handle{nullptr};
};

template <>
ARCGISMAPSSDK_API ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::ArcGISCollection();

template <>
ARCGISMAPSSDK_API ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::~ArcGISCollection();

template <>
ARCGISMAPSSDK_API GameEngine::Elevation::Base::ArcGISElevationSource ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::operator[](size_t index) const;

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Add(const GameEngine::Elevation::Base::ArcGISElevationSource& value);

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::AddArray(const ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>& vector2);

template <>
ARCGISMAPSSDK_API GameEngine::Elevation::Base::ArcGISElevationSource ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::At(size_t position) const;

template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Contains(const GameEngine::Elevation::Base::ArcGISElevationSource& value) const;

template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Equals(const ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>& vector2) const;

template <>
ARCGISMAPSSDK_API GameEngine::Elevation::Base::ArcGISElevationSource ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::First() const;

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::GetSize() const;

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::IndexOf(GameEngine::Elevation::Base::ArcGISElevationSource& value) const;

template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Insert(size_t position, const GameEngine::Elevation::Base::ArcGISElevationSource& value);

template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::IsEmpty() const;

template <>
ARCGISMAPSSDK_API GameEngine::Elevation::Base::ArcGISElevationSource ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Last() const;

template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Move(size_t oldPosition, size_t newPosition);

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Npos();

template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Remove(size_t position);

template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::RemoveAll();

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Add(const GameEngine::Elevation::ArcGISImageElevationSource& value);

template <>
template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Contains(const GameEngine::Elevation::ArcGISImageElevationSource& value) const;

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::IndexOf(GameEngine::Elevation::ArcGISImageElevationSource& value) const;

template <>
template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Elevation::Base::ArcGISElevationSource>::Insert(size_t position, const GameEngine::Elevation::ArcGISImageElevationSource& value);

template <>
ARCGISMAPSSDK_API ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::ArcGISCollection();

template <>
ARCGISMAPSSDK_API ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::~ArcGISCollection();

template <>
ARCGISMAPSSDK_API GameEngine::Layers::Base::ArcGISLayer ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::operator[](size_t index) const;

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::Base::ArcGISLayer& value);

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::AddArray(const ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>& vector2);

template <>
ARCGISMAPSSDK_API GameEngine::Layers::Base::ArcGISLayer ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::At(size_t position) const;

template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::Base::ArcGISLayer& value) const;

template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Equals(const ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>& vector2) const;

template <>
ARCGISMAPSSDK_API GameEngine::Layers::Base::ArcGISLayer ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::First() const;

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::GetSize() const;

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::Base::ArcGISLayer& value) const;

template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::Base::ArcGISLayer& value);

template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IsEmpty() const;

template <>
ARCGISMAPSSDK_API GameEngine::Layers::Base::ArcGISLayer ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Last() const;

template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Move(size_t oldPosition, size_t newPosition);

template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Npos();

template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Remove(size_t position);

template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::RemoveAll();

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGIS3DObjectSceneLayer& value);

template <>
template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGIS3DObjectSceneLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGIS3DObjectSceneLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGIS3DObjectSceneLayer& value);

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISImageLayer& value);

template <>
template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISImageLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISImageLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISImageLayer& value);

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISIntegratedMeshLayer& value);

template <>
template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISIntegratedMeshLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISIntegratedMeshLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISIntegratedMeshLayer& value);

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISUnknownLayer& value);

template <>
template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISUnknownLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISUnknownLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISUnknownLayer& value);

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISUnsupportedLayer& value);

template <>
template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISUnsupportedLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISUnsupportedLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISUnsupportedLayer& value);

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Add(const GameEngine::Layers::ArcGISVectorTileLayer& value);

template <>
template <>
ARCGISMAPSSDK_API bool ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Contains(const GameEngine::Layers::ArcGISVectorTileLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API size_t ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::IndexOf(GameEngine::Layers::ArcGISVectorTileLayer& value) const;

template <>
template <>
ARCGISMAPSSDK_API void ArcGISCollection<GameEngine::Layers::Base::ArcGISLayer>::Insert(size_t position, const GameEngine::Layers::ArcGISVectorTileLayer& value);
} // namespace Unreal
} // namespace Esri