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

#include "ArcGISMapsSDK/API/Standard/ArcGISFutureCompletedEvent.h"

namespace Esri
{
namespace Unreal
{
class ArcGISException;
} // namespace Unreal

namespace Standard
{
class ArcGISElement;
enum class ArcGISFutureStatus;

/// <summary>
/// A <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> represents work that can be completed asynchronously and concurrently with other work.
/// </summary>
/// <remarks>
/// A <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> can be either executing or complete as indicated by <see cref="Esri::Standard::ArcGISIntermediateFuture.isDone">ArcGISIntermediateFuture.isDone</see>. 
/// Notification of completion is available through the callback <see cref="Esri::Standard::ArcGISFutureCompletedEvent">ArcGISFutureCompletedEvent</see>.
/// 
/// When complete, the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> will have either completed successfully or failed with an error
/// during its execution. A successfully completed <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> returns null from <see cref="Esri::Standard::ArcGISIntermediateFuture.getError">ArcGISIntermediateFuture.getError</see>
/// and the result can be obtained from <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see>. Whereas a failed <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> returns an <see cref="Esri::Standard::ArcGISError">ArcGISError</see>,
/// including if the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> was canceled.
/// 
/// Successfully completed <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> instances may return a result to the caller. The result is accessed by
/// calling <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see>. If there is no result an empty <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> is returned.
/// 
/// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is executing and <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> or <see cref="Esri::Standard::ArcGISIntermediateFuture.wait">ArcGISIntermediateFuture.wait</see> is called the 
/// thread will be blocked until the completion of the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see>. Once the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is complete
/// subsequent calls will no longer block. If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> fails, but not canceled, both
/// <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> or <see cref="Esri::Standard::ArcGISIntermediateFuture.wait">ArcGISIntermediateFuture.wait</see> will result in an error. A cancelled <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> will return a null
/// from <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> and <see cref="Esri::Standard::ArcGISFutureStatus.canceled">ArcGISFutureStatus.canceled</see> from <see cref="Esri::Standard::ArcGISIntermediateFuture.wait">ArcGISIntermediateFuture.wait</see>.
///         
/// To avoid blocking calling threads with either <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> or <see cref="Esri::Standard::ArcGISIntermediateFuture.wait">ArcGISIntermediateFuture.wait</see>, it is recommended to
/// use the <see cref="Esri::Standard::ArcGISFutureCompletedEvent">ArcGISFutureCompletedEvent</see> to receive a completion notification before checking <see cref="Esri::Standard::ArcGISIntermediateFuture.getError">ArcGISIntermediateFuture.getError</see>
/// for errors and then calling <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> to access the return value.
/// 
/// An executing <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> can be requested to cancel by calling <see cref="Esri::Standard::ArcGISIntermediateFuture.cancel">ArcGISIntermediateFuture.cancel</see>. If the cancellation is
/// observed by the executing code, then the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> returns an <see cref="Esri::Standard::ArcGISError">ArcGISError</see> from <see cref="Esri::Standard::ArcGISIntermediateFuture.getError">ArcGISIntermediateFuture.getError</see>.
/// </remarks>
/// <since>1.0.0</since>
class ArcGISIntermediateFuture
{
public:
    #pragma region Methods
    /// <summary>
    /// Request cancellation of the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see>.
    /// </summary>
    /// <remarks>
    /// Cancellation is a cooperative mechanism. Cancel can be called on the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see>, but the
    /// executing code must also periodically check for cancellation and terminate. It is possible
    /// that a canceled <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> could still complete successfully, if cancel was called after
    /// the executing code checked for cancellation. 
    /// Once cancel is called, <see cref="Esri::Standard::ArcGISIntermediateFuture.isCanceled">ArcGISIntermediateFuture.isCanceled</see> will return true.
    /// If the executing code observed the cancellation, the following will apply:
    /// * <see cref="Esri::Standard::ArcGISIntermediateFuture.getError">ArcGISIntermediateFuture.getError</see> returns an error indicating cancellation
    /// * <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> returns null
    /// * <see cref="Esri::Standard::ArcGISIntermediateFuture.wait">ArcGISIntermediateFuture.wait</see> returns <see cref="Esri::Standard::ArcGISFutureStatus.canceled">ArcGISFutureStatus.canceled</see>
    /// </remarks>
    /// <returns>
    /// true if the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> was requested to cancel, false if the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> had already been
    /// requested to cancel.
    /// Returns false if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    bool Cancel();
    
    /// <summary>
    /// Returns the result of the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see>.
    /// </summary>
    /// <remarks>
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is successful then <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> will return the result. For a
    /// <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> which is successful but has no result then an empty <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> is returned.
    /// 
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> has failed during execution, the call to <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> will result
    /// in an error.
    /// 
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is not complete, a call to <see cref="Esri::Standard::ArcGISIntermediateFuture.get">ArcGISIntermediateFuture.get</see> will block the calling
    /// thread until the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> completes execution.
    /// </remarks>
    /// <returns>
    /// The result of the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> or null if the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> was canceled.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElement Get() const;
    
    /// <summary>
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is executing, or has completed successfully, a null is returned. If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> has failed returns the error.
    /// </summary>
    /// <remarks>
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is executing, or completed successfully null is returned. For a
    /// completed but failed <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> the failure is returned in an <see cref="Esri::Standard::ArcGISError">ArcGISError</see>.
    /// 
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> terminated due to a cancellation request, this is also a failure and returns an error.
    /// </remarks>
    /// <returns>
    /// Returns the <see cref="Esri::Standard::ArcGISError">ArcGISError</see> instance or null.
    /// </returns>
    /// <since>1.0.0</since>
    Unreal::ArcGISException GetError() const;
    
    /// <summary>
    /// Indicates if the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> has been requested to cancel.
    /// </summary>
    /// <returns>
    /// true if the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> has been requested to cancel or false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool IsCanceled() const;
    
    /// <summary>
    /// Indicates if the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> has completed execution.
    /// </summary>
    /// <returns>
    /// true if the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> has completed, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool IsDone() const;
    
    /// <summary>
    /// Waits for the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> to complete.
    /// </summary>
    /// <remarks>
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is successful or canceled then <see cref="Esri::Standard::ArcGISIntermediateFuture.wait">ArcGISIntermediateFuture.wait</see> will return the
    /// <see cref="Esri::Standard::ArcGISFutureStatus">ArcGISFutureStatus</see>.
    /// 
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> has failed during execution, the call to <see cref="Esri::Standard::ArcGISIntermediateFuture.wait">ArcGISIntermediateFuture.wait</see> will
    /// result in an error.
    /// 
    /// If the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is not complete, a call to <see cref="Esri::Standard::ArcGISIntermediateFuture.wait">ArcGISIntermediateFuture.wait</see> will block the calling
    /// thread until the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> completes execution.
    /// </remarks>
    /// <returns>
    /// The <see cref="Esri::Standard::ArcGISFutureStatus">ArcGISFutureStatus</see>. Returns <see cref="Esri::Standard::ArcGISFutureStatus.unknown">ArcGISFutureStatus.unknown</see> if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISFutureStatus Wait() const;
    #pragma endregion Methods
    
    #pragma region Events
    /// <summary>
    /// Sets the function that will be called when the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> is completed.
    /// </summary>
    /// <remarks>
    /// When the <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> completes then <see cref="Esri::Standard::ArcGISIntermediateFuture.isDone">ArcGISIntermediateFuture.isDone</see> is true and this callback
    /// will be called.
    /// 
    /// Setting this callback after <see cref="Esri::Standard::ArcGISIntermediateFuture">ArcGISIntermediateFuture</see> has completed will immediately call the
    /// callback.
    /// 
    /// Setting the callback to null after it has already been set will stop the function
    /// from being called.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISFutureCompletedEvent GetTaskCompleted() const;
    void SetTaskCompleted(ArcGISFutureCompletedEvent taskCompleted);
    #pragma endregion Events

public:
    #pragma region Special Members
    explicit ArcGISIntermediateFuture(void* handle);
    
    ArcGISIntermediateFuture(const ArcGISIntermediateFuture&) = delete;
    
    ArcGISIntermediateFuture(ArcGISIntermediateFuture&& other) noexcept;
    
    ArcGISIntermediateFuture() = default;
    
    ~ArcGISIntermediateFuture();
    
    ArcGISIntermediateFuture& operator=(const ArcGISIntermediateFuture&) = delete;
    
    ArcGISIntermediateFuture& operator=(ArcGISIntermediateFuture&& other) noexcept;
    
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
    ArcGISFutureCompletedEvent m_taskCompleted;
};
} // namespace Standard
} // namespace Esri