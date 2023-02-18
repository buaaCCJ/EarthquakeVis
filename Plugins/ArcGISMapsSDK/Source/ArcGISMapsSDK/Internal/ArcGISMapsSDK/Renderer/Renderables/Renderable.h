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
#pragma once

#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderableType.h"
#include "ArcGISMapsSDK/Components/ArcGISMeshComponent.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceMaterial.h"
#include "ArcGISMapsSDK/Renderer/Renderables/ObbTransform.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace Renderables
{
class FRenderable : public TSharedFromThis<FRenderable>
{
public:
	FRenderable(UObject* InOuter, uint32 InLayerId, uint64 InCallbackToken);
	virtual ~FRenderable();

	virtual GameEngine::RCQ::ArcGISRenderableType GetRenderableType() const = 0;
	virtual bool HasGPUResources() const = 0;

	uint64 GetCallbackToken() const;

	uint32 GetLayerId() const;
	const UArcGISMeshComponent* GetMeshComponent() const;
	std::pair<const FPositionVertexBuffer*, const FDynamicMeshIndexBuffer32*> GetPositionBuffer();
	const FTransform& GetTransform() const;

	void SetCastsShadows(bool bInCastsShadows);
	void SetMesh(const TSharedPtr<const GPUResources::FGPUResourceMesh>& InGPUResourceMesh);
	void SetRotation(const FQuat& InRotation);
	void SetScale(const FVector3d& InScale);

	FVector3d GetLocation() const;
	void SetLocation(FVector3d InLocation);

	bool GetIsMeshColliderEnabled() const;
	void SetIsMeshColliderEnabled(bool bInIsMeshColliderEnabled);

	bool GetIsVisible() const;
	void SetIsVisible(bool bInIsVisible);

	bool GetMasksTerrain() const;
	void SetMasksTerrain(bool bInMasksTerrain);

	const TSharedPtr<const GPUResources::FGPUResourceMaterial>& GetMaterial() const;
	void SetMaterial(const TSharedPtr<const GPUResources::FGPUResourceMaterial>& InGPUResourceMaterial);

	const FObbTransform& GetObbTransform() const;
	void SetObbTransform(const FObbTransform& InObbTransform);

	const FVector3d& GetPivot() const;
	void SetPivot(const FVector3d& InPivot);

	FTransform ENUToWorldTransformAtOrigin;

protected:
	void CreateMeshComponent();

	bool bCastsShadows{true};
	bool bMasksTerrain{false};
	bool bIsVisible{false};

	uint64 CallbackToken{0};
	TSharedPtr<const GPUResources::FGPUResourceMaterial> GPUResourceMaterial;
	uint32 LayerId{0};
	UArcGISMeshComponent* MeshComponent{nullptr};
	FObbTransform ObbTransform;
	UObject* Outer{nullptr};
	FVector3d Pivot;
};
} // namespace Renderables
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
