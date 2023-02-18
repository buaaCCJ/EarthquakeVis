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

#include "ArcGISSegment.generated.h"

class UArcGISPoint;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISSegment;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
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
class ARCGISMAPSSDK_API UArcGISSegment :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSegment")
    /// <summary>
    /// The end point of the segment.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetEndPoint();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSegment")
    /// <summary>
    /// Indicates is a segment is closed, it has a matching start and end point.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsClosed();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSegment")
    /// <summary>
    /// False if the object is a <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see>; true otherwise.
    /// </summary>
    /// <remarks>
    /// Prior to v100.12, only <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see> instances were supported when creating new geometries using a
    /// <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder">ArcGISMultipartBuilder</see> or iterating the <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> instances in an existing <see cref="Esri::GameEngine::Geometry::ArcGISMultipart">ArcGISMultipart</see> geometry.
    /// 
    /// From v100.12, you can add curve segments (<see cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</see>, <see cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</see>) when using a
    /// <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder">ArcGISMultipartBuilder</see>, and get them back from an existing <see cref="Esri::GameEngine::Geometry::ArcGISMultipart">ArcGISMultipart</see> geometry when
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISMutablePart.hasCurves">ArcGISMutablePart.hasCurves</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISCubicBezierSegment">ArcGISCubicBezierSegment</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISEllipticArcSegment">ArcGISEllipticArcSegment</seealso>
    /// <since>1.0.0</since>
    bool GetIsCurve();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSegment")
    /// <summary>
    /// The spatial reference for the segment.
    /// </summary>
    /// <remarks>
    /// If the segment does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSegment")
    /// <summary>
    /// The start point of the segment.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetStartPoint();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSegment")
    /// <summary>
    /// Tests if this object is equal to a second <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> object.
    /// </summary>
    /// <param name="right">The second segment to compare for equality.</param>
    /// <returns>
    /// True if the comparison succeeds and the objects are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(UArcGISSegment* right) const;
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISSegment> APIObject;
};