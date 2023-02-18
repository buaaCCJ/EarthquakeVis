// COPYRIGHT 1995-2022 ESRI
// TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
// Unpublished material - all rights reserved under the
// Copyright Laws of the United States and applicable international
// laws, treaties, and conventions.
//
// For additional information, contact:
// Environmental Systems Research Institute, Inc.
// Attn: Contracts and Legal Services Department
// 380 New York Street
// Redlands, California, 92373
// USA
//
// email: contracts@esri.com

#include "ArcGISMapsSDK/Utils/GeoCoord/GeoRotation.h"

FGeoRotation::FGeoRotation() = default;

FGeoRotation::FGeoRotation(UArcGISRotation* InRotation)
{
	Heading = InRotation->GetHeading();
	Pitch = InRotation->GetPitch();
	Roll = InRotation->GetRoll();
}

bool FGeoRotation::operator==(const FGeoRotation& other) const
{
	return Heading == other.Heading && Pitch == other.Pitch && Roll == other.Roll;
}

bool FGeoRotation::operator!=(const FGeoRotation& other) const
{
	return Heading != other.Heading || Pitch != other.Pitch || Roll != other.Roll;
}
