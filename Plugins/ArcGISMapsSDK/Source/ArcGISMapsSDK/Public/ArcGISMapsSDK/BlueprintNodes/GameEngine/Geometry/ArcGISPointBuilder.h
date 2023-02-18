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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryBuilder.h"

#include "ArcGISPointBuilder.generated.h"

class UArcGISPoint;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPointBuilder;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The point builder object is used to create a point.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISPointBuilder :
    public UArcGISGeometryBuilder
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// Creates a point builder from a point.
    /// </summary>
    /// <param name="point">The point object.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</seealso>
    /// <since>1.0.0</since>
    static UArcGISPointBuilder* CreateArcGISPointBuilderFromPoint(UArcGISPoint* point);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// Creates a point builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    static UArcGISPointBuilder* CreateArcGISPointBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// The m-value for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetM();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// The m-value for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetM(double m);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// The x-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetX();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// The x-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetX(double x);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// The y-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetY();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// The y-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetY(double y);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// The z-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// The minimum z-coordinate is -6,356,752 meters, which is the approximate radius of the earth (the WGS 84 datum semi-minor axis).
    /// The maximum z-coordinate is 55,000,000 meters. Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetZ();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// The z-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// The minimum z-coordinate is -6,356,752 meters, which is the approximate radius of the earth (the WGS 84 datum semi-minor axis).
    /// The maximum z-coordinate is 55,000,000 meters. Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetZ(double z);
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// Offsets the envelope by the given offsets for the x and y dimension.
    /// </summary>
    /// <param name="offsetX">The number of units to move the envelope on the x axis.</param>
    /// <param name="offsetY">The number of units to move the envelope on the y axis.</param>
    /// <since>1.0.0</since>
    void OffsetBy(double offsetX, double offsetY);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISPointBuilder")
    /// <summary>
    /// Sets the x,y coordinates of a point.
    /// </summary>
    /// <param name="x">The new x-coordinate value for the point.</param>
    /// <param name="y">The new y-coordinate value for the point.</param>
    /// <since>1.0.0</since>
    void SetXY(double x, double y);
    #pragma endregion Methods
};