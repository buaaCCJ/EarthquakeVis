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

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"

#include "ArcGISMapsSDK/Subsystem/IArcGISMapsSDKSubsystemListener.h"

#include "ArcGISCameraComponent.generated.h"

UCLASS(ClassGroup = (ArcGISMapsSDK), meta = (BlueprintSpawnableComponent), Category = "ArcGISMapsSDK|ArcGISCameraComponent")
class ARCGISMAPSSDK_API UArcGISCameraComponent : public UCameraComponent, public IArcGISMapsSDKSubsystemListener
{
	GENERATED_BODY()

public:
	UArcGISCameraComponent();

	// UActorComponent
	void BeginPlay() override;
	void OnRegister() override;
	void OnUnregister() override;
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// IArcGISMapsSDKSubsystemListener
	void OnArcGISMapComponentChanged(UArcGISMapComponent* InMapComponent) override;

	UPROPERTY(EditAnywhere,
			  Category = "ArcGISCameraComponent",
			  meta = (ClampMin = "0.1", ClampMax = "10.0", UIMin = "0.1", UIMax = "10.0", ToolTip = "Adjust this property to modify the quality of the content rendered from the ArcGIS system. A higher number indicates better quality and a higher impact on performance."))
	float QualityScalingFactor = 2.0f;

#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	struct FProperties
	{
		float HorizontalFov = 0;
		int32 ViewportSizeX = 0;
		int32 ViewportSizeY = 0;
		float QualityScalingFactor = 0;
	};

	struct FTransform
	{
		FVector Position;
		FRotator Rotation;
	};

	virtual FProperties CalculateProperties();
	virtual FTransform CalculateTransform();

private:
	UFUNCTION()
	void OnEditorModeChanged();

	UFUNCTION()
	void PushPosition();

	UPROPERTY()
	TObjectPtr<UArcGISMapComponent> MapComponent;

	void PushViewportProperties();

	FProperties Properties;
};
