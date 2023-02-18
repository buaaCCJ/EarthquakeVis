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
class ArcGISPoint;
class ArcGISSpatialReference;

/// <summary>
/// Represents an immutable collection of points.
/// </summary>
/// <remarks>
/// This collection is used to represent the content of a <see cref="Esri::GameEngine::Geometry::ArcGISMultipoint">ArcGISMultipoint</see> geometry.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISImmutablePointCollection
{
public:
    #pragma region Properties
    /// <summary>
    /// Indicates if the immutable point collection contains no points.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty() const;
    
    /// <summary>
    /// The number of points in the collection.
    /// </summary>
    /// <since>1.0.0</since>
    size_t GetSize() const;
    
    /// <summary>
    /// The spatial reference for the immutable point collection.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISSpatialReference GetSpatialReference() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Returns a point at the specified index in the collection.
    /// </summary>
    /// <param name="index">The position in the collection.</param>
    /// <returns>
    /// The point at the specified position in the collection.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISPoint GetPoint(size_t index) const;
    
    /// <summary>
    /// Retrieves the position of the point in the immutable point collection.
    /// The first point that is equal to the supplied point is returned.
    /// </summary>
    /// <param name="point">The point to find</param>
    /// <returns>
    /// The position of the point in the collection, -1 otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    size_t IndexOf(const ArcGISPoint& point) const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISImmutablePointCollection(void* handle);
    ArcGISImmutablePointCollection(const ArcGISImmutablePointCollection&) = delete;
    ArcGISImmutablePointCollection(ArcGISImmutablePointCollection&& other) noexcept;
    ArcGISImmutablePointCollection() = default;
    ~ArcGISImmutablePointCollection();
    
    ArcGISImmutablePointCollection& operator=(const ArcGISImmutablePointCollection&) = delete;
    ArcGISImmutablePointCollection& operator=(ArcGISImmutablePointCollection&& other) noexcept;
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