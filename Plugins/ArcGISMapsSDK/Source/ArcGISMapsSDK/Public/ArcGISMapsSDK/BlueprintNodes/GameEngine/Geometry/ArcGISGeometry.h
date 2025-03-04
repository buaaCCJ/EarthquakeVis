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

#include "ArcGISGeometry.generated.h"

class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISGeometry;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Base class for all classes that represent geometric shapes.
/// </summary>
/// <remarks>
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> is the base class for two-dimensional (x,y) or three-dimensional
/// (x,y,z) geometries. Objects that inherit from the <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> class may also include a
/// measure (m-value) for each vertex. The <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> class provides functionality common
/// to all types of geometry. <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>, <see cref="Esri::GameEngine::Geometry::ArcGISMultipoint">ArcGISMultipoint</see>, <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see>, <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see>, and
/// <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see> all inherit from <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> and represent different types of shapes.
/// 
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> represents real-world objects by defining a shape at a specific geographic location.
/// It is used throughout this API to represent the shapes of features and graphics, layer extents,
/// viewpoints, and GPS locations. It is also used, for example, to define inputs and outputs for
/// spatial analysis and geoprocessing operations and to measure distances and areas.
/// 
/// All types of geometry:
/// * Have a <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> indicating the coordinate system used by its coordinates
/// * Can be empty, indicating that they have no specific location or shape
/// * May have z-values and/or m-values to define elevation and measures respectively
/// * Can be converted to and from JSON to be persisted or to be exchanged directly with
/// REST services
/// 
/// Immutability
/// Most geometries are created and not changed for their lifetime. Examples include features
/// created to be stored in a geodatabase or read from a non-editable layer, and features returned
/// from tasks such as a spatial query, geocode operation, network trace, or geoprocessing task.
/// Immutable geometries (geometries that cannot be changed) offer some important benefits to
/// your app. They are inherently thread-safe, help prevent inadvertent changes, and allow for
/// certain performance optimizations.
/// 
/// Instead of changing the properties of existing geometries, you can create and update geometries
/// using the various subclasses of <see cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder">ArcGISGeometryBuilder</see> (for example, <see cref="Esri::GameEngine::Geometry::ArcGISPolygonBuilder">ArcGISPolygonBuilder</see>), which can
/// represent the state of a geometry under construction while allowing modifications, thus enabling
/// editing workflows.
/// 
/// Additionally, <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine">ArcGISGeometryEngine</see> offers a range of topological and spatial transformations that
/// read the content of existing geometries and create new geometries, for example, project, buffer,
/// union, and so on. Relational tests such as intersects and overlaps are also available on
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine">ArcGISGeometryEngine</see>.
/// 
/// Coordinate units
/// The coordinates that define a geometry are only meaningful in the context of the geometry's
/// <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see>. The vertices and spatial reference together allow your app to translate a
/// real-world object from its location on the Earth to its location on your map or scene.
/// 
/// In some cases, a geometry's spatial reference may not be set. For example, a <see cref="">Graphic</see> that
/// does not have a spatial reference is drawn using the same spatial reference as the <see cref="">MapView</see>
/// to which it was added. If the coordinates are in a different spatial reference, the graphics may
/// not display in the correct location, or at all.
/// 
/// When using <see cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder">ArcGISGeometryBuilder</see> to create a <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see> or <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see> from a collection of
/// <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>, you don't need to set the spatial reference of every point before you add it to
/// the builder, as it is assigned the spatial reference of the builder itself. In most other
/// cases, such as when using a geometry in geometry operations or when editing a feature table,
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.spatialReference">ArcGISGeometry.spatialReference</see> must be set.
/// 
/// Spatial reference and projection
/// Changing the coordinates of a geometry to have the same shape and location represented using a
/// different <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> is known as "projection" or sometimes as "reprojection". Because
/// geometries are immutable, they do not have any member methods that project, transform, or
/// otherwise modify their content.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine">ArcGISGeometryEngine</seealso>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder">ArcGISGeometryBuilder</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISGeometry :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeometry")
    /// <summary>
    /// True if this geometry contains curve segments; false otherwise.
    /// </summary>
    /// <remarks>
    /// The ArcGIS Platform supports polygon and polyline geometries that contain curve segments (where 
    /// <see cref="Esri::GameEngine::Geometry::ArcGISSegment.isCurve">ArcGISSegment.isCurve</see> is true, sometimes known as true curves or nonlinear segments). Curves may be present
    /// in certain types of data - for example Mobile Map Packages (MMPK) or geometry JSON. When connecting to
    /// ArcGIS feature services that <see cref="support curves">ArcGISFeatureServiceInfo.supportsTrueCurve</see>, ArcGIS
    /// Maps API retrieves densified versions of curve feature geometries by default.
    /// 
    /// If a polygon or polyline geometry contains curve segments, this property returns true. Prior to v100.12,
    /// it was not possible to access curve segments, and only <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see> instances would be returned
    /// when iterating through the segments in a <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see> or <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see> object, irrespective of this property.
    /// 
    /// From v100.12, you can use curve segments when using a <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder">ArcGISMultipartBuilder</see> to create or edit polygon and
    /// polyline geometries, and also get curve segments when iterating through the segments of existing
    /// <see cref="Esri::GameEngine::Geometry::ArcGISMultipart">ArcGISMultipart</see> geometries when this property returns true. You can also choose to return true curves from
    /// feature services by using <see cref="">ArcGISRuntimeEnvironment.serviceCurveGeometryMode</see>.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISImmutablePart.hasCurves">ArcGISImmutablePart.hasCurves</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSegment.isCurve">ArcGISSegment.isCurve</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</seealso>
    /// <since>1.0.0</since>
    bool GetHasCurves();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeometry")
    /// <summary>
    /// A value indicating if the geometry has M.
    /// </summary>
    /// <remarks>
    /// If an error occurs false is returned.
    /// M is a vertex value that is stored with the geometry.
    /// </remarks>
    /// <since>1.0.0</since>
    bool GetHasM();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeometry")
    /// <summary>
    /// A value indicating if the geometry has Z.
    /// </summary>
    /// <remarks>
    /// If an error occurs false is returned.
    /// Z typically represent elevations or heights.
    /// </remarks>
    /// <since>1.0.0</since>
    bool GetHasZ();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeometry")
    /// <summary>
    /// Check if a geometry is empty or not.
    /// </summary>
    /// <remarks>
    /// Only check the geometry to see if it is empty. Does not check the spatial reference. Returns true if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    bool GetIsEmpty();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeometry")
    /// <summary>
    /// The spatial reference for the geometry.
    /// </summary>
    /// <remarks>
    /// If the geometry does not have a spatial reference null is returned.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeometry")
    /// <summary>
    /// Tests if this object is equal to a second <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> object.
    /// </summary>
    /// <param name="right">The second geometry.</param>
    /// <returns>
    /// True if the comparison succeeds and the objects are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(UArcGISGeometry* right) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeometry")
    /// <summary>
    /// Check if two geometries are equal to within some tolerance.
    /// </summary>
    /// <remarks>
    /// This function performs a lightweight comparison of two geometries,
    /// such as might be useful when writing test code.
    /// It uses the tolerance to compare each of x, y, and any other values
    /// the geometries possess (such as z or m) independently in the manner:
    /// abs(value1 - value2) <= tolerance.
    /// Returns true if the difference of each is within the tolerance and
    /// all other properties of the geometries are exactly equal (spatial
    /// reference, vertex count, etc.).
    /// A single tolerance is used even if the units for the horizontal
    /// coordinates and other values differ, e.g horizontal coordinates in
    /// degrees and vertical coordinates in meters. This function does not
    /// respect modular arithmetic of spatial references which wrap around,
    /// so longitudes of -180 and +180 degrees are considered to differ by
    /// 360 degrees.
    /// Returns false if an error occurs.
    /// For topological equality, use relational operators
    /// instead of this function. See <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.equals">ArcGISGeometryEngine.equals</see>.
    /// </remarks>
    /// <param name="right">The second geometry.</param>
    /// <param name="tolerance">The tolerance.</param>
    /// <returns>
    /// True if the geometries are equal, within the tolerance, otherwise false.
    /// </returns>
    /// <since>1.0.0</since>
    bool EqualsWithTolerance(UArcGISGeometry* right, double tolerance) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeometry")
    /// <summary>
    /// Creates a geometry from an ArcGIS JSON geometry representation.
    /// </summary>
    /// <remarks>
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> can be serialized and de-serialized to and from JSON. The
    /// <see cref="ArcGIS REST API documentation">https://developers.arcgis.com/documentation/common-data-types/geometry-objects.htm</see>
    /// describes the JSON representation of geometry objects.
    /// You can use this encoding and decoding mechanism to exchange geometries with REST Web services
    /// or to store them in text files.
    /// </remarks>
    /// <param name="inputJSON">JSON representation of geometry.</param>
    /// <param name="spatialReference">The geometry's spatial reference.</param>
    /// <returns>
    /// Geometry converted from a JSON String.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</seealso>
    /// <since>1.0.0</since>
    static UArcGISGeometry* FromJSONWithSpatialReference(FString inputJSON, UArcGISSpatialReference* spatialReference);
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISGeometry> APIObject;
};