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
enum class ArcGISGeometryType;

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
class ARCGISMAPSSDK_API ArcGISGeometryInternal
{
    friend class ArcGISGeometryInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The type of geometry.
    /// </summary>
    /// <remarks>
    /// The geometry type for a specific geometry. Returns <see cref="Esri::GameEngine::Geometry::ArcGISGeometryType.unknown">ArcGISGeometryType.unknown</see> if an error occurs.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryType">ArcGISGeometryType</seealso>
    /// <since>1.0.0</since>
    static ArcGISGeometryType GetObjectType(ArcGISGeometry* self);
    #pragma endregion Properties
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri