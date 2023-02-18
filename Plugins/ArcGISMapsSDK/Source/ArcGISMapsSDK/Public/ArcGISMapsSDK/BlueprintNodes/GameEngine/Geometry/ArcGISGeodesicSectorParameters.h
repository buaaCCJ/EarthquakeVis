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

#include "ArcGISGeodesicSectorParameters.generated.h"

class UArcGISAngularUnit;
class UArcGISPoint;
class UArcGISLinearUnit;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISGeodesicSectorParameters;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The required parameters for calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.sectorGeodesic">ArcGISGeometryEngine.sectorGeodesic</see>.
/// </summary>
/// <remarks>
/// The parameters needed when calling GeometryEngine's sectorGeodesic method.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISGeodesicSectorParameters :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// Creates a new and empty <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters">ArcGISGeodesicSectorParameters</see> object.
    /// </summary>
    /// <since>1.0.0</since>
    static UArcGISGeodesicSectorParameters* CreateArcGISGeodesicSectorParameters();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// Creates a new <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters">ArcGISGeodesicSectorParameters</see> object with the given values.
    /// </summary>
    /// <param name="axisDirection">The direction of the major axis of the ellipse as an angle in the given angular unit.</param>
    /// <param name="angularUnit">The angular unit of measure. If null degrees are assumed.</param>
    /// <param name="center">The center of the ellipse.</param>
    /// <param name="linearUnit">The linear unit of measure. If null meters are assumed.</param>
    /// <param name="maxPointCount">The max number of vertices in the ellipse.</param>
    /// <param name="maxSegmentLength">The max segment length of the result approximation in the given linear unit.</param>
    /// <param name="geometryType">The type of output geometry.</param>
    /// <param name="sectorAngle">The sweep angle of the sector in angular_unit.</param>
    /// <param name="semiAxis1Length">The length of the semi-major or semi-minor axis of the ellipse in the given linear unit.</param>
    /// <param name="semiAxis2Length">The length of the semi-major or semi-minor axis of the ellipse in the given linear unit.</param>
    /// <param name="startDirection">The direction of starting radius of the sector as an angle in angular_unit.</param>
    /// <since>1.0.0</since>
    static UArcGISGeodesicSectorParameters* CreateArcGISGeodesicSectorParametersWith(double axisDirection, UArcGISAngularUnit* angularUnit, UArcGISPoint* center, UArcGISLinearUnit* linearUnit, int32 maxPointCount, double maxSegmentLength, EArcGISGeometryType::Type geometryType, double sectorAngle, double semiAxis1Length, double semiAxis2Length, double startDirection);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// Creates a new <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters">ArcGISGeodesicSectorParameters</see> object with the given values.
    /// </summary>
    /// <remarks>
    /// The geodesic sector parameter set returned contains the following default values:
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
    /// <param name="sectorAngle">The sweep angle of the sector in degrees.</param>
    /// <param name="startDirection">The direction of starting radius of the sector as an angle in degrees.</param>
    /// <since>1.0.0</since>
    static UArcGISGeodesicSectorParameters* CreateArcGISGeodesicSectorParametersWithCenterAndAxisLengthsAndSectorAngleAndStartDirection(UArcGISPoint* center, double semiAxis1Length, double semiAxis2Length, double sectorAngle, double startDirection);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.axisDirection">ArcGISGeodesicSectorParameters.axisDirection</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.sectorAngle">ArcGISGeodesicSectorParameters.sectorAngle</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.startDirection">ArcGISGeodesicSectorParameters.startDirection</see>.
    /// </summary>
    /// <remarks>
    /// By default, the angular unit is degrees.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISAngularUnit* GetAngularUnit();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.axisDirection">ArcGISGeodesicSectorParameters.axisDirection</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.sectorAngle">ArcGISGeodesicSectorParameters.sectorAngle</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.startDirection">ArcGISGeodesicSectorParameters.startDirection</see>.
    /// </summary>
    /// <remarks>
    /// By default, the angular unit is degrees.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetAngularUnit(UArcGISAngularUnit* angularUnit);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The direction of the major axis of the ellipse as an angle in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetAxisDirection();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The direction of the major axis of the ellipse as an angle in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetAxisDirection(double axisDirection);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The center of the ellipse.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISPoint* GetCenter();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The center of the ellipse.
    /// </summary>
    /// <since>1.0.0</since>
    void SetCenter(UArcGISPoint* center);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The type of the output geometry.
    /// </summary>
    /// <since>1.0.0</since>
    EArcGISGeometryType::Type GetGeometryType();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The type of the output geometry.
    /// </summary>
    /// <since>1.0.0</since>
    void SetGeometryType(EArcGISGeometryType::Type geometryType);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.semiAxis1Length">ArcGISGeodesicSectorParameters.semiAxis1Length</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.semiAxis2Length">ArcGISGeodesicSectorParameters.semiAxis2Length</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.maxSegmentLength">ArcGISGeodesicSectorParameters.maxSegmentLength</see>.
    /// </summary>
    /// <remarks>
    /// By default, the linear unit is meters.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISLinearUnit* GetLinearUnit();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.semiAxis1Length">ArcGISGeodesicSectorParameters.semiAxis1Length</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.semiAxis2Length">ArcGISGeodesicSectorParameters.semiAxis2Length</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.maxSegmentLength">ArcGISGeodesicSectorParameters.maxSegmentLength</see>.
    /// </summary>
    /// <remarks>
    /// By default, the linear unit is meters.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetLinearUnit(UArcGISLinearUnit* linearUnit);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The max segment length of the result, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetMaxSegmentLength();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The max segment length of the result, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetMaxSegmentLength(double maxSegmentLength);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The sweep angle of the sector, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// The sweep angle goes clockwise from the starting radius.
    /// </summary>
    /// <since>1.0.0</since>
    double GetSectorAngle();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The sweep angle of the sector, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// The sweep angle goes clockwise from the starting radius.
    /// </summary>
    /// <since>1.0.0</since>
    void SetSectorAngle(double sectorAngle);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetSemiAxis1Length();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetSemiAxis1Length(double semiAxis1Length);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetSemiAxis2Length();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetSemiAxis2Length(double semiAxis2Length);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The direction of starting radius of the sector as an angle, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetStartDirection();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeodesicSectorParameters")
    /// <summary>
    /// The direction of starting radius of the sector as an angle, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetStartDirection(double startDirection);
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters> APIObject;
};