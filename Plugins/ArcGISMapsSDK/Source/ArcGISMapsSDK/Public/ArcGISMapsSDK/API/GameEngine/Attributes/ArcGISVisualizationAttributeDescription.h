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
namespace Attributes
{
enum class ArcGISVisualizationAttributeType;

/// <summary>
/// Describes how the visualization attributes are provided to <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessorEvent">ArcGISAttributeProcessorEvent</see>
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISVisualizationAttributeDescription
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a VisualizationAttributeDescription object.
    /// </summary>
    /// <param name="name">The attribute name</param>
    /// <param name="visualizationAttributeType">The type of the visualization attribute.</param>
    /// <since>1.0.0</since>
    ArcGISVisualizationAttributeDescription(const FString& name, ArcGISVisualizationAttributeType visualizationAttributeType);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The attribute name
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName() const;
    
    /// <summary>
    /// The type of the visualization attribute.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Attributes::ArcGISVisualizationAttributeType">ArcGISVisualizationAttributeType</seealso>
    /// <since>1.0.0</since>
    ArcGISVisualizationAttributeType GetVisualizationAttributeType() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISVisualizationAttributeDescription(void* handle);
    ArcGISVisualizationAttributeDescription(const ArcGISVisualizationAttributeDescription&) = delete;
    ArcGISVisualizationAttributeDescription(ArcGISVisualizationAttributeDescription&& other) noexcept;
    ArcGISVisualizationAttributeDescription() = default;
    ~ArcGISVisualizationAttributeDescription();
    
    ArcGISVisualizationAttributeDescription& operator=(const ArcGISVisualizationAttributeDescription&) = delete;
    ArcGISVisualizationAttributeDescription& operator=(ArcGISVisualizationAttributeDescription&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Attributes
} // namespace GameEngine
} // namespace Esri