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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMultipartBuilder.h"

#include "ArcGISPolygonBuilder.generated.h"

class UArcGISPolyline;
class UArcGISPolygon;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPolygonBuilder;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The polygon builder object is used to create a polygon.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISPolygonBuilder :
    public UArcGISMultipartBuilder
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPolygonBuilder")
    /// <summary>
    /// Creates a polygon builder from a polygon.
    /// </summary>
    /// <remarks>
    /// Prior to v100.12, only polygons without curves could be used; passing in a polygon where
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true would throw an exception.
    /// 
    /// From v100.12, polygons with curves are supported.
    /// </remarks>
    /// <param name="polygon">A polygon object.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <since>1.0.0</since>
    static UArcGISPolygonBuilder* CreateArcGISPolygonBuilderFromPolygon(UArcGISPolygon* polygon);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPolygonBuilder")
    /// <summary>
    /// Creates a polygon builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    static UArcGISPolygonBuilder* CreateArcGISPolygonBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPolygonBuilder")
    /// <summary>
    /// Creates a polyline with the values in the polygon builder.
    /// </summary>
    /// <remarks>
    /// Creates the polyline object described by this builder.
    /// </remarks>
    /// <returns>
    /// A polyline.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISPolyline* ToPolyline() const;
    #pragma endregion Methods
};