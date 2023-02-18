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
class ArcGISImmutablePointCollection;
class ArcGISPoint;
class ArcGISSpatialReference;

/// <summary>
/// A collection object that can be changed containing points.
/// </summary>
/// <remarks>
/// Contains a collection of points that can be changed.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISImmutablePointCollection">ArcGISImmutablePointCollection</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISMutablePointCollection
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a mutable point collection with a specified spatial reference.
    /// </summary>
    /// <param name="spatialReference">A spatial reference object, can be null.</param>
    /// <since>1.0.0</since>
    ArcGISMutablePointCollection(const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// Indicates if the mutable point collection contains no points.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty() const;
    
    /// <summary>
    /// The number of points in the collection.
    /// </summary>
    /// <since>1.0.0</since>
    size_t GetSize() const;
    
    /// <summary>
    /// The spatial reference for the mutable point collection.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISSpatialReference GetSpatialReference() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Add a new point to the end of the mutable point collection by specifying the points x,y coordinates.
    /// </summary>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    size_t AddPoint(double x, double y);
    
    /// <summary>
    /// Add a new point to the end of the mutable point collection by specifying the points x,y,z coordinates.
    /// </summary>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point.</param>
    /// <param name="z">The z coordinate of the new point.</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    size_t AddPoint(double x, double y, double z);
    
    /// <summary>
    /// Add a new point to the end of the mutable point collection.
    /// </summary>
    /// <param name="point">The point to add</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    size_t AddPoint(const ArcGISPoint& point);
    
    /// <summary>
    /// Add a new points to the end of the mutable point collection.
    /// </summary>
    /// <param name="points">The new points to add</param>
    /// <since>1.0.0</since>
    void AddPoints(const ArcGISImmutablePointCollection& points);
    
    /// <summary>
    /// Add a new points to the end of the mutable point collection.
    /// </summary>
    /// <param name="points">The new points to add</param>
    /// <since>1.0.0</since>
    void AddPoints(const ArcGISMutablePointCollection& points);
    
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
    /// Retrieves the position of the point in the mutable point collection.
    /// The first point that is equal to the supplied point is returned.
    /// </summary>
    /// <param name="point">The point to find</param>
    /// <returns>
    /// The position of the point in the collection, -1 otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    size_t IndexOf(const ArcGISPoint& point) const;
    
    /// <summary>
    /// Inserts a point specified by its x,y coordinates into the mutable point collection at the specified point index.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point</param>
    /// <since>1.0.0</since>
    void InsertPoint(size_t pointIndex, double x, double y);
    
    /// <summary>
    /// Inserts a point specified by its x,y,z coordinate into the mutable point collection at the specified point index.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point</param>
    /// <param name="z">The z-coordinate of the new point</param>
    /// <since>1.0.0</since>
    void InsertPoint(size_t pointIndex, double x, double y, double z);
    
    /// <summary>
    /// Inserts a point into the mutable point collection at the specified point index.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="point">The point to insert.</param>
    /// <since>1.0.0</since>
    void InsertPoint(size_t pointIndex, const ArcGISPoint& point);
    
    /// <summary>
    /// Remove all points from the mutable point collection.
    /// </summary>
    /// <remarks>
    /// After calling this method the mutable point collection is empty.
    /// </remarks>
    /// <since>1.0.0</since>
    void RemoveAll();
    
    /// <summary>
    /// Removes a point from the mutable point collection.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <since>1.0.0</since>
    void RemovePoint(size_t pointIndex);
    
    /// <summary>
    /// Replace a point in the mutable point collection at the specified point index.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="point">The point.</param>
    /// <since>1.0.0</since>
    void SetPoint(size_t pointIndex, const ArcGISPoint& point);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISMutablePointCollection(void* handle);
    ArcGISMutablePointCollection(const ArcGISMutablePointCollection&) = delete;
    ArcGISMutablePointCollection(ArcGISMutablePointCollection&& other) noexcept;
    ArcGISMutablePointCollection() = default;
    ~ArcGISMutablePointCollection();
    
    ArcGISMutablePointCollection& operator=(const ArcGISMutablePointCollection&) = delete;
    ArcGISMutablePointCollection& operator=(ArcGISMutablePointCollection&& other) noexcept;
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