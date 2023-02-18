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
namespace View
{
namespace State
{
class ArcGISViewStateMessage;
enum class ArcGISViewStatus;

/// <summary>
/// A view state object.
/// </summary>
/// <remarks>
/// This object contains the current state of the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISViewState
{
public:
    #pragma region Properties
    /// <summary>
    /// Retrieve the message if it exists.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISViewState">ArcGISViewState</seealso>
    /// <since>1.0.0</since>
    ArcGISViewStateMessage GetMessage() const;
    
    /// <summary>
    /// Retrieve the renderer view status.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISViewStatus">ArcGISViewStatus</seealso>
    /// <since>1.0.0</since>
    ArcGISViewStatus GetStatus() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISViewState(void* handle);
    ArcGISViewState(const ArcGISViewState&) = delete;
    ArcGISViewState(ArcGISViewState&& other) noexcept;
    ArcGISViewState() = default;
    ~ArcGISViewState();
    
    ArcGISViewState& operator=(const ArcGISViewState&) = delete;
    ArcGISViewState& operator=(ArcGISViewState&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace State
} // namespace View
} // namespace GameEngine
} // namespace Esri