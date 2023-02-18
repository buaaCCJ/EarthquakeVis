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
template<typename Key, typename Value> class ArcGISDictionary;
} // namespace Unreal

namespace GameEngine
{
namespace View
{
namespace State
{
enum class ArcGISViewStateMessageType;

/// <summary>
/// A view message.
/// </summary>
/// <remarks>
/// This object contains the error or warning message that comes from the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISViewStateMessage
{
public:
    #pragma region Methods
    /// <summary>
    /// Retrieve the additional information if it exists.
    /// </summary>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISViewStateMessage">ArcGISViewStateMessage</see>.
    /// </returns>
    /// <since>1.0.0</since>
    Unreal::ArcGISDictionary<FString, FString> GetAdditionalInformation() const;
    
    /// <summary>
    /// Retrieve warning or error code.
    /// </summary>
    /// <returns>
    /// The unique code identifies a error or warning.
    /// </returns>
    /// <since>1.0.0</since>
    uint32_t GetCode() const;
    
    /// <summary>
    /// Retrieve error or warning message if it exists.
    /// </summary>
    /// <returns>
    /// This message contains the error or warning description.
    /// </returns>
    /// <since>1.0.0</since>
    FString GetMessage() const;
    
    /// <summary>
    /// Retrieve the message type
    /// </summary>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISViewStateMessageType">ArcGISViewStateMessageType</see>
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISViewStateMessageType GetMessageType() const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISViewStateMessage(void* handle);
    ArcGISViewStateMessage(const ArcGISViewStateMessage&) = delete;
    ArcGISViewStateMessage(ArcGISViewStateMessage&& other) noexcept;
    ArcGISViewStateMessage() = default;
    ~ArcGISViewStateMessage();
    
    ArcGISViewStateMessage& operator=(const ArcGISViewStateMessage&) = delete;
    ArcGISViewStateMessage& operator=(ArcGISViewStateMessage&& other) noexcept;
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