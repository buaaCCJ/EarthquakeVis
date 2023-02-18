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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMutablePart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMutablePart.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSegment.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISMutablePart* UArcGISMutablePart::CreateArcGISMutablePartWithSpatialReference(UArcGISSpatialReference* spatialReference)
{
    auto result = NewObject<UArcGISMutablePart>();
    
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    result->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISMutablePart>(spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    return result;
}

UArcGISPoint* UArcGISMutablePart::GetEndPoint()
{
    auto localResult = APIObject->GetEndPoint();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISMutablePart::GetHasCurves()
{
    auto localResult = APIObject->GetHasCurves();
    
    return localResult;
}

bool UArcGISMutablePart::GetIsEmpty()
{
    auto localResult = APIObject->GetIsEmpty();
    
    return localResult;
}

int64 UArcGISMutablePart::GetPointCount()
{
    auto localResult = APIObject->GetPointCount();
    
    return localResult;
}

int64 UArcGISMutablePart::GetSegmentCount()
{
    auto localResult = APIObject->GetSegmentCount();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISMutablePart::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISMutablePart::GetStartPoint()
{
    auto localResult = APIObject->GetStartPoint();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISMutablePart::AddPointXY(double x, double y)
{
    auto localResult = APIObject->AddPoint(x, y);
    
    return localResult;
}

int64 UArcGISMutablePart::AddPointXYZ(double x, double y, double z)
{
    auto localResult = APIObject->AddPoint(x, y, z);
    
    return localResult;
}

int64 UArcGISMutablePart::AddPoint(UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = APIObject->AddPoint(point ? *derivedPointAPIObject : nullPoint);
    
    return localResult;
}

int64 UArcGISMutablePart::AddSegment(UArcGISSegment* segment)
{
    auto nullSegment = Esri::GameEngine::Geometry::ArcGISSegment{};
    
    auto localResult = APIObject->AddSegment(segment ? *segment->APIObject : nullSegment);
    
    return localResult;
}

int64 UArcGISMutablePart::GetEndPointIndexFromSegmentIndex(int64 segmentIndex) const
{
    auto localResult = APIObject->GetEndPointIndexFromSegmentIndex(segmentIndex);
    
    return localResult;
}

UArcGISPoint* UArcGISMutablePart::GetPoint(int64 pointIndex) const
{
    auto localResult = APIObject->GetPoint(pointIndex);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISImmutablePointCollection* UArcGISMutablePart::GetPoints() const
{
    auto localResult = APIObject->GetPoints();
    
    auto localLocalResult = NewObject<UArcGISImmutablePointCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISImmutablePointCollection>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISSegment* UArcGISMutablePart::GetSegment(int64 segmentIndex) const
{
    auto localResult = APIObject->GetSegment(segmentIndex);
    
    auto localLocalResult = NewObject<UArcGISSegment>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSegment>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISMutablePart::GetSegmentIndexFromEndPointIndex(int64 pointIndex) const
{
    auto localResult = APIObject->GetSegmentIndexFromEndPointIndex(pointIndex);
    
    return localResult;
}

int64 UArcGISMutablePart::GetSegmentIndexFromStartPointIndex(int64 pointIndex) const
{
    auto localResult = APIObject->GetSegmentIndexFromStartPointIndex(pointIndex);
    
    return localResult;
}

int64 UArcGISMutablePart::GetStartPointIndexFromSegmentIndex(int64 segmentIndex) const
{
    auto localResult = APIObject->GetStartPointIndexFromSegmentIndex(segmentIndex);
    
    return localResult;
}

void UArcGISMutablePart::InsertPointXY(int64 pointIndex, double x, double y)
{
    APIObject->InsertPoint(pointIndex, x, y);
}

void UArcGISMutablePart::InsertPointXYZ(int64 pointIndex, double x, double y, double z)
{
    APIObject->InsertPoint(pointIndex, x, y, z);
}

void UArcGISMutablePart::InsertPoint(int64 pointIndex, UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    APIObject->InsertPoint(pointIndex, point ? *derivedPointAPIObject : nullPoint);
}

void UArcGISMutablePart::InsertSegment(int64 segmentIndex, UArcGISSegment* segment)
{
    auto nullSegment = Esri::GameEngine::Geometry::ArcGISSegment{};
    
    APIObject->InsertSegment(segmentIndex, segment ? *segment->APIObject : nullSegment);
}

void UArcGISMutablePart::RemoveAll()
{
    APIObject->RemoveAll();
}

void UArcGISMutablePart::RemovePoint(int64 pointIndex)
{
    APIObject->RemovePoint(pointIndex);
}

void UArcGISMutablePart::RemoveSegment(int64 segmentIndex)
{
    APIObject->RemoveSegment(segmentIndex);
}

void UArcGISMutablePart::SetPoint(int64 pointIndex, UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    APIObject->SetPoint(pointIndex, point ? *derivedPointAPIObject : nullPoint);
}

void UArcGISMutablePart::SetSegment(int64 segmentIndex, UArcGISSegment* segment)
{
    auto nullSegment = Esri::GameEngine::Geometry::ArcGISSegment{};
    
    APIObject->SetSegment(segmentIndex, segment ? *segment->APIObject : nullSegment);
}