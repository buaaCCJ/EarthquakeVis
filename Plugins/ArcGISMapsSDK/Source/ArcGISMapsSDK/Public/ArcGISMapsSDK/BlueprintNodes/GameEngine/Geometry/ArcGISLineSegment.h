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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSegment.h"

#include "ArcGISLineSegment.generated.h"

class UArcGISPoint;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISLineSegment;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A line segment represents a straight line from its start to end point. It is derived from a segment object.
/// </summary>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISLineSegment :
    public UArcGISSegment
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLineSegment")
    /// <summary>
    /// Creates a line segment based on coordinates
    /// </summary>
    /// <remarks>
    /// Use this method to create a line segment representing a straight line between two points.
    /// </remarks>
    /// <param name="xStart">The X coordinate of start point.</param>
    /// <param name="yStart">The Y coordinate of start point.</param>
    /// <param name="xEnd">The X coordinate of end point.</param>
    /// <param name="yEnd">The Y coordinate of end point.</param>
    /// <since>1.0.0</since>
    static UArcGISLineSegment* CreateArcGISLineSegmentWithXY(double xStart, double yStart, double xEnd, double yEnd);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLineSegment")
    /// <summary>
    /// Creates a line segment based on 3D coordinates.
    /// </summary>
    /// <remarks>
    /// Use this method to create a line segment representing a straight line between two points.
    /// </remarks>
    /// <param name="xStart">The X coordinate of start point.</param>
    /// <param name="yStart">The Y coordinate of start point.</param>
    /// <param name="zStart">The Z coordinate of start point.</param>
    /// <param name="xEnd">The X coordinate of end point.</param>
    /// <param name="yEnd">The Y coordinate of end point.</param>
    /// <param name="zEnd">The Z coordinate of end point.</param>
    /// <since>1.0.0</since>
    static UArcGISLineSegment* CreateArcGISLineSegmentWithXYZ(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLineSegment")
    /// <summary>
    /// Creates a line segment based on 3D coordinates and a spatial reference.
    /// </summary>
    /// <remarks>
    /// Use this method to create a line segment representing a straight line between two points.
    /// </remarks>
    /// <param name="xStart">The X coordinate of start point.</param>
    /// <param name="yStart">The Y coordinate of start point.</param>
    /// <param name="zStart">The Z coordinate of start point.</param>
    /// <param name="xEnd">The X coordinate of end point.</param>
    /// <param name="yEnd">The Y coordinate of end point.</param>
    /// <param name="zEnd">The Z coordinate of end point.</param>
    /// <param name="spatialReference">A spatial reference</param>
    /// <since>1.0.0</since>
    static UArcGISLineSegment* CreateArcGISLineSegmentWithXYZSpatialReference(double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd, UArcGISSpatialReference* spatialReference);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLineSegment")
    /// <summary>
    /// Creates a line segment based on coordinates.
    /// </summary>
    /// <remarks>
    /// Use this method to create a line segment representing a straight line between two points.
    /// </remarks>
    /// <param name="xStart">The X coordinate of start point.</param>
    /// <param name="yStart">The Y coordinate of start point.</param>
    /// <param name="xEnd">The X coordinate of end point.</param>
    /// <param name="yEnd">The Y coordinate of end point.</param>
    /// <param name="spatialReference">A spatial reference</param>
    /// <since>1.0.0</since>
    static UArcGISLineSegment* CreateArcGISLineSegmentWithXYSpatialReference(double xStart, double yStart, double xEnd, double yEnd, UArcGISSpatialReference* spatialReference);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLineSegment")
    /// <summary>
    /// Creates a line segment based on two points.
    /// </summary>
    /// <remarks>
    /// Use this method to create a line segment representing a straight line between two points.
    /// 
    /// If both points have a spatial reference set, they must be equal.
    /// </remarks>
    /// <param name="startPoint">The start point.</param>
    /// <param name="endPoint">The end point.</param>
    /// <since>1.0.0</since>
    static UArcGISLineSegment* CreateArcGISLineSegment(UArcGISPoint* startPoint, UArcGISPoint* endPoint);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLineSegment")
    /// <summary>
    /// Creates a line segment based on two points and a spatial reference.
    /// </summary>
    /// <remarks>
    /// Use this method to create a line segment representing a straight line between two points.
    /// The spatial reference parameter is used if the points have a null spatial reference. If more than one
    /// spatial reference is supplied (as a parameter or as a property of a <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see> parameter), they must all be
    /// equal.
    /// </remarks>
    /// <param name="startPoint">The start point.</param>
    /// <param name="endPoint">The end point.</param>
    /// <param name="spatialReference">A spatial reference</param>
    /// <since>1.0.0</since>
    static UArcGISLineSegment* CreateArcGISLineSegmentWithSpatialReference(UArcGISPoint* startPoint, UArcGISPoint* endPoint, UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLineSegment")
    /// <summary>
    /// Creates a line segment of the specified length and angle from a given start point.
    /// </summary>
    /// <remarks>
    /// Use this method to create a line segment. The represents a straight line between two points.
    /// the spatial reference of the point is used to determine the segment's spatial reference.
    /// The angle is specified in radians relative to the X axis
    /// The length is in the units of the spatial reference.
    /// </remarks>
    /// <param name="startPoint">The start point of the line segment.</param>
    /// <param name="angleRadians">The angle of the line relative to the X axis. Units are radians.</param>
    /// <param name="length">The length of the line</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISLineSegment">ArcGISLineSegment</see>.
    /// </returns>
    /// <since>1.0.0</since>
    static UArcGISLineSegment* CreateLineAtAngleFromStartPoint(UArcGISPoint* startPoint, double angleRadians, double length);
    #pragma endregion Methods
};