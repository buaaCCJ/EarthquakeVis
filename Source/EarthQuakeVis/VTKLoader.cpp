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
	ACrustLoader* CrustLoader = Cast<ACrustLoader>(GetWorld()->SpawnActor(ACrustLoader::StaticClass()));
	TArray<FString> CrustContent;
	FFileHelper::LoadFileToStringArray(CrustContent, *CRUSTFileFolderPath);

	//数据处理
	const float LatStart = -89.5;
	const float LngStart = -179.5;

	//收集点位
	TArray<TArray<FPoint>> EngineDataList;//表明每层的顶点数据
	EngineDataList.SetNum(9);//一共九层
	std::vector < CDT::V2d<double>> LnglatList;//收集各点的经纬度，用于后续三角化

	FVector EngineCoordinates;
	FVector East;
	FVector Up;
	FVector North;
	FVector NewUp;
	//todo  并行化处理
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
			LnglatList.push_back(CDT::V2d<double>::make(CurLng, CurLat));

			FGeographicCoordinates ProjectedCoordinates(CurLng, CurLat, 0);
			GeoReferenceingSystem->GeographicToEngine(ProjectedCoordinates, EngineCoordinates);
			GeoReferenceingSystem->GetENUVectorsAtEngineLocation(EngineCoordinates, East, North, Up);
			auto MapComponent = ArcGisMapActor->GetMapComponent();
			if (MapComponent)
			{
				auto PawnENUToViewENU = MapComponent->GetENUAtLocationToViewENUTransform(EngineCoordinates);
				NewUp = PawnENUToViewENU.GetUnitAxis(EAxis::Z);
			}

			for (int32 idx = 0; idx < Offset.Num(); idx++)
			{
				float ShellThickness = FCString::Atof(*Offset[idx]);
				FVector Temp = NewUp * ShellThickness * 1000 * 100;//引擎单位为cm
				FVector OffsetVec = EngineCoordinates + Temp;
				//another way 
				//	FGeographicCoordinates OffsetCoordinates(CurLng, CurLat, ShellThickness * 1000);
					//GeoReferenceingSystem->GeographicToEngine(OffsetCoordinates, EngineCoordinates);
				EngineDataList[idx].Add({ OffsetVec,Up });
			}
		}
	}

	//三角化
	CDT::Triangulation<double> CDT;
	CDT.insertVertices(LnglatList);
	CDT.eraseSuperTriangle();
	CDT::TriangleVec CurTriangleVec = CDT.triangles;
	for (int32 idx = 0; idx < 9; idx++)
	{
		AVTKProxyActor* Proxy = Cast<AVTKProxyActor>(GetWorld()->SpawnActor(AVTKProxyActor::StaticClass()));
		Proxy->GenerateFromCRUST(EngineDataList[idx], CurTriangleVec);
	}
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
	TArray<AActor*> FoundActors;
	FoundActors.Empty();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGeoReferencingSystem::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
		GeoReferenceingSystem = Cast<AGeoReferencingSystem>(FoundActors[0]);
	FoundActors.Empty();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArcGISMapActor::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0)
		ArcGisMapActor = Cast<AArcGISMapActor>(FoundActors[0]);

	Super::BeginPlay();

}

// Called every frame
void AVTKLoader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

