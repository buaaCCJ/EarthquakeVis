// Fill out your copyright notice in the Description page of Project Settings.


#include "VTKLoader.h"
#include "vtkPolyDataReader.h"
#include "vtkNew.h"
#include "vtkDataReader.h"
#include "VTKProxyActor.h"
#include "Runtime/Core/Public/Async/ParallelFor.h"

// Sets default values
AVTKLoader::AVTKLoader()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AVTKLoader::LoadFile(int32 Num)
{
	for (auto ProxyActor : ProxyActors)
	{
		if (ProxyActor)
			ProxyActor->K2_DestroyActor();
	}
	ProxyActors.Empty();

	TArray<FString> FileList;

	IFileManager::Get().FindFilesRecursive(FileList, *VTKFileFolderPath, TEXT("*.vtk"), true, false);
	if (FileList.Num() > 0)
	{
		AVTKProxyActor* Proxy = Cast<AVTKProxyActor>(GetWorld()->SpawnActor(AVTKProxyActor::StaticClass()));
		ProxyActors.Emplace(Proxy);
		vtkNew<vtkPolyDataReader> VTKReader;

		VTKReader->SetFileName(TCHAR_TO_ANSI(*FileList[0]));
		VTKReader->Update();

		if (!Proxy)check(false);
		auto Data = VTKReader->GetOutput();
		Proxy->GenerateFromVTK(VTKMaterial, true, Data);
	}
	FileList.Empty();
	IFileManager::Get().FindFilesRecursive(FileList, *VTKFileFolderPath, TEXT("*.txt"), true, false);

	FVector4 White(255, 255, 255, 255);
	FVector4 Red(255, 0, 0, 255);
	FVector4 Blue(0, 0, 255, 255);

	TArray<TArray<FColor>> ColorFrameList;
	for (int32 idx = 0; idx < FileList.Num(); ++idx)
	{
		{
			//²åÖµÑÕÉ«
			TArray<FString> Displacement;
			FFileHelper::LoadFileToStringArray(Displacement, *FileList[idx]);

			TArray<FColor> Result;
			Result.SetNum(Displacement.Num() - 1);
			ParallelFor(Displacement.Num() - 1, [&](int32 Idx) {
				//for (int32 Idx = 0; Idx < Displacement.Num(); ++Idx){
				float Value = FCString::Atof(*Displacement[Idx]);

				FVector4 TempColor;
				float Factor = (Value - 127.5) / 127.5;
				if (Factor > 0)
					TempColor = White * (1 - Factor) + Red * Factor;
				else
					TempColor = White * (1 + Factor) + Blue * Factor;

				Result[Idx] = FColor(TempColor.X, TempColor.Y, TempColor.Z, TempColor.W);
				}
			);
			ColorFrameList.Add(Result);
		}
	}

	if (ProxyActors.Num() > 0)
		ProxyActors[0]->SetColorFrames(ColorFrameList);
}

void AVTKLoader::Play()
{
	if (ProxyActors.Num() > 0)
		ProxyActors[0]->StartPlayAnimation();
}

void AVTKLoader::Stop()
{
	if (ProxyActors.Num() > 0)
		ProxyActors[0]->EndPlayAnimation();
}

void AVTKLoader::SetArcgisVis(bool bShow)
{
	if (ProxyActors.Num() > 0)
		ProxyActors[0]->EndPlayAnimation();
}

// Called when the game starts or when spawned
void AVTKLoader::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AVTKLoader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

