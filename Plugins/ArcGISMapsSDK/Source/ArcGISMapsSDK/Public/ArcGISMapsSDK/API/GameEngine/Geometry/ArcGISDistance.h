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
class ArcGISLinearUnit;

/// <summary>
/// <see cref="Esri::GameEngine::Geometry::ArcGISDistance">ArcGISDistance</see> holds the distance measurement data associated with a specific distance component.
/// </summary>
/// <remarks>
/// Distance contains the value and associated <see cref="Esri::GameEngine::Geometry::ArcGISLinearUnit">ArcGISLinearUnit</see> of a specific distance component.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISLinearUnit">ArcGISLinearUnit</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISDistance
{
public:
    #pragma region Properties
    /// <summary>
    /// The unit of the Distance component.
    /// </summary>
    /// <remarks>
    /// Unit is the linear unit by which the value of the distance is measured.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISLinearUnit GetUnit() const;
    
    /// <summary>
    /// The value of the Distance component.
    /// </summary>
    /// <remarks>
    /// Value is the scalar value of the distance, measured by the associated Distance Unit. Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetValue() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISDistance(void* handle);
    ArcGISDistance(const ArcGISDistance&) = delete;
    ArcGISDistance(ArcGISDistance&& other) noexcept;
    ArcGISDistance() = default;
    ~ArcGISDistance();
    
    ArcGISDistance& operator=(const ArcGISDistance&) = delete;
    ArcGISDistance& operator=(ArcGISDistance&& other) noexcept;
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