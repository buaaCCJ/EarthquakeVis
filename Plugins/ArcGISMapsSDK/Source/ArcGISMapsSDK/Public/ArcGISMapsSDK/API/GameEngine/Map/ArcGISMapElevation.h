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
namespace Unreal
{
template<typename T> class ArcGISCollection;
} // namespace Unreal

namespace GameEngine
{
namespace Elevation
{
namespace Base
{
class ArcGISElevationSource;
} // namespace Base
} // namespace Elevation

namespace Map
{
/// <summary>
/// The map contains elevation sources and additional properties and can be displayed in a ArcGISRenderComponent.
/// </summary>
/// <remarks>
/// The map represent the document with all data that will be renderer by ArcGISRenderComponent.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISMapElevation
{
public:
    #pragma region Constructors
    /// <summary>
    /// Create a elevation for the map with no elevation sources
    /// </summary>
    /// <remarks>
    /// Create elevation with no elevation sources
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISMapElevation();
    
    /// <summary>
    /// Create a elevation for the map with one elevation source
    /// </summary>
    /// <remarks>
    /// Create elevation with a single elevation source
    /// </remarks>
    /// <param name="elevationSource">Elevation source</param>
    /// <since>1.0.0</since>
    ArcGISMapElevation(Elevation::Base::ArcGISElevationSource& elevationSource);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// List of elevation sources included on the elevation.
    /// </summary>
    /// <remarks>
    /// At present, the ArcGISElevationSourceCollection may contain a maximum of one elevation source.
    /// </remarks>
    /// <since>1.0.0</since>
    Unreal::ArcGISCollection<Elevation::Base::ArcGISElevationSource> GetElevationSources() const;
    void SetElevationSources(const Unreal::ArcGISCollection<Elevation::Base::ArcGISElevationSource>& elevationSources);
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISMapElevation(void* handle);
    ArcGISMapElevation(const ArcGISMapElevation&) = delete;
    ArcGISMapElevation(ArcGISMapElevation&& other) noexcept;
    ~ArcGISMapElevation();
    
    ArcGISMapElevation& operator=(const ArcGISMapElevation&) = delete;
    ArcGISMapElevation& operator=(ArcGISMapElevation&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Map
} // namespace GameEngine
} // namespace Esri