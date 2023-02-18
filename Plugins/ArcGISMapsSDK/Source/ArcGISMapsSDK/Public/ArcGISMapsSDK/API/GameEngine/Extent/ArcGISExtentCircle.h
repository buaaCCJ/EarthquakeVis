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

#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtent.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISPoint;
} // namespace Geometry

namespace Extent
{
/// <summary>
/// Circle extent
/// </summary>
/// <remarks>
/// Circle extent
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISExtentCircle :
    public ArcGISExtent
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates an circle extent centered on provided coordinates.
    /// </summary>
    /// <param name="center">Circle center</param>
    /// <param name="radius">Size of radius in meters</param>
    /// <since>1.0.0</since>
    ArcGISExtentCircle(const Geometry::ArcGISPoint& center, double radius);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// Size of radius in meters
    /// </summary>
    /// <since>1.0.0</since>
    double GetRadius() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISExtentCircle(void* handle);
    ArcGISExtentCircle(const ArcGISExtentCircle&) = delete;
    ArcGISExtentCircle(ArcGISExtentCircle&& other) noexcept;
    ArcGISExtentCircle();
    virtual ~ArcGISExtentCircle() = default;
    
    ArcGISExtentCircle& operator=(const ArcGISExtentCircle&) = delete;
    ArcGISExtentCircle& operator=(ArcGISExtentCircle&& other) = default;
    #pragma endregion Special Members
};
} // namespace Extent
} // namespace GameEngine
} // namespace Esri