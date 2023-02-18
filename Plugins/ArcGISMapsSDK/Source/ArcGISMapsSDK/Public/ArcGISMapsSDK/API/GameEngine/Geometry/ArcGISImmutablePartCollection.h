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
namespace Geometry
{
class ArcGISImmutablePart;
class ArcGISSpatialReference;

/// <summary>
/// Represents immutable collection of parts for a polygon or polyline geometry. Each part is a collection of segments.
/// </summary>
/// <remarks>
/// Polygons and polyline can have multiple disjoint parts.
/// Each part is represented by a <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePart">ArcGISImmutablePart</see>.
/// A part is composed of segments representing the edge of the polygon or polyline.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISImmutablePartCollection
{
public:
    #pragma region Properties
    /// <summary>
    /// Indicates if the immutable part collection contains no parts.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty() const;
    
    /// <summary>
    /// The number of parts in the immutable part collection.
    /// </summary>
    /// <since>1.0.0</since>
    size_t GetSize() const;
    
    /// <summary>
    /// The spatial reference for the immutable part collection.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISSpatialReference GetSpatialReference() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Returns a part at the specified index in the immutable part collection.
    /// A part is represented by a immutable collection of segments.
    /// </summary>
    /// <param name="index">Position to retrieve the part.</param>
    /// <returns>
    /// the immutable part at the specified part index.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISImmutablePart GetPart(size_t index) const;
    
    /// <summary>
    /// Retrieves the position of the given part in the immutable part collection
    /// </summary>
    /// <param name="immutablePart">The part you want to find.</param>
    /// <returns>
    /// The position of the part in the collection, -1 otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    size_t IndexOf(const ArcGISImmutablePart& immutablePart) const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISImmutablePartCollection(void* handle);
    ArcGISImmutablePartCollection(const ArcGISImmutablePartCollection&) = delete;
    ArcGISImmutablePartCollection(ArcGISImmutablePartCollection&& other) noexcept;
    ArcGISImmutablePartCollection() = default;
    ~ArcGISImmutablePartCollection();
    
    ArcGISImmutablePartCollection& operator=(const ArcGISImmutablePartCollection&) = delete;
    ArcGISImmutablePartCollection& operator=(ArcGISImmutablePartCollection&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri