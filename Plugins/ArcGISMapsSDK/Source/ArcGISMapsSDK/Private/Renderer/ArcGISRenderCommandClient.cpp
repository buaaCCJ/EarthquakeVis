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
#include "ArcGISMapsSDK/Renderer/ArcGISRenderCommandClient.h"

#include <array>
#include <vector>

#include "Misc/EngineVersionComparison.h"

#include "ArcGISMapsSDK/API/GameEngine/Math/ArcGISVector4.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISComposedTextureElement.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISCopyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISCreateRenderTargetCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISCreateRenderableCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISCreateTextureCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDataBufferView.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDestroyRenderTargetCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDestroyRenderableCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDestroyTextureCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISGenerateNormalTextureCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISMeshBufferChangeType.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISMultipleComposeCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderCommandType.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderableType.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialNamedTexturePropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialRenderTargetPropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialScalarPropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialTexturePropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialVectorPropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMeshCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderablePivotCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableVisibleCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetTexturePixelDataCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISTextureFormat.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISDataBuffer.h"
#include "ArcGISMapsSDK/Components/ArcGISMapComponentInterface.h"
#include "ArcGISMapsSDK/Renderer/GPUComputing/IImageComposer.h"
#include "ArcGISMapsSDK/Renderer/GPUComputing/INormalMapGenerator.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/GPUResourceMaterial.h"
#include "ArcGISMapsSDK/Renderer/GPUResources/IGPUResourceProvider.h"
#include "ArcGISMapsSDK/Renderer/Renderables/IRenderableProvider.h"
#include "ArcGISMapsSDK/Renderer/Renderables/ObbTransform.h"
#include "ArcGISMapsSDK/Renderer/Renderables/Renderable.h"

namespace
{
template <typename T>
TArrayView<T> ToArrayView(const Esri::GameEngine::RCQ::ArcGISDataBufferView& View)
{
	return TArrayView<T>(reinterpret_cast<T*>(View.Data), View.Size / sizeof(T));
}

template <typename To, typename From>
To TransformStruct(const From& from)
{
	To to;

	static_assert(sizeof(From) == sizeof(To), "The input struct size should be the same as the output one");
	static_assert(std::is_trivially_copyable<From>::value, "The input struct should be trivially copyable");
	static_assert(std::is_trivially_copyable<To>::value, "The output struct should be trivially copyable");

	memcpy(&to, &from, sizeof(To));

	return to;
}

const FString& GetScalarPropertyName(Esri::GameEngine::RCQ::ArcGISMaterialScalarProperty Property)
{
	static auto Names = std::array<FString, 5>{"ClippingMode", "UseUVIndex", "Metallic", "Roughness", "Opacity"};
	return Names[static_cast<int>(Property)];
}

const FString& GetVectorPropertyName(Esri::GameEngine::RCQ::ArcGISMaterialVectorProperty Property)
{
	static auto Names = std::array<FString, 4>{"MapAreaMin", "MapAreaMax", "NormalMapRegion", "ImageryRegion"};
	return Names[static_cast<int>(Property)];
}

const FString& GetTexturePropertyName(Esri::GameEngine::RCQ::ArcGISMaterialTextureProperty Property)
{
	// clang-format off
	static auto Names = std::array<FString, 9>
	{
		"Imagery",
		"NormalMap",
		"BaseMap",
		"UVRegionLUT",
		"PositionsMap",
		"FeatureIds",
		"MetallicRoughness",
		"Emissive",
		"OcclusionMap"
	};
	// clang-format on

	return Names[static_cast<int>(Property)];
}
} // namespace

namespace Esri
{
namespace ArcGISMapsSDK
{
namespace Renderer
{
namespace
{
Renderables::FObbTransform TransformObbForENU(IArcGISMapComponentInterface* InMap, const Renderables::FObbTransform& InObbTransform)
{
	// Obb is in UE coordinates, convert, transform, convert back (with scale)
	Renderables::FObbTransform result;

	result.Position = InMap->ToEnginePosition(InObbTransform.Position);
	result.Rotation = InMap->GetENUToWorldTransformAtOrigin().GetRotation() * InObbTransform.Rotation;
	result.Scale = (InObbTransform.Scale * 100.).GetAbs();

	return result;
}
} // namespace

FArcGISRenderCommandClient::FArcGISRenderCommandClient(IArcGISMapComponentInterface* InMap,
													   TSharedPtr<GPUResources::IGPUResourceProvider> InGPUResourceProvider,
													   TSharedPtr<Renderables::IRenderableProvider> InRenderableProvider,
													   TSharedPtr<GPUComputing::IImageComposer> InImageComposer,
													   TSharedPtr<GPUComputing::INormalMapGenerator> InNormalMapGenerator)
: GPUResourceProvider(InGPUResourceProvider),
  ImageComposer(InImageComposer),
  Map(InMap),
  NormalMapGenerator(InNormalMapGenerator),
  RenderableProvider(InRenderableProvider)
{
}

void FArcGISRenderCommandClient::ExecuteRenderCommand(const GameEngine::RCQ::ArcGISRenderCommand& RenderCommand)
{
	using namespace GameEngine::RCQ;

	switch (RenderCommand.GetType())
	{
		case ArcGISRenderCommandType::CreateRenderTarget:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISCreateRenderTargetCommandParameters>();

			GPUResourceProvider->CreateRenderTarget(Params.RenderTargetId, Params.Width, Params.Height, Params.TextureFormat, Params.HasMipMaps);

			break;
		}

		case ArcGISRenderCommandType::CreateTexture:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISCreateTextureCommandParameters>();

			GPUResourceProvider->CreateTexture(Params.TextureId, Params.Width, Params.Height, Params.TextureFormat, Params.IsSRGB);

			break;
		}

		case ArcGISRenderCommandType::CreateRenderable:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISCreateRenderableCommandParameters>();

			auto Renderable = RenderableProvider->CreateRenderable(Params.RenderableId, Params.RenderableType, Params.LayerId, Params.CallbackToken);

			UMaterialInterface* CustomMaterial{nullptr};
			if (Params.Material)
			{
				CustomMaterial = Cast<UMaterialInterface>(reinterpret_cast<FWeakObjectPtr*>(Params.Material)->Get());
			}
			auto Material = GPUResourceProvider->CreateMaterial(Params.RenderableId, Params.RenderableType, CustomMaterial);

			Renderable->SetMaterial(Material);

			break;
		}

		case ArcGISRenderCommandType::DestroyRenderTarget:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISDestroyRenderTargetCommandParameters>();

			GPUResourceProvider->DestroyRenderTarget(Params.RenderTargetId);
			break;
		}

		case ArcGISRenderCommandType::DestroyTexture:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISDestroyTextureCommandParameters>();

			GPUResourceProvider->DestroyTexture(Params.TextureId);
			break;
		}

		case ArcGISRenderCommandType::DestroyRenderable:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISDestroyRenderableCommandParameters>();

			GPUResourceProvider->DestroyMaterial(Params.RenderableId);
			RenderableProvider->DestroyRenderable(Params.RenderableId);

			break;
		}

		case ArcGISRenderCommandType::MultipleCompose:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISMultipleComposeCommandParameters>();

			const auto& Target = GPUResourceProvider->GetRenderTarget(Params.TargetId);

			std::vector<GPUComputing::FComposableImage> Images;

			auto Texture = reinterpret_cast<ArcGISComposedTextureElement*>(Params.ComposedTextures.Data);
			auto Texture_end = reinterpret_cast<ArcGISComposedTextureElement*>(Params.ComposedTextures.Data + Params.ComposedTextures.Size);

			while (Texture < Texture_end)
			{
				auto TargetTexture = GPUResourceProvider->GetTexture(Texture->TextureId);

				Images.emplace_back(GPUComputing::FComposableImage{TransformStruct<FVector4f>(Texture->Region), TargetTexture, Texture->Opacity});
				Texture++;
			}

			ImageComposer->Compose(Images, Target);
			break;
		}

		case ArcGISRenderCommandType::Copy:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISCopyCommandParameters>();

			const auto& Source = GPUResourceProvider->GetRenderTarget(Params.SourceId);
			const auto& Target = GPUResourceProvider->GetRenderTarget(Params.TargetId);

			ImageComposer->Copy(Source, Target, TransformStruct<FVector4f>(Params.Region));
			break;
		}

		case ArcGISRenderCommandType::GenerateNormalTexture:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISGenerateNormalTextureCommandParameters>();
			const auto& Target = GPUResourceProvider->GetRenderTarget(Params.TargetId);
			const auto& Elevation =
				Params.ElevationId != 0 ? GPUResourceProvider->GetTexture(Params.ElevationId) : GPUResourceProvider->GetBlackFloatTexture();
			auto TileExtent = TransformStruct<FVector4f>(Params.TileExtent);
			auto Region = TransformStruct<FVector4f>(Params.TextureExtent);
			NormalMapGenerator->Compute(Elevation, TileExtent, Region, Target);

			break;
		}

		case ArcGISRenderCommandType::SetTexturePixelData:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetTexturePixelDataCommandParameters>();
			const auto& Texture = GPUResourceProvider->GetTexture(Params.TextureId);

			Texture->SetPixelData(Params.Pixels.Data);

			break;
		}

		case ArcGISRenderCommandType::SetRenderableMaterialScalarProperty:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetRenderableMaterialScalarPropertyCommandParameters>();

			const auto& Material = GPUResourceProvider->GetMaterial(Params.RenderableId);
			const auto& Name = GetScalarPropertyName(Params.MaterialScalarProperty);

			if (Params.RenderableId == 0)
			{
				// Global property
				check(Params.MaterialScalarProperty == ArcGISMaterialScalarProperty::ClippingMode);

				// Cache the global property value for setting on subsequently created materials
				GlobalScalarProperties.Add(Params.MaterialScalarProperty, Params.Value);

				const auto& Renderables = RenderableProvider->GetRenderables();
				for (const auto& Renderable : Renderables)
				{
					const auto RenderableId = Renderable.Key;
					GPUResourceProvider->GetMaterial(RenderableId)->SetFloat(Name, Params.Value);
				}
			}
			else
			{
				// Per-instance property
				check(Params.MaterialScalarProperty == ArcGISMaterialScalarProperty::Opacity ||
					  Params.MaterialScalarProperty == ArcGISMaterialScalarProperty::UseUvRegionLut ||
					  Params.MaterialScalarProperty == ArcGISMaterialScalarProperty::Metallic ||
					  Params.MaterialScalarProperty == ArcGISMaterialScalarProperty::Roughness);
				Material->SetFloat(Name, Params.Value);
			}
			break;
		}

		case ArcGISRenderCommandType::SetRenderableMaterialVectorProperty:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetRenderableMaterialVectorPropertyCommandParameters>();
			const auto& Name = GetVectorPropertyName(Params.MaterialVectorProperty);
			const auto Value = TransformStruct<FVector4d>(Params.Value);

			if (Params.RenderableId == 0)
			{
				check(Params.MaterialVectorProperty == ArcGISMaterialVectorProperty::MapAreaMin ||
					  Params.MaterialVectorProperty == ArcGISMaterialVectorProperty::MapAreaMax);

				// Global property

				// Cache the global property value for setting on subsequently created materials
				GlobalVectorProperties.Add(Params.MaterialVectorProperty, Value);

				// Set position, relative to Renderable, on all Materials
				const auto& Renderables = RenderableProvider->GetRenderables();
				for (const auto& Renderable : Renderables)
				{
					const auto RenderableId = Renderable.Key;
					auto& Pivot = Renderable.Value->GetPivot();
					const FVector4d Pivot4(Pivot.X, Pivot.Y, Pivot.Z, 0);
					const auto RelativeValue = FVector4f(Value - Pivot4);
					GPUResourceProvider->GetMaterial(RenderableId)->SetVector(Name, RelativeValue);
				}
			}
			else
			{
				// Per-instance property
				check(Params.MaterialVectorProperty == ArcGISMaterialVectorProperty::NormalMapRegion ||
					  Params.MaterialVectorProperty == ArcGISMaterialVectorProperty::ImageryRegion);

				const auto& Material = GPUResourceProvider->GetMaterial(Params.RenderableId);
				Material->SetVector(Name, FVector4f(Value));
			}
			break;
		}

		case ArcGISRenderCommandType::SetRenderableMaterialRenderTargetProperty:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetRenderableMaterialRenderTargetPropertyCommandParameters>();

			const auto& Material = GPUResourceProvider->GetMaterial(Params.RenderableId);
			const auto& RenderTarget = GPUResourceProvider->GetRenderTarget(Params.Value);
			const auto& Name = GetTexturePropertyName(Params.MaterialTextureProperty);

			Material->SetTexture(Name, RenderTarget);
			break;
		}

		case ArcGISRenderCommandType::SetRenderableMaterialTextureProperty:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetRenderableMaterialTexturePropertyCommandParameters>();

			const auto& Material = GPUResourceProvider->GetMaterial(Params.RenderableId);
			const auto& Texture = GPUResourceProvider->GetTexture(Params.Value);
			const auto& Name = GetTexturePropertyName(Params.MaterialTextureProperty);

			Material->SetTexture(Name, Texture);
			break;
		}

		case ArcGISRenderCommandType::SetRenderableMaterialNamedTextureProperty:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetRenderableMaterialNamedTexturePropertyCommandParameters>();

			const auto& Material = GPUResourceProvider->GetMaterial(Params.RenderableId);
			const auto& Texture = GPUResourceProvider->GetTexture(Params.Value);
			const FString Name{static_cast<int32>(Params.TextureName.Size), reinterpret_cast<const char*>(Params.TextureName.Data)};

			Material->SetTexture(Name, Texture);
			break;
		}

		case ArcGISRenderCommandType::SetRenderableVisible:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetRenderableVisibleCommandParameters>();

			const auto& Renderable = RenderableProvider->GetRenderable(Params.RenderableId);

			Renderable->SetIsVisible(Params.IsVisible);
			break;
		}

		case ArcGISRenderCommandType::SetRenderableMesh:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetRenderableMeshCommandParameters>();
			const auto& Renderable = RenderableProvider->GetRenderable(Params.RenderableId);

			auto SafeMeshData = ::MakeShared<FGPUResourceMesh>();

			// Assure the vertex attributes are always packed into the same UV index
			static constexpr auto RealUVIndex = 0;
			static constexpr auto FeatureIndicesUvIndex = 1;
			static constexpr auto UvRegionIdsUvIndex = 2;

			bool HasFeatureIndices = Params.FeatureIndices.Size > 0u;
			bool HasUvRegionIds = Params.UvRegionIds.Size > 0u;

			auto NumUVs = 1 + std::max(HasFeatureIndices * FeatureIndicesUvIndex, HasUvRegionIds * UvRegionIdsUvIndex);

			SafeMeshData->UVs.SetNum(NumUVs);

			if (HasFeatureIndices)
			{
				SafeMeshData->bUseFullPrecisionUVs = true;
				SafeMeshData->UVs[FeatureIndicesUvIndex] = {ToArrayView<float>(Params.FeatureIndices), 2};
			}

			if (HasUvRegionIds)
			{
				SafeMeshData->UVs[UvRegionIdsUvIndex] = {ToArrayView<float>(Params.UvRegionIds), 1};
			}

			SafeMeshData->Normals = ToArrayView<FVector3f>(Params.Normals);
			SafeMeshData->Tangents = ToArrayView<FVector4f>(Params.Tangents);
			SafeMeshData->UVs[RealUVIndex] = {ToArrayView<float>(Params.Uvs), 2};
			SafeMeshData->Triangles = ToArrayView<int32>(Params.Triangles);
			SafeMeshData->Colors = ToArrayView<uint32>(Params.Colors);
			SafeMeshData->Positions = ToArrayView<FVector3f>(Params.Positions);

			Renderable->SetMesh(SafeMeshData);

			Renderable->SetMasksTerrain(Params.MaskTerrain);

			if (Params.MaskTerrain)
			{
				const auto& Obb = Params.OrientedBoundingBox;

				FVector3d ObbPos(Obb.CenterX, Obb.CenterY, Obb.CenterZ);
				FVector3d ObbScale(Obb.ExtentX, Obb.ExtentY, Obb.ExtentZ);
				FQuat ObbRot(Obb.OrientationX, Obb.OrientationY, Obb.OrientationZ, Obb.OrientationW);

				// Scale is doubled to go from half-size to size
				Renderable->SetObbTransform(TransformObbForENU(Map, Renderables::FObbTransform{ObbPos, 2. * ObbScale, ObbRot}));
			}
			break;
		}

		case ArcGISRenderCommandType::SetRenderablePivot:
		{
			const auto& Params = RenderCommand.GetParameters<ArcGISSetRenderablePivotCommandParameters>();

			const auto& Renderable = RenderableProvider->GetRenderable(Params.RenderableId);

			Renderable->SetScale(FVector3d(100.0));

			Renderable->ENUToWorldTransformAtOrigin = Map->GetENUToWorldTransformAtOrigin();
			Renderable->SetRotation(Renderable->ENUToWorldTransformAtOrigin.GetRotation());

			// Pivots and vertices are in UE coordinates.
			auto UEFrameCoordinates = Params;

			// To convert from UE into ECEF/Projected, we have to invert the Y coordinate because of left-handed UE Frame.
			FVector3d Coordinates(UEFrameCoordinates.X, UEFrameCoordinates.Y, UEFrameCoordinates.Z);

			// Store global location so we can generate relative positions for clipping area later
			Renderable->SetPivot(Coordinates);

			auto EngineLocation = Map->ToEnginePosition(Coordinates);

			Renderable->SetLocation(EngineLocation);

			const auto RenderableId = Params.RenderableId;
			const auto Location = Coordinates;

			const auto SetRelativePositionProperty = [&](ArcGISMaterialVectorProperty Property) {
				// Set global properties on Renderable
				if (auto GlobalPosition = GlobalVectorProperties.Find(Property); GlobalPosition)
				{
					const auto RelativeValue =
						FVector4f(static_cast<float>(GlobalPosition->X - Location.X), static_cast<float>(GlobalPosition->Y - Location.Y),
								  static_cast<float>(GlobalPosition->Z - Location.Z), 0.0F);
					GPUResourceProvider->GetMaterial(RenderableId)->SetVector(GetVectorPropertyName(Property), RelativeValue);
				}
			};

			SetRelativePositionProperty(ArcGISMaterialVectorProperty::MapAreaMin);
			SetRelativePositionProperty(ArcGISMaterialVectorProperty::MapAreaMax);

			if (auto Value = GlobalScalarProperties.Find(ArcGISMaterialScalarProperty::ClippingMode); Value)
			{
				GPUResourceProvider->GetMaterial(RenderableId)->SetFloat(GetScalarPropertyName(ArcGISMaterialScalarProperty::ClippingMode), *Value);
			}

			break;
		}

		case ArcGISRenderCommandType::CommandGroupBegin:
		case ArcGISRenderCommandType::CommandGroupEnd:
			break;

		default:
			throw "Unknown render command type!";
	}
}
} // namespace Renderer
} // namespace ArcGISMapsSDK
} // namespace Esri
