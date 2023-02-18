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

#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSegment.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPoint;
class ArcGISSpatialReference;

/// <summary>
/// An elliptic arc segment for use in a multipart geometry.
/// </summary>
/// <remarks>
/// An elliptic arc is the portion of the boundary of a 2D ellipse that connects two points.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISEllipticArcSegment :
    public ArcGISSegment
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates an elliptic arc based on parameters that define an ellipse and the portion of that ellipse that
    /// defines the arc.
    /// </summary>
    /// <remarks>
    /// The spatial reference parameter is used if the center point parameter has a null spatial reference. If both
    /// spatial references are supplied, they must be equal.
    /// 
    /// The z-value and m-value of the center point (if present) are ignored. Use
    /// <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.EllipticArcSegment">ArcGISEllipticArcSegment.EllipticArcSegment</see>
    /// to create an <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see> with end points with z-value and/or m-value.
    /// </remarks>
    /// <param name="centerPoint">The center point of the embedded ellipse.</param>
    /// <param name="rotationAngle">The angle in radians by which the major axis of the embedded ellipse is rotated from the x-axis.</param>
    /// <param name="semiMajorAxis">The length of the semi-major axis of the embedded ellipse in the units of the spatial reference.</param>
    /// <param name="minorMajorRatio">The ratio of the length of the semi-minor axis to the length of the semi-major axis of the embedded ellipse.</param>
    /// <param name="startAngle">The parametric angle in radians of the start of the arc relative to the major axis of the embedded ellipse.</param>
    /// <param name="centralAngle">The parametric angle in radians measuring the span of the arc from <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.startAngle">ArcGISEllipticArcSegment.startAngle</see> to <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.endAngle">ArcGISEllipticArcSegment.endAngle</see>.</param>
    /// <param name="spatialReference">A spatial reference to use for the segment if the center point parameter does not have a spatial reference set.</param>
    /// <since>1.0.0</since>
    ArcGISEllipticArcSegment(const ArcGISPoint& centerPoint, double rotationAngle, double semiMajorAxis, double minorMajorRatio, double startAngle, double centralAngle, const ArcGISSpatialReference& spatialReference);
    
    /// <summary>
    /// Creates an elliptic arc segment from the given start and end points, and other parameters that define an ellipse.
    /// </summary>
    /// <remarks>
    /// The z-value and m-value of the start and end points (if present) are used in the <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see>.
    /// 
    /// To maintain the given startPoint and endPoint in the new segment, the other parameters may be adjusted if
    /// required. Such adjustments are made according to the <see cref="Scalable Vector Graphics 1.1
    /// Specification, Appendix F.6.5">https://www.w3.org/TR/SVG11/implnote.html#ArcConversionEndpointToCenter</see>. If
    /// these cannot be adjusted sufficiently, an arc represented with a straight line is returned.
    /// </remarks>
    /// <param name="startPoint">The start point of the segment.</param>
    /// <param name="endPoint">The end point of the segment.</param>
    /// <param name="rotationAngle">The angle in radians by which the major axis of the embedded ellipse is rotated from the x-axis.</param>
    /// <param name="isMinor">True if <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.centralAngle">ArcGISEllipticArcSegment.centralAngle</see> of the segment is less than PI.</param>
    /// <param name="isCounterClockwise">True if the direction of the segment, from start point to end point, proceeds in a counterclockwise direction, otherwise false.</param>
    /// <param name="semiMajorAxis">The length of the semi-major axis of the embedded ellipse in the units of the spatial reference.</param>
    /// <param name="minorMajorRatio">The ratio of the length of the semi-minor axis to the length of the semi-major axis of the embedded ellipse.</param>
    /// <param name="spatialReference">A spatial reference to use for the segment if the points do not have spatial references set.</param>
    /// <since>1.0.0</since>
    ArcGISEllipticArcSegment(const ArcGISPoint& startPoint, const ArcGISPoint& endPoint, double rotationAngle, bool isMinor, bool isCounterClockwise, double semiMajorAxis, double minorMajorRatio, const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The center point of the ellipse that this segment is defined upon.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISPoint GetCenterPoint() const;
    
    /// <summary>
    /// The parametric angle in radians measuring the span of the arc from <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.startAngle">ArcGISEllipticArcSegment.startAngle</see> to <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.endAngle">ArcGISEllipticArcSegment.endAngle</see>.
    /// </summary>
    /// <remarks>
    /// A positive value corresponds to a counterclockwise arc sweep.
    /// 
    /// This value is always between -2*PI and 2*PI, these limits indicating this arc forms a complete ellipse in
    /// either clockwise or counterclockwise direction.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetCentralAngle() const;
    
    /// <summary>
    /// The parametric angle in radians of the end of the arc relative to the major axis of the embedded ellipse.
    /// </summary>
    /// <remarks>
    /// A positive value corresponds to a counterclockwise rotation from the major axis.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetEndAngle() const;
    
    /// <summary>
    /// Indicates if this arc is a portion of the boundary of a 2D circle.
    /// </summary>
    /// <remarks>
    /// An elliptic arc is circular if the ellipse upon which it is based is a circle, meaning the lengths of its
    /// major and minor axes are equal.
    /// 
    /// Use <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.createCircularEllipticArc">ArcGISEllipticArcSegment.createCircularEllipticArc</see> and
    /// <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.createCircularEllipticArc">ArcGISEllipticArcSegment.createCircularEllipticArc</see> to create circular arcs.
    /// </remarks>
    /// <since>1.0.0</since>
    bool GetIsCircular() const;
    
    /// <summary>
    /// Indicates if the direction of the segment, from start point to end point, proceeds in a counterclockwise direction.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsCounterClockwise() const;
    
    /// <summary>
    /// The ratio of the length of the semi-minor axis to the semi-major axis.
    /// </summary>
    /// <since>1.0.0</since>
    double GetMinorMajorRatio() const;
    
    /// <summary>
    /// The angle in radians by which the major axis of the ellipse this segment is based upon is rotated from the x-axis.
    /// </summary>
    /// <since>1.0.0</since>
    double GetRotationAngle() const;
    
    /// <summary>
    /// The length of the longer of the two axes of the ellipse upon which this arc is based.
    /// </summary>
    /// <remarks>
    /// The semi-major axis always lies on the line between 0 and PI radians.
    /// 
    /// The length is in the units of the spatial reference.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetSemiMajorAxis() const;
    
    /// <summary>
    /// The length of the shorter of the two axes of the ellipse upon which this arc is based.
    /// </summary>
    /// <remarks>
    /// The semi-minor axis always lies on the line between PI/2 and 3*PI/2 radians.
    /// 
    /// The length is in the units of the spatial reference.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetSemiMinorAxis() const;
    
    /// <summary>
    /// The parametric angle in radians of the start of the arc relative to the major axis of the embedded ellipse.
    /// </summary>
    /// <remarks>
    /// A positive value corresponds to a counterclockwise rotation from the major axis.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetStartAngle() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Creates an <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see> that is a partial circle shape from the center point and radius of the
    /// embedded circle, and the start and central angle around that circle.
    /// </summary>
    /// <remarks>
    /// The z-value and m-value of the center point (if present) are ignored. Use
    /// <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.createCircularEllipticArc">ArcGISEllipticArcSegment.createCircularEllipticArc</see>
    /// to create a circular <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see> with end points with z-value and/or m-value.
    /// </remarks>
    /// <param name="centerPoint">The center point of the embedded circle.</param>
    /// <param name="radius">The distance from the center of the embedded circle to its perimeter.</param>
    /// <param name="startAngle">The parametric angle in radians of the start of the arc relative to the major axis of the embedded ellipse.</param>
    /// <param name="centralAngle">The parametric angle in radians measuring the span of the arc from <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.startAngle">ArcGISEllipticArcSegment.startAngle</see> to <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.endAngle">ArcGISEllipticArcSegment.endAngle</see>.</param>
    /// <param name="spatialReference">The spatial reference of the new segment.</param>
    /// <returns>
    /// A new <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see> with the given center point, radius, start and central angles, and
    /// spatial reference, where <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.isCircular">ArcGISEllipticArcSegment.isCircular</see> is true.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEllipticArcSegment CreateCircularEllipticArc(const ArcGISPoint& centerPoint, double radius, double startAngle, double centralAngle, const ArcGISSpatialReference& spatialReference);
    
    /// <summary>
    /// Creates an <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see> from start, end, and interior points that is a partial circle shape.
    /// </summary>
    /// <remarks>
    /// The z-value and m-value of the start and end points (if present) are used in the circular
    /// <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see>. The z-value and m-value of the interior point (if present) are ignored.
    /// </remarks>
    /// <param name="startPoint">The start point of the segment.</param>
    /// <param name="endPoint">The end point of the segment.</param>
    /// <param name="interiorPoint">A point along the circular arc, between the start and end points.</param>
    /// <param name="spatialReference">The spatial reference of the new segment.</param>
    /// <returns>
    /// A new <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see> with the given start, through and end point, and spatial reference, where
    /// <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment.isCircular">ArcGISEllipticArcSegment.isCircular</see> is true.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEllipticArcSegment CreateCircularEllipticArc(const ArcGISPoint& startPoint, const ArcGISPoint& endPoint, const ArcGISPoint& interiorPoint, const ArcGISSpatialReference& spatialReference);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISEllipticArcSegment(void* handle);
    ArcGISEllipticArcSegment(const ArcGISEllipticArcSegment&) = delete;
    ArcGISEllipticArcSegment(ArcGISEllipticArcSegment&& other) noexcept;
    ArcGISEllipticArcSegment();
    virtual ~ArcGISEllipticArcSegment() = default;
    
    ArcGISEllipticArcSegment& operator=(const ArcGISEllipticArcSegment&) = delete;
    ArcGISEllipticArcSegment& operator=(ArcGISEllipticArcSegment&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri