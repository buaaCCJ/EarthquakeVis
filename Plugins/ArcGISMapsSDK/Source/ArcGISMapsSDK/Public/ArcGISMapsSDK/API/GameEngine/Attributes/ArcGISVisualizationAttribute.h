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
/// Information about the visualization attribute
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISVisualizationAttribute
{
public:
    #pragma region Properties
    /// <summary>
    /// The visualization attribute data for a particular node.
    /// </summary>
    /// <remarks>
    /// Data is only valid during the scope of <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessorEvent">ArcGISAttributeProcessorEvent</see>.
    /// </remarks>
    /// <since>1.0.0</since>
    TArrayView<uint8> GetData() const;
    
    /// <summary>
    /// The visualization attribute name
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName() const;
    
    /// <summary>
    /// The type of the attribute.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Attributes::ArcGISVisualizationAttributeType">ArcGISVisualizationAttributeType</seealso>
    /// <since>1.0.0</since>
    ArcGISVisualizationAttributeType GetVisualizationAttributeType() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISVisualizationAttribute(void* handle);
    ArcGISVisualizationAttribute(const ArcGISVisualizationAttribute&) = delete;
    ArcGISVisualizationAttribute(ArcGISVisualizationAttribute&& other) noexcept;
    ArcGISVisualizationAttribute() = default;
    ~ArcGISVisualizationAttribute();
    
    ArcGISVisualizationAttribute& operator=(const ArcGISVisualizationAttribute&) = delete;
    ArcGISVisualizationAttribute& operator=(ArcGISVisualizationAttribute&& other) noexcept;
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