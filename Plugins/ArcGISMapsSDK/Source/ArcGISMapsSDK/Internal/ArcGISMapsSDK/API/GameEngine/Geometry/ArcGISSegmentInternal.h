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
enum class ArcGISSegmentType;

/// <summary>
/// A segment represents an edge of a multipart geometry, connecting a start to an end point.
/// </summary>
/// <remarks>
/// A segment describes a continuous line between a start location and an end location. The ArcGIS Platform,
/// including this API, supports both linear segments (represented by <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see>) and curve
/// segments (represented by <see cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</see> and <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see>).
/// 
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.densify">ArcGISGeometryEngine.densify</see> can translate curve segments into multiple <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see>
/// instances to approximate the curve.
/// 
/// Every <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePart">ArcGISImmutablePart</see> in a <see cref="Esri::GameEngine::Geometry::ArcGISMultipart">ArcGISMultipart</see> geometry is a collection of <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> instances, where the end of
/// one segment is at exactly the same location as the start of the following segment. <see cref="Esri::GameEngine::Geometry::ArcGISMultipart">ArcGISMultipart</see> geometries
/// can be composed from and decomposed into their constituent segments if required.
/// 
/// Because a single location is shared by adjacent segments, a single <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see> object is used to represent the
/// shared location when you iterate through the points in a part. As a result, when iterating through the points
/// in a part of a polyline or polygon, there is one more point than the number of segments in that same part.
/// 
/// Segments are immutable so you can not change a segment's shape once it is created. For workflows that involve
/// geometry editing, create a new segment with the properties you require.
/// 
/// From v100.12, curve segments are supported in geometry editing workflows. You can add curve segments to a
/// <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder">ArcGISMultipartBuilder</see>, and if a geometry has curves (<see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true) then curve segments are
/// returned where applicable from the <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePart">ArcGISImmutablePart</see> collections that comprise the multipart geometry. Curve
/// and linear segments can be mixed together in the same geometry.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</seealso>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</seealso>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISSegmentInternal
{
    friend class ArcGISSegmentInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The object type of the segment.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSegmentType">ArcGISSegmentType</seealso>
    /// <since>1.0.0</since>
    static ArcGISSegmentType GetObjectType(ArcGISSegment* self);
    #pragma endregion Properties
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri