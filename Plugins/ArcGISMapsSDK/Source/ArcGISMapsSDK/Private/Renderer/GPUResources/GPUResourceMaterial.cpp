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
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceMaterial.h"

#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace GPUResources
{
FGPUResourceMaterial::FGPUResourceMaterial(UMaterialInterface* Material)
{
	MaterialInstance = UMaterialInstanceDynamic::Create(Material, nullptr);

	MaterialInstance->AddToRoot();
}

FGPUResourceMaterial::FGPUResourceMaterial(const FString& Name)
{
	auto Material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, *Name));

	MaterialInstance = UMaterialInstanceDynamic::Create(Material, nullptr);

	MaterialInstance->AddToRoot();
}

FGPUResourceMaterial::~FGPUResourceMaterial()
{
	MaterialInstance->RemoveFromRoot();
}

UMaterialInstanceDynamic* FGPUResourceMaterial::GetInstance() const
{
	return MaterialInstance;
}

TSharedPtr<const FGPUResourceTexture> FGPUResourceMaterial::GetTexture(const FString& Name) const
{
	const auto* Value = Textures.Find(Name);

	if (Value)
	{
		return *Value;
	}

	return nullptr;
}

void FGPUResourceMaterial::SetFloat(const FString& Name, float Value)
{
	MaterialInstance->SetScalarParameterValue(FName(*Name), Value);
}

void FGPUResourceMaterial::SetVector(const FString& Name, const FVector4f& Value)
{
	MaterialInstance->SetVectorParameterValue(FName(*Name), FLinearColor(Value));
}

void FGPUResourceMaterial::SetTexture(const FString& Name, const TSharedPtr<const FGPUResourceTexture>& Value)
{
	if (Value)
	{
		MaterialInstance->SetTextureParameterValue(FName(*Name), Value->GetNativeTexture());

		Textures.Add(Name, Value);
	}
	else
	{
		MaterialInstance->SetTextureParameterValue(FName(*Name), nullptr);

		Textures.Remove(Name);
	}
}
} // namespace GPUResources
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
