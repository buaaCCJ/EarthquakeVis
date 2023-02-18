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
class ArcGISLinearUnit;

/// <summary>
/// The returned results of calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.distanceGeodetic">ArcGISGeometryEngine.distanceGeodetic</see>.
/// </summary>
/// <remarks>
/// The results of calling GeometryEngine's distanceGeodetic methods.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISGeodeticDistanceResult
{
public:
    #pragma region Properties
    /// <summary>
    /// Output azimuth at point 1 towards point 2, in the angular unit that was used as a parameter when calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.distanceGeodetic">ArcGISGeometryEngine.distanceGeodetic</see>.
    /// (clockwise angle between tangent vector at point1 in the direction of the curve towards point2 and meridian passing through the point1).
    /// </summary>
    /// <since>1.0.0</since>
    double GetAzimuth1() const;
    
    /// <summary>
    /// Output azimuth at point 2 towards point 1, in the angular unit that was used as a parameter when calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.distanceGeodetic">ArcGISGeometryEngine.distanceGeodetic</see>.
    /// (clockwise angle between tangent vector at point2 in the direction of the curve towards point2 and meridian passing through the point2).
    /// </summary>
    /// <since>1.0.0</since>
    double GetAzimuth2() const;
    
    /// <summary>
    /// The unit of measure for azimuth1 and azimuth2.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISAngularUnit GetAzimuthUnit() const;
    
    /// <summary>
    /// The geodesic distance from the two input points, in the linear unit used as a parameter when calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.distanceGeodetic">ArcGISGeometryEngine.distanceGeodetic</see>.
    /// </summary>
    /// <since>1.0.0</since>
    double GetDistance() const;
    
    /// <summary>
    /// The unit of measure for distance.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISLinearUnit GetDistanceUnit() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISGeodeticDistanceResult(void* handle);
    ArcGISGeodeticDistanceResult(const ArcGISGeodeticDistanceResult&) = delete;
    ArcGISGeodeticDistanceResult(ArcGISGeodeticDistanceResult&& other) noexcept;
    ArcGISGeodeticDistanceResult() = default;
    ~ArcGISGeodeticDistanceResult();
    
    ArcGISGeodeticDistanceResult& operator=(const ArcGISGeodeticDistanceResult&) = delete;
    ArcGISGeodeticDistanceResult& operator=(ArcGISGeodeticDistanceResult&& other) noexcept;
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