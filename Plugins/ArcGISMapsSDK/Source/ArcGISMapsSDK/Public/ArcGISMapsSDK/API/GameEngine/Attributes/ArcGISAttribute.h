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
enum class ArcGISAttributeType;

/// <summary>
/// Information about the attribute
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISAttribute
{
public:
    #pragma region Properties
    /// <summary>
    /// The type of the attribute.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Attributes::ArcGISAttributeType">ArcGISAttributeType</seealso>
    /// <since>1.0.0</since>
    ArcGISAttributeType GetAttributeType() const;
    
    /// <summary>
    /// A column worth of attribute data.
    /// </summary>
    /// <remarks>
    /// Data is only valid during the scope of <see cref="Esri::GameEngine::Attributes::ArcGISAttributeProcessorEvent">ArcGISAttributeProcessorEvent</see>.
    /// </remarks>
    /// <since>1.0.0</since>
    TArrayView<uint8> GetData() const;
    
    /// <summary>
    /// The attribute name
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISAttribute(void* handle);
    ArcGISAttribute(const ArcGISAttribute&) = delete;
    ArcGISAttribute(ArcGISAttribute&& other) noexcept;
    ArcGISAttribute() = default;
    ~ArcGISAttribute();
    
    ArcGISAttribute& operator=(const ArcGISAttribute&) = delete;
    ArcGISAttribute& operator=(ArcGISAttribute&& other) noexcept;
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