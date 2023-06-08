// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "vtkPolyData.h"
#include "Materials/MaterialInterface.h"
#include "include/CDTUtils.h"
#include "VTKProxyActor.generated.h"

class UProceduralMeshComponent;
class AArcGISMapActor;
class AGeoReferencingSystem;
struct FPoint
{
	FVector Position;
	FVector Normal;
};
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

	void GenerateFromCRUST(const TArray<FPoint>& Points, const CDT::TriangleVec& TriangleList);

	void SetColorFrames(int32 _NumFrameToPlayAnim, const TArray<TArray<FColor>>& Frames) { NumFrameToPlayAnim = _NumFrameToPlayAnim, ColorFrameList = Frames; }
	void StartPlayAnimation();

	void EndPlayAnimation();

	void SetArcgisVis(bool bShow);

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

	AArcGISMapActor* ArcGisMapActor = nullptr;
	AGeoReferencingSystem* GeoReferenceingSystem = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 NumFrameToPlayAnim = 1;

};
