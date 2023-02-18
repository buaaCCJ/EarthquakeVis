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
namespace Security
{
/// <summary>
/// A base class for authentication configurations
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISAuthenticationConfiguration
{
    friend class ArcGISAuthenticationConfigurationInternal;

public:

public:
    #pragma region Special Members
    explicit ArcGISAuthenticationConfiguration(void* handle);
    ArcGISAuthenticationConfiguration(const ArcGISAuthenticationConfiguration&) = delete;
    ArcGISAuthenticationConfiguration(ArcGISAuthenticationConfiguration&& other) noexcept;
    ArcGISAuthenticationConfiguration() = default;
    ~ArcGISAuthenticationConfiguration();
    
    ArcGISAuthenticationConfiguration& operator=(const ArcGISAuthenticationConfiguration&) = delete;
    ArcGISAuthenticationConfiguration& operator=(ArcGISAuthenticationConfiguration&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Security
} // namespace GameEngine
} // namespace Esri