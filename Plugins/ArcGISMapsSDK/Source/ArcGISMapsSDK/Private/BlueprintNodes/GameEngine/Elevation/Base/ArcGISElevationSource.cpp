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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISLoadable.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSourceType.h"
#include "ArcGISMapsSDK/API/GameEngine/Extent/ArcGISExtentRectangle.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSource.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSourceType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Extent/ArcGISExtentRectangle.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"

UArcGISElevationSource* UArcGISElevationSource::CreateArcGISElevationSource(FString source, EArcGISElevationSourceType::Type type, FString APIKey)
{
    auto result = NewObject<UArcGISElevationSource>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::Elevation::Base::ArcGISElevationSource>(source, static_cast<Esri::GameEngine::Elevation::Base::ArcGISElevationSourceType>(type), APIKey);
    
    return result;
}

FString UArcGISElevationSource::GetAPIKey()
{
    auto localResult = APIObject->GetAPIKey();
    
    return localResult;
}

UArcGISExtentRectangle* UArcGISElevationSource::GetExtent()
{
    auto localResult = APIObject->GetExtent();
    
    auto localLocalResult = NewObject<UArcGISExtentRectangle>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Extent::ArcGISExtentRectangle>(std::move(localResult));
    
    return localLocalResult;
}

bool UArcGISElevationSource::GetIsEnabled()
{
    auto localResult = APIObject->GetIsEnabled();
    
    return localResult;
}
void UArcGISElevationSource::SetIsEnabled(bool isEnabled)
{
    APIObject->SetIsEnabled(isEnabled);
}

FString UArcGISElevationSource::GetName()
{
    auto localResult = APIObject->GetName();
    
    return localResult;
}
void UArcGISElevationSource::SetName(FString name)
{
    APIObject->SetName(name);
}

FString UArcGISElevationSource::GetSource()
{
    auto localResult = APIObject->GetSource();
    
    return localResult;
}

UArcGISSpatialReference* UArcGISElevationSource::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}