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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelopeBuilder.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISEnvelopeBuilder.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISEnvelopeBuilder* UArcGISEnvelopeBuilder::CreateArcGISEnvelopeBuilderFromCenterPoint(UArcGISPoint* center, double width, double height)
{
    auto result = NewObject<UArcGISEnvelopeBuilder>();
    
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(center ? *derivedCenterAPIObject : nullCenter, width, height);
    
    return result;
}

UArcGISEnvelopeBuilder* UArcGISEnvelopeBuilder::CreateArcGISEnvelopeBuilderFromCenterPointAndDepth(UArcGISPoint* center, double width, double height, double depth)
{
    auto result = NewObject<UArcGISEnvelopeBuilder>();
    
    auto nullCenter = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedCenterAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(center->APIObject);
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(center ? *derivedCenterAPIObject : nullCenter, width, height, depth);
    
    return result;
}

UArcGISEnvelopeBuilder* UArcGISEnvelopeBuilder::CreateArcGISEnvelopeBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISEnvelopeBuilder>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISPoint* UArcGISEnvelopeBuilder::GetCenter()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetCenter();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

double UArcGISEnvelopeBuilder::GetDepth()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetDepth();
    
    return localResult;
}

double UArcGISEnvelopeBuilder::GetHeight()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetHeight();
    
    return localResult;
}

double UArcGISEnvelopeBuilder::GetMMax()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetMMax();
    
    return localResult;
}
void UArcGISEnvelopeBuilder::SetMMax(double mMax)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetMMax(mMax);
}

double UArcGISEnvelopeBuilder::GetMMin()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetMMin();
    
    return localResult;
}
void UArcGISEnvelopeBuilder::SetMMin(double mMin)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetMMin(mMin);
}

double UArcGISEnvelopeBuilder::GetWidth()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetWidth();
    
    return localResult;
}

double UArcGISEnvelopeBuilder::GetXMax()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetXMax();
    
    return localResult;
}
void UArcGISEnvelopeBuilder::SetXMax(double xMax)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetXMax(xMax);
}

double UArcGISEnvelopeBuilder::GetXMin()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetXMin();
    
    return localResult;
}
void UArcGISEnvelopeBuilder::SetXMin(double xMin)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetXMin(xMin);
}

double UArcGISEnvelopeBuilder::GetYMax()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetYMax();
    
    return localResult;
}
void UArcGISEnvelopeBuilder::SetYMax(double yMax)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetYMax(yMax);
}

double UArcGISEnvelopeBuilder::GetYMin()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetYMin();
    
    return localResult;
}
void UArcGISEnvelopeBuilder::SetYMin(double yMin)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetYMin(yMin);
}

double UArcGISEnvelopeBuilder::GetZMax()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetZMax();
    
    return localResult;
}
void UArcGISEnvelopeBuilder::SetZMax(double zMax)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetZMax(zMax);
}

double UArcGISEnvelopeBuilder::GetZMin()
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    auto localResult = derivedAPIObject->GetZMin();
    
    return localResult;
}
void UArcGISEnvelopeBuilder::SetZMin(double zMin)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetZMin(zMin);
}

void UArcGISEnvelopeBuilder::CenterAt(UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->CenterAt(point ? *derivedPointAPIObject : nullPoint);
}

void UArcGISEnvelopeBuilder::ChangeAspectRatio(double width, double height)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->ChangeAspectRatio(width, height);
}

void UArcGISEnvelopeBuilder::Expand(double factor)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->Expand(factor);
}

void UArcGISEnvelopeBuilder::ExpandAtAnchor(UArcGISPoint* anchor, double factor)
{
    auto nullAnchor = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedAnchorAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(anchor->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->Expand(anchor ? *derivedAnchorAPIObject : nullAnchor, factor);
}

void UArcGISEnvelopeBuilder::OffsetBy(double offsetX, double offsetY)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->OffsetBy(offsetX, offsetY);
}

void UArcGISEnvelopeBuilder::SetM(double mMin, double mMax)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetM(mMin, mMax);
}

void UArcGISEnvelopeBuilder::SetXY(double xMin, double yMin, double xMax, double yMax)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetXY(xMin, yMin, xMax, yMax);
}

void UArcGISEnvelopeBuilder::SetZ(double zMin, double zMax)
{
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->SetZ(zMin, zMax);
}

void UArcGISEnvelopeBuilder::UnionWithPoint(UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto derivedAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISEnvelopeBuilder>(APIObject);
    
    derivedAPIObject->Union(point ? *derivedPointAPIObject : nullPoint);
}