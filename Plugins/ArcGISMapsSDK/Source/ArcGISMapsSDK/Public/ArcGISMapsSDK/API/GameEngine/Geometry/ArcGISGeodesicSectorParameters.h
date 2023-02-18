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
class ArcGISAngularUnit;
enum class ArcGISGeometryType;
class ArcGISLinearUnit;
class ArcGISPoint;

/// <summary>
/// The required parameters for calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.sectorGeodesic">ArcGISGeometryEngine.sectorGeodesic</see>.
/// </summary>
/// <remarks>
/// The parameters needed when calling GeometryEngine's sectorGeodesic method.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISGeodesicSectorParameters
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a new and empty <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters">ArcGISGeodesicSectorParameters</see> object.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISGeodesicSectorParameters();
    
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
    ArcGISGeodesicSectorParameters(double axisDirection, const ArcGISAngularUnit& angularUnit, const ArcGISPoint& center, const ArcGISLinearUnit& linearUnit, uint32_t maxPointCount, double maxSegmentLength, ArcGISGeometryType geometryType, double sectorAngle, double semiAxis1Length, double semiAxis2Length, double startDirection);
    
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
    ArcGISGeodesicSectorParameters(const ArcGISPoint& center, double semiAxis1Length, double semiAxis2Length, double sectorAngle, double startDirection);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.axisDirection">ArcGISGeodesicSectorParameters.axisDirection</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.sectorAngle">ArcGISGeodesicSectorParameters.sectorAngle</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.startDirection">ArcGISGeodesicSectorParameters.startDirection</see>.
    /// </summary>
    /// <remarks>
    /// By default, the angular unit is degrees.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISAngularUnit GetAngularUnit() const;
    void SetAngularUnit(const ArcGISAngularUnit& angularUnit);
    
    /// <summary>
    /// The direction of the major axis of the ellipse as an angle in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetAxisDirection() const;
    void SetAxisDirection(double axisDirection);
    
    /// <summary>
    /// The center of the ellipse.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISPoint GetCenter() const;
    void SetCenter(const ArcGISPoint& center);
    
    /// <summary>
    /// The type of the output geometry.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISGeometryType GetGeometryType() const;
    void SetGeometryType(const ArcGISGeometryType& geometryType);
    
    /// <summary>
    /// The unit of measure for <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.semiAxis1Length">ArcGISGeodesicSectorParameters.semiAxis1Length</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.semiAxis2Length">ArcGISGeodesicSectorParameters.semiAxis2Length</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.maxSegmentLength">ArcGISGeodesicSectorParameters.maxSegmentLength</see>.
    /// </summary>
    /// <remarks>
    /// By default, the linear unit is meters.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISLinearUnit GetLinearUnit() const;
    void SetLinearUnit(const ArcGISLinearUnit& linearUnit);
    
    /// <summary>
    /// The max number of vertices in the ellipse.
    /// </summary>
    /// <since>1.0.0</since>
    uint32_t GetMaxPointCount() const;
    void SetMaxPointCount(uint32_t maxPointCount);
    
    /// <summary>
    /// The max segment length of the result, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetMaxSegmentLength() const;
    void SetMaxSegmentLength(double maxSegmentLength);
    
    /// <summary>
    /// The sweep angle of the sector, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// The sweep angle goes clockwise from the starting radius.
    /// </summary>
    /// <since>1.0.0</since>
    double GetSectorAngle() const;
    void SetSectorAngle(double sectorAngle);
    
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetSemiAxis1Length() const;
    void SetSemiAxis1Length(double semiAxis1Length);
    
    /// <summary>
    /// The length of the semi-major or semi-minor axis of the ellipse, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.linearUnit">ArcGISGeodesicSectorParameters.linearUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetSemiAxis2Length() const;
    void SetSemiAxis2Length(double semiAxis2Length);
    
    /// <summary>
    /// The direction of starting radius of the sector as an angle, in <see cref="Esri::GameEngine::Geometry::ArcGISGeodesicSectorParameters.angularUnit">ArcGISGeodesicSectorParameters.angularUnit</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetStartDirection() const;
    void SetStartDirection(double startDirection);
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISGeodesicSectorParameters(void* handle);
    ArcGISGeodesicSectorParameters(const ArcGISGeodesicSectorParameters&) = delete;
    ArcGISGeodesicSectorParameters(ArcGISGeodesicSectorParameters&& other) noexcept;
    ~ArcGISGeodesicSectorParameters();
    
    ArcGISGeodesicSectorParameters& operator=(const ArcGISGeodesicSectorParameters&) = delete;
    ArcGISGeodesicSectorParameters& operator=(ArcGISGeodesicSectorParameters&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri