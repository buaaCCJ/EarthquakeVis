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
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDecodedRenderCommandQueue.h"

#include "ArcGISMapsSDK/API/GameEngine/Math/ArcGISVector4.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISRenderCommandType.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISComposedTextureElement.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISCopyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISCreateRenderTargetCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISCreateRenderableCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISCreateTextureCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDestroyRenderTargetCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDestroyRenderableCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISDestroyTextureCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISGenerateNormalTextureCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISMeshBufferChangeType.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISMultipleComposeCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISNullCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialNamedTexturePropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialRenderTargetPropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialScalarPropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialTexturePropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMaterialVectorPropertyCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableMeshCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderablePivotCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetTexturePixelDataCommandParameters.h"
#include "ArcGISMapsSDK/API/GameEngine/RCQ/ArcGISSetRenderableVisibleCommandParameters.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISDataBuffer.h"

namespace Esri
{
namespace GameEngine
{
namespace RCQ
{
ArcGISDecodedRenderCommandQueue::ArcGISDecodedRenderCommandQueue(Unreal::ArcGISDataBuffer<uint8_t> InRawRenderCommands)
{
	RawRenderCommands = std::move(InRawRenderCommands);
}

#define DECODE_COMMAND_WITH_PARAMETERS(EnumValue, ParameterName)                 \
	case ArcGISRenderCommandType::EnumValue:                                     \
	{                                                                            \
		return GetRenderCommand<ParameterName##CommandParameters>(); \
	}

#define DECODE_COMMAND(EnumValue) DECODE_COMMAND_WITH_PARAMETERS(EnumValue, ArcGIS##EnumValue)

ArcGISRenderCommand* ArcGISDecodedRenderCommandQueue::GetNextCommand()
{
	if (RawRenderCommands && CurrentOffset < RawRenderCommands.GetSizeBytes())
	{
		auto CommandType = GetCommandType();
		switch (CommandType)
		{
			DECODE_COMMAND(Copy);
			DECODE_COMMAND(CreateRenderTarget);
			DECODE_COMMAND(CreateRenderable);
			DECODE_COMMAND(CreateTexture);
			DECODE_COMMAND(DestroyRenderTarget);
			DECODE_COMMAND(DestroyRenderable);
			DECODE_COMMAND(DestroyTexture);
			DECODE_COMMAND(GenerateNormalTexture);
			DECODE_COMMAND(MultipleCompose);
			DECODE_COMMAND(SetRenderableMaterialNamedTextureProperty);
			DECODE_COMMAND(SetRenderableMaterialRenderTargetProperty);
			DECODE_COMMAND(SetRenderableMaterialScalarProperty);
			DECODE_COMMAND(SetRenderableMaterialTextureProperty);
			DECODE_COMMAND(SetRenderableMaterialVectorProperty);
			DECODE_COMMAND(SetRenderableMesh);
			DECODE_COMMAND(SetRenderablePivot);
			DECODE_COMMAND(SetTexturePixelData);
			DECODE_COMMAND(SetRenderableVisible);
			DECODE_COMMAND_WITH_PARAMETERS(CommandGroupBegin, ArcGISNull);
			DECODE_COMMAND_WITH_PARAMETERS(CommandGroupEnd, ArcGISNull);
			default:
			{
				// debug ignore unknown commands
				throw "Unknown render command type!";
			}
		}
	}
	return nullptr;
}

ArcGISRenderCommandType ArcGISDecodedRenderCommandQueue::GetCommandType()
{
	return *reinterpret_cast<ArcGISRenderCommandType*>(RawRenderCommands.GetData<uint8>() + CurrentOffset);
}

template <typename T>
ArcGISRenderCommand* ArcGISDecodedRenderCommandQueue::GetRenderCommand()
{
	auto Address = RawRenderCommands.GetData<uint8>() + CurrentOffset;
	CurrentOffset += sizeof(ArcGISRenderCommandType) + sizeof(T);
	return reinterpret_cast<ArcGISRenderCommand*>(Address);
}
} // namespace RCQ
} // namespace GameEngine
} // namespace Esri
