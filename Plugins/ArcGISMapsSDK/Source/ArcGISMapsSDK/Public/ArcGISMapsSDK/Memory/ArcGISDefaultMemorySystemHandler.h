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

#include "ArcGISMapsSDK/Memory/IArcGISMemorySystemHandler.h"

class FArcGISDefaultMemorySystemHandler : public IArcGISMemorySystemHandler
{
public:
	virtual ~FArcGISDefaultMemorySystemHandler();

	virtual FArcGISMemoryQuotas GetMemoryQuotas() override;
	virtual void Initialize(IArcGISMemorySystem* InMemorySystem) override;

protected:
	IArcGISMemorySystem* MemorySystem{nullptr};
};
