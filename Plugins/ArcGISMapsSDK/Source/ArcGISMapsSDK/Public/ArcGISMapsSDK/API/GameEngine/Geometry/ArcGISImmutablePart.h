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
class ArcGISSegment;
class ArcGISSpatialReference;

/// <summary>
/// Represents a single part of a multipart geometry (polygon or polyline).
/// </summary>
/// <remarks>
/// A collection of <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> objects that together represent a part in a <see cref="Esri::GameEngine::Geometry::ArcGISMultipart">ArcGISMultipart</see> geometry. You
/// can also access the <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see> objects that represent the vertices of the geometry (that is, the ends of each
/// segment), using point-based helpers such as <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePart.getPoint">ArcGISImmutablePart.getPoint</see>.
/// 
/// Prior to v100.12, the only supported segment type was <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see>. If the underlying geometry contained
/// curve segments (<see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true) then the curve information was lost when iterating through
/// the segments in that part.
/// 
/// From v100.12, curve segments may be returned from <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePart.getSegment">ArcGISImmutablePart.getSegment</see>. A part may contain
/// a mix of linear and curve segments.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISImmutablePart
{
public:
    #pragma region Properties
    /// <summary>
    /// The end point of the last segment in the part.
    /// Returns null if the collection is empty.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISPoint GetEndPoint() const;
    
    /// <summary>
    /// Indicates if the part contains any curve segments.
    /// </summary>
    /// <remarks>
    /// Prior to v100.12, if this property returned true, there was no way to access the curve segment information
    /// contained by the part. Retrieving the <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> instances of the part would return only <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see>
    /// instances.
    /// 
    /// From v100.12, when this property returns true, curve segments may be returned from 
    /// <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePart.getSegment">ArcGISImmutablePart.getSegment</see>. A part may contain a mix of linear and curve segments.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</seealso>
    /// <since>1.0.0</since>
    bool GetHasCurves() const;
    
    /// <summary>
    /// Indicates if the part contains no segments.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty() const;
    
    /// <summary>
    /// The count of points in the part.
    /// </summary>
    /// <remarks>
    /// The points in the part are the start and end points of segments.
    /// Segments can share a point if the end point of one segment matches the start point of the next.
    /// </remarks>
    /// <since>1.0.0</since>
    size_t GetPointCount() const;
    
    /// <summary>
    /// The count of segments in the part.
    /// </summary>
    /// <since>1.0.0</since>
    size_t GetSegmentCount() const;
    
    /// <summary>
    /// The spatial reference for the immutable part.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISSpatialReference GetSpatialReference() const;
    
    /// <summary>
    /// The start point of the first segment in the part.
    /// Returns null if the collection is empty.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISPoint GetStartPoint() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// For a segment at a specified segment_index the method returns the point index of the segment's end point.
    /// </summary>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <returns>
    /// A point index
    /// </returns>
    /// <since>1.0.0</since>
    size_t GetEndPointIndexFromSegmentIndex(size_t segmentIndex) const;
    
    /// <summary>
    /// Returns a point at a specified point index.
    /// </summary>
    /// <remarks>
    /// The points in the part are the start and end points of segments.
    /// Segments can share a point if the end point of one segment matches the start point of the next.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISPoint GetPoint(size_t pointIndex) const;
    
    /// <summary>
    /// Returns all the points that are the vertexes of the part.
    /// </summary>
    /// <returns>
    /// A collections of points in the immutable part.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISImmutablePointCollection GetPoints() const;
    
    /// <summary>
    /// Gets a segment at a specified segment index.
    /// </summary>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see>.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISSegment GetSegment(size_t segmentIndex) const;
    
    /// <summary>
    /// Converts from a point index to a segment index that uses the given point as an end point.
    /// If the point is not an end point then -1 is returned.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <returns>
    /// The segment index containing the end point. If the point index is not an end point, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    size_t GetSegmentIndexFromEndPointIndex(size_t pointIndex) const;
    
    /// <summary>
    /// Converts from a point index to a segment index of the start point and another segment index containing the end point.
    /// If the point is not a start or end point, then -1 is set.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="outStartPointSegmentIndex">This is set to the segment index using the point as a start point. Can be null.</param>
    /// <param name="outEndPointSegmentIndex">This is set to the segment index using the point as an end point. Can be null.</param>
    /// <since>1.0.0</since>
    void GetSegmentIndexFromPointIndex(size_t pointIndex, size_t* outStartPointSegmentIndex, size_t* outEndPointSegmentIndex) const;
    
    /// <summary>
    /// Converts from a point index to a segment index that uses the given point as a start point.
    /// If the point is not a start point, then -1 is returned.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <returns>
    /// The segment index containing the start point. If point is not a start point, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    size_t GetSegmentIndexFromStartPointIndex(size_t pointIndex) const;
    
    /// <summary>
    /// For a segment at a specified segment_index the method returns the point index of the segment's start point.
    /// </summary>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <returns>
    /// A point index
    /// </returns>
    /// <since>1.0.0</since>
    size_t GetStartPointIndexFromSegmentIndex(size_t segmentIndex) const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISImmutablePart(void* handle);
    ArcGISImmutablePart(const ArcGISImmutablePart&) = delete;
    ArcGISImmutablePart(ArcGISImmutablePart&& other) noexcept;
    ArcGISImmutablePart() = default;
    ~ArcGISImmutablePart();
    
    ArcGISImmutablePart& operator=(const ArcGISImmutablePart&) = delete;
    ArcGISImmutablePart& operator=(ArcGISImmutablePart&& other) noexcept;
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