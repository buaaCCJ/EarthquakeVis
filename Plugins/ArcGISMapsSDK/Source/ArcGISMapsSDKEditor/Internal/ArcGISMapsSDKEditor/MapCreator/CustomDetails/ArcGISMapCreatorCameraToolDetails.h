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

#include "DetailLayoutBuilder.h"
#include "IDetailCustomization.h"

#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorCameraTool.h"

class FArcGISMapCreatorCameraToolDetails : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	// IDetailCustomization
	void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	FReply AlignView(TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties, TSharedRef<IPropertyUtilities> utilities);
	FReply CreateCamera(TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties, TSharedRef<IPropertyUtilities> utilities);

	void CreateAlignButton(IDetailLayoutBuilder& detailBuilder, TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties);
	void CreateCameraButton(IDetailLayoutBuilder& detailBuilder, TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties);
};
