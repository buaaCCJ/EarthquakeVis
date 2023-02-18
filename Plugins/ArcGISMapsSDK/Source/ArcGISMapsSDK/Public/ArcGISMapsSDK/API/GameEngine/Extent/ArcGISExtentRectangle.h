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
/// Rectangle extent
/// </summary>
/// <remarks>
/// Rectangle extent
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISExtentRectangle :
    public ArcGISExtent
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates an rectangle extent centered on provided coordinates.
    /// </summary>
    /// <param name="center">Rectangle center</param>
    /// <param name="width">Side length along the east-to-west axis, in meters</param>
    /// <param name="height">Side length along the north-to-south axis, in meters</param>
    /// <since>1.0.0</since>
    ArcGISExtentRectangle(const Geometry::ArcGISPoint& center, double width, double height);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// Side length along the north-to-south axis, in meters
    /// </summary>
    /// <since>1.0.0</since>
    double GetHeight() const;
    
    /// <summary>
    /// Side length along the east-to-west axis, in meters
    /// </summary>
    /// <since>1.0.0</since>
    double GetWidth() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISExtentRectangle(void* handle);
    ArcGISExtentRectangle(const ArcGISExtentRectangle&) = delete;
    ArcGISExtentRectangle(ArcGISExtentRectangle&& other) noexcept;
    ArcGISExtentRectangle();
    virtual ~ArcGISExtentRectangle() = default;
    
    ArcGISExtentRectangle& operator=(const ArcGISExtentRectangle&) = delete;
    ArcGISExtentRectangle& operator=(ArcGISExtentRectangle&& other) = default;
    #pragma endregion Special Members
};
} // namespace Extent
} // namespace GameEngine
} // namespace Esri