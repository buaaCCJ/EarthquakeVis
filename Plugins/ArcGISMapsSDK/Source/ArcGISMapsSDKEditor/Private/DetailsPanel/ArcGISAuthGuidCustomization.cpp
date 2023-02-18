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
#include "ArcGISMapsSDKEditor/DetailsPanel/ArcGISAuthGuidCustomization.h"

#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "IPropertyTypeCustomization.h"
#include "IPropertyUtilities.h"
#include "ScopedTransaction.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Text/STextBlock.h"

#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"

using namespace MapCreatorUtilities;

#define LOCTEXT_NAMESPACE "FArcGISAuthGuidCustomization"

TSharedRef<IPropertyTypeCustomization> FArcGISAuthGuidCustomization::MakeInstance()
{
	return MakeShared<FArcGISAuthGuidCustomization>();
}

void FArcGISAuthGuidCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle,
													 IDetailChildrenBuilder& ChildBuilder,
													 IPropertyTypeCustomizationUtils& CustomizationUtils)
{
}

void FArcGISAuthGuidCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle,
												   FDetailWidgetRow& HeaderRow,
												   IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	MapComponent = Cast<UArcGISMapComponent>(MapComponentManager::GetMapComponent());

	if (MapComponent)
	{
		MapComponent->OnAuthenticationChanged.AddSP(this, &FArcGISAuthGuidCustomization::OnAuthenticationChanged);
	}

	StructProperty = PropertyHandle;

	void* guidData;
	check(StructProperty->GetValueData(guidData) == FPropertyAccess::Success);
	GuidData = reinterpret_cast<FAuthGuid*>(guidData);

	ValidateIDs();
	UpdateAuthConfigOptions();

	// clang-format off
	HeaderRow
	.NameContent()
	[
		StructProperty->CreatePropertyNameWidget()
	]
	.ValueContent()
	[
		SAssignNew(AuthConfigListComboBox, STextComboBox)
		.OptionsSource(&AuthConfigOptions)
		.InitiallySelectedItem(GetCurrentConfigOption())
		.Font(CustomizationUtils.GetRegularFont())
		.OnSelectionChanged(this, &FArcGISAuthGuidCustomization::SetSelection)
		.OnGetTextLabelForItem(this, &FArcGISAuthGuidCustomization::GetSelection)
	];
	// clang-format on
}

FString FArcGISAuthGuidCustomization::GetSelection(TSharedPtr<FString> StringItem)
{
	return *StringItem;
}

void FArcGISAuthGuidCustomization::OnAuthenticationChanged()
{
	UpdateAuthConfigOptions();
	ValidateIDs();
	AuthConfigListComboBox->SetSelectedItem(GetCurrentConfigOption());
}

void FArcGISAuthGuidCustomization::UpdateConfigDataList()
{
	if (MapComponent)
	{
		ConfigDataList = MapComponent->GetAuthenticationConfigurations();
	}
}

void FArcGISAuthGuidCustomization::UpdateAuthConfigOptions()
{
	AuthConfigOptions.Empty();
	AuthConfigOptions.Add(MakeShareable(new FString("None")));

	UpdateConfigDataList();

	for (auto& config : ConfigDataList)
	{
		AuthConfigOptions.Add(MakeShareable(new FString(config.Name)));
	}
}

void FArcGISAuthGuidCustomization::ValidateIDs()
{
	UpdateConfigDataList();

	for (const auto& config : ConfigDataList)
	{
		if (*GuidData == config.ID)
		{
			return;
		}
	}

	GuidData->Invalidate();

	if (MapComponent)
	{
		MapComponent->MarkPackageDirty();
	}
}

TSharedPtr<FString> FArcGISAuthGuidCustomization::GetCurrentConfigOption()
{
	UpdateConfigDataList();

	for (int32 index = 0; index < ConfigDataList.Num(); index++)
	{
		if (*GuidData == ConfigDataList[index].ID && *AuthConfigOptions[index + 1].Get() == ConfigDataList[index].Name)
		{
			return AuthConfigOptions[index + 1];
		}
	}

	return AuthConfigOptions[0];
}

void FArcGISAuthGuidCustomization::SetSelection(TSharedPtr<FString> Item, ESelectInfo::Type Type)
{
	FScopedTransaction Transaction(LOCTEXT("SetAuthConfigSelection", "Set Auth Config Selection"));

	UpdateConfigDataList();

	if (Item == AuthConfigOptions[0])
	{
		GuidData->Invalidate();
	}
	else
	{
		for (int32 index = 1; index < AuthConfigOptions.Num(); index++)
		{
			if (Item == AuthConfigOptions[index])
			{
				*GuidData = ConfigDataList[index - 1].ID;
				break;
			}
		}
	}

	StructProperty->NotifyPreChange();

	TArray<UObject*> Objects;
	StructProperty->GetOuterObjects(Objects);
	for (UObject* Object : Objects)
	{
		Object->Modify();
	}

	TArray<void*> Ptrs;
	StructProperty->AccessRawData(Ptrs);

	for (int32 Index = 0; Index < Ptrs.Num(); ++Index)
	{
		*static_cast<FAuthGuid*>(Ptrs[Index]) = *GuidData;
	}

	StructProperty->NotifyPostChange(EPropertyChangeType::ValueSet);
	StructProperty->NotifyFinishedChangingProperties();

	auto parentHandle = StructProperty->GetParentHandle();

	void* parentData;
	parentHandle->GetValueData(parentData);

	if (parentData == nullptr)
	{
		return;
	}

	auto ParentObject = reinterpret_cast<FArcGISLayerInstanceData*>(parentData);

	if (ParentObject)
	{
		parentHandle->NotifyPostChange(EPropertyChangeType::ValueSet);
		return;
	}
}

#undef LOCTEXT_NAMESPACE
