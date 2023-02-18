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

#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

FGeoPosition::FGeoPosition() = default;

FGeoPosition::FGeoPosition(double InX, double InY, double InZ) : X(InX), Y(InY), Z(InZ)
{
	SpatialReferenceWkid = Esri::GameEngine::Geometry::ArcGISSpatialReference::WGS84().GetWKID();
}

FGeoPosition::FGeoPosition(double InX, double InY, double InZ, int InSpatialReferenceWkid)
: X(InX),
  Y(InY),
  Z(InZ),
  SpatialReferenceWkid(InSpatialReferenceWkid)
{
}

FGeoPosition::FGeoPosition(double InX, double InY, double InZ, const Esri::GameEngine::Geometry::ArcGISSpatialReference& InSpatialReference)
: X(InX),
  Y(InY),
  Z(InZ)
{
	SpatialReferenceWkid = InSpatialReference.GetWKID();
	SpatialReferenceWkt = InSpatialReference.GetWKText();
}

FGeoPosition::FGeoPosition(double InX, double InY, double InZ, UArcGISSpatialReference* InSpatialReference) : X(InX), Y(InY), Z(InZ)
{
	if (!InSpatialReference)
	{
		return;
	}

	SpatialReferenceWkid = InSpatialReference->GetWKID();
	SpatialReferenceWkt = InSpatialReference->GetWKText();
}

FGeoPosition::FGeoPosition(const Esri::GameEngine::Geometry::ArcGISPoint& InPosition)
: X(InPosition.GetX()),
  Y(InPosition.GetY()),
  Z(InPosition.GetZ())
{
	SpatialReferenceWkid = InPosition.GetSpatialReference().GetWKID();
	SpatialReferenceWkt = InPosition.GetSpatialReference().GetWKText();
}

FGeoPosition::FGeoPosition(UArcGISPoint* InPosition)
{
	if (!InPosition)
	{
		SpatialReferenceWkid = Esri::GameEngine::Geometry::ArcGISSpatialReference::WGS84().GetWKID();
		return;
	}

	X = InPosition->GetX();
	Y = InPosition->GetY();
	Z = InPosition->GetZ();
	auto spatialRef = InPosition->GetSpatialReference();

	if (!spatialRef)
	{
		return;
	}

	SpatialReferenceWkid = spatialRef->GetWKID();
	SpatialReferenceWkt = spatialRef->GetWKText();
}

FGeoPosition::operator UArcGISPoint*() const
{
	return UArcGISPoint::CreateArcGISPointWithXYZSpatialReference(X, Y, Z, GetSpatialReference());
}

FGeoPosition::operator Esri::GameEngine::Geometry::ArcGISPoint() const
{
	auto SR = GetSpatialReference();
	return Esri::GameEngine::Geometry::ArcGISPoint(X, Y, Z, *(SR->APIObject.Get()));
}

bool FGeoPosition::operator==(const FGeoPosition& other) const
{
	return X == other.X && Y == other.Y && Z == other.Z && SpatialReferenceWkid == other.SpatialReferenceWkid &&
		   SpatialReferenceWkt == other.SpatialReferenceWkt;
}

bool FGeoPosition::operator!=(const FGeoPosition& other) const
{
	return X != other.X || Y != other.Y || Z != other.Z || SpatialReferenceWkid != other.SpatialReferenceWkid ||
		   SpatialReferenceWkt != other.SpatialReferenceWkt;
	;
}

bool FGeoPosition::IsValid() const
{
	return !FMath::IsNaN(X) && !FMath::IsNaN(Y) && !FMath::IsNaN(Z);
}

// Use this to get the Spatial Reference. This ensures that accessing the value
// to create a Position will not throw an exception or return nullptr. Which in some cases
// cannot be handled easily. Such as in the UI.
UArcGISSpatialReference* FGeoPosition::GetSpatialReference() const
{
	try
	{
		return UArcGISSpatialReference::CreateArcGISSpatialReference(SpatialReferenceWkid);
	}
	catch (...)
	{
		try
		{
			if (SpatialReferenceWkt != "")
			{
				return UArcGISSpatialReference::CreateArcGISSpatialReferenceFromWKText(SpatialReferenceWkt);
			}
		}
		catch (...)
		{
		}

		UE_LOG(LogTemp, Warning, TEXT("%i is an invalid Spatial Refernce WKID. Falling back to 4326"), SpatialReferenceWkid);
		SpatialReferenceWkid = 4326;
		return UArcGISSpatialReference::CreateArcGISSpatialReference(SpatialReferenceWkid);
	}
}
