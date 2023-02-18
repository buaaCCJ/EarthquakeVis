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
#include "ArcGISMapsSDK/Components/ArcGISMesh.h"

namespace
{
FBox CalculateLocalBounds(TSharedPtr<const FGPUResourceMesh> InGPUResourceMesh)
{
	FBox box{ForceInit};

	for (int32 i = 0; i < InGPUResourceMesh->Positions.Num(); ++i)
	{
		box += FVector3d(InGPUResourceMesh->Positions[i]);
	}

	return box;
}
} // namespace

void UArcGISMesh::BeginDestroy()
{
	Super::BeginDestroy();

	if (bRenderingResourcesInitialized)
	{
		ReleaseResources();
	}
}

FBox UArcGISMesh::GetBounds() const
{
	return LocalBounds;
}

const FArcGISMeshRenderData* UArcGISMesh::GetRenderData() const
{
	return RenderData.Get();
}

bool UArcGISMesh::IsReadyForFinishDestroy()
{
	if (bRenderingResourcesInitialized)
	{
		ReleaseResources();
	}

	return ReleaseResourcesFence.IsFenceComplete();
}

void UArcGISMesh::ReleaseResources()
{
	if (RenderData)
	{
		RenderData->ReleaseResources();

		ReleaseResourcesFence.BeginFence();
	}

	bRenderingResourcesInitialized = false;
}

void UArcGISMesh::SetRenderData(TSharedPtr<const Esri::ArcGISMapsSDK::Renderer::GPUResources::FGPUResourceMesh> InGPUResourceMesh)
{
	if (!RenderData)
	{
		UWorld* World = GetWorld();

		RenderData = MakeUnique<FArcGISMeshRenderData>(World ? World->FeatureLevel.GetValue() : ERHIFeatureLevel::Num);
	}

	RenderData->SetMeshData(InGPUResourceMesh);

	LocalBounds = CalculateLocalBounds(std::move(InGPUResourceMesh));

	bRenderingResourcesInitialized = true;
}

int32 UArcGISMesh::GetFeatureIndexByTriangleIndex(uint32 InPrimitiveIndex) const
{
	return RenderData ? RenderData->GetFeatureIndexByTriangleIndex(InPrimitiveIndex) : -1;
}

std::pair<const FPositionVertexBuffer*, const FDynamicMeshIndexBuffer32*> UArcGISMesh::GetPositionBuffer() const
{
	if (RenderData)
	{
		return RenderData->GetPositionBuffer();
	}

	return {nullptr, nullptr};
}
