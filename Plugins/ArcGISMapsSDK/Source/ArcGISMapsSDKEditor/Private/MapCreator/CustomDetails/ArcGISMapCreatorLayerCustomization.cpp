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
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorLayerCustomization.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "EditorViewportClient.h"
#include "IDetailChildrenBuilder.h"
#include "IPropertyTypeCustomization.h"
#include "IPropertyUtilities.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"

#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorLayerTool.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"

using namespace MapCreatorUtilities;

TSharedRef<IPropertyTypeCustomization> FArcGISMapCreatorLayerCustomization::MakeInstance()
{
	return MakeShared<FArcGISMapCreatorLayerCustomization>();
}

void FArcGISMapCreatorLayerCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle,
														  FDetailWidgetRow& HeaderRow,
														  IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	NameProp = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMapCreatorLayer, Name));
	FString name{};
	NameProp->GetValue(name);

	IsVisibleProp = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMapCreatorLayer, bIsVisible));
	bool isVisible = false;
	IsVisibleProp->GetValue(isVisible);

	// clang-format off
	HeaderRow
	.NameContent()
	[
		SAssignNew(LayerNameText, STextBlock)
		.Text(FText::FromString(name))
		.Font(IDetailLayoutBuilder::GetDetailFont())
	]
	.ValueContent()
	[
		SNew(SCheckBox)
		.IsChecked(isVisible)
		.OnCheckStateChanged_Lambda([this](ECheckBoxState state)
		{
			 auto isChecked = state == ECheckBoxState::Checked ? true : false;
			 IsVisibleProp->SetValue(isChecked);
		})
	];
	// clang-format on
}

void FArcGISMapCreatorLayerCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle,
															IDetailChildrenBuilder& ChildBuilder,
															IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	ChildBuilder.AddProperty(NameProp.ToSharedRef());

	NameProp->SetOnPropertyValueChanged(FSimpleDelegate::CreateLambda([this]() {
		FString name{};
		NameProp->GetValue(name);
		LayerNameText->SetText(FText::FromString(name));
	}));

	SourceProp = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMapCreatorLayer, Source));
	ChildBuilder.AddProperty(SourceProp.ToSharedRef());

	OpacityProp = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMapCreatorLayer, Opacity));
	ChildBuilder.AddProperty(OpacityProp.ToSharedRef());

	TypeProp = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMapCreatorLayer, Type));
	ChildBuilder.AddProperty(TypeProp.ToSharedRef());

	AuthConfigIDProp = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMapCreatorLayer, AuthConfigID));
	ChildBuilder.AddProperty(AuthConfigIDProp.ToSharedRef());

	// clang-format off
	ChildBuilder.AddCustomRow(FText::FromString("Zoom to Layer"))
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.HAlign(EHorizontalAlignment::HAlign_Right)
		[
			SNew(SButton)
			.Content()
			[
				SNew(STextBlock)
				.Font(IDetailLayoutBuilder::GetDetailFont())
				.Text(FText::FromString("Zoom to Layer"))
				.Margin(FMargin(0, 4, 0, 0))
			]
			.OnClicked_Lambda([PropertyHandle]()
			{
				void* data;
				PropertyHandle->GetValueData(data);

				if (data == nullptr)
				{
					return FReply::Handled();
				}

				auto propertyLayer = reinterpret_cast<FMapCreatorLayer*>(data);

				if (propertyLayer)
				{
					auto mapComponent = Cast<UArcGISMapComponent>(MapComponentManager::GetMapComponent());

					if (!mapComponent)
					{
						return FReply::Handled();
					}

					FArcGISLayerInstanceData mapLayer{};

					auto layers = mapComponent->GetLayers();

					for (const auto& layer : layers)
					{
						if (layer.Source == propertyLayer->Source &&
							layer.Type == propertyLayer->Type &&
							layer.AuthConfigID == propertyLayer->AuthConfigID &&
							layer.Name == propertyLayer->Name &&
							layer.Opacity == propertyLayer->Opacity)
						{
							mapLayer = layer;
							break;
						}
					}

					if (mapLayer.Source == "")
					{
						return FReply::Handled();
					}

					FTransform EngineTransform;

					if (mapComponent->ZoomToLayer(mapLayer, EngineTransform))
					{
						if (auto activeViewport = GEditor->GetActiveViewport())
						{
							if (auto editorViewportClient = static_cast<FEditorViewportClient*>(activeViewport->GetClient()))
							{
								if (editorViewportClient->IsPerspective())
								{
									editorViewportClient->SetViewLocation(EngineTransform.GetLocation());
									editorViewportClient->SetViewRotation(EngineTransform.Rotator());
									editorViewportClient->Invalidate();
								}
							}
						}
					}
				}

				return FReply::Handled();
			})
		]
	];
	// clang-format on
}
