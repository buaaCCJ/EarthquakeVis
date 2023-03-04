// Fill out your copyright notice in the Description page of Project Settings.


#include "VTKProxyActor.h"
#include "ProceduralMeshComponent.h"
#include "vtkContourTriangulator.h"

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
	
}

// Called every frame
void AVTKProxyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AVTKProxyActor::GenerateFromVTK(vtkSmartPointer<vtkPolyData> PolyData)
{
	// optional code ~ have to include Engine.h
	// output number of points
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green,
		TEXT("Number of Points: ") + FString::SanitizeFloat(PolyData->GetNumberOfPoints()));

	// optional code 
	// opens the message log for ouput
	auto MessageLog = FMessageLog("Points");
	MessageLog.Open(EMessageSeverity::Info, true);

	TArray<FLinearColor> VerticeColors;

	// optional - output all points to message log
		// store all the points into a vvector containing all the vertices
	double x[3];
	TArray<FVector> Vertices;
	for (vtkIdType i = 0; i < PolyData->GetNumberOfPoints(); i++) {
		// get point from poly data and store in vertice
		PolyData->GetPoint(i, x);
		Vertices.Add(FVector(x[0], x[1], x[2]));

		VerticeColors.Add(FLinearColor(255, 255, 255, 255));

		// optional - output point to message log
		//MessageLog.Message(EMessageSeverity::Info,
		//	FText::FromString(FString::Printf(TEXT("Point %d: (%f, %f, %f)"), i, x[0], x[1], x[2])));
	}

	// create a cell array data to get all the polygons from the polygon data
	vtkSmartPointer<vtkCellArray> CellArray = vtkSmartPointer<vtkCellArray>::New();

	// get polygon data and store into array
	CellArray = PolyData->GetPolys();

	// optional - output number of triangles
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue,
		TEXT("Number of Vertices: ") + FString::SanitizeFloat(CellArray->GetSize()));

	// stores the data for triangles
	TArray<int32> Triangles;

	// create a list that stores the points, in order, for each triangle
		// get each vertice and add it into a triangles vector in order
	vtkSmartPointer<vtkIdList> p =vtkSmartPointer<vtkIdList>::New();

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
	// draws the vertices and triangles in Unreal
	// most of the fields are unused for the purpose of this project, so just create empty arrays
	MeshComp->CreateMeshSection_LinearColor(0, Vertices, Triangles,
		TArray<FVector>(), TArray<FVector2D>(), VerticeColors, TArray<FProcMeshTangent>(), true);

	// Enable collision data
	MeshComp->ContainsPhysicsTriMeshData(true);
}

