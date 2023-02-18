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
enum class ArcGISLayerViewStatus;
class ArcGISViewStateMessage;

/// <summary>
/// A layer view state object.
/// </summary>
/// <remarks>
/// This object allows you to know the current state of a layer in a view.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISLayerViewState
{
public:
    #pragma region Properties
    /// <summary>
    /// Retrieve the message if it exists.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISLayerViewState">ArcGISLayerViewState</seealso>
    /// <since>1.0.0</since>
    ArcGISViewStateMessage GetMessage() const;
    
    /// <summary>
    /// Retrieve the layer view status.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::View::State::ArcGISLayerViewStatus">ArcGISLayerViewStatus</seealso>
    /// <since>1.0.0</since>
    ArcGISLayerViewStatus GetStatus() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISLayerViewState(void* handle);
    ArcGISLayerViewState(const ArcGISLayerViewState&) = delete;
    ArcGISLayerViewState(ArcGISLayerViewState&& other) noexcept;
    ArcGISLayerViewState() = default;
    ~ArcGISLayerViewState();
    
    ArcGISLayerViewState& operator=(const ArcGISLayerViewState&) = delete;
    ArcGISLayerViewState& operator=(ArcGISLayerViewState&& other) noexcept;
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