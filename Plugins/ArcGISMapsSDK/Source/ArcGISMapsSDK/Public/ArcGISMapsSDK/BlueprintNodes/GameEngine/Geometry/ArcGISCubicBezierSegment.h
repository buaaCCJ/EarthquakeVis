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

#include "ArcGISCubicBezierSegment.generated.h"

class UArcGISPoint;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISCubicBezierSegment;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A cubic Bezier curve for use in a multipart geometry.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISCubicBezierSegment :
    public UArcGISSegment
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISCubicBezierSegment")
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
    static UArcGISCubicBezierSegment* CreateArcGISCubicBezierSegment(UArcGISPoint* startPoint, UArcGISPoint* controlPoint1, UArcGISPoint* controlPoint2, UArcGISPoint* endPoint, UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISCubicBezierSegment")
    /// <summary>
    /// A point tangent to the start of the segment.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetControlPoint1();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISCubicBezierSegment")
    /// <summary>
    /// A point tangent to the end of the segment.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetControlPoint2();
    #pragma endregion Properties
};