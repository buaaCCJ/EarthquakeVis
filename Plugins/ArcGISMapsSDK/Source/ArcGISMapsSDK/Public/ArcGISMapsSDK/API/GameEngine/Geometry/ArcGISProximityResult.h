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
class ArcGISPoint;

/// <summary>
/// The returned results of calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.nearestCoordinate">ArcGISGeometryEngine.nearestCoordinate</see> and <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.nearestVertex">ArcGISGeometryEngine.nearestVertex</see>.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISProximityResult
{
public:
    #pragma region Properties
    /// <summary>
    /// The point found.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISPoint GetCoordinate() const;
    
    /// <summary>
    /// The result distance.
    /// </summary>
    /// <since>1.0.0</since>
    double GetDistance() const;
    
    /// <summary>
    /// The index of the part in which the point was found.
    /// </summary>
    /// <remarks>
    /// Returned index value should be checked against <see cref="">ProximityResult.npos</see> for validity.
    /// </remarks>
    /// <seealso cref="">ProximityResult.npos</seealso>
    /// <since>1.0.0</since>
    size_t GetPartIndex() const;
    
    /// <summary>
    /// The index of the point that was found within its part.
    /// </summary>
    /// <remarks>
    /// Returned index value should be checked against <see cref="">ProximityResult.npos</see> for validity.
    /// </remarks>
    /// <seealso cref="">ProximityResult.npos</seealso>
    /// <since>1.0.0</since>
    size_t GetPointIndex() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISProximityResult(void* handle);
    ArcGISProximityResult(const ArcGISProximityResult&) = delete;
    ArcGISProximityResult(ArcGISProximityResult&& other) noexcept;
    ArcGISProximityResult() = default;
    ~ArcGISProximityResult();
    
    ArcGISProximityResult& operator=(const ArcGISProximityResult&) = delete;
    ArcGISProximityResult& operator=(ArcGISProximityResult&& other) noexcept;
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