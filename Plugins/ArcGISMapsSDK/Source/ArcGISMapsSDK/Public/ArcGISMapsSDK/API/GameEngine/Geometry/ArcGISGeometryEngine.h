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
namespace Unreal
{
template<typename T> class ArcGISImmutableArray;
template<typename T> class ArcGISList;
} // namespace Unreal

namespace GameEngine
{
namespace Geometry
{
class ArcGISAngularUnit;
class ArcGISAreaUnit;
class ArcGISDatumTransformation;
class ArcGISEnvelope;
class ArcGISGeodesicEllipseParameters;
class ArcGISGeodesicSectorParameters;
enum class ArcGISGeodeticCurveType;
class ArcGISGeodeticDistanceResult;
class ArcGISGeometry;
enum class ArcGISGeometryExtendOptions;
enum class ArcGISGeometryOffsetType;
class ArcGISLinearUnit;
class ArcGISMultipart;
class ArcGISPoint;
class ArcGISPolygon;
class ArcGISPolyline;
class ArcGISProximityResult;
class ArcGISSpatialReference;

/// <summary>
/// Performs geometric operations such as spatial relationship tests, reprojections, shape manipulations,
/// topological query and analysis operations on <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> objects.
/// </summary>
/// <remarks>
/// Capabilities include:
/// * Create new geometries from others with <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.buffer">ArcGISGeometryEngine.buffer</see>,
///   <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.clip">ArcGISGeometryEngine.clip</see> and
///   <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.union">ArcGISGeometryEngine.union</see>
/// * Test spatial relationships between geometries such as
///   <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.intersects">ArcGISGeometryEngine.intersects</see> and
///   <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.contains">ArcGISGeometryEngine.contains</see>
/// * Find the <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.nearestCoordinate">ArcGISGeometryEngine.nearestCoordinate</see> or
///   <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.nearestVertex">ArcGISGeometryEngine.nearestVertex</see> between geometries
/// * Reproject a geometry to another <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> using
///   <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.project">ArcGISGeometryEngine.project</see>
/// * Calculate area and length using <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.area">ArcGISGeometryEngine.area</see> and
///   <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.length">ArcGISGeometryEngine.length</see>, or the geodetic equivalents
///   (<see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.bufferGeodetic">ArcGISGeometryEngine.bufferGeodetic</see>
///   and <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.lengthGeodetic">ArcGISGeometryEngine.lengthGeodetic</see>) that
///   account for the curvature of the earth
/// 
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine">ArcGISGeometryEngine</see> generally operates in two dimensions; operations do not account for z-values unless
/// documented as such for a specific method (for example <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.project">ArcGISGeometryEngine.project</see>
/// transforms z-values in some cases).
/// 
/// Geodetic methods are better suited to data that have a geographic spatial reference (see <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.isGeographic">ArcGISSpatialReference.isGeographic</see>),
/// especially for large-area, small-scale use, while planar methods are suitable to data that have a projected
/// coordinate system, especially for local, large-scale areas. Geodetic methods indicate this in the name, for example
/// GeometryEngine.bufferGeodetic(Geometry, double, LinearUnit, double, GeodeticCurveType).
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISGeometryEngine
{
public:
    #pragma region Methods
    /// <summary>
    /// Calculates the area of the given geometry.
    /// </summary>
    /// <remarks>
    /// Planar measurements of distance and area can be extremely inaccurate if using an unsuitable spatial reference.
    /// Ensure that you understand the potential for error with the geometry's spatial reference. If you need to calculate
    /// more accurate results consider using a different spatial reference, or using the geodetic equivalent,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.areaGeodetic">ArcGISGeometryEngine.areaGeodetic</see>.
    /// See <see cref="">https://developers.arcgis.com/documentation/spatial-references/</see> for more information about spatial references.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <returns>
    /// The area of the given geometry in the same units as the geometry's spatial reference system.
    /// </returns>
    /// <since>1.0.0</since>
    static double Area(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Calculates the geodesic area of the given geometry.
    /// </summary>
    /// <remarks>
    /// Supports true curves, calculating the result by densifying curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="unit">The unit of measure for the return value. If null, meters squared are assumed.</param>
    /// <param name="curveType">The type of curve to calculate.</param>
    /// <returns>
    /// The calculated geodesic area in the requested unit.
    /// </returns>
    /// <since>1.0.0</since>
    static double AreaGeodetic(const ArcGISGeometry& geometry, const ArcGISAreaUnit& unit, ArcGISGeodeticCurveType curveType);
    
    /// <summary>
    /// Fills the closed gaps between polygons using polygon boundaries and
    /// polylines as the boundary for the new polygons.
    /// </summary>
    /// <remarks>
    /// The new polygons are created in the closed empty areas bounded by
    /// the edges of the existing polygon boundaries and the new boundary
    /// polylines. The newly created polygons do not overlap any existing
    /// polygons or polylines, and the boundary of a new polygon must
    /// contain at least one edge from the polylines. Only polygons that
    /// intersect the input polylines participate in the operation, so
    /// it makes sense to prefilter the input accordingly.
    /// 
    /// The geometries in existing_boundaries must all have an area, i.e. be polygons or
    /// envelopes.
    /// 
    /// The geometries in new_boundaries must all be polylines.
    /// 
    /// The geometries in existing_boundaries and new_boundaries must have consistent spatial
    /// references.
    /// </remarks>
    /// <param name="existingBoundaries">The polygons.</param>
    /// <param name="newBoundaries">The polylines.</param>
    /// <returns>
    /// The new polygons that were created. If either
    /// existing_boundaries or new_boundaries is empty, returns an empty
    /// array. Returns null on error.
    /// </returns>
    /// <since>1.0.0</since>
    static Unreal::ArcGISImmutableArray<ArcGISPolygon> AutoComplete(const Unreal::ArcGISList<ArcGISPolygon>& existingBoundaries, const Unreal::ArcGISList<ArcGISPolyline>& newBoundaries);
    
    /// <summary>
    /// Calculates the boundary of the given geometry.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <returns>
    /// The boundary of the given geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Boundary(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Returns a geometry object that represents a buffer relative to the given geometry.
    /// </summary>
    /// <remarks>
    /// Planar measurements of distance and area can be extremely inaccurate if using an unsuitable spatial reference.
    /// Ensure that you understand the potential for error with the geometry's spatial reference. If you need to calculate
    /// more accurate results consider using a different spatial reference, or using the geodetic equivalent,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.bufferGeodetic">ArcGISGeometryEngine.bufferGeodetic</see>.
    /// See <see cref="">https://developers.arcgis.com/documentation/spatial-references/</see> for more information about spatial references.
    /// 
    /// Supports true curves as input, producing a densified curve as output where applicable.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="distance">The buffer distance for the geometry in the same units as the geometry's spatial reference system.</param>
    /// <returns>
    /// A polygon object that represents a buffer at the desired distance relative to the given geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISPolygon Buffer(const ArcGISGeometry& geometry, double distance);
    
    /// <summary>
    /// Creates and returns a buffer relative to the given geometries.
    /// </summary>
    /// <remarks>
    /// The geometries must have the same spatial reference. Planar measurements of distance and area can be extremely
    /// inaccurate if using an unsuitable spatial reference. Ensure that you understand the potential for error with the geometry's spatial reference. If you need to calculate
    /// more accurate results consider using a different spatial reference, or using the geodetic equivalent,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.bufferGeodetic">ArcGISGeometryEngine.bufferGeodetic</see>.
    /// See <see cref="">https://developers.arcgis.com/documentation/spatial-references/</see> for more information about spatial references.
    /// If unionResult is true, the output collection contains a single result. If geometries is empty, an empty array is returned.
    /// Returns null on error.
    /// 
    /// Supports true curves as input, producing a densified curve as output where applicable.
    /// </remarks>
    /// <param name="geometries">A collection of geometries.</param>
    /// <param name="distances">The distance to buffer each geometry, expressed as a <see cref="Esri::Standard::ArcGISIntermediateMutableArray">ArcGISIntermediateMutableArray</see> of double. If the size of the distances array is less than the number of geometries, the last distance value is used for the rest of geometries.</param>
    /// <param name="unionResult">Returns a single geometry that buffers all the geometries (true), or one buffer for each in the given collection (false).</param>
    /// <returns>
    /// A collection of polygons representing buffers at the defined distance(s) relative to the input geometries.
    /// </returns>
    /// <since>1.0.0</since>
    static Unreal::ArcGISImmutableArray<ArcGISPolygon> Buffer(const Unreal::ArcGISList<ArcGISGeometry>& geometries, const Unreal::ArcGISList<double>& distances, bool unionResult);
    
    /// <summary>
    /// Calculates the geodesic buffer of a given geometry.
    /// </summary>
    /// <remarks>
    /// Geodesic buffers account for the actual shape of the Earth.
    /// Distances are calculated between points on a curved surface (the geoid)
    /// as opposed to points on a flat surface (the Cartesian plane).
    /// 
    /// Negative distance can be used to create a buffer inside a <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see> or an <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see>.
    /// Using a negative buffer distance shrinks the geometry's boundary by the distance specified.
    /// Note that if the negative buffer distance is large enough, the geometry may collapse to an empty polygon.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="distance">The distance to buffer.</param>
    /// <param name="distanceUnit">The unit of measure for the distance.</param>
    /// <param name="maxDeviation">The maximum deviation between points.</param>
    /// <param name="curveType">The curve type to calculate.</param>
    /// <returns>
    /// The geodesic buffer.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISPolygon BufferGeodetic(const ArcGISGeometry& geometry, double distance, const ArcGISLinearUnit& distanceUnit, double maxDeviation, ArcGISGeodeticCurveType curveType);
    
    /// <summary>
    /// Calculates the geodesic buffer of the geometries in a given collection.
    /// </summary>
    /// <remarks>
    /// Geodesic buffers account for the actual shape of the Earth.
    /// Distances are calculated between points on a curved surface (the geoid)
    /// as opposed to points on a flat surface (the Cartesian plane).
    /// 
    /// Negative distance can be used to create buffers inside polygons.
    /// Using a negative buffer distance shrinks the polygons' boundaries by the distance specified.
    /// Note that if the negative buffer distance is large enough, polygons may collapse to empty geometries.
    /// </remarks>
    /// <param name="geometries">A collection of geometries.</param>
    /// <param name="distances">The distance to buffer each geometry, expressed as a <see cref="Esri::Standard::ArcGISIntermediateMutableArray">ArcGISIntermediateMutableArray</see> of double. If the size of the distances array is less than the number of geometries, the last distance value is used for the rest of geometries.</param>
    /// <param name="distanceUnit">The unit of measure for the distance.</param>
    /// <param name="maxDeviation">The maximum deviation between points.</param>
    /// <param name="curveType">The curve type to calculate.</param>
    /// <param name="unionResult">Return a single geometry that buffers all the geometries (true), or one buffer for each in the given collection (false).</param>
    /// <returns>
    /// A collection of polygon geometries that represent a geodesic buffer
    /// at the desired distance(s) relative to the given geometries. If
    /// 'unionResult' is true, the resulting collection contains a single
    /// polygon. If geometries is empty, returns an empty array. Returns
    /// null on error.
    /// </returns>
    /// <since>1.0.0</since>
    static Unreal::ArcGISImmutableArray<ArcGISPolygon> BufferGeodetic(const Unreal::ArcGISList<ArcGISGeometry>& geometries, const Unreal::ArcGISList<double>& distances, const ArcGISLinearUnit& distanceUnit, double maxDeviation, ArcGISGeodeticCurveType curveType, bool unionResult);
    
    /// <summary>
    /// Clips the given geometry with the envelope.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="envelope">The envelope representing the area to clip.</param>
    /// <returns>
    /// A geometry object that represents the given geometry with the desired area clipped out.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Clip(const ArcGISGeometry& geometry, const ArcGISEnvelope& envelope);
    
    /// <summary>
    /// Returns the envelope of the two given geometries.
    /// </summary>
    /// <remarks>
    /// The given geometries must have consistent spatial references.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// The maximum extents of the two given geometries, or null on error.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEnvelope CombineExtents(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Returns the envelope of geometries in the given collection.
    /// </summary>
    /// <remarks>
    /// The given geometries must have consistent spatial references.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometries">A collection of geometries.</param>
    /// <returns>
    /// The maximum extents of the geometries in the collection, or null on error.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEnvelope CombineExtents(const Unreal::ArcGISList<ArcGISGeometry>& geometries);
    
    /// <summary>
    /// Tests if geometry1 contains geometry2.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// true if geometry1 contains geometry2, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Contains(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Returns the minimum bounding geometry that completely encloses the given geometry.
    /// </summary>
    /// <param name="geometry">A geometry object.</param>
    /// <returns>
    /// The minimum bounding geometry that completely encloses the given geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry ConvexHull(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Returns the convex hull for the geometries in the given collection.
    /// </summary>
    /// <remarks>
    /// The geometries must have consistent spatial references.
    /// </remarks>
    /// <param name="geometries">A collection of geometries.</param>
    /// <param name="merge">Return a single geometry that encloses all the geometries (true), or one enclosing geometry for each in the collection (false).</param>
    /// <returns>
    /// If merge is true, returns a single convex hull that
    /// encloses all the geometries in the collection as a single geometry
    /// in an array. If merge is false, returns the minimum bounding
    /// geometry that completely encloses each of the geometries in the
    /// given collection as an array of geometries. If geometries is empty,
    /// returns an empty array. Returns null on error.
    /// </returns>
    /// <since>1.0.0</since>
    static Unreal::ArcGISImmutableArray<ArcGISGeometry> ConvexHull(const Unreal::ArcGISList<ArcGISGeometry>& geometries, bool merge);
    
    /// <summary>
    /// Return the point at the given distance along the line.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="polyline">A line.</param>
    /// <param name="distance">The distance along the line of the point to return, in the line's units.</param>
    /// <returns>
    /// the point at the given distance along the line. If
    /// 'distance' is less than or equal to zero, the point returned is
    /// coincident with the start of the line. If 'distance' is greater than
    /// or equal to the line's length, the point returned is coincident with
    /// the end of the line. If the line has multiple parts, and the
    /// distance falls exactly on a boundary between two parts, the returned
    /// point is coincident with either the end of one part or the
    /// start of the next--which is undetermined.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISPoint CreatePointAlong(const ArcGISPolyline& polyline, double distance);
    
    /// <summary>
    /// Tests if geometry1 crosses geometry2.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// true if geometry1 crosses geometry2, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Crosses(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Cut the 'geometry' <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> with the 'cutter' <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see>
    /// </summary>
    /// <remarks>
    /// The cutter and geometry's spatial references must match.
    /// 
    /// A touch event is considered to be a cut (applies when cutting an <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see>).
    /// 
    /// When cutting an <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see>, all left cuts are grouped together in the first <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see>, right cuts and coincident
    /// cuts are grouped in the second <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see>, and each undefined cut, along with any uncut parts, are output as separate Polylines.
    /// 
    /// When cutting an <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see>, all left cuts are grouped in the first <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see>, all right cuts are in the second <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see>,
    /// and each undefined cut, along with any left-over parts after cutting, are output as a separate <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see>.
    /// 
    /// If there were no cuts then an empty <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> is returned.
    /// 
    /// If the left or right cut does not exist, the returned <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> is empty for this type of cut.
    /// An undefined cut is only be produced if a left cut or right cut was produced, and there was a part left over after cutting or a cut is bounded to the left and right of the cutter.
    /// 
    /// If an error occurs, null is returned.
    /// </remarks>
    /// <param name="geometry">The input <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> to be cut.</param>
    /// <param name="cutter">The <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see> used to divide the geometry into pieces where they cross the cutter.</param>
    /// <returns>
    /// An <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> of <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see>.
    /// </returns>
    /// <since>1.0.0</since>
    static Unreal::ArcGISImmutableArray<ArcGISGeometry> Cut(const ArcGISGeometry& geometry, const ArcGISPolyline& cutter);
    
    /// <summary>
    /// Densifies the input geometry by inserting additional vertices along the geometry at an interval defined by maxSegmentLength.
    /// </summary>
    /// <remarks>
    /// Additional vertices are not inserted on segments of the input <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see>, <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see>, or <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see>
    /// that are shorter than maxSegmentLength.
    /// 
    /// Supports true curves as input, producing a densified curve as output where applicable.
    /// </remarks>
    /// <param name="geometry">A <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see>, <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see>, or <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see> geometry.</param>
    /// <param name="maxSegmentLength">The maximum distance between vertices when the input geometry is densified. The linear unit is assumed to be that of the input geometry's spatial reference (decimal degrees for a geometry with a geographic spatial reference, meters for geometry with a Mercator spatial reference, and so on). Use <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.unit">ArcGISSpatialReference.unit</see> to determine the unit used by a specific spatial reference.</param>
    /// <returns>
    /// The densified geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Densify(const ArcGISGeometry& geometry, double maxSegmentLength);
    
    /// <summary>
    /// Densifies the input geometry by creating additional vertices along the geometry, using a geodesic curve.
    /// </summary>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="maxSegmentLength">The maximum distance between vertices when the input geometry is densified, in the given linear units.</param>
    /// <param name="lengthUnit">The unit of measure for the maximum segment length. If null, meters are assumed.</param>
    /// <param name="curveType">The type of curve to calculate.</param>
    /// <returns>
    /// The geodesic densified geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry DensifyGeodetic(const ArcGISGeometry& geometry, double maxSegmentLength, const ArcGISLinearUnit& lengthUnit, ArcGISGeodeticCurveType curveType);
    
    /// <summary>
    /// Constructs the set-theoretic difference between two geometries.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">The second geometry of dimension equal to or greater than the elements of the first geometry.</param>
    /// <returns>
    /// A new geometry object that represents the difference of the two given input geometries.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Difference(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Tests if the two geometries are disjoint.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// True if the two geometries are disjoint, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Disjoint(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Measures the simple planar distance between two geometries.
    /// </summary>
    /// <remarks>
    /// Planar measurements of distance and area can be extremely inaccurate if using an unsuitable spatial reference.
    /// Ensure that you understand the potential for error with the geometry's spatial reference. If you need to calculate
    /// more accurate results consider using a different spatial reference, or using the geodetic equivalent,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.distanceGeodetic">ArcGISGeometryEngine.distanceGeodetic</see>.
    /// See <see cref="">https://developers.arcgis.com/documentation/spatial-references/</see> for more information about spatial references.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// The distance between the two geometries in the same units as the geometry's spatial reference system.
    /// </returns>
    /// <since>1.0.0</since>
    static double Distance(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Calculates the geodesic distance between the two points.
    /// </summary>
    /// <param name="point1">A point object.</param>
    /// <param name="point2">Another point object.</param>
    /// <param name="distanceUnit">The linear unit of measure for the returned results.</param>
    /// <param name="azimuthUnit">The angular unit of measure for the returned results.</param>
    /// <param name="curveType">The type of curve to calculate.</param>
    /// <returns>
    /// A structure containing the distance and the azimuth at both points for the geodesic curve that connects them.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeodeticDistanceResult DistanceGeodetic(const ArcGISPoint& point1, const ArcGISPoint& point2, const ArcGISLinearUnit& distanceUnit, const ArcGISAngularUnit& azimuthUnit, ArcGISGeodeticCurveType curveType);
    
    /// <summary>
    /// Constructs a geodesic ellipse centered on a specific point.
    /// </summary>
    /// <param name="parameters">Various parameters needed to construct the ellipse.</param>
    /// <returns>
    /// The geodesic ellipse described by the parameters.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry EllipseGeodesic(const ArcGISGeodesicEllipseParameters& parameters);
    
    /// <summary>
    /// Tests if two geometries are equal
    /// </summary>
    /// <remarks>
    /// The geometries are equal if they have the same spatial reference systems, geometry type and points.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// True if the two geometries are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Equals(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Extends a polyline using a polyline as the extender.
    /// </summary>
    /// <remarks>
    /// The output polyline has the first and last segment of each
    /// path extended to the extender if the segments can be interpolated to
    /// intersect the extender. In the case that the segments can be
    /// extended to multiple segments of the extender, the shortest
    /// extension is chosen. Only end points for paths that are not shared
    /// by the end points of other paths are extended. If the polyline
    /// cannot be extended by the input extender, then null is
    /// returned.
    /// </remarks>
    /// <param name="polyline">The polyline to be extended.</param>
    /// <param name="extender">The polyline to extend to.</param>
    /// <param name="extendOptions">The flag for the type of extend operation to perform.</param>
    /// <returns>
    /// The extended polyline. Returns null on error.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISPolyline Extend(const ArcGISPolyline& polyline, const ArcGISPolyline& extender, ArcGISGeometryExtendOptions extendOptions);
    
    /// <summary>
    /// Finds the location on the line nearest the input point, expressed as the
    /// fraction along the line's total geodesic length, if the point is
    /// within the specified distance from the closest location on the
    /// line.  The line and point must have consistent spatial references.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="line">The line to locate the point's distance along its length.</param>
    /// <param name="point">The point to locate.</param>
    /// <param name="tolerance">The maximum distance that a point is allowed to be from the line, in the units of the <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see>. If the tolerance is -1, the fraction of the closest location on the line is always returned as long as the point lies between the two ends of the polyline. If the distance from the point to the closest location on the line is greater than the tolerance, or the tolerance is -1 and the point does not lie between the two ends of the polyline, NAN is returned.</param>
    /// <returns>
    /// The length along the line nearest the input point, expressed as the fraction of the line's length between 0.0 and 1.0, or NAN if the point is outside the tolerance.
    /// </returns>
    /// <since>1.0.0</since>
    static double FractionAlong(const ArcGISPolyline& line, const ArcGISPoint& point, double tolerance);
    
    /// <summary>
    /// Generalizes the given geometry by removing vertices based on the Douglas-Poiker algorithm.
    /// </summary>
    /// <remarks>
    /// Supports true curves as input, producing a densified curve as output where applicable.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="maxDeviation">The maximum distance that the generalized geometry can deviate from the original, in the same units as the geometry's spatial reference system.</param>
    /// <param name="removeDegenerateParts">If true, degenerate parts of the resulting geometry that are undesired for drawing are removed.</param>
    /// <returns>
    /// The geometry object that represents the generalization of the input geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Generalize(const ArcGISGeometry& geometry, double maxDeviation, bool removeDegenerateParts);
    
    /// <summary>
    /// Calculates the intersection of two geometries.
    /// </summary>
    /// <remarks>
    /// The result has the same dimensionality as the lower dimensionality
    /// of the two intersecting geometries. If there is no intersection with
    /// this dimensionality, returns an empty geometry. For example, the
    /// intersection of two polygons (geometries with area, so they have
    /// dimensionality of 2) or, say, a polygon and an envelope (also an
    /// area) is a polygon. Similarly, the intersection of a polyline (a
    /// line, so dimensionality of 1) and another polyline is always a
    /// polyline. Therefore when computing the intersection of polylines,
    /// this function does not return points where they cross, but rather
    /// lines of overlap. If there are no lines of overlap, an empty
    /// polyline is returned even if the input lines cross. To obtain all
    /// intersections, irrespective of dimensionality, see
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.intersections">ArcGISGeometryEngine.intersections</see>. Returns an empty geometry if the
    /// two input geometries do not intersect. Returns null on error.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// A geometry object that represents the intersection of the given geometries.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.intersections">ArcGISGeometryEngine.intersections</seealso>
    /// <since>1.0.0</since>
    static ArcGISGeometry Intersection(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Calculates the intersection of two geometries.
    /// </summary>
    /// <remarks>
    /// The returned collection contains one geometry of each dimension for
    /// which there are intersections. For example, if both inputs are
    /// polylines, the collection contains at most two geometries: the
    /// first a multipoint containing the points at which the lines cross,
    /// and the second a polyline containing the lines of overlap. If a
    /// crossing point lies within a line of overlap, only the line of
    /// overlap is present -- the result set is not self-intersecting. If
    /// there are no crossing points or there are no lines of overlap, the
    /// respective geometry is not be present in the returned
    /// collection. If the input geometries do not intersect, the resulting
    /// collection is empty. The table below shows, for each
    /// combination of pairs of input geometry types, the types of geometry
    /// that are contained within the returned collection if there are
    /// intersections of that type.
    /// <table>
    /// <caption>Set of potential output geometry types for pairs of input geometry types</caption>
    /// <tr><th>Input type       <th>Point/Multipoint <th>Polyline             <th>Polygon/Envelope
    /// <tr><th>Point/Multipoint <td>Multipoint       <td>Multipoint           <td>Multipoint
    /// <tr><th>Polyline         <td>Multipoint       <td>Multipoint, Polyline <td>Multipoint, Polyline
    /// <tr><th>Polygon/Envelope <td>Multipoint       <td>Multipoint, Polyline <td>Multipoint, Polyline, Polygon
    /// </table>
    /// The geometries in the returned collection are sorted by ascending
    /// dimensionality, e.g. multipoint (dimension 0) then polyline
    /// (dimension 1) then polygon (dimension 2) for the intersection of two
    /// geometries with area that have intersections of those types.
    /// Returns null on error.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// A collection of geometry objects that represent the intersection of the given geometries.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.intersection">ArcGISGeometryEngine.intersection</seealso>
    /// <since>1.0.0</since>
    static Unreal::ArcGISImmutableArray<ArcGISGeometry> Intersections(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Tests if two geometries intersect.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// True if the two geometries intersect, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Intersects(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Gets a value indicating whether or not the geometry is simple.
    /// </summary>
    /// <remarks>
    /// Point geometry is always simple.
    /// 
    /// For Multi_point: there can be no point with exactly equal x and y - the tolerance is not taken into account.
    /// 
    /// For Polylines: the only condition is there can be no degenerate segments. When the polyline has no z, the
    /// degenerate segments are those that have length in xy plane less or equal the tolerance. When the polyline
    /// has z, the degenerate segments are those that are shorter than the tolerance in xy plane, and the
    /// change in z-value along the segment is less than or equal to the z-tolerance.
    /// 
    /// For Polygons:
    /// * Exterior rings are clockwise, and holes are counterclockwise
    /// * Rings can touch other rings in finite number of points
    /// * Rings can be self tangent in finite number of points
    /// * Vertices are either exactly coincident, or further than the Spatial_reference
    ///   tolerance from each other
    /// * If a vertex is not equal to any boundary point of a segment, it has to be further
    ///   than tolerance from any segment
    /// * No segment length is zero or less than tolerance
    /// * Each path contains at least three non-equal vertices
    /// * No empty paths allowed
    /// * Order of rings does not matter
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">The geometry object.</param>
    /// <returns>
    /// True if the geometry object is simple.
    /// </returns>
    /// <since>1.0.0</since>
    static bool IsSimple(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Calculates an interior point for the given polygon. This point can be used by clients to place a label for the polygon.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="polygon">A polygon object.</param>
    /// <returns>
    /// A geometry object that represents the intersection of the given geometries.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISPoint LabelPoint(const ArcGISPolygon& polygon);
    
    /// <summary>
    /// Calculates the length of the given geometry.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <returns>
    /// The length of the given geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static double Length(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Calculates the geodesic length of the geometry.
    /// </summary>
    /// <remarks>
    /// Supports true curves, calculating the result by densifying curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="lengthUnit">The unit of measure for the returned value. If null, meters are assumed.</param>
    /// <param name="curveType">The type of curve to calculate.</param>
    /// <returns>
    /// The geodesic length of the given geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static double LengthGeodetic(const ArcGISGeometry& geometry, const ArcGISLinearUnit& lengthUnit, ArcGISGeodeticCurveType curveType);
    
    /// <summary>
    /// Moves each point in the point collection by a geodesic distance.
    /// </summary>
    /// <remarks>
    /// There must be the same spatial reference on each point in the input <see cref="Esri::Standard::ArcGISIntermediateMutableArray">ArcGISIntermediateMutableArray</see> of points.
    /// The returned collection is in the same order as the input, but with new points at their destination locations.
    /// Specifying a negative distance moves points in the opposite direction from azimuth.
    /// </remarks>
    /// <param name="pointCollection">A <see cref="Esri::Standard::ArcGISIntermediateMutableArray">ArcGISIntermediateMutableArray</see> of <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see> geometries. Contents of the <see cref="Esri::Standard::ArcGISIntermediateMutableArray">ArcGISIntermediateMutableArray</see> are copied.</param>
    /// <param name="distance">The distance to move the points.</param>
    /// <param name="distanceUnit">The unit of measure for distance. If null, meters are assumed.</param>
    /// <param name="azimuth">The azimuth angle of the direction for the points.</param>
    /// <param name="azimuthUnit">The angular unit of measure for azimuth. If null, degrees are assumed.</param>
    /// <param name="curveType">The type of curve to calculate.</param>
    /// <returns>
    /// A new collection of points moved by the given distance from the input collection.
    /// </returns>
    /// <since>1.0.0</since>
    static Unreal::ArcGISImmutableArray<ArcGISPoint> MoveGeodetic(const Unreal::ArcGISList<ArcGISPoint>& pointCollection, double distance, const ArcGISLinearUnit& distanceUnit, double azimuth, const ArcGISAngularUnit& azimuthUnit, ArcGISGeodeticCurveType curveType);
    
    /// <summary>
    /// Determines the nearest point in the input geometry to the input point using a simple planar measurement.
    /// </summary>
    /// <remarks>
    /// Input geometry of type <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see> is not supported. To find the nearest coordinate on
    /// an <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see>, convert it to a <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see> first.
    /// 
    /// If the specified geometry is a polyline or polygon the nearest coordinate is the closest
    /// point in a segment that comprises geometry; it may not necessarily be the closest
    /// vertex of a segment. If you want to obtain the closest vertex in the polyline or
    /// polygon use the <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.nearestVertex">ArcGISGeometryEngine.nearestVertex</see> method instead.
    /// 
    /// Planar measurements of distance and area can be extremely inaccurate if using an unsuitable spatial reference.
    /// Ensure that you understand the potential for error with the geometry's spatial reference. If you need to calculate
    /// more accurate results consider using a different spatial reference, or using the geodetic equivalent,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.nearestCoordinateGeodetic">ArcGISGeometryEngine.nearestCoordinateGeodetic</see>.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="point">The point of interest.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISProximityResult">ArcGISProximityResult</see> containing the results of the operation. This is null if the input geometry is empty.
    /// <see cref="Esri::GameEngine::Geometry::ArcGISProximityResult.distance">ArcGISProximityResult.distance</see> is zero if the point lies inside an input polygon, polyline, or envelope.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISProximityResult NearestCoordinate(const ArcGISGeometry& geometry, const ArcGISPoint& point);
    
    /// <summary>
    /// Determines the nearest point in the input geometry to the input point, by using a shape preserving geodesic approximation of the input geometry.
    /// </summary>
    /// <remarks>
    /// All geometry types are supported for the geometry parameter. Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry object on which to calculate the nearest coordinate to the point parameter.</param>
    /// <param name="point">The point from which to calculate the nearest coordinate on the geometry parameter.</param>
    /// <param name="maxDeviation">The maximum distance that the geodesic geometry can deviate from the original, in the units of the deviationUnit parameter.</param>
    /// <param name="deviationUnit">The unit of measure for the maxDeviation parameter. If null, the units of maxDeviation are assumed to be meters.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISProximityResult">ArcGISProximityResult</see> containing the results of the operation, where the <see cref="Esri::GameEngine::Geometry::ArcGISProximityResult.distance">ArcGISProximityResult.distance</see> is
    /// returned in meters. Returns null if the input geometry is empty. <see cref="Esri::GameEngine::Geometry::ArcGISProximityResult.distance">ArcGISProximityResult.distance</see> is zero if the
    /// point lies inside an input polygon, polyline, or envelope.
    /// </returns>
    /// GeometryEngine.nearestCoordinate(Geometry
    /// Point)
    /// <since>1.0.0</since>
    static ArcGISProximityResult NearestCoordinateGeodetic(const ArcGISGeometry& geometry, const ArcGISPoint& point, double maxDeviation, const ArcGISLinearUnit& deviationUnit);
    
    /// <summary>
    /// Returns a <see cref="Esri::GameEngine::Geometry::ArcGISProximityResult">ArcGISProximityResult</see> that describes the nearest vertex in the input geometry to the input point.
    /// </summary>
    /// <remarks>
    /// Input geometry of type <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see> is not supported. To find the nearest vertex on an <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see>, convert it to a <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see> first.
    /// 
    /// Input geometries with true curves (where <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true) are supported, although curve
    /// segments do not affect the return value.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="point">The point of interest.</param>
    /// <returns>
    /// A struct containing the results of the operation.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISProximityResult NearestVertex(const ArcGISGeometry& geometry, const ArcGISPoint& point);
    
    /// <summary>
    /// Folds the geometry into a range of 360 degrees.  This may be necessary when wrap around is enabled on the map.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <returns>
    /// The normalized geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry NormalizeCentralMeridian(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Creates an offset version of the input geometry.
    /// </summary>
    /// <remarks>
    /// The offset operation creates a geometry that is a constant distance from the input geometry.  If is similar to buffering, but produces
    /// a one sided result.  If distance > 0, then the offset geometry is constructed to the right of the input geometry, otherwise it is constructed
    /// to the left.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="distance">The offset distance for the new geometry.</param>
    /// <param name="offsetType">The offset type the resulting geometry.</param>
    /// <param name="bevelRatio">The ratio used to produce a bevel join instead of a miter join (used only when the offset type is Miter).</param>
    /// <param name="flattenError">The maximum distance of the resulting segments compared to the true circular arc (used only when the offset type if round).</param>
    /// <returns>
    /// The offset geometry object.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Offset(const ArcGISGeometry& geometry, double distance, ArcGISGeometryOffsetType offsetType, double bevelRatio, double flattenError);
    
    /// <summary>
    /// Tests if two geometries overlap.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// True if the two geometries overlap, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Overlaps(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Projects the given geometry from its current spatial reference system into the given spatial reference system.
    /// </summary>
    /// <remarks>
    /// A default best-choice <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation">ArcGISDatumTransformation</see> is applied to the project operation. To control the specific
    /// transformation used, use the <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.project">ArcGISGeometryEngine.project</see>
    /// overload.
    /// 
    /// If the geometry parameter has z-values then those z-values are also be transformed, providing the
    /// SpatialReference of that geometry, and the spatialReference parameter, both have a vertical coordinate
    /// system set.
    /// 
    /// Supports true curves. Projecting curves located at poles and coordinate system horizons using ArcGIS Maps
    /// API may give results that differ slightly from other ArcGIS software. This is because it uses a different
    /// geometry projection function.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="spatialReference">The target spatial reference system.</param>
    /// <returns>
    /// The geometry projected into the given SpatialReference. If the input geometry has a null SpatialReference,
    /// no projection occurs; instead, an identical geometry with the given SpatialReference is returned.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Project(const ArcGISGeometry& geometry, const ArcGISSpatialReference& spatialReference);
    
    /// <summary>
    /// Projects the given geometry from its current spatial reference system into the given output spatial reference system, applying the datum transformation provided.
    /// </summary>
    /// <remarks>
    /// Use this overload to project a geometry if the difference between the input geometry's SpatialReference
    /// and the outputSpatialReference involves a change of datum, and you do not wish to use the default datum
    /// transformation used by <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.project">ArcGISGeometryEngine.project</see>.
    /// 
    /// Supports true curves. Projecting curves located at poles and coordinate system horizons using the ArcGIS
    /// Maps API may give results that differ slightly from other ArcGIS software. This is because it uses a
    /// different geometry projection function.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <param name="outputSpatialReference">The spatial reference system to project to.</param>
    /// <param name="datumTransformation">The datum transformation that describes how coordinates are converted from one coordinate system to another.</param>
    /// <returns>
    /// The geometry projected into the given SpatialReference. If the input geometry has a null SpatialReference,
    /// no projection occurs; instead, an identical geometry with the given SpatialReference is returned.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Project(const ArcGISGeometry& geometry, const ArcGISSpatialReference& outputSpatialReference, const ArcGISDatumTransformation& datumTransformation);
    
    /// <summary>
    /// Test if the two geometries are related by the given relation.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <param name="relation">The DE-9IM string to be evaluated</param>
    /// <returns>
    /// True if the two geometries have the given relationship, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Relate(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2, const FString& relation);
    
    /// <summary>
    /// Return a copy of the given geometry with its m-values removed.
    /// </summary>
    /// <remarks>
    /// The resulting geometry has <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasM">ArcGISGeometry.hasM</see> false. If the given geometry
    /// has no m-values, a new object to the same underlying geometry is
    /// returned so this is an inexpensive call.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry.</param>
    /// <returns>
    /// A copy of the given geometry with its m-values removed.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry RemoveM(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Return a copy of the given geometry with its z-coordinate removed.
    /// </summary>
    /// <remarks>
    /// The resulting geometry has <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasZ">ArcGISGeometry.hasZ</see> false. If the given geometry
    /// has no z-coordinates, a new object to the same underlying geometry is
    /// returned so this is an inexpensive call.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry.</param>
    /// <returns>
    /// A copy of the given geometry with its z-coordinates removed.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry RemoveZ(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Return a copy of the given geometry with its z-coordinates and m-values removed.
    /// </summary>
    /// <remarks>
    /// The resulting geometry has both <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasZ">ArcGISGeometry.hasZ</see> and <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasM">ArcGISGeometry.hasM</see> false. If the
    /// given geometry has no z-coordinates and no m-values, a new object to
    /// the same underlying geometry is returned so this is an inexpensive
    /// call.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry.</param>
    /// <returns>
    /// A copy of the given geometry with both its z-coordinates and m-values removed.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry RemoveZAndM(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Reshape polygons or polylines with a single path polyline.
    /// </summary>
    /// <remarks>
    /// Performs the reshape operation on a polygon or polyline using a
    /// single path polyline as the reshaper. The output geometry takes the
    /// shape of the Multi_path where it first intersects the reshaper to
    /// the last intersection. The first and last intersection points of the
    /// reshaper are chosen closest to the end points of the reshaper in the
    /// case that multiple intersections are found. For polygons, only
    /// individual paths can be reshaped. However, polylines can be reshaped
    /// across paths. If the geometry cannot be reshaped by the input
    /// reshaper, then null is returned.
    /// </remarks>
    /// <param name="geometry">The polygon or polyline to be reshaped.</param>
    /// <param name="reshaper">The single path polyline reshaper</param>
    /// <returns>
    /// The reshaped polygon or polyline. Returns null on error.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISMultipart Reshape(const ArcGISMultipart& geometry, const ArcGISPolyline& reshaper);
    
    /// <summary>
    /// Constructs a geodesic sector defined by a geodesic arc and 2 radii.
    /// </summary>
    /// <param name="parameters">Specifies the parameters for constructing the sector.</param>
    /// <returns>
    /// A geometry representing the geodesic sector.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry SectorGeodesic(const ArcGISGeodesicSectorParameters& parameters);
    
    /// <summary>
    /// Return a copy of a geometry with the supplied m-value.
    /// </summary>
    /// <remarks>
    /// If the given geometry already has m-values, they are replaced
    /// within the resulting geometry by the supplied value. The resulting
    /// geometry has <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasM">ArcGISGeometry.hasM</see> true.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry.</param>
    /// <param name="m">The m-value.</param>
    /// <returns>
    /// A copy of the given geometry with its m-values set to the supplied value.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry SetM(const ArcGISGeometry& geometry, double m);
    
    /// <summary>
    /// Return a copy of a geometry with the supplied z-coordinate.
    /// </summary>
    /// <remarks>
    /// If the given geometry already has z-coordinates, they are replaced
    /// within the resulting geometry by the supplied value. The resulting
    /// geometry has <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasZ">ArcGISGeometry.hasZ</see> true.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry.</param>
    /// <param name="z">The z-coordinate.</param>
    /// <returns>
    /// A copy of the given geometry with its z-coordinates set to the supplied value.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry SetZ(const ArcGISGeometry& geometry, double z);
    
    /// <summary>
    /// Return a copy of a geometry with the supplied z-coordinate and m-value.
    /// </summary>
    /// <remarks>
    /// If the given geometry already has z-coordinates or m-values, they are
    /// replaced in the resulting geometry by the supplied values.
    /// The resulting geometry has both <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasZ">ArcGISGeometry.hasZ</see> and <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasM">ArcGISGeometry.hasM</see> true.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry.</param>
    /// <param name="z">The z-coordinate.</param>
    /// <param name="m">The m-value.</param>
    /// <returns>
    /// A copy of the given geometry with its z-coordinates and m-values set to the supplied values.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry SetZAndM(const ArcGISGeometry& geometry, double z, double m);
    
    /// <summary>
    /// Simplifies the given geometry to make it topologically consistent according to its geometry type.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry">A geometry object.</param>
    /// <returns>
    /// The simplified geometry.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Simplify(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Calculates the symmetric difference (exclusive or) of the two geometries.
    /// </summary>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// The symmetric difference of the two geometries.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry SymmetricDifference(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Test if the two geometries touch on their borders.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// True if the two geometries touch, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Touches(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Calculates the union of the two geometries.
    /// </summary>
    /// <remarks>
    /// If the two geometries have different dimensionality, returns a copy
    /// of the geometry with the higher dimensionality. E.g. if given a
    /// polygon and a point, returns the polygon.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// The union of the two geometries.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Union(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    
    /// <summary>
    /// Calculates the union of a collection of geometries
    /// </summary>
    /// <remarks>
    /// There must be at least one geometry in the given collection.
    /// The geometries must have consistent spatial references.
    /// If the collection contains geometries of differing dimensionality,
    /// returns the union of the subset of geometries with the highest
    /// dimensionality. E.g. given a collection of polygons, polylines and
    /// points, returns the union of the polygons.
    /// 
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometries">A collection of geometries.</param>
    /// <returns>
    /// The union of all the geometries in the given collection. Returns null on error.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISGeometry Union(const Unreal::ArcGISList<ArcGISGeometry>& geometries);
    
    /// <summary>
    /// Tests if geometry1 is within geometry2.
    /// </summary>
    /// <remarks>
    /// Supports true curves.
    /// </remarks>
    /// <param name="geometry1">A geometry object.</param>
    /// <param name="geometry2">Another geometry object.</param>
    /// <returns>
    /// True if geometry1 is within geometry2, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    static bool Within(const ArcGISGeometry& geometry1, const ArcGISGeometry& geometry2);
    #pragma endregion Methods
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri