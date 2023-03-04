// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VTKLoader.generated.h"

UCLASS()
class EARTHQUAKEVIS_API AVTKLoader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVTKLoader();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString VTKFileFolderPath;

	UFUNCTION(BlueprintCallable)
		void LoadFile();

	UFUNCTION(BlueprintCallable)
		void Play();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
