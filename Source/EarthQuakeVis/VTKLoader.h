// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VTKProxyActor.h"
#include "Materials/MaterialInterface.h"
#include "VTKLoader.generated.h"

class AGeoReferencingSystem;
class AArcGISMapActor;

UCLASS()
class EARTHQUAKEVIS_API AVTKLoader : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVTKLoader();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString VTKFileFolderPath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CRUSTFileFolderPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AVTKProxyActor*> ProxyActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInterface* VTKMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 NumFrameToPlayAnim = 1;

	UFUNCTION(BlueprintCallable)
		void LoadFile(int32 Num);

	UFUNCTION(BlueprintCallable)
		void LoadCRUSTFile();

	UFUNCTION(BlueprintCallable)
		void Play();

	UFUNCTION(BlueprintCallable)
		void Stop();

	UFUNCTION(BlueprintCallable)
		void SetArcgisVis(bool bShow);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AGeoReferencingSystem* GeoReferenceingSystem = nullptr;
	AArcGISMapActor* ArcGisMapActor = nullptr;
};
