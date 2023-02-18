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
#include "Tasks/Task.h"

#include "ArcGISMapsSDK/Components/ArcGISActorComponent.h"
#include "ArcGISMapsSDK/Components/ArcGISMapComponentInterface.h"
#include "ArcGISMapsSDK/Memory/IArcGISMemorySystem.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoRotation.h"

#include "ArcGISMapComponent.generated.h"

UCLASS(Within = ArcGISMapActor,
	   ClassGroup = (ArcGISMapsSDK),
	   Category = "ArcGISMapsSDK|ArcGISMapComponent",
	   hidecategories = (Activation, AssetUserData, Collision, Cooking, LOD, Object, Physics, Rendering, SceneComponent, Tags))
class ARCGISMAPSSDK_API UArcGISMapComponent : public UArcGISActorComponent, public IArcGISMapComponentInterface, public IArcGISMemorySystem
{
	GENERATED_BODY()

	DECLARE_MULTICAST_DELEGATE(FAuthenticationChangedDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEditorModeChangedDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMapTypeChangedDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMeshCollidersEnabledChangedDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOriginPositionChangedDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpatialReferenceChangedDelegate);

public:
	// IArcGISMapComponentInterface
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	FString GetAPIKey() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetAPIKey(const FString& InAPIKey) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	bool GetAreMeshCollidersEnabled() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetAreMeshCollidersEnabled(bool bInAreMeshCollidersEnabled) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	const TArray<FArcGISAuthenticationConfigurationInstanceData>& GetAuthenticationConfigurations() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetAuthenticationConfigurations(TArray<FArcGISAuthenticationConfigurationInstanceData> InAuthenticationConfigurations) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Basemap")
	FAuthGuid GetBasemapAuthID() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Basemap")
	void SetBasemapAuthID(FAuthGuid bInBasemapAuthID) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Basemap")
	const FString& GetBasemapSource() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Basemap")
	void SetBasemapSource(const FString& BasemapSource) override;

	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent|Basemap")
	void SetBasemapSourceAndType(const FString& InBasemapSource, EBaseMapTypes InBasemapType) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Basemap")
	EBaseMapTypes GetBasemapType() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Basemap")
	void SetBasemapType(EBaseMapTypes InBasemapType) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Elevation")
	bool GetIsElevationEnabled() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Elevation")
	void SetIsElevationEnabled(bool bInIsElevationEnabled) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Elevation")
	FString GetElevationSource() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Elevation")
	void SetElevationSource(const FString& InElevationSource) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Elevation")
	FAuthGuid GetElevationAuthID() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent|Elevation")
	void SetElevationAuthID(FAuthGuid InElevationAuthID) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	const FArcGISExtentInstanceData& GetExtent() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetExtent(const FArcGISExtentInstanceData& InExtent) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	bool GetIsEditorModeEnabled() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetIsEditorModeEnabled(bool bInIsEditorModeEnabled) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	bool GetIsExtentEnabled() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetIsExtentEnabled(bool bInIsExtentEnabled) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	bool GetIsOriginAtPlanetCenter() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetIsOriginAtPlanetCenter(bool bInIsOriginAtPlanetCenter) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	const TArray<FArcGISLayerInstanceData>& GetLayers() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetLayers(TArray<FArcGISLayerInstanceData> InLayers) override;

	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"), Category = "ArcGISMapsSDK|ArcGISMapComponent")
	static UArcGISMapComponent* GetMapComponent(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	UArcGISMap* GetMap() override;
	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetMap(UArcGISMap* InMap) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	TEnumAsByte<EArcGISMapType::Type> GetMapType() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetMapType(TEnumAsByte<EArcGISMapType::Type> InMapType) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	UArcGISPoint* GetOriginPosition() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetOriginPosition(UArcGISPoint* InOriginPosition) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	bool GetShouldUpdateGeoReferencingSystem() const override;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetShouldUpdateGeoReferencingSystem(bool bInShouldUpdateGeoReferencingSystem) override;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	FArcGISViewportProperties GetViewportProperties() const override;
	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetViewportProperties(FArcGISViewportProperties InViewportProperties) override;

	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	UArcGISView* GetView() override;

	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|Transformations")
	FGeoPosition EngineToGeographic(const FVector& InEngineCoordinates) override;
	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|Transformations")
	FVector GeographicToEngine(const FGeoPosition& InGeographicCoordinates) override;

	UFUNCTION(BlueprintPure, Category = "ArcGISMapsSDK|Transformations")
	FVector FromEnginePosition(const FVector& InEnginePosition) const override;
	UFUNCTION(BlueprintPure, Category = "ArcGISMapsSDK|Transformations")
	FVector ToEnginePosition(const FVector& InWorldPosition) const override;

	// Returns a transform that allows to go from the ENU space (in UE axes) based at the provided
	// location to the ENU space based at the Origin Location (in UE axes)
	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ENU Transforms")
	FTransform GetENUAtLocationToViewENUTransform(const FVector& EngineCoordinates) override;

	// Returns a transform that allows to go from the ENU frame (also in UE axes) based at the Origin to the World frame (in UE axes)
	// The Origin is the position set in the ArcGISMapComponent at editor-time that doesn't change at run-time
	FTransform GetENUToWorldTransformAtOrigin() const override;

	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	bool ZoomToExtent(AActor* InActor, UArcGISExtent* InExtent) override;

	UE::Tasks::TTask<bool> ZoomToLayerAsync(AActor* InActor, UArcGISLayer* InLayer) override;

	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	bool ZoomToLayer(AActor* InActor, FArcGISLayerInstanceData InLayer) override;

	FAuthenticationChangedDelegate OnAuthenticationChanged;

	FEditorModeChangedDelegate OnEditorModeChanged;

	UPROPERTY(BlueprintAssignable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	FMapTypeChangedDelegate OnMapTypeChanged;

	FMeshCollidersEnabledChangedDelegate OnMeshCollidersEnabledChanged;

	FOriginPositionChangedDelegate OnOriginPositionChanged;

	UPROPERTY(BlueprintAssignable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	FSpatialReferenceChangedDelegate OnSpatialReferenceChanged;

	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	FArcGISRaycastHit GetArcGISRaycastHit(FHitResult InRaycastHit) override;

	IArcGISMemorySystemHandler* GetMemorySystemHandler() override;
	void SetMemorySystemHandler(IArcGISMemorySystemHandler* InMemorySystemHandler) override;

	UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	bool HasSpatialReference() override;

	bool ShouldEditorComponentBeUpdated() const override;

	// UObject
	void BeginDestroy() override;
#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	void Serialize(FArchive& Ar) override;

	// UActorComponent
	void OnComponentCreated() override;
	void OnRegister() override;

	// IArcGISMapsSDKSubsystemListener
	void OnGeoReferencingSystemChanged(AGeoReferencingSystem* InGeoReferencingSystem) override;

	//	IArcGISMemorySystem
	virtual void NotifyLowMemoryWarning() override;
	virtual void SetMemoryQuotas(FArcGISMemoryQuotas InMemoryQuotas) override;

	// IArcGISMapComponentInterface
	void UpdateLayerGuid(FArcGISLayerInstanceData* InUpdatedLayer) override;
	bool MarkPackageDirty() const override;

protected:
	friend class UArcGISLocationComponent;
	friend class UArcGISMapCreatorBasemapTool;
	friend class UArcGISMapCreatorBasemapToolBuilder;
	friend class UArcGISMapCreatorElevationTool;
	friend class UArcGISMapCreatorElevationToolBuilder;
	friend class FArcGISMapCreatorLayerCustomization;

	FString GetCustomElevationSource() const override;
	void SetCustomElevationSource(const FString& InCustomElevationSource) override;

	// This member is used to store a custom value in the case where the default one is active
	// but we still want to be able to persist this in the modes panel
	UPROPERTY()
	FString CustomElevationSource;

	bool GetEngineTransform(FGeoPosition InPosition, FGeoRotation InRotation, FTransform& OutTransform);

	bool ZoomToExtent(UArcGISExtent* InExtent, FTransform& OutTransform);
	bool ZoomToLayer(FArcGISLayerInstanceData InLayer, FTransform& OutTransform);
	UE::Tasks::TTask<bool> ZoomToLayerAsync(UArcGISLayer* InLayer, FTransform& OutTransform);

private:
	friend class FArcGISMapCreatorLayerToolDetails;
	friend class SArcGISMapCreatorBasemapWidget;
	friend class UArcGISMapCreatorLayerTool;
	friend class UArcGISMapCreatorLayerToolBuilder;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetAreMeshCollidersEnabled,
			  BlueprintSetter = SetAreMeshCollidersEnabled,
			  Category = "ArcGISMapComponent|Settings",
			  meta = (DisplayName = "Enable Mesh Colliders"))
	bool bAreMeshCollidersEnabled = false;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetIsEditorModeEnabled,
			  BlueprintSetter = SetIsEditorModeEnabled,
			  Category = "ArcGISMapComponent|Settings",
			  meta = (DisplayName = "Enable Editor Mode"))
	bool bIsEditorModeEnabled = true;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetIsOriginAtPlanetCenter,
			  BlueprintSetter = SetIsOriginAtPlanetCenter,
			  Category = "ArcGISMapComponent",
			  meta = (DisplayName = "Origin At Planet Center", EditConditionHides, EditCondition = "MapType==EArcGISMapType::Global"))
	bool bIsOriginAtPlanetCenter = false;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetShouldUpdateGeoReferencingSystem,
			  BlueprintSetter = SetShouldUpdateGeoReferencingSystem,
			  Category = "ArcGISMapComponent",
			  meta = (EditConditionHides, EditCondition = "GeoReferencingSystem!=nullptr"))
	bool bUpdateGeoReferencingSystem = false;

	UPROPERTY()
	AGeoReferencingSystem* GeoReferencingSystem;

	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	FGeoPosition GetOriginPosition_Internal() const;
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "ArcGISMapsSDK|ArcGISMapComponent")
	void SetOriginPosition_Internal(const FGeoPosition& InPosition);

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetOriginPosition_Internal,
			  BlueprintSetter = SetOriginPosition_Internal,
			  Category = "ArcGISMapComponent",
			  meta = (EditConditionHides, EditCondition = "bIsOriginAtPlanetCenter==false||MapType==EArcGISMapType::Local"))
	FGeoPosition OriginPosition;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetMapType, BlueprintSetter = SetMapType, Category = "ArcGISMapComponent")
	TEnumAsByte<EArcGISMapType::Type> MapType;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetBasemapSource, BlueprintSetter = SetBasemapSource, Category = "ArcGISMapComponent|Basemap")
	FString Basemap;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetBasemapType, BlueprintSetter = SetBasemapType, Category = "ArcGISMapComponent|Basemap")
	EBaseMapTypes BasemapType;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetBasemapAuthID,
			  BlueprintSetter = SetBasemapAuthID,
			  Category = "ArcGISMapComponent|Basemap",
			  meta = (DisplayName = "Authentication", BasemapAuth = true))
	FAuthGuid BasemapAuthConfigID;

	UPROPERTY()
	bool EnableElevation_DEPRECATED = true;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetIsElevationEnabled,
			  BlueprintSetter = SetIsElevationEnabled,
			  Category = "ArcGISMapComponent|Elevation")
	bool bIsElevationEnabled = true;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetElevationSource,
			  BlueprintSetter = SetElevationSource,
			  Category = "ArcGISMapComponent|Elevation",
			  meta = (EditConditionHides, EditCondition = "bIsElevationEnabled==true"))
	FString ElevationSource;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetElevationAuthID,
			  BlueprintSetter = SetElevationAuthID,
			  Category = "ArcGISMapComponent|Elevation",
			  meta = (DisplayName = "Authentication", ElevationAuth = true))
	FAuthGuid ElevationAuthConfigID;

	UPROPERTY()
	bool EnableExtent_DEPRECATED = false;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetIsExtentEnabled,
			  BlueprintSetter = SetIsExtentEnabled,
			  Category = "ArcGISMapComponent",
			  meta = (EditConditionHides, EditCondition = "MapType==EArcGISMapType::Local"))
	bool bIsExtentEnabled = false;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetExtent,
			  BlueprintSetter = SetExtent,
			  Category = "ArcGISMapComponent",
			  meta = (EditConditionHides, EditCondition = "bIsExtentEnabled==true&&MapType==EArcGISMapType::Local"))
	FArcGISExtentInstanceData Extent;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetLayers, BlueprintSetter = SetLayers, Category = "ArcGISMapComponent")
	TArray<FArcGISLayerInstanceData> Layers;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetAPIKey,
			  BlueprintSetter = SetAPIKey,
			  Category = "ArcGISMapComponent|Authentication",
			  meta = (DisplayName = "API Key"))
	FString APIKey;

	UPROPERTY(EditAnywhere,
			  BlueprintGetter = GetAuthenticationConfigurations,
			  BlueprintSetter = SetAuthenticationConfigurations,
			  Category = "ArcGISMapComponent|Authentication")
	TArray<FArcGISAuthenticationConfigurationInstanceData> AuthenticationConfigurations;

	TArray<FArcGISLayerInstanceData> LastLayers;
	TStrongObjectPtr<UArcGISMap> Map;
	IArcGISMemorySystemHandler* MemorySystemHandler{nullptr};
	TStrongObjectPtr<UArcGISView> View;

	// Transforms a point from the ENU frame to the World frame
	FMatrix44d ENUFrameToWorldFrame;
	// Transforms a point from the World frame to the ENU frame
	FMatrix44d WorldFrameToENUFrame;
	// Transforms a point from meters to centimeters and applies an axis conversion to UE's axis convention
	FMatrix44d ToUnrealCoordSystem;
	// Transforms a point from centimeters to meters and applies an axis conversion from UE's axis convention
	FMatrix44d FromUnrealCoordSystem;

	// Used by terrain occlusion
	FArcGISViewportProperties CurrentViewportProperties;

	void ApplyAPIKeyUpdate();
	void ApplyBasemapUpdate();
	void ApplyEditorModeUpdate();
	void ApplyElevationUpdate();
	void ApplyExtentUpdate();
	void ApplyMapTypeUpdate();
	void DestroyView();
	FString GetEffectiveAPIKey();
	void Initialize();
	void InitializeMap();
	void InitializeMemorySystem();
	bool InsertAuthenticationConfig(const FGuid& InAuthConfigId, const FString& InSource);
	void InvalidateLayers();
	void PullFromGeoReferencingSystem();
	void PushToGeoReferencingSystem();
	void ResetMap();
	void SetMapToView();
	void UpdateAuthenticationConfigurations();
	void UpdateENUToWorldTransform();
	void UpdateLayers();
};
