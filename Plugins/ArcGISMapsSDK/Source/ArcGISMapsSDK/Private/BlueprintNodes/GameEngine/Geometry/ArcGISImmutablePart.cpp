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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePart.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSegment.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISImmutablePart.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISImmutablePointCollection.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSegment.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISPoint* UArcGISImmutablePart::GetEndPoint()
{
    auto localResult = APIObject->GetEndPoint();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISImmutablePart::GetHasCurves()
{
    auto localResult = APIObject->GetHasCurves();
    
    return localResult;
}

bool UArcGISImmutablePart::GetIsEmpty()
{
    auto localResult = APIObject->GetIsEmpty();
    
    return localResult;
}

int64 UArcGISImmutablePart::GetPointCount()
{
    auto localResult = APIObject->GetPointCount();
    
    return localResult;
}

int64 UArcGISImmutablePart::GetSegmentCount()
{
    auto localResult = APIObject->GetSegmentCount();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISImmutablePart::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISImmutablePart::GetStartPoint()
{
    auto localResult = APIObject->GetStartPoint();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISImmutablePart::GetEndPointIndexFromSegmentIndex(int64 segmentIndex) const
{
    auto localResult = APIObject->GetEndPointIndexFromSegmentIndex(segmentIndex);
    
    return localResult;
}

UArcGISPoint* UArcGISImmutablePart::GetPoint(int64 pointIndex) const
{
    auto localResult = APIObject->GetPoint(pointIndex);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISImmutablePointCollection* UArcGISImmutablePart::GetPoints() const
{
    auto localResult = APIObject->GetPoints();
    
    auto localLocalResult = NewObject<UArcGISImmutablePointCollection>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISImmutablePointCollection>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISSegment* UArcGISImmutablePart::GetSegment(int64 segmentIndex) const
{
    auto localResult = APIObject->GetSegment(segmentIndex);
    
    auto localLocalResult = NewObject<UArcGISSegment>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSegment>(std::move(localResult));
    
    return localLocalResult;
}

int64 UArcGISImmutablePart::GetSegmentIndexFromEndPointIndex(int64 pointIndex) const
{
    auto localResult = APIObject->GetSegmentIndexFromEndPointIndex(pointIndex);
    
    return localResult;
}

int64 UArcGISImmutablePart::GetSegmentIndexFromStartPointIndex(int64 pointIndex) const
{
    auto localResult = APIObject->GetSegmentIndexFromStartPointIndex(pointIndex);
    
    return localResult;
}

int64 UArcGISImmutablePart::GetStartPointIndexFromSegmentIndex(int64 segmentIndex) const
{
    auto localResult = APIObject->GetStartPointIndexFromSegmentIndex(segmentIndex);
    
    return localResult;
}