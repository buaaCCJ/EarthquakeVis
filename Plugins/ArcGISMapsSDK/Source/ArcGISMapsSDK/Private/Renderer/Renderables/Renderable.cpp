// COPYRIGHT 1995-2022 ESRI
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
#include "ArcGISMapsSDK/Renderer/Renderables/Renderable.h"

#include "Async/Async.h"

#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceMaterial.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceMesh.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace Renderables
{
FRenderable::FRenderable(UObject* InOuter, uint32 InLayerId, uint64 InCallbackToken)
: CallbackToken(InCallbackToken),
  LayerId(InLayerId),
  Outer(InOuter)
{
	CreateMeshComponent();
}

FRenderable::~FRenderable()
{
	if (MeshComponent && MeshComponent->IsValidLowLevel())
	{
		MeshComponent->ConditionalBeginDestroy();
	}
}

void FRenderable::CreateMeshComponent()
{
	if (!MeshComponent)
	{
		MeshComponent = NewObject<UArcGISMeshComponent>(Outer);

		MeshComponent->SetFlags(RF_Transient | RF_DuplicateTransient | RF_TextExportTransient);

		MeshComponent->CastShadow = bCastsShadows ? 1 : 0;

		MeshComponent->RegisterComponent();

		if (GPUResourceMaterial)
		{
			MeshComponent->SetMaterial(0, GPUResourceMaterial->GetInstance());
		}
	}

	MeshComponent->SetVisibility(false);

	bIsVisible = false;
}

uint64 FRenderable::GetCallbackToken() const
{
	return CallbackToken;
}

bool FRenderable::GetIsMeshColliderEnabled() const
{
	return MeshComponent->GetIsMeshColliderEnabled();
}

bool FRenderable::GetIsVisible() const
{
	return bIsVisible;
}

void FRenderable::SetIsMeshColliderEnabled(bool bInIsMeshColliderEnabled)
{
	MeshComponent->SetIsMeshColliderEnabled(bInIsMeshColliderEnabled);
}

bool FRenderable::GetMasksTerrain() const
{
	return bMasksTerrain;
}

const TSharedPtr<const GPUResources::FGPUResourceMaterial>& FRenderable::GetMaterial() const
{
	return GPUResourceMaterial;
}

void FRenderable::SetMasksTerrain(bool bInMasksTerrain)
{
	bMasksTerrain = bInMasksTerrain;
}

const FObbTransform& FRenderable::GetObbTransform() const
{
	return ObbTransform;
}

std::pair<const FPositionVertexBuffer*, const FDynamicMeshIndexBuffer32*> FRenderable::GetPositionBuffer()
{
	if (!MeshComponent)
	{
		return {nullptr, nullptr};
	}

	return MeshComponent->GetPositionBuffer();
}

const FTransform& FRenderable::GetTransform() const
{
	return MeshComponent->GetComponentTransform();
}

void FRenderable::SetObbTransform(const FObbTransform& InObbTransform)
{
	ObbTransform = InObbTransform;
}

uint32 FRenderable::GetLayerId() const
{
	return LayerId;
}

const UArcGISMeshComponent* FRenderable::GetMeshComponent() const
{
	return MeshComponent;
}

void FRenderable::SetCastsShadows(bool bInCastsShadows)
{
	if (bCastsShadows != bInCastsShadows)
	{
		bCastsShadows = bInCastsShadows;

		MeshComponent->CastShadow = bCastsShadows ? 1 : 0;
	}
}

void FRenderable::SetIsVisible(bool bInIsVisible)
{
	if (bIsVisible != bInIsVisible)
	{
		bIsVisible = bInIsVisible;

		MeshComponent->SetVisibility(bIsVisible);
	}
}

void FRenderable::SetMaterial(const TSharedPtr<const GPUResources::FGPUResourceMaterial>& InGPUResourceMaterial)
{
	if (GPUResourceMaterial != InGPUResourceMaterial)
	{
		GPUResourceMaterial = InGPUResourceMaterial;

		if (MeshComponent)
		{
			MeshComponent->SetMaterial(0, GPUResourceMaterial ? GPUResourceMaterial->GetInstance() : nullptr);
		}
	}
}

void FRenderable::SetMesh(const TSharedPtr<const GPUResources::FGPUResourceMesh>& InGPUResourceMesh)
{
	// Set the mesh asynchronously as SetMesh can take time to execute and may affect throttling
	TWeakPtr<FRenderable> Self = AsShared();
	AsyncTask(ENamedThreads::GameThread, [Self, GPUResourceMesh = std::move(InGPUResourceMesh)]() {
		// It may happen the Renderable gets destroyed in-between
		if (auto Renderable = Self.Pin())
		{
			Renderable->MeshComponent->SetMesh(GPUResourceMesh);
		}
	});
}

FVector3d FRenderable::GetLocation() const
{
	return MeshComponent->GetComponentLocation();
}

void FRenderable::SetLocation(FVector3d InLocation)
{
	MeshComponent->SetWorldLocation(std::move(InLocation), false, nullptr, ETeleportType::TeleportPhysics);
}

void FRenderable::SetPivot(const FVector3d& InPivot)
{
	Pivot = InPivot;
}

const FVector3d& FRenderable::GetPivot() const
{
	return Pivot;
}

void FRenderable::SetScale(const FVector3d& InScale)
{
	MeshComponent->SetWorldScale3D(InScale);
}

void FRenderable::SetRotation(const FQuat& InRotation)
{
	MeshComponent->SetWorldRotation(InRotation, false, nullptr, ETeleportType::TeleportPhysics);
}
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
