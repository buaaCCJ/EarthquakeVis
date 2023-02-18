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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryType.h"

#include "ArcGISGeodesicEllipseParameters.generated.h"

class UArcGISAngularUnit;
class UArcGISPoint;
class UArcGISLinearUnit;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISGeodesicEllipseParameters;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The required parameters for calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.ellipseGeodesic">ArcGISGeometryEngine.ellipseGeodesic</see>.
/// </summary>
/// <remarks>
/// The parameters needed when calling GeometryEngine's ellipseGeodesic method.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISGeodesicEllipseParameters :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// Creates a new and empty <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters">ArcGISGeodesicEllipseParameters</see> object.
    /// </summary>
    /// <since>1.0.0</since>
    static UArcGISGeodesicEllipseParameters* CreateArcGISGeodesicEllipseParameters();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// Creates a new <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters">ArcGISGeodesicEllipseParameters</see> object with the given values.
    /// </summary>
    /// <param name="axisDirection">The direction of the major axis of the ellipse as an angle in the given angular unit.</param>
    /// <param name="angularUnit">The angular unit of measure. If null degrees are assumed.</param>
    /// <param name="center">The center of the ellipse.</param>
    /// <param name="linearUnit">The linear unit of measure. If null meters are assumed.</param>
    /// <param name="maxPointCount">The max number of vertices in the ellipse.</param>
    /// <param name="maxSegmentLength">The max segment length of the result approximation in the given linear unit.</param>
    /// <param name="geometryType">The type of output geometry required, must be one of <see cref="Esri::GameEngine::Geometry::ArcGISGeometryType.polyline">ArcGISGeometryType.polyline</see>, <see cref="Esri::GameEngine::Geometry::ArcGISGeometryType.polygon">ArcGISGeometryType.polygon</see>, or <see cref="Esri::GameEngine::Geometry::ArcGISGeometryType.multipoint">ArcGISGeometryType.multipoint</see>.</param>
    /// <param name="semiAxis1Length">The length of the semi-major or semi-minor axis of the ellipse in the given linear unit.</param>
    /// <param name="semiAxis2Length">The length of the semi-major or semi-minor axis of the ellipse in the given linear unit.</param>
    /// <since>1.0.0</since>
    static UArcGISGeodesicEllipseParameters* CreateArcGISGeodesicEllipseParametersWith(double axisDirection, UArcGISAngularUnit* angularUnit, UArcGISPoint* center, UArcGISLinearUnit* linearUnit, int32 maxPointCount, double maxSegmentLength, EArcGISGeometryType::Type geometryType, double semiAxis1Length, double semiAxis2Length);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// Creates a new <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters">ArcGISGeodesicEllipseParameters</see> object with the given center point and axis lengths.
    /// </summary>
    /// <remarks>
    /// The geodesic ellipse parameter set returned contains the following default values:
    /// Property | Value
    /// -------- | -----
    /// linearUnit | meter
    /// angularUnit | degree
    /// axisDirection | 0
    /// geometryType | polygon
    /// maxSegmentLength | _2 * pi * a / 360_
    /// maxPointCount | 65536
    /// (where _a_ is the semi major axis length)
    /// </remarks>
    /// <param name="center">The center of the ellipse.</param>
    /// <param name="semiAxis1Length">The length of the semi-major or semi-minor axis of the ellipse in meters.</param>
    /// <param name="semiAxis2Length">The length of the semi-major or semi-minor axis of the ellipse in meters.</param>
    /// <since>1.0.0</since>
    static UArcGISGeodesicEllipseParameters* CreateArcGISGeodesicEllipseParametersWithCenterAndAxisLengths(UArcGISPoint* center, double semiAxis1Length, double semiAxis2Length);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.axisDirection">ArcGISGeodesicEllipseParameters.axisDirection</see>.
    /// </summary>
    /// <remarks>
    /// By default, the angular unit is degrees.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISAngularUnit* GetAngularUnit();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.axisDirection">ArcGISGeodesicEllipseParameters.axisDirection</see>.
    /// </summary>
    /// <remarks>
    /// By default, the angular unit is degrees.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetAngularUnit(UArcGISAngularUnit* angularUnit);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The direction of the major axis of the ellipse as an angle, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.angularUnit">ArcGISGeodesicEllipseParameters.angularUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetAxisDirection();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The direction of the major axis of the ellipse as an angle, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.angularUnit">ArcGISGeodesicEllipseParameters.angularUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetAxisDirection(double axisDirection);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The center of the ellipse.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetCenter();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The center of the ellipse.
    /// </summary>
    /// <since>1.0.0</since>
    void SetCenter(UArcGISPoint* center);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The type of the output geometry.
    /// </summary>
    /// <since>1.0.0</since>
    EArcGISGeometryType::Type GetGeometryType();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The type of the output geometry.
    /// </summary>
    /// <since>1.0.0</since>
    void SetGeometryType(EArcGISGeometryType::Type geometryType);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.semiAxis1Length">ArcGISGeodesicEllipseParameters.semiAxis1Length</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.semiAxis2Length">ArcGISGeodesicEllipseParameters.semiAxis2Length</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.maxSegmentLength">ArcGISGeodesicEllipseParameters.maxSegmentLength</see>.
    /// </summary>
    /// <remarks>
    /// By default, the linear unit is meters.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISLinearUnit* GetLinearUnit();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.semiAxis1Length">ArcGISGeodesicEllipseParameters.semiAxis1Length</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.semiAxis2Length">ArcGISGeodesicEllipseParameters.semiAxis2Length</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.maxSegmentLength">ArcGISGeodesicEllipseParameters.maxSegmentLength</see>.
    /// </summary>
    /// <remarks>
    /// By default, the linear unit is meters.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetLinearUnit(UArcGISLinearUnit* linearUnit);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The max segment length of the result, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.linearUnit">ArcGISGeodesicEllipseParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetMaxSegmentLength();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The max segment length of the result, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.linearUnit">ArcGISGeodesicEllipseParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetMaxSegmentLength(double maxSegmentLength);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.linearUnit">ArcGISGeodesicEllipseParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetSemiAxis1Length();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.linearUnit">ArcGISGeodesicEllipseParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetSemiAxis1Length(double semiAxis1Length);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.linearUnit">ArcGISGeodesicEllipseParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetSemiAxis2Length();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicEllipseParameters")
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters.linearUnit">ArcGISGeodesicEllipseParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetSemiAxis2Length(double semiAxis2Length);
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISGeodesicEllipseParameters> APIObject;
};