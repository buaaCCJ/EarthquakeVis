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

#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"

class FArcGISMapCreatorLayerCustomization : public IPropertyTypeCustomization
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
	TSharedPtr<STextBlock> LayerNameText;
	TSharedPtr<IPropertyHandle> NameProp;
	TSharedPtr<IPropertyHandle> SourceProp;
	TSharedPtr<IPropertyHandle> OpacityProp;
	TSharedPtr<IPropertyHandle> IsVisibleProp;
	TSharedPtr<IPropertyHandle> TypeProp;
	TSharedPtr<IPropertyHandle> AuthConfigIDProp;
};
