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
enum class ArcGISElevationSourceViewStatus;
class ArcGISViewStateMessage;

/// <summary>
/// A elevation source view state object.
/// </summary>
/// <remarks>
/// This object allows you to know the current state of a elevation source in a view.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISElevationSourceViewState
{
public:
    #pragma region Properties
    /// <summary>
    /// Retrieve the message if it exists.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewState">ArcGISElevationSourceViewState</seealso>
    /// <since>1.0.0</since>
    ArcGISViewStateMessage GetMessage() const;
    
    /// <summary>
    /// Retrieve the elevation source status.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewStatus">ArcGISElevationSourceViewStatus</seealso>
    /// <since>1.0.0</since>
    ArcGISElevationSourceViewStatus GetStatus() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISElevationSourceViewState(void* handle);
    ArcGISElevationSourceViewState(const ArcGISElevationSourceViewState&) = delete;
    ArcGISElevationSourceViewState(ArcGISElevationSourceViewState&& other) noexcept;
    ArcGISElevationSourceViewState() = default;
    ~ArcGISElevationSourceViewState();
    
    ArcGISElevationSourceViewState& operator=(const ArcGISElevationSourceViewState&) = delete;
    ArcGISElevationSourceViewState& operator=(ArcGISElevationSourceViewState&& other) noexcept;
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