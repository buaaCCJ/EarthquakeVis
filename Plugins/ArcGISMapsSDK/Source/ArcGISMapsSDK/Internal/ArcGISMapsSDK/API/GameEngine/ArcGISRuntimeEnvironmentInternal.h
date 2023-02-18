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

#include "ArcGISMapsSDK/API/GameEngine/ArcGISRuntimeEnvironmentErrorEvent.h"

namespace Esri
{
namespace Standard
{
enum class ArcGISRuntimeClient;
} // namespace Standard

namespace GameEngine
{
/// <summary>
/// Provides access to and manipulation of environment settings, such as configurations for the operating environment and licenses for deployment.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISRuntimeEnvironmentInternal
{
    friend class ArcGISRuntimeEnvironmentInternal;

public:
    #pragma region Properties
    /// <summary>
    /// Control using authentication at the core level.
    /// </summary>
    /// <remarks>
    /// Defaulted to false. Should be set only once if opting in to authentication at the core level.
    /// </remarks>
    /// <since>1.0.0</since>
    static bool GetUseCoreAuthentication();
    static void SetUseCoreAuthentication(bool useCoreAuthentication);
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Enables/disables breaking on exceptions.
    /// </summary>
    /// <param name="enable">true if the runtime should break on an exception, false otherwise.</param>
    /// <since>1.0.0</since>
    static void EnableBreakOnException(bool enable);
    
    /// <summary>
    /// Enables/disables memory leak detection.
    /// </summary>
    /// <remarks>
    /// Disabling will cause the runtime to dump all of the object instances that were currently being tracked and
    /// it will not track object instances from the point of disabling.  Enabling leak detection will make the
    /// runtime track all object instances allocated from the point of enabling.  By default, leak detection is turned off.
    /// </remarks>
    /// <param name="enable">true if the runtime should be tracking object allocations and deallocations, false otherwise.</param>
    /// <since>1.0.0</since>
    static void EnableLeakDetection(bool enable);
    
    /// <summary>
    /// Enables/disables raising assertion.
    /// </summary>
    /// <remarks>
    /// This is enabled by default in debug builds and disabled by default in release builds.
    /// If disable abort will not be called.
    /// </remarks>
    /// <param name="enable">true if the runtime should turn assertions on and abort, false otherwise.</param>
    /// <since>1.0.0</since>
    static void EnableRaiseAssertion(bool enable);
    
    /// <summary>
    /// Enables/disables the assert/abort dialog on Windows Desktop.
    /// </summary>
    /// <param name="enable">true the assert/abort dialog should appear with abort, break and continue options. enable false if all asserts and errors should go to the debug console.</param>
    /// <since>1.0.0</since>
    static void EnableShowAssertDialog(bool enable);
    
    /// <summary>
    /// Get the path of the directory containing the feature toggle file.
    /// </summary>
    /// <remarks>
    /// Returns the path of the directory used to find the feature toggle file 'arcgis_runtime_feature_set.txt'.
    /// This directory is set by calling <see cref="Esri::GameEngine::ArcGISRuntimeEnvironment.setFeatureToggleDirectory">ArcGISRuntimeEnvironment.setFeatureToggleDirectory</see>
    /// 
    /// Additionally when <see cref="Esri::GameEngine::ArcGISRuntimeEnvironment.setInstallDirectory">ArcGISRuntimeEnvironment.setInstallDirectory</see> is called, if the feature toggle directory has not already been set,
    /// then it is set to the install directory.
    /// 
    /// The feature toggle file is plain text. Each line contains the name of a feature (no spaces) and '=' a boolean value.
    /// For example:
    /// <code>
    /// enable_rendering_engine_mr3d=true
    /// </code>
    /// </remarks>
    /// <returns>
    /// The location of the directory containing the feature toggle file.
    /// </returns>
    /// <since>1.0.0</since>
    static FString GetFeatureToggleDirectory();
    
    /// <summary>
    /// Indicates if a specified feature is enabled in the feature toggle file.
    /// </summary>
    /// <remarks>
    /// If the feature toggle file contains the specified name then toggle value is returned.
    /// Otherwise false is returned where the file or toggle does not exist.
    /// See <see cref="Esri::GameEngine::ArcGISRuntimeEnvironment.setFeatureToggleDirectory">ArcGISRuntimeEnvironment.setFeatureToggleDirectory</see> and <see cref="Esri::GameEngine::ArcGISRuntimeEnvironment.getFeatureToggleDirectory">ArcGISRuntimeEnvironment.getFeatureToggleDirectory</see>.
    /// </remarks>
    /// <param name="featureToggle">The name of the feature in the feature toggle file.</param>
    /// <returns>
    /// The location of the directory containing the feature toggle file.
    /// </returns>
    /// <since>1.0.0</since>
    static bool IsFeatureEnabled(const FString& featureToggle);
    
    /// <summary>
    /// This will override the license watermark text with the beta text info.
    /// </summary>
    /// <remarks>
    /// * 'true' the water mark will always appear even if you set a license
    /// * 'false' (default) the water mark will not appear. The developer license will appear if a license is not set.
    /// </remarks>
    /// <param name="set">Set to true if you wish the beta watermark to appear, false if you wish the license level text to appear.</param>
    /// <since>1.0.0</since>
    static void SetBetaWatermark(bool set);
    
    /// <summary>
    /// Sets the location of the directory containing the feature toggle file and reads the content of the file.
    /// </summary>
    /// <remarks>
    /// Sets the directory containing the feature toggle file 'arcgis_runtime_feature_set.txt'.
    /// If the file exists it will be read into memory. If the file is not formatted an error is returned, for example if a toggle is missing an '='.
    /// The feature toggles are used to enable or disable features that are tested <see cref="Esri::GameEngine::ArcGISRuntimeEnvironment.isFeatureEnabled">ArcGISRuntimeEnvironment.isFeatureEnabled</see>.
    /// 
    /// If the directory or file does not exist, no error is returned and tests for features will return false.
    /// This function should be called once at the start of runtime initialization.
    /// 
    /// Additionally when <see cref="Esri::GameEngine::ArcGISRuntimeEnvironment.setInstallDirectory">ArcGISRuntimeEnvironment.setInstallDirectory</see> is called, if the feature toggle directory has not already been set,
    /// then it is set to the install directory.
    /// 
    /// The feature toggle file is plain text. Each line contains the name of a feature (no spaces) and '=' a boolean value.
    /// For example:
    /// <code>
    /// enable_rendering_engine_mr3d=true
    /// </code>
    /// </remarks>
    /// <param name="featureToggleDirectory">The path to the directory containing the feature toggle file.</param>
    /// <since>1.0.0</since>
    static void SetFeatureToggleDirectory(const FString& featureToggleDirectory);
    
    /// <summary>
    /// Set the location of the root folder for the deployment resources.
    /// </summary>
    /// <remarks>
    /// This is used for the default location to find file resources as follows:
    /// - DirectX shaders default location.
    /// - <i><b>install_path</b></i>/resources/shaders
    /// - military dictionary symbol style default location
    /// - <i><b>install_path</b></i>/resources/symbols/mil2525c
    /// - navigation localized resources
    /// - <i><b>install_path</b></i>/resources/navigation
    /// </remarks>
    /// <param name="installPath">The path to the root folder of the deployment.</param>
    /// <since>1.0.0</since>
    static void SetInstallDirectory(const FString& installPath);
    
    /// <summary>
    /// Set the product name and version.
    /// </summary>
    /// <remarks>
    /// Sets the product information to be used to build the user-agent string.
    /// This should be called before the runtime environment is created. Calling it after may have no effect.
    /// The values are global to the process and defaults to an empty string.
    /// </remarks>
    /// <param name="name"></param>
    /// <param name="version"></param>
    /// <since>1.0.0</since>
    static void SetProductInfo(const FString& name, const FString& version);
    
    /// <summary>
    /// Sets the resources directory for the process.
    /// </summary>
    /// <remarks>
    /// If not set, it will default to "<install_directory>\resources\".
    /// </remarks>
    /// <param name="resourcesPath">Full pathname of the resources directory.</param>
    /// <since>1.0.0</since>
    static void SetResourcesDirectory(const FString& resourcesPath);
    
    /// <summary>
    /// Set the runtime client type and version.
    /// </summary>
    /// <remarks>
    /// This is to support a specific use case. The Unity game engine requires a different thread pool implementation and
    /// this allows to identify the runtime client and instantiate the right thread pool implementation at startup.
    /// This should be called before the runtime environment is created. Calling it after that has no effect.
    /// The values are global to the process and default to <see cref="Esri::Standard::ArcGISRuntimeClient.none">ArcGISRuntimeClient.none</see> and an empty string respectively when not set.
    /// Both values are also used to build the user-agent string.
    /// </remarks>
    /// <param name="runtimeClient"></param>
    /// <param name="version"></param>
    /// <seealso cref="Esri::Standard::ArcGISRuntimeClient">ArcGISRuntimeClient</seealso>
    /// <since>1.0.0</since>
    static void SetRuntimeClient(Standard::ArcGISRuntimeClient runtimeClient, const FString& version);
    
    /// <summary>
    /// Sets the temp directory for the process.
    /// </summary>
    /// <param name="tempPath">Full pathname of the temporary file.</param>
    /// <since>1.0.0</since>
    static void SetTempDirectory(const FString& tempPath);
    #pragma endregion Methods
    
    #pragma region Events
    /// <summary>
    /// Set a global error handler.
    /// </summary>
    /// <remarks>
    /// The global error handler can be overridden by a function error handler. At least one must be set.
    /// A exception will be thrown if which will cause a crash if the error handler has not been
    /// set globally or per function call.
    /// </remarks>
    /// <seealso cref="Esri::Standard::ArcGISErrorHandler">ArcGISErrorHandler</seealso>
    /// <since>1.0.0</since>
    static ArcGISRuntimeEnvironmentErrorEvent GetError();
    static void SetError(ArcGISRuntimeEnvironmentErrorEvent error);
    #pragma endregion Events
};
} // namespace GameEngine
} // namespace Esri