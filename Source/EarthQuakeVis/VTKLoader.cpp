// Fill out your copyright notice in the Description page of Project Settings.


#include "VTKLoader.h"
#include "vtkPolyDataReader.h"
#include "vtkNew.h"
#include "vtkDataReader.h"
#include "VTKProxyActor.h"


// Sets default values
AVTKLoader::AVTKLoader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AVTKLoader::LoadFile()
{
	TArray<FString> FileList;

	IFileManager::Get().FindFilesRecursive(FileList, *VTKFileFolderPath, TEXT("*.vtk"), true, false);
	for (auto& File : FileList)
	{
		vtkNew<vtkPolyDataReader> VTKReader;
		VTKReader->SetFileName(TCHAR_TO_ANSI(*File));
		VTKReader->Update();
		AVTKProxyActor* Proxy = Cast<AVTKProxyActor>(GetWorld()->SpawnActor(AVTKProxyActor::StaticClass()));

		if (!Proxy)check(false);
		auto Data = VTKReader->GetOutput();
		Proxy->GenerateFromVTK(Data);
		break;
	}
}

void AVTKLoader::Play()
{

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

