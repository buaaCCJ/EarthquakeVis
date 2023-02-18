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
#include "ArcGISMapsSDK/API/GameEngine/ArcGISGameEngineType.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Map/ArcGISMap.h"
#include "ArcGISMapsSDK/API/GameEngine/MapView/ArcGISCamera.h"
#include "ArcGISMapsSDK/API/GameEngine/MapView/ArcGISGlobeModel.h"
#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISView.h"
#include "ArcGISMapsSDK/API/GameEngine/View/ArcGISViewOptions.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISElevationSourceViewState.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISLayerViewState.h"
#include "ArcGISMapsSDK/API/GameEngine/View/State/ArcGISViewState.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/ArcGISGameEngineType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Map/ArcGISMap.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/MapView/ArcGISCamera.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/MapView/ArcGISGlobeModel.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/ArcGISView.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/ArcGISViewOptions.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISElevationSourceViewState.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISLayerViewState.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/State/ArcGISViewState.h"

UArcGISView* UArcGISView::CreateArcGISView(EArcGISGameEngineType::Type gameEngineType, EArcGISGlobeModel::Type globeModel)
{
    auto result = NewObject<UArcGISView>();
    
    result->APIObject = ::MakeShared<Esri::GameEngine::View::ArcGISView>(static_cast<Esri::GameEngine::ArcGISGameEngineType>(gameEngineType), static_cast<Esri::GameEngine::MapView::ArcGISGlobeModel>(globeModel));
    
    return result;
}

UArcGISCamera* UArcGISView::GetCamera()
{
    auto localResult = APIObject->GetCamera();
    
    auto localLocalResult = NewObject<UArcGISCamera>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::MapView::ArcGISCamera>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISView::SetCamera(UArcGISCamera* camera)
{
    auto nullCamera = Esri::GameEngine::MapView::ArcGISCamera{};
    
    APIObject->SetCamera(camera ? *camera->APIObject : nullCamera);
}

UArcGISMap* UArcGISView::GetMap()
{
    auto localResult = APIObject->GetMap();
    
    auto localLocalResult = NewObject<UArcGISMap>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Map::ArcGISMap>(std::move(localResult));
    
    return localLocalResult;
}
void UArcGISView::SetMap(UArcGISMap* map)
{
    auto nullMap = Esri::GameEngine::Map::ArcGISMap{};
    
    APIObject->SetMap(map ? *map->APIObject : nullMap);
}

UArcGISSpatialReference* UArcGISView::GetSpatialReference()
{
    auto localResult = APIObject->GetSpatialReference();
    
    auto localLocalResult = NewObject<UArcGISSpatialReference>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISSpatialReference>(std::move(localResult));
    
    return localLocalResult;
}

FArcGISViewOptions UArcGISView::GetViewOptions()
{
    auto localResult = APIObject->GetViewOptions();
    
    static_assert(sizeof(FArcGISViewOptions) == sizeof(Esri::GameEngine::View::ArcGISViewOptions), "Type size mismatch");
    
    return reinterpret_cast<FArcGISViewOptions&>(localResult);
}
void UArcGISView::SetViewOptions(FArcGISViewOptions viewOptions)
{
    static_assert(sizeof(FArcGISViewOptions) == sizeof(Esri::GameEngine::View::ArcGISViewOptions), "Type size mismatch");
    
    APIObject->SetViewOptions(reinterpret_cast<Esri::GameEngine::View::ArcGISViewOptions&>(viewOptions));
}

FVector UArcGISView::GeographicToWorld(UArcGISPoint* geographicCoordinate) const
{
    auto nullGeographicCoordinate = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedGeographicCoordinateAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(geographicCoordinate->APIObject);
    
    auto localResult = APIObject->GeographicToWorld(geographicCoordinate ? *derivedGeographicCoordinateAPIObject : nullGeographicCoordinate);
    
    static_assert(sizeof(FVector) == sizeof(FVector3d), "Type size mismatch");
    
    return reinterpret_cast<FVector&>(localResult);
}

UArcGISViewState* UArcGISView::GetViewViewState() const
{
    auto localResult = APIObject->GetViewState();
    
    auto localLocalResult = NewObject<UArcGISViewState>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::View::State::ArcGISViewState>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISElevationSourceViewState* UArcGISView::GetElevationSourceViewState(UArcGISElevationSource* elevation) const
{
    auto nullElevation = Esri::GameEngine::Elevation::Base::ArcGISElevationSource{};
    
    auto localResult = APIObject->GetViewState(elevation ? *elevation->APIObject : nullElevation);
    
    auto localLocalResult = NewObject<UArcGISElevationSourceViewState>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::View::State::ArcGISElevationSourceViewState>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISLayerViewState* UArcGISView::GetLayerViewState(UArcGISLayer* layer) const
{
    auto nullLayer = Esri::GameEngine::Layers::Base::ArcGISLayer{};
    
    auto localResult = APIObject->GetViewState(layer ? *layer->APIObject : nullLayer);
    
    auto localLocalResult = NewObject<UArcGISLayerViewState>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::View::State::ArcGISLayerViewState>(std::move(localResult));
    
    return localLocalResult;
}

void UArcGISView::HandleLowMemoryWarning()
{
    APIObject->HandleLowMemoryWarning();
}

void UArcGISView::SetMemoryQuotas(int64 systemMemory, int64 videoMemory)
{
    APIObject->SetMemoryQuotas(systemMemory, videoMemory);
}

void UArcGISView::SetViewportProperties(int32 viewportWidthPixels, int32 viewportHeightPixels, float horizontalFieldOfViewDegrees, float verticalFieldOfViewDegrees, float verticalDistortionFactor)
{
    APIObject->SetViewportProperties(viewportWidthPixels, viewportHeightPixels, horizontalFieldOfViewDegrees, verticalFieldOfViewDegrees, verticalDistortionFactor);
}

UArcGISPoint* UArcGISView::WorldToGeographic(FVector worldCoordinate) const
{
    static_assert(sizeof(FVector) == sizeof(FVector3d), "Type size mismatch");
    
    auto localResult = APIObject->WorldToGeographic(reinterpret_cast<FVector3d&>(worldCoordinate));
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}