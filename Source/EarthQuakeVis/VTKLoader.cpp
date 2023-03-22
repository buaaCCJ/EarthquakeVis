// Fill out your copyright notice in the Description page of Project Settings.


#include "VTKLoader.h"
#include "vtkPolyDataReader.h"
#include "vtkNew.h"
#include "vtkDataReader.h"
#include "VTKProxyActor.h"
#include "Runtime/Core/Public/Async/ParallelFor.h"
#include "CRUST/CrustLoader.h"
#include "Kismet/GameplayStatics.h"
#include "include/CDT.h"
#include "include/CDTUtils.h"
#include "CartesianCoordinates.h"
#include "ArcGISMapsSDK/Actors/ArcGISMapActor.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"
#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "include/Triangulation.h"
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
			//插值颜色
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


void AVTKLoader::LoadCRUSTFile()
{
	return;
	ACrustLoader* CrustLoader = Cast<ACrustLoader>(GetWorld()->SpawnActor(ACrustLoader::StaticClass()));
	TArray<FString> CrustContent;
	FFileHelper::LoadFileToStringArray(CrustContent, *CRUSTFileFolderPath);

	//数据处理
	const float LatStart = -89.5;
	const float LngStart = -179.5;


	//收集点位
	TArray<FPoint> Water;

	std::vector < CDT::V2d<double>> Lnglat;

	for (int LatIdx = 0; LatIdx < 180; ++LatIdx)
	{
		for (int LngIdx = 0; LngIdx < 360; ++LngIdx)
		{
			TArray<FString> Offset;
			CrustContent[360 * LatIdx + LngIdx].ParseIntoArray(Offset, TEXT(" "), false);
			for (int32 idx = Offset.Num() - 1; idx >= 0; idx--)
			{
				if (Offset[idx] == "")
					Offset.RemoveAt(idx);
			}

			float CurLat = LatStart + LatIdx;
			float CurLng = LngStart + LngIdx;

			FGeographicCoordinates ProjectedCoordinates(CurLng, CurLat, 0);
			Lnglat.push_back(CDT::V2d<double>::make(CurLng, CurLat));
			FVector EngineCoordinates;
			GeoReferenceingSystem->GeographicToEngine(ProjectedCoordinates, EngineCoordinates);
			FVector East;
			FVector Up;
			FVector North;
			GeoReferenceingSystem->GetENUVectorsAtGeographicLocation(ProjectedCoordinates, East, North, Up);
			float WaterThickness = FCString::Atof(*Offset[1]);

			FVector OffsetVec = EngineCoordinates + Up * WaterThickness;

			Water.Add({ OffsetVec,Up });
		}
	}

	CDT::Triangulation<double> cdt;
	cdt.insertVertices(Lnglat);
	cdt.eraseSuperTriangle();
	CDT::TriangleVec CurTriangleVec = cdt.triangles;

	AVTKProxyActor* Proxy = Cast<AVTKProxyActor>(GetWorld()->SpawnActor(AVTKProxyActor::StaticClass()));
	Proxy->GenerateFromCRUST(Water, CurTriangleVec);
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
	TArray<AActor*> FoundActors;
	FoundActors.Empty();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGeoReferencingSystem::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
		GeoReferenceingSystem = Cast<AGeoReferencingSystem>(FoundActors[0]);
}

// Called every frame
void AVTKLoader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

