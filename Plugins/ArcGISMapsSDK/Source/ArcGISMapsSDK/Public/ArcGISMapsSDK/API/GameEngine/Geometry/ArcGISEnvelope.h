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

#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometry.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPoint;
class ArcGISSpatialReference;

/// <summary>
/// A geometry that represents a rectangular shape.
/// </summary>
/// <remarks>
/// An <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see> is an axis-aligned box described by the coordinates of the lower left corner 
/// and the coordinates of the upper right corner. They are commonly used to represent the spatial extent 
/// covered by layers or other geometries, or to define an area of interest. They can be used as the 
/// geometry for a graphic and as an input for many spatial operations. Although they both represent
/// a geographic area, an <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see> is distinct from a <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see>, and they cannot always be used 
/// interchangeably.
/// 
/// New instances of <see cref="Esri::GameEngine::Geometry::ArcGISEnvelope">ArcGISEnvelope</see> are defined by specifying a minimum and maximum x-coordinate and minimum 
/// and maximum y-coordinate, and a <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see>. Optionally, a minimum and maximum z-value can be 
/// specified to define the depth of the envelope.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISEnvelope :
    public ArcGISGeometry
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates an envelope based on the x,y coordinates with a null spatial reference.
    /// </summary>
    /// <remarks>
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="xMin">The minimal x-value.</param>
    /// <param name="yMin">The minimal y-value.</param>
    /// <param name="xMax">The maximum x-value.</param>
    /// <param name="yMax">The maximum y-value.</param>
    /// <since>1.0.0</since>
    ArcGISEnvelope(double xMin, double yMin, double xMax, double yMax);
    
    /// <summary>
    /// Creates an envelope based on the x,y and z values with a null spatial reference.
    /// </summary>
    /// <remarks>
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="xMin">The minimal x-value.</param>
    /// <param name="yMin">The minimal y-value.</param>
    /// <param name="xMax">The maximum x-value.</param>
    /// <param name="yMax">The maximum y-value.</param>
    /// <param name="zMin">The minimal z-value.</param>
    /// <param name="zMax">The maximum z-value.</param>
    /// <since>1.0.0</since>
    ArcGISEnvelope(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax);
    
    /// <summary>
    /// Creates an envelope based on x, y, and z values with the spatial reference.
    /// </summary>
    /// <remarks>
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="xMin">The minimal x-value.</param>
    /// <param name="yMin">The minimal y-value.</param>
    /// <param name="xMax">The maximum x-value.</param>
    /// <param name="yMax">The maximum y-value.</param>
    /// <param name="zMin">The minimal z-value.</param>
    /// <param name="zMax">The maximum z-value.</param>
    /// <param name="spatialReference">The spatial reference for the envelope.</param>
    /// <since>1.0.0</since>
    ArcGISEnvelope(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, const ArcGISSpatialReference& spatialReference);
    
    /// <summary>
    /// Creates an envelope based on the x,y coordinates with a spatial reference.
    /// </summary>
    /// <remarks>
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="xMin">The minimal x-value.</param>
    /// <param name="yMin">The minimal y-value.</param>
    /// <param name="xMax">The maximum x-value.</param>
    /// <param name="yMax">The maximum y-value.</param>
    /// <param name="spatialReference">The spatial reference for the envelope.</param>
    /// <since>1.0.0</since>
    ArcGISEnvelope(double xMin, double yMin, double xMax, double yMax, const ArcGISSpatialReference& spatialReference);
    
    /// <summary>
    /// Creates an envelope from a center point and a width and height.
    /// </summary>
    /// <remarks>
    /// The spatial reference of the resulting envelope comes from the center point.
    /// </remarks>
    /// <param name="center">The center point for the envelope.</param>
    /// <param name="width">The width of the envelope around the center point.</param>
    /// <param name="height">The height of the envelope around the center point.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</seealso>
    /// <since>1.0.0</since>
    ArcGISEnvelope(const ArcGISPoint& center, double width, double height);
    
    /// <summary>
    /// Creates an envelope from a center point and a width, height, and depth.
    /// </summary>
    /// <remarks>
    /// The spatial reference of the resulting envelope comes from the center point.
    /// </remarks>
    /// <param name="center">The center point for the envelope.</param>
    /// <param name="width">The width of the envelope around the center point.</param>
    /// <param name="height">The height of the envelope around the center point.</param>
    /// <param name="depth">The depth of the envelope around the center point.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</seealso>
    /// <since>1.0.0</since>
    ArcGISEnvelope(const ArcGISPoint& center, double width, double height, double depth);
    
    /// <summary>
    /// Creates an envelope from any two points.
    /// </summary>
    /// <remarks>
    /// The spatial reference of the points must be the same. The spatial reference of the result envelope comes from the points.
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="min">The minimal values for the envelope.</param>
    /// <param name="max">The maximum values for the envelope.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</seealso>
    /// <since>1.0.0</since>
    ArcGISEnvelope(const ArcGISPoint& min, const ArcGISPoint& max);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The center point for the envelope.
    /// </summary>
    /// <remarks>
    /// Creates a new Point.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</seealso>
    /// <since>1.0.0</since>
    ArcGISPoint GetCenter() const;
    
    /// <summary>
    /// The depth (ZMax - ZMin) for the envelope.
    /// </summary>
    /// <remarks>
    /// A 2D envelope has zero
    /// depth. Returns NAN if the envelope is empty or if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetDepth() const;
    
    /// <summary>
    /// The height for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetHeight() const;
    
    /// <summary>
    /// The m maximum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetMMax() const;
    
    /// <summary>
    /// The m minimum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetMMin() const;
    
    /// <summary>
    /// The width for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetWidth() const;
    
    /// <summary>
    /// The x maximum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetXMax() const;
    
    /// <summary>
    /// The x minimum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetXMin() const;
    
    /// <summary>
    /// The y maximum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetYMax() const;
    
    /// <summary>
    /// The y minimum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetYMin() const;
    
    /// <summary>
    /// The z maximum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetZMax() const;
    
    /// <summary>
    /// The z minimum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetZMin() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Creates an envelope based on the x, y and m values with a null spatial reference.
    /// </summary>
    /// <remarks>
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="xMin">The minimal x-value.</param>
    /// <param name="yMin">The minimal y-value.</param>
    /// <param name="xMax">The maximum x-value.</param>
    /// <param name="yMax">The maximum y-value.</param>
    /// <param name="mMin">The minimal m-value.</param>
    /// <param name="mMax">The maximum m-value.</param>
    /// <returns>
    /// A envelope. This is passed to geometry or envelope functions.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEnvelope CreateWithM(double xMin, double yMin, double xMax, double yMax, double mMin, double mMax);
    
    /// <summary>
    /// Creates an envelope based on the x, y, z and m values with a null spatial reference.
    /// </summary>
    /// <remarks>
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="xMin">The minimal x-value.</param>
    /// <param name="yMin">The minimal y-value.</param>
    /// <param name="xMax">The maximum x-value.</param>
    /// <param name="yMax">The maximum y-value.</param>
    /// <param name="zMin">The minimal z-value.</param>
    /// <param name="zMax">The maximum z-value.</param>
    /// <param name="mMin">The minimal m-value.</param>
    /// <param name="mMax">The maximum m-value.</param>
    /// <returns>
    /// A envelope. This is passed to geometry or envelope functions.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEnvelope CreateWithM(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, double mMin, double mMax);
    
    /// <summary>
    /// Creates an envelope based on the x, y, z and m values with a spatial reference.
    /// </summary>
    /// <remarks>
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="xMin">The minimal x-value.</param>
    /// <param name="yMin">The minimal y-value.</param>
    /// <param name="xMax">The maximum x-value.</param>
    /// <param name="yMax">The maximum y-value.</param>
    /// <param name="zMin">The minimal z-value.</param>
    /// <param name="zMax">The maximum z-value.</param>
    /// <param name="mMin">The minimal m-value.</param>
    /// <param name="mMax">The maximum m-value.</param>
    /// <param name="spatialReference">The spatial reference for the envelope.</param>
    /// <returns>
    /// A envelope. This is passed to geometry or envelope functions.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEnvelope CreateWithM(double xMin, double yMin, double xMax, double yMax, double zMin, double zMax, double mMin, double mMax, const ArcGISSpatialReference& spatialReference);
    
    /// <summary>
    /// Creates an envelope based on the x, y and m values with a spatial reference.
    /// </summary>
    /// <remarks>
    /// If the values for min parameters are bigger than max parameters then they are re-ordered. The resulting envelope always has min less than or equal to max.
    /// </remarks>
    /// <param name="xMin">The minimal x-value.</param>
    /// <param name="yMin">The minimal y-value.</param>
    /// <param name="xMax">The maximum x-value.</param>
    /// <param name="yMax">The maximum y-value.</param>
    /// <param name="mMin">The minimal m-value.</param>
    /// <param name="mMax">The maximum m-value.</param>
    /// <param name="spatialReference">The spatial reference for the envelope.</param>
    /// <returns>
    /// A envelope. This is passed to geometry or envelope functions.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEnvelope CreateWithM(double xMin, double yMin, double xMax, double yMax, double mMin, double mMax, const ArcGISSpatialReference& spatialReference);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISEnvelope(void* handle);
    ArcGISEnvelope(const ArcGISEnvelope&) = delete;
    ArcGISEnvelope(ArcGISEnvelope&& other) noexcept;
    ArcGISEnvelope();
    virtual ~ArcGISEnvelope() = default;
    
    ArcGISEnvelope& operator=(const ArcGISEnvelope&) = delete;
    ArcGISEnvelope& operator=(ArcGISEnvelope&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri