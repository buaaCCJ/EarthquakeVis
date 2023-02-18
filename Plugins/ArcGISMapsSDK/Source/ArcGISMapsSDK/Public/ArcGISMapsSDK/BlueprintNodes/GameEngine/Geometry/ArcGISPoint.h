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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometry.h"

#include "ArcGISPoint.generated.h"

class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPoint;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A location defined by x and y (and optionally z) coordinates.
/// </summary>
/// <remarks>
/// <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see> geometries represent discrete locations or entities, such as a geocoded house
/// address, the location of a water meter in a water utility network, or a moving vehicle.
/// Larger geographic entities (such as cities) are often represented as points on small-scale
/// maps. Points can be used as the geometry of features and graphics and are often used to
/// construct more complex geometries. They are also used in a <see cref="">Viewpoint</see> to define the
/// center of the display.
/// 
/// Points store a single set of x,y coordinates that define a location (longitude and latitude,
/// for example), and a <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see>. Points can optionally have a z-value (commonly
/// used to describe elevation or altitude) and an m-value (commonly used for measurement
/// relative to the geometry).
/// 
/// For points defined with a geographic spatial reference, the x-coordinate is the longitude (east
/// or west), and the y-coordinate is the latitude (north or south). When geographic coordinates
/// are represented in strings, points are generally written using the form "(latitude, longitude)",
/// where the y-coordinate comes before the x-coordinate. Latitude values south of the equator
/// and longitude values west of the prime meridian are expressed as negative numbers.
/// 
/// Use <see cref="Esri::GameEngine::Geometry::ArcGISCoordinateFormatter">ArcGISCoordinateFormatter</see> to convert a latitude and longitude formatted string directly
/// to a <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>. The coordinate formatter can also return a latitude and longitude formatted
/// string from an existing <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>. Other coordinate notations, such as Military Grid Reference
/// System (MGRS) and United States National Grid (USNG) are also supported.
/// 
/// Points are based upon the parent <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> class. The geometry class is
/// immutable which means that you can not change its shape once it is created. If you need to
/// modify a point once it has been created, use the <see cref="Esri::GameEngine::Geometry::ArcGISPointBuilder">ArcGISPointBuilder</see> class
/// instead. The <see cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.toGeometry">ArcGISGeometryBuilder.toGeometry</see> method provides you with the
/// point object.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISPoint :
    public UArcGISGeometry
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// Creates a point with an x, y and a null spatial reference.
    /// </summary>
    /// <param name="x">The x-coordinate for the point.</param>
    /// <param name="y">The y-coordinate for the point.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    static UArcGISPoint* CreateArcGISPointWithXY(double x, double y);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// Creates a point with an x, y, z and a null spatial reference.
    /// </summary>
    /// <remarks>
    /// The minimum z-value is -6,356,752 meters, which is the approximate radius of the earth (the WGS 84 datum semi-minor axis).
    /// The maximum z-value is 55,000,000 meters.
    /// </remarks>
    /// <param name="x">The x-coordinate for the point.</param>
    /// <param name="y">The y-coordinate for the point.</param>
    /// <param name="z">The z-coordinate for the point.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    static UArcGISPoint* CreateArcGISPointWithXYZ(double x, double y, double z);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// Creates a point with an x, y, z and spatial reference.
    /// </summary>
    /// <remarks>
    /// The minimum z-value is -6,356,752 meters, which is the approximate radius of the earth (the WGS 84 datum semi-minor axis).
    /// The maximum z-value is 55,000,000 meters.
    /// </remarks>
    /// <param name="x">The x-coordinate for the point.</param>
    /// <param name="y">The y-coordinate for the point.</param>
    /// <param name="z">The z-coordinate for the point.</param>
    /// <param name="spatialReference">The spatial reference for the point.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    static UArcGISPoint* CreateArcGISPointWithXYZSpatialReference(double x, double y, double z, UArcGISSpatialReference* spatialReference);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// Creates a point with an x, y and a spatial reference.
    /// </summary>
    /// <remarks>
    /// Creates a point with x, y for the coordinates and a spatial reference.
    /// </remarks>
    /// <param name="x">The x-coordinate for the point.</param>
    /// <param name="y">The y-coordinate for the point.</param>
    /// <param name="spatialReference">The spatial reference for the point.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    static UArcGISPoint* CreateArcGISPointWithXYSpatialReference(double x, double y, UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// An optional coordinate to define a measure value for the point.
    /// </summary>
    /// <remarks>
    /// M-values are used in linear referencing scenarios and may represent things like mile markers along a highway. Like 
    /// z-values, every geometry can optionally store m-values with the point coordinates that comprise it. The default 
    /// m-value is NaN. If an m-value is specified when a geometry is created, the new geometry has m-values 
    /// (<see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasM">ArcGISGeometry.hasM</see> is true). Note that when you get m-values back from a geometry, the default value of 
    /// NAN is returned for vertices that do not have m-values. A geometry with m-values is sometimes known as an 
    /// m-aware geometry.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetM();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// The x-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetX();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// The y-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetY();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// The z-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Geometries can have z-values, indicating values along the z-axis, which is perpendicular to both 
    /// the x-axis and y-axis. Z-values indicate height above or depth below a surface, or an absolute 
    /// elevation. For example, z-values are used to draw the locations of geometries in a <see cref="">SceneView</see>. 
    /// Note that geometries are not considered true 3D shapes and are draped onto surfaces in the view, 
    /// or in some cases, drawn in a single plane by using z-values. Z-values are stored on <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see> and 
    /// <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see>. Since <see cref="Esri::GameEngine::Geometry::ArcGISMultipoint">ArcGISMultipoint</see>, <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see> are created from a collection of
    /// <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>, all types of geometry can have z-values.
    /// 
    /// Whether or not a geometry has z-values is determined when the geometry is created; if you use a 
    /// method that has a z-value parameter, the new geometry has z-values (<see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasZ">ArcGISGeometry.hasZ</see> is true).
    /// If you create geometries using constructors that take z-value parameters, or if you pass 
    /// into the constructor points or segments that have z-values, the new geometry has z-values. A 
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> with z-values is sometimes known as a z-aware geometry.
    /// 
    /// It may be that not all vertices in your geometry have a z-value defined. NAN is a valid z-value used 
    /// to indicate an unknown z-value. However, the default z-value is 0. When you get z-values from a geometry 
    /// that does not have z-values, the default is 0. Check the <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasZ">ArcGISGeometry.hasZ</see> to determine whether a 
    /// z-value of 0 means that there are no z-values in the geometry or that the z-value in the geometry's 
    /// coordinates really is 0.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetZ();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// Creates a point with an x,y coordinates and m-value and a null spatial reference.
    /// </summary>
    /// <param name="x">The x-coordinate for the point.</param>
    /// <param name="y">The y-coordinate for the point.</param>
    /// <param name="m">The m-value for the point.</param>
    /// <returns>
    /// A point. This is passed to geometry or point functions.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    static UArcGISPoint* CreateWithM(double x, double y, double m);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// Creates a point with an x, y, z coordinates and m-value.
    /// </summary>
    /// <remarks>
    /// The minimum z-value is -6,356,752 meters, which is the approximate radius of the earth (the WGS 84 datum semi-minor axis).
    /// The maximum z-value is 55,000,000 meters.
    /// </remarks>
    /// <param name="x">The x-coordinate for the point.</param>
    /// <param name="y">The y-coordinate for the point.</param>
    /// <param name="z">The z-coordinate for the point.</param>
    /// <param name="m">The m-value for the point.</param>
    /// <returns>
    /// A point. This is passed to geometry or point functions.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    static UArcGISPoint* CreateWithZM(double x, double y, double z, double m);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// Creates a point with an x, y, z, m and a spatial reference.
    /// </summary>
    /// <remarks>
    /// The minimum z-value is -6,356,752 meters, which is the approximate radius of the earth (the WGS 84 datum semi-minor axis).
    /// The maximum z-value is 55,000,000 meters.
    /// </remarks>
    /// <param name="x">The x-coordinate for the point.</param>
    /// <param name="y">The y-coordinate for the point.</param>
    /// <param name="z">The z-coordinate for the point.</param>
    /// <param name="m">The m-value for the point.</param>
    /// <param name="spatialReference">The spatial reference for the point.</param>
    /// <returns>
    /// A point. This is passed to geometry or point functions.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    static UArcGISPoint* CreateWithZMSpatialReference(double x, double y, double z, double m, UArcGISSpatialReference* spatialReference);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPoint")
    /// <summary>
    /// Creates a point with an x, y, m and spatial reference.
    /// </summary>
    /// <param name="x">The x-coordinate for the point.</param>
    /// <param name="y">The y-coordinate for the point.</param>
    /// <param name="m">The m-value for the point.</param>
    /// <param name="spatialReference">The spatial reference for the point.</param>
    /// <returns>
    /// A point. This is passed to geometry or point functions.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</seealso>
    /// <since>1.0.0</since>
    static UArcGISPoint* CreateWithMSpatialReference(double x, double y, double m, UArcGISSpatialReference* spatialReference);
    #pragma endregion Methods
};