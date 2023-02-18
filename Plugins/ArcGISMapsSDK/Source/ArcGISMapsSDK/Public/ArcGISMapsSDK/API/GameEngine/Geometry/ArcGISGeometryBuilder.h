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
class ArcGISEnvelope;
class ArcGISGeometry;
enum class ArcGISGeometryType;
class ArcGISSpatialReference;

/// <summary>
/// A geometry builder object
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISGeometryBuilder
{
    friend class ArcGISGeometryBuilderInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The extent for the geometry in the builder.
    /// </summary>
    /// <remarks>
    /// The extent for the geometry in the builder which is a envelope and contains the same spatial reference
    /// as the input geometry.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</seealso>
    /// <since>1.0.0</since>
    ArcGISEnvelope GetExtent() const;
    
    /// <summary>
    /// A value indicating whether the geometry builder currently contains any curve segments.
    /// </summary>
    /// <remarks>
    /// The ArcGIS Platform supports polygon and polyline geometries that contain curve segments (where <see cref="Esri::GameEngine::Geometry::ArcGISSegment.isCurve">ArcGISSegment.isCurve</see> is true, sometimes known as
    /// true curves or nonlinear segments). Curves may be present in certain types of data - for example Mobile Map
    /// Packages (MMPKs), or geometry JSON.
    /// 
    /// Prior to v100.12, only <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see> instances were supported when creating new geometries using a
    /// <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder">ArcGISMultipartBuilder</see>. Attempting to add curve geometries to a <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder">ArcGISMultipartBuilder</see> would cause an error.
    /// 
    /// From v100.12, you can use curves in a <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder">ArcGISMultipartBuilder</see>. New segment types <see cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</see> and
    /// <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see> represent different types of curve that can be added to polygon and polyline
    /// geometries.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISMutablePart.hasCurves">ArcGISMutablePart.hasCurves</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSegment.isCurve">ArcGISSegment.isCurve</seealso>
    /// <since>1.0.0</since>
    bool GetHasCurves() const;
    
    /// <summary>
    /// A value indicating if the geometry builder has M.
    /// </summary>
    /// <remarks>
    /// If an error occurs false is returned.
    /// M is a vertex value that is stored with the geometry builder.
    /// </remarks>
    /// <since>1.0.0</since>
    bool GetHasM() const;
    
    /// <summary>
    /// A value indicating if the geometry builder has Z.
    /// </summary>
    /// <remarks>
    /// If an error occurs false is returned.
    /// Z typically represent elevations or heights.
    /// </remarks>
    /// <since>1.0.0</since>
    bool GetHasZ() const;
    
    /// <summary>
    /// Check if a geometry builder is empty or not.
    /// </summary>
    /// <remarks>
    /// Only check the geometry builder to see if it is empty. Does not check the spatial reference. Returns true if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    bool GetIsEmpty() const;
    
    /// <summary>
    /// Check if a geometry builder contains sufficient points to show a valid graphical sketch.
    /// </summary>
    /// <remarks>
    /// This can be used as an initial lightweight check to see if the current state of a builder produces a
    /// non-empty geometry; for example, it may be used to enable or disable functionality in an editing user
    /// interface. The exact requirements vary depending on the type of geometry produced by the builder:
    /// * A <see cref="Esri::GameEngine::Geometry::ArcGISPointBuilder">ArcGISPointBuilder</see> must contain non-NaN x,y coordinates
    /// * A <see cref="Esri::GameEngine::Geometry::ArcGISMultipointBuilder">ArcGISMultipointBuilder</see> must contain at least one valid Point
    /// * An <see cref="Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder">ArcGISEnvelopeBuilder</see> must contain non-NaN minimum and maximum x,y coordinates
    /// * A <see cref="Esri::GameEngine::Geometry::ArcGISPolylineBuilder">ArcGISPolylineBuilder</see> must contain at least one <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart">ArcGISMutablePart</see>. Each <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart">ArcGISMutablePart</see> it contains must have:
    ///   * At least two valid points, or
    ///   * At least one <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> where <see cref="Esri::GameEngine::Geometry::ArcGISSegment.isCurve">ArcGISSegment.isCurve</see> is true
    /// * A <see cref="Esri::GameEngine::Geometry::ArcGISPolygonBuilder">ArcGISPolygonBuilder</see> must contain at least one <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart">ArcGISMutablePart</see>. Each <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart">ArcGISMutablePart</see> it contains must have:
    ///   * At least three valid points, or
    ///   * At least one <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> where <see cref="Esri::GameEngine::Geometry::ArcGISSegment.isCurve">ArcGISSegment.isCurve</see> is true
    /// 
    /// Note that this is not equivalent to topological simplicity, which is enforced by <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.simplify">ArcGISGeometryEngine.simplify</see>
    /// and checked using <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.isSimple">ArcGISGeometryEngine.isSimple</see>. Geometries must be topologically simple to be
    /// successfully saved in a geodatabase or used in some service operations.
    /// 
    /// Does not check the spatial reference. Returns false if an error occurs.
    /// 
    /// Prior to v100.8, only one part of a multipart polygon or polyline was required to have the minimum number
    /// (2 for a polyline, 3 for a polygon) of points, and only <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see> instances were supported in
    /// builders.
    /// 
    /// Prior to v100.12, a <see cref="Esri::GameEngine::Geometry::ArcGISPolygonBuilder">ArcGISPolygonBuilder</see> required at least three valid Points in each <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart">ArcGISMutablePart</see>, and at
    /// least one part.
    /// </remarks>
    /// <since>1.0.0</since>
    bool GetIsSketchValid() const;
    
    /// <summary>
    /// The spatial reference for the geometry.
    /// </summary>
    /// <remarks>
    /// If the geometry does not have a spatial reference null is returned.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    ArcGISSpatialReference GetSpatialReference() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Creates a geometry builder using the geometry provided as a starting
    /// point for further modifications.
    /// </summary>
    /// <remarks>
    /// Prior to v100.12, only geometries without curves could be used; passing in a geometry where
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true would throw an exception.
    /// 
    /// From v100.12, geometries with curves are supported.
    /// </remarks>
    /// <param name="geometry">The geometry to use as the starting point for further modifications.</param>
    /// <returns>
    /// A new geometry builder.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <since>1.0.0</since>
    static ArcGISGeometryBuilder Create(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Creates a geometry builder which builds geometries of the given
    /// type.
    /// </summary>
    /// <param name="geometryType">The builder's geometry type.</param>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <returns>
    /// A new geometry builder.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <since>1.0.0</since>
    static ArcGISGeometryBuilder Create(ArcGISGeometryType geometryType, const ArcGISSpatialReference& spatialReference);
    
    /// <summary>
    /// Replaces the geometry in the builder with the new geometry.
    /// </summary>
    /// <remarks>
    /// This does not update the spatial reference
    /// of the builder. If the geometry is null, the builder is cleared.
    /// 
    /// Prior to v100.12, only geometries without curves could be used; passing in a geometry where
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true would throw an exception.
    /// 
    /// From v100.12, geometries with curves are supported.
    /// </remarks>
    /// <param name="geometry">The geometry object.</param>
    /// <since>1.0.0</since>
    void ReplaceGeometry(const ArcGISGeometry& geometry);
    
    /// <summary>
    /// Creates a geometry with the values in the geometry builder.
    /// </summary>
    /// <returns>
    /// A geometry. This is passed to geometry functions.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISGeometry ToGeometry() const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISGeometryBuilder(void* handle);
    ArcGISGeometryBuilder(const ArcGISGeometryBuilder&) = delete;
    ArcGISGeometryBuilder(ArcGISGeometryBuilder&& other) noexcept;
    ArcGISGeometryBuilder() = default;
    ~ArcGISGeometryBuilder();
    
    ArcGISGeometryBuilder& operator=(const ArcGISGeometryBuilder&) = delete;
    ArcGISGeometryBuilder& operator=(ArcGISGeometryBuilder&& other) noexcept;
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