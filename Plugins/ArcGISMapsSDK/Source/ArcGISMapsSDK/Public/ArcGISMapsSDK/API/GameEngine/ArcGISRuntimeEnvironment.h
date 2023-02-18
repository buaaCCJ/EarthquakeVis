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
/// Provides access to and manipulation of environment settings, such as configurations for the operating environment and licenses for deployment.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISRuntimeEnvironment
{
    friend class ArcGISRuntimeEnvironmentInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The default API key to access API key enabled services and resources in ArcGIS Online.
    /// </summary>
    /// <remarks>
    /// An API key is a unique key used to authorize access to specific services and resources in ArcGIS Online.
    /// It is also used to monitor access to those services. An API key is created and managed in the ArcGIS developer
    /// dashboard and is tied to a specific ArcGIS account.
    /// 
    /// In addition to setting an <see cref="Esri::GameEngine::ArcGISRuntimeEnvironment.APIKey">ArcGISRuntimeEnvironment.APIKey</see> at a global level for your application, you
    /// can set it on any class that implements <see cref="">APIKeyResource</see>. This overrides the
    /// <see cref="Esri::GameEngine::ArcGISRuntimeEnvironment.APIKey">ArcGISRuntimeEnvironment.APIKey</see> and enables more granular usage telemetry and management of ArcGIS
    /// location resources used by your app.
    /// 
    /// Classes that expose an API key property by implementing <see cref="">APIKeyResource</see> include:
    /// * <see cref="">Basemap</see>
    /// * <see cref="">ArcGISSceneLayer</see>
    /// * <see cref="">ArcGISTiledLayer</see>
    /// * <see cref="">ArcGISVectorTiledLayer</see>
    /// * <see cref="">ServiceFeatureTable</see>
    /// * <see cref="">ExportVectorTilesTask</see>
    /// * <see cref="">LocatorTask</see>
    /// * <see cref="">GeodatabaseSyncTask</see>
    /// * <see cref="">ClosestFacilityTask</see>
    /// * <see cref="">RouteTask</see>
    /// * <see cref="">ServiceAreaTask</see>
    /// * <see cref="">ExportTileCacheTask</see>
    /// </remarks>
    /// <since>1.0.0</since>
    static FString GetAPIKey();
    static void SetAPIKey(const FString& APIKey);
    #pragma endregion Properties
};
} // namespace GameEngine
} // namespace Esri