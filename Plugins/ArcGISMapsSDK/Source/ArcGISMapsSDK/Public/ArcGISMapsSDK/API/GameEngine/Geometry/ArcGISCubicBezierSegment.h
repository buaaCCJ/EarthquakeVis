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
/// A cubic Bezier curve for use in a multipart geometry.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISCubicBezierSegment :
    public ArcGISSegment
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a bezier segment based on a start and end point and two control points at tangents to the start and end points.
    /// </summary>
    /// <remarks>
    /// The spatial reference parameter is used if the points have a null spatial reference. If more than one
    /// spatial reference is supplied (as a parameter or as a property of a <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see> parameter), they must all be
    /// equal.
    /// 
    /// The z-value and m-value of the start and end points (if present) are used in the
    /// <see cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</see>. The z-value and m-value of the control points (if present) are ignored.
    /// </remarks>
    /// <param name="startPoint">The start point of the segment.</param>
    /// <param name="controlPoint1">A point tangent to the start of the segment.</param>
    /// <param name="controlPoint2">A point tangent to the end of the segment.</param>
    /// <param name="endPoint">The end point of the segment.</param>
    /// <param name="spatialReference">A spatial reference to use for the segment if the points do not have spatial references set.</param>
    /// <since>1.0.0</since>
    ArcGISCubicBezierSegment(const ArcGISPoint& startPoint, const ArcGISPoint& controlPoint1, const ArcGISPoint& controlPoint2, const ArcGISPoint& endPoint, const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// A point tangent to the start of the segment.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISPoint GetControlPoint1() const;
    
    /// <summary>
    /// A point tangent to the end of the segment.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISPoint GetControlPoint2() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISCubicBezierSegment(void* handle);
    ArcGISCubicBezierSegment(const ArcGISCubicBezierSegment&) = delete;
    ArcGISCubicBezierSegment(ArcGISCubicBezierSegment&& other) noexcept;
    ArcGISCubicBezierSegment();
    virtual ~ArcGISCubicBezierSegment() = default;
    
    ArcGISCubicBezierSegment& operator=(const ArcGISCubicBezierSegment&) = delete;
    ArcGISCubicBezierSegment& operator=(ArcGISCubicBezierSegment&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri