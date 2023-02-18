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

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "Widgets/Input/STextComboBox.h"

#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"
#include "ArcGISMapsSDK/Utils/AuthGuid.h"

class ARCGISMAPSSDKEDITOR_API FArcGISAuthGuidCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	// IPropertyTypeCustomization
	void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle,
						 FDetailWidgetRow& HeaderRow,
						 IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle,
						   IDetailChildrenBuilder& ChildBuilder,
						   IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
	friend class FArcGISAuthGuidCustomizationValidateIDsTest;

	void OnAuthenticationChanged();
	void UpdateConfigDataList();
	void UpdateAuthConfigOptions();
	void ValidateIDs();
	void SetSelection(TSharedPtr<FString> Item, ESelectInfo::Type Type);
	FString GetSelection(TSharedPtr<FString> StringItem);
	TSharedPtr<FString> GetCurrentConfigOption();

	UArcGISMapComponent* MapComponent;
	TArray<FArcGISAuthenticationConfigurationInstanceData> ConfigDataList;
	FAuthGuid* GuidData;
	TSharedPtr<IPropertyHandle> StructProperty;
	TArray<TSharedPtr<FString>> AuthConfigOptions;
	TSharedPtr<STextComboBox> AuthConfigListComboBox;
};
