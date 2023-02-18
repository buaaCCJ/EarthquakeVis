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
/// <summary>
/// A block of memory containing values of struct or primitive type T
/// </summary>
/// <remarks>
/// DataBuffer owns its chunk of memory and this memory will remain valid for the lifetime of the DataBuffer.
/// </remarks>
/// <since>1.0.0</since>
class ArcGISIntermediateDataBuffer
{
public:
    #pragma region Properties
    /// <summary>
    /// A pointer to the beginning of the block of memory.
    /// </summary>
    /// <since>1.0.0</since>
    void* GetData() const;
    
    /// <summary>
    /// The size of one item, in bytes
    /// </summary>
    /// <remarks>
    /// Possibly not needed
    /// </remarks>
    /// <since>1.0.0</since>
    size_t GetItemSize() const;
    
    /// <summary>
    /// The size of the block of memory, in bytes
    /// </summary>
    /// <since>1.0.0</since>
    size_t GetSizeBytes() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISIntermediateDataBuffer(void* handle);
    
    ArcGISIntermediateDataBuffer(const ArcGISIntermediateDataBuffer&) = delete;
    
    ArcGISIntermediateDataBuffer(ArcGISIntermediateDataBuffer&& other) noexcept;
    
    ArcGISIntermediateDataBuffer() = default;
    
    ~ArcGISIntermediateDataBuffer();
    
    ArcGISIntermediateDataBuffer& operator=(const ArcGISIntermediateDataBuffer&) = delete;
    
    ArcGISIntermediateDataBuffer& operator=(ArcGISIntermediateDataBuffer&& other) noexcept;
    
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace GameEngine
} // namespace Esri