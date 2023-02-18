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
namespace Standard
{
/// <summary>
/// An object that represents an error.
/// </summary>
/// <since>1.0.0</since>
class ArcGISError
{
public:
    #pragma region Properties
    /// <summary>
    /// A string with additional information about the error.
    /// </summary>
    /// <remarks>
    /// The additional message is also a part of the dictionary returned by <see cref="">Error.additionalInformation</see>.
    /// </remarks>
    /// <since>1.0.0</since>
    FString GetAdditionalMessage() const;
    
    /// <summary>
    /// The error's code.
    /// </summary>
    /// <since>1.0.0</since>
    int32_t GetCode() const;
    
    /// <summary>
    /// The error's message.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetMessage() const;
    
    /// <summary>
    /// The error's user defined failure.
    /// </summary>
    /// <since>1.0.0</since>
    void* GetUserDefinedFailure() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISError(void* handle);
    ArcGISError(const ArcGISError&) = delete;
    ArcGISError(ArcGISError&& other) noexcept;
    ArcGISError() = default;
    ~ArcGISError();
    
    ArcGISError& operator=(const ArcGISError&) = delete;
    ArcGISError& operator=(ArcGISError&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Standard
} // namespace Esri