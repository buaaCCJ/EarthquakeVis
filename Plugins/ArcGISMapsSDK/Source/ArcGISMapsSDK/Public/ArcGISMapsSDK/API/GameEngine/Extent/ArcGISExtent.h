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
} // namespace Geometry

namespace Extent
{
/// <summary>
/// Abstract class of any kind of extent
/// </summary>
/// <remarks>
/// Abstract class of any kind of extent.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISExtent
{
    friend class ArcGISExtentInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The center of the extent.
    /// </summary>
    /// <since>1.0.0</since>
    Geometry::ArcGISPoint GetCenter() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISExtent(void* handle);
    ArcGISExtent(const ArcGISExtent&) = delete;
    ArcGISExtent(ArcGISExtent&& other) noexcept;
    ArcGISExtent() = default;
    ~ArcGISExtent();
    
    ArcGISExtent& operator=(const ArcGISExtent&) = delete;
    ArcGISExtent& operator=(ArcGISExtent&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Extent
} // namespace GameEngine
} // namespace Esri