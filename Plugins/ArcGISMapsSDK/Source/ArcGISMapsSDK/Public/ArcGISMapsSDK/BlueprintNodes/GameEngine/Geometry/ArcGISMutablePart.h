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

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "ArcGISMutablePart.generated.h"

class UArcGISPoint;
class UArcGISSpatialReference;
class UArcGISImmutablePointCollection;
class UArcGISSegment;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISMutablePart;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Represents a single part of a multipart builder.
/// </summary>
/// <remarks>
/// Multipart builder is the base class of <see cref="Esri::GameEngine::Geometry::ArcGISPolygonBuilder">ArcGISPolygonBuilder</see> or <see cref="Esri::GameEngine::Geometry::ArcGISPolylineBuilder">ArcGISPolylineBuilder</see>.
/// A part is made up of a collection of segments making the edge of the multipart.
/// Additionally access and modified using the points (vertexes) of segments is available.
/// Adjacent segments which share an end point and a start point are connected and the shared vertex is not duplicated when accessing points.
/// The mutable part can represent gaps between one end point and an adjacent start.
/// However, this is only recommended as a temporary state while modifying a multipart builder,
/// when using <see cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.toGeometry">ArcGISGeometryBuilder.toGeometry</see> the gaps are closed with line segments.
/// 
/// Prior to v100.12, the only supported segment type was <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see>.
/// 
/// From v100.12, curve segments can be added to a <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart">ArcGISMutablePart</see> and used build polygon and polyline
/// geometries. A part may contain a mix of linear and curve segments.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</seealso>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</seealso>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMutablePart :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Creates a part with a specified spatial reference.
    /// </summary>
    /// <param name="spatialReference">A spatial reference object, can be null.</param>
    /// <since>1.0.0</since>
    static UArcGISMutablePart* CreateArcGISMutablePartWithSpatialReference(UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// The end point of the last segment in the part.
    /// Returns null if the collection is empty.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetEndPoint();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Indicates if the part contains any curve segments.
    /// </summary>
    /// <remarks>
    /// Prior to v100.12, only <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see> linear segments were available to be added to mutable parts when
    /// building geometries.
    /// 
    /// From v100.12, geometry builders support curve segments. This property returns true if any segments where
    /// <see cref="Esri::GameEngine::Geometry::ArcGISSegment.isCurve">ArcGISSegment.isCurve</see> is true have been added to the part.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSegment.isCurve">ArcGISSegment.isCurve</seealso>
    /// <since>1.0.0</since>
    bool GetHasCurves();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Indicates if the part contains no segments.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// The count of points in the part.
    /// </summary>
    /// <remarks>
    /// The points in the part are the start and end points of segments.
    /// Segments can share a point if the end point of one segment matches the start point of the next.
    /// </remarks>
    /// <since>1.0.0</since>
    int64 GetPointCount();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// The count of segments in the part.
    /// </summary>
    /// <since>1.0.0</since>
    int64 GetSegmentCount();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// The spatial reference for the part.
    /// </summary>
    /// <remarks>
    /// If the mutable_part does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// The start point of the first segment in the part.
    /// Returns null if the collection is empty.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetStartPoint();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Add a new point to the end of the part by specifying the points x,y coordinates.
    /// A new line segment is added to connect the new point to the previous.
    /// </summary>
    /// <remarks>
    /// The points in the part are the start and end points of segments.
    /// A new line segment is added to connect the new point to the previous point.
    /// If this is the first point in an empty segment, a single closed segment is added using the same start and end point.
    /// Adding a second point updates this line segment to gain a distinct end point.
    /// Adding subsequent points adds new line segments.
    /// </remarks>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPointXY(double x, double y);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Add a new point to the end of the part by specifying the points x,y,z coordinates.
    /// A new line segment is added to connect the new point to the previous.
    /// </summary>
    /// <remarks>
    /// The points in the part are the start and end points of segments.
    /// A new line segment is added to connect the new point to the previous point.
    /// If this is the first point in an empty segment, a single closed segment is added using the same start and end point.
    /// Adding a second point updates this line segment to gain a distinct end point.
    /// Adding subsequent points adds new line segments.
    /// </remarks>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point.</param>
    /// <param name="z">The z-coordinate of the new point.</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPointXYZ(double x, double y, double z);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Add a new point to the end of the part.
    /// A new line segment is added to connect the new point to the previous.
    /// </summary>
    /// <remarks>
    /// The points in the part are the start and end points of segments.
    /// A new line segment is added to connect the new point to the previous point.
    /// If this is the first point in an empty segment, a single closed segment is added using the same start and end point.
    /// Adding a second point updates this line segment to gain a distinct end point.
    /// Adding subsequent points adds new line segments.
    /// </remarks>
    /// <param name="point">The point to add</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPoint(UArcGISPoint* point);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Add segment to the end of the part.
    /// </summary>
    /// <remarks>
    /// A new segment is added to the end. If the start point of the segment matches the previous end point, the segment shares this point.
    /// The count of points increases by 1 if the segment connects, or 2 points if it is disconnected.
    /// A more efficient way to add a <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see> to a part is to use one of the point addition methods. For example <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart.addPoint">ArcGISMutablePart.addPoint</see>.
    /// </remarks>
    /// <param name="segment">The segment.</param>
    /// <returns>
    /// the segment index where the segment was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddSegment(UArcGISSegment* segment);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// For a segment at a specified segment_index the method returns the point index of the segment's end point.
    /// </summary>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <returns>
    /// A point index
    /// </returns>
    /// <since>1.0.0</since>
    int64 GetEndPointIndexFromSegmentIndex(int64 segmentIndex) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
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
    UArcGISPoint* GetPoint(int64 pointIndex) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Returns all the points that are the vertexes of the part.
    /// </summary>
    /// <remarks>
    /// This is a copy of the points in the mutable part.
    /// </remarks>
    /// <returns>
    /// The immutable collections of points.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISImmutablePointCollection* GetPoints() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Gets a segment at a specified segment index.
    /// </summary>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see>.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISSegment* GetSegment(int64 segmentIndex) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Converts from a point index to a segment index that uses the given point as an end point.
    /// If the point is not an end point, then -1 is returned.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <returns>
    /// The segment index containing the end point or max size_t if the segment is not found.
    /// </returns>
    /// <since>1.0.0</since>
    int64 GetSegmentIndexFromEndPointIndex(int64 pointIndex) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Converts from a point index to a segment index that uses the given point as a start point.
    /// If the point is not a start point, then -1 is returned.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <returns>
    /// The segment index containing the start point. If point is not a start point, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 GetSegmentIndexFromStartPointIndex(int64 pointIndex) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// For a segment at a specified segment_index the method returns the point index of the segment's start point.
    /// </summary>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <returns>
    /// A point index
    /// </returns>
    /// <since>1.0.0</since>
    int64 GetStartPointIndexFromSegmentIndex(int64 segmentIndex) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Inserts a point specified by its x,y coordinates into the part at the specified point index.
    /// Line segments are added to connect the point to adjacent segments.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// The points in the part are the start and end points of segments.
    /// An existing segment connection the point before or after the point index is removed.
    /// Inserting a new point inserts new line segments connecting the adjacent points.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point</param>
    /// <since>1.0.0</since>
    void InsertPointXY(int64 pointIndex, double x, double y);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Inserts a point specified by its x,y,z coordinate into the part at the specified point index.
    /// Line segments are added to connect the point to adjacent segments.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// The points in the part are the start and end points of segments.
    /// An existing segment connection the point before or after the point index is removed.
    /// Inserting a new point inserts new line segments connecting the adjacent points.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point.</param>
    /// <param name="z">The z-coordinate of the new point.</param>
    /// <since>1.0.0</since>
    void InsertPointXYZ(int64 pointIndex, double x, double y, double z);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Inserts a point into the part at the specified point index.
    /// Line segments are added to connect the point to adjacent segments.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// The points in the part are the start and end points of segments.
    /// An existing segment connection the point before or after the point index is removed.
    /// Inserting a new point inserts new line segments connecting the adjacent points.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="point">The point to insert.</param>
    /// <since>1.0.0</since>
    void InsertPoint(int64 pointIndex, UArcGISPoint* point);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Inserts a segment into the part at the specified index.
    /// </summary>
    /// <remarks>
    /// The new segment is inserted at the specified segment_index. This index may be equal to the segment count which is equivalent to adding to the end of the collection.
    /// The number of points in the part increases to connect in the new segment.
    /// </remarks>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <param name="segment">The segment to insert.</param>
    /// <since>1.0.0</since>
    void InsertSegment(int64 segmentIndex, UArcGISSegment* segment);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Remove all segments from the part.
    /// </summary>
    /// <remarks>
    /// After calling this method the part is empty.
    /// </remarks>
    /// <since>1.0.0</since>
    void RemoveAll();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Removes a point from the part.
    /// Segments connecting to this point are removed and the gap filled with a new line segment.
    /// </summary>
    /// <remarks>
    /// The points in the part are the start and end points of segments.
    /// Removing a point can remove the two adjacent segments.
    /// A new line segment reconnects the gap.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <since>1.0.0</since>
    void RemovePoint(int64 pointIndex);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Remove a segment at the specified index from the part.
    /// </summary>
    /// <remarks>
    /// If the segment connected to adjacent segments, then after a segment is removed a gap can be left behind.
    /// </remarks>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <since>1.0.0</since>
    void RemoveSegment(int64 segmentIndex);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Replace a point in the part at the specified point index.
    /// Segments that use this point are changed.
    /// </summary>
    /// <remarks>
    /// The points in the part correspond to start and end points of segments. Setting a new point affects 1 or
    /// 2 segments using the point at the specified index. The type of affected segment(s) (<see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</see> or <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see>) remains the same.
    /// 
    /// For affected cubic bezier segments, the shape of the curve may change because the control points remain the
    /// same, as does the unchanged start or end point location. For elliptic arc segments, the arc parameters are
    /// adjusted enough to ensure the unchanged start or end point location remains the same.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="point">The point.</param>
    /// <since>1.0.0</since>
    void SetPoint(int64 pointIndex, UArcGISPoint* point);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePart")
    /// <summary>
    /// Replaces a segment at the specified index in the part.
    /// </summary>
    /// <remarks>
    /// The points of the part can change if the input segment is not coincident with the start and end points of the segment that's being replaced.
    /// </remarks>
    /// <param name="segmentIndex">Zero-based index of the segment.</param>
    /// <param name="segment">The segment to be set into the collection.</param>
    /// <since>1.0.0</since>
    void SetSegment(int64 segmentIndex, UArcGISSegment* segment);
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISMutablePart> APIObject;
};