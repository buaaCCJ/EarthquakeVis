// Fill out your copyright notice in the Description page of Project Settings.


#include "VTKProxyActor.h"
#include "ProceduralMeshComponent.h"
#include "vtkContourTriangulator.h"
#include "Kismet/GameplayStatics.h"
#include "ArcGISMapsSDK/Actors/ArcGISMapActor.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"
#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "CartesianCoordinates.h"
#include "include/CDTUtils.h"

// Sets default values
AVTKProxyActor::AVTKProxyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = MeshComp;
	// New in UE 4.17, multi-threaded PhysX cooking.
	MeshComp->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AVTKProxyActor::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArcGISMapActor::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0)
		ArcGisMapActor = Cast<AArcGISMapActor>(FoundActors[0]);

	FoundActors.Empty();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGeoReferencingSystem::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
		GeoReferenceingSystem = Cast<AGeoReferencingSystem>(FoundActors[0]);
}

// Called every frame
void AVTKProxyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bStartAnim)
	{
		UpdateAnimation();
		CurrentAnimTime += DeltaTime;
		CurrentFrameIdx++;

	}

}
void AVTKProxyActor::GenerateFromVTK(UMaterialInterface* Mat, bool bInit, vtkSmartPointer<vtkPolyData> PolyData)
{
	if (bInit)
	{
		AllVertices.Empty();

	}
	MeshComp->SetMaterial(0, Mat);

	TArray<FLinearColor> VerticeColors;

	double x[3];
	TArray<FVector> Vertices;
	TArray<FVector> Normals;
	for (vtkIdType i = 0; i < PolyData->GetNumberOfPoints(); i++) {
		PolyData->GetPoint(i, x);
		FVector Vertex(FVector(x[0], x[1], x[2]));
		{
			FGeographicCoordinates ProjectedCoordinates(x[0], x[1], x[2]);
			FVector EngineCoordinates;
			GeoReferenceingSystem->GeographicToEngine(ProjectedCoordinates, EngineCoordinates);
			FVector East;
			FVector Up;
			FVector North;
			GeoReferenceingSystem->GetENUVectorsAtEngineLocation(EngineCoordinates, East, North, Up);

			Vertex = EngineCoordinates;

			Normals.Add(Up);
		}
		Vertices.Add(Vertex);
		if (bInit)
			VerticeColors.Add(FLinearColor(255, 255, 255, 255));
	}
	AllVertices.Emplace(Vertices);
	if (!bInit)return;
	vtkSmartPointer<vtkCellArray> CellArray = vtkSmartPointer<vtkCellArray>::New();

	// get polygon data and store into array
	CellArray = PolyData->GetPolys();

	// stores the data for triangles
	TArray<int32> Triangles;


	vtkSmartPointer<vtkIdList> p = vtkSmartPointer<vtkIdList>::New();
	int h;

	for (int i = 0; i < PolyData->GetNumberOfPolys(); i++) {
		// GetNextCell returns 0 if end of cells, 1 otherwise
		h = CellArray->GetNextCell(p);
		if (h == 0) {
			break;
		}

		int32 NumOfIds = p->GetNumberOfIds();
		// if the number of vertices in p is 3
		if (NumOfIds == 3) {
			Triangles.Add(p->GetId(0));
			Triangles.Add(p->GetId(1));
			Triangles.Add(p->GetId(2));
		}
	}
	FBox Bounds(Vertices);

	MeshComp->CreateMeshSection_LinearColor(0, Vertices, Triangles,
		Normals, TArray<FVector2D>(), VerticeColors, TArray<FProcMeshTangent>(), false);

	// Enable collision data
	//MeshComp->ContainsPhysicsTriMeshData(true);
}

void AVTKProxyActor::GenerateFromCRUST(const TArray<FPoint>& Points, const CDT::TriangleVec& TriangleList)
{
	TArray<FVector> Vertices;
	TArray<FVector> Normals;
	TArray<int32> Triangles;
	TArray<FLinearColor> VerticeColors;

	for (auto& Point : Points)
	{
		Vertices.Emplace(Point.Position);
		Normals.Emplace(Point.Normal);
	}
	for (auto& Tri : TriangleList)
	{
		Triangles.Add(Tri.vertices[0]);
		Triangles.Add(Tri.vertices[1]);
		Triangles.Add(Tri.vertices[2]);
	}
	MeshComp->CreateMeshSection_LinearColor(0, Vertices, Triangles,
		TArray<FVector>(), TArray<FVector2D>(), VerticeColors, TArray<FProcMeshTangent>(), false);
}

void AVTKProxyActor::StartPlayAnimation()
{
	bStartAnim = true;
	CurrentAnimTime = 0.0;
	CurrentFrameIdx = 0;
}

void AVTKProxyActor::EndPlayAnimation()
{
	bStartAnim = false;
}

void AVTKProxyActor::SetArcgisVis(bool bShow)
{
	/*if (!ArcGisMapActor)return;
	TArray<UActorComponent*> MeshComponents = ArcGisMapActor->K2_GetComponentsByClass(UArcGISMeshComponent::StaticClass());
	for (auto MeshComponent : MeshComponents)
	{
		Cast<UArcGISMeshComponent>(MeshComponent)->SetVisibility(bShow);
	}*/
}

void AVTKProxyActor::UpdateAnimation()
{
	CurrentFrameIdx = CurrentFrameIdx % ColorFrameList.Num();
	TArray<FVector2D> EmptyArray;
	TArray<FColor> EmptyColorArray;

	MeshComp->UpdateMeshSection(0, AllVertices[0], TArray<FVector>(), TArray<FVector2D>(), EmptyArray, EmptyArray, EmptyArray, ColorFrameList[CurrentFrameIdx], TArray<FProcMeshTangent>());
}

