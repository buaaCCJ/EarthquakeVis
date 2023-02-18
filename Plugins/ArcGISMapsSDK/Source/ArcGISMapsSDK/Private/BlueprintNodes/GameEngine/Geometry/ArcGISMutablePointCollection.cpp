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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMutablePointCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISMutablePointCollection* UArcGISMutablePointCollection::CreateArcGISMutablePointCollectionWithSpatialReference(UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISMutablePointCollection>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMutablePointCollection>(spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

bool UArcGISMutablePointCollection::GetIsEmpty()
{
    auto localResult = APIObject->GetIsEmpty();
    
    return localResult;
}

int64 UArcGISMutablePointCollection::GetSize()
{
    auto localResult = APIObject->GetSize();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISMutablePointCollection::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISMutablePointCollection::AddPointXY(double x, double y)
{
    auto localResult = APIObject->AddPoint(x, y);
    
    return localResult;
}

int64 UArcGISMutablePointCollection::AddPointXYZ(double x, double y, double z)
{
    auto localResult = APIObject->AddPoint(x, y, z);
    
    return localResult;
}

int64 UArcGISMutablePointCollection::AddPoint(UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = APIObject->AddPoint(point ? *derivedPointAPIObject : nullPoint);
    
    return localResult;
}

void UArcGISMutablePointCollection::AddPointsFromImmutable(UArcGISImmutablePointCollection* points)
{
    auto nullPoints = Esri::GameEngine::Geometry::ArcGISImmutablePointCollection{};
    
    APIObject->AddPoints(points ? *points->APIObject : nullPoints);
}

void UArcGISMutablePointCollection::AddPoints(UArcGISMutablePointCollection* points)
{
    auto nullPoints = Esri::GameEngine::Geometry::ArcGISMutablePointCollection{};
    
    APIObject->AddPoints(points ? *points->APIObject : nullPoints);
}

UArcGISPoint* UArcGISMutablePointCollection::GetPoint(int64 index) const
{
    auto localResult = APIObject->GetPoint(index);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISMutablePointCollection::IndexOf(UArcGISPoint* point) const
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = APIObject->IndexOf(point ? *derivedPointAPIObject : nullPoint);
    
    return localResult;
}

void UArcGISMutablePointCollection::InsertPointXY(int64 pointIndex, double x, double y)
{
    APIObject->InsertPoint(pointIndex, x, y);
}

void UArcGISMutablePointCollection::InsertPointXYZ(int64 pointIndex, double x, double y, double z)
{
    APIObject->InsertPoint(pointIndex, x, y, z);
}

void UArcGISMutablePointCollection::InsertPoint(int64 pointIndex, UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    APIObject->InsertPoint(pointIndex, point ? *derivedPointAPIObject : nullPoint);
}

void UArcGISMutablePointCollection::RemoveAll()
{
    APIObject->RemoveAll();
}

void UArcGISMutablePointCollection::RemovePoint(int64 pointIndex)
{
    APIObject->RemovePoint(pointIndex);
}

void UArcGISMutablePointCollection::SetPoint(int64 pointIndex, UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    APIObject->SetPoint(pointIndex, point ? *derivedPointAPIObject : nullPoint);
}