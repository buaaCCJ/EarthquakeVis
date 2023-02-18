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

#include "ArcGISPolylineBuilder.generated.h"

class UArcGISPolyline;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPolylineBuilder;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The polyline builder object is used to create a polyline.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISPolylineBuilder :
    public UArcGISMultipartBuilder
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPolylineBuilder")
    /// <summary>
    /// Creates a polyline builder from a polyline.
    /// </summary>
    /// <remarks>
    /// Prior to v100.12, only polylines without curves could be used; passing in a polygon where
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry.hasCurves">ArcGISGeometry.hasCurves</see> is true would throw an exception.
    /// 
    /// From v100.12, polylines with curves are supported.
    /// </remarks>
    /// <param name="polyline">A polyline object.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilder.hasCurves">ArcGISGeometryBuilder.hasCurves</seealso>
    /// <since>1.0.0</since>
    static UArcGISPolylineBuilder* CreateArcGISPolylineBuilderFromPolyline(UArcGISPolyline* polyline);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPolylineBuilder")
    /// <summary>
    /// Creates a polyline builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    static UArcGISPolylineBuilder* CreateArcGISPolylineBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
};