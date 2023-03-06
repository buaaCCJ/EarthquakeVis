// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "vtkPolyData.h"
#include "Materials/MaterialInterface.h"
#include "VTKProxyActor.generated.h"

class UProceduralMeshComponent;

UCLASS()
class EARTHQUAKEVIS_API AVTKProxyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVTKProxyActor();
	UPROPERTY(VisibleAnywhere)
		USceneComponent* ThisScene;

	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* MeshComp;


	void GenerateFromVTK(UMaterialInterface* Mat, bool bInit, vtkSmartPointer<vtkPolyData> Data);


	void SetColorFrames(const TArray<TArray<FColor>>& Frames) { ColorFrameList = Frames; }
	void StartPlayAnimation();

	void EndPlayAnimation();

	void UpdateAnimation();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<TArray<FVector>> AllVertices;

	TArray<TArray<FColor>> ColorFrameList;
	bool bStartAnim = false;

	float CurrentAnimTime = 0.0;
	int32 CurrentFrameIdx = 0;
};
