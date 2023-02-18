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
/// Authentication challenge
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISAuthenticationChallenge
{
    friend class ArcGISAuthenticationChallengeInternal;

public:
    #pragma region Methods
    /// <summary>
    /// Cancels the authentication challenge
    /// </summary>
    /// <since>1.0.0</since>
    void Cancel();
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISAuthenticationChallenge(void* handle);
    ArcGISAuthenticationChallenge(const ArcGISAuthenticationChallenge&) = delete;
    ArcGISAuthenticationChallenge(ArcGISAuthenticationChallenge&& other) noexcept;
    ArcGISAuthenticationChallenge() = default;
    ~ArcGISAuthenticationChallenge();
    
    ArcGISAuthenticationChallenge& operator=(const ArcGISAuthenticationChallenge&) = delete;
    ArcGISAuthenticationChallenge& operator=(ArcGISAuthenticationChallenge&& other) noexcept;
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