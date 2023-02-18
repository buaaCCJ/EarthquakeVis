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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfo.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfo.h" // IWYU pragma: associated

double UArcGISVectorTileSourceInfo::GetMaxScale()
{
    auto localResult = APIObject->GetMaxScale();
    
    return localResult;
}

double UArcGISVectorTileSourceInfo::GetMinScale()
{
    auto localResult = APIObject->GetMinScale();
    
    return localResult;
}

FString UArcGISVectorTileSourceInfo::GetName()
{
    auto localResult = APIObject->GetName();
    
    return localResult;
}

UArcGISPoint* UArcGISVectorTileSourceInfo::GetOrigin()
{
    auto localResult = APIObject->GetOrigin();
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISSpatialReference* UArcGISVectorTileSourceInfo::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

FString UArcGISVectorTileSourceInfo::GetURI()
{
    auto localResult = APIObject->GetURI();
    
    return localResult;
}

FString UArcGISVectorTileSourceInfo::GetVersion()
{
    auto localResult = APIObject->GetVersion();
    
    return localResult;
}