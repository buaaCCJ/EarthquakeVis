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
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceTexture.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
FGPUResourceTexture ::~FGPUResourceTexture()
{
	if (NativeTexture)
	{
		NativeTexture->RemoveFromRoot();
	}
}

bool FGPUResourceTexture::GetIsUpdated() const
{
	return bIsUpdated;
}

UTexture* FGPUResourceTexture::GetNativeTexture() const
{
	return NativeTexture;
}

void FGPUResourceTexture::SetIsUpdated(bool bInIsUpdated)
{
	bIsUpdated = bInIsUpdated;
}

void FGPUResourceTexture::SetIsUpdatedInRenderThread(bool bInIsUpdated)
{
	TWeakPtr<FGPUResourceTexture> WeakSelf = AsShared();

	ENQUEUE_RENDER_COMMAND(UpdateRenderTargetStatus)
	([WeakSelf, bInIsUpdated](FRHICommandListImmediate& /*RHICmdList*/) {
		if (auto StrongSelf = WeakSelf.Pin())
		{
			StrongSelf->bIsUpdated = bInIsUpdated;
		}
	});
}
} // namespace GPUResources
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
