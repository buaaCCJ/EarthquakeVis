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

#include "Materials/MaterialParameterCollection.h"
#include "Templates/SharedPointer.h"
#include "Templates/UniquePtr.h"

#include "ArcGISMapsSDK/Renderer/Renderables/ObbTransform.h"
#include "ArcGISMapsSDK/Renderer/Renderables/Renderable.h"
#include "ArcGISMapsSDK/Utils/ArcGISViewportProperties.h"

struct ViewportProperties;

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
class IGPUResourceProvider;
class FGPUResourceRenderTarget;
} // namespace GPUResources

namespace Renderables
{
class IRenderableProvider;
} // namespace Renderables

namespace GPUComputing
{
class FTerrainOcclusionDepthMapRenderer
{
public:
	FTerrainOcclusionDepthMapRenderer(TSharedPtr<Renderables::IRenderableProvider> InRenderableProvider,
									  TSharedPtr<GPUResources::IGPUResourceProvider> InGpuResourceProvider,
									  UObject* InOuter);

	~FTerrainOcclusionDepthMapRenderer();

	void Update(const FArcGISViewportProperties& InViewportProperties);

	UTextureRenderTarget2D* GetClippingRenderTarget();

	void BeginRendering();
	void EndRendering();

private:
	void Render(FPostOpaqueRenderParameters& parameters);
	void ClearDepthToZero(FRHICommandListImmediate& RHICmdList);
	void RenderStencilMask(FRHICommandListImmediate& RHICmdList, const FMatrix44d& InView, const FMatrix44d& InProj);
	void RenderOBBDepth(FRHICommandListImmediate& RHICmdList, const FMatrix44d& InView, const FMatrix44d& InProj);

	void InitializeCubeAndQuad();
	bool IsCameraInsideAnyOBB(const FVector3d& InCameraPosition);

	FDelegateHandle OnPostOpaqueRenderHandle;

	UMaterialParameterCollection* MaterialParameterCollection;

	FDynamicMeshIndexBuffer32 CubeIndexBuffer;
	FPositionVertexBuffer CubePositionVertexBuffer;
	FDynamicMeshIndexBuffer32 QuadIndexBuffer;
	FPositionVertexBuffer QuadPositionVertexBuffer;

	UTextureRenderTarget2D* ClippingRenderTarget;
	FTexture2DRHIRef ClippingDepthStencil;
	TSharedPtr<Renderables::IRenderableProvider> RenderableProvider;

	UObject* Outer;

	struct FCachedRenderableRenderData
	{
		FBufferRHIRef VertexBufferRHI;
		uint32 VertexCount;
		FBufferRHIRef IndexBufferRHI;
		uint32 TriangleCount;
		FMatrix44f RenderableTransform;
		Renderables::FObbTransform ObbTransform;
	};

	TArray<FCachedRenderableRenderData> RThreadRenderableRenderData;

	FIntPoint ViewportSize;
};
} // namespace GPUComputing
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
