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
template<typename T> class ArcGISDataBuffer;
} // namespace Unreal

namespace GameEngine
{
namespace RCQ
{
/// <summary>
/// Stream render commands to the game engine
/// </summary>
/// <since>1.0.0</since>
class ArcGISRenderCommandServer
{
public:
    #pragma region Methods
    /// <summary>
    /// Get an object with the render command cache since the last time the method was called
    /// </summary>
    /// <remarks>
    /// The DataBuffer contains the render commands serialized as a consecutive array of [type_of_command, render_command_parameters].
    /// Since the length of each render command is different, the de-serialization has to be done dynamically, reading the commands one by one
    /// and dynamically advancing the pointer to the DataBuffer.
    /// </remarks>
    /// <returns>
    /// An object with the render command cache since the last time the method was called
    /// </returns>
    /// <since>1.0.0</since>
    Unreal::ArcGISDataBuffer<uint8_t> GetRenderCommands() const;
    
    /// <summary>
    /// The game engine must call this method to notify the runtimecore when created Renderables are drawable (i.e. their GPU resources have been created).
    /// The runtimecore uses this information when determining what Renderables to make visible.
    /// </summary>
    /// <param name="callbackTokens">List of Renderables that have GPU resources, identified by their uint64 callbackToken values</param>
    /// <since>1.0.0</since>
    void NotifyRenderableHasGPUResources(TArrayView<uint8> callbackTokens);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISRenderCommandServer(void* handle);
    ArcGISRenderCommandServer(const ArcGISRenderCommandServer&) = delete;
    ArcGISRenderCommandServer(ArcGISRenderCommandServer&& other) noexcept;
    ArcGISRenderCommandServer() = default;
    ~ArcGISRenderCommandServer();
    
    ArcGISRenderCommandServer& operator=(const ArcGISRenderCommandServer&) = delete;
    ArcGISRenderCommandServer& operator=(ArcGISRenderCommandServer&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri