// COPYRIGHT 1995-2021 ESRI
// TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
// Unpublished material - all rights reserved under the
// Copyright Laws of the United States and applicable international
// laws, treaties, and conventions.
//
// For additional information, contact:
// Attn: Contracts and Legal Department
// Environmental Systems Research Institute, Inc.
// 380 New York Street
// Redlands, California 92373
// USA
//
// email: legal@esri.com
#include "ArcGISMapsSDK/Components/ArcGISMeshComponent.h"

#include "PhysicsEngine/BodySetup.h"
#include "PhysicsEngine/PhysicsSettings.h"

#include "ArcGISMapsSDK/Components/ArcGISMeshSceneProxy.h"

UArcGISMeshComponent::UArcGISMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SetCollisionEnabled(bIsMeshColliderEnabled && IsVisible() ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
}

FBoxSphereBounds UArcGISMeshComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	if (!ArcGISMesh)
	{
		return FBoxSphereBounds(LocalToWorld.GetLocation(), FVector::ZeroVector, 0.f);
	}

	auto boxWorldBounds = ArcGISMesh->GetBounds().TransformBy(LocalToWorld);

	if (boxWorldBounds.IsValid)
	{
		auto sphereWorldBounds = FBoxSphereBounds(boxWorldBounds);

		// Setting a minimum height (100cm) in case of flat tiles (tiles with no elevation in local)
		// This should never be a problem in global
		sphereWorldBounds.BoxExtent.Z = FMath::Max(sphereWorldBounds.BoxExtent.Z, 100);

		sphereWorldBounds.BoxExtent *= BoundsScale;
		sphereWorldBounds.SphereRadius *= BoundsScale;

		return sphereWorldBounds;
	}
	else
	{
		return FBoxSphereBounds(LocalToWorld.GetLocation(), FVector::ZeroVector, 0.f);
	}
}

void UArcGISMeshComponent::SetVisibility(bool bInVisibility)
{
	Super::SetVisibility(bInVisibility);

	UpdateCollision();
}

FPrimitiveSceneProxy* UArcGISMeshComponent::CreateSceneProxy()
{
	if (!ArcGISMesh)
	{
		return nullptr;
	}

	return new FArcGISMeshSceneProxy(this);
}

const FArcGISMeshRenderData* UArcGISMeshComponent::GetRenderData() const
{
	if (!ArcGISMesh)
	{
		return nullptr;
	}

	return ArcGISMesh->GetRenderData();
}

int32 UArcGISMeshComponent::GetNumMaterials() const
{
	return 1;
}

void UArcGISMeshComponent::SetMesh(TSharedPtr<const FGPUResourceMesh> InGPUResourceMesh)
{
	if (ArcGISMesh == nullptr)
	{
		ArcGISMesh = NewObject<UArcGISMesh>(this);
	}

	ArcGISMesh->SetRenderData(InGPUResourceMesh);

	if (IsRenderStateCreated())
	{
		// This will eventually trigger a RecreateRenderState_Concurrent
		MarkRenderStateDirty();

		UpdateBounds();
	}
	else if (ShouldCreateRenderState())
	{
		RecreateRenderState_Concurrent();
	}

	bMeshColliderCreated = false;

	UpdateCollision();
}

int32 UArcGISMeshComponent::GetFeatureIndexByTriangleIndex(uint32 InPrimitiveIndex) const
{
	return ArcGISMesh ? ArcGISMesh->GetFeatureIndexByTriangleIndex(InPrimitiveIndex) : -1;
}

bool UArcGISMeshComponent::ShouldCreateRenderState() const
{
	if (!Super::ShouldCreateRenderState())
	{
		return false;
	}

	if (ArcGISMesh == nullptr || ArcGISMesh->GetRenderData() == nullptr)
	{
		return false;
	}

	return true;
}

bool UArcGISMeshComponent::ContainsPhysicsTriMeshData(bool bInUseAllTriData) const
{
	return bIsMeshColliderEnabled && ArcGISMesh && ArcGISMesh->GetRenderData();
}

UBodySetup* UArcGISMeshComponent::GetBodySetup()
{
	return BodySetup;
}

UMaterialInterface* UArcGISMeshComponent::GetMaterialFromCollisionFaceIndex(int32 FaceIndex, int32& SectionIndex) const
{
	return nullptr;
}

bool UArcGISMeshComponent::WantsNegXTriMesh()
{
	return false;
}

void UArcGISMeshComponent::UpdateCollision()
{
	UWorld* World = GetWorld();

	if (World && World->IsGameWorld() && ArcGISMesh)
	{
		for (UBodySetup* OldBody : AsyncBodySetupQueue)
		{
			OldBody->AbortPhysicsMeshAsyncCreation();
		}

		if (bMeshColliderCreated)
		{
			SetCollisionEnabled(bIsMeshColliderEnabled && IsVisible() ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
			return;
		}

		auto NewBodySetup = NewObject<UBodySetup>(this, NAME_None, RF_NoFlags);

		NewBodySetup->BodySetupGuid = FGuid::NewGuid();
		NewBodySetup->bGenerateMirroredCollision = false;
		NewBodySetup->bDoubleSidedGeometry = true;
		NewBodySetup->CollisionTraceFlag = CTF_UseComplexAsSimple;

		AsyncBodySetupQueue.Add(NewBodySetup);

		NewBodySetup->CreatePhysicsMeshesAsync(
			FOnAsyncPhysicsCookFinished::CreateUObject(this, &UArcGISMeshComponent::FinishPhysicsAsyncCook, NewBodySetup));
	}
}

void UArcGISMeshComponent::FinishPhysicsAsyncCook(bool bSuccess, UBodySetup* FinishedBodySetup)
{
	TArray<UBodySetup*> NewQueue;
	NewQueue.Reserve(AsyncBodySetupQueue.Num());

	int32 FoundIdx;
	if (AsyncBodySetupQueue.Find(FinishedBodySetup, FoundIdx))
	{
		if (bSuccess)
		{
			bMeshColliderCreated = true;

			BodySetup = FinishedBodySetup;

			RecreatePhysicsState();

			// Remove any async body setups that were requested before this one
			for (int32 AsyncIdx = FoundIdx + 1; AsyncIdx < AsyncBodySetupQueue.Num(); ++AsyncIdx)
			{
				NewQueue.Add(AsyncBodySetupQueue[AsyncIdx]);
			}

			AsyncBodySetupQueue = NewQueue;
		}
		else
		{
			AsyncBodySetupQueue.RemoveAt(FoundIdx);
		}

		SetCollisionEnabled(bSuccess && bIsMeshColliderEnabled && IsVisible() ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
	}
}

bool UArcGISMeshComponent::GetPhysicsTriMeshData(FTriMeshCollisionData* CollisionData, bool bInUseAllTriData)
{
	ArcGISMesh->GetRenderData()->GetPhysicsTriMeshData(CollisionData);

	CollisionData->bFlipNormals = true;
	CollisionData->bDeformableMesh = true;
	CollisionData->bFastCook = true;

	return true;
}

std::pair<const FPositionVertexBuffer*, const FDynamicMeshIndexBuffer32*> UArcGISMeshComponent::GetPositionBuffer() const
{
	if (ArcGISMesh)
	{
		return ArcGISMesh->GetPositionBuffer();
	}

	return {nullptr, nullptr};
}

bool UArcGISMeshComponent::GetIsMeshColliderEnabled() const
{
	return bIsMeshColliderEnabled;
}

void UArcGISMeshComponent::SetIsMeshColliderEnabled(bool bInIsMeshColliderEnabled)
{
	if (bIsMeshColliderEnabled == bInIsMeshColliderEnabled)
	{
		return;
	}

	bIsMeshColliderEnabled = bInIsMeshColliderEnabled;

	UpdateCollision();
}
