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

#include "CoreMinimal.h"
#include "Math/TransformNonVectorized.h"

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMap.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMapType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/ArcGISView.h"
#include "ArcGISMapsSDK/Components/BaseMapTypes.h"
#include "ArcGISMapsSDK/Memory/IArcGISMemorySystemHandler.h"
#include "ArcGISMapsSDK/Security/ArcGISAuthenticationConfigurationInstanceData.h"
#include "ArcGISMapsSDK/Utils/ArcGISExtentInstanceData.h"
#include "ArcGISMapsSDK/Utils/ArcGISLayerInstanceData.h"
#include "ArcGISMapsSDK/Utils/AuthGuid.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"
#include "ArcGISMapsSDK/Utils/Unreal/RaycastHelpers.h"
#include "ArcGISMapsSDK/Utils/ArcGISViewportProperties.h"

#include "ArcGISMapComponentInterface.generated.h"

UINTERFACE(Blueprintable)
class ARCGISMAPSSDK_API UArcGISMapComponentInterface : public UInterface
{
	GENERATED_BODY()
};

class ARCGISMAPSSDK_API IArcGISMapComponentInterface
{
	GENERATED_BODY()

public:
	// API Key Interface
	virtual FString GetAPIKey() const = 0;
	virtual void SetAPIKey(const FString& InAPIKey) = 0;

	// Mesh Collider Interface
	virtual bool GetAreMeshCollidersEnabled() const = 0;
	virtual void SetAreMeshCollidersEnabled(bool bInAreMeshCollidersEnabled) = 0;

	// Authentication Configuration Interface
	virtual const TArray<FArcGISAuthenticationConfigurationInstanceData>& GetAuthenticationConfigurations() const = 0;
	virtual void SetAuthenticationConfigurations(TArray<FArcGISAuthenticationConfigurationInstanceData> InAuthenticationConfigurations) = 0;

	// Basemap Interface
	virtual FAuthGuid GetBasemapAuthID() const = 0;
	virtual void SetBasemapAuthID(FAuthGuid InBasemapAuthID) = 0;

	virtual const FString& GetBasemapSource() const = 0;
	virtual void SetBasemapSource(const FString& InBasemapSource) = 0;

	virtual void SetBasemapSourceAndType(const FString& InBasemapSource, EBaseMapTypes InBasemapType) = 0;

	virtual EBaseMapTypes GetBasemapType() const = 0;
	virtual void SetBasemapType(EBaseMapTypes InBasemapType) = 0;

	// Elevation Interface
	virtual bool GetIsElevationEnabled() const = 0;
	virtual void SetIsElevationEnabled(bool bInIsElevationEnabled) = 0;

	virtual FString GetElevationSource() const = 0;
	virtual void SetElevationSource(const FString& InElevationSource) = 0;

	virtual FString GetCustomElevationSource() const = 0;
	virtual void SetCustomElevationSource(const FString& InCustomElevationSource) = 0;

	virtual FAuthGuid GetElevationAuthID() const = 0;
	virtual void SetElevationAuthID(FAuthGuid InElevationAuthID) = 0;

	// Extent Interface
	virtual const FArcGISExtentInstanceData& GetExtent() const = 0;
	virtual void SetExtent(const FArcGISExtentInstanceData& InExtent) = 0;

	virtual bool GetIsEditorModeEnabled() const = 0;
	virtual void SetIsEditorModeEnabled(bool bInIsEditorModeEnabled) = 0;

	virtual bool GetIsExtentEnabled() const = 0;
	virtual void SetIsExtentEnabled(bool bInIsExtentEnabled) = 0;

	virtual bool GetIsOriginAtPlanetCenter() const = 0;
	virtual void SetIsOriginAtPlanetCenter(bool bInIsOriginAtPlanetCenter) = 0;

	// Layers Interface
	virtual const TArray<FArcGISLayerInstanceData>& GetLayers() const = 0;
	virtual void SetLayers(TArray<FArcGISLayerInstanceData> InLayers) = 0;

	virtual void UpdateLayerGuid(FArcGISLayerInstanceData* InUpdatedLayer) = 0;

	// Map Interface
	virtual UArcGISMap* GetMap() = 0;
	virtual void SetMap(UArcGISMap* InMap) = 0;

	virtual TEnumAsByte<EArcGISMapType::Type> GetMapType() const = 0;
	virtual void SetMapType(TEnumAsByte<EArcGISMapType::Type> InMapType) = 0;

	// Geographic Interface
	virtual UArcGISPoint* GetOriginPosition() const = 0;
	virtual void SetOriginPosition(UArcGISPoint* InOriginPosition) = 0;

	virtual bool GetShouldUpdateGeoReferencingSystem() const = 0;
	virtual void SetShouldUpdateGeoReferencingSystem(bool bInShouldUpdateGeoReferencingSystem) = 0;

	virtual FArcGISViewportProperties GetViewportProperties() const = 0;
	virtual void SetViewportProperties(FArcGISViewportProperties InViewportProperties) = 0;

	virtual UArcGISView* GetView() = 0;

	virtual FGeoPosition EngineToGeographic(const FVector& InEngineCoordinates) = 0;
	virtual FVector GeographicToEngine(const FGeoPosition& InGeographicCoordinates) = 0;

	virtual FVector FromEnginePosition(const FVector& InEnginePosition) const = 0;
	virtual FVector ToEnginePosition(const FVector& InWorldPosition) const = 0;

	virtual FTransform GetENUAtLocationToViewENUTransform(const FVector& InEngineCoordinates) = 0;
	virtual FTransform GetENUToWorldTransformAtOrigin() const = 0;

	// Zoom Interface
	virtual bool ZoomToExtent(AActor* InActor, UArcGISExtent* InExtent) = 0;

	virtual UE::Tasks::TTask<bool> ZoomToLayerAsync(AActor* InActor, UArcGISLayer* InLayer) = 0;

	virtual bool ZoomToLayer(AActor* InActor, FArcGISLayerInstanceData Layer) = 0;

	virtual FArcGISRaycastHit GetArcGISRaycastHit(FHitResult InRaycastHit) = 0;

	// Memory Interface
	virtual IArcGISMemorySystemHandler* GetMemorySystemHandler() = 0;
	virtual void SetMemorySystemHandler(IArcGISMemorySystemHandler* InMemorySystemHandler) = 0;

	virtual bool HasSpatialReference() = 0;

	virtual bool ShouldEditorComponentBeUpdated() const = 0;

	virtual bool MarkPackageDirty() const = 0;
};
